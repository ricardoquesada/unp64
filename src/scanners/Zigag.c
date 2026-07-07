/* Zigag Packer */
#include "../unp64.h"
void Scn_Zigag(unpstr *Unp)
{
    unsigned char *mem;
    int p;
    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if(((*(unsigned int*)(mem+0x80d)&0xff00ffff)==0x8500A978) &&
           (*(unsigned int*)(mem+0x815)==0xA2FB84FA) &&
           (*(unsigned int*)(mem+0x819)==0x0860BD00) &&
           (*(unsigned int*)(mem+0x8c1)==0x20034D20) &&
           (*(unsigned int*)(mem+0x8c5)==0x5A20035A) )
        {
            Unp->DepAdr=0x334;
            Unp->Forced=0x80d;
            p=0x8d4;
            if( (mem[p]&0xdf) == 0x58 )
                p++;
            if(*(unsigned int*)(mem+p)==0x4CA65920)
            {
                mem[p]=0x2c;
                Unp->RetAdr=mem[p+4]|mem[p+5]<<8;
            }
            else
                Unp->RetAdr=mem[p+1]|mem[p+2]<<8;
            Unp->EndAdr=0xfc;
            Unp->StrMem=mem[0x826]|mem[0x82a]<<8;
            PrintInfo(Unp,_I_ZIGAG);
            Unp->IdFlag=1;return;
        }
    }
}
