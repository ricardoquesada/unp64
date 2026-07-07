/* HTL Coder */
#include "../unp64.h"
void Scn_HTLcoder(unpstr *Unp)
{
    unsigned char *mem;
    int q;
    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x810)==0xA201E678) &&
           (*(unsigned int*)(mem+0x815)==0x450825BD) &&
           (*(unsigned int*)(mem+0x819)==0x01009DAE) &&
           (*(unsigned int*)(mem+0x81d)==0xD020E0E8) &&
           (*(unsigned int*)(mem+0x821)==0x01004CF3) )
        {
            Unp->DepAdr=0x100;
            Unp->Forced=0x810;
            q=mem[0x826];
            Unp->RetAdr=(mem[0x843]^q)|(mem[0x844]^q)<<8;
            Unp->EndAdr=Unp->info->end-0x44;
            Unp->StrMem=0x0801;
            PrintInfo(Unp,_I_HTLCOD);
            /* debug
            p=Unp->info->end&0xff;
            if(q!=p)
            {
                printf("*WARNING*\n"
                       "Crypt value #1 ($826=$%02x) not equal to filesize.lowbyte=$%02x\n",q,p);
            }
            */
            Unp->IdFlag=1;return;
        }
    }
}
