/* BN 1872 charpacker, used in his intromaker */
#include "../unp64.h"
void Scn_BN1872(unpstr *Unp)
{
    unsigned char *mem;

    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x814)==0x849AFFA2) &&
            (*(unsigned int*)(mem+0x818)==0x0840B901) &&
            (*(unsigned int*)(mem+0x81c)==0xC800FB99) &&
            (*(unsigned int*)(mem+0x83c)==0x01074C2E) )
        {
            Unp->Forced=0x814;
            Unp->DepAdr=0x107;
            Unp->RetAdr=mem[0x895]|mem[0x896]<<8;
            Unp->EndAdr=0x2d;
            Unp->StrMem=mem[0x836]|mem[0x83a]<<8;
            PrintInfo(Unp,_I_BN1872PK);
            Unp->IdFlag=1;return;
        }
    }
}
