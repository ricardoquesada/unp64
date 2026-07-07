/* PZW/MPSoft file compactor */
#include "../unp64.h"
void Scn_PZW(unpstr *Unp)
{
    unsigned char *mem;

    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x820)==0x9D082EBD) &&
            (*(unsigned int*)(mem+0x824)==0xD0E80100) &&
            (*(unsigned int*)(mem+0x82c)==0xA9780100) &&
            (*(unsigned int*)(mem+0x8b9)==0x01954CAD) )
        {
            Unp->DepAdr=0x100;
            Unp->Forced=0x820;
            Unp->RetAdr=mem[0x8b2]|mem[0x8b3]<<8;
            Unp->StrMem=mem[0x869]|mem[0x86d]<<8;
            Unp->EndAdr=0xae;
            PrintInfo(Unp,_I_PZWCOM);
            Unp->IdFlag=1;return;
        }
    }
}
