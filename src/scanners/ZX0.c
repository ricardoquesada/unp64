/* ZX0 C64 port included in Bitfire */
#include "../unp64.h"
void Scn_ZX0(unpstr *Unp)
{
    unsigned char *mem;
    int q;
    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x80d)==0xA501E678) &&
           (*(unsigned int*)(mem+0x811)==0xD0A248BA) &&
           (*(unsigned int*)(mem+0x832)==0xA900024C) &&
           (mem[0x901]==0xBA) )
        {
            Unp->DepAdr=0x02;
            Unp->Forced=0x80d;
            Unp->StrMem=mem[0x88a]|mem[0x88b]<<8;
            Unp->EndAdr=mem[0x845]; //0x57;
            Unp->RetAdr=mem[0x903]|mem[0x904]<<8;
            PrintInfo(Unp,_I_ZX010);
            Unp->IdFlag=1;return;
        }
        if((*(unsigned int*)(mem+0x80d)==0x48BAA578) &&
           (*(unsigned int*)(mem+0x811)==0x32BDD4A2) &&
           (*(unsigned int*)(mem+0x830)==0x3800024C) &&
           (mem[0x903]==0xBA) )
        {
            Unp->DepAdr=0x02;
            Unp->Forced=0x80d;
            Unp->StrMem=mem[0x88c]|mem[0x88d]<<8;
            Unp->EndAdr=mem[0x844]; //0x5a;
            Unp->RetAdr=mem[0x905]|mem[0x906]<<8;
            PrintInfo(Unp,_I_ZX015);
            Unp->IdFlag=1;return;
        }
        if((*(unsigned int*)(mem+0x80d)==0xA501E678) &&
           (*(unsigned int*)(mem+0x811)==0xD1A248BA) &&
           (*(unsigned int*)(mem+0x832)==0xA900024C) &&
           (mem[0x8fc]==0x4c) )
        {
            Unp->DepAdr=0x02;
            Unp->Forced=0x80d;
            Unp->StrMem=mem[0x88a]|mem[0x88b]<<8;
            Unp->EndAdr=mem[0x845]; //0x57;
            Unp->RetAdr=mem[0x8fd]|mem[0x8fe]<<8;
            PrintInfo(Unp,_I_ZX009);
            Unp->IdFlag=1;return;
        }
        /* dali 0.3 released on 2022.02.11 */
        if((*(unsigned int*)(mem+0x80d)==0x9A0BA278) &&
           (*(unsigned int*)(mem+0x811)==0xB748EAA0) &&
           (*(unsigned int*)(mem+0x81e)==0x3400034C) &&
           (mem[0x908]==0x4C) )
        {
            Unp->DepAdr=0x03;
            Unp->Forced=0x80d;
            Unp->StrMem=mem[0x88f]|mem[0x890]<<8;
            Unp->EndAdr=mem[0x853]; //0x6f;
            Unp->RetAdr=mem[0x909]|mem[0x90a]<<8;
            // patch zp restore, I need to read the endaddr pointer
            mem[0x902]=0x24;
            PrintInfo(Unp,_I_DALI03F);
            Unp->IdFlag=1;return;
        }
        /* 0.3 update 2022.02.21, both salvador and dali are different, ASL instead of LSR in 0.3.2  */
        if((*(unsigned int*)(mem+0x80d)==0x9A0BA278) &&
           (*(unsigned int*)(mem+0x811)==0xB748EEA0) &&
           (*(unsigned int*)(mem+0x81e)==0x3400034C) &&
           (mem[0x90C]==0x4C) )
        {
            Unp->DepAdr=0x03;
            Unp->Forced=0x80d;
            Unp->StrMem=mem[0x88d]|mem[0x88e]<<8;
            Unp->EndAdr=mem[0x853]; //0x6d;
            Unp->RetAdr=mem[0x90d]|mem[0x90e]<<8;
            // patch zp restore, I need to read the endaddr pointer
            mem[0x906]=0x24;
            if (mem[0x83a]==0x46)
                PrintInfo(Unp,_I_DALI031F);
            else
                PrintInfo(Unp,_I_DALI032F);
            Unp->IdFlag=1;return;
        }
        /* 0.3 short, unmodified in 02.21 update, ASL instead of LSR in 0.3.2 */
        if((*(unsigned int*)(mem+0x80d)==0xBEB7A078) &&
           (*(unsigned int*)(mem+0x811)==0x0096081A) &&
           (*(unsigned int*)(mem+0x818)==0x3400034C) &&
           (mem[0x8cf]==0x4C) )
        {
            Unp->DepAdr=0x03;
            Unp->Forced=0x80d;
            Unp->StrMem=mem[0x87d]|mem[0x87e]<<8;
            Unp->EndAdr=mem[0x83f]; //0x63;
            Unp->RetAdr=mem[0x8d0]|mem[0x8d1]<<8;
            if (mem[0x831]==0x46)
               PrintInfo(Unp,_I_DALI03S);
            else
               PrintInfo(Unp,_I_DALI032S); // also 0.3.3 small when not relocated, unchanged from 0.3.2
            Unp->IdFlag=1;return;
        }
        /* 0.3.3 (2023.9 update) also sysless, fast depacker is changed */
        for(q=Unp->info->start;q<Unp->info->start+0x0f;q++)
        {
            if( (*(unsigned int*)(mem+q+0x00)==0x9A0BA278) &&
                (*(unsigned int*)(mem+q+0x04)==0xB748ECA0) &&
                (*(unsigned int*)(mem+q+0x11)==0x3400034C) &&
                (mem[q+0xfd]==0x4C) )
            {
                Unp->DepAdr=0x03;
                break;
            }
        }
        if(Unp->DepAdr)
        {
            Unp->Forced=q;
            Unp->StrMem=mem[q+0x7e]|mem[q+0x7f]<<8;
            Unp->EndAdr=mem[q+0x44]; //0x6b;
            Unp->RetAdr=mem[q+0xfe]|mem[q+0xff]<<8;
            // patch zp restore, I need to read the endaddr pointer
            mem[q+0xf7]=0x24;
            PrintInfo(Unp,_I_DALI033F);
            Unp->IdFlag=1;return;
        }
        /* 0.3.3 (2023.9 update) small depacker relocated
           it's identical to 0.3.2 small, but sysless and of course relocated
        */
        for(q=Unp->info->start;q<Unp->info->start+0x0f;q++)
        {
            if( (*(unsigned int*)(mem+q+0x00)==0xBEB7A078) &&
                (*(unsigned int*)(mem+q+0x06)==0xD0880096) &&
                (*(unsigned int*)(mem+q+0x0b)==0x3400034C) &&
                (mem[q+0x24]==0x06) &&
                (mem[q+0xc2]==0x4C)
                )
            {
                Unp->DepAdr=0x03;
                break;
            }
        }
        if(Unp->DepAdr)
        {
            Unp->DepAdr=0x03;
            Unp->Forced=q;
            Unp->StrMem=mem[q+0x70]|mem[q+0x71]<<8;
            Unp->EndAdr=mem[q+0x3a]; //0x63;
            Unp->RetAdr=mem[q+0xc3]|mem[q+0xc4]<<8;
            PrintInfo(Unp,_I_DALI033S);
            Unp->IdFlag=1;return;
        }
        /* 0.3.4 (2024.07.11) small sfx with depacking effect */
        for(q=Unp->info->start;q<Unp->info->start+0x0f;q++)
        {
            if( (*(unsigned int*)(mem+q+0x00)==0xBEBEA078) &&
                (*(unsigned int*)(mem+q+0x06)==0xD0880096) &&
                (*(unsigned int*)(mem+q+0x0b)==0x3400034C) &&
                (mem[q+0x24]==0x06) &&
                (mem[q+0xc9]==0x4C)
                )
            {
                Unp->DepAdr=0x03;
                break;
            }
        }
        if(Unp->DepAdr)
        {
            Unp->DepAdr=0x03;
            Unp->Forced=q;
            Unp->StrMem=mem[q+0x77]|mem[q+0x78]<<8;
            Unp->EndAdr=mem[q+0x32]; //0x6a;
            Unp->RetAdr=mem[q+0xca]|mem[q+0xcb]<<8;
            PrintInfo(Unp,_I_DALI034SFX);
            Unp->IdFlag=1;return;
        }
        /* 0.3.5 (2024.10.05) small sfx with depacking effect */
        for(q=Unp->info->start;q<Unp->info->start+0x0f;q++)
        {
            if( (*(unsigned int*)(mem+q+0x00)==0x9A0BA278) &&
                (*(unsigned int*)(mem+q+0x0c)==0xD0880096) &&
                (*(unsigned int*)(mem+q+0x11)==0x3400034C) &&
                (mem[q+0x2d]==0x06) &&
                (mem[q+0x104]==0x4C) // 0x0103=0x78 note:check if it's always there
                )
            {
                Unp->DepAdr=0x03;
                break;
            }
        }
        if(Unp->DepAdr)
        {
            Unp->DepAdr=0x03;
            Unp->Forced=q;
            Unp->StrMem=mem[q+0x85]|mem[q+0x86]<<8;
            Unp->EndAdr=mem[q+0x44]; //0x72;
            Unp->RetAdr=mem[q+0x105]|mem[q+0x106]<<8;
            // patch zp restore, I need to read the endaddr pointer
            mem[q+0xfe]=0x24;
            PrintInfo(Unp,_I_DALI035SFX);
            Unp->IdFlag=1;return;
        }

    }
}
