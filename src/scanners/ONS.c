/* Unknown ONS packer */
#include "../unp64.h"
void Scn_ONS(unpstr *Unp)
{
    unsigned char *mem;
    int p;
    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x801)==0xE67800A2)&&
           (*(unsigned short int*)(mem+0x805)==0xbd01)&&
           (*(unsigned int*)(mem+0x809)==0xA900E89D)&&
           (*(unsigned int*)(mem+0x813)==0x01004CF2))
        {
            p=mem[0x807]|mem[0x808]<<8;
            if( (mem[p  ]==0x8d) &&
                (*(unsigned int*)(mem+p+0x52)==0x4C00F420) )
            {
                Unp->Forced=0x801;
                Unp->DepAdr=0x100;
                Unp->RetAdr=mem[p+0x63]|mem[p+0x64]<<8;
                Unp->EndAdr=mem[p+1]|mem[p+2]<<8;Unp->EndAdr++;
                Unp->fStrAf=0xe9;
                PrintInfo(Unp,_I_ONSPACK);
                Unp->IdFlag=1;return;
            }
        }
    }
}
