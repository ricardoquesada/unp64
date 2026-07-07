/* Zero/Nato Coder */
#include "../unp64.h"
void Scn_ZeroCoder(unpstr *Unp)
{
    unsigned char *mem;

    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x812)==0xA8AA00A9) &&
           (*(unsigned int*)(mem+0x816)==0xCF083ADB) &&
           (*(unsigned int*)(mem+0x834)==0x790837CF) &&
           (mem[0x850]==0xED) )
        {
            Unp->DepAdr=0x400;
            Unp->Forced=0x812;
            //Unp->RetAdr=0xa7ae;
            Unp->fStrBf=0x404;
            Unp->EndAdr=Unp->info->end-0xa1;
            PrintInfo(Unp,_I_ZEROCOD);
            Unp->IdFlag=1;return;
        }
    }
}
