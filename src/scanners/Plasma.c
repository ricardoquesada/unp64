/* Plasma Coder */
#include "../unp64.h"
void Scn_Plasma(unpstr *Unp)
{
    unsigned char *mem;

    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x82c)==0xBD07A0AA) &&
            (*(unsigned int*)(mem+0x830)==0x69180883) &&
            (*(unsigned int*)(mem+0x87f)==0x05004CAF) &&
            (*(unsigned int*)(mem+0x88f)==0xDEE1C6D0) )
        {
            Unp->DepAdr=0x500;
            Unp->Forced=0x82c;
            Unp->fEndAf=0xae;
            PrintInfo(Unp,_I_PLASMACOD);
            Unp->IdFlag=1;return;
        }
    }
}
