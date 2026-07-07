/* OmegaSupreme/Panoramic */
#include "../unp64.h"
void Scn_Panoramic(unpstr *Unp)
{
    unsigned char *mem;
    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x803)==0xBD44A278) &&
           (*(unsigned int*)(mem+0x807)==0x00950811) &&
           (*(unsigned int*)(mem+0x823)==0x003B20C8) &&
           (*(unsigned int*)(mem+0x84f)==0x02D03CE6) )
        {
            Unp->DepAdr=0x2;
            Unp->Forced=0x803;
            Unp->StrMem=mem[0x833]|mem[0x834]<<8;
            Unp->RetAdr=mem[0x84a]|mem[0x84b]<<8;
            Unp->EndAdr=0x22;
            PrintInfo(Unp,_I_PDPACK1);
            Unp->IdFlag=1;return;
        }
    }
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x803)==0xBD41A278) &&
           (*(unsigned int*)(mem+0x807)==0x00950812) &&
           (*(unsigned int*)(mem+0x824)==0x003820C8) &&
           (*(unsigned int*)(mem+0x84d)==0x02D039E6) )
        {
            Unp->DepAdr=0x2;
            Unp->Forced=0x803;
            Unp->StrMem=mem[0x834]|mem[0x835]<<8;
            Unp->RetAdr=mem[0x848]|mem[0x849]<<8;
            Unp->EndAdr=0x22;
            PrintInfo(Unp,_I_PDPACK2);
            Unp->IdFlag=1;return;
        }
    }
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x803)==0xA001E678) &&
           (*(unsigned int*)(mem+0x807)==0x0815B947) &&
           (*(unsigned int*)(mem+0x82a)==0x013420C8) &&
           (*(unsigned int*)(mem+0x835)==0x013420A8) )
        {
            Unp->DepAdr=0xfa;
            Unp->Forced=0x803;
            Unp->StrMem=mem[0x818]|mem[0x819]<<8;
            Unp->RetAdr=mem[0x852]|mem[0x853]<<8;
            Unp->EndAdr=mem[0x845]|mem[0x849]<<8;
            PrintInfo(Unp,_I_PDPACK30);
            Unp->IdFlag=1;return;
        }
    }
    /* same as 3.0 but reversed depack from end to start */
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x803)==0xA001E678) &&
           (*(unsigned int*)(mem+0x807)==0x0815B94d) &&
           (*(unsigned int*)(mem+0x82a)==0x013420C8) &&
           (*(unsigned int*)(mem+0x835)==0x013420A8) )
        {
            Unp->DepAdr=0xfa;
            Unp->Forced=0x803;
            Unp->StrMem=mem[0x845]|mem[0x849]<<8;Unp->StrMem++;
            Unp->RetAdr=mem[0x852]|mem[0x853]<<8;
            Unp->EndAdr=mem[0x818]|mem[0x819]<<8;Unp->EndAdr++;
            PrintInfo(Unp,_I_PDPACK32);
            Unp->IdFlag=1;return;
        }
    }
    /* found in mentallic */
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x803)==0xA001E678) &&
           (*(unsigned int*)(mem+0x807)==0x0815B959) &&
           (*(unsigned int*)(mem+0x838)==0x014820e8) &&
           (*(unsigned int*)(mem+0x840)==0xAA014820) )
        {
            Unp->DepAdr=0xfa;
            Unp->Forced=0x803;
            Unp->StrMem=mem[0x816]|mem[0x817]<<8;
            Unp->RetAdr=mem[0x864]|mem[0x865]<<8;
            Unp->EndAdr=mem[0x855]|mem[0x85b]<<8;
            PrintInfo(Unp,_I_PDPACK31);
            Unp->IdFlag=1;return;
        }
    }
    /*Equalizer 1.5/OmegaSupreme*/
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x803)==0xA001E678) &&
           (*(unsigned int*)(mem+0x807)==0x0815B94C) &&
           (*(unsigned int*)(mem+0x80b)==0x8800F599) &&
           (*(unsigned int*)(mem+0x849)==0xDD90F9E5) )
        {
            Unp->DepAdr=0xfa;
            Unp->Forced=0x803;
            Unp->StrMem=mem[0x81e]|mem[0x81f]<<8;
            Unp->RetAdr=mem[0x851]|mem[0x852]<<8;
            Unp->EndAdr=mem[0x818]|mem[0x819]<<8;Unp->EndAdr++;
            PrintInfo(Unp,_I_PDEQLZ15);
            Unp->IdFlag=1;return;
        }
    }

}
