/* unknown $100 packer, sysless at $0801 */
#include "../unp64.h"
void Scn_U_100pack(unpstr *Unp)
{
    unsigned char *mem;
    int p;
    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    /* unknown $100 packer, sys2061 (or 2062 w/o SEI) */
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x80e)==0x018534A9) &&
            (*(unsigned int*)(mem+0x820)==0x1BCE0818) &&
            (*(unsigned int*)(mem+0x82e)==0xD08800FB) &&
            (*(unsigned int*)(mem+0x83c)==0x2a2a2a2a) )
        {
            Unp->Forced=0x80e;
            Unp->DepAdr=0x100;
            Unp->RetAdr=mem[0x870]|mem[0x871]<<8;
            Unp->StrMem=mem[0x836]|mem[0x837]<<8;
            Unp->EndAdr=0xfc;
            PrintInfo(Unp,_I_U_100_P2);
            Unp->IdFlag=1;return;
        }
    }
    /* another unknown $100 packer, 2 variants */
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x816)==0x1FCEAFC6) &&
            (*(unsigned int*)(mem+0x81a)==0x99AEB108) &&
            (*(unsigned int*)(mem+0x83c)==0x4A4AFEB1) &&
            (*(unsigned int*)(mem+0x840)==0xAA4A4A4A) )
        {
            for(p=0x0801;p<0x810;p++)
            {
                if(mem[p]==0x78)
                {
                    Unp->Forced=p;
                    break;
                }
            }
            Unp->DepAdr=0x100;
            if(*(unsigned int*)(mem+0x86d)==0x4CA65920)
                mem[0x86d]=0x2c;
            Unp->RetAdr=mem[0x871]|mem[0x872]<<8;
            Unp->StrMem=mem[0x838]|mem[0x839]<<8;
            Unp->EndAdr=0xae;
            PrintInfo(Unp,_I_U_100_P3);
            Unp->IdFlag=1;return;
        }
    }
    /* another, this time with sys 2066 */
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x812)==0x33E000A2) &&
            (*(unsigned int*)(mem+0x83e)==0x512060ED) &&
            (*(unsigned int*)(mem+0x890)==0x5C2009D0) &&
            (*(unsigned int*)(mem+0x894)==0x00572001) )
        {
            Unp->Forced=0x812;
            Unp->DepAdr=0x100;
            Unp->RetAdr=mem[0x8b8]|mem[0x8b9]<<8;
            Unp->StrMem=mem[0x8ce]|mem[0x8cf]<<8;
            Unp->EndAdr=0x62;
            PrintInfo(Unp,_I_U_100_P4);
            Unp->IdFlag=1;return;
        }
    }
    /* "sys 2062!" */
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x80e)==0xC9BDF9A2) &&
            (*(unsigned int*)(mem+0x812)==0xE8009507) &&
            (*(unsigned int*)(mem+0x876)==0x004C0172) &&
            (*(unsigned int*)(mem+0x8a2)==0xA518F885) )
        {
            Unp->Forced=0x80e;
            Unp->DepAdr=0x100;
            Unp->RetAdr=mem[0x89c]|mem[0x89d]<<8;
            Unp->StrMem=mem[0x8c4]|mem[0x8c5]<<8;
            Unp->EndAdr=0xfb;
            PrintInfo(Unp,_I_U_100_P5);
            Unp->IdFlag=1;return;
        }
    }
}
