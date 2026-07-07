/* Tony Savona (Tsurugi/ATL) Cruncher */
#include "../unp64.h"
void Scn_TSCrunch(unpstr *Unp)
{
    unsigned char *mem;

    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x80d)==0xBDB3A278) &&
           (*(unsigned int*)(mem+0x818)==0x3400024C) &&
           (*(unsigned int*)(mem+0x86d)==0xD69000A9) &&
           (mem[0x876]==0x4c) )
        {
            Unp->DepAdr=0x02;
            Unp->Forced=0x80d;
            Unp->StrMem=mem[0x841]|mem[0x842]<<8;
            Unp->EndAdr=mem[0x848]; //0x27;
            Unp->RetAdr=mem[0x877]|mem[0x878]<<8;
            PrintInfo(Unp,_I_TSCRUNCH10);
            Unp->IdFlag=1;return;
        }
    }
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x80d)==0xBDC0A278) &&
           (*(unsigned int*)(mem+0x818)==0x3400024C) &&
           (*(unsigned int*)(mem+0x86d)==0xD69002A2) &&
           (mem[0x876]==0x4c) )
        {
            Unp->DepAdr=0x02;
            Unp->Forced=0x80d;
            Unp->StrMem=mem[0x841]|mem[0x842]<<8;
            Unp->EndAdr=mem[0x848]; //0x27;
            Unp->RetAdr=mem[0x877]|mem[0x878]<<8;
            PrintInfo(Unp,_I_TSCRUNCH12);
            Unp->IdFlag=1;return;
        }
    }
    // https://csdb.dk/release/?id=216394
    // v1.3 as of 2022-04-05 build
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x80d)==0xBDC9A278) &&
           (*(unsigned int*)(mem+0x818)==0x3400024C) &&
           (*(unsigned int*)(mem+0x85c)==0x538502A2) &&
           (mem[0x875]==0x4c) )
        {
            Unp->DepAdr=0x02;
            Unp->Forced=0x80d;
            Unp->StrMem=mem[0x83f]|mem[0x840]<<8;
            Unp->EndAdr=mem[0x846]; //0x25;
            Unp->RetAdr=mem[0x876]|mem[0x877]<<8;
            PrintInfo(Unp,_I_TSCRUNCH13);
            Unp->IdFlag=1;return;
        }
    }
    // v1.3.1 as of 2023-01-02 build, updated 2025-03-30
    if( Unp->DepAdr==0 )
    {
        if(((*(unsigned int*)(mem+0x80d)==0xBDCFA278)||(*(unsigned int*)(mem+0x80d)==0xBDCCA278)) &&
           (*(unsigned int*)(mem+0x818)==0x3400024C) &&
           (*(unsigned int*)(mem+0x862)==0x598502A2) &&
           (mem[0x87b]==0x4c) )
        {
            Unp->DepAdr=0x02;
            Unp->Forced=0x80d;
            Unp->StrMem=mem[0x841]|mem[0x842]<<8;
            Unp->EndAdr=mem[0x84e]; //0x27;
            Unp->RetAdr=mem[0x87c]|mem[0x87d]<<8;
            PrintInfo(Unp,_I_TSCRUNCH131);
            Unp->IdFlag=1;return;
        }
    }
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x80d)==0x8D0BA978) &&
           (*(unsigned int*)(mem+0x81d)==0x3400024C) &&
           (*(unsigned int*)(mem+0x867)==0x598502A2) &&
           (mem[0x880]==0x4c) )
        {
            Unp->DepAdr=0x02;
            Unp->Forced=0x80d;
            Unp->StrMem=mem[0x846]|mem[0x847]<<8;
            Unp->EndAdr=mem[0x853]; //0x27;
            Unp->RetAdr=mem[0x881]|mem[0x882]<<8;
            PrintInfo(Unp,_I_TSCRUNCH131B);
            Unp->IdFlag=1;return;
        }
    }
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x80d)==0x8534A978) &&
           (*(unsigned int*)(mem+0x81c)==0x01004CF7) &&
           (*(unsigned int*)(mem+0x86a)==0xF98502A2) &&
           (mem[0x883]==0x4c) )
        {
            Unp->DepAdr=0x0100;
            Unp->Forced=0x80d;
            Unp->StrMem=mem[0x822]|mem[0x823]<<8;
            Unp->EndAdr=mem[0x856]; //0xfe;
            Unp->RetAdr=mem[0x884]|mem[0x885]<<8;
            PrintInfo(Unp,_I_TSCRUNCH131X2);
            Unp->IdFlag=1;return;
        }
    }

}
