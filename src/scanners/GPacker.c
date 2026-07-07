/*G-Packer by Graham/Oxyron */
#include "../unp64.h"
void Scn_GPacker(unpstr *Unp)
{
    unsigned char *mem;
    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        /* sysless */
        if((*(unsigned int*)(mem+0x801)==0x8534A978) &&
           (*(unsigned int*)(mem+0x811)==0xF5D0FFC0) &&
           (*(unsigned int*)(mem+0x821)==0xFB99082B) &&
           (*(unsigned int*)(mem+0x831)==0x013B2000) )
        {
            Unp->DepAdr=0x100;
            Unp->Forced=0x801;
            Unp->StrMem=mem[0x82e]|mem[0x82f]<<8;
            Unp->RetAdr=mem[0x87a]|mem[0x87b]<<8;
            Unp->EndAdr=0xfe;
            PrintInfo(Unp,_I_GPACK);
            Unp->IdFlag=1;return;
        }
        /*sysline+text*/
        if((*(unsigned int*)(mem+0x80d)==0x08A045A9) &&
           (*(unsigned int*)(mem+0x82a)==0xF5D0FFC0) &&
           (*(unsigned int*)(mem+0x83a)==0xFB99086f) &&
           (*(unsigned int*)(mem+0x875)==0x013B2000) )
        {
            Unp->DepAdr=0x100;
            Unp->Forced=0x80d;
            Unp->StrMem=mem[0x872]|mem[0x873]<<8;
            Unp->RetAdr=mem[0x8be]|mem[0x8bf]<<8;
            Unp->EndAdr=0xfe;
            PrintInfo(Unp,_I_GPACK);
            if(Unp->DebugP)
                printmsg(mem,0x847,40);
            Unp->IdFlag=1;return;
        }
    }
}
