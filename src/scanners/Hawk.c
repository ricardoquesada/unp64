/* Hawk(?) packer */
#include "../unp64.h"
void Scn_Hawk(unpstr *Unp)
{
    unsigned char *mem;

    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x82b)==0xF886F786) &&
           (*(unsigned int*)(mem+0x82f)==0x0186E878) &&
           (*(unsigned int*)(mem+0x833)==0x9D0849BD) &&
           (*(unsigned int*)(mem+0x837)==0xE0E80100) &&
           (*(unsigned int*)(mem+0x8a2)==0xB1012320) )
        {
            Unp->DepAdr=0x100;
            if(Unp->info->run == -1)
                Unp->Forced=0x811;
            Unp->StrMem=mem[0x87b]|mem[0x87d]<<8;
            Unp->RetAdr=mem[0x8cf]|mem[0x8d0]<<8;
            Unp->EndAdr=0xf9;
            PrintInfo(Unp,_I_HAWK);
            if(Unp->DebugP)
                printmsg(mem,0x8d6,40);
            Unp->IdFlag=1;return;
        }
    }
}
