/* Compress64k by Hermit */
#include "../unp64.h"
void Scn_Comp64k(unpstr *Unp)
{
    unsigned char *mem;

    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x80e)==0x1BBDE0A2) &&
            (*(unsigned int*)(mem+0x813)==0xCA00FB9D) &&
            (*(unsigned int*)(mem+0x840)==0xB04A48B0) &&
            (*(unsigned int*)(mem+0x8e9)==0x4A4A4A4A) )
        {
            Unp->DepAdr=0x100;
            Unp->Forced=0x80e;
            Unp->StrMem=mem[0x81e]|mem[0x81f]<<8;
            Unp->fEndAf=0xfe;
            Unp->EndAdC=0xffff;
            Unp->RetAdr=mem[0x8fa]|mem[0x8fb]<<8;
            PrintInfo(Unp,_I_COMP64K11);
            Unp->IdFlag=1;return;
        }
        if( (*(unsigned int*)(mem+0x80e)==0x018538A9) &&
            (*(unsigned int*)(mem+0x817)==0xCA00FB9D) &&
            (*(unsigned int*)(mem+0x840)==0xB04AC802) &&
            (*(unsigned int*)(mem+0x8EF)==0xFFE60590) )
        {
            Unp->DepAdr=0x100;
            Unp->Forced=0x80e;
            Unp->StrMem=mem[0x839]|mem[0x83a]<<8;
            Unp->fEndAf=0xfe;
            Unp->EndAdC=0xffff;
            Unp->RetAdr=mem[0x8fd]|mem[0x8fe]<<8;
            PrintInfo(Unp,_I_COMP64K12);
            Unp->IdFlag=1;return;
        }
    }
}
