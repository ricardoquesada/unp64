/* found in direbreaks & migges cracks */
#include "../unp64.h"
void Scn_FinalCompactor(unpstr *Unp)
{
    unsigned char *mem;
    int p;
    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x81e)==0x4BBD03A2) &&
            (*(unsigned int*)(mem+0x826)==0xBD9AF810) &&
            (*(unsigned int*)(mem+0x82a)==0xFF9D084D) &&
            (*(unsigned int*)(mem+0x860)==0x4A4A4A68) &&
            (mem[0x8f7]==0x4c))
        {
            Unp->DepAdr=0x11e;
            Unp->Forced=0x81e;
            Unp->RetAdr=mem[0x884]|mem[0x885]<<8;
            p=mem[0x934];
            Unp->StrMem=(mem[0x935]^p)|(mem[0x936]^p)<<8;
            Unp->MonEnd=0x04<<16|0x05;
            Unp->fEndAf=0x04;
            PrintInfo(Unp,_I_FINCOMP);
            Unp->IdFlag=1;return;
        }
    }
}
