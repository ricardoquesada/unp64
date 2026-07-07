/* CobraCC/ShadowfireGG Coder */
#include "../unp64.h"
void Scn_Cobra(unpstr *Unp)
{
    unsigned char *mem;
    int p;
    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x81e)==0xFB8577A9) &&
           (*(unsigned int*)(mem+0x832)==0xBD36A278) &&
           (*(unsigned int*)(mem+0x836)==0x3B9D0840) &&
           (*(unsigned int*)(mem+0x842)==0x49FBB100) )
        {
            Unp->Forced=0x81e;
            Unp->DepAdr=0x33c;
            Unp->StrMem=0x801;
            Unp->fEndAf=0xae;
            Unp->EndAdC=0xffff;
            p=0x869;
            Unp->RetAdr=mem[p+1]|mem[p+2]<<8;
            if(Unp->RetAdr == 0xa659)
            {
                mem[p]=0x2c;
                Unp->RetAdr=0xa7ae;
            }
            PrintInfo(Unp,_I_COBRACOD);
            Unp->IdFlag=1;return;

        }
    }
}
