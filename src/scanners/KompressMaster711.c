/* Kompressmaster/711 crunch, (C)1988? Peter Arndt (see 64'er) */
#include "../unp64.h"
void Scn_KompressMaster711(unpstr *Unp)
{
    unsigned char *mem;
    int q,p,type=0;
    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if( mem[0x80e]==0x78 &&
            (*(unsigned int*)(mem+0x811)==0x990846B9) &&
            ((*(unsigned int*)(mem+0x843)&0xff00ffff)==0x01004CAF))
        {
            for(q=0x8df;q<0x8e2;q++)
            if((*(unsigned int*)(mem+q)==0x90035320)||
               (*(unsigned int*)(mem+q)==0xf0035320) )
            {
                Unp->DepAdr=mem[0x845]|mem[0x846]<<8;
                if( mem[q+3]==0xf0 )
                    type=1;
                break;
            }
            if(Unp->DepAdr)
            {
                if(Unp->info->run == -1)
                    Unp->Forced=0x80e;
                for(p=q+0x4;p<q+0xf;p++)
                {
                    if( mem[p]==0x4c && (*(unsigned int*)(mem+p+4)==0xD0ACE6AC) )
                    {
                        Unp->RetAdr=mem[p+1]|mem[p+2]<<8;
                        break;
                    }
                }
                if(Unp->DepAdr>=0x110 && Unp->RetAdr==0x827)
                {
                    Unp->StrMem=0x100;
                    Unp->EndAdr=0xae;
                    /*, use -s -e$827 on next layer*/
                    PrintInfo(Unp,_I_KOMPSP);
                    Unp->IdFlag=1;return;
                }
                else
                {
                    Unp->StrMem=mem[0x83d]|mem[0x841]<<8;
                    Unp->EndAdr=0xae;
                    if(type==1)
                        PrintInfo(Unp,_I_KOMPBB);
                    else
                        PrintInfo(Unp,_I_KOMP711);
                    Unp->IdFlag=1;return;
                }
            }
        }
    }
    /* unknown 711 pack/special */
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x829)==0x990858B9) &&
            (*(unsigned int*)(mem+0x82e)==0xF7D08801) &&
            (*(unsigned int*)(mem+0x832)==0xAAB504A2) &&
            (*(unsigned int*)(mem+0x836)==0xABD602D0) &&
            (*(unsigned int*)(mem+0x1b3)==0xd0ACE6AC) &&
            (*(unsigned int*)(mem+0x858)==0x01B22001) )
        {
            Unp->DepAdr=mem[0x857]|mem[0x858]<<8;
            Unp->Forced=0x825;
            mem[0x825]=0xe6;
            mem[0x826]=0x01;
            Unp->StrMem=mem[0x84f]|mem[0x853]<<8;
            Unp->EndAdr=0xae;
            for(p=0x880;p<0x882;p++)
            {
                if (mem[p]==0x4c)
                {
                    Unp->RetAdr=mem[p+1]|mem[p+2]<<8;
                    break;
                }
            }
            Unp->FStack=0;
            PrintInfo(Unp,_I_KOMP71PS);
            Unp->IdFlag=1;return;
        }
    }
    /* kompressmaster pack v1 */
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x80e)==0xB93cA078) &&
            (*(unsigned int*)(mem+0x812)==0x87990846) &&
            (*(unsigned int*)(mem+0x843)==0x01884CAF) &&
            (*(unsigned int*)(mem+0x871)==0xACE6ACB1) )
        {
            Unp->DepAdr=0x188;
            if(Unp->info->run == -1)
                Unp->Forced=0x80e;
            Unp->StrMem=mem[0x83d]|mem[0x841]<<8;
            Unp->EndAdr=0xae;
            Unp->RetAdr=mem[0x86f]|mem[0x870]<<8;
            PrintInfo(Unp,_I_KOMP71P1);
            Unp->IdFlag=1;return;
        }
    }
    /* kompressmaster pack v2 */
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x80e)==0xB93dA078) &&
            (*(unsigned int*)(mem+0x812)==0x86990846) &&
            (*(unsigned int*)(mem+0x843)==0x01874CAF) &&
            (*(unsigned int*)(mem+0x872)==0xACE6ACB3) )
        {
            Unp->DepAdr=0x187;
            if(Unp->info->run == -1)
                Unp->Forced=0x80e;
            Unp->StrMem=mem[0x83d]|mem[0x841]<<8;
            Unp->EndAdr=0xae;
            Unp->RetAdr=mem[0x870]|mem[0x871]<<8;
            PrintInfo(Unp,_I_KOMP71P2);
            Unp->IdFlag=1;return;
        }
    }
}
