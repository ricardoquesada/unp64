/* TSB pack */
#include "../unp64.h"
void Scn_TSB(unpstr *Unp)
{
    unsigned char *mem;

    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x810)==0xB9A0A078) &&
            (*(unsigned int*)(mem+0x814)==0xF799081E) &&
            (*(unsigned int*)(mem+0x818)==0xF7D08800) &&
           ((*(unsigned int*)(mem+0x81c)&0x00ffffff)==0x0001064C) &&
            (*(unsigned int*)(mem+0x882)==0x20012E4C) )
        {
            Unp->DepAdr=0x106;
            Unp->Forced=0x810;
            Unp->StrMem=mem[0x856]|mem[0x857]<<8;
            Unp->RetAdr=mem[0x86f]|mem[0x870]<<8;
            Unp->fEndAf=0x12f;
            Unp->EndAdC=0xffff;
            PrintInfo(Unp,_I_TSBP3);
            Unp->IdFlag=1;return;
        }
        if( (*(unsigned int*)(mem+0x810)==0x1DB970A0) &&
            (*(unsigned int*)(mem+0x814)==0x00FF9908) &&
            (*(unsigned int*)(mem+0x818)==0x4CF7D088) &&
            (*(unsigned int*)(mem+0x81c)==0xA9780100) &&
            (*(unsigned int*)(mem+0x850)==0x4BAD015C) )
        {
            Unp->DepAdr=0x100;
            Unp->Forced=0x810;
            Unp->StrMem=mem[0x87b]|mem[0x87c]<<8;
            Unp->RetAdr=mem[0x865]|mem[0x866]<<8;
            Unp->fEndAf=0x15d;
            Unp->EndAdC=0xffff;
            PrintInfo(Unp,_I_TSBP1);
            Unp->IdFlag=1;return;
        }
        if( (*(unsigned int*)(mem+0x810)==0x1DB9A0A0) &&
            (*(unsigned int*)(mem+0x814)==0x00F69908) &&
            (*(unsigned int*)(mem+0x818)==0x4CF7D088) &&
            (*(unsigned int*)(mem+0x880)==0x3A4C00F7) &&
            (*(unsigned int*)(mem+0x884)==0xD003A201) )
        {
            Unp->DepAdr=0x108;
            Unp->Forced=0x810;
            Unp->StrMem=mem[0x862]|mem[0x863]<<8;
            Unp->RetAdr=mem[0x879]|mem[0x87a]<<8;
            Unp->fEndAf=0x13b;
            Unp->EndAdC=0xffff;
            PrintInfo(Unp,_I_TSBP21);
            Unp->IdFlag=1;return;
        }
    }
}
