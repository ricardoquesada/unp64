/* matcham charpack 250 */
#include "../unp64.h"
void Scn_Matcham(unpstr *Unp)
{
    unsigned char *mem;
    int p,strtmp,endtmp;
    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if( (mem[0x80d]==0x78) &&
            (*(unsigned int*)(mem+0x816)==0x0195081F) &&
            (*(unsigned int*)(mem+0x81c)==0x00024CF8) &&
            (*(unsigned int*)(mem+0x870)==0x12B11985) )
        {
            Unp->DepAdr=0x002;
            Unp->Forced=0x80d;
            Unp->EndAdr=mem[0x837]|mem[0x838]<<8; Unp->EndAdr+=mem[0x82c]+1;
            Unp->RetAdr=mem[0x8b1]|mem[0x8b2]<<8;
            Unp->StrAdC=EA_USE_Y|1;
            Unp->fStrAf=0x19;
            PrintInfo(Unp,_I_MATCHARP);
            Unp->IdFlag=1;return;
        }
    }
    /* matcham basic packer 1.1 */
    if( Unp->DepAdr==0 )
    {
        if( (mem[0x811]==0xa2) && (mem[0x813]==0xa0) &&
            (*(unsigned int*)(mem+0x815)==0x2E842D86) &&
            (*(unsigned int*)(mem+0x821)==0x779D082B) &&
            (*(unsigned int*)(mem+0x829)==0xA200784C) )
        {
            Unp->DepAdr=0x078;
            Unp->Forced=0x811;
            Unp->EndAdr=mem[0x812]|mem[0x814]<<8;
            Unp->RetAdr=mem[0x8c7]|mem[0x8c8]<<8;
            //Unp->StrMem=0x800;
            mem[0x8b9]=0x24; /* patch sta $77,x, would clear useful vars */
            Unp->fStrAf=0x8f;
            Unp->StrAdC=0xffff|EA_ADDFF;
            PrintInfo(Unp,_I_MATCBASP);
            Unp->IdFlag=1;return;
        }
    }
    /* MTC pack/Matcham Denser */
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x811)==0x00A0D878) &&
            (*(unsigned int*)(mem+0x815)==0x2EC60184) &&
            (*(unsigned int*)(mem+0x819)==0xB10820CE) &&
            (*(unsigned int*)(mem+0x888)==0x010E4C2D) )
        {
            Unp->DepAdr=0x100;
            Unp->EndAdr=0x2d;
            Unp->StrMem=mem[0x82b]|mem[0x82f]<<8;
            Unp->RetAdr=mem[0x85f]|mem[0x860]<<8;
            if(Unp->info->run == -1)
            {
                Unp->Forced=0x811;
                if(mem[0x808]==0xa2 && mem[0x80d]==0x2d )
                    Unp->Forced=0x808;
            }
            PrintInfo(Unp,_I_MATCDNEQ);
            Unp->IdFlag=1;return;
        }
    }
    /* Matcham Denser/251 */
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x811)==0x8400A078) &&
            (*(unsigned int*)(mem+0x815)==0xCE2EC601) &&
            (*(unsigned int*)(mem+0x819)==0x2DB1081F) &&
            (*(unsigned int*)(mem+0x87a)==0x015520C1) )
        {
            Unp->DepAdr=0x100;
            Unp->EndAdr=0x2d;
            Unp->StrMem=mem[0x838]|mem[0x839]<<8;
            Unp->RetAdr=mem[0x88c]|mem[0x88d]<<8;
            if(Unp->info->run == -1)
            {
                Unp->Forced=0x811;
            }
            PrintInfo(Unp,_I_MATCDN25);
            Unp->IdFlag=1;return;
        }
    }
    /* Matcham Denser/flex */
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x81a)==0x8400A078) &&
            (*(unsigned int*)(mem+0x81e)==0x094EB902) &&
            (*(unsigned int*)(mem+0x822)==0x8800FF99) &&
            (*(unsigned int*)(mem+0x8f5)==0xB103704C) &&
            (*(unsigned int*)(mem+0x933)==0xB103704C) )
        {
            Unp->DepAdr=0x334;
            Unp->EndAdr=0x2d; /* fendafter=0x370 */
            Unp->StrMem=mem[0x89d]|mem[0x89e]<<8;
            Unp->RetAdr=mem[0x8ba]|mem[0x8bb]<<8;
            if(Unp->info->run == -1)
            {
                Unp->Forced=0x81a;
            }
            PrintInfo(Unp,_I_MATCDNFL);
            Unp->IdFlag=1;return;
        }
    }
    /* Matcham Linker/251 */
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x336)==0x0343BDD8) &&
            (*(unsigned int*)(mem+0x33a)==0xE801009D) &&
            (*(unsigned int*)(mem+0x3a0)==0x9AFFA278) &&
            (*(unsigned int*)(mem+0x3bb)==0x03364CED) )
        {
            Unp->DepAdr=0x100;
            Unp->RetAdr=mem[0x37e]|mem[0x37f]<<8;
            Unp->Forced=0x3a0;

            Unp->StrMem=0x10000;
            Unp->EndAdr=0;
            /* offsets table, 0x20 bytes */
            for(p=0x380;p<0x3a0;p+=4)
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
            PrintInfo(Unp,_I_MATCLNK2);
            Unp->IdFlag=1;return;
        }
    }
    /* Matcham Flexer/229 */
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x817)==0x0FB934A0) &&
            (*(unsigned int*)(mem+0x81b)==0x03009908) &&
            (*(unsigned int*)(mem+0x89c)==0xD0038BEE) &&
            (*(unsigned int*)(mem+0x8ac)==0xAD03B28D) )
        {
            Unp->DepAdr=0x334;
            Unp->EndAdr=0x2d;
            Unp->StrMem=mem[0x89a]|mem[0x89b]<<8;
            Unp->RetAdr=mem[0x8d2]|mem[0x8d3]<<8;
            if(Unp->info->run == -1)
            {
                Unp->Forced=0x817;
            }
            PrintInfo(Unp,_I_MATCFLEX);
            Unp->IdFlag=1;return;
        }
    }
}
