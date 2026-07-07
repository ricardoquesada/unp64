/* Beta dynamic 3, similar to TimeCruncher 4 */
#include "../unp64.h"
void Scn_BetaDynamic(unpstr *Unp)
{
    unsigned char *mem;
    int q,p=0;
    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if(((*(unsigned int*)(mem+0x80b)==0x847800A0)||
            (*(unsigned int*)(mem+0x80b)==0xe67800A0))  &&
           (*(unsigned int*)(mem+0x80f)==0x081CB901) &&
           (*(unsigned int*)(mem+0x818)==0x01004CF7) &&
           (*(unsigned int*)(mem+0x830)==0x018420F7) )
        {
            Unp->EndAdr=mem[0x81d]|mem[0x81e]<<8;Unp->EndAdr++;
            Unp->DepAdr=0x100;
            Unp->Forced=0x80b;
            Unp->RetAdr=mem[0x8c4]|mem[0x8c5]<<8;
            Unp->fStrAf=0xfc;
            PrintInfo(Unp,_I_BETADYN3);
            Unp->IdFlag=1;return;
        }
        if((*(unsigned int*)(mem+0x80b)==0x8c7800A0) &&
           (*(unsigned int*)(mem+0x812)==0x081fB901) &&
           (*(unsigned int*)(mem+0x81b)==0x01004CF7) &&
           (*(unsigned int*)(mem+0x833)==0x018420F7) && (mem[0x8d5]==0x4c))
        {
            Unp->EndAdr=mem[0x820]|mem[0x821]<<8;Unp->EndAdr++;
            Unp->DepAdr=0x100;
            Unp->Forced=0x80b;
            Unp->RetAdr=mem[0x8d6]|mem[0x8d7]<<8;
            Unp->fStrAf=0xfc;
            PrintInfo(Unp,_I_BETADYN3FX);
            Unp->IdFlag=1;return;
        }
        if((*(unsigned int*)(mem+0x80b)==0x207800A0) &&
           (*(unsigned int*)(mem+0x812)==0x081fB901) &&
           (*(unsigned int*)(mem+0x81b)==0x01004CF7) &&
           (*(unsigned int*)(mem+0x833)==0x018420F7) && (mem[0x8cd]==0x4c))
        {
            Unp->EndAdr=mem[0x820]|mem[0x821]<<8;Unp->EndAdr++;
            Unp->DepAdr=0x100;
            Unp->Forced=0x80b;
            Unp->RetAdr=mem[0x8ce]|mem[0x8cf]<<8;
            Unp->fStrAf=0xfc;
            PrintInfo(Unp,_I_BETADYN3CCS);
            Unp->IdFlag=1;return;
        }
    }
    /* Beta 2x / Betaskip */
    if( Unp->DepAdr==0 )
    {
        //for(q=0x080b;q<0x811;q+=5)
        for(q=Unp->info->start;q<Unp->info->start+0x12;q++)
        {
            if(mem[q]==0xa0 && mem[q+1]==0 && mem[q+5]==0x4c)
            {
                p=mem[q+6]|mem[q+7]<<8;
                if(mem[p     ]==0xc0 && mem[p+0x02]==0xb0 &&
                   mem[p+0x0a]==0xc0 && mem[p+0x0c]==0xb0 &&
                   mem[p+0x1d]==0x4c )
                {
                    Unp->DepAdr=mem[p+0x1e]|mem[p+0x1f]<<8;
                    Unp->Forced=q;
                    q=mem[p+0xf]|mem[p+0x10]<<8;
                    break;
                }
            }
        }
        if(Unp->DepAdr)
        {
            Unp->EndAdr=mem[q+3]|mem[q+4]<<8;/*Unp->EndAdr++;*/
            Unp->fStrAf=mem[p+0x12]+3;Unp->StrAdC=0xffff;
            for(p=q+0xfa;p<q+0x103;p++)
            {
                if(mem[p]==0x4c)
                {
                    Unp->RetAdr=mem[p+1]|mem[p+2]<<8;
                    break;
                }
            }
            PrintInfo(Unp,_I_BETADYN2);
            Unp->IdFlag=1;return;
        }
    }
}
