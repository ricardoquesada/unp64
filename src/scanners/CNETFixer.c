/* 
CNET PROGRAM FIXER BY EDDY CARROLL 1988
whatever it is meant for, it's also a EOR crypter
*/
#include "../unp64.h"
void Scn_CNETFixer(unpstr *Unp)
{
    unsigned char *mem;

    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x847)==0x2BA557A0) &&
           (*(unsigned int*)(mem+0x84b)==0x918E6918) &&
           (*(unsigned int*)(mem+0x890)==0x852BB1CF) &&
           (*(unsigned int*)(mem+0x8a0)==0x2DA5FD85) )
        {
            Unp->Forced=0x847;
            Unp->DepAdr=0x110;
            Unp->StrMem=0x801;
            Unp->EndAdr=0x2d;
            Unp->RetAdr=0xa7ae;
            PrintInfo(Unp,_I_CNETFIX);
            Unp->IdFlag=1;return;
        }
    }
}
