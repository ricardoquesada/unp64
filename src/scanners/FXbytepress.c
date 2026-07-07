/* FX bytepress */
#include "../unp64.h"
void Scn_FXbytepress(unpstr *Unp)
{
    unsigned char *mem;
    int p;
    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x822)==0xBD00A278) &&
            (*(unsigned int*)(mem+0x826)==0x019D0837) &&
            (*(unsigned int*)(mem+0x82a)==0x0858BD04) &&
            (*(unsigned int*)(mem+0x94c)==0x033C4C03) )
        {
            Unp->DepAdr=0x40d;
            Unp->Forced=0x822;
            p=0x837;
            Unp->StrMem=mem[p+0x00]|mem[p+0x01]<<8;
            Unp->EndAdr=mem[p+0x02]|mem[p+0x03]<<8;
            Unp->RetAdr=mem[p+0x06]|mem[p+0x07]<<8;
            PrintInfo(Unp,_I_FXBYTEP);
            Unp->IdFlag=1;return;
        }
    }
    /* BB bytepress */
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x827)==0x9D0835BD) &&
            (*(unsigned int*)(mem+0x82f)==0x4CF5D0F5) &&
            (*(unsigned int*)(mem+0x8FF)==0x03E5FDA5) &&
            (*(unsigned int*)(mem+0x90F)==0xD0FFC088) )
        {
            Unp->DepAdr=mem[0x833]|mem[0x834]<<8;
            p=0x835;
            Unp->StrMem=mem[p+0x00]|mem[p+0x01]<<8;
            Unp->EndAdr=mem[p+0x02]|mem[p+0x03]<<8;
            Unp->RetAdr=mem[p+0x06]|mem[p+0x07]<<8;
            if((mem[0x825]==0xa2) &&
               (mem[0x928]!=mem[0x91f]) )
            {
                if(*(unsigned short int*)(mem+0x928)!=0x33c)
                    Unp->RetAdr=mem[0x928]|mem[0x929]<<8;
                PrintInfo(Unp,_I_FXBP_BBSP);
            }
            else
            {
                PrintInfo(Unp,_I_FXBP_BB);
            }
            if(Unp->info->run == -1)
                Unp->Forced=0x822;
            Unp->IdFlag=1;return;
        }
    }
    /* Jewels bytepress */
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x81f)==0xE89AFFA2) &&
            (*(unsigned int*)(mem+0x823)==0x9D0835BD) &&
            (*(unsigned int*)(mem+0x900)==0x03E5FDA5) &&
            (*(unsigned int*)(mem+0x910)==0xD0FFC088) )
        {
            Unp->DepAdr=mem[0x833]|mem[0x834]<<8;
            if(Unp->info->run == -1)
                Unp->Forced=0x81e;
            p=0x835;
            Unp->StrMem=mem[p+0x00]|mem[p+0x01]<<8;
            Unp->EndAdr=mem[p+0x02]|mem[p+0x03]<<8;
            Unp->RetAdr=mem[0x928]|mem[0x929]<<8;
            PrintInfo(Unp,_I_FXBP_JW);
            Unp->IdFlag=1;return;
        }
    }
    /* SEEN bytepress */
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x822)==0x9affA278) &&
            (*(unsigned int*)(mem+0x826)==0x0835BDE8) &&
            (*(unsigned int*)(mem+0x82a)==0xE801009D) &&
            (*(unsigned int*)(mem+0x928)==0x01058D4C) )
        {
            Unp->DepAdr=0x10c;
            Unp->Forced=0x822;
            p=0x835;
            Unp->StrMem=mem[p+0x00]|mem[p+0x01]<<8;
            Unp->EndAdr=mem[p+0x02]|mem[p+0x03]<<8;
            Unp->RetAdr=mem[p+0x06]|mem[p+0x07]<<8;
            PrintInfo(Unp,_I_FXBP_SN);
            Unp->IdFlag=1;return;
        }
    }
}
