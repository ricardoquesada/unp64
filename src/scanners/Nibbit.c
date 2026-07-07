/* Nibb-it/SCL */
#include "../unp64.h"
void Scn_Nibbit(unpstr *Unp)
{
    unsigned char *mem;

    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x814)==0xA97800A0) &&
            (*(unsigned int*)(mem+0x834)==0xC8070099) &&
            (*(unsigned int*)(mem+0x850)==0x8D073D20) &&
            (*(unsigned int*)(mem+0x880)==0x3FEE03D0) )
        {
            Unp->DepAdr=0x700;
            Unp->Forced=0x814;
            Unp->StrMem=mem[0x854]|mem[0x855]<<8;
            Unp->fEndAf=0x717;Unp->EndAdC=0xffff;

            Unp->RetAdr=mem[0x875]|mem[0x856]<<8;
            if(*(unsigned int*)(mem+0x874)==0x4CA65920)
            {
                mem[0x874]=0x2c;
                Unp->RetAdr=mem[0x878]|mem[0x879]<<8;
            }
            PrintInfo(Unp,_I_NIBBIT);
            Unp->IdFlag=1;return;
        }
    }
}
