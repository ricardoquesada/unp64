/* J0xstrap secret cruncher */
#include "../unp64.h"
void Scn_Jox(unpstr *Unp)
{
    unsigned char *mem;
    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if(Unp->info->run==2114)
    {
        if( (*(unsigned int*)(mem+0x83f)==0x7801414C) &&
            (*(unsigned int*)(mem+0x843)==0xE69AF0A2)
          )
        {
            Unp->DepAdr=0x141;
            Unp->fEndAf=0xfe;
            Unp->EndAdC=0xff;
            Unp->StrMem=mem[0x869]|(1+mem[0x86a])<<8;
            Unp->RetAdr=mem[0x89b]|mem[0x89c]<<8;
            PrintInfo(Unp,_I_JOXCR);
            Unp->IdFlag=1;return;
        }
    }
}
