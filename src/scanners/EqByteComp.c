/* equal byte comp */
#include "../unp64.h"
void Scn_EqByteComp(unpstr *Unp)
{
    unsigned char *mem;
    int q,p;
    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    /* EBC 1.4/FLT */
    if( Unp->DepAdr==0 )
    {
        p=Unp->info->run;
        if(p!=0x80b)
            p=Unp->info->start;
        for(q=p+0x10;p<q;p++)
        {
            if( (*(unsigned int*)(mem+p     )==0x867800A2) &&
                (*(unsigned int*)(mem+p+0x08)==0xE800F99D) &&
                (*(unsigned int*)(mem+p+0x0d)==0x01484CF7) &&
                (*(unsigned int*)(mem+p+0x72)==0xE8EDD088) )
            {
                Unp->DepAdr=0x148;
                break;
            }
        }
        if( Unp->DepAdr )
        {
            Unp->Forced=p;
            Unp->RetAdr=mem[p+0x3a]|mem[p+0x3b]<<8;
            Unp->StrMem=mem[p+0x13]|mem[p+0x14]<<8;
            Unp->EndAdr=0xfb;
            PrintInfo(Unp,_I_EQBYTEC14);
            Unp->IdFlag=1;return;
        }
    }
    /*
    EBC 1.2 SOMA 1987
    ATT x-code(reu), can be sysless or $812 and even loadback
    found some variants in Trianon/Savage cracks
    */
    if( Unp->DepAdr==0 )
    {
        p=0;
        for(q=Unp->info->start;q<=Unp->info->start+0x12;q++)
        {
            if((((*(unsigned int*)(mem+q+0x00))==0x8600A278)||
                ((*(unsigned int*)(mem+q+0x00))==0x867800A2)) &&
                (*(unsigned short int*)(mem+q+0x04)==0xbd01) &&
                (*(unsigned short int*)(mem+q+0x06)==q+0x11) &&
                (*(unsigned int*)(mem+q+0x08)==0xE800F99D) &&
                (*(unsigned int*)(mem+q+0x20)==0xFBE6FB91) &&
                (*(unsigned int*)(mem+q+0x30)==0xE1D0FFE6) )
            {
                p=mem[q+0x0f]|mem[q+0x10]<<8;
                break;
            }
        }
        if(p)
        {
            Unp->DepAdr=p;
            Unp->Forced=q;
            switch(p)
            {
            case 0x14c:
                Unp->RetAdr=mem[q+0x3d]|mem[q+0x3e]<<8;
                break;
            case 0x15b:
                Unp->RetAdr=mem[q+0x49]|mem[q+0x4a]<<8;
                break;
            case 0x15c:
                Unp->RetAdr=mem[q+0x4a]|mem[q+0x4b]<<8;
                break;
            }
            Unp->StrMem=mem[q+0x13]|mem[q+0x14]<<8;
            Unp->fEndAf=0xfb;
            PrintInfo(Unp,_I_EQBYTEC12);
            Unp->IdFlag=1;return;
        }
    }
    /* Eq Byte Compressor 1.7 QED/3532, found in some FLT and ESM warez
       can have a sys2059, but often sysless at $801 and even "loadback"
       for example 3rd layer of "SPHEREON+3  _FLT.prg.0801.1200"
    */
    if( Unp->DepAdr==0 )
    {
        p=0;
        //for(q=0x801;q<0x80c;q++)
        for(q=Unp->info->start;q<Unp->info->start+0x0d;q++)
        {
            if((*(unsigned int*)(mem+q     )==0x867800A2) &&
               (*(unsigned int*)(mem+q+0x08)==0xE800F89D) &&
               (*(unsigned int*)(mem+q+0x22)==0x00FD4CE8) )
            {
                for(p=q+0x53;p<q+0x55;p++)
                {
                    if((mem[p]==0x4c)&&(*(unsigned int*)(mem+p+3)==0x02D0FEE6))
                    {
                        Unp->DepAdr=0xfd;
                        break;
                    }
                }
                if(Unp->DepAdr) break;
            }
        }
        if(Unp->DepAdr)
        {
            if(Unp->info->run==-1)
            {
                Unp->Forced=q;
            }
            Unp->RetAdr=mem[p+1]|mem[p+2]<<8;
            Unp->StrMem= mem[q+0x29]|mem[q+0x2a]<<8;
            Unp->EndAdr=0xfb;
            PrintInfo(Unp,_I_EQBYTEC17);
            Unp->IdFlag=1;return;
        }
    }
    /* v1.9 mostly found in FLT and L+T cracks, similar to XTC packer */
    if( Unp->DepAdr==0 )
    {
        for(q=Unp->info->start;q<Unp->info->start+0x0c;q++)
        {
            if( (*(unsigned int*)(mem+q+0x00)==0x867800A2) &&
                (*(unsigned int*)(mem+q+0x08)==0xE800F89D) &&
                (*(unsigned int*)(mem+q+0x22)==0x01074CE8) &&
                (*(unsigned int*)(mem+q+0x71)==0x01184C00) )
            {
                Unp->DepAdr=0x107;
                break;
            }
        }
        if(Unp->DepAdr)
        {
            Unp->Forced=q;
            Unp->RetAdr=mem[q+0x5d]|mem[q+0x5e]<<8;
            Unp->EndAdr=0xfb;
            Unp->StrMem=mem[q+0x29]|mem[q+0x2a]<<8;
            PrintInfo(Unp,_I_EQBYTEC19);
            Unp->IdFlag=1;return;
        }
    }
    /* probably another Rockstar hack, found in Talent Warez, 4codes */
    if( Unp->DepAdr==0 )
    {
        for(q=Unp->info->start;q<Unp->info->start+0x0c;q++)
        {
            if( (*(unsigned int*)(mem+q+0x00)==0x847800A0) &&
                (*(unsigned int*)(mem+q+0x08)==0xB9FF0099) &&
                (*(unsigned int*)(mem+q+0x0c)==0xF9990820) &&
                (*(unsigned int*)(mem+q+0x71)==0x00FD20D0) )
            {
                Unp->DepAdr=0x107;
                break;
            }
        }
        if(Unp->DepAdr)
        {
            Unp->Forced=q;
            Unp->RetAdr=mem[q+0x58]|mem[q+0x59]<<8;
            Unp->fEndAf=0x11d;
            Unp->EndAdC=0xffff|EA_USE_Y;
            Unp->StrMem=mem[q+0x43]|mem[q+0x44]<<8;
            PrintInfo(Unp,_I_EQBYTEC19TAL);
            Unp->IdFlag=1;return;
        }
    }
}
