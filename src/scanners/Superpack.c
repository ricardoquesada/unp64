/* Superpack */
#include "../unp64.h"
void Scn_Superpack(unpstr *Unp)
{
    unsigned char *mem;

    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x81b)==0x20A28078) &&
            (*(unsigned int*)(mem+0x836)==0x08A06BA2) &&
            (*(unsigned int*)(mem+0x84b)==0xE602D0C8) &&
            (*(unsigned int*)(mem+0x85b)==0xE3D061E0) )
        {
            Unp->DepAdr=0x161;
            Unp->Forced=0x81b;
            Unp->fEndAf=0x2d;
            PrintInfo(Unp,_I_SUPERPACK4);
            Unp->IdFlag=1;return;
        }
    }
}
