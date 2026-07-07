/* ScreenCrunch */
#include "../unp64.h"
void Scn_ScreenCrunch(unpstr *Unp)
{
    unsigned char *mem;

    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x810)==0x2BBDA0A2) &&
          ((*(unsigned int*)(mem+0x814)&0xf0ffffff)==0x003B9D08) &&
          ((*(unsigned int*)(mem+0x818)&0x00ffffff)==0x00F7D0CA) &&
           mem[0x8a2]==0x4c)
        {
            Unp->DepAdr=mem[0x82a]|mem[0x82b]<<8;
            Unp->Forced=0x810;
            Unp->RetAdr=mem[0x8a3]|mem[0x8a4]<<8;
            Unp->StrMem=mem[0x85b]|mem[0x85f]<<8;
            Unp->EndAdr=0xae;
            PrintInfo(Unp,_I_SCRCR4);
            Unp->IdFlag=1;return;
        }
        if((*(unsigned int*)(mem+0x812)==0x20BD80A2) &&
          ((*(unsigned int*)(mem+0x816)&0xf0ffffff)==0x003C9D08) &&
           (*(unsigned int*)(mem+0x81a)==0x4CF710CA) &&
           mem[0x88b]==0x4c)
        {
            Unp->DepAdr=mem[0x81e]|mem[0x81f]<<8;
            Unp->Forced=0x812;
            Unp->RetAdr=mem[0x88c]|mem[0x88d]<<8;
            Unp->StrMem=mem[0x84c]|mem[0x850]<<8;
            Unp->EndAdr=0xae;
            PrintInfo(Unp,_I_SCRCR6);
            Unp->IdFlag=1;return;
        }
        if((*(unsigned int*)(mem+0x80f)==0x9D0824BD) &&
           (*(unsigned int*)(mem+0x813)==0xE0E8033C) &&
           (*(unsigned int*)(mem+0x846)==0xA008494C) &&
           (*(unsigned int*)(mem+0x870)==0xACC6ADC6) &&
           (*(unsigned int*)(mem+0x874)==0x02D0AEA5) )
        {
            Unp->DepAdr=0x100;
            Unp->Forced=0x80f;
            Unp->RetAdr=mem[0x8cd]|mem[0x8ce]<<8;
            Unp->StrMem=mem[0x88d]|mem[0x891]<<8;
            Unp->EndAdr=0xae;
            PrintInfo(Unp,_I_SCRCRFCG);
            Unp->IdFlag=1;return;
        }

    }
}
