/* Anticom */
#include "../unp64.h"
void Scn_Anticom(unpstr *Unp)
{
    unsigned char *mem;

    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x828)==0x3DBD84A2) &&
           (*(unsigned int*)(mem+0x82c)==0x03349D08) &&
           (*(unsigned int*)(mem+0x880)==0x20039D20) &&
           (*(unsigned int*)(mem+0x890)==0x03A420FF) )
        {
            Unp->DepAdr=0x334;
            Unp->Forced=0x828;
            Unp->RetAdr=mem[0x8c3]|mem[0x8c4]<<8;
            Unp->StrMem=mem[0x8c1]|mem[0x8c2]<<8;
            Unp->EndAdr=0xfd;
            PrintInfo(Unp,_I_ANTICOM);
            Unp->IdFlag=1;return;
        }
    }
}
