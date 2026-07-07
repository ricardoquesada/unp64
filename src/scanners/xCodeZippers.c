/* various zippers (multiple-codes charpackers) */
#include "../unp64.h"
void Scn_xCodeZippers(unpstr *Unp)
{
    unsigned char *mem;
    int q,p;
    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    /* 3codezipper/REM */
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x790)==0x01A001A2) &&
           (*(unsigned int*)(mem+0x794)==0xC907D920) &&
           (*(unsigned int*)(mem+0x7E0)==0x07E5CE07) &&
           (*(unsigned int*)(mem+0x7D3)==0x4CBAD007) )
        {
            Unp->DepAdr=0x790;
            Unp->Forced=0x790;
            Unp->RetAdr=mem[0x7d7]|mem[0x7d8]<<8;
            Unp->EndAdr=mem[0x7b3]|mem[0x7b4]<<8;Unp->EndAdr++;
            Unp->fStrAf=0x7b3;
            PrintInfo(Unp,_I_3CZIP );
            Unp->IdFlag=1;return;
        }
    }
    /* 4codezipper 2.0/Oneway, zp version */
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x803)==0x078FBC78) &&
           (*(unsigned int*)(mem+0x807)==0x30CA8194) &&
           (*(unsigned int*)(mem+0x80b)==0x00024CF8) &&
           (*(unsigned int*)(mem+0x846)==0x42C707A9) )
        {
            Unp->DepAdr=0x002;
            Unp->Forced=0x803;
            q=mem[0x80f]&0xff;
            Unp->RetAdr=mem[0x840]|mem[0x841]<<8;
            Unp->EndAdr=mem[0x82f]|mem[0x830]<<8;Unp->EndAdr+=q;
            Unp->fStrAf=0x21;
            Unp->StrAdC=0xffff|EA_ADDFF|EA_USE_Y;
            PrintInfo(Unp,_I_4CZIP );
            Unp->IdFlag=1;return;
        }
    }
    /* 4codezipper 2.s/Oneway, stack version */
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x803)==0x0810BD78) &&
           (*(unsigned int*)(mem+0x807)==0xE800FE9D) &&
           (*(unsigned int*)(mem+0x80b)==0x004CF710) &&
           (*(unsigned int*)(mem+0x857)==0x01332060) )
        {
            Unp->DepAdr=0x100;
            Unp->Forced=0x803;
            q=mem[0x813]&0xff;
            Unp->RetAdr=mem[0x843]|mem[0x844]<<8;
            Unp->EndAdr=mem[0x810]|mem[0x811]<<8;Unp->EndAdr+=q;
            Unp->fStrAf=0xfe;
            Unp->StrAdC=EA_USE_Y;
            PrintInfo(Unp,_I_4CZIP2S );
            Unp->IdFlag=1;return;
        }
    }
    /* X-Terminator/FLT */
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x801)==0xE67800A0) &&
           (*(unsigned int*)(mem+0x805)==0x080ECE01) &&
           (*(unsigned int*)(mem+0x809)==0xB90811CE) &&
           (*(unsigned int*)(mem+0x861)==0xF8A5F4D0) )
        {
            Unp->DepAdr=0x100;
            Unp->Forced=0x801;
            Unp->RetAdr=mem[0x86d]|mem[0x86e]<<8;
            Unp->StrMem=mem[0x858]|mem[0x859]<<8;
            Unp->EndAdC=0xffff|EA_USE_Y;
            Unp->fEndAf=0x121;
            PrintInfo(Unp,_I_XTERM );
            Unp->IdFlag=1;return;
        }
    }
    /* ILS Compacker 2.x, similar to x-terminator
       9code version (2.2) found in:
       Creatures2/ILS (sysless),
       BlackHornet/ILS also with sys
       WrathOTDemon/ILS & BonanzaBros/ILS, slightly diff preamble (3.x?)
       8code version also found in at least 3 other warez (2.1)
    */
    if( Unp->DepAdr==0 )
    {
        for(q=Unp->info->start;q<Unp->info->start+0x0c;q++)
        {
            if((*(unsigned int*)(mem+q     )==0xE67800A0) &&
               (*(unsigned int*)(mem+q+0x04)==(((q+0x0d)<<16)|0x0000CE01)) &&
               (*(unsigned int*)(mem+q+0x08)==(((q+0x10)<<8 )|0xB90000CE)) &&
               (*(unsigned int*)(mem+q+0x36)==0xC900F620) )
            {
                Unp->DepAdr=0x100;
                Unp->IdFlag=_I_ILSCOMP2X;
                break;
            }
            if((*(unsigned int*)(mem+q     )==0xa97800A0) &&
               (*(unsigned int*)(mem+q+0x06)==(((q+0x13)<<16)|0x0000b901)) &&
               (*(unsigned int*)(mem+q+0x1d)==0xCE0108CE) &&
               (*(unsigned int*)(mem+q+0x36)==0xC900F620) )
            {
                Unp->DepAdr=0x100;
                Unp->IdFlag=_I_ILSCOMP3X;
                break;
            }
        }
        if( Unp->DepAdr != 0 )
        {
            /* has variable codebytes so addresses varies */
            for(p=q+0x39;p<q+0x69;p+=4)
            {
                if(mem[p]==0xc9)
                    continue;
                if(mem[p]==0x86)
                    continue;
                if(mem[p]==0x99)
                {
                    Unp->DepAdr=0x100;
                    Unp->fEndAf=Unp->DepAdr+mem[p+7]-1;
                    Unp->RetAdr=mem[p+0x18]|mem[p+0x19]<<8;
                    Unp->StrMem=mem[p+0x01]|mem[p+0x02]<<8;
                    Unp->Forced=q;
                    Unp->EndAdC=0xffff|EA_USE_Y;
                    PrintInfo(Unp,Unp->IdFlag);
                    Unp->IdFlag=1;
                    break;
                }
                else
                {
                    Unp->IdFlag=0;
                    Unp->DepAdr=0;
                    break; /* unexpected byte, get out */
                }
            }
            if(Unp->IdFlag)
                return;
        }
    }
    /* Uzzy Packer II/Entropy, $100, 3codes */
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x80D)==0xA2018478) &&
            (*(unsigned int*)(mem+0x811)==0x081FBD5A) &&
            (*(unsigned int*)(mem+0x844)==0xA8014E20) &&
            (*(unsigned int*)(mem+0x848)==0xAA014E20) &&
            (*(unsigned int*)(mem+0x84c)==0x8D014E20)   )
        {
            Unp->DepAdr=0x100;
            Unp->Forced=0x80d;
            Unp->StrMem=mem[0x850]|mem[0x851]<<8;
            Unp->fEndAf=0x131;
            Unp->EndAdC=0xffff; // it's always end+1 at end of decompression
            Unp->RetAdr=mem[0x86b]|mem[0x86c]<<8;
            PrintInfo(Unp,_I_UPACK2);
            Unp->IdFlag=1;return;
        }
    }
    /* rebellic noter/toon noter/alpha noter, all $100*/
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x80D)==0x9AFFA278) &&
            (*(unsigned int*)(mem+0x815)==0x009D0820) &&
            (*(unsigned int*)(mem+0x871)==0xB1017220) &&
            (*(unsigned int*)(mem+0x889)==0x04E6014B) )
        {
            Unp->DepAdr=0x100;
            Unp->Forced=0x80d;
            //Unp->StrMem=mem[0x857]|mem[0x859]<<8; // 0x7fd always?
            Unp->StrMem=0x800;
            Unp->fEndAf=0x04;
            Unp->RetAdr=mem[0x828]|mem[0x829]<<8;
            PrintInfo(Unp,_I_REBELP);
            Unp->IdFlag=1;return;
        }
    }
    /* Plush zipper? found in Plushdos, 2 times, and in Floppy2001demo/FLT*/
    if( Unp->DepAdr==0 )
    {
        q=Unp->info->start;
        for(p=q;p<q+0x10;p++)
        {
            if( (*(unsigned int*)(mem+p     )==0xBD6FA278) &&
                (*(unsigned int*)(mem+p+0x04)==(0x00950000+p+0x0E))&&
                (*(unsigned int*)(mem+p+0x08)==0xA0F8D0CA) &&
                (*(unsigned int*)(mem+p+0x70)==0xC65CC6F7)   )
            {
                Unp->DepAdr=0x5a;
                break;
            }
        }
        if(Unp->DepAdr)
        {
            Unp->Forced=p;
            Unp->StrMem=mem[p+0x18]|mem[p+0x19]<<8;
            Unp->fEndAf=0x0a;
            Unp->RetAdr=mem[p+0x2d]|mem[p+0x2e]<<8;
            PrintInfo(Unp,_I_PLUSHZ);
            Unp->IdFlag=1;return;
        }
        for(p=q;p<q+0x10;p++)
        {
            if( (*(unsigned int*)(mem+p     )==0xBD48A278) &&
                (*(unsigned int*)(mem+p+0x04)==(0x00950000+p+0x0E))&&
                (*(unsigned int*)(mem+p+0x08)==0xA0F8D0CA) &&
                (*(unsigned int*)(mem+p+0x49)==0xC635C6F7)   )
            {
                Unp->DepAdr=0x33;
                break;
            }
        }
        if(Unp->DepAdr)
        {
            Unp->Forced=p;
            Unp->StrMem=mem[p+0x27]|mem[p+0x28]<<8;
            Unp->fEndAf=0x19;
            Unp->RetAdr=mem[p+0x3f]|mem[p+0x40]<<8;
            PrintInfo(Unp,_I_PLUSHZS);
            Unp->IdFlag=1;return;
        }
    }

}
