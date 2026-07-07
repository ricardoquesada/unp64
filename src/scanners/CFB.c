/* CFB coder */
#include "../unp64.h"
void Scn_CFB(unpstr *Unp)
{
    unsigned char *mem;

    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x83b)==0x48B900A0) &&
           ((*(unsigned int*)(mem+0x83F)&0x00ffffff)==0x00FF9908) &&
            (*(unsigned int*)(mem+0x861)==0x49FBB1F6)
          )
        {
            Unp->Forced=0x83b;
            Unp->DepAdr=mem[0x847]|mem[0x848]<<8;
            Unp->StrMem=mem[0x857]|mem[0x859]<<8;
            Unp->EndAdr=mem[0x877]|mem[0x879]<<8;
            Unp->RetAdr=mem[0x883]|mem[0x884]<<8;
            if(*(unsigned int*)(mem+0x882)==0x4CA65920)
            {
                mem[0x882]=0x2c;
                Unp->RetAdr=mem[0x886]|mem[0x887]<<8;
            }
            PrintInfo(Unp,_I_CFBCOD1);
            Unp->IdFlag=1;return;
        }
    }
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x81d)==0x758DA4A9) &&
            (*(unsigned int*)(mem+0x83F)==0xD0C4E0E8) &&
            (*(unsigned int*)(mem+0x843)==0x03C84CF5)
          )
        {
            Unp->Forced=0x81d;
            Unp->DepAdr=0x3c8;
            Unp->EndAdr=0x2d;
            PrintInfo(Unp,_I_CFBCOD2);
            Unp->IdFlag=1;return;
        }
    }
}
