/* TMC Coder */
#include "../unp64.h"
void Scn_TMCcoder(unpstr *Unp)
{
    unsigned char *mem;

    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x811)==0x8535A978) &&
           (*(unsigned int*)(mem+0x815)==0xBD35A201) &&
           (*(unsigned int*)(mem+0x819)==0x339D0823) &&
           (*(unsigned int*)(mem+0x821)==0xA903344C) &&
           (*(unsigned int*)(mem+0x829)==0x0856BDFF) )
        {
            Unp->DepAdr=0x334;
            Unp->Forced=0x811;
            if(*(unsigned int*)(mem+0x850)==0x4CA65920)
            {
                mem[0x850]=0x2c;
            }
            Unp->RetAdr=mem[0x854]|mem[0x855]<<8;
            Unp->EndAdr=Unp->info->end - 0x55;
            Unp->StrMem=mem[0x833]|mem[0x834]<<8;
            PrintInfo(Unp,_I_TMCCOD);
            Unp->IdFlag=1;return;
        }
    }
}
