/* Jazoo coder */
#include "../unp64.h"
void Scn_Jazoo(unpstr *Unp)
{
    unsigned char *mem;
    int q,p;
    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x81f)==0x018535A9) &&
           (*(unsigned int*)(mem+0x823)==0x36BD00A2) &&
           (*(unsigned int*)(mem+0x827)==0x8DEF4908) &&
           (*(unsigned int*)(mem+0x84F)==0xECD30105) )
        {
            Unp->DepAdr=0x334;
            Unp->Forced=0x81f;
            q=mem[0x829]; /* xor byte at $829 seems fixed */
            p=q<<24|q<<16|q<<8|q;
            Unp->RetAdr=(mem[0x862]^q)|(mem[0x863]^q)<<8;
            if( (*(unsigned int*)(mem+0x861)^p)==0x4CA65920 )
            {
                mem[0x861]=0x2c^q;
                Unp->RetAdr=(mem[0x866]^q)|(mem[0x867]^q)<<8;
            }
            Unp->StrMem=0x801;
            Unp->EndAdr=Unp->info->end - 0x67;
            PrintInfo(Unp,_I_JAZOOCOD);
            Unp->IdFlag=1;return;
        }
    }
}
