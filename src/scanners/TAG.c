/* TAG Cruncher by Usul */
#include "../unp64.h"
void Scn_TAG(unpstr *Unp)
{
    unsigned char *mem;

    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x811)==0x9AFFA278) &&
            (*(unsigned int*)(mem+0x829)==0x033C4CF1) &&
            (*(unsigned int*)(mem+0x850)==0x4C0343CE) &&
            (*(unsigned int*)(mem+0x92b)==0xE602D0FD) )
        {
            Unp->DepAdr=0x33c;
            Unp->Forced=0x811;
            Unp->StrMem=mem[0x871]|mem[0x875]<<8;
            Unp->EndAdr=0xfd;
            Unp->RetAdr=mem[0x86b]|mem[0x86c]<<8;
            PrintInfo(Unp,_I_TAG);
            Unp->IdFlag=1;return;
        }
    }
}
