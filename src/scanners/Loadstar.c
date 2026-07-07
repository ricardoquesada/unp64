/* Loadstar ModLinker by Malakai */
#include "../unp64.h"
void Scn_Loadstar(unpstr *Unp)
{
    unsigned char *mem;
    int p,strtmp,endtmp;
    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x829)==0xA9082C4C) &&
           (*(unsigned int*)(mem+0x82d)==0xA9048500) &&
           (*(unsigned int*)(mem+0x873)==0xD002A5FC) &&
           (*(unsigned int*)(mem+0x883)==0x085F4C02) )
        {
            Unp->DepAdr=0x100;
            if(Unp->info->run == -1)
                Unp->Forced=0x829;
            Unp->RetAdr=mem[0x8e8]|mem[0x8e9]<<8;
            Unp->StrMem=0x10000;
            Unp->EndAdr=0;
            for(p=0;p<mem[0x8ef];p++) /* max 5 ml parts */
            {
                strtmp=mem[0x8fa+(p*2)]|mem[0x8fa+(p*2)+1]<<8;
                endtmp=strtmp+(mem[0x8f0+(p*2)]|mem[0x8f0+(p*2)+1]<<8);
                if(endtmp==0)
                    endtmp=0x10000;
                if(strtmp<Unp->StrMem)
                    Unp->StrMem=strtmp;
                if(endtmp>Unp->EndAdr)
                    Unp->EndAdr=endtmp;
                if(Unp->DebugP)
                {
                    printf("$%04x-$%04x\n",strtmp,endtmp-1);
                }
            }
            /* last part str=$0801, always basic, len at $08ed/e */
            strtmp=0x0801;
            if(strtmp<Unp->StrMem)
                Unp->StrMem=strtmp;
            endtmp=strtmp+(mem[0x8ed]|mem[0x8ee]<<8)+1;;
            if(endtmp>Unp->EndAdr)
                Unp->EndAdr=endtmp;
            if(Unp->DebugP)
            {
                printf("$%04x-$%04x\n",strtmp,endtmp-1);
            }
            PrintInfo(Unp,_I_LSMODL);
            Unp->IdFlag=1;return;
        }
    }
    /* found in loadstar 236-250, .pkd in filenames */
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x80d)==0x8500A978) &&
           (*(unsigned int*)(mem+0x811)==0x8508A97A) &&
           (*(unsigned int*)(mem+0x821)==0x84318630) &&
           (*(unsigned int*)(mem+0x8e8)==0x4a4a4a4a) )
        {
            Unp->DepAdr=0x100; /* actually is at $fe00 but JMP $100 at end */
            if(Unp->info->run == -1)
                Unp->Forced=0x80d;
            Unp->StrMem=mem[0x859]|mem[0x85a]<<8;
            Unp->EndAdr=0xfb;
            Unp->RetAdr=0xa7ae;
            PrintInfo(Unp,_I_LSPACK);
            Unp->IdFlag=1;return;
        }
    }
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x80d)==0xA000A278) &&
           (*(unsigned int*)(mem+0x812)==0x7B847A86) &&
           (*(unsigned int*)(mem+0x860)==0xD006C0C8) &&
           (*(unsigned int*)(mem+0x870)==0xFAE6F9D0) )
        {
            Unp->DepAdr=0x100;
            if(Unp->info->run == -1)
                Unp->Forced=0x80d;
            Unp->StrMem=mem[0x894]|mem[0x895]<<8;
            Unp->EndAdr=0xfb;
            Unp->EndAdC=/*0xffff|*/EA_USE_Y;
            Unp->RetAdr=0xa7ae;
            PrintInfo(Unp,_I_LSLNK2);
            Unp->IdFlag=1;return;
        }
    }
    if( Unp->DepAdr==0 ) /* starlinked */
    {
        if((*(unsigned int*)(mem+0x829)==0x8574A978) &&
           (*(unsigned int*)(mem+0x899)==0x00A0D0F2) &&
           (*(unsigned int*)(mem+0x8d3)==0x027B4C7B) &&
           (*(unsigned int*)(mem+0x95F)==0x60DBD022) )
        {
            Unp->DepAdr=0x027b;
            if(Unp->info->run == -1)
                Unp->Forced=0x829;
            Unp->StrMem=mem[0x855]|mem[0x859]<<8;
            Unp->MonEnd=0x00bc<<16|0x00bb;
            Unp->RetAdr=0xa7ae;
            PrintInfo(Unp,_I_LSSTLNK);
            Unp->IdFlag=1;return;
        }
    }

}

