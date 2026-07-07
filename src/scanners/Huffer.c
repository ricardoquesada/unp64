/* Hufffer/FLT */
#include "../unp64.h"
void Scn_Huffer(unpstr *Unp)
{
    unsigned char *mem;

    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x80f)==0xA97800A0) &&
           (*(unsigned int*)(mem+0x817)==0xF7990849) &&
           (*(unsigned int*)(mem+0x844)==0xFC4CD0D0) &&
           (*(unsigned int*)(mem+0x875)==0xBCFd00BD) )
        {
            Unp->DepAdr=0xfc;
            Unp->Forced=0x80f;
            Unp->RetAdr=mem[0x8a0]|mem[0x8a1]<<8;
            Unp->fStrAf=0xf8;
            Unp->EndAdr=mem[0x84a]|mem[0x84b]<<8;Unp->EndAdr++;
            PrintInfo(Unp,_I_HUFFER);
            Unp->IdFlag=1;return;
        }
        if((*(unsigned int*)(mem+0x810)==0xA97800A0) &&
           (*(unsigned int*)(mem+0x818)==0xF799084A) &&
           (*(unsigned int*)(mem+0x845)==0xFC4CD0D0) &&
           (*(unsigned int*)(mem+0x887)==0xBCFC00BD) )
        {
            Unp->DepAdr=0xfc;
            Unp->Forced=0x810;
            Unp->RetAdr=mem[0x8a8]|mem[0x8a9]<<8;
            Unp->fStrAf=0xf8;
            Unp->EndAdr=mem[0x84b]|mem[0x84c]<<8;Unp->EndAdr++;
            PrintInfo(Unp,_I_HUFFERQC);
            Unp->IdFlag=1;return;
        }
    }
}
