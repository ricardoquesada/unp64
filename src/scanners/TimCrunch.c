/* TimCrunch (Stoat&Tim) */
#include "../unp64.h"
void Scn_TimCrunch(unpstr *Unp)
{
    unsigned char *mem;
    int p;
    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x81b)==0xB994A078) &&
            (*(unsigned int*)(mem+0x82b)==0xBD10A201) &&
            (*(unsigned int*)(mem+0x87a)==0xC601004C) )
        {
            Unp->DepAdr=0x100;
            if(Unp->info->run == -1)
                Unp->Forced=0x81b;
            if(mem[0x901] == 0xff)
            {
                Unp->RetAdr=mem[0x907]|mem[0x908]<<8;
            }
            else
            {
                if(mem[0x901]==0)
                {
                    //Unp->RetAdr=0x17b;
                }
                else
                {
                    Unp->RetAdr=mem[0x920]|mem[0x921]<<8;
                }
            }
            p=Unp->info->end-4;
            Unp->StrMem=mem[p+2]|mem[p+3]<<8;
            Unp->EndAdr=mem[p+0]|mem[p+1]<<8;
            PrintInfo(Unp,_I_TIMCR );
            Unp->IdFlag=1;return;
        }
    }
}
