/* LST Coder(s) */
#include "../unp64.h"
void Scn_LSTcoder(unpstr *Unp)
{
    unsigned char *mem;

    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x840)==0xA24C0478) &&
           (*(unsigned int*)(mem+0x844)==0x055D8A38) &&
           (*(unsigned int*)(mem+0x850)==0xD22093A9) &&
           (*(unsigned int*)(mem+0x8b0)==0xAFA52D85) )
        {
            Unp->DepAdr=0x100;
            Unp->Forced=0x840;
            Unp->RetAdr=0xa7ae;
            Unp->EndAdr=0x2d;
            Unp->StrMem=0x0801;
            PrintInfo(Unp,_I_LSTCOD1);
            Unp->IdFlag=1;return;
        }
    }
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x811)==0x0810AF78) &&
           (*(unsigned int*)(mem+0x821)==0x081CCF4C) &&
           (*(unsigned int*)(mem+0x8a1)==0x78489848) &&
           (*(unsigned int*)(mem+0x8a5)==0x02E602A4) )
        {
            Unp->DepAdr=0x220;
            Unp->Forced=0x811;
            Unp->RetAdr=0xa7ae;
            Unp->EndAdr=0x2d;
            Unp->StrMem=0x0801;
            /* patch code to execute IRQ unpack sequentially */
            mem[0x83e]=0x4C;
            mem[0x83f]=0xA1;
            mem[0x840]=0x08;
            mem[0x8b7]=0xA2;
            mem[0x8b8]=0xF8;
            mem[0x8b9]=0x9A;
            mem[0x8ba]=0x4C;
            mem[0x8bb]=0x47;
            mem[0x8bc]=0xE1;
            PrintInfo(Unp,_I_LSTCOD2);
            Unp->IdFlag=1;return;
        }
    }
}
