/* Gimzo/WOW */
#include "../unp64.h"
void Scn_Gimzo(unpstr *Unp)
{
    unsigned char *mem;

    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x810)==0x1EB90184) &&
            (*(unsigned int*)(mem+0x822)==0xFC86FB85) &&
            (*(unsigned int*)(mem+0x850)==0xA78DFBB1) &&
            (*(unsigned int*)(mem+0x860)==0xA98DFBB1) )
        {
            Unp->DepAdr=0x4a7;
            Unp->Forced=0x80d;
            Unp->StrMem=mem[0x827]|mem[0x829]<<8;
            Unp->EndAdr=0xae;
            Unp->RetAdr=mem[0x8c3]|mem[0x8c4]<<8;
            PrintInfo(Unp,_I_GIMZO);
            Unp->IdFlag=1;return;
        }
    }
}
