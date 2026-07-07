/* Marauder cruncher and hacks */
#include "../unp64.h"
void Scn_MRD(unpstr *Unp)
{
    unsigned char *mem;
    int p;
    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x844)==0xFB8500A9) &&
            (*(unsigned int*)(mem+0x84f)==0xA0FE86FD) &&
            (*(unsigned int*)(mem+0x853)==0xB104F000) &&
            (*(unsigned int*)(mem+0x883)==0x20033C4C) )
        {
            Unp->DepAdr=0x33c;
            Unp->EndAdr=mem[0x880];
            Unp->StrMem=mem[0x90d]|mem[0x90e]<<8;
            if(Unp->info->run == -1 )
            {
                for(p=0x80d;p<0x840;p++)
                {
                    if(mem[p]==0x78)
                    {
                        Unp->Forced=p;
                    }
                }
                if(Unp->Forced==0)
                    Unp->Forced=0x834;
            }
            if((mem[0x887]==0x68) && (mem[0x8e0]==0x4c))
            {
                Unp->RetAdr=mem[0x8e1]|mem[0x8e2]<<8;
                PrintInfo(Unp,_I_MRDCR1);
            }
            else if((mem[0x887]==0x6c))
            {
                Unp->RetAdr=mem[0x8d7]|mem[0x8d8]<<8;
                PrintInfo(Unp,_I_MRDCRCOD1);
            }
            Unp->IdFlag=1;return;
        }
    }
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x827)==0x9D0855BD) &&
            (*(unsigned int*)(mem+0x82b)==0xD0E800FA) &&
            (*(unsigned int*)(mem+0x834)==0x8600A278) &&
            (*(unsigned int*)(mem+0x8cf)==0xB901D64C) )
        {
            Unp->DepAdr=0x1d6;
            Unp->EndAdr=0xfa;
            Unp->StrMem=mem[0x855]|mem[0x856]<<8;
            Unp->RetAdr=mem[0x8ee]|mem[0x8ef]<<8;
            if(Unp->info->run == -1 )
                Unp->Forced=0x834;
            PrintInfo(Unp,_I_MRDLNK2);
            Unp->IdFlag=1;return;
        }
    }
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x834)==0x00BD00A2) &&
            (*(unsigned int*)(mem+0x838)==0x04009D08) &&
            (*(unsigned int*)(mem+0x863)==0x490800BD) &&
            (*(unsigned int*)(mem+0x87b)==0xA904614C) )
        {
            Unp->DepAdr=0x442;
            Unp->EndAdr=mem[0x881]; /*$2d*/
            Unp->StrMem=0x801;
            if((*(unsigned int*)(mem+0x88e)==0x20e3bf20) )
                mem[0x88e]=0x2c;
            Unp->RetAdr=mem[0x892]|mem[0x893]<<8;
            if(Unp->info->run == -1 )
                Unp->Forced=0x834;
            PrintInfo(Unp,_I_GSSCO12);
            Unp->IdFlag=1;return;
        }
    }
}
