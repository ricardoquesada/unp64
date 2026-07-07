/* Topaz Maimer/Scapegoat
 * name found in Caught from Behind/Topaz
 */
#include "../unp64.h"
void Scn_Maimer(unpstr *Unp)
{
    unsigned char *mem;

    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x810)==0x99084EB9) &&
            (*(unsigned int*)(mem+0x814)==0xD0880400) &&
            (*(unsigned int*)(mem+0x84a)==0x04094C03) &&
            (*(unsigned int*)(mem+0x8cc)==0x04154CE5) )
        {
            Unp->DepAdr=0x409;
            if(Unp->info->run == -1)
            {
               // there are patched versions, use sys addr when possible
               Unp->Forced=0x80b;
            }
            Unp->StrMem=mem[0x85b]|mem[0x85d]<<8;
            Unp->fEndAf=0x04;
            Unp->EndAdC=0xffff; // always incremented at end
            Unp->RetAdr=mem[0x871]|mem[0x872]<<8;
            PrintInfo(Unp,_I_MAIMER23);
            Unp->IdFlag=1;return;
        }
        if( ((*(unsigned int*)(mem+0x810)&0xffffff00)==0x99084000) &&
            (*(unsigned int*)(mem+0x814)==0xD0880400) &&
            (*(unsigned int*)(mem+0x8a2)==0x04114C03) &&
            (*(unsigned int*)(mem+0x8f7)==0x04114C00) )
        {
            Unp->DepAdr=0x409;
            if(Unp->info->run == -1)
            {
               Unp->Forced=0x80b;
            }
            // this version assumes low byte of start mem always 1
            // 0849  C8        INY      <- enters depacker with Y=0
            // 084A  A2 08     LDX #$08
            // 084C  84 04     STY $04
            // 084E  86 05     STX $05  <- sta ($04),y is used to store
            Unp->StrMem=1|mem[0x84b]<<8;
            Unp->fEndAf=0x04;
            Unp->EndAdC=0xffff;
            Unp->RetAdr=mem[0x85f]|mem[0x860]<<8;
            PrintInfo(Unp,_I_MAIMER1X);
            Unp->IdFlag=1;return;
        }
    }
}
