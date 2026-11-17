/* Duplex Coder */
#include "../unp64.h"
void Scn_DuplexCoder(unpstr *Unp)
{
    unsigned char decrmem[0x200];
    unsigned char *mem;
    int q=0, p=0, i=0;;
    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {

        if((*(unsigned int*)(mem+0x81F)==0xAD0400A2) &&
           (*(unsigned int*)(mem+0x825)==0x499D0408) &&
           (*(unsigned int*)(mem+0x82b)==0x03FE9DBD) &&
           (*(unsigned int*)(mem+0x837)==0x03FE6C4E)
          )
        {
            memcpy(decrmem, mem + 0x83d, 0x100);
            // xorvalue
            q = mem[0x829];
            for (i = 0;i < 0x100;i++)
            {
                decrmem[i] ^= q;
            }
            p=0x3fe; //decrmem[0] real address
            Unp->Forced = 0x081f;
            Unp->DepAdr = decrmem[0]|decrmem[1]<<8; // $0428
            Unp->RetAdr = decrmem[0x471-p]|decrmem[0x472-p]<<8;
            Unp->StrMem = 0x0801;
            Unp->EndAdr = Unp->info->end-0xb4;
            if (Unp->DebugP)
            {
                printmsg(decrmem,2,40);
            }
            PrintInfo(Unp,_I_DUPLEXCOD31);
            Unp->IdFlag=1;return;
        }
        if((*(unsigned int*)(mem+0x823)==0x018534A9) &&
           (*(unsigned int*)(mem+0x829)==0x490833B9) &&
           (*(unsigned int*)(mem+0x82e)==0xC8083399)
          )
        {
            p=0x833; //decrmem[0] real address
            memcpy(decrmem, mem + p, 0x100);
            // xorvalue
            q = mem[0x82d];
            for (i = 0;i < 0x200;i++)
            {
                decrmem[i] ^= q;
            }
            // xorvalue #2
            q=decrmem[0x847-p];
            for (i = 0;i < 0x200;i++)
            {
                decrmem[i] ^= q;
            }
            p=0x860-0x833; // 0860->0400

            Unp->Forced = 0x0823;
            Unp->DepAdr = 0x0428;
            Unp->fEndAf = 0x046b;
            Unp->StrMem = 0x0801;
            Unp->EndAdr = Unp->info->end-0xd0;
            if (Unp->DebugP)
            {
                printmsg(decrmem,p,40);
            }
            PrintInfo(Unp,_I_DUPLEXCOD30);
            Unp->IdFlag=1;return;
        }
    }
}
