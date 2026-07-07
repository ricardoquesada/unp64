/*
ICS "drive 8" very stupid coder
unpack will fail if the prg isn't loaded from drive 8 (expects $ba=8)
*/
#include "../unp64.h"
void Scn_ICS8(unpstr *Unp)
{
    unsigned char *mem;
    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if( (mem[0x810]==0xa9) &&
            (*(unsigned int*)(mem+0x820)==0x5D0800BD) &&
            (*(unsigned int*)(mem+0x82b)==0x03AF4CF4) )
        {
            Unp->DepAdr=0x3fa;
            Unp->EndAdr=0xae;
            Unp->RetAdr=0x801;
            mem[0xba]=0x8;
            PrintInfo(Unp,_I_ICS8);
            Unp->IdFlag=1;return;
        }
    }
}
