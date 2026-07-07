/* NuCrunch/ChristopherJam */
#include "../unp64.h"
void Scn_NuCrunch(unpstr *Unp)
{
    unsigned char *mem;
    int p=0,q=0,s=0,t=0;
    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        for(q=0x80b;q<0x840;q++)
        {
            if(((*(unsigned int*)(mem+q+0x00)&0xffffff00)==0x85E08600) &&
                (*(unsigned int*)(mem+q+0x04)==0x8400A0E1) &&
                (*(unsigned int*)(mem+q+0x08)==0x84E384E2) &&
                (*(unsigned int*)(mem+q+0x0c)==0x2000A0E4) )
            {
                if(Unp->info->run == -1)
                {
                    Unp->Forced=0x80d;
                }
                t=mem[q+0x013]|mem[q+0x014]<<8;
                Unp->DepAdr=t-1;
                if((mem[q]>0x03)&&(mem[q-5]==0x20))
                {
                    // alpha versions, found in after39cws.prg & scharf.prg
                    s=q-2;
                    Unp->RtAFrc=1;
                    Unp->MonStr=(t<<16)|(t+1);
                    t=q+0x75;
                    Unp->MonEnd=(t<<16)|(t+1);
                    // *fixme* this is a workaround, can't get exact start/end address
                    // because there are 2 pointers and not updated at the same time
                    Unp->EndAdC=0x100;
                    Unp->StrAdC=0xffff;
                }
                else
                {
                    Unp->fStrAf=t;
                    if( mem[q+0x1d]==0x20 )
                    {   // compact version
                        t=q+0x10f;
                        s=q+0x125;
                    }
                    else
                    {
                        t=q+0x186;
                        s=q+0x1a0;
                    }
                    for(p=t;p<t+0x10;p++)
                    {   // This to cover an early variant in approp_jr.prg
                        // it's 2 bytes after the normal position
                        if(mem[p]==0xbd)
                            break;
                    }
                    if(mem[p]==0xbd)
                    {
                       t=p+1;
                       p=mem[t]|mem[t+1]<<8;
                       p--;
                       t=mem[p]|mem[p-1]<<8;
                       if(t<0x100)
                       {
                           p-=0x09;
                           t=mem[p]|mem[p-1]<<8;
                       }
                       Unp->EndAdr = ++t;
                    }
                }

                for(p=s;p<s+0x20;p++)
                {
                    if(mem[p]==0x4c)
                    {
                        Unp->RetAdr=0;
                        if((Unp->RetAdr=mem[p+1]|mem[p+2]<<8)>=0x200)
                        {
                            break;
                        }
                        else
                        {   /* it's a jmp $01xx, goto next */
                            p++;
                            p++;
                        }
                    }
                }
                PrintInfo(Unp,_I_NUCRUNCH );
                Unp->IdFlag=1;return;
            }
        }
    }
}
