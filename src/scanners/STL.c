/* Starline protector? tries to format drive 8 if $9d != 0 after depack */
#include "../unp64.h"
void Scn_STL(unpstr *Unp)
{
    unsigned char *mem;
    int p;
    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x80d)==0x19B900A0) &&
           (*(unsigned int*)(mem+0x811)==0x99FF4908) &&
           (*(unsigned int*)(mem+0x815)==0xD0C80819) &&
           (*(unsigned int*)(mem+0x899)==0xD27A517A) )
        {
            p=mem[0x813];
            Unp->Forced=0x80d;
            mem[0x88d]=0xa9^p; /* always 0, never activate formatter */
            mem[0x88e]=0x00^p;
            Unp->DepAdr=(mem[0x82c]^p)|(mem[0x82d]^p)<<8;
            Unp->StrMem=(mem[0x85d]^p)|(mem[0x859]^p)<<8;
            Unp->EndAdr=0x2d;
            Unp->RetAdr=(mem[0x8a9]^p)|(mem[0x8aa]^p)<<8;
            PrintInfo(Unp,_I_STLPROT);
            Unp->IdFlag=1;return;

        }
    }
}
