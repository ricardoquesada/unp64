/* unknown packer found in 20cc demos and bros cracks, probably by Falco Paul */
#include "../unp64.h"
void Scn_FalcoPack(unpstr *Unp)
{
    unsigned char *mem;

    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x80d)==0x8C00A078) &&
            (*(unsigned int*)(mem+0x815)==0x36BD5BA2) &&
            (*(unsigned int*)(mem+0x819)==0x00FA9D08) &&
            (*(unsigned int*)(mem+0x84e)==0x10EE03D0) )
        {
            Unp->Forced=0x80d;
            Unp->DepAdr=0x100;
            Unp->RetAdr=mem[0x85f]|mem[0x860]<<8;
            Unp->fEndAf=0x10f;
            Unp->EndAdC=EA_USE_X|0xffff;
            Unp->StrMem=mem[0x84b]|mem[0x84c]<<8;Unp->StrMem+=mem[0x83d];
            PrintInfo(Unp,_I_FALCOP);
            Unp->IdFlag=1;return;
        }
    }
}
