/* Warlock/Panic Packer */
#include "../unp64.h"
void Scn_Warlock(unpstr *Unp)
{
    unsigned char *mem;

    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x828)==0x45BDB2A2) &&
            (*(unsigned int*)(mem+0x82c)==0x03339D08) &&
            (*(unsigned int*)(mem+0x830)==0xA9F7D0CA) &&
            (*(unsigned int*)(mem+0x89d)==0x037C4C48) )
        {
            Unp->DepAdr=0x334;
            Unp->Forced=0x828;
            Unp->fStrAf=0x3cb;
            Unp->StrAdC=EA_USE_X|0x100;
            Unp->EndAdr=mem[0x8dd]|mem[0x8de]<<8;Unp->EndAdr++;
            Unp->RetAdr=mem[0x8a9]|mem[0x8aa]<<8;
            PrintInfo(Unp,_I_WARLOCK);
            Unp->IdFlag=1;return;
        }
    }
}
