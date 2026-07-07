/* Skylight Protector
   uses a real bunch of illegals  */
#include "../unp64.h"
void Scn_SKLcoder(unpstr *Unp)
{
    unsigned char *mem;

    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x80b)==0x208E00A2) &&
           (*(unsigned int*)(mem+0x81b)==0x099D090C) &&
           (*(unsigned int*)(mem+0x83c)==0x084FBD01) &&
           (*(unsigned int*)(mem+0x84c)==0x05004CF0) )
        {
            Unp->DepAdr=0x574;
            Unp->Forced=0x80b;
            Unp->StrMem=0x0801;
            Unp->RetAdr=0x0801;
            Unp->fEndAf=0x2d;
            Unp->EndAdC=0xffff;
            /* hack:
               change:INX
                      ISB $00,x
                      BRK (0316 is set to entry point)
               into:  JMP ($0316)
            */
            mem[0x8c4]=0x3b; /* 6c ^ 20 ^ 77 */
            mem[0x8c5]=0x41; /* 16 ^ 20 ^ 77 */
            mem[0x8c6]=0x54; /* 03 ^ 20 ^ 77 */
            PrintInfo(Unp,_I_SKLCOD);
            Unp->IdFlag=1;return;
        }
    }
}
