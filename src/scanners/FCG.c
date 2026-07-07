/* FlashCG */
#include "../unp64.h"
void Scn_FCG(unpstr *Unp)
{
    unsigned char *mem;
    int q=0,p,strtmp,endtmp;
    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        for(p=0x80d;p<0x812;p+=4)
        {
            if((*(unsigned int*)(mem+p+0x00)==0xBD9AFFA2) &&
               (*(unsigned int*)(mem+p+0x05)==0x00F79D08) &&
               (*(unsigned int*)(mem+p+0x0c)==0xA901004C) &&
               (*(unsigned int*)(mem+p+0x58)==0xAAACB101) )
            {
                if( (mem[p+0x57]==0x66) && (mem[p+0x7a]==0x4c) )
                    q=0x7b;
                else if( (mem[p+0x57]==0x75) && (mem[p+0x89]==0x4c) )
                    q=0x8a;
                else
                    break;
                Unp->DepAdr=0x100;
                break;
            }
        }
        if(Unp->DepAdr)
        {
            if(Unp->info->run == -1 )
                Unp->Forced=p;
            Unp->StrMem=mem[p+0x49]|mem[p+0x4d]<<8;
            Unp->RetAdr=mem[p+q]|mem[p+q+1]<<8;
            if(Unp->RetAdr==0xf8)
                Unp->RetAdr=mem[p+0x15]|mem[p+0x16]<<8;
            Unp->EndAdr=0xae; /* there is also a broken version that sets it +1 */

            if(q==0x7b)
                PrintInfo(Unp,_I_FCGPACK10);
            else
                PrintInfo(Unp,_I_FCGPACK30);
            Unp->IdFlag=1;return;
        }
    }
    /* pratically identical to 1.0 but without support of "run" A9 00 20 71 A8 4C AE A7 */
    if( Unp->DepAdr==0 )
    {
        p=0x80d;
        if(((*(unsigned int*)(mem+p+0x00)&0xff00ffff)==0xBD00A0A2) &&
           (*(unsigned int*)(mem+p+0x05)==0x00FF9D08) &&
           (*(unsigned int*)(mem+p+0x0c)==0x7801004C) &&
           (*(unsigned int*)(mem+p+0x50)==0xAAACB101) )
        {
            Unp->DepAdr=0x100;
            if(Unp->info->run == -1 )
                Unp->Forced=p;
            Unp->StrMem=mem[p+0x41]|mem[p+0x45]<<8;
            Unp->RetAdr=mem[p+0x73]|mem[p+0x74]<<8;
            Unp->EndAdr=0xae;
            PrintInfo(Unp,_I_FCGPACK12);
            Unp->IdFlag=1;return;
        }
    }
    /* another variant... */
    if( Unp->DepAdr==0 )
    {
        p=0x80e;
        if((*(unsigned int*)(mem+p+0x00)==0x1BBDACA2) &&
           (*(unsigned int*)(mem+p+0x04)==0x00FF9D08) &&
           (*(unsigned int*)(mem+p+0x0b)==0x7801004C) &&
           (*(unsigned int*)(mem+p+0x50)==0xCA01A520) )
        {
            Unp->DepAdr=0x100;
            if(Unp->info->run == -1 )
                Unp->Forced=p;
            Unp->StrMem=mem[p+0x3a]|mem[p+0x3e]<<8;
            Unp->RetAdr=mem[p+0x78]|mem[p+0x79]<<8;
            Unp->EndAdr=0xae;
            PrintInfo(Unp,_I_FCGPACK13);
            Unp->IdFlag=1;return;
        }
    }
    if( Unp->DepAdr==0 )
    {
        for(p=0x80d;p<0x813;p+=5)
        {
            if(mem[p]==0xa2 &&
               (*(unsigned int*)(mem+p+0x04)==0xAF84AE86) &&
               (*(unsigned int*)(mem+p+0x0c)==0x00FF9908) &&
               (*(unsigned int*)(mem+p+0x13)==0x7801004C) &&
               (*(unsigned int*)(mem+p+0x31)==0xAC91AEB1) )
            {
                if( (p==0x80d) && (mem[p+0x9b]==0x4c) )
                    q=0x9c;
                else if( (p==0x812) && (mem[p+0x90]==0x4c) )
                    q=0x91;
                else
                    break;
                Unp->DepAdr=0x100;
                break;
            }
        }
        if(Unp->DepAdr)
        {
            if(Unp->info->run == -1 )
                Unp->Forced=p;
            Unp->RetAdr=mem[p+q]|mem[p+q+1]<<8;
            if(q==0x91)
                PrintInfo(Unp,_I_FCGLINK);
            else
                PrintInfo(Unp,_I_TMCULINK);
            Unp->StrMem=0x10000;
            Unp->EndAdr=0;
            /* offsets table, 0x15*4 bytes */
            for(p=p+q+2,q=p+0x54;p<q;p+=4)
            {
                strtmp=(mem[p+0]|mem[p+1]<<8);
                if(strtmp==0)
                {
                    break;
                }
                if(Unp->StrMem > strtmp)
                {
                    Unp->StrMem=strtmp;
                }
                endtmp=(mem[p+2]|mem[p+3]<<8);
                if(endtmp==0)
                    endtmp=0x10000;
                if(Unp->EndAdr < endtmp)
                {
                    Unp->EndAdr=endtmp;
                }
                if(Unp->DebugP)
                {
                    printf("$%04x-$%04x\n",strtmp,endtmp-1);
                }
            }
            Unp->IdFlag=1;return;
        }
    }
    if( Unp->DepAdr==0 )
    {
        if(((*(unsigned int*)(mem+0x811)==0x1EB900A0)||
            (*(unsigned int*)(mem+0x811)==0x1fB900A0)) &&
           (*(unsigned int*)(mem+0x81f)==0x8534A978) &&
           (*(unsigned int*)(mem+0x837)==0x49FBB1F6) &&
           (*(unsigned int*)(mem+0x827)==0x84FB8508) )
        {
            Unp->DepAdr=mem[0x81d]|mem[0x81e]<<8;
            if(Unp->info->run == -1 )
                Unp->Forced=0x811;
            Unp->StrMem=mem[0x82d]|mem[0x82f]<<8;
            Unp->RetAdr=mem[0x85c]|mem[0x85d]<<8;
            Unp->EndAdr=mem[0x84d]|mem[0x84f]<<8;
            /* this variant has correct end pointer */
            if(Unp->DepAdr!=0x5e1)
                Unp->EndAdr+=0x2a;
            PrintInfo(Unp,_I_FCGCODER);
            Unp->IdFlag=1;return;
        }
    }
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x811)==0x1FBD00A2) &&
          ((*(unsigned int*)(mem+0x815)&0xff00ffff)==0x9D004908) &&
           (*(unsigned int*)(mem+0x819)==0xE0E8081F) )
        {
            q=mem[0x817];
            p=q<<24|q<<16|q<<8|q;
            if(((*(unsigned int*)(mem+0x860)^p)==0x01004CF5) &&
               ((*(unsigned int*)(mem+0x864)^p)==0x00A209A0) )
            {
                if(Unp->info->run == -1 )
                    Unp->Forced=0x811;
                Unp->DepAdr=0x100;
                Unp->StrMem= 0x800;
                Unp->EndAdr=Unp->info->end-0x100;
                Unp->RetAdr=(mem[0x852]^q)|(mem[0x853]^q)<<8;
                mem[0x852]=0xea^q; /* in any case avoid the disk format =) */
                mem[0x853]=0xea^q;
                if(((*(unsigned int*)(mem+0x8a6)^p)==0xA9AB1E20))
                    PrintInfo(Unp,_I_HLEISEP); /* prints warning and exits */
                else
                    PrintInfo(Unp,_I_FCGPROT); /* formats with label "FLASH-PROTECTED!" */
                Unp->IdFlag=1;return;
            }
        }
    }
    /* similar protector, maybe an hack */
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x810)==0x1FBD00A2) &&
          ((*(unsigned int*)(mem+0x814)&0xff00ffff)==0x9D004908) &&
           (*(unsigned int*)(mem+0x818)==0xE0E8081F) &&
          ((*(unsigned int*)(mem+0x81c)&0x00ffff00)==0x00F3D000) )
        {
            q=mem[0x816];
            p=q<<24|q<<16|q<<8|q;
            q=mem[0x81c];
            if(((*(unsigned int*)(mem+0x823)^p)==0xAEA509D0) &&
               ((q==0x9f)||(q==0xa5)) )
            {
                if(Unp->info->run == -1 )
                    Unp->Forced=0x810;
                if( q==0x9f )
                    q=0x898;
                else
                    q=0x89d;
                p&=0xff;
                mem[0xaf]=mem[0x822]^p; /* correct values always =) */
                mem[0xae]=mem[0x828]^p;
                Unp->DepAdr=0x100;
                Unp->StrMem=(mem[q+3]^p)|(mem[q+4]^p)<<8;
                Unp->EndAdr=0x2d;
                Unp->RetAdr=(mem[q+0x23]^p)|(mem[q+0x24]^p)<<8;
                PrintInfo(Unp,_I_FCCPROT); /* formats with label "F.C.C PROTECTED!" */
                Unp->IdFlag=1;return;
            }
        }
    }
    /* TFG PACK+CODER, pratically FCG packer 1 at $820 + xor */
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x820)==0x148D34A9) &&
           (*(unsigned int*)(mem+0x824)==0x9AFFA203) &&
           (*(unsigned int*)(mem+0x828)==0x9D0833BD) &&
           (*(unsigned int*)(mem+0x897)==0xB1017B20) )
        {
            Unp->DepAdr=0x100;
            if(Unp->info->run == -1 )
                Unp->Forced=0x820;
            Unp->StrMem=mem[0x874]|mem[0x878]<<8;
            Unp->RetAdr=mem[0x8b5]|mem[0x8b6]<<8;
            if(Unp->RetAdr==0xf8)
                Unp->RetAdr=mem[0x83a]|mem[0x83b]<<8;
            Unp->EndAdr=0xae;
            PrintInfo(Unp,_I_TFGPACK);
            Unp->IdFlag=1;return;
        }
    }
    /* Exprotect/Flash&Voodoo */
    if( Unp->DepAdr==0 )
    {
        if((mem[0x83e]==0x78)&&(mem[0x83f]==0xa9)&&
           (*(unsigned int*)(mem+0x841)==0x00A90285) &&
           (*(unsigned int*)(mem+0x845)==0xF7A20185) &&
           (*(unsigned int*)(mem+0x849)==0x61B900A0) &&
           (*(unsigned int*)(mem+0x850)==0xC8086199) )
        {
            Unp->DepAdr=0x100;
            if(Unp->info->run == -1 )
                Unp->Forced=0x83e;
            p=mem[0x840];
            Unp->StrMem=0x801;
            Unp->RetAdr=(mem[0x8bb]^p)|(mem[0x8bc]^p)<<8;
            Unp->EndAdr=Unp->info->end-0xff;
            PrintInfo(Unp,_I_EXPROT);
            Unp->IdFlag=1;return;
        }
    }
    /* Flash/RWE Protector 3.3 */
    if( Unp->DepAdr==0 )
    {
        if(
           (*(unsigned int*)(mem+0x824)==0xB9083E4C) &&
           (*(unsigned int*)(mem+0x828)==0x01E60860) &&
           (*(unsigned int*)(mem+0x84c)==0x02450827) &&
           (*(unsigned int*)(mem+0x850)==0xC8086099) )
        {
            Unp->DepAdr=0x100;
            if(Unp->info->run == -1 )
                Unp->Forced=0x824;
            p=Unp->info->end&0xff; /* uses endaddr.lowbyte as initial xorval */
            Unp->StrMem=0x801;
            Unp->RetAdr=(mem[0x8bb]^p)|(mem[0x8bc]^p)<<8;
            Unp->fEndAf=0xae;
            Unp->EndAdC=0xff00;
            PrintInfo(Unp,_I_FLSPROT33);
            Unp->IdFlag=1;return;
        }
    }
    /* TFG CODER */
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x818)==0x018536A9) &&
           (*(unsigned int*)(mem+0x829)==0x49083ABD) &&
           (*(unsigned int*)(mem+0x82f)==0x4D081B4D) &&
           (*(unsigned int*)(mem+0x836)==0xD0E8083A) )
        {
            Unp->DepAdr=0x68a;
            if(Unp->info->run == -1 )
                Unp->Forced=0x818;
            Unp->StrMem=0x801;
            q=mem[0x82d]^mem[0x81b]^mem[0x820];
            Unp->RetAdr=(mem[0x8b1]^q)|(mem[0x8b2]^q)<<8;
            Unp->EndAdr=0x2d;
            PrintInfo(Unp,_I_TFGCODE);
            Unp->IdFlag=1;return;
        }
    }
}
