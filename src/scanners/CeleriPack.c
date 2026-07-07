/* CeleriPack/OneWay */
#include "../unp64.h"
void Scn_CeleriPack(unpstr *Unp)
{
    unsigned char *mem;
    int p;
    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x801)==0xE67800A2) &&
            (*(unsigned int*)(mem+0x809)==0xE800D99D) &&
            (*(unsigned int*)(mem+0x80d)==0xE64CF7D0) )
        {
            p=mem[0x807]|mem[0x808]<<8;
            if((*(unsigned int*)(mem+p+0x00)==0x02D0E2A5) &&
               (*(unsigned int*)(mem+p+0x83)==0x5BCE03D0) )
            {
                Unp->Forced=0x801;
                Unp->DepAdr=0x0e6;
                Unp->RetAdr=mem[p+0x96]|mem[p+0x97]<<8;
                Unp->EndAdr=mem[p+0x81]|mem[p+0x82]<<8;
                Unp->fStrAf=0x15a;
                Unp->StrAdC=EA_ADDFF|0xffff;
                PrintInfo(Unp,_I_CELERIP);
                Unp->IdFlag=1;return;
            }
        }
    }
}
