/* DarkSqueezer 0.x */
#include "../unp64.h"
void Scn_DarkSqueezer(unpstr *Unp)
{
    unsigned char *mem;
    int p;
    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x80f)==0x9AFFA278) &&
           (*(unsigned int*)(mem+0x813)==0x22B900A0) &&
           (*(unsigned int*)(mem+0x817)==0x00F99908) &&
           (*(unsigned int*)(mem+0x81b)==0x84F7D0C8) &&
           (*(unsigned int*)(mem+0x900)==0xD088FC91) )
        {
            Unp->DepAdr=0x100;
            Unp->Forced=0x80f;
            Unp->RetAdr=mem[0x918]|mem[0x919]<<8;
            Unp->EndAdr=mem[0x825]|mem[0x826]<<8;Unp->EndAdr++;
            Unp->fStrAf=0xfc;
            PrintInfo(Unp,_I_DARKSQ08);
            Unp->IdFlag=1;return;
        }
    }
    /* DarkSqueezer 2.0/2.1, there is no 1.0 ID, it's == time 3.1 (3x/2072) */
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x815)==0x0828BD78) &&
           (*(unsigned int*)(mem+0x819)==0xBD00FB9D) &&
           (*(unsigned int*)(mem+0x81d)==0x359D0862) &&
           (*(unsigned int*)(mem+0x821)==0xF1D0E801) &&
           (*(unsigned int*)(mem+0x900)==0xFC85F7E5) )
        {
            Unp->DepAdr=0x200;
            Unp->Forced=0x813;
            if(mem[0x813]!=0xa0)
                Unp->Forced=0x815;
            Unp->RetAdr=mem[0x95d]|mem[0x95e]<<8;
            Unp->EndAdr=mem[0x829]|mem[0x82a]<<8;
            Unp->fStrAf=0xfc;
            Unp->StrAdC=0xffff;
            PrintInfo(Unp,_I_DARKSQ21);
            Unp->IdFlag=1;return;
        }
    }
    /* Darksqueezer 2.x */
    if( Unp->DepAdr==0 )
    {
        if((mem[0x80b]==0xA0) &&
           (*(unsigned int*)(mem+0x810)==0x99081CB9) &&
           (*(unsigned int*)(mem+0x818)==0x01004CF7) &&
           (*(unsigned int*)(mem+0x824)==0xC807EE99) &&
           (*(unsigned int*)(mem+0x82b)==0x016F20F7) )
        {
            Unp->EndAdr=mem[0x81d]|mem[0x81e]<<8;Unp->EndAdr++;
            Unp->DepAdr=0x100;
            Unp->Forced=0x80b;
            Unp->RetAdr=mem[0x8af]|mem[0x8b0]<<8;
            Unp->fStrAf=0xfc;
            PrintInfo(Unp,_I_DARKSQ2X);
            Unp->IdFlag=1;return;
        }
    }
    /* DarkSqueezer v4 */
    if( Unp->DepAdr==0 )
    {
        if((mem[0x80b]==0xA2) && (mem[0x81a]==0x4c) &&
           (*(unsigned int*)(mem+0x810)==0x9d081DBD) &&
           (*(unsigned int*)(mem+0x814)==0xE89A00FA) &&
           (*(unsigned int*)(mem+0x8eb)==0xb1fcc602) &&
           (*(unsigned int*)(mem+0x82b)==0xf1d0e808) )
        {
            Unp->EndAdr=mem[0x81e]|mem[0x81f]<<8;Unp->EndAdr++;
            Unp->DepAdr=0xfd ;
            Unp->Forced=0x80b;
            Unp->RetAdr=mem[0x8ca]|mem[0x8cb]<<8;
            Unp->fStrAf=0xfb;
            Unp->StrAdC=0xffff;
            PrintInfo(Unp,_I_DARKSQ4);
            Unp->IdFlag=1;return;
        }
    }
    /* DarkSqueezer v4 / Sharks */
    if( Unp->DepAdr==0 )
    {
        if((mem[0x80b]==0xA2) && (mem[0x81a]==0x4c) &&
           (*(unsigned int*)(mem+0x810)==0x9d081DBD) &&
           (*(unsigned int*)(mem+0x814)==0xE89A00FA) &&
           (*(unsigned int*)(mem+0x8e3)==0xb1fcc602) &&
           (*(unsigned int*)(mem+0x82b)==0xf1d0e808) )
        {
            Unp->EndAdr=mem[0x81e]|mem[0x81f]<<8;Unp->EndAdr++;
            Unp->DepAdr=0xfd ;
            Unp->Forced=0x80b;
            Unp->RetAdr=mem[0x8c2]|mem[0x8c3]<<8;
            Unp->fStrAf=0xfb;
            //Unp->StrAdC=0xffff;
            PrintInfo(Unp,_I_DARKSQ4SHK);
            Unp->IdFlag=1;return;
        }
    }
    /* DarkSqueezer f4cg? */
    if( Unp->DepAdr==0 )
    {
        if((mem[0x80b]==0xA2) && (mem[0x81a]==0x4c) &&
           (*(unsigned int*)(mem+0x810)==0x9d081DBD) &&
           (*(unsigned int*)(mem+0x814)==0xE89A00Fb) &&
           (*(unsigned int*)(mem+0x8f1)==0xb1fdc602) &&
           (*(unsigned int*)(mem+0x82d)==0xf1d0e808) )
        {
            Unp->EndAdr=mem[0x81e]|mem[0x81f]<<8;Unp->EndAdr++;
            Unp->DepAdr=0x100 ;
            Unp->Forced=0x80b;
            Unp->RetAdr=mem[0x8ca]|mem[0x8cb]<<8;
            Unp->fStrAf=0xfc;
            Unp->StrAdC=0xffff;
            PrintInfo(Unp,_I_DARKSQF4  );
            Unp->IdFlag=1;return;
        }
    }
    /* DarkSqueezer hack found in Extacy and Collision warez */
    if( Unp->DepAdr==0 )
    {
        if((mem[0x80b]==0xA2) && (mem[0x81a]==0x4c) &&
           (*(unsigned int*)(mem+0x810)==0x9d081DBD) &&
           ((*(unsigned int*)(mem+0x814)&0xff0fffff)==0xE80A00FB) &&
           (*(unsigned int*)(mem+0x8ff)==0x60ED10F8) &&
           (*(unsigned int*)(mem+0x82d)==0xf1d0e808) )
        {
            Unp->EndAdr=mem[0x81e]|mem[0x81f]<<8;Unp->EndAdr++;
            Unp->DepAdr=0x100;
            Unp->Forced=0x80b;
            Unp->RetAdr=mem[0x8c7]|mem[0x8c8]<<8;
            Unp->fStrAf=0xfc;
            PrintInfo(Unp,_I_DARKSQXTC );
            Unp->IdFlag=1;return;
        }
    }
    /* DarkSqueezer/Darkfiler 1.0 by THCM hack found in Xfactor and WOW warez */
    if( Unp->DepAdr==0 )
    {
        if(((*(unsigned int*)(mem+0x80b)&0x00ffffff)==0x007800A0) &&
           ((*(unsigned int*)(mem+0x814)&0x00ffffff)==0x00B901E6) &&
           (*(unsigned int*)(mem+0x819)==0xC800FB99) &&
           (*(unsigned int*)(mem+0x81d)==0x004CF7D0) )
        {
            p=mem[0x817]|mem[0x818]<<8;
            if((*(unsigned int*)(mem+p+0x08)==0xC8072299) &&
               (*(unsigned int*)(mem+p+0x0c)==0x8498F7D0) &&
               (*(unsigned int*)(mem+p+0xa7)==0x4C01C668) )
            {
                Unp->DepAdr=0x100;
                Unp->EndAdr=mem[p+1]|mem[p+2]<<8;
                Unp->Forced=0x80b;
                Unp->RetAdr=mem[p+0xab]|mem[p+0xac]<<8;
                Unp->fStrAf=0xfc;
                Unp->StrAdC=0xffff;
                PrintInfo(Unp,_I_DARKSQWOW  );
                Unp->IdFlag=1;return;
            }
        }
    }
    /* DarkSqueezer 2.2/2.2+/Unknown hacks, at least 3 types are covered by this code */
    if( Unp->DepAdr==0 )
    {
        if((mem[0x81a]==0x4c) &&
           (*(unsigned int*)(mem+0x810)==0x9d081DBD) &&
          ((*(unsigned int*)(mem+0x814)&0xff0fffff)==0xE80A00FB) &&
           (*(unsigned int*)(mem+0x8fc)==0x60ED10F8) &&
           (*(unsigned int*)(mem+0x82d)==0xf1d0e808) )
        {
            Unp->EndAdr=mem[0x81e]|mem[0x81f]<<8;Unp->EndAdr++;
            Unp->DepAdr=0x100;
            if(Unp->info->run == -1)
                Unp->Forced=0x80b;
            Unp->RetAdr=mem[0x8c4]|mem[0x8c5]<<8;
            Unp->fStrAf=0xfc;
            PrintInfo(Unp,_I_DARKSQ22);
            Unp->IdFlag=1;return;
        }
    }
    /* Darksqueezer 2.x / G*P */
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x80b)==0x847800A0) &&
           (*(unsigned int*)(mem+0x80f)==0x081CB901) &&
           (*(unsigned int*)(mem+0x818)==0x01004CF7) &&
           (*(unsigned int*)(mem+0x84f)==0xB0017520) )
        {
            Unp->EndAdr=mem[0x81d]|mem[0x81e]<<8;Unp->EndAdr++;
            Unp->DepAdr=0x100;
            Unp->Forced=0x80b;
            Unp->RetAdr=mem[0x8b7]|mem[0x8b8]<<8;
            Unp->fStrAf=0xfc;
            PrintInfo(Unp,_I_DARKSQGP );
            Unp->IdFlag=1;return;
        }
    }
    /* ByteBonker, very similar to ds 0.x */
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x80d)==0x9AFFA278) &&
           (*(unsigned int*)(mem+0x811)==0x20B900A0) &&
           (*(unsigned int*)(mem+0x815)==0x00F99908) &&
           (*(unsigned int*)(mem+0x819)==0x84F7D0C8) &&
           (*(unsigned int*)(mem+0x8ee)==0xD088FC91) )
        {
            Unp->DepAdr=0x100;
            Unp->Forced=0x80d;
            Unp->RetAdr=mem[0x906]|mem[0x907]<<8;
            Unp->EndAdr=mem[0x823]|mem[0x824]<<8;Unp->EndAdr++;
            /*Unp->fStrAf=0xfc; no need, packs always from $0801!*/
            Unp->StrMem=0x801;
            PrintInfo(Unp,_I_DARKSQBB1 );
            Unp->IdFlag=1;return;
        }
    }
    /* DarkSqueezer 2.x / DOM */
    if( Unp->DepAdr==0 )
    {
        if((mem[0x81a]==0x4c) &&
           (*(unsigned int*)(mem+0x810)==0x9d081DBD) &&
          ((*(unsigned int*)(mem+0x814)&0xff0fffff)==0xE80A00FB) &&
           (*(unsigned int*)(mem+0x846)==0xA901AD20) &&
           (*(unsigned int*)(mem+0x8fc)==0xFDC6F9B1) )
        {
            Unp->DepAdr=0x100;
            if(Unp->info->run == -1)
                Unp->Forced=0x80b;
            Unp->RetAdr=mem[0x8c7]|mem[0x8c8]<<8;
            Unp->EndAdr=mem[0x81e]|mem[0x81f]<<8;Unp->EndAdr++;
            Unp->fStrAf=0xfc;
            Unp->StrAdC=0xffff;
            PrintInfo(Unp,_I_DARKSQDOM);
            Unp->IdFlag=1;return;
        }
    }
    /* DarkSqueezer 2.x / Paradroid */
    if( Unp->DepAdr==0 )
    {
        if((mem[0x81c]==0x4c) && (mem[0x81d]==0xfa) &&
           (*(unsigned int*)(mem+0x810)==0x9d081fBD) &&
           (*(unsigned int*)(mem+0x814)==0xE89A00F5) &&
           (*(unsigned int*)(mem+0x848)==0x8a01A120) &&
           (*(unsigned int*)(mem+0x8eb)==0xB188F7C6) )
        {
            Unp->DepAdr=0xfa;
            if(Unp->info->run == -1)
                Unp->Forced=0x80b;
            Unp->RetAdr=mem[0x8c9]|mem[0x8ca]<<8;
            Unp->EndAdr=mem[0x820]|mem[0x821]<<8;
            Unp->fStrAf=0xf6;
            Unp->StrAdC=0xffff;
            PrintInfo(Unp,_I_DARKSQPAR);
            Unp->IdFlag=1;return;
        }
    }
    /* ByteBonker? similar but enough different/hacked */
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x80d)==0x9AFFA278) &&
           (*(unsigned short int*)(mem+0x80b)==0x00a0) &&
           (*(unsigned short int*)(mem+0x811)==0x20B9) &&
           (*(unsigned int*)(mem+0x813)==0x00F99908) &&
           (*(unsigned int*)(mem+0x817)==0x20F7D0C8) &&
           (*(unsigned int*)(mem+0x8ee)==0xD088FC91) )
        {
            Unp->DepAdr=0x100;
            Unp->Forced=0x80b;
            Unp->RetAdr=mem[0x906]|mem[0x907]<<8;
            Unp->EndAdr=mem[0x823]|mem[0x824]<<8;Unp->EndAdr++;
            /*Unp->fStrAf=0xfc; no need, packs always from $0801!*/
            Unp->StrMem=0x801;
            PrintInfo(Unp,_I_DARKSQBB2 );
            if(Unp->DebugP)
                printmsg(mem,(mem[0x91f]|mem[0x920]<<8),mem[0x91d]+1);
            Unp->IdFlag=1;return;
        }
    }
}
