/* ILS Coder */
#include "../unp64.h"
void Scn_ILSCoder(unpstr *Unp)
{
    unsigned char *mem;

    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr == 0 )
    {
        if((*(unsigned int*)(mem+0x80b)==0xA27800A0) &&
           (*(unsigned int*)(mem+0x81f)==0x01004CF1) &&
           (*(unsigned int*)(mem+0x847)==0x15493F29) &&
           (*(unsigned int*)(mem+0x85a)==0x005D5D5D) )
        {
            /* current screen location after loading and run */
            mem[0xd1]=0xe0;
            mem[0xd2]=0x05;
            mem[0x5b8]='R'&0x1f;
            mem[0x5b9]='U'&0x1f;
            mem[0x5ba]='N'&0x1f;
            Unp->DepAdr=0x100;
            Unp->Forced=0x80b;
            Unp->StrMem=mem[0x823]|mem[0x824]<<8;
            Unp->RetAdr=mem[0x883]|mem[0x884]<<8;
            Unp->EndAdr=Unp->info->end-0x87;
            PrintInfo(Unp,_I_ILSCOD);
            Unp->IdFlag=1;return;
        }
    }
}
