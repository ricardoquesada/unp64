/* Ratt/TSW */
#include "../unp64.h"
void Scn_Ratt(unpstr *Unp)
{
    unsigned char *mem;
    int strtmp,endtmp,p,q;
    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x820)==0x43BD00A2) &&
           (*(unsigned int*)(mem+0x824)==0x01009D08) &&
           (*(unsigned int*)(mem+0x88c)==0xECC5F0B1) &&
           (*(unsigned int*)(mem+0x89c)==0xD0F0E6EB) )
        {
            Unp->DepAdr=0x100;
            Unp->Forced=0x820;
            Unp->RetAdr=mem[0x8b7]|mem[0x8b8]<<8;
            Unp->StrMem=mem[0x8e2]|mem[0x8e3]<<8;
            Unp->EndAdr=mem[0x8e4]|mem[0x8e5]<<8;Unp->EndAdr++;
            PrintInfo(Unp,_I_RATTPACK);
            Unp->IdFlag=1;return;
        }
    }

    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x820)==0x73BD00A2) &&
           (*(unsigned int*)(mem+0x824)==0x01009D08) &&
           (*(unsigned int*)(mem+0x870)==0x7801004C) &&
           (*(unsigned int*)(mem+0x880)==0xFAE6FC91) )
        {
            Unp->DepAdr=0x100;
            Unp->Forced=0x820;
            Unp->RetAdr=mem[0x904]|mem[0x905]<<8;
            Unp->StrMem=0x10000;
            Unp->EndAdr=0;
            q=0x90a+mem[0x89d]+1;
            for(p=0x90a;p<q;p+=4)
            {
                strtmp=mem[p]|mem[p+1]<<8;
                endtmp=strtmp+(mem[p+2]|mem[p+3]<<8);
                if(endtmp==0)
                    break;
                if(strtmp<Unp->StrMem)
                    Unp->StrMem=strtmp;
                if(endtmp>Unp->EndAdr)
                    Unp->EndAdr=endtmp;
                if(Unp->DebugP)
                {
                    printf("$%04x-$%04x\n",strtmp,endtmp-1);
                }
            }
            PrintInfo(Unp,_I_RATTLINK);
            Unp->IdFlag=1;return;
        }
    }
}
