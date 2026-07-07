/* DrZoom Packer */
#include "../unp64.h"
void Scn_DrZoom(unpstr *Unp)
{
    unsigned char *mem;

    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x80d)==0x1BBD00A2) &&
            (*(unsigned int*)(mem+0x89d)==0xC8638561) &&
            (*(unsigned int*)(mem+0x8ad)==0x62E602D0) )
        {
            Unp->DepAdr=0x400;
            Unp->Forced=0x80d;
            Unp->StrMem=mem[0x900]|mem[0x901]<<8;
            Unp->EndAdr=0x63;
            Unp->RetAdr=mem[0x8f8]|mem[0x8f9]<<8;
            PrintInfo(Unp,_I_DRZOOM);
            Unp->IdFlag=1;return;
        }
    }
}
