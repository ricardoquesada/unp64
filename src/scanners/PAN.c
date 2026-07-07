/* PAN(inaro?) packer */
#include "../unp64.h"
void Scn_PAN(unpstr *Unp)
{
    unsigned char *mem;

    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        /*found in games by eike kiltz*/
        if( (mem[0x812]==0x78) &&
            (*(unsigned int*)(mem+0x81b)==0x0828BD00) &&
            (*(unsigned int*)(mem+0x86b)==0xB101A0AA) &&
            (*(unsigned int*)(mem+0x87b)==0x201FF068) )
        {
            Unp->Forced=0x812;
            Unp->DepAdr=0x100;
            Unp->fEndAf=0x52;
            Unp->EndAdC=EA_ADDFF|EA_USE_Y;
            Unp->StrMem=mem[0x849]|mem[0x84b]<<8;
            Unp->RetAdr=mem[0x8a8]|mem[0x8a9]<<8;
            PrintInfo(Unp,_I_PANPACK);
            Unp->IdFlag=1;return;
        }
        /* Paninaro cracks */
        if( (*(unsigned int*)(mem+0x801)==0x9AFFA278) &&
            (*(unsigned int*)(mem+0x805)==0x9D0823BD) &&
            (*(unsigned int*)(mem+0x809)==0xD0CA00F9) &&
            (*(unsigned int*)(mem+0x842)==0x013120AA) )
        {
            Unp->Forced=0x801;
            Unp->DepAdr=0x100;
            Unp->fEndAf=0xfa;
            Unp->StrMem=mem[0x824]|mem[0x825]<<8;
            Unp->RetAdr=mem[0x840]|mem[0x841]<<8;
            PrintInfo(Unp,_I_PANPACK2);
            Unp->IdFlag=1;return;
        }
    }
}
