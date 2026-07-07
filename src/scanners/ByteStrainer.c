/* ByteStrainer 1.3 */
#include "../unp64.h"
void Scn_ByteStrainer(unpstr *Unp)
{
    unsigned char *mem;

    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x80b)==0xBE7800A0) &&
            (*(unsigned int*)(mem+0x80f)==0x01960802) &&
            (*(unsigned int*)(mem+0x813)==0x4CF810C8) &&
            (*(unsigned int*)(mem+0x817)==0x57B10018) )
        {
            Unp->DepAdr=0x18;
            Unp->Forced=0x80b;
            Unp->fStrAf=0x42;
            Unp->EndAdr=mem[0x843]|mem[0x844]<<8;Unp->EndAdr++;
            Unp->RetAdr=mem[0x835]|mem[0x836]<<8;
            PrintInfo(Unp,_I_BYTESTRN);
            Unp->IdFlag=1;return;
        }
    }
}
