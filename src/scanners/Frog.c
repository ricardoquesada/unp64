/* Frog aka BCC e-Packer v1 */
#include "../unp64.h"
void Scn_Frog(unpstr *Unp)
{
    unsigned char *mem;

    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x811)==0x21BDB0A2) &&
            (*(unsigned int*)(mem+0x815)==0x01009D08) &&
            (*(unsigned int*)(mem+0x821)==0x8501ACAD) &&
            (*(unsigned int*)(mem+0x825)==0x01ADADF7)
          )
        {
            Unp->Forced=0x811;
            Unp->DepAdr=0x100;
            Unp->StrMem=mem[0x862]|mem[0x864]<<8;
            Unp->RetAdr=mem[0x8b5]|mem[0x8b6]<<8;
            if (Unp->RetAdr==0xa533)
            {
                mem[0x8b4]=0x4c;
                mem[0x8b5]=0xae;
                mem[0x8b6]=0xa7;
                Unp->RetAdr=mem[0x8b5]|mem[0x8b6]<<8;
            }
            Unp->EndAdr=0xf9;
            PrintInfo(Unp,_I_FROGPACK);
            Unp->IdFlag=1;return;
        }
    }
}
