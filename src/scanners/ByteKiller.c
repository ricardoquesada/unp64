/* Bytekiller/MrWegi */
#include "../unp64.h"
void Scn_ByteKiller(unpstr *Unp)
{
    unsigned char *mem;

    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x80d)==0x8538A978) &&
           (*(unsigned int*)(mem+0x819)==0x84FFA0FC) &&
           (*(unsigned int*)(mem+0x81d)==0xC8FE84FD) &&
           (*(unsigned int*)(mem+0x855)==0x010A4CF7) )
        {
            Unp->DepAdr=0x10a;
            if(Unp->info->run == -1)
                Unp->Forced=0x80b;
            Unp->RetAdr=mem[0x8a2]|mem[0x8a3]<<8;
            Unp->EndAdr=0xfb;
            Unp->StrMem=mem[0x844]|mem[0x848]<<8;
            PrintInfo(Unp,_I_BYTEKILL);
            Unp->IdFlag=1;return;
        }
    }
}
