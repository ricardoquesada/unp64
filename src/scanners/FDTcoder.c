/* FDT/AFL Coder */
#include "../unp64.h"
void Scn_FDTcoder(unpstr *Unp)
{
    unsigned char *mem;
    int q;
    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x824)==0x690830BD) &&
           (*(unsigned int*)(mem+0x828)==0x08309D66) &&
           (*(unsigned int*)(mem+0x82c)==0xD079E0E8) )
        {
            q=mem[0x828];
            Unp->DepAdr=((mem[0x85c]+q)&0xff)|((mem[0x85d]+q)&0xff)<<8;
            Unp->Forced=0x824;
            Unp->RetAdr=0xa7ae;
            Unp->EndAdr=Unp->info->end-0xa8;
            Unp->StrMem=0x0801;
            PrintInfo(Unp,_I_FDTCOD);
            Unp->IdFlag=1;return;
        }
    }
}
