/* Brains packer, apparently does always $0800-ffff */
#include "../unp64.h"
void Scn_Brains(unpstr *Unp)
{
    unsigned char *mem;
    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x815)==0x22B9A1A0) &&
           (*(unsigned int*)(mem+0x819)==0x03339908) &&
           (*(unsigned int*)(mem+0x821)==0x02A00334) &&
           (*(unsigned int*)(mem+0x895)==0xC503CC20) )
        {
            Unp->DepAdr=0x334;
            Unp->Forced=0x815;
            Unp->RetAdr=mem[0x8b9]|mem[0x8ba]<<8;
            PrintInfo(Unp,_I_BRAINS);
            Unp->IdFlag=1;return;
        }
    }
}
