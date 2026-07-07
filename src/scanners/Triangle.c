/*
Triangle coder
uses SBX #$FF (helped finding a bug in implementation), uses basic ROM,
has no SYS line but a poke 807,8 (forces vector $0326/7 to $8ca),
stack is not $f6 but $f2, depacker is at $180, $100 bytes exact long.
*/
#include "../unp64.h"
void Scn_Triangle(unpstr *Unp)
{
    unsigned char *mem;
    unsigned int p;

    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x831)==0x38080BAF) &&
           (*(unsigned int*)(mem+0x83b)==0x009D42EB) &&
           (*(unsigned int*)(mem+0x841)==0x009D0800) &&
           (*(unsigned int*)(mem+0x8ca)==0xDFF0004B) )
        {
            Unp->Forced=0x7f0;
            p=Unp->Forced;
            mem[p++]=0xa2;
            mem[p++]=0xf2;
            mem[p++]=0x9A;
            mem[p++]=0x4C;
            mem[p++]=0xCA;
            mem[p++]=0x08;
            Unp->DepAdr=0x180;
            Unp->StrMem=0x801;
            Unp->EndAdr=Unp->info->end-0x100;
            Unp->RtAFrc=1;
            Unp->RetAdr=0xa7ae;
            memcpy(mem+0xa180, roms[0]+0x0180,0x100);
            PrintInfo(Unp,_I_TRIANGLECOD);
            Unp->IdFlag=1;return;
        }
    }
}
