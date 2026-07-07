/* AEB/CNCD Classic Cruncher (but it's a charpacker) */
#include "../unp64.h"
void Scn_CNCD(unpstr *Unp)
{
    unsigned char *mem;

    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x80f)==0xA0018534) &&
            (*(unsigned int*)(mem+0x813)==0x0844B995) &&
            (*(unsigned int*)(mem+0x817)==0x8803FF99) &&
            (*(unsigned int*)(mem+0x89f)==0x4C048C20) )
        {
            Unp->Forced=0x80d;
            Unp->DepAdr=0x418;
            Unp->RetAdr=mem[0x8c3]|mem[0x8c4]<<8;
            Unp->EndAdr=0x2d;
            Unp->StrMem=0x801;
            PrintInfo(Unp,_I_CNCD);
            Unp->IdFlag=1;return;
        }
    }
}
