/* Face packer */
#include "../unp64.h"
void Scn_Facepacker(unpstr *Unp)
{
    unsigned char *mem;

    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x80d)==0x8538A978) &&
            (*(unsigned int*)(mem+0x811)==0xBD44A201) &&
            (*(unsigned int*)(mem+0x815)==0xFF9D0835) &&
            (*(unsigned int*)(mem+0x853)==0xD0011BEE)
          )
        {
            Unp->Forced=0x80d;
            Unp->DepAdr=mem[0x834]|mem[0x835]<<8;
            Unp->RetAdr=mem[0x877]|mem[0x878]<<8;
            Unp->StrMem=mem[0x851]|mem[0x852]<<8;
            Unp->fEndAf=0x11b;
            Unp->EndAdC=0xffff;
            PrintInfo(Unp,_I_FACEPACK10);
            Unp->IdFlag=1;return;
        }
    }
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x80d)==0x8538A978) &&
            (*(unsigned int*)(mem+0x811)==0xBD43A201) &&
            (*(unsigned int*)(mem+0x815)==0xFF9D0835) &&
            (*(unsigned int*)(mem+0x853)==0xD0011BEE)
          )
        {
            Unp->Forced=0x80d;
            Unp->DepAdr=mem[0x834]|mem[0x835]<<8;
            Unp->RetAdr=mem[0x876]|mem[0x877]<<8;
            Unp->StrMem=mem[0x851]|mem[0x852]<<8;
            Unp->fEndAf=0x11b;
            Unp->EndAdC=0xffff;
            PrintInfo(Unp,_I_FACEPACK11);
            Unp->IdFlag=1;return;
        }
    }
}
