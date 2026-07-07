/* Fast Packer (LZSS) by Repose/Style */
#include "../unp64.h"
void Scn_Lzss(unpstr *Unp)
{
    unsigned char *mem;

    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x80e)==0x8501A5D8) &&
            (*(unsigned int*)(mem+0x821)==0x05A96285) &&
            (*(unsigned int*)(mem+0x938)==0x758570B1) &&
            (*(unsigned int*)(mem+0xa0b)==0x4A4A4A4A) )
        {
            Unp->DepAdr=mem[0x856]|mem[0x857]<<8;
            Unp->Forced=0x80e;
            Unp->StrMem=mem[0xa92]|mem[0xa93]<<8;
            Unp->EndAdr=mem[0xa90]|mem[0xa91]<<8;
            Unp->EndAdr+=Unp->StrMem;
            Unp->RetAdr=mem[0xa88]|mem[0xa89]<<8;
            PrintInfo(Unp,_I_LZSS1);
            Unp->IdFlag=1;return;
        }
    }
}
