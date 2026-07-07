/* megacrunch */
#include "../unp64.h"
void Scn_MegaCruncher(unpstr *Unp)
{
    unsigned char *mem;
    int p;
    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x80d)==0x20BD6CA2) &&
           (*(unsigned int*)(mem+0x81d)==0xA204004C) &&
           (*(unsigned int*)(mem+0x852)==0x20045B20) &&
           (*(unsigned int*)(mem+0x856)==0x264C0454) )
        {
            Unp->DepAdr=0x400;
            Unp->Forced=0x80d;
            Unp->RetAdr=mem[0x888]|mem[0x889]<<8;
            Unp->EndAdr=0x2d;
            Unp->StrMem=mem[0x83f]|mem[0x843]<<8;
            PrintInfo(Unp,_I_MEGCRBD);
            Unp->IdFlag=1;return;
        }
    }
    /* Megacrunch 2.3/SCW */
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x818)==0x789AFDA2) &&
           (*(unsigned int*)(mem+0x83c)==0xFDC604D0) &&
           (*(unsigned int*)(mem+0x840)==0xB18823C6) &&
          ((*(unsigned int*)(mem+0x850)&0xfff0ffff)==0x01604C22) )
        {
            p=mem[0x852];
            Unp->DepAdr=mem[0x852]|mem[0x853]<<8;
            Unp->Forced=0x818;
            if (p==0x62)
               Unp->RetAdr=mem[0x91e]|mem[0x91f]<<8;
            else if (p==0x6d)
               Unp->RetAdr=mem[0x929]|mem[0x929]<<8;
            Unp->EndAdr=0x2d;
            Unp->StrMem=mem[0x856]|mem[0x857]<<8;
            PrintInfo(Unp,_I_MEGCR23);
            Unp->IdFlag=1;return;
        }
    }
}
