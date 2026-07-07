/* Frontpacker */
#include "../unp64.h"
void Scn_FrontPacker(unpstr *Unp)
{
    unsigned char *mem;

    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x82e)==0xBD5DA278) &&
            (*(unsigned int*)(mem+0x832)==0x009D086D) &&
            (*(unsigned int*)(mem+0x836)==0xF710CA01) &&
            (*(unsigned int*)(mem+0x882)==0xACB1AAC8)
          )
        {
            Unp->Forced=0x82e;
            Unp->DepAdr=0x100;
            Unp->StrMem=mem[0x86e]|mem[0x872]<<8;
            Unp->RetAdr=mem[0x8c6]|mem[0x8c7]<<8;
            Unp->EndAdr=0xae;
            PrintInfo(Unp,_I_FRONTPACK);
            if(Unp->DebugP)
                printmsg(mem,0x8cb,40);
            Unp->IdFlag=1;return;
        }
    }
}
