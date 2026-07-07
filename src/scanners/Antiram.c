/* Antiram packers, mostly found in CGS cracks */
#include "../unp64.h"
void Scn_Antiram(unpstr *Unp)
{
    unsigned char *mem;
    int p;
    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    /* WARNING: found many times the prg with 1 extra byte at end
       and fails to unpack on vice (must ask someone to check on real c64 but
       I don't have any reason to think it is just an emulation issue).
       Just delete last byte thus reducing the file size and it works.
     */
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x80d)==0xB900A078) &&
           (*(unsigned int*)(mem+0x81d)==0xC6FF004C) &&
           (*(unsigned int*)(mem+0x82d)==0x08C9AFA5) &&
           (*(unsigned int*)(mem+0x8ed)==0xFF354C03) )
        {
            Unp->DepAdr=0xff00;
            Unp->Forced=0x80d;
            p=0x904;
            if(mem[p]==0x20)
            {
                mem[p]=0x2c;
                p+=3;
            }
            Unp->RetAdr=mem[p+1]|mem[p+2]<<8;
            Unp->StrMem=0x801;
            Unp->EndAdr=0x2d;
            Unp->RtAFrc=1;
            PrintInfo(Unp,_I_ANTIRAM1);
            Unp->IdFlag=1;return;
        }
    }
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x80d)==0xB900A078) &&
           (*(unsigned int*)(mem+0x81d)==0xa9FF004C) &&
           (*(unsigned int*)(mem+0x82d)==0xC86291AE) &&
           (*(unsigned int*)(mem+0x8ed)==0xD0CA2EE6) )
        {
            Unp->DepAdr=0xff00;
            Unp->Forced=0x80d;
            p=0x911;
            if(mem[p]==0x20)
            {
                mem[p]=0x2c;
                p+=3;
            }
            Unp->RetAdr=mem[p+1]|mem[p+2]<<8;

            Unp->StrMem=0x801;
            Unp->EndAdr=0x2d;
            Unp->RtAFrc=1;
            PrintInfo(Unp,_I_ANTIRAM2);
            Unp->IdFlag=1;return;
        }
    }
}
