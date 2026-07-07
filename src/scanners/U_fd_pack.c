/* unknown $00fd packer
   found for example in The Spirit Preview +2M/ONS
*/
#include "../unp64.h"
void Scn_U_fd_pack(unpstr *Unp)
{
    unsigned char *mem;

    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x80d)==0x8534A978) &&
            (*(unsigned int*)(mem+0x811)==0xBD00A201) &&
            (*(unsigned int*)(mem+0x815)==0xFD9D0895) &&
            (*(unsigned int*)(mem+0x90E)==0x1801124C) &&
            (*(unsigned int*)(mem+0x940)==0x6001B0AC) )
        {
            Unp->Forced=0x80d;
            Unp->DepAdr=0xfd;
            Unp->RetAdr=mem[0x89e]|mem[0x89f]<<8;
            Unp->StrMem=mem[0x949]|mem[0x94a]<<8;
            Unp->EndAdr=mem[0x94b]|mem[0x94c]<<8;
            PrintInfo(Unp,_I_U_FD);
            Unp->IdFlag=1;return;
        }
    }
}
