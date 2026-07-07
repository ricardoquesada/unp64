/* 4wdsoft Packer */
#include "../unp64.h"
void Scn_4wd(unpstr *Unp)
{
    unsigned char *mem;

    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x811)==0x2901A578) &&
           (*(unsigned int*)(mem+0x821)==0xA9FD85FF) &&
           (*(unsigned int*)(mem+0x849)==0x08284CFD) &&
           (*(unsigned int*)(mem+0x891)==0xAD03404C) )
        {
            Unp->DepAdr=0x340;
            Unp->Forced=0x811;
            Unp->RetAdr=mem[0x906]|mem[0x907]<<8;
            Unp->fEndAf=0xfd;
            Unp->StrMem=mem[0x910]|mem[0x911]<<8;
            PrintInfo(Unp,_I_4WD);
            Unp->IdFlag=1;return;
        }
    }
}
