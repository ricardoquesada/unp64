/* Doynamite v1.1 */
#include "../unp64.h"
void Scn_Doynamite(unpstr *Unp)
{
    unsigned char *mem;

    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x80d)==0xA201E678) &&
           (*(unsigned int*)(mem+0x82b)==0x0825CE08) &&
           (*(unsigned int*)(mem+0x834)==0x0000C64C) &&
           (*(unsigned int*)(mem+0x910)==0x34EEF3E6) )
        {
            Unp->DepAdr=0x0c6;
            Unp->Forced=0x80d;
            Unp->RetAdr=mem[0x91a]|mem[0x91b]<<8;
            Unp->EndAdr=0xfb;
            Unp->StrMem=mem[0x870]|mem[0x871]<<8;
            PrintInfo(Unp,_I_DOYNAMITE);
            Unp->IdFlag=1;return;
        }
        /* variant by Bitbreaker, v0.4 */
        if((*(unsigned int*)(mem+0x81f)==0x00A201E6) &&
           (*(unsigned int*)(mem+0x823)==0x9D0846BD) &&
           (*(unsigned int*)(mem+0x827)==0xD0E80020) &&
           (*(unsigned int*)(mem+0x922)==0x60ACE643) )
        {
            Unp->DepAdr=0x020;
            if(Unp->info->run == -1)
                Unp->Forced=0x81e;
            Unp->RetAdr=mem[0x92c]|mem[0x92d]<<8;
            Unp->EndAdr=0x4b;
            Unp->StrMem=mem[0x871]|mem[0x872]<<8;
            PrintInfo(Unp,_I_BITNAX04);
            Unp->IdFlag=1;return;
        }
    }
}
