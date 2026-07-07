/* WHO coder */
#include "../unp64.h"
void Scn_WHO(unpstr *Unp)
{
    unsigned char *mem;

    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x811)==0xBD00A278) &&
            (mem[0x817]==0x49)&&
           (*(unsigned int*)(mem+0x819)==0xE804029D) &&
           (*(unsigned int*)(mem+0x825)==0x04024C58) )
        {
            Unp->DepAdr=0x402;
            Unp->Forced=0x811;
            Unp->EndAdr=0x2d;
            PrintInfo(Unp,_I_WHO);
            Unp->IdFlag=1;return;
        }
    }
}
