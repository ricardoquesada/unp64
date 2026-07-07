/* SpyPacker, variable entry */
#include "../unp64.h"
void Scn_SpyPack(unpstr *Unp)
{
    unsigned char *mem;
    int q=0;
    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        for(q=0x801;q<0x830;q++)
        {
            if(/*(mem[q]==0xa2)&&*/(mem[q+2]==0xbd)&&
               (*(unsigned int*)(mem+q+0x04)==0x033C9D08) &&
               (*(unsigned int*)(mem+q+0x50)==0x20033C4C) &&
               (*(unsigned int*)(mem+q+0x80)==0x03A52003) )
            {
                Unp->DepAdr=0x33c;
                break;
            }
        }
        if(Unp->DepAdr)
        {
            if(Unp->info->run==-1)
            {
                Unp->Forced=q+2;
            }
            Unp->RetAdr=mem[q+0x95]|mem[q+0x96]<<8;
            Unp->StrMem=mem[q+0x49]|mem[q+0x4b]<<8;
            Unp->EndAdr=0x2d;
            PrintInfo(Unp,_I_SPYPACK);
            Unp->IdFlag=1;return;
        }
    }
}
