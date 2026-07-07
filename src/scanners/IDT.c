
#include "../unp64.h"
void Scn_IDT(unpstr *Unp)
{
    unsigned char *mem;
    int p;
    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    /* Idiots packer 1.0 */
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x80b)==0x847800A0) &&
            (*(unsigned short int*)(mem+0x80f)==0xb901) &&
            (*(unsigned int*)(mem+0x813)==0xC8FF4A99) &&
            (*(unsigned int*)(mem+0x825)==0x00064CEA) )
        {
            p=mem[0x811]|mem[0x812]<<8;p+=0xb6;
            if( (mem[p]==0x2f) &&
                (*(unsigned int*)(mem+p+0x0a)==0x049118F0) &&
                (*(unsigned int*)(mem+p+0x45)==0xF0BED003) )
            {
                Unp->Forced=0x80d;
                Unp->DepAdr=0x006;
                Unp->RetAdr=mem[p+0x22]|mem[p+0x23]<<8;
                Unp->fEndAf=0x04;
                Unp->StrMem=mem[p+0x4]|mem[p+0x5]<<8;
                PrintInfo(Unp,_I_IDT10);
                Unp->IdFlag=1;return;
            }
        }
    }
    /* Idiots packer 2.1 */
    if( Unp->DepAdr==0 )
    {
        if(((*(unsigned int*)(mem+0x80e)&0x00ffffff)==0x00BD0186) &&
            (*(unsigned int*)(mem+0x816)            ==0xCEF7D0E8) &&
           ((*(unsigned int*)(mem+0x828)&0x00ffffff)==0x0000014c) )
        {
            p=mem[0x811]|mem[0x812]<<8;
            Unp->Forced=0x80b;
            Unp->DepAdr=0x1;
            Unp->EndAdr=0x18;
            Unp->StrMem=mem[p+0xe6]|mem[p+0xe7]<<8;
            Unp->RetAdr=mem[p+0xfe]|mem[p+0xff]<<8;
            PrintInfo(Unp,_I_IDTFX21);
            Unp->IdFlag=1;return;
        }
    }
    /* Idiots packer 2.0 */
    if( Unp->DepAdr==0 )
    {
        if(((*(unsigned int*)(mem+0x80e)&0x00ffffff)==0x00BD0186) &&
            (*(unsigned int*)(mem+0x816)            ==0xCEF7D0E8) &&
           ((*(unsigned int*)(mem+0x828)&0x00ffffff)==0x0000024c) )
        {
            p=mem[0x811]|mem[0x812]<<8;
            Unp->Forced=0x80b;
            Unp->DepAdr=0x2;
            Unp->EndAdr=0x19;
            Unp->StrMem=mem[p+0xe6]|mem[p+0xe7]<<8;
            Unp->RetAdr=mem[p+0xfe]|mem[p+0xff]<<8;
            PrintInfo(Unp,_I_IDTFX20);
            Unp->IdFlag=1;return;
        }
    }
    /* Gentlemen packer 2.0 */
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x80b)==0x847800A0) &&
           (*(unsigned int*)(mem+0x80f)==0x85FFA901) &&
           (*(unsigned int*)(mem+0x81e)==0xAD00328D) &&
           ((*(unsigned int*)(mem+0x844)&0x00ffffff)==0x0000014c) )
        {
            Unp->Forced=0x80b;
            Unp->DepAdr=0x1;
            Unp->EndAdr=0x18;
            p=Unp->info->end-3;
            if(mem[p]==0x4c && mem[p-0x18]==0x8d)
            {
                Unp->RetAdr=mem[p+1]|mem[p+2]<<8;
                Unp->StrMem=mem[p-0x17]|mem[p-0x16]<<8;
            }
            PrintInfo(Unp,_I_GNTFX20);
            Unp->IdFlag=1;return;
        }
    }
    /* Gentlemen Stat Packer */
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x80b)==0x847800A0) &&
           (*(unsigned int*)(mem+0x80f)==0x9AFFA201) &&
           (*(unsigned int*)(mem+0x81e)==0xC602D02D) &&
           (*(unsigned int*)(mem+0x8d4)==0x01204CB0) )
        {
            Unp->Forced=0x80b;
            Unp->DepAdr=0x100;
            Unp->EndAdr=0x2d;
            Unp->RetAdr=mem[0x8ed]|mem[0x8ee]<<8;
            Unp->StrMem=mem[0x84d]|mem[0x851]<<8;
            PrintInfo(Unp,_I_GNTSTATP);
            Unp->IdFlag=1;return;
        }
    }
}
