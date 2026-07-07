/* Found in Shurigen & Glitters */
#include "../unp64.h"
void Scn_Shurigen(unpstr *Unp)
{
    unsigned char *mem;

    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x82D)==0x8604A278) &&
           (*(unsigned int*)(mem+0x831)==0xBD92A201) &&
           (*(unsigned int*)(mem+0x83D)==0xED3800A9) &&
           (*(unsigned int*)(mem+0x86a)==0x03344CFD) )
        {
            Unp->DepAdr=0x334;
            Unp->Forced=0x82d;
            Unp->StrMem=mem[0x866]|mem[0x864]<<8;
            Unp->RetAdr=mem[0x8ea]|mem[0x8eb]<<8;
            Unp->EndAdr=0xfd;
            PrintInfo(Unp,_I_SHRPACK);
            Unp->IdFlag=1;return;
        }
    }
}
