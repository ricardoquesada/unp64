/* NEC/LRU packer */
#include "../unp64.h"
void Scn_NEC(unpstr *Unp)
{
    unsigned char *mem;
    int q,p=0;
    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        for(q=0x801;q<0x830;q++)
        {
            if((*(unsigned int*)(mem+q+0x00)==0x018530A9) &&
               (*(unsigned int*)(mem+q+0x04)==0xE938AEA5) &&
               (*(unsigned int*)(mem+q+0x40)==0x48B0B101) &&
               (*(unsigned int*)(mem+q+0x44)==0x292A2A2A)   )
            {
                Unp->DepAdr=0x100;
                p=q;
                break;
            }
        }
        if( Unp->DepAdr )
        {
            if(Unp->info->run == -1)
                Unp->Forced=p;
            Unp->EndAdr=0xae;
            Unp->StrMem=mem[p+0xb3]|mem[p+0xb4]<<8;
            Unp->RetAdr=mem[p+0x6e]|mem[p+0x6f]<<8;
            PrintInfo(Unp,_I_NECPACK);
            Unp->IdFlag=1;return;
        }
    }
}
