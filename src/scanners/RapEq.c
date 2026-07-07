/* Rap Equal Chars/Nebula */
#include "../unp64.h"
void Scn_RapEq(unpstr *Unp)
{
    unsigned char *mem;

    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0)
    {
        if( (*(unsigned int*)(mem+0x80b)==0x867800A2) &&
            (*(unsigned int*)(mem+0x80f)==0x083EBD01) &&
            (*(unsigned int*)(mem+0x813)==0xBD01009D) &&
            (*(unsigned int*)(mem+0x83c)==0x86CA0101) &&
            (*(unsigned int*)(mem+0x840)==0x017D20FD) )
        {
            Unp->Forced=0x80b;
            Unp->DepAdr=0x101;
            Unp->fEndAf=0x157;
            Unp->EndAdC=0xffff;
            Unp->StrMem=mem[0x895]|mem[0x896]<<8;
            Unp->RetAdr=mem[0x8b6]|mem[0x8b7]<<8;
            PrintInfo(Unp,_I_RAPEQC);
            Unp->IdFlag=1;return;
        }
    }
}
