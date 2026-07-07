/* eastlinker */
#include "../unp64.h"
void Scn_Eastlinker(unpstr *Unp)
{
    unsigned char *mem;

    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x80f)==0x018538A9) &&
           (*(unsigned int*)(mem+0x81a)==0xCAFF009D) &&
           (*(unsigned int*)(mem+0x83e)==0x01404C03) &&
           (*(unsigned int*)(mem+0x89c)==0x048501A6) )
        {
            Unp->DepAdr=0x140;
            Unp->Forced=0x80f;
            Unp->RetAdr=mem[0x8bb]|mem[0x8bc]<<8;
            if((mem[0x8c0]==mem[0x848])&&(mem[0x8c1]==0)) /* 1st rle=startpointer */
                Unp->StrMem=mem[0x8c2]|mem[0x8c3]<<8;
            Unp->EndAdr=0x04;
            PrintInfo(Unp,_I_EASTLINK);
            Unp->IdFlag=1;return;
        }
    }
}
