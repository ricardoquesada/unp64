/* unknown (P3) found in some Panoramic and 20cc demos */
#include "../unp64.h"
void Scn_U_P3_pack(unpstr *Unp)
{
    unsigned char *mem;

    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x812)==0x8534A978) &&
            (*(unsigned int*)(mem+0x822)==0x2BCEF9C6) &&
            (*(unsigned int*)(mem+0x87a)==0x0F29F2E6) &&
            (*(unsigned int*)(mem+0x8da)==0xB1FBE602) )
        {
            Unp->Forced=0x812;
            Unp->DepAdr=0x100;
            Unp->RetAdr=mem[0x870]|mem[0x871]<<8;
            Unp->EndAdr=0xfc;
            Unp->StrMem=mem[0x83c]|mem[0x83d]<<8;
            PrintInfo(Unp,_I_U_P3);
            Unp->IdFlag=1;return;
        }
    }
}
