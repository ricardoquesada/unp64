/* ByteBoozer 0.9/1.0/PC 1.0/ PC 1.1 */
#include "../unp64.h"
void Scn_ByteBoozer(unpstr *Unp)
{
    unsigned char *mem;

    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x80d)==0x8534A978) &&
            (*(unsigned int*)(mem+0x811)==0xBD3BA201) &&
            (*(unsigned int*)(mem+0x815)==0x0695081F) &&
            (*(unsigned int*)(mem+0x819)==0x4CF810CA) &&
            (*(unsigned int*)(mem+0x8d2)==0x3003DD20) &&
            mem[0x81d]==0x08)
        {
            Unp->Forced=0x80d;
            Unp->RetAdr=mem[0x8dd]|mem[0x8de]<<8;
            Unp->DepAdr=0x8;
            Unp->StrMem=mem[0x91c]|mem[0x91d]<<8;
            Unp->fEndAf=0x04;Unp->EndAdC=0xffff;
            PrintInfo(Unp,_I_BYTEBOOZER);
            Unp->IdFlag=1;return;
        }
        if( (*(unsigned int*)(mem+0x80d)==0x8534A978) &&
            (*(unsigned int*)(mem+0x811)==0xBD3dA201) &&
            (*(unsigned int*)(mem+0x815)==0x0695081F) &&
            (*(unsigned int*)(mem+0x819)==0x4CF810CA) &&
            (*(unsigned int*)(mem+0x8d4)==0x3003D120) &&
            mem[0x81d]==0x08)
        {
            Unp->Forced=0x80d;
            Unp->RetAdr=mem[0x8df]|mem[0x8e0]<<8;
            Unp->DepAdr=0x8;
            Unp->StrMem=mem[0x912]|mem[0x913]<<8;
            Unp->fEndAf=0x04;Unp->EndAdC=0xffff;
            PrintInfo(Unp,_I_BYTEBOOZ11C);
            Unp->IdFlag=1;return;
        }
        if( (*(unsigned int*)(mem+0x80d)==0xA5083C4C) &&
            (*(unsigned int*)(mem+0x844)==0x8534A978) &&
            (*(unsigned int*)(mem+0x848)==0xBD3bA201) &&
            (*(unsigned int*)(mem+0x909)==0x3003CE20) &&
            mem[0x854]==0x08)
        {
            Unp->Forced=0x810;
            Unp->RetAdr=mem[0x911]|mem[0x912]<<8;
            Unp->DepAdr=0x8;
            Unp->StrMem=mem[0x96a]|mem[0x96b]<<8;
            Unp->fEndAf=0x04;Unp->EndAdC=0xffff;
            PrintInfo(Unp,_I_BYTEBOOZ11E);
            Unp->IdFlag=1;return;
        }
        if( (*(unsigned int*)(mem+0x80d)==0x8534A978) &&
            (*(unsigned int*)(mem+0x813)==0x081EBDB7) &&
            (*(unsigned int*)(mem+0x870)==0x00AD20A8) &&
            (*(unsigned int*)(mem+0x8C0)==0xE602D0AE) )
        {
            Unp->Forced=0x80d;
            Unp->RetAdr=mem[0x8cb]|mem[0x8cc]<<8;
            Unp->DepAdr=0x10;
            Unp->StrMem=mem[0x886]|mem[0x887]<<8;
            Unp->fEndAf=0x77;Unp->EndAdC=0xffff;
            PrintInfo(Unp,_I_BYTEBOOZ20);
            Unp->IdFlag=1;return;
        }
        if( (*(unsigned int*)(mem+0x817)==0x8534A978) &&
            (*(unsigned int*)(mem+0x81b)==0xBDc6A201) &&
            (*(unsigned int*)(mem+0x81f)==0xf99d083c) &&
            (*(unsigned int*)(mem+0x824)==0xbdF7d0CA) &&
            (*(unsigned int*)(mem+0x8f7)==0x60f210ca) )
        {
            Unp->Forced=0x817;
            Unp->RetAdr=mem[0x8c5]|mem[0x8c6]<<8;
            Unp->DepAdr=0x100;
            Unp->StrMem=mem[0x83f]|mem[0x840]<<8;
            Unp->fEndAf=0xfc;Unp->EndAdC=0xffff;
            PrintInfo(Unp,_I_LAMEBOOZER);
            Unp->IdFlag=1;return;
        }
    }
}
