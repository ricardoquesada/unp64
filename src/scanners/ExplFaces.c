/* Exploding Faces */
#include "../unp64.h"
void Scn_ExplFaces(unpstr *Unp)
{
    unsigned char *mem;

    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x81f)==0x8D00A978) &&
            (*(unsigned int*)(mem+0x82e)==0x018534A9) &&
            (*(unsigned int*)(mem+0x834)==0x9D0846BD) &&
            (*(unsigned int*)(mem+0x843)==0x20FE004C)
          )
        {
            Unp->Forced=0x81f;
            Unp->DepAdr=mem[0x92a]|mem[0x92b]<<8;
            Unp->RetAdr=mem[0xa01]|mem[0xa02]<<8;
            Unp->EndAdr=mem[0xa07]|mem[0xa08]<<8;
            PrintInfo(Unp,_I_EXPLFAC1);
            Unp->IdFlag=1;return;
        }
    }
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x816)==0xB905A078) &&
            (*(unsigned int*)(mem+0x81a)==0xFA990926) &&
            (*(unsigned int*)(mem+0x823)==0x03344C01) &&
            (*(unsigned int*)(mem+0x876)==0x2603C120)
          )
        {
            if(Unp->info->run == -1)
            {
                if(mem[0x80b]==0xa0)
                    Unp->Forced=0x80b;
            }
            Unp->DepAdr=0x334;
            Unp->RetAdr=mem[0x841]|mem[0x842]<<8;
            Unp->StrMem=mem[0x830]|mem[0x831]<<8;
            Unp->fEndAf=0x33d;
            Unp->EndAdC=0xffff-mem[0x82d];
            PrintInfo(Unp,_I_EXPLFAC2);
            Unp->IdFlag=1;return;
        }
    }
}
