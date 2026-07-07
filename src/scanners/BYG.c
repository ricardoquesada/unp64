/* BYG compactor v1 1988 */
#include "../unp64.h"
void Scn_BYG(unpstr *Unp)
{
    unsigned char *mem;

    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x817)==0x9FB901E6) &&
            (*(unsigned int*)(mem+0x81b)==0x00F79908) &&
            (*(unsigned int*)(mem+0x867)==0x2001244C) &&
            (*(unsigned int*)(mem+0x8db)==0xD000FA20)
          )
        {
            Unp->Forced=0x817;
            Unp->DepAdr=0x124;
            Unp->StrMem=mem[0x89b]|mem[0x89c]<<8;
            Unp->RetAdr=mem[0x8e6]|mem[0x8e7]<<8;
            Unp->EndAdr=0x2d;
            PrintInfo(Unp,_I_BYG1);
            Unp->IdFlag=1;return;
        }
    }
    /* BYG compactor v2 1989 */
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x828)==0x07A20184) &&
            (*(unsigned int*)(mem+0x82c)==0x9508CDBD) &&
            (*(unsigned int*)(mem+0x89c)==0x01274CF7)
          )
        {
            Unp->Forced=0x828;
            Unp->DepAdr=0x127;
            Unp->StrMem=mem[0x8d1]|mem[0x8d2]<<8;
            Unp->RetAdr=mem[0x91f]|mem[0x920]<<8;
            Unp->EndAdr=0x2d;
            PrintInfo(Unp,_I_BYG2);
            if(Unp->DebugP)
                printmsg(mem,0x854,40);
            Unp->IdFlag=1;return;
        }
    }
    /* ByteBaby, reduced unpacker hack by Joe/Steel */
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x80b)==0x8C7800A0) &&
            (*(unsigned int*)(mem+0x814)==0x07A20184) &&
            (*(unsigned int*)(mem+0x818)==0x950891BD) &&
            (*(unsigned int*)(mem+0x860)==0x01274CF7)
          )
        {
            Unp->Forced=0x80b;
            Unp->DepAdr=0x127;
            Unp->StrMem=mem[0x895]|mem[0x896]<<8;
            Unp->RetAdr=mem[0x8e8]|mem[0x8e9]<<8;
            Unp->EndAdr=0x2d;
            PrintInfo(Unp,_I_BYGBB);
            Unp->IdFlag=1;return;
        }
    }
}
