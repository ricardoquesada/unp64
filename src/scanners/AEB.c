/* Baskerville Cruncher/Aleksi Eeben */
#include "../unp64.h"
void Scn_AEB(unpstr *Unp)
{
    unsigned char *mem;

    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if( (mem[0x80b]==0xa0) &&
            (*(unsigned int*)(mem+0x810)==0x99082CB9) &&
            (*(unsigned int*)(mem+0x814)==0xD0C800F9) &&
            (*(unsigned int*)(mem+0x86b)==0xF0F6D002) &&
            (*(unsigned int*)(mem+0x828)==0x01254CF2) )
        {
            Unp->DepAdr=0x125;
            Unp->Forced=0x80b;
            Unp->StrMem=mem[0x831]|mem[0x832]<<8;
            Unp->EndAdr=0xfe;
            Unp->RetAdr=mem[0x874]|mem[0x875]<<8;
            PrintInfo(Unp,_I_AEB2);
            Unp->IdFlag=1;return;
        }
        if( (*(unsigned int*)(mem+0x80b)==0xE67800A0) &&
            (*(unsigned int*)(mem+0x828)==0x01274CF2) &&
            (*(unsigned int*)(mem+0x85F)==0x0107202C) &&
            (*(unsigned int*)(mem+0x8e9)==0x60AA2A01) )
        {
            Unp->DepAdr=0x127;
            Unp->Forced=0x80b;
            Unp->StrMem=mem[0x832]|mem[0x833]<<8;
            Unp->EndAdr=0xfe;
            Unp->RetAdr=mem[0x87d]|mem[0x87e]<<8;
            PrintInfo(Unp,_I_AEB1);
            Unp->IdFlag=1;return;
        }
    }
}
