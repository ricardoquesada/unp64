/* unknown $8e */
#include "../unp64.h"
void Scn_U_8e_pack(unpstr *Unp)
{
    unsigned char *mem;
    int q,p;
    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x80e)==0xE69AFFA2) &&
            (*(unsigned int*)(mem+0x832)==0x083EB901) &&
            (*(unsigned int*)(mem+0x836)==0x88005F99) &&
            (*(unsigned int*)(mem+0x83a)==0x8E4CF1D0) )
        {
            Unp->Forced=0x80e;
            Unp->DepAdr=0x08e;
            for(q=0x8ae;q<0x8b8;q++)
            {
                if((mem[q]==0x20)||(mem[q]==0x4c))
                {
                    p=mem[q+1]|mem[q+2]<<8;
                    if(mem[q]==0x20)
                    {
                        if( p==0xa871 )
                        {
                            mem[q]=0x2c;
                            q+=2;
                            continue;
                        }
                    }
                    Unp->RetAdr=p;
                    break;
                }
            }
            if(mem[0x891]==0xa9)
                Unp->EndAdr=mem[0x88e]|mem[0x892]<<8;
            else /* in case it sets also $2d/2e */
                Unp->EndAdr=mem[0x88e]|mem[0x894]<<8;

            Unp->StrMem=mem[0x8bb]|mem[0x8bc]<<8; /* 0800 fixed */
            /* depacker cleaner */
            //mem[0x8a7]=0x2c;
            PrintInfo(Unp,_I_U_8E);
            Unp->IdFlag=1;return;
        }
    }
}
