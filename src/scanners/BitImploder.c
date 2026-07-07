/* BitImploder */
#include "../unp64.h"
void Scn_BitImploder(unpstr *Unp)
{
    unsigned char *mem;
    int p;
    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if(((*(unsigned int*)(mem+0x830)&0xfffff0ff)==0xf00800bd) &&
            (*(unsigned int*)(mem+0x834)==0xffd22006) &&
            (*(unsigned int*)(mem+0x83b)==0xa201e678) &&
            (*(unsigned int*)(mem+0x865)==0xE802009D)
          )
        {
            Unp->DepAdr=0x1d9;
            /* it's not true that the unpacked MUST start at $0801
               found lots of test cases starting all over
            */
            if(Unp->info->run == -1)
            {
                Unp->Forced=0x830;
            }
            Unp->fStrAf=0xfe;
            p=mem[0x845]|mem[0x846]<<8;p+=0x4;
            Unp->EndAdr=mem[p]|mem[p+1]<<8;Unp->EndAdr++;
            PrintInfo(Unp,_I_BITIMP);
            Unp->IdFlag=1;return;
        }
    }
}
