/* Paradroid Packer */
#include "../unp64.h"
void Scn_Paradroid(unpstr *Unp)
{
    unsigned char *mem;
    int p,q;
    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        q=Unp->info->start;
        for(p=q;p<q+0x10;p++)
        {
            if((*(unsigned int*)(mem+p+0x00)==0x847800A0) &&
               (*(unsigned int*)(mem+p+0x07)==0x00FB9908) &&
               (*(unsigned int*)(mem+p+0x29)==0x85014420) &&
               (*(unsigned int*)(mem+p+0x65)==0x011B4C01) )
            {
                Unp->DepAdr=0x100;
                break;
            }
        }
        if(Unp->DepAdr)
        {
            Unp->Forced=p;
            Unp->RetAdr=mem[p+0x7e]|mem[p+0x7f]<<8;
            Unp->EndAdr=0xf9;
            Unp->StrMem=mem[p+0x87]|mem[p+0x88]<<8;
            PrintInfo(Unp,_I_PARADROID1);
            Unp->IdFlag=1;return;
        }
    }
    p=0x080b;
    if((*(unsigned short int*)(mem+p+0x00)==0x00A2) &&
       (*(unsigned int*)(mem+p+0x19)==0x0830B960) &&
       (*(unsigned int*)(mem+p+0x1d)==0x8800F599) &&
       (*(unsigned int*)(mem+p+0x35)==0xF7C51BF0) )
    {
        Unp->DepAdr=0x100;
        Unp->Forced=p;
        Unp->RetAdr=mem[p+0x83]|mem[p+0x84]<<8;
        Unp->EndAdr=0xfe;
        Unp->StrMem=mem[p+0x2e]|mem[p+0x2f]<<8;
        PrintInfo(Unp,_I_PARADROID2);
        Unp->IdFlag=1;return;
    }
    p=0x0812;
    if((*(unsigned int*)(mem+p+0x00)==0x78084F20) &&
       (*(unsigned int*)(mem+p+0x0b)==0x9D0893BD) &&
       (*(unsigned int*)(mem+p+0x8c)==0xC8AA2BF0) &&
       (*(unsigned int*)(mem+p+0xec)==0x93D0AFE6) )
    {
        Unp->DepAdr=mem[p+0x3b]|mem[p+0x3c]<<8;
        Unp->DepAdr+=0x47;
        Unp->Forced=p;
        Unp->RetAdr=mem[p+0xfe]|mem[p+0xff]<<8;
        Unp->fStrBf=0xae;
        Unp->EndAdr=0xae;
        PrintInfo(Unp,_I_PARADROIDL);
        if(Unp->DebugP)
            printmsg(mem,p+0x59,40);
        Unp->IdFlag=1;return;
    }
}
