/* RFO Coder */
#include "../unp64.h"
void Scn_RFOCoder(unpstr *Unp)
{
    unsigned char *mem;

    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x815)==0x0811AF78) &&
           (*(unsigned int*)(mem+0x822)==0x0831AFFC) &&
           (*(unsigned int*)(mem+0x852)==0x01658F8A) &&
           (*(unsigned int*)(mem+0x873)==0x9301004C) )
        {
            Unp->DepAdr=0x100;
            Unp->Forced=0x815;
            Unp->RetAdr=((mem[0x8d5]-0x73)&0xff)|(((mem[0x8d6]-0x73)&0xff)<<8);
            Unp->StrMem=mem[0x86c]|(mem[0x870]<<8);
            Unp->EndAdr=0xfd;
            PrintInfo(Unp,_I_RFOCOD);
            Unp->IdFlag=1;return;
        }
    }
}
