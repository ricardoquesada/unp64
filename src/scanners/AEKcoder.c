/* AEK Coder */
#include "../unp64.h"
void Scn_AEKcoder(unpstr *Unp)
{
    unsigned char *mem;
    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x833)==0x41BD00A2) &&
          ((*(unsigned int*)(mem+0x837)&0x00ffffff)==0x00419D08) &&
           (*(unsigned int*)(mem+0x83b)==0x4CF7D0E8) &&
          ((*(unsigned int*)(mem+0x83f)&0xffff00ff)==0xA9780041) &&
          ((*(unsigned int*)(mem+0x85b)&0xffffff00)==0xD0FFC900) )
        {
            Unp->DepAdr=mem[0x83f]|mem[0x840]<<8;
            Unp->Forced=0x833;
            Unp->RetAdr=mem[0x877]|mem[0x878]<<8;
            if((Unp->RetAdr!=0xa7ae) && (mem[0x873]==0x20))
                mem[0x873]=0x2c;
            Unp->EndAdr=mem[0x861]|mem[0x863]<<8;
            Unp->StrMem=mem[0x84e]|mem[0x84f]<<8;
            PrintInfo(Unp,_I_AEKCOD20);
            Unp->IdFlag=1;return;
        }
    }
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x811)==0x2FBD00A2) &&
           (*(unsigned int*)(mem+0x815)==0x04009D09) &&
           (*(unsigned int*)(mem+0x833)==0x00A900A2) &&
           (*(unsigned int*)(mem+0x86b)==0x08114CF5) &&
           (*(unsigned int*)(mem+0x987)==0x49FAB100) )
        {
            Unp->DepAdr=0x400;
            Unp->Forced=0x833;
            Unp->RetAdr=mem[0x9f3]|mem[0x9f4]<<8;
            if((Unp->RetAdr!=0xa7ae) && (mem[0x9ef]==0x20))
                mem[0x9ef]=0x2c;
            Unp->EndAdr=0xae;
            Unp->StrMem=0x800;
            PrintInfo(Unp,_I_AEKCOD11);
            Unp->IdFlag=1;return;
        }
    }
}
