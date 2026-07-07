/* BonanzaBros coder */
#include "../unp64.h"
void Scn_BonanzaBros(unpstr *Unp)
{
    unsigned char *mem;
    int p;
    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        p=0x812;
        if((*(unsigned int*)(mem+p+0x000)==0xA2786C04) &&
           (*(unsigned int*)(mem+p+0x004)==0x0821FF00) &&
           (*(unsigned int*)(mem+p+0x008)==0x040821FF) &&
           (*(unsigned int*)(mem+p+0x00c)==0xF3D0E84C) )
        {   /* modify unpacker to execute irq as sequential code. */
            mem[p+0x51]=0x4a;
            mem[p+0x52]=0xfe;
            mem[p+0x53]=0x02;
            Unp->DepAdr=0x492;
            Unp->Forced=p;
            Unp->EndAdr=0x2d;
            PrintInfo(Unp,_I_BONANZA);
            Unp->IdFlag=1;return;
        }
    }
}
