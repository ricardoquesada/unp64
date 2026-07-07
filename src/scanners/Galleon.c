/* Galleon eq chars */
#include "../unp64.h"
void Scn_Galleon(unpstr *Unp)
{
    unsigned char *mem;
    int q,p;
    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x80b)==0xe67800A2) &&
            (*(unsigned int*)(mem+0x814)==0x2E852D84) &&
            (*(unsigned int*)(mem+0x820)==0x00E44CF7) )
        {
            p=mem[0x819]|mem[0x81a]<<8;
            if((*(unsigned int*)(mem+p     )==0x06D0E1A5) &&
               (*(unsigned int*)(mem+p+0x30)==0xF0F5D0CA) )
            {
                Unp->DepAdr=0x109;
                Unp->Forced=0x80b;
                for(q=p+0x3a;q<p+0x4a;q++)
                {
                    /* if there's a ldy before the end must be patched */
                    if((mem[q]==0xa9)||
                       (mem[q]==0x85))
                    {
                        q++;
                        continue;
                    }
                    if(mem[q]==0xa0)
                    {
                        mem[q]=0x24;
                        q++;
                        continue;
                    }
                    if((mem[q]==0x8d)||
                       (mem[q]==0x8c) )
                    {
                        q+=2;
                        continue;
                    }
                    if(mem[q]==0x4c)
                    {
                        Unp->RetAdr=mem[q+0x1]|mem[q+2]<<8;
                        break;
                    }
                }
                Unp->fStrAf=0xfe;
                Unp->StrAdC=EA_ADDFF|EA_USE_Y|0xffff;
                Unp->EndAdr=mem[0x811]|mem[0x813]<<8;

                PrintInfo(Unp,_I_GALLEONEQ);
                Unp->IdFlag=1;return;
            }
        }
    }
    /* Galleon Compactor v3.7 */
    if( Unp->DepAdr==0 )
    {
        for(p=0x801;p<0x80c;p+=0x0a)
        {
            if( (*(unsigned int*)(mem+p+0x00)==0x7FA200A0) &&
               ((*(unsigned int*)(mem+p+0x04)&0xfff0ffff)==0x0810BD9A) &&
                (*(unsigned int*)(mem+p+0x14)==0xAF84AE84) &&
                (*(unsigned int*)(mem+p+0x6c)==0x01692001) )
            {
                Unp->DepAdr=0x100;
                break;
            }
        }
        if(Unp->DepAdr)
        {
            Unp->Forced=p;
            Unp->RetAdr=mem[p+0x78]|mem[p+0x79]<<8;
            Unp->EndAdr=0x2d;
            Unp->StrMem=mem[p+0x39]|mem[p+0x3b]<<8;
            PrintInfo(Unp,_I_GALLCP37);
            Unp->IdFlag=1;return;
        }
    }

    /* Galleon Compactor v3.8 (sysless/loadback) */
    if( Unp->DepAdr==0 )
    {
        p=Unp->info->start;
        for(q=p+0x30;p<q;p++)
        {
            if( (*(unsigned int*)(mem+p     )==0xAE8401E6) &&
                (*(unsigned int*)(mem+p+0x04)==0xAEA5AF84) &&
                (*(unsigned int*)(mem+p+0x08)==0xAFC602D0) &&
                (*(unsigned int*)(mem+p+0x0c)==0x2DA5AEC6) &&
                (*(unsigned int*)(mem+p+0x6e)==0x60AFE602) )
            {
                Unp->IdFlag=_I_GALLCP38;
                break;
            }
        }
        if( Unp->IdFlag )
        {
            Unp->IdFlag=0;
            for(q=Unp->info->start;q<p;q++)
            {
                if(*(unsigned int*)(mem+q)==0xBD9A5FA2)
                {
                    Unp->Forced=q;
                    Unp->DepAdr=0x100;
                    break;
                }
            }
            Unp->RetAdr=mem[p+0x69]|mem[p+0x6a]<<8;
            Unp->EndAdr=0x2d;
            Unp->StrMem=mem[p+0x2a]|mem[p+0x2c]<<8;
            PrintInfo(Unp,_I_GALLCP38);
            Unp->IdFlag=1;return;
        }
    }
    /* Galleon Compactor v3.9 sysless */
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x803)==0x11BD2DA4) &&
            (*(unsigned int*)(mem+0x807)==0x03FF9D08) &&
            (*(unsigned int*)(mem+0x86f)==0xD0D00469) &&
            (*(unsigned int*)(mem+0x80f)==0xE604004C) )
        {
            Unp->DepAdr=0x400;
            Unp->Forced=0x803;
            Unp->RetAdr=mem[0x879]|mem[0x87a]<<8;
            Unp->EndAdr=0x2d;
            Unp->StrMem=mem[0x83c]|mem[0x83e]<<8;
            PrintInfo(Unp,_I_GALLCP39);
            Unp->IdFlag=1;return;
        }
    }
    /* Galleon FW 4codes zipper; can be at $xx01 */
    if( Unp->DepAdr==0 )
    {
        p=Unp->info->start;
        for(q=p+0x10;p<q;p++)
        {
            if( (*(unsigned int*)(mem+p     )==0xA97800A0) &&
                (*(unsigned int*)(mem+p+0x04)==0xA2018534) &&
                (*(unsigned int*)(mem+p+0x08)==0x9D2CB569) &&
                (*(unsigned int*)(mem+p+0x80)==0x950102BD) )
            {
                Unp->DepAdr=0x02f;
                break;
            }
        }
        if( Unp->DepAdr )
        {
            Unp->Forced=p;
            Unp->RetAdr=mem[p+0x8a]|mem[p+0x8b]<<8;
            Unp->EndAdr=0x2d;
            /*memset(mem+p+0x80,0xea,8);*/ /* destroys the unpacker, just in case */
            Unp->StrMem=mem[p+0x57]|mem[p+0x58]<<8;
            PrintInfo(Unp,_I_GALLFW4C);
            Unp->IdFlag=1;return;
        }
    }
    /* Galleon FW 4codes zipper v2.x ? */
    if( Unp->DepAdr==0 )
    {
        p=Unp->info->start;
        for(q=p+0x10;p<q;p++)
        {
            if( (*(unsigned int*)(mem+p     )==0x4e7800A0) &&
                (*(unsigned int*)(mem+p+0x09)==0x2CB57AA2) &&
                (*(unsigned int*)(mem+p+0x0d)==0xBD01009D) &&
                (*(unsigned int*)(mem+p+0x29)==0x002F4C01) )
            {
                Unp->DepAdr=0x02f;
                break;
            }
        }
        if( Unp->DepAdr )
        {
            Unp->Forced=p;
            Unp->RetAdr=mem[p+0x73]|mem[p+0x74]<<8;
            Unp->EndAdr=0x2d;
            Unp->StrMem=mem[p+0x2d]|mem[p+0x2e]<<8;
            PrintInfo(Unp,_I_GALLFW4C2);
            Unp->IdFlag=1;return;
        }
    }
    /* Galleon Byteraper
       there is a jsr $ff5b that clears the screen.
       bytes on screen NEED to be $20. now jsr $e544/ff5b simulated by filling $0400
    */
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x811 )==0x20A28078) &&
            (*(unsigned int*)(mem+0x815 )==0xD0CAFF5B) &&
            (*(unsigned int*)(mem+0x821 )==0xD0CAD99C) &&
            (*(unsigned int*)(mem+0x825 )==0xAFAD80FA) )
        {
            p=mem[0x829]|mem[0x82a]<<8;
            if( (*(unsigned int*)(mem+p+1)==0x06D0FEA5) &&
                (*(unsigned int*)(mem+p-4)==0x01114C2E) )
            {
                Unp->DepAdr=0x111;
                Unp->Forced=0x811;
                Unp->EndAdr=0x2d;
                Unp->RetAdr=mem[p+0x53]|mem[p+0x54]<<8;
                PrintInfo(Unp,_I_GALLBRPR);
                Unp->IdFlag=1;return;
            }
        }
    }
    /* Galleon fw4 3.x? */
    if( Unp->DepAdr==0 )
    {
        p=Unp->info->start;
        for(q=p+0x10;p<q;p++)
        {
            if( (*(unsigned short int*)(mem+p     )==0x00a0) &&
                (*(unsigned short int*)(mem+p+0x08)==0xa278) &&
                (*(unsigned int*)(mem+p+0x0e)==0xCA002B9D) &&
                (*(unsigned int*)(mem+p+0x1b)==0x002F4C01) &&
                (*(unsigned int*)(mem+p+0x64)==0xAA00A820) )
            {
                Unp->DepAdr=0x02f;
                break;
            }
        }
        if( Unp->DepAdr )
        {
            Unp->Forced=p;
            Unp->RetAdr=mem[p+0x62]|mem[p+0x63]<<8;
            Unp->EndAdr=0x2d;
            Unp->StrMem=mem[p+0x20]|mem[p+0x21]<<8;
            PrintInfo(Unp,_I_GALLFW4C3);
            Unp->IdFlag=1;return;
        }
    }
    /* Galleon fw4 3.1? */
    if( Unp->DepAdr==0 )
    {
        p=Unp->info->start;
        for(q=p+0x10;p<q;p++)
        {
            if( (*(unsigned short int*)(mem+p     )==0x00a2) &&
                (*(unsigned short int*)(mem+p+0x08)==0xbd78) &&
                (*(unsigned int*)(mem+p+0x0c)==0xCA002B9D) &&
                (*(unsigned int*)(mem+p+0x1c)==0x0400354C) &&
                (*(unsigned int*)(mem+p+0x6d)==0xAA00A820) )
            {
                Unp->DepAdr=0x035;
                break;
            }
        }
        if( Unp->DepAdr )
        {
            Unp->Forced=p;
            Unp->RetAdr=mem[p+0x6b]|mem[p+0x6c]<<8;
            Unp->EndAdr=0x2d;
            Unp->StrMem=mem[p+0x20]|mem[p+0x21]<<8;
            PrintInfo(Unp,_I_GALLFW4C31);
            Unp->IdFlag=1;return;
        }
    }
    /* Unknown $02 */
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x80b)==0xE67800A0) &&
            (*(unsigned int*)(mem+0x813)==0x0195081C) &&
            (*(unsigned int*)(mem+0x83f)==0x5420E7D0) &&
            (*(unsigned int*)(mem+0x873)==0x0EC60FC6) )
        {
            Unp->DepAdr=0x002;
            Unp->Forced=0x80b;
            Unp->RetAdr=mem[0x87e]|mem[0x87f]<<8;
            Unp->EndAdr=mem[0x834]|mem[0x835]<<8;Unp->EndAdr++;
            Unp->fStrAf=0x19;
            Unp->StrAdC=EA_USE_Y;
            PrintInfo(Unp,_I_GALLU02);
            Unp->IdFlag=1;return;
        }
    }
    /* Unknown $100 very similar to $02, sysless */
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x805)==0x00A001E6) &&
            (*(unsigned int*)(mem+0x809)==0x990815B9) &&
            (*(unsigned int*)(mem+0x80d)==0xD0C800FC) &&
            (*(unsigned int*)(mem+0x845)==0x2BF00150) )
        {
            Unp->DepAdr=0x100;
            Unp->Forced=0x805;
            Unp->RetAdr=mem[0x87e]|mem[0x87f]<<8;
            Unp->EndAdr=mem[0x817]|mem[0x818]<<8;Unp->EndAdr++;
            Unp->fStrAf=0xfe;
            Unp->StrAdC=EA_USE_Y;
            PrintInfo(Unp,_I_GALLU100);
            Unp->IdFlag=1;return;
        }
    }
    /* Whom Packer v1.x */
    if( Unp->DepAdr==0 )
    {
        if((mem[0x801]==0x78) &&
          ((*(unsigned int*)(mem+0x808)&0x00ffffff)==0x004C01E6))
        {
            p=mem[0x80b]|mem[0x80c]<<8;

            if( (mem[p]==0xa9) && (mem[p+2]==0xa2) &&
                (*(unsigned int*)(mem+p+0x04)==0x2E862D85) &&
                (*(unsigned int*)(mem+p+0x6a)==0xB18812F0) &&
                (*(unsigned int*)(mem+p+0x7a)==0xB1F0A6D0) )
            {
                Unp->DepAdr=mem[p+0x20]|mem[p+0x21]<<8; /* $a1 or $02 */
                Unp->Forced=0x801;
                Unp->RetAdr=mem[p+0x8a]|mem[p+0x8b]<<8;
                Unp->EndAdr=mem[p+1]|mem[p+3]<<8;
                Unp->fStrAf=mem[p+0x36];
                Unp->StrAdC=EA_ADDFF|0xffff;
                PrintInfo(Unp,_I_GALLWHOM1);
                Unp->IdFlag=1;return;
            }
            if( (mem[p]==0xa9) && (mem[p+2]==0xa2) &&
                (*(unsigned int*)(mem+p+0x04)==0x2E862D85) &&
                (*(unsigned int*)(mem+p+0x68)==0xB1881dF0) &&
                (*(unsigned int*)(mem+p+0x83)==0xA8F09DD0) )
            {
                Unp->DepAdr=mem[p+0x20]|mem[p+0x21]<<8; /* $e3 */
                Unp->Forced=0x801;
                Unp->RetAdr=mem[p+0x93]|mem[p+0x94]<<8;
                Unp->EndAdr=mem[p+1]|mem[p+3]<<8;
                Unp->fStrAf=mem[p+0x36];
                Unp->StrAdC=EA_USE_Y|EA_ADDFF|0xffff;
                PrintInfo(Unp,_I_GALLWHOM11);
                Unp->IdFlag=1;return;
            }
            if( (mem[p]==0xa0) && (mem[p+2]==0xb9) &&
                (*(unsigned int*)(mem+p+0x05)==0xC0000199) &&
                (*(unsigned int*)(mem+p+0x62)==0xB18812F0) &&
                (*(unsigned int*)(mem+p+0x72)==0xB1F0A6D0) )
            {
                Unp->DepAdr=0x02;
                Unp->Forced=0x801;
                for(q=p+0x82;q<p+0x8a;q++)
                {
                    if(mem[q]==0x4c)
                    {
                        Unp->RetAdr=mem[q+1]|mem[q+2]<<8;
                        break;
                    }
                }
                Unp->EndAdr=0x2d;
                Unp->fStrAf=mem[p+0x2e];
                Unp->StrAdC=EA_ADDFF|0xffff;
                PrintInfo(Unp,_I_GALLWHOM2);
                Unp->IdFlag=1;return;
            }
        }
    }
    /* Whom Packer v4.x (sys and sysless) */
    if( Unp->DepAdr==0 )
    {
        Unp->IdFlag=0;
        p=0;
        if((*(unsigned int*)(mem+0x801)==0xCA7800A2) &&
          ((*(unsigned int*)(mem+0x80c)&0x00ffffff)==0x004C01E6))
        {
            p=mem[0x80f]|mem[0x810]<<8;
            Unp->IdFlag=_I_GALLWHOM4S;
            Unp->Forced=0x801;
        }
        if((*(unsigned int*)(mem+0x80b)==0xCA7800A2) &&
          ((*(unsigned int*)(mem+0x816)&0x00ffffff)==0x004C01E6))
        {
            p=mem[0x819]|mem[0x81a]<<8;
            Unp->IdFlag=_I_GALLWHOM4;
            Unp->Forced=0x80b;
        }
        if(Unp->IdFlag)
        {
            if( (mem[p]==0xa9) && (mem[p+2]==0xa2) &&
                (*(unsigned int*)(mem+p+0x04)==0x2E862D85) &&
                (*(unsigned int*)(mem+p+0x81)==0x38FEA5FE) &&
                (*(unsigned int*)(mem+p+0x91)==0x9CF091D0) )
            {
                Unp->DepAdr=0x0f2;
                Unp->RetAdr=mem[p+0xa3]|mem[p+0xa4]<<8;
                Unp->EndAdr=mem[p+1]|mem[p+3]<<8;
                Unp->fStrAf=0xfe;
                Unp->StrAdC=EA_USE_X|EA_ADDFF|0xffff;
                PrintInfo(Unp,Unp->IdFlag);
                Unp->IdFlag=1;return;
            }
            else
                Unp->IdFlag=0;
        }
    }
    /* galleon 3.6 (always at $2001) and other sysless/loadback variants */
    if( Unp->DepAdr==0 )
    {
        p=Unp->info->start;
        for(q=p+0x30;p<q;p++)
        {
            if( (*(unsigned int*)(mem+p     )==0x8401E678) &&
                (*(unsigned int*)(mem+p+0x04)==0xA5AF84AE) &&
                (*(unsigned int*)(mem+p+0x08)==0xC602D0AE) &&
                (*(unsigned int*)(mem+p+0x0c)==0xA5AEC6AF) &&
                (*(unsigned int*)(mem+p+0x6c)==0x60AFE602) )
            {
                Unp->IdFlag=_I_GALLCP36;
                break;
            }
        }
        if( Unp->IdFlag )
        {
            Unp->IdFlag=0;
            for(q=Unp->info->start;q<p;q++)
            {
                if(((mem[q]==0xa0)||(mem[q]==0xa2))&&
                   (mem[q+1]==0x00)&&(Unp->Forced==0))
                {
                    Unp->Forced=q;
                    q++;
                    continue;
                }
                if((mem[q]==0xbd)||
                   (mem[q]==0xb9)||
                   (mem[q]==0x9d)||
                   (mem[q]==0x99))
                {
                    q+=2;
                    continue;
                }
                if(mem[q]==0x4c)
                {
                    Unp->DepAdr=mem[q+1]|mem[q+2]<<8;
                    break;
                }
            }
            Unp->RetAdr=mem[p+0x67]|mem[p+0x68]<<8;
            Unp->EndAdr=0x2d;
            Unp->StrMem=mem[p+0x28]|mem[p+0x2a]<<8;
            PrintInfo(Unp,_I_GALLCP36);
            Unp->IdFlag=1;return;
        }
    }
    /* 3.5? seems an hack judging from the 2 nops and different zp locs */
    if( Unp->DepAdr==0 )
    {
        p=Unp->info->start;
        for(q=p+0x30;p<q;p++)
        {
            if( (*(unsigned int*)(mem+p     )==0xA0EAEA78) &&
                (*(unsigned int*)(mem+p+0x04)==0x84AC8400) &&
                (*(unsigned int*)(mem+p+0x08)==0xD0ACA5AD) &&
                (*(unsigned int*)(mem+p+0x0c)==0xC6ADC602) &&
                (*(unsigned int*)(mem+p+0x6e)==0x60ADE602) )
            {
                Unp->IdFlag=_I_GALLCP35;
                break;
            }
        }
        if( Unp->IdFlag )
        {
            Unp->IdFlag=0;
            for(q=Unp->info->start;q<p;q++)
            {
                if(*(unsigned int*)(mem+q)==0x018538A9)
                {
                    Unp->Forced=q;
                    Unp->DepAdr=mem[q+0x12]|mem[q+0x13]<<8;
                    break;
                }
            }
            Unp->RetAdr=mem[p+0x69]|mem[p+0x6a]<<8;
            Unp->EndAdr=0x2d;
            Unp->StrMem=mem[p+0x2a]|mem[p+0x2c]<<8;
            PrintInfo(Unp,_I_GALLCP35);
            Unp->IdFlag=1;return;
        }
    }
    /* seems derived from galleon comp 3.6 */
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x801)==0x11BD00A2) &&
            (*(unsigned int*)(mem+0x805)==0x01009D08) &&
            (*(unsigned int*)(mem+0x851)==0xCA017220) &&
            (*(unsigned int*)(mem+0x861)==0x6B20AAAC) )
        {
            Unp->Forced=0x801;
            Unp->DepAdr=0x100;
            Unp->RetAdr=mem[0x87a]|mem[0x87b]<<8;
            Unp->StrMem=mem[0x83b]|mem[0x83d]<<8;
            Unp->EndAdr=0x2d;
            PrintInfo(Unp,_I_GALLCP3X);
            Unp->IdFlag=1;return;
        }
    }
    /* Alvestalink doesn't work if loadback is !=$08, and also uses code at $d000 (VIC sprite regs) */
    if( Unp->DepAdr==0 )
    {
        p=Unp->info->start;
        for(q=p+0x30;p<q;p++)
        {
            if(((*(unsigned int*)(mem+p     )&0x0000ffff)==0x000000A0) &&
                (*(unsigned int*)(mem+p+0x0a)==0x9D2CB567) &&
                (*(unsigned int*)(mem+p+0x0e)==0x39BD0100) &&
                (*(unsigned int*)(mem+p+0x26)==0x002F4C01) &&
                (*(unsigned int*)(mem+p+0x6a)==0xD0004C01) )
            {
                Unp->IdFlag=_I_GALLVEST;
                break;
            }
        }
        if( Unp->IdFlag )
        {
            mem[p+0x1b]=mem[p+0x12]; // bug in the original, works only at $0801
            mem[p+0x1e]=0x1; // copy last part at $0200 instead of $d000
            mem[p+0x6d]=0x2; // and execute it there
            Unp->Forced=p;
            Unp->RtAFrc=1;
            Unp->DepAdr=0x2f;
            Unp->RetAdr=mem[p+0x37]|mem[p+0x38]<<8;
            Unp->EndAdr=0x2d;
            Unp->StrMem=mem[p+0x39]|mem[p+0x3a]<<8;
            PrintInfo(Unp,_I_GALLVEST);
            Unp->IdFlag=1;return;
        }
    }
}
