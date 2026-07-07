/* Beastlink/OneWay */
#include "../unp64.h"
void Scn_BeastLink(unpstr *Unp)
{
    unsigned char *mem;
    int q,p;
    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        p=0;
        for(q=Unp->info->start;q<=Unp->info->start+0x10;q++)
        {
            if(((*(unsigned int*)(mem+q+0x00)&0x00ffffff)==0x00A200A0) &&
                (*(unsigned int*)(mem+q+0x07)==0xB901E678) &&
                (*(unsigned int*)(mem+q+0x1b)==0x001F4CEE) )
            {
                p=mem[q+0x0b]|mem[q+0x0c]<<8;p+=0x8d;
                break;
            }
        }
        if(p)
        {
            if((mem[p]==0x2f)&&
               (*(unsigned int*)(mem+p+0x0d)==0x02D00BE6) )
            {
                Unp->DepAdr=0x01f;
                Unp->Forced=q;
                q=p+0x3d;
                if(*(unsigned int*)(mem+q)==0x4CE3BF20)
                {
                    mem[q]=0x2c;
                    q=p+0x41;
                }
                if(mem[q]!=0x4c)
                    q=p+0x41;
                Unp->RetAdr=mem[q]|mem[q+1]<<8;
                Unp->StrMem=mem[p+0xb]|mem[p+0xc]<<8;
                Unp->fEndAf=0xb;
                PrintInfo(Unp,_I_BEASTLINK);
                Unp->IdFlag=1;return;
            }
        }
    }
}
