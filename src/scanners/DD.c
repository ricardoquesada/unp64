/* DD Coder */
#include "../unp64.h"
void Scn_DD(unpstr *Unp)
{
    unsigned char *mem;
    int p;
    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x80e)==0x018536A9) &&
           (*(unsigned int*)(mem+0x812)==0x00A2C7A0) &&
           (*(unsigned int*)(mem+0x816)==0x490820BD) &&
           (*(unsigned int*)(mem+0x81b)==0xE808209D) )
        {
            p=mem[0x81a];
            Unp->DepAdr=0x33c;
            Unp->Forced=0x80e;
            Unp->EndAdr=Unp->info->end-(0x1100-0x801);
            Unp->StrMem=(mem[0xb98]^p)|(mem[0xb99]^p)<<8; /* $0801 fixed */
            PrintInfo(Unp,_I_DDINTROC);
            Unp->IdFlag=1;return;
        }
    }
}
