/* unknown $101 packer, sysless at $0801
   found for example in hackpack3
*/
#include "../unp64.h"
void Scn_U_101pack(unpstr *Unp)
{
    unsigned char *mem;

    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x801)==0xE67800A0) &&
            (*(unsigned int*)(mem+0x805)==0x0812B901) &&
            (*(unsigned int*)(mem+0x809)==0xC800E599) &&
            (*(unsigned int*)(mem+0x80e)==0x01014CF7) &&
            (*(unsigned int*)(mem+0x872)==0x4A4A4A4A) )
        {
            Unp->Forced=0x801;
            Unp->DepAdr=0x101;
            Unp->RetAdr=mem[0x886]|mem[0x887]<<8;
            Unp->EndAdr=mem[0x859]|mem[0x85a]<<8;Unp->EndAdr+=0x100;
            Unp->fStrAf=0x12c;
            Unp->StrAdC=0xffff|EA_USE_Y|EA_ADDFF;
            PrintInfo(Unp,_I_U_101);
            Unp->IdFlag=1;return;
        }
    }
}
