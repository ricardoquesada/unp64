/* unknown $0420 coder*/
#include "../unp64.h"
void Scn_UProt(unpstr *Unp)
{
    unsigned char *mem;
    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x820)==0xB40811AD) &&
            (*(unsigned int*)(mem+0x824)==0x02A92C99) &&
            (*(unsigned int*)(mem+0x828)==0x048D0549)
          )
        {
            if(Unp->info->run==-1)
                Unp->Forced=0x820;
            Unp->DepAdr=0x420;
            Unp->RetAdr=0xa7ae;
            Unp->StrMem=0x0801;
            Unp->EndAdr=0x2d;
            PrintInfo(Unp,_I_UPROT420);
            Unp->IdFlag=1;return;
        }
    }
}
