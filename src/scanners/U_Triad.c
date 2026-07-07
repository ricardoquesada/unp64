/* found in some Triad and Light cracks */
#include "../unp64.h"
void Scn_U_Triad(unpstr *Unp)
{
    unsigned char *mem;

    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0)
    {
        if( (*(unsigned int*)(mem+0x80b)==0xE67800A0) &&
            (*(unsigned int*)(mem+0x80f)==0x081CB901) &&
            (*(unsigned int*)(mem+0x813)==0xC800FA99) &&
            (*(unsigned int*)(mem+0x8b2)==0x35200115) &&
            mem[0x81b]==1
          )
        {
            Unp->Forced=0x80b;
            Unp->DepAdr=0x100;
            Unp->EndAdr=mem[0x81e]|mem[0x81f]<<8;
            Unp->fStrAf=0xfc;
            PrintInfo(Unp,_I_U_3ADCR);
            Unp->IdFlag=1;return;
        }
    }
}
