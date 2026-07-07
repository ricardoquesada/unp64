/* TDT packer(s)? */
#include "../unp64.h"
void Scn_TDT(unpstr *Unp)
{
    unsigned char *mem;
    int p;
    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x811)==0x8534A978) &&
           (*(unsigned int*)(mem+0x819)==0xFF9D0823) &&
           (*(unsigned int*)(mem+0x821)==0xA204004C) &&
           (*(unsigned int*)(mem+0x874)==0x2002A74C) )
        {
            /* to bypass intro */
            Unp->DepAdr=0x2aa;
            Unp->Forced=0x811;
            Unp->EndAdr=0x2d;
            mem[0x877]=0x2c;
            mem[0xcb]=1;
            PrintInfo(Unp,_I_TDT);
            Unp->IdFlag=1;return;
        }
        /* not sure is by TDT but surely used by them, "*PET*" in code */
        if((*(unsigned int*)(mem+0x810)==0xBD9A00A2) &&
           (*(unsigned int*)(mem+0x816)==0xF9D0E848) &&
           (*(unsigned int*)(mem+0x81a)==0xF8A29AAA) &&
           (*(unsigned int*)(mem+0x821)==0xD0E80095) )
        {
            Unp->DepAdr=0x10d;
            Unp->Forced=0x80d;
            p=mem[0x814]|mem[0x815]<<8;
            Unp->EndAdr=mem[p+2]|mem[p+3]<<8;Unp->EndAdr++;
            Unp->RetAdr=mem[p+7]|mem[p+6]<<8;Unp->RetAdr++;
            if(mem[p+0xff]==0xf3)
            {
                Unp->StrMem=mem[p+0xb5]|mem[p+0xbb]<<8;
                PrintInfo(Unp,_I_TDTPETC1);
            }
            else if(mem[p+0xff]==0xf4)
            {
                Unp->StrMem=mem[p+0xb3]|mem[p+0xb9]<<8;
                PrintInfo(Unp,_I_TDTPETC2);
            }
            else
            {
                PrintInfo(Unp,_I_TDTPETCU);
            }
            Unp->IdFlag=1;return;
        }

        if((*(unsigned int*)(mem+0x813)==0x018538A9) &&
           (*(unsigned int*)(mem+0x818)==0x9AA8AA00) &&
           (*(unsigned int*)(mem+0x81f)==0xF9D0E848) &&
           (*(unsigned int*)(mem+0x842)==0x0857BDEE) )
        {
            Unp->DepAdr=0x102;
            Unp->Forced=0x813;
            p=mem[0x81d]|mem[0x81e]<<8;
            Unp->RetAdr=mem[p+7]|mem[p+6]<<8;Unp->RetAdr++;
            Unp->StrMem=mem[p+0xed]|mem[p+0xec]<<8;
            PrintInfo(Unp,_I_TDTPETL);
            Unp->IdFlag=1;return;
        }
    }

}
