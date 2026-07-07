/* WCC Modem converter, not a packer, just a size filler for modem xfers */
#include "../unp64.h"
void Scn_WCC(unpstr *Unp)
{
    unsigned char *mem;

    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x833)==0x43B900A0) &&
           (*(unsigned int*)(mem+0x837)==0x03519908) &&
           (*(unsigned int*)(mem+0x873)==0xAEA5AFE6) &&
           (*(unsigned int*)(mem+0x883)==0xAFA52D85) )
        {
            Unp->DepAdr=0x351;
            Unp->Forced=0x833;
            Unp->StrMem=mem[0x859]|mem[0x85d]<<8;
            Unp->RetAdr=mem[0x898]|mem[0x899]<<8;
            Unp->EndAdr=0x2d;
            PrintInfo(Unp,_I_WCCMC);
            Unp->IdFlag=1;return;
        }
    }
}
