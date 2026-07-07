/* Bitpacker 2
seems just a clone of Supercompressor/flexible.
*/
#include "../unp64.h"
void Scn_BitPacker(unpstr *Unp)
{
    unsigned char *mem;

    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x816)==0x018400A0) &&
           (*(unsigned int*)(mem+0x81a)==0x990815B9) &&
           (*(unsigned int*)(mem+0x81e)==0x15B90400) &&
           (*(unsigned int*)(mem+0x911)==0x044F4C05) )
        {
            Unp->DepAdr=0x417;
            if(Unp->info->run == -1 )
                Unp->Forced=0x816;
            Unp->StrMem=mem[0x865]|mem[0x866]<<8;
            Unp->RetAdr=mem[0x887]|mem[0x888]<<8;
            Unp->fEndAf=0x450;Unp->EndAdC=0xffff;
            PrintInfo(Unp,_I_BITPACK2);
            Unp->IdFlag=1;return;
        }
    }
}
