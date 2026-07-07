/* Soeren Kress */
#include "../unp64.h"
void Scn_KressCrunch(unpstr *Unp)
{
    unsigned char *mem;
    int p;
    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x80b)==0x4E7800A2) &&
            (*(unsigned int*)(mem+0x80f)==0x01E6D011) &&
            mem[0x813]==0x4c )
        {
            p=mem[0x814]|mem[0x815]<<8;
            if( (*(unsigned int*)(mem+p+0x05)== 0xBD04009D)&&
                (*(unsigned int*)(mem+p+0x33)== 0xA500ED4C) )
            {
                Unp->Forced=0x80b;
                Unp->DepAdr=0x0ed;
                Unp->RetAdr=mem[p+0x6d]|mem[p+0x6e]<<8;
                Unp->EndAdr=mem[p+0x5b]|mem[p+0x5c]<<8;;Unp->EndAdr+=0x100;
                Unp->fStrAf=0x102;
                Unp->StrAdC=0xffff|EA_USE_Y|EA_ADDFF;
                PrintInfo(Unp,_I_KRESS);
                Unp->IdFlag=1;return;
            }
        }
    }
}
