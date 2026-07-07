/* Low cruncher/jens-m.b. from magic disk */

#include "../unp64.h"
void Scn_Low(unpstr *Unp)
{
    unsigned char *mem;

    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x80b)==0xE67800A0) &&
           (*(unsigned int*)(mem+0x820)==0x4A4A4A4A) &&
           (*(unsigned int*)(mem+0x902)==0xA200BD4C) &&
           (*(unsigned int*)(mem+0x993)==0x1EA506D0) )
        {
            Unp->DepAdr=0x02d;
            Unp->Forced=0x80b;
            Unp->RetAdr=mem[0x9d1]|mem[0x9d2]<<8;
            Unp->StrMem=mem[0x811]|mem[0x815]<<8;
            Unp->EndAdr=mem[0x992]|mem[0x998]<<8;
            PrintInfo(Unp,_I_LOWCR);
            Unp->IdFlag=1;return;
        }
    }
}
