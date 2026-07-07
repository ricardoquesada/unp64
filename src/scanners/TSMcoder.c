/* TSM coder, needs kernal rom just for an indirect JMP $0490 */
#include "../unp64.h"
void Scn_TSMcoder(unpstr *Unp)
{
    unsigned char *mem;
    int p;
    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        p=0x810;
        if((*(unsigned int*)(mem+p+0x000)==0x5CA008A9) &&
           (*(unsigned int*)(mem+p+0x004)==0xDA4806C2) &&
           (*(unsigned int*)(mem+p+0x010)==0x20214D53) &&
           (*(unsigned int*)(mem+p+0x014)==0xFC8292AE) &&
           (*(unsigned int*)(mem+p+0x081)==0xF1D56C04)   )
        {   /* modify unpacker so it doesn't need the kernal rom. */
            mem[p+0x82]=0x4c;
            mem[p+0x83]=mem[p+0x70];
            mem[p+0x84]=mem[p+0x71];
            Unp->DepAdr=mem[p+0x70]|mem[p+0x71]<<8;
            Unp->Forced=0x810;
            Unp->EndAdr=Unp->info->end - 0x94;
            PrintInfo(Unp,_I_TSMCOD);
            Unp->IdFlag=1;return;
        }
    }
    /* packer by Stealth/TSM ? */
    if( Unp->DepAdr==0 )
    {
        p=0x813;
        if((*(unsigned int*)(mem+p+0x000)==0x789AFFA2) &&
           (*(unsigned int*)(mem+p+0x010)==0xE800FC9D) &&
           (*(unsigned int*)(mem+p+0x020)==0xEE03D008) &&
           (*(unsigned int*)(mem+p+0x080)==0x8501634C)   )
        {   /* modify unpacker so it doesn't need the kernal rom. */
            Unp->DepAdr=0x100;
            Unp->Forced=0x813;
            Unp->StrMem=mem[p+0x3c]|mem[p+0x3d]<<8;
            Unp->fEndAf=0xfe;
            Unp->RetAdr=mem[p+0x5e]|mem[p+0x5f]<<8;
            PrintInfo(Unp,_I_TSMPACK);
            Unp->IdFlag=1;return;
        }
    }
}
