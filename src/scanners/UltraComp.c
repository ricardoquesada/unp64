/* Ultracomp/Dennis, does only all mem $800-ffff */
#include "../unp64.h"
void Scn_UltraComp(unpstr *Unp)
{
    unsigned char *mem;

    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x829)==0x490834BD) &&
           (*(unsigned int*)(mem+0x94c)==0x095BBD78) &&
           (*(unsigned int*)(mem+0x958)==0x7801004C) &&
           (*(unsigned int*)(mem+0x9d2)==0x02D0ACE6) )
        {
            Unp->DepAdr=0x100;
            Unp->Forced=0x94d;
            Unp->RetAdr=mem[0x9cd]|mem[0x9ce]<<8;
            PrintInfo(Unp,_I_ULTRAC3);
            Unp->IdFlag=1;return;
        }
    }
}
