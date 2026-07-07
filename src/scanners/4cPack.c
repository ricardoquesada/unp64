/* 4c packer */
#include "../unp64.h"
void Scn_4cPack(unpstr *Unp)
{
    unsigned char *mem;
    int p;
    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x80b)==0x867800A2) &&
           (*(unsigned int*)(mem+0x80f)==0x081DCE01) &&
           (*(unsigned int*)(mem+0x813)==0x024C03D0) &&
           (*(unsigned int*)(mem+0x817)==0x0820CE00) )
        {
            Unp->DepAdr=0x002;
            Unp->Forced=0x80b;
            p=mem[0x81c]|mem[0x81d]<<8;p-=0x24;
            Unp->StrMem=mem[p     ]|mem[p+1  ]<<8;
            Unp->RetAdr=mem[p+0x1b]|mem[p+0x1c]<<8;
            Unp->EndAdr=0x0f;
            PrintInfo(Unp,_I_4CPACK);
            Unp->IdFlag=1;return;
        }
    }
}
