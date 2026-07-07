/* bronx packer */
#include "../unp64.h"
void Scn_BronxPacker(unpstr *Unp)
{
    unsigned char *mem;
    int p;
    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if(mem[0x80d]==0xa0&&
           ((*(unsigned int*)(mem+0x80d)&0x00ffffff)==0x00B900A0) &&
            (*(unsigned int*)(mem+0x812)==0x88000599) &&
            (*(unsigned int*)(mem+0x816)==0xF5D0FFC0) &&
            (*(unsigned int*)(mem+0x8b2)==0x60F7D0CA) )
        {
            p=mem[0x810]|mem[0x811]<<8;p-=5;
            if(mem[p]==0x2f)
            {
                Unp->Forced=0x8a4;
                Unp->StrMem=mem[p+4]|mem[p+5]<<8;
                if( Unp->StrMem==0x7e8)
                    Unp->StrMem=0x800;
                Unp->EndAdr=0x04;
                Unp->RetAdr=mem[0x8ba]|mem[0x8bb]<<8;
                Unp->DepAdr=mem[0x8b6]|mem[0x8b7]<<8;Unp->DepAdr++;
                PrintInfo(Unp,_I_BRONX);
                Unp->IdFlag=1;return;
            }
        }
    }
}
