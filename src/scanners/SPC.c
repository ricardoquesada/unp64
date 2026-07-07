/* SPC/FCS Coder */
#include "../unp64.h"
void Scn_SPC(unpstr *Unp)
{
    unsigned char *mem;
    int p;
    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x811)==0x8535A978) &&
           (*(unsigned int*)(mem+0x821)==0xA904454C) &&
           (*(unsigned int*)(mem+0x829)==0x0856BDFF) &&
           (*(unsigned int*)(mem+0x839)==0xD0FFA5FF) )
        {
            Unp->Forced=0x811;
            Unp->DepAdr=0x445;
            Unp->StrMem=0x801;
            Unp->EndAdr=Unp->info->end-0x55;
            p=0x850;
            Unp->RetAdr=mem[p+1]|mem[p+2]<<8;
            if(Unp->RetAdr == 0xa659)
            {
                mem[p]=0x2c;
                p+=3;
                Unp->RetAdr=mem[p+1]|mem[p+2]<<8;
            }
            PrintInfo(Unp,_I_SPCCOD);
            Unp->IdFlag=1;return;

        }
    }
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x80d)==0x1DBD00A2) &&
           (*(unsigned int*)(mem+0x811)==0x02904A08) &&
           (*(unsigned int*)(mem+0x815)==0x1D9D8009) &&
           (*(unsigned int*)(mem+0x85e)==0x067ADD10) )
        {
            Unp->Forced=0x80d;
            Unp->DepAdr=0x33c;
            Unp->StrMem=0x800;
            Unp->EndAdr=0xae; /* end-0x100 */
            PrintInfo(Unp,_I_SPCPROT);
            Unp->IdFlag=1;return;
        }
    }
}
