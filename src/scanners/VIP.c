/* VIP 2.0/Kulfon, improved optimus but at $0801 */
#include "../unp64.h"
void Scn_VIP(unpstr *Unp)
{
    unsigned char *mem;
    int q;
    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        q=0x801;
        if( (*(unsigned int*)(mem+q+0x00)==0xBE7800A0) &&
            (*(unsigned int*)(mem+q+0x04)==0x8196078F) &&
            (*(unsigned int*)(mem+q+0x08)==0x4CF83088) &&
            (*(unsigned int*)(mem+q+0x0c)==0xB9380002) )
         {
            if(*(unsigned int*)(mem+q+0x19)==0xC9002F20)
            {
                Unp->DepAdr=0x02;
                Unp->Forced=q;
                Unp->RetAdr=mem[q+0x4c]|mem[q+0x4d]<<8;
                Unp->EndAdr=mem[q+0x31]|mem[q+0x32]<<8;Unp->EndAdr+=mem[q+0x0e];
                Unp->fStrAf=0x24;
                Unp->StrAdC=0xffff|EA_USE_X;
                PrintInfo(Unp,_I_VIP1X);
                Unp->IdFlag=1;return;
            }
            if(*(unsigned int*)(mem+q+0x1a)==0x15C602D0)
            {
                Unp->DepAdr=0x02;
                Unp->Forced=q;
                Unp->RetAdr=mem[q+0x44]|mem[q+0x45]<<8;
                Unp->EndAdr=mem[q+0x21]|mem[q+0x22]<<8;Unp->EndAdr--;
                Unp->fStrAf=0x14;
                Unp->StrAdC=0xffff;
                PrintInfo(Unp,_I_VIP20);
                Unp->IdFlag=1;return;
            }
            else if(*(unsigned int*)(mem+q+0x1c)==0x0eC602D0)
            {
                Unp->DepAdr=0x02;
                Unp->Forced=q;
                Unp->RetAdr=mem[q+0x39]|mem[q+0x3a]<<8;
                Unp->EndAdr=mem[q+0x1a]|mem[q+0x1b]<<8;Unp->EndAdr+=mem[q+0x0e];Unp->EndAdr--;
                Unp->fStrAf=0x0d;
                Unp->StrAdC=0xffff|EA_USE_X;
                PrintInfo(Unp,_I_TOTP20);
                Unp->IdFlag=1;return;
            }

            else if(*(unsigned int*)(mem+q+0x19)==0xC9002B20)
            {
                Unp->DepAdr=0x02;
                Unp->Forced=q;
                Unp->RetAdr=mem[q+0x48]|mem[q+0x49]<<8;
                Unp->EndAdr=mem[q+0x2d]|mem[q+0x2e]<<8;Unp->EndAdr+=mem[q+0x0e];
                Unp->fStrAf=0x20;
                Unp->StrAdC=0xffff|EA_USE_X;
                PrintInfo(Unp,_I_TOTP1X);
                Unp->IdFlag=1;return;
            }
        }
        /* tested only vip3.2/hitmen */
        if( (*(unsigned int*)(mem+q+0x02)==0xBD01E678) &&
            (*(unsigned int*)(mem+q+0x06)==0xE89D0812) &&
            (*(unsigned int*)(mem+q+0x0a)==0xF7D0E800) &&
            (*(unsigned int*)(mem+q+0x0e)==0x8D01004C) &&
            (*(unsigned int*)(mem+q+0x83)==0x4a4a4a4a) )
        {
            Unp->DepAdr=0x100;
            Unp->Forced=q;
            Unp->RetAdr=mem[q+0x6a]|mem[q+0x6b]<<8;
            Unp->EndAdr=mem[q+0x12]|mem[q+0x13]<<8;Unp->EndAdr++;
            Unp->fStrAf=0xe9;
            PrintInfo(Unp,_I_VIP3X);
            Unp->IdFlag=1;return;
        }
        /* found only in Hitmen rels */
        if( (*(unsigned int*)(mem+q+0x00)==0xBE7858A0) &&
            (*(unsigned int*)(mem+q+0x04)==0x0096080D) &&
            (*(unsigned int*)(mem+q+0x11)==0x88076699) &&
            (*(unsigned int*)(mem+q+0x50)==0x43C602D0) )
        {
            Unp->DepAdr=0x02;
            Unp->Forced=q;
            Unp->RetAdr=mem[q+0x43]|mem[q+0x44]<<8;
            Unp->EndAdr=mem[q+0x4e]|mem[q+0x4f]<<8;Unp->EndAdr+=0x100;
            Unp->fStrAf=0x42;
            Unp->StrAdC=EA_ADDFF|EA_USE_Y|0xffff;
            PrintInfo(Unp,_I_HIT02);
            Unp->IdFlag=1;return;
        }

        if( (*(unsigned int*)(mem+q+0x0c)==0xE67824A2) &&
            (*(unsigned int*)(mem+q+0x10)==0x081DBD01) &&
            (*(unsigned int*)(mem+q+0x14)==0x10CA2095) &&
            (*(unsigned int*)(mem+q+0x30)==0x2FC6F7D0) )
        {
            Unp->DepAdr=0x20;
            Unp->Forced=q+0xc;
            Unp->RetAdr=mem[q+0x3d]|mem[q+0x3e]<<8;
            Unp->EndAdr=mem[q+0x2d]|mem[q+0x2e]<<8;Unp->EndAdr+=0x100;
            Unp->fStrAf=0x26;
            //Unp->StrAdC=EA_ADDFF|EA_USE_Y|0xffff;
            PrintInfo(Unp,_I_HIT20);
            Unp->IdFlag=1;return;
        }
        /* found in agnus mags */
        if( (*(unsigned int*)(mem+q+0x0c)==0x0819BD78) &&
            (*(unsigned int*)(mem+q+0x10)==0x10E80195) &&
            (*(unsigned int*)(mem+q+0x14)==0x00024CF8) &&
            (*(unsigned int*)(mem+q+0x40)==0x005620A8) )
        {
            Unp->DepAdr=0x2;
            Unp->Forced=q+0xc;
            Unp->RetAdr=mem[q+0x6b]|mem[q+0x6c]<<8;
            Unp->EndAdr=mem[q+0x49]|mem[q+0x4a]<<8;Unp->EndAdr++;
            Unp->fStrAf=0x32;
            PrintInfo(Unp,_I_AGNUS02);
            Unp->IdFlag=1;return;
        }
        /* found in buraki cracks, similar to Hitmen $02 */
        q=0x7e9;
        if(((*(unsigned int*)(mem+q+0x00)&0x00ffffff)==0x00A000A2) &&
            (*(unsigned int*)(mem+q+0x1c)==0x0096080D) &&
            (*(unsigned int*)(mem+q+0x29)==0x88076699) &&
            (*(unsigned int*)(mem+q+0x68)==0x43C602D0) )
        {
            Unp->DepAdr=0x02;
            Unp->Forced=q;
            Unp->RetAdr=mem[q+0x5b]|mem[q+0x5c]<<8;
            Unp->EndAdr=mem[q+0x66]|mem[q+0x67]<<8;Unp->EndAdr+=0x100;
            Unp->fStrAf=0x42;
            Unp->StrAdC=EA_ADDFF|EA_USE_Y|0xffff;
            PrintInfo(Unp,_I_BUK02);
            Unp->IdFlag=1;return;
        }

    }
}
