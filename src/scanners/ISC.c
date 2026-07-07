/*
INTELLIGENT SCYP COMPRESSOR V2.0
ISC 2.0 - VERSION 8/4/87 - BY JOERG BUBLATH
*/
#include "../unp64.h"
void Scn_ISC(unpstr *Unp)
{
    unsigned char *mem;
    int q,p;
    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x81b)==0x24CEAFC6) &&
            (*(unsigned int*)(mem+0x81f)==0x99AEB108) &&
            (*(unsigned int*)(mem+0x823)==0xD0880000) &&
            (*(unsigned int*)(mem+0x8a7)==0x4A4A4A4A) &&
            (*(unsigned int*)(mem+0x90a)==0x0A0A0A0A) )
        {
            Unp->DepAdr=0x139;
            Unp->StrMem=mem[0x851]|mem[0x852]<<8;
            //Unp->EndAdr=mem[0x84f]|mem[0x850]<<8;
            Unp->EndAdr=0xae;
            if(Unp->info->run == -1)
            {
                for(p=0x80d;p<0x820;p++)
                {
                    if(mem[p]==0x78)
                    {
                        Unp->Forced=p;
                        break;
                    }
                }
            }
            for(p=0x8c4;p<0x8ca;p++)
            {
                if(mem[p]==0x4c)
                {
                    Unp->RetAdr=mem[p+1]|mem[p+2]<<8;
                    break;
                }
            }
            PrintInfo(Unp,_I_ISCN);
            Unp->IdFlag=1;return;
        }
    }
    /* ISC Pack */
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x811)==0x8538A978) &&
            (*(unsigned int*)(mem+0x815)==0x9AFDA201) &&
            (*(unsigned int*)(mem+0x83d)==0x00F59908) &&
            (*(unsigned int*)(mem+0x859)==0x4A4A4A4A) &&
            (*(unsigned int*)(mem+0x85d)==0xF8B5AA4A) &&
            (*(unsigned int*)(mem+0x885)==0x7E200190) )
        {
            if(Unp->info->run == -1)
            {
                Unp->Forced=0x811;
            }
            Unp->DepAdr=0x100;
            Unp->StrMem=mem[0x845]|mem[0x849]<<8;
            Unp->EndAdr=0xae;
            Unp->RetAdr=mem[0x882]|mem[0x883]<<8;
            PrintInfo(Unp,_I_ISCP);
            Unp->IdFlag=1;return;
        }
    }
    /* ISC Bitstream */
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x817)==0x018538A9) &&
            (*(unsigned int*)(mem+0x81b)==0xA09AFDA2) &&
            (*(unsigned int*)(mem+0x89b)==0x662003D0) &&
            (*(unsigned int*)(mem+0x8cb)==0xC6606085) )
        {
            for(q=0,p=0x8d0;p<0x8db;p+=1)
            {
                if(mem[p]==0x4c )
                {
                    q=p;
                    break;
                }
            }
            if(q)
            {
                if(Unp->info->run == -1)
                {
                    Unp->Forced=0x817;
                }
                Unp->DepAdr=0xfc;
                Unp->fStrBf=0xae; /* seems fixed? */
                Unp->EndAdr=0xae;
                Unp->RetAdr=mem[q+1]|mem[q+2]<<8;
                PrintInfo(Unp,_I_ISCBS);
                Unp->IdFlag=1;return;
            }
        }
    }
}
