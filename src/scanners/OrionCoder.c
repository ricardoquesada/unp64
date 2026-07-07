/* Found in The Terminator cracks. Uses directory track content to decrypt
   part of the protected program at $0f00. For some reason the actual text
   is ALSO in memory so the coded program already contains the 3 blocks needed.
   from $0e00 to $0eff xor #$01 -> $0400 (on disk:trk 18 sec 18)
   from $0c00 to $0cff xor #$10 -> $0500 (on disk:trk 18 sec 00)
   from $0d02 to $0da0 xor #$13 -> $0602 (on disk:trk 18 sec 01)
   (extra bytes from $6a0 are ignored)
   bytes at $0600: 12 04 (as it is on trk 18 01) but are ignored
*/
#include "../unp64.h"
void Scn_OrionCoder(unpstr *Unp)
{
    unsigned char *mem;
    int q;
    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
    	if( (mem[0x823] == 0x20) &&
            (*(unsigned int*)(mem+0x82F)==0x8D05A909) &&
            (*(unsigned int*)(mem+0x874)==0x04005D10) &&
            (*(unsigned int*)(mem+0xA00)==0x4C48415D) &&
            (*(unsigned int*)(mem+0xEF0)==0x53453F3F)
          )
        {
            for(q=0;q<0x100;q++)
            {
            	mem[0x400+q] =	mem[0xe00+q] ^ 0x01;
            	mem[0x500+q] =	mem[0xc00+q] ^ 0x10;
            }
            for(q=2;q<0x0a0;q++)
            {
            	mem[0x600+q] =	mem[0xd00+q] ^ 0x13;
            }
            Unp->Forced=0x84a;
            Unp->StrMem=0x801;
            Unp->DepAdr=0x100;
            Unp->EndAdr=Unp->info->end-0x700;
            PrintInfo(Unp,_I_ORIONCOD);
            if(Unp->DebugP)
            {
                printf("%s\r\n",mem+0x400);
                printf("%s\r\n",mem+0x590);
            }
            Unp->IdFlag=1;return;
        }
    }
}
