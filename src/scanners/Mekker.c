/* Mekker  */
#include "../unp64.h"
void Scn_Mekker(unpstr *Unp)
{
    unsigned char *mem;

    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x801)==0x847800A0) &&
            (*(unsigned int*)(mem+0x811)==0x080BEE08) &&
            (*(unsigned int*)(mem+0x822)==0x01124CF7) &&
            (*(unsigned int*)(mem+0x8a2)==0x010920FB) )
        {
            Unp->DepAdr=0x112;
            Unp->Forced=0x801;
            Unp->StrMem=mem[0x828]|mem[0x829]<<8;
            Unp->EndAdr=0xfe;
            Unp->RetAdr=mem[0x866]|mem[0x867]<<8;
            PrintInfo(Unp,_I_MEKKER);
            Unp->IdFlag=1;return;
        }
    }
}
