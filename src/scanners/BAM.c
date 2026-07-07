/* THE BAM packer/coders */
#include "../unp64.h"
void Scn_BAM(unpstr *Unp)
{
    unsigned char *mem;
    int p,q;
    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x818)==0xA204A078) &&
           (*(unsigned int*)(mem+0x820)==0x009D0838) &&
           (*(unsigned int*)(mem+0x858)==0xB1A5F3D0) &&
           (*(unsigned int*)(mem+0x868)==0x85B1A5AC) )
        {
            Unp->Forced=0x818;
            Unp->DepAdr=0x100;
            /* loads and packs from $0801 anyway */
            Unp->StrMem=mem[0x836]|mem[0x837]<<8;
            Unp->fEndAf=0xae;
            /* 3 fixed return address on stack, keep only the good one
             * A7 AD (a7ae) 3rd and last
             * A6 58 (a659) 2nd
             * E5 43 (e544) 1st
             */
            for(p=0x83c;p>0x837;p-=2)
            {
                q=mem[p+1]|mem[p]<<8;q++; /* on stack: (hi+lo)-1 */
                if((q == 0xa659)||
                   (q == 0xe544) )
                {
                    p-=2;
                    mem[p+2]=mem[p+0];
                    mem[p+3]=mem[p+1];
                }
            }
            Unp->RetAdr=q;

            PrintInfo(Unp,_I_BAMCOD1);
            Unp->IdFlag=1;return;

        }
    }
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x81e)==0xA201E678) &&
           (*(unsigned int*)(mem+0x822)==0x0828DE00) &&
           (*(unsigned int*)(mem+0x84a)==0x2B2B2B2B) )
        {
            Unp->Forced=0x81e;
            Unp->DepAdr=0x100;
            Unp->StrMem=(mem[0x90b]-1)|(mem[0x90c]-1)<<8;
            Unp->fEndAf=0xae;
            Unp->RetAdr=Unp->StrMem;
            if((mem[0x835]-1)==0x20)
                Unp->RetAdr=(mem[0x836]-1)|(mem[0x837]-2)<<8;
            PrintInfo(Unp,_I_BAMCOD2);
            Unp->IdFlag=1;return;
        }
    }
    /* reductor 2.0 & 3.0 are identical and derived from mc-cracken */
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x818)==0x8537A978) &&
           (*(unsigned int*)(mem+0x81c)==0xA8386801) &&
           (*(unsigned int*)(mem+0x831)==0x2a2a2a2a) &&
           (*(unsigned int*)(mem+0x8d0)==0xB0B10145) )
        {
            Unp->Forced=0x818;
            Unp->DepAdr=0x100;
            Unp->StrMem=mem[0x8f1]|mem[0x8f2]<<8;
            Unp->fEndAf=0xae;
            Unp->RetAdr=mem[0x861]|(mem[0x862]-1)<<8;
            if(Unp->RetAdr==0x1c6)
                Unp->RetAdr=0xa7ae;
            PrintInfo(Unp,_I_BAMCOD3);
            Unp->IdFlag=1;return;
        }
    }
}
