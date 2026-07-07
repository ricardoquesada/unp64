/* Graffity packer */
#include "../unp64.h"
void Scn_Graffity(unpstr *Unp)
{
    unsigned char *mem;

    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x817)==0x8600A278) &&
           (*(unsigned int*)(mem+0x81b)==0x082ABD01) &&
           (*(unsigned int*)(mem+0x827)==0xA0033C4C) &&
           (*(unsigned int*)(mem+0x877)==0x039E2003) )
        {
            Unp->DepAdr=0x33c;
            Unp->Forced=0x817;
            Unp->RetAdr=mem[0x883]|mem[0x884]<<8;
            Unp->StrMem=mem[0x851]|mem[0x853]<<8;
            Unp->fEndAf=0xae;
            PrintInfo(Unp,_I_GRAFFITY);
            Unp->IdFlag=1;return;
        }
    }
}
