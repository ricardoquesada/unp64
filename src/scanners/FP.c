/* FP coder, seems rarely used, found just 3 prgs with it =) */
#include "../unp64.h"
void Scn_FP(unpstr *Unp)
{
    unsigned char *mem;

    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x826)==0x018526A9) &&
            (*(unsigned int*)(mem+0x82a)==0x850820AD) &&
            (*(unsigned int*)(mem+0x82e)==0xADAE852D) &&
            (*(unsigned int*)(mem+0x83a)==0x4908D8BD)
          )
        {
            Unp->Forced=0x826;
            Unp->DepAdr=mem[0x853]|mem[0x854]<<8;
            Unp->EndAdr=mem[0x820]|mem[0x821]<<8;
            Unp->RetAdr=mem[0x8a9]|mem[0x8aa]<<8;
            PrintInfo(Unp,_I_FPCOD);
            Unp->IdFlag=1;return;
        }
    }
}
