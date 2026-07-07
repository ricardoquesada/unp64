/* Pride packer */
#include "../unp64.h"
void Scn_Pride(unpstr *Unp)
{
    unsigned char *mem;

    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x80b)==0xB97800A0) &&
           (*(unsigned int*)(mem+0x80f)==0xE999081A) &&
           (*(unsigned int*)(mem+0x817)==0xA501014C) &&
           (*(unsigned int*)(mem+0x83b)==0xE920F7D0) )
        {
            Unp->DepAdr=0x101;
            Unp->Forced=0x80b;
            Unp->RetAdr=mem[0x85e]|mem[0x85f]<<8;
            Unp->fStrAf=0x11f;
            Unp->StrAdC=EA_ADDFF|EA_USE_Y|0xffff;
            Unp->EndAdr=mem[0x850]|mem[0x851]<<8;Unp->EndAdr+=0x100;
            PrintInfo(Unp,_I_PRIDE);
            Unp->IdFlag=1;return;
        }
    }
}
