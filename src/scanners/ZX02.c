/* ZX02 SFX
   found in Shadow cracks
*/
#include "../unp64.h"
void Scn_ZX02(unpstr *Unp)
{
    unsigned char *mem;
    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x80f)==0xA2018534) &&
            (*(unsigned int*)(mem+0x834)==0x03344CEE) &&
            (*(unsigned int*)(mem+0x85b)==0xE602D081) &&
            (*(unsigned int*)(mem+0x8c7)==0x0860E7B0) )
        {
            Unp->Forced=0x80d;
            Unp->DepAdr=0x334;
            Unp->StrMem=mem[0x846]|mem[0x847]<<8;
            Unp->RetAdr=mem[0x841]|mem[0x842]<<8;
            Unp->fEndAf=0x81;
            Unp->EndAdC=0xffff;
            PrintInfo(Unp,_I_ZX02);
            Unp->IdFlag=1;return;
        }
    }
}
