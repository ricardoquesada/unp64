/* TAT Coder */
#include "../unp64.h"
void Scn_TATCoder(unpstr *Unp)
{
    unsigned char *mem;

    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x810)==0x288DE1A9) &&
           (*(unsigned int*)(mem+0x81c)==0x06F0E544) &&
           (*(unsigned int*)(mem+0x838)==0x49AAAF49) &&
           (mem[0x858]==0xaf) )
        {
            Unp->DepAdr=0x3ff;
            Unp->Forced=0x810;
            Unp->RetAdr=0xa7ae;
            Unp->StrMem=0x801;
            Unp->EndAdr=0x2d;
            mem[0x9a]=3;
            PrintInfo(Unp,_I_TATCOD);
            Unp->IdFlag=1;return;
        }
    }
}
