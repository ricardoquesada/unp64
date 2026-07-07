/* Yeti Coder */
#include "../unp64.h"
void Scn_YetiCoder(unpstr *Unp)
{
    unsigned char *mem;

    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x812)==0xEA00A0EA) &&
           (*(unsigned int*)(mem+0x81b)==0x140841B9) &&
           (*(unsigned int*)(mem+0x81f)==0x080159D0) &&
           (mem[0x836]==0x25) )
        {
            Unp->DepAdr=0x33c;
            Unp->Forced=0x812;
            Unp->RetAdr=0xa7ae;
            Unp->EndAdr=Unp->info->end-0x5f;
            PrintInfo(Unp,_I_YETICOD);
            Unp->IdFlag=1;return;
        }
    }
}
