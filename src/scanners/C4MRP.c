/* C4 Mr.President/RSi */
#include "../unp64.h"
void Scn_C4MRP(unpstr *Unp)
{
    unsigned char *mem;
    int q,p;
    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x801)==0x867800A2) &&
            (*(unsigned int*)(mem+0x80b)==0xBD0813CE) &&
            (*(unsigned int*)(mem+0x819)==0x00024CEE) &&
            (mem[0x813]==0))
        {
            p=mem[0x80f]|mem[0x810]<<8;p-=mem[0x812];
            if((mem[p]==0x2f)&&(mem[p+0x05]==0xa2)&&
               (*(unsigned int*)(mem+p+0x07)==0xD508F0CA) &&
               (*(unsigned int*)(mem+p+0x35)==0xD0CA31E6) )
            {
                Unp->DepAdr=0x2;
                Unp->Forced=0x801;
                Unp->StrMem=mem[p+0x30]|mem[p+0x31]<<8;
                for(q=0x42;q<0x44;q++)
                {
                    if(mem[p+q]==0x4c)
                    {
                        Unp->RetAdr=mem[p+q+1]|mem[p+q+2]<<8;
                        break;
                    }
                }
                Unp->fEndAf=0x30;
                Unp->EndAdC=EA_ADDFF|EA_USE_Y|0xffff;
                PrintInfo(Unp,_I_C4MRP);
                Unp->IdFlag=1;return;
            }
        }
    }
}
