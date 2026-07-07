/* PIT Coder */
#include "../unp64.h"
void Scn_PITcoder(unpstr *Unp)
{
    unsigned char *mem;
    int q,p;
    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x81d)==0x4A082BBD) &&
           (*(unsigned int*)(mem+0x821)==0x80090290) &&
           (*(unsigned int*)(mem+0x825)==0xCA082B9D) &&
           (*(unsigned int*)(mem+0x829)==0x0DF0F2D0) &&
           (*(unsigned int*)(mem+0x891)==0x02530650) )
        {
            Unp->DepAdr=0x33c;
            Unp->Forced=0x81d;
            if(*(unsigned int*)(mem+0x888)==0x984DB240)
            {
                Unp->RetAdr=0xa7ae;
            }
            else
            {
                p=(mem[0x889]>>1)|((mem[0x889]&0x01)<<7);
                q=(mem[0x88a]>>1)|((mem[0x88a]&0x01)<<7);
                Unp->RetAdr=p|q<<8;
            }
            //endaddr=Unp->info->end-0x100;
            Unp->fEndAf=0x34a;
            Unp->EndAdC=0xffff;
            p=(mem[0x84d]>>1)|((mem[0x84d]&0x01)<<7);
            q=(mem[0x84e]>>1)|((mem[0x84e]&0x01)<<7);
            Unp->StrMem=p|q<<8;
            PrintInfo(Unp,_I_PITCOD);
            Unp->IdFlag=1;return;
        }
    }
}
