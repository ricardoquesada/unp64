/*MASCHINENSPRACHE-KOMPRESSOR*/
#include "../unp64.h"
void Scn_MaschSprache(unpstr *Unp)
{
    unsigned char *mem;
    int q;
    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        for(q=0x801;q<0x900;q++)
        {
            if( (*(unsigned int*)(mem+q+0x00)==0x018534A9) &&
                (*(unsigned int*)(mem+q+0x08)==0x00FA9D08) &&
                (*(unsigned int*)(mem+q+0x0c)==0x9AF710CA) &&
                (*(unsigned int*)(mem+q+0x1c)==0x4CAFE6F9) &&
                (*(unsigned int*)(mem+q+0x59)==0x015E2001) )
            {
                Unp->DepAdr=0x100;
                break;
            }
        }
        if(Unp->DepAdr)
        {
            Unp->Forced=q;
            Unp->RetAdr=mem[q+0x79]|mem[q+0x7a]<<8;
            Unp->EndAdr=mem[q+0x22]|mem[q+0x23]<<8;Unp->EndAdr++;
            Unp->fStrAf=0xfa;
            PrintInfo(Unp,_I_MASCHK);
            Unp->IdFlag=1;return;
        }
    }
}
