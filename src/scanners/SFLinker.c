/* SUPER FILELINKER BY BOWIE */
#include "../unp64.h"
void Scn_SFLinker(unpstr *Unp)
{
    unsigned char *mem;

    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x828)==0x8634A278) &&
           (*(unsigned int*)(mem+0x831)==0xAF84AE86) &&
           (*(unsigned int*)(mem+0x863)==0xA501664C) &&
           (*(unsigned int*)(mem+0x8bd)==0x01664CE4) )
        {
            Unp->DepAdr=0x166;
            if(Unp->info->run == -1)
                Unp->Forced=0x828;
            Unp->StrMem=mem[0x900]|mem[0x901]<<8;
            Unp->RetAdr=mem[0x882]|mem[0x883]<<8;
            Unp->EndAdr=mem[0x86f]|mem[0x871]<<8;
            PrintInfo(Unp,_I_SFLINK);
            Unp->IdFlag=1;return;
        }
    }
}
