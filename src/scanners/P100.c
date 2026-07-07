/* P100/Nebula */
#include "../unp64.h"
void Scn_P100(unpstr *Unp)
{
    unsigned char *mem;
    int p;
    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x812)==0xB9018478) &&
           (*(unsigned int*)(mem+0x822)==0x0817CEFB) &&
           (*(unsigned int*)(mem+0x832)==0x01304C9A) )
        {
            p=mem[0x816]|mem[0x817]<<8;
            if((*(unsigned int*)(mem+p+0x30)==0x9001BB20) &&
               (*(unsigned int*)(mem+p+0xd5)==0x3801DE20) )
            {
                Unp->DepAdr=0x130;
                Unp->Forced=0x812;
                Unp->RetAdr=mem[p+0xd0]|mem[p+0xd1]<<8;
                Unp->EndAdr=0xfe;
                Unp->StrMem=mem[0x839]|mem[0x83a]<<8;
                PrintInfo(Unp,_I_P100);
                Unp->IdFlag=1;return;
            }
        }
    }
}
