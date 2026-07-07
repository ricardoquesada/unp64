/* Packer Optimizer 1.0 */
#include "../unp64.h"
void Scn_PackOpt(unpstr *Unp)
{
    unsigned char *mem;

    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x80b)==0xE67800A0) &&
           ((*(unsigned int*)(mem+0x80f)==0xCEAFC601)||
            (*(unsigned int*)(mem+0x80f)==0xCE2eC601)) &&
           ((*(unsigned int*)(mem+0x813)==0xAEB10819)||
            (*(unsigned int*)(mem+0x813)==0x2dB10819)) &&
            (*(unsigned int*)(mem+0x817)==0xC8000099) &&
            (*(unsigned int*)(mem+0x873)==0x004C0158) )
        {
            Unp->DepAdr=0x100;
            Unp->Forced=0x80b;
            Unp->StrMem=mem[0x834]|mem[0x835]<<8;
            /* Beware: SOMETIMES unpacker places a 0 instead of last byte, even
               if it's in the packed stream! simply forgets to copy it??
               Verified in vice, but I haven't studied why it bugs.
            */
            Unp->fEndAf=0xfe;
            Unp->RetAdr=mem[0x89d]|mem[0x89e]<<8;
            PrintInfo(Unp,_I_PAKOPT);
            Unp->IdFlag=1;return;
        }
    }
}
