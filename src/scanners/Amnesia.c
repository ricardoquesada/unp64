/* Amnesia(?) packer */
/*
So far I've found only files that unpack 0800-ffff, so this scanner
is completely unneeded, apart for printing it's recognized =)
A simpler version without screen text found in at least 3 files.
*/
#include "../unp64.h"
void Scn_Amnesia(unpstr *Unp)
{
    unsigned char *mem;
    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x81b)==0x9D084CBD) &&
           (*(unsigned int*)(mem+0x82e)==0xA00186EC) &&
           (*(unsigned int*)(mem+0x83b)==0xD0FFE0CA) &&
           (*(unsigned int*)(mem+0x899)==0xA6F2D088) )
        {
            Unp->DepAdr=0x428;
            if(Unp->info->run == -1)
                Unp->Forced=0x80b;
            Unp->RetAdr=mem[0x8ab]|mem[0x8ac]<<8;
            Unp->StrMem=mem[0x88f]|mem[0x890]<<8;
            Unp->fEndAf=0x443;
            PrintInfo(Unp,_I_AMNESIA1);
            if(Unp->DebugP)
                printmsg(mem,0x84c,40);
            Unp->IdFlag=1;return;
        }
    }
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x80b)==0x867800A2) &&
           (*(unsigned int*)(mem+0x813)==0x349D0836) &&
           (*(unsigned int*)(mem+0x825)==0xD0FFE0CA) &&
           (*(unsigned int*)(mem+0x85b)==0xA6F2D088) )
        {
            Unp->DepAdr=0x334;
            if(Unp->info->run == -1)
                Unp->Forced=0x80b;
            Unp->RetAdr=mem[0x86d]|mem[0x86e]<<8;
            Unp->StrMem=mem[0x851]|mem[0x852]<<8;
            Unp->fEndAf=0x34f;
            PrintInfo(Unp,_I_AMNESIA2);
            Unp->IdFlag=1;return;
        }
    }
}
