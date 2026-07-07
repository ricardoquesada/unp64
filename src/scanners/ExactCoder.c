/* Exact Coder */
#include "../unp64.h"
void Scn_ExactCoder(unpstr *Unp)
{
    unsigned char *mem;
    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x815)==0xA9FDA320) &&
           (*(unsigned int*)(mem+0x819)==0x58028500) &&
           (*(unsigned int*)(mem+0x81d)==0x61BD36A2) &&
           (*(unsigned int*)(mem+0x858)==0x7F99A505) )
        {
            Unp->DepAdr=0x500;
            Unp->Forced=0x815;
            Unp->RetAdr=0xa7ae;
            Unp->EndAdr=Unp->info->end-0x95;
            Unp->StrMem=0x801;
            PrintInfo(Unp,_I_EXACTCOD);
            Unp->IdFlag=1;return;
        }
    }
}
