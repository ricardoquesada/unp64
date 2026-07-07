/* Turbo packer 1.0 */
#include "../unp64.h"
void Scn_TurboPacker(unpstr *Unp)
{
    unsigned char *mem;

    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x80b)==0xe67800a2) &&
            (*(unsigned int*)(mem+0x80f)==0xBDBACA01) &&
            (*(unsigned int*)(mem+0x813)==0xFB9D083D) &&
            (*(unsigned int*)(mem+0x8a1)==0xE6FE9160) )
        {
            Unp->DepAdr=0x100;
            Unp->Forced=0x80b;
            Unp->StrMem=mem[0x840]|mem[0x841]<<8;
            Unp->EndAdr=0xfe;
            Unp->RetAdr=mem[0x855]|mem[0x856]<<8;
            PrintInfo(Unp,_I_TURBOP);
            Unp->IdFlag=1;return;
        }
    }
}
