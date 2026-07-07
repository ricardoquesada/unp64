/* Chris Noack mega-bytepacker */
#include "../unp64.h"
void Scn_C_Noack(unpstr *Unp)
{
    unsigned char *mem;

    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x81c)==0x29B9A4A0) &&
           (*(unsigned int*)(mem+0x824)==0x4CF7D088) &&
           (*(unsigned int*)(mem+0x88c)==0xC4850069) &&
           (*(unsigned int*)(mem+0x8c0)==0xC4E68C90) )
        {
            Unp->DepAdr=mem[0x828]|mem[0x829]<<8;
            if(Unp->info->run == -1)
                 Unp->Forced=0x81c;
            Unp->RetAdr=mem[0x8cc]|mem[0x8cd]<<8;
            Unp->StrMem=mem[0x8d0]|mem[0x8d1]<<8;
            Unp->EndAdr=0xae;
            PrintInfo(Unp,_I_CNOACK);
            Unp->IdFlag=1;return;
        }
    }
    /* lxt hacks */
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x814)==0x21B9ACA0) &&
           (*(unsigned int*)(mem+0x81c)==0x4CF7D088) &&
           (*(unsigned int*)(mem+0x88c)==0xC4850069) &&
           (*(unsigned int*)(mem+0x8c0)==0xC4E68C90) )
        {
            Unp->DepAdr=mem[0x820]|mem[0x821]<<8;
            if(Unp->info->run == -1)
                 Unp->Forced=0x814;
            Unp->RetAdr=mem[0x8cc]|mem[0x8cd]<<8;
            Unp->StrMem=mem[0x8d0]|mem[0x8d1]<<8;
            Unp->EndAdr=0xae;
            PrintInfo(Unp,_I_CNOACKLXT);
            Unp->IdFlag=1;return;
        }
    }
}
