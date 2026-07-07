/* Thomas Koncina? different versions */
#include "../unp64.h"
void Scn_Koncina(unpstr *Unp)
{
    unsigned char *mem;
    int q,p;
    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        for(p=0x826;p<0x840;p++)
        {
            if((*(unsigned int*)(mem+p+0x000)==0x9A78FAA2) &&
               (*(unsigned int*)(mem+p+0x004)==0x018534A9) &&
               (*(unsigned int*)(mem+p+0x008)==0xAE8400A0) &&
               (*(unsigned int*)(mem+p+0x030)==0x01004CF7) )
            {
                Unp->DepAdr=0x100;
                break;
            }
        }
        if(Unp->DepAdr)
        {
            Unp->Forced=p;
            for(q=p+0x98;q<p+0xb4;q++)
            {
                if(mem[q]==0x4c)
                {
                    Unp->RetAdr=mem[q+1]|mem[q+2]<<8;
                    break;
                }
            }
            Unp->StrMem=mem[p+0x3d]|mem[p+0x41]<<8;
            Unp->EndAdr=0xae;
            PrintInfo(Unp,_I_KONCINA);
            Unp->IdFlag=1;return;
        }
    }
}
