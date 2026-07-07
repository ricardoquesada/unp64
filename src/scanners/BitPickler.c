/* BitPickler / CJam
   Experimental, not sure how to work this out
   uses SHX $7e00,y (implemented now in 6502emu.c) and many other illegals
   part of the unpacking code is packed, so it's not visible...
*/
#include "../unp64.h"
void Scn_BitPickler(unpstr *Unp)
{
    unsigned char *mem;
    int q,p;
    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x80d)==0x8524A978) &&
           (*(unsigned int*)(mem+0x811)==0x7C009901) &&
           (*(unsigned int*)(mem+0x8ff)==0x907E01BD))
        {
            Unp->Forced=0x80d;
            // workaround for onscreen5k and x-tiles
            p=mem[0x82e];
            if( (p == 0x9c) ||
                (p == 0xa0) ||
                (p == 0xa3) ||
                (p == 0xa5) ||
                (p == 0xa9) )
                p=0x19;  // add to skip this code
            else
                p=0x0;  // normally is $ac,$a8,$a4, offsets are correct
            Unp->DepAdr=mem[0x8d4]|mem[0x8d5]<<8;
            Unp->DepAdr+=p;
            // point on the CLI or JMP, needs a workaround in main()
            // because we don't see the actual code before it's unpacked
            Unp->RetAdr=Unp->DepAdr+0x1a;
            q=Unp->DepAdr+0x8;
            Unp->MonStr=(q<<16)|(q+1);
            Unp->fEndAf=q;
            Unp->RtAFrc=1;
            Unp->BPKFlg=1;
            PrintInfo(Unp,_I_BITPICK1);
            Unp->IdFlag=1;return;
        }
        if((mem[0x80d]==0xee)&&
           (*(unsigned int*)(mem+0x817)==0x8524A978) &&
           (*(unsigned int*)(mem+0x81b)==0x7D009901) &&
           (*(unsigned int*)(mem+0x87b)==0xB37F0099))
        {
            p=mem[0x838]; // workaround for onscreen5k
            if( (p==0x93) || (p==0x96) )
                p=0x19;    // add to skip this code
            else
                p=0;
            // tiny
            if (mem[0x08AE]==0x4A)
                q=0x8c2;
            else // --tiny + --novis
                q=0x8bc;

            Unp->DepAdr=mem[q]|mem[q+1]<<8;
            Unp->DepAdr+=p;
            Unp->Forced=0x817;
            // point on the CLI or JMP, needs a workaround in main()
            Unp->RetAdr=Unp->DepAdr+0x1a;
            q=Unp->DepAdr+0x8;
            Unp->MonStr=(q<<16)|(q+1);
            Unp->fEndAf=q;
            Unp->RtAFrc=1;
            Unp->BPKFlg=1;
            PrintInfo(Unp,_I_BITPICK1T);
            Unp->IdFlag=1;return;
        }
    }
}
