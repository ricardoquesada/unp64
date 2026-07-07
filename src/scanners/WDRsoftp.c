/* WDR softprotector!1 */
#include "../unp64.h"
void Scn_WDRsoftp(unpstr *Unp)
{
    unsigned char *mem;

    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x821)==0x208F00A9) &&
           (*(unsigned int*)(mem+0x829)==0x288DEAA9) &&
           (*(unsigned int*)(mem+0x82f)==0x40D00952) )
        {
            Unp->DepAdr=mem[0x975]|mem[0x874]<<8;
            Unp->Forced=0x873;
            Unp->RetAdr=mem[0x9d7]|mem[0x9d8]<<8;
            Unp->EndAdr=Unp->info->end - 0x01ff;
            PrintInfo(Unp,_I_WDRPROT);
            Unp->IdFlag=1;return;
        }
        if((*(unsigned int*)(mem+0x80d)==0x038604A2) &&
           (*(unsigned int*)(mem+0x821)==0x04CEFFD2) &&
           (*(unsigned int*)(mem+0x831)==0xEEFC8508) )
        {
            Unp->DepAdr=0x0100;
            Unp->Forced=0x080d;
            Unp->RetAdr=0xa659;
            Unp->StrMem=0x0801;
            Unp->EndAdr=0x0801+(mem[0x853]|mem[0x859]<<8)-0xa00;
            PrintInfo(Unp,_I_WDRLAMEK);
            Unp->IdFlag=1;return;
        }
    }
}
