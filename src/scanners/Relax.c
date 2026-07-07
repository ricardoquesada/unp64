/* Relax Packers */
#include "../unp64.h"
void Scn_Relax(unpstr *Unp)
{
    unsigned char *mem;

    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x816)==0x847800A0) &&
           (*(unsigned int*)(mem+0x81a)==0xA02EC601) &&
           (*(unsigned int*)(mem+0x81e)==0x992DB100) &&
           (*(unsigned int*)(mem+0x8c7)==0x1BF073A5) )
        {
            Unp->DepAdr=0x002;
            Unp->Forced=0x816;
            Unp->StrMem=mem[0x85a]|mem[0x85b]<<8;Unp->StrMem++;
            Unp->RetAdr=mem[0x8fc]|mem[0x8fd]<<8;
            Unp->EndAdr=mem[0x8c5]|mem[0x8c6]<<8;
            PrintInfo(Unp,_I_RLX3B);
            Unp->IdFlag=1;return;
        }
    }
    if( Unp->DepAdr==0 )
    {
        if(mem[0x816]==0x78 &&
           (*(unsigned int*)(mem+0x81b)==0x2E842D86) &&
           (*(unsigned int*)(mem+0x823)==0xB5B95BA0) &&
           (*(unsigned int*)(mem+0x827)==0x01409900) &&
           (*(unsigned int*)(mem+0x896)==0x990140B9) )
        {
            Unp->DepAdr=0x0b5;
            Unp->Forced=0x816;
            Unp->StrMem=mem[0x87c]|mem[0x87d]<<8;
            Unp->RetAdr=mem[0x8a5]|mem[0x8a6]<<8;
            mem[0x899]=0x2c; /* patch sta $00b5,y , would clear useful vars */
            Unp->EndAdr=0xe6;
            PrintInfo(Unp,_I_RLXP2);
            Unp->IdFlag=1;return;
        }
    }
}
