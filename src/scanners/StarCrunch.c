/* StarCrunch */
#include "../unp64.h"
void Scn_StarCrunch(unpstr *Unp)
{
    unsigned char *mem;

    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x80d)==0x9AFFA278) &&
           (*(unsigned int*)(mem+0x81d)==0x68990842) &&
           (*(unsigned int*)(mem+0x825)==0x4AB9D5A0) &&
           (*(unsigned int*)(mem+0x879)==0x4A4A4A48) )
        {
            Unp->DepAdr=0x100;
            Unp->Forced=0x80d;
            Unp->StrMem=mem[0x843]|mem[0x844]<<8;
            Unp->RetAdr=mem[0x8ea]|mem[0x8eb]<<8;
            Unp->EndAdr=0x69;
            PrintInfo(Unp,_I_STARCRUNCH);
            Unp->IdFlag=1;return;
        }
    }
}
