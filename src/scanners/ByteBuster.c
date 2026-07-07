/* ByteBuster 4.0+4.1 Tao/Triad
   Variable code; 2 modes low (reloc to zp) & high (no reloc, unpacker at $801)
*/
#include "../unp64.h"
void Scn_ByteBuster(unpstr *Unp)
{
    unsigned char *mem;
    unsigned int p,q;
    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if( mem[0x802]==0x78 )
        {
            for(p=0x807;p<0x80a;p++)
            {
                if((*(unsigned int*)(mem+p)              ==0x880800BE) &&
                  ((*(unsigned int*)(mem+p+4)&0x00ffffff)==0x004CF8D0) )
                {
                    Unp->DepAdr=mem[p+0x7];
                    break;
                }
            }
            if(Unp->DepAdr)
            {
                for(q=0x839;q<0x846;q++)
                {
                    if((mem[q]  ==0x8d)&&
                       (mem[q+3]==0xe6)&&
                       (mem[q+7]==0xe6)&&
                       (mem[q+5]==0xd0) )
                    {
                        Unp->StrMem=mem[q+1]|mem[q+2]<<8;
                        Unp->Forced=0x802;
                        Unp->fEndAf=mem[q+4];
                        Unp->EndAdC=0xfffe; /* 2 bytes in excess always? */
                        for(p=q+0x010;p<q+0x20;p++)
                        {
                            if(mem[p]==0x4c)
                            {
                                Unp->RetAdr=mem[p+1]|mem[p+2]<<8;
                                break;
                            }
                        }
                        PrintInfo(Unp,_I_BYTEBUST4L);
                        Unp->IdFlag=1;return;
                        break;
                    }
                }
            }
        }
        else if((mem[0x801]==0xee)&&(mem[0x80d]==0x78))
        {
            if((*(unsigned int*)(mem+0x802) == 0x03D0080A) &&
               (*(unsigned int*)(mem+0x81e) == 0x19CE0816) )
            {
                for(q=0x835;q<0x840;q++)
                {
                    if((mem[q]  ==0x8d)&&
                       (mem[q+3]==0xee) )
                    {
                        Unp->DepAdr=0x801;
                        Unp->Forced=0x80d;
                        Unp->StrMem=mem[q+1]|mem[q+2]<<8;
                        Unp->fEndAf=q+1;
                        Unp->EndAdC=0xfffe; /* 2 bytes in excess always? */
                        for(p=q+0x010;p<q+0x20;p++)
                        {
                            if(mem[p]==0x4c)
                            {
                                Unp->RetAdr=mem[p+1]|mem[p+2]<<8;
                                break;
                            }
                        }
                        PrintInfo(Unp,_I_BYTEBUST4H);
                        Unp->IdFlag=1;return;
                        break;
                    }
                }
            }

        }

    }
}
