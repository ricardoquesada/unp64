/* MCCrackenCompressor */
#include "../unp64.h"
void Scn_MCCrackenComp(unpstr *Unp)
{
    unsigned char *mem;
    int p,q;
    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        for(p=0x810;p<0x840;p++)
        {
            if(mem[p]==0xa9 && mem[p+2]==0x85 &&
              (*(unsigned int*)(mem+p+0x04)==0xAFC600A0) &&
              (*(unsigned int*)(mem+p+0x2a)==0xFFA2F8D0) &&
              (*(unsigned int*)(mem+p+0x2e)==0x01004C9A) &&
              (*(unsigned int*)(mem+p+0x3f)==0x2a2a2a2a) )
            {
                Unp->DepAdr=0x100;
                Unp->EndAdr=0xae;
                Unp->StrMem=mem[p+0x32]|mem[p+0x33]<<8;
                if (mem[p+0x61]==0x4c)
                {
                    Unp->RetAdr=mem[p+0x62]|mem[p+0x63]<<8;
                    if((Unp->RetAdr == 0x1b7)&&
                       (*(unsigned int*)(mem+p+0xed)==0x4CA65920) )
                    {
                        Unp->RetAdr=0xa7ae;
                        mem[p+0x62]=0xae;
                        mem[p+0x63]=0xa7;
                    }
                    PrintInfo(Unp,_I_MCCCOMP);
                    if(Unp->info->run == -1 )
                    {
                        Unp->Forced=p;
                        while(--p>=0x810)
                        {
                            if(mem[p]==0x78)
                            {
                                Unp->Forced=p;
                            }
                        }
                    }
                }
                else if( (mem[p+0x60]==0x4c)/* &&(mem[p+0x108]==0x4c)*/)
                {
                    Unp->Forced=0x828;
                    if (mem[p+0x108]==0x4c)
                    {
                        Unp->RetAdr=mem[p+0x109]|mem[p+0x10a]<<8;
                        PrintInfo(Unp,_I_MCTSS3);
                    }
                    else if( (mem[p+0xff]==0x4c) && (mem[p+0x100]==0xab) )
                    {
                        Unp->RetAdr=0x5ab;
                        PrintInfo(Unp,_I_MCTSSIP);
                    }
                    else
                    {
                        PrintInfo(Unp,_I_MCUNK);
                    }
                }
                break;
            }
        }
    }
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x828)==0x8534A978) &&
           (*(unsigned int*)(mem+0x82c)==0xC600A001) &&
           (*(unsigned int*)(mem+0x830)==0x0838CE2E) &&
           (*(unsigned int*)(mem+0x834)==0x00992DB1) &&
           (*(unsigned int*)(mem+0x908)==0x2001364C) )
        {
            Unp->DepAdr=0x100;
            Unp->EndAdr=0xae;
            Unp->RetAdr=mem[0x88b]|mem[0x88c]<<8;
            Unp->StrMem=mem[0x85b]|mem[0x85c]<<8;
            Unp->Forced=0x828;
            PrintInfo(Unp,_I_MCCRUSH3);
            Unp->IdFlag=1;return;
        }
    }
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x828)==0x8534A978) &&
           (*(unsigned int*)(mem+0x82c)==0xC600A001) &&
           (*(unsigned int*)(mem+0x830)==0x0838CEaf) &&
           (*(unsigned int*)(mem+0x834)==0x0099aeB1) &&
           (*(unsigned int*)(mem+0x908)==0x2001364C) )
        {
            Unp->DepAdr=0x100;
            Unp->EndAdr=0xae;
            Unp->RetAdr=mem[0x88b]|mem[0x88c]<<8;
            Unp->StrMem=mem[0x85b]|mem[0x85c]<<8;
            if(Unp->info->run==-1)
                Unp->Forced=0x813;
            PrintInfo(Unp,_I_MCCOBRA);
            Unp->IdFlag=1;return;
        }
    }
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x812)==0xA201E678) &&
           (*(unsigned int*)(mem+0x816)==0x0840BD06) &&
           (*(unsigned int*)(mem+0x81a)==0x10CAAB95) &&
           (*(unsigned int*)(mem+0x81e)==0x00A09AF8) &&
           (*(unsigned int*)(mem+0x8f0)==0x2001364C) )
        {
            Unp->DepAdr=0x100;
            Unp->EndAdr=0xae;
            Unp->RetAdr=mem[0x873]|mem[0x874]<<8;
            Unp->StrMem=mem[0x843]|mem[0x844]<<8;
            if(Unp->info->run==-1)
                Unp->Forced=0x812;
            PrintInfo(Unp,_I_MCCSCC);
            Unp->IdFlag=1;return;
        }
    }
    /* substantially a normal MCC + crypted data from $916 */
    if( Unp->DepAdr==0 )
    {
        if(((*(unsigned int*)(mem+0x80e)&0xffff00ff)==0xAE8500A9) &&
           (*(unsigned int*)(mem+0x81a)==0x9816A001) &&
           (*(unsigned int*)(mem+0x81e)==0x99090059) &&
           (*(unsigned int*)(mem+0x86a)==0x07292A2A) &&
           (*(unsigned int*)(mem+0x908)==0x2001364C) )
        {
            /* patch deprypter and already xor data upto eof
               so unused memory won't be filled with a sequential pattern
            */
            mem[0x81c]=0x00;
            mem[0x81e]=0x4c;
            mem[0x81f]=0x2f;
            mem[0x820]=0x08;
            p=mem[0x80f]|mem[0x813]<<8;
            q=0x916;
            for(q=0x916;q<p;q++)
                mem[q]^=(q&0xff);

            Unp->DepAdr=0x100;
            Unp->EndAdr=0xae;
            Unp->RetAdr=mem[0x88b]|mem[0x88c]<<8;
            Unp->StrMem=mem[0x85b]|mem[0x85c]<<8;
            Unp->Forced=0x80e;
            PrintInfo(Unp,_I_MCCRYPT);
            Unp->IdFlag=1;return;
        }
    }
    if(Unp->DepAdr)
    {
        Unp->IdFlag=1;return;
    }
}
