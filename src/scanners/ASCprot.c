/* ASC/SCF Protector v1.14
pokepeek(174)+peek(175)*256,0:sys(sqr(4401604))
*/
#include "../unp64.h"
void Scn_ASCprot(unpstr *Unp)
{
    unsigned char *mem;
    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x81f)==0x28BA289E) &&
            (*(unsigned int*)(mem+0x823)==0x31303434) &&
            (*(unsigned int*)(mem+0x827)==0x29343036)
          )
        {
            Unp->Forced=0x846;
            Unp->DepAdr=mem[0x86C]|mem[0x86d]<<8;Unp->DepAdr+=0x1f;
            Unp->fStrBf=0xfd;
            Unp->EndAdr=0x2d;
            PrintInfo(Unp,_I_ASCPROT);
            Unp->IdFlag=1;return;
        }
    }
}
