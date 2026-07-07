#include "../unp64.h"
void Scn_CIACrypt(unpstr *Unp)
{
    unsigned char *mem;
    int p;
    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x816)==0xA20829EE) &&
           (*(unsigned int*)(mem+0x81e)==0x2A9D0949) &&
           (*(unsigned int*)(mem+0x822)==0x082ADE08) &&
           (*(unsigned int*)(mem+0x8d6)==0xAA09CD28) )
        {
            Unp->Forced=0x816;
            Unp->DepAdr=0x33c;
            Unp->EndAdr=Unp->info->end-0xff;
            PrintInfo(Unp,_I_CIACRP);
            if(Unp->DebugP)
            {
                for(p=0x890;p<0x900;p++)
                {
                    mem[p]^=0x09;
                    mem[p]-=0x01;
                }
                printmsg(mem,0x890,40);
            }
            Unp->IdFlag=1;return;
        }
    }
}
