/* cadgers pack */
#include "../unp64.h"
void Scn_CadgersPacker(unpstr *Unp)
{
    unsigned char *mem;

    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x80b)==0xE67800A0) &&
            (*(unsigned int*)(mem+0x80f)==0x081CB901) &&
            (*(unsigned int*)(mem+0x813)==0xC800E999) &&
            (*(unsigned int*)(mem+0x817)==0x014CF710) )
        {
            Unp->Forced=0x80d;
            Unp->DepAdr=0x101;
            Unp->RetAdr=mem[0x864]|mem[0x865]<<8;
            Unp->EndAdr=mem[0x852]|mem[0x853]<<8;
            Unp->EndAdr+=0x0100;
            Unp->fStrAf=0x11f;
            Unp->StrAdC=EA_ADDFF|EA_USE_Y|0xffff;
            PrintInfo(Unp,_I_CADGERS);
            Unp->IdFlag=1;return;
        }
    }
}
