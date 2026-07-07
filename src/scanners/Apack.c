/* apack */
#include "../unp64.h"
void Scn_Apack(unpstr *Unp)
{
    unsigned char *mem;
    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x80b)==0xB97800A0) &&
           (*(unsigned int*)(mem+0x80f)==0x0099081C) &&
           (*(unsigned int*)(mem+0x813)==0xF7D0C801) &&
           (*(unsigned int*)(mem+0x817)==0x004C0184) )
        {
            Unp->DepAdr=0x100;
            Unp->Forced=0x80b;
            Unp->StrMem=mem[0x840]|mem[0x842]<<8;
            Unp->RetAdr=mem[0x850]|mem[0x851]<<8;
            Unp->EndAdr=0xfc;
            PrintInfo(Unp,_I_APACK);
            Unp->IdFlag=1;return;
        }
    }
}
