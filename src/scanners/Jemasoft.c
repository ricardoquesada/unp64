#include "../unp64.h"
void Scn_Jemasoft(unpstr *Unp)
{
    unsigned char *mem;
    int p;
    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    /* Jemasoft BasicPacker */
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x80b)==0x847800A0) &&
            (*(unsigned int*)(mem+0x812)==0x06009908) &&
            (*(unsigned int*)(mem+0x819)==0xB9061C4C) )
        {
            p=mem[0x81d]|mem[0x81e]<<8;
            if( (mem[p]==0xca) &&
                (*(unsigned int*)(mem+p+0x0c)==0x07622088) &&
                (*(unsigned int*)(mem+p+0x3c)==0x076FCE03) )
            {
                Unp->Forced=0x80b;
                Unp->DepAdr=0x61c;
                Unp->RetAdr=mem[p+0x2b]|mem[p+0x2c]<<8;
                if(Unp->RetAdr == 0xa659 )
                    Unp->RetAdr=mem[p+0x2e]|mem[p+0x2f]<<8;
                Unp->fEndAf=0x2d;
                Unp->StrMem=0x0801;
                PrintInfo(Unp,_I_JEMABASIC);
                Unp->IdFlag=1;return;
            }
        }
    }
}
