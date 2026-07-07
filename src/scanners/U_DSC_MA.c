/* Sys(2066)DSC/MA/DM */
#include "../unp64.h"
void Scn_U_DSC_MA(unpstr *Unp)
{
    unsigned char *mem;
    int p;
    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if(Unp->DepAdr==0)
    {
        if( (*(unsigned int*)(mem+0x812)==0x8D0BA978) ||
            (*(unsigned int*)(mem+0x816)==0x34A9D011) ||
           ((*(unsigned int*)(mem+0x81a)&0x00ffffff)==0x004C0185) )
        {
            p=mem[0x81d]|mem[0x81e]<<8;
            if( (*(unsigned int*)(mem+p+0x00)==0x0CAD00A2)&&
               ((*(unsigned int*)(mem+p+0x04)&0xff00ffff)==0xD000C908) &&
                (*(unsigned int*)(mem+p+0x2a)==0x041B4CDE) )
            {
                mem[p+8]=0; /* anti hack */
                Unp->DepAdr=0x41b;
                Unp->Forced=0x812;
                Unp->RetAdr=mem[p+0x147]|mem[p+0x148]<<8;
                Unp->EndAdr=0xae;
                PrintInfo(Unp,_I_DSCCR);
                Unp->IdFlag=1;return;
            }
            else if(((*(unsigned int*)(mem+p+0x00)&0x00ffffff)==0x00BD1EA2) &&
                     (*(unsigned int*)(mem+p+0x10)==0xBD01009D)&&
                     (*(unsigned int*)(mem+p+0xc0)==0x18019120) )
            {
                Unp->DepAdr=0x100;
                Unp->Forced=0x812;
                Unp->RetAdr=mem[p+0xf9]|mem[p+0xfa]<<8;
                Unp->EndAdr=0xae;
                Unp->fStrAf=0xb0;
                /* not much to adjust here, the unpacker itself always writes
                   2 bytes too much before real start (7fe instead of 800).
                   Also, Y is always 0.
                */
                Unp->StrAdC=2;
                PrintInfo(Unp,_I_DSCPK);
                Unp->IdFlag=1;return;
            }
        }
    }
    if(Unp->DepAdr==0)
    {
        if( (mem[0x812]==0x78) && (mem[0x81c]==0x4c) &&
            (*(unsigned int*)(mem+0x818)==0x018534A9) )
        {
            p=mem[0x81d]|mem[0x81e]<<8;
            if( (mem[p+0  ]==0xa2) && (mem[p+1]==0) &&
                (*(unsigned int*)(mem+p+0x11)==0x009D02B5) &&
                (*(unsigned int*)(mem+p+0x39)==0x00024CD7) &&
                (*(unsigned int*)(mem+p+0x3d)==0x950400BD) )
            {
                Unp->DepAdr=0x2c0;
                Unp->Forced=0x812;
                Unp->RetAdr=mem[p+0x52]|mem[p+0x53]<<8;
                Unp->EndAdr=mem[p+0xa1]|mem[p+0xa2]<<8;Unp->EndAdr++;
                /* another version, same "bug", real start is 2 bytes off */
                Unp->fStrBf=0x4c;
                Unp->StrAdC=2;
                PrintInfo(Unp,_I_DSCPK2);
                Unp->IdFlag=1;return;
            }
        }
    }
}
