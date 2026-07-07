/* XIP sysless and autostarter */
#include "../unp64.h"
void Scn_XIP(unpstr *Unp)
{
    unsigned char *mem;

    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if(Unp->info->run == -1)
    {
        if(Unp->info->start == 0x326 )
        {
            if( (*(unsigned int*)(mem+0x326)==0xF6ED0351) &&
                (*(unsigned int*)(mem+0x332)==0x08D02B46) &&
                (*(unsigned int*)(mem+0x357)==0x4CD81074) )
            {
                Unp->DepAdr=0x351;Unp->Forced=Unp->DepAdr;
                Unp->RetAdr=mem[0x35b]|mem[0x35c]<<8;
                mem[0x73]=0xe6;
                mem[0x74]=0x7a;
                Unp->StrMem=0x7ae7;
                Unp->fEndAf=0x73;
                Unp->r->x=0x0a;
                PrintInfo(Unp,_I_XIP);
                Unp->IdFlag=1;return;
            }
        }
    }
}
