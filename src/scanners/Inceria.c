/* Inceria Packer */
#include "../unp64.h"
void Scn_Inceria(unpstr *Unp)
{
    unsigned char *mem;
    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x826)==0x6FBD00A2) &&
           (*(unsigned int*)(mem+0x82a)==0x05009D08) &&
           (*(unsigned int*)(mem+0x836)==0xFB8400A0) &&
           (*(unsigned int*)(mem+0x886)==0xD0BFC905) )
        {
            Unp->EndAdr=0x2d;
            Unp->DepAdr=0x500;
            Unp->Forced=0x826; // 0x815 is useless code to clear screen
            Unp->RetAdr=mem[0x8b1]|mem[0x8b2]<<8;
            if(*(unsigned int*)(mem+0x8b0)==0x4CA65920)
            {
                mem[0x8b0]=0x2c;
                Unp->RetAdr=mem[0x8b4]|mem[0x8b5]<<8;
            }
            Unp->StrMem=mem[0x865]|mem[0x869]<<8;
            PrintInfo(Unp, _I_INCERIAPK);
            if(Unp->DebugP)
                printmsg(mem,0x8fd,39);
            Unp->IdFlag=1;return;
        }
    }
}
