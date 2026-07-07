/* MSI cruncher, actually is a denser... */
#include "../unp64.h"
void Scn_MSI(unpstr *Unp)
{
    unsigned char *mem;
    int q,p;
    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x814)==0x8534A978) &&
            (*(unsigned int*)(mem+0x821)==0x04840385) &&
            (*(unsigned int*)(mem+0x890)==0xD0FCE6FC) &&
            (*(unsigned int*)(mem+0x8B0)==0xA501214C)   )
        {
            Unp->DepAdr=0x100;
            Unp->Forced=0x814;
            Unp->StrMem=mem[0x84a]|mem[0x84b]<<8;
            Unp->EndAdr=0xfc;
            Unp->RetAdr=mem[0x8c0]|mem[0x8c1]<<8;
            PrintInfo(Unp,_I_MSICR2);
            Unp->IdFlag=1;return;
        }
    }
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x80f)==0x847800A0) &&
            (*(unsigned int*)(mem+0x81f)==0x2EA5F8D0) &&
            (*(unsigned int*)(mem+0x82f)==0x015D4CF7) &&
            (*(unsigned int*)(mem+0x88f)==0xF0F5D088)  )
        {
            Unp->DepAdr=0x15d;
            Unp->Forced=0x80f;
            Unp->StrMem=mem[0x833]|mem[0x834]<<8;
            Unp->EndAdr=0xfc;
            Unp->RetAdr=mem[0x862]|mem[0x863]<<8;
            PrintInfo(Unp,_I_MSICR3);
            Unp->IdFlag=1;return;
        }
    }
    /* MSI(2071) and Sonic(2074) coder*/
    if( Unp->DepAdr==0 )
    {
        for(p=0x0817;p<0x81b;p++)
        if( mem[p]==0xaf &&
            (*(unsigned int*)(mem+p+0x002)==0xD0608F08) &&
            (*(unsigned int*)(mem+p+0x006)==0x38D0A18F) &&
            (*(unsigned int*)(mem+p+0x07c)==0x014DFF86) &&
            (*(unsigned int*)(mem+p+0x08c)==0xFA759D94) )
        {
            Unp->DepAdr=0x100;
            Unp->Forced=p;
            Unp->fStrBf=0xfd;
            Unp->EndAdr=0xfd;
            q=mem[p+0x5c];
            Unp->RetAdr=((mem[p+0xdd]-q)&0xff)|(((mem[p+0xde]-q)&0xff)<<8);
            PrintInfo(Unp,_I_MSICOD);
            Unp->IdFlag=1;return;
        }
    }
}
