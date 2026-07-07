/* unknown $25 */
#include "../unp64.h"
void Scn_U_25_pack(unpstr *Unp)
{
    unsigned char *mem;
    int p=0,q;
    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        for(q=Unp->info->start;q<Unp->info->start+0x21;q++)
        {
            if( (*(unsigned int*)(mem+q+0x00)==0xE67800A0) &&
                (*(unsigned int*)(mem+q+0x0a)==0xC8FF4099) &&
                (*(unsigned int*)(mem+q+0x18)==0x00254CEE) )
            {
                p=mem[q+0x8]|mem[q+0x9]<<8;p+=0xc0;
                if( (*(unsigned short int*)(mem+p+0x00)==0x342f) &&
                    (*(unsigned int*)(mem+p+0x05)==0xF08824B0) &&
                    (*(unsigned int*)(mem+p+0x34)==0xCAD004E6) )
                {
                    Unp->DepAdr=0x25;
                    Unp->Forced=q;
                }
                break;
            }
        }
        if(Unp->DepAdr)
        {
            Unp->RetAdr=mem[p+0x3e]|mem[p+0x3f]<<8;
            Unp->EndAdr=0x15;
            Unp->StrMem=mem[p+0x15]|mem[p+0x16]<<8;
            PrintInfo(Unp,_I_U_25);
            Unp->IdFlag=1;return;
        }
    }
}
