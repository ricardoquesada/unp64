/* BlackAdder/VSN */
#include "../unp64.h"
void Scn_BlackAdder(unpstr *Unp)
{
    unsigned char *mem;

    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x817)==0x208D00A9) &&
           (*(unsigned int*)(mem+0x82f)==0x88033499) &&
           (*(unsigned int*)(mem+0x833)==0x384CF710) &&
           (*(unsigned int*)(mem+0x84f)==0x03E605E6) )
        {
            Unp->DepAdr=0x338;
            Unp->Forced=0x817;
            Unp->RetAdr=mem[0x85f]|mem[0x860]<<8;
            Unp->StrMem=mem[0x83a]|mem[0x83b]<<8;Unp->StrMem++;
            Unp->EndAdr=Unp->info->end - (mem[0x838]|mem[0x839]<<8)-1+Unp->StrMem;
            PrintInfo(Unp,_I_BLACKADDER);
            Unp->IdFlag=1;return;
        }
    }
}
