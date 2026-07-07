/* KGB Coder ? */
#include "../unp64.h"
void Scn_KGBcoder(unpstr *Unp)
{
    unsigned char *mem;

    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x82b)==0x9D0839BD) &&
           (*(unsigned int*)(mem+0x82f)==0xE0E80400) &&
           (*(unsigned int*)(mem+0x85a)==0x4908A0BD) &&
           (*(unsigned int*)(mem+0x86f)==0xD0C90428) )
        {
            Unp->DepAdr=0x400;
            Unp->Forced=0x829;
            Unp->RetAdr=0xa7ae;
            Unp->EndAdr=Unp->info->end-0xa0;
            Unp->StrMem=0x0801;
            PrintInfo(Unp,_I_KGBCOD);
            Unp->IdFlag=1;return;
        }
    }
}
