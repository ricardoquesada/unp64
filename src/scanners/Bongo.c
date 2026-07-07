/* bongo cruncher */
#include "../unp64.h"
void Scn_Bongo(unpstr *Unp)
{
    unsigned char *mem;
//    int q,p;
    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if( (mem[0x814]==0xa0) &&
            (*(unsigned int*)(mem+0x816)==0x084DB978) &&
            (*(unsigned int*)(mem+0x81a)==0xC000FF99) &&
            (*(unsigned int*)(mem+0x846)==0x0D01004C) )
        {
            if( Unp->info->run == -1)
                Unp->Forced=0x814;

            Unp->EndAdr=0x6c;
            mem[0xd1]=0;
            mem[0xd2]=4;// output on screen 0x400;
            if(mem[0x822]==0x23)
            {
                Unp->RetAdr=mem[0x8f5]|mem[0x8f6]<<8;
                Unp->DepAdr=0x12e;
                Unp->MonStr=0x006c<<16|0x006d;
            }
            if(mem[0x822]==0x0c)
            {
                Unp->RetAdr=mem[0x8de]|mem[0x8df]<<8;
                Unp->DepAdr=0x128;
                Unp->fStrBf=0x06c;
            }
            PrintInfo(Unp,_I_BONGO);
            Unp->IdFlag=1;return;
        }
        if( (mem[0x814]==0xa2) &&
            (*(unsigned int*)(mem+0x816)==0x0834bd78) &&
            (*(unsigned int*)(mem+0x81a)==0xe001009d) &&
            (*(unsigned int*)(mem+0x832)==0x8D01014C) )
        {
            if( Unp->info->run == -1)
                Unp->Forced=0x814;

            Unp->EndAdr=0x6c;
            mem[0xd1]=0;
            mem[0xd2]=4;// output on screen 0x400;
            Unp->RetAdr=mem[0x8dc]|mem[0x8dd]<<8;
            Unp->DepAdr=0x12f;
            Unp->MonStr=0x006c<<16|0x006d;
            PrintInfo(Unp,_I_BONGO);
            Unp->IdFlag=1;return;
        }
        if( (mem[0x814]==0x78) &&
            (*(unsigned int*)(mem+0x815)==0x018538A9) &&
            (*(unsigned int*)(mem+0x820)==0xEF8C08EE) &&
            (*(unsigned int*)(mem+0x8c0)==0xE56DA56E) )
        {
            if( Unp->info->run == -1)
                Unp->Forced=0x814;

            Unp->EndAdr=0x6c;
            mem[0xd1]=0;
            mem[0xd2]=4;// output on screen 0x400;
            Unp->RetAdr=mem[0x8af]|mem[0x8b0]<<8;
            Unp->RtAFrc=1;
            Unp->DepAdr=0x847;
            Unp->fStrBf=0x06c;
            PrintInfo(Unp,_I_BONGO);
            Unp->IdFlag=1;return;
        }
    }
}
