#include "../unp64.h"
void Scn_CCrypt(unpstr *Unp)
{
    unsigned char *mem;

    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x811)==0x20BD00A2) &&
           (*(unsigned int*)(mem+0x815)==0x9D134908) &&
           (*(unsigned int*)(mem+0x819)==0x17EE0820) &&
           (*(unsigned int*)(mem+0x81d)==0xE1D0E808) )
        {
            Unp->Forced=0x811;
            Unp->DepAdr=0x100;
            Unp->StrMem=0x801;
            Unp->EndAdr=0xae;
            Unp->RetAdr=0xa7ae;
            PrintInfo(Unp,_I_CCRYPT);
            Unp->IdFlag=1;return;
        }
    }
}
