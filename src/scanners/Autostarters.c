/* autostarers */
#include "../unp64.h"
void Scn_Autostarters(unpstr *Unp)
{
    unsigned char *mem;
    int p,q;
    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if(Unp->info->run == -1)
    {
        if(Unp->info->start == 0x2a4 )
        {
            if( (*(unsigned int*)(mem+0x2a4)==0x58FD1520) &&
                (*(unsigned int*)(mem+0x2d8)==0xEA4A4ADD) &&
                (*(unsigned int*)(mem+0x39c)==0xA9EB224C) )
            {
                Unp->DepAdr=0x2bb;
                Unp->Forced=Unp->DepAdr;
                p=0x2bf;
                Unp->RetAdr=mem[p]|mem[p+1]<<8;
                p=0x3a0;
                Unp->StrMem=mem[p]|mem[p+1]<<8;
                p+=2;
                Unp->EndAdr=Unp->info->end-p;
                memmove(mem+Unp->StrMem,mem+p,Unp->EndAdr);
                Unp->EndAdr+=Unp->StrMem;
                PrintInfo(Unp,_I_64ERAUTO);
                Unp->IdFlag=1;return;
            }
        }
        if(Unp->info->start == 0x2a8 )
        {
            if( (*(unsigned int*)(mem+0x2a8)==0xA4EE1320) &&
                (*(unsigned int*)(mem+0x2ac)==0x7817D090) &&
                (*(unsigned int*)(mem+0x2c4)==0x299802A8) )
            {
                /* normal kernal loads until load vector $330 is overwritten
                   with $2ed, then the routine at $2ed takes control:
                   checks $ae for $34 or $68 (thus loading upto $334 or $368)
                   then changes ae/$af to the new destination. Loads all RAM
                   TODO:
                   $68 should actually split in 2 prgs because loads 1st a
                   pic and executes it, then loads again at $0801 the real game.
                */
                for(p=0x2e9;p<0x2eb;p++)
                {
                    if(mem[p]==0x4c)
                    {
                        Unp->DepAdr=p;
                        break;
                    }
                }
                Unp->Forced=Unp->DepAdr;
                Unp->RetAdr=mem[p+1]|mem[p+2]<<8;
                q=mem[0x2f0];
                if(q==0x68)
                    Unp->StrMem=mem[0x344]|mem[0x348]<<8;
                else
                    Unp->StrMem=mem[0x2f5]|mem[0x2f9]<<8;
                p=Unp->info->end-(0x300+q);
                memmove(mem+Unp->StrMem,mem+0x300+q,p);
                Unp->EndAdr=p+Unp->StrMem;
                PrintInfo(Unp,_I_GCSAUTO);
                Unp->IdFlag=1;return;
            }
        }
        if(Unp->info->start == 0x2e4 )
        {
            if( (*(unsigned int*)(mem+0x2e4)==0x20E54420) &&
                (*(unsigned int*)(mem+0x2e8)==0xA94CFC93) &&
                (*(unsigned int*)(mem+0x2f0)==0x8DF9A9AE) )
            {
                Unp->DepAdr=0x2ed;
                Unp->Forced=Unp->DepAdr;
                Unp->RetAdr=0xa7ae;
                if (mem[0x37c]==0xa5)
                {
                    Unp->StrMem=mem[mem[0x37d]]|mem[mem[0x381]]<<8;
                    if(Unp->StrMem==0)
                        if(mem[0x37d]==0x2b)
                            Unp->StrMem=0x801;
                }
                else
                {
                    Unp->StrMem=mem[0x37d]|mem[0x381]<<8;
                }
                p=Unp->info->end-0x4de;
                memmove(mem+Unp->StrMem,mem+0x4de,p);
                Unp->EndAdr=p+Unp->StrMem;
                PrintInfo(Unp,_I_AUTOFLG);
                Unp->IdFlag=1;return;
            }
        }
        if(Unp->info->start == 0x2B8 )
        {
            if( (*(unsigned int*)(mem+0x2b8)==0x99EE1320) &&
                (*(unsigned int*)(mem+0x2bc)==0xC0C80200) &&
                (*(unsigned int*)(mem+0x2c8)==0xA9ED0C20) &&
                (*(unsigned int*)(mem+0x2cc)==0xEDB9206F) )
            {
                Unp->DepAdr=0x4d4;
                Unp->Forced=Unp->DepAdr;
                p=mem[0x1296]|mem[0x1297]<<8;
                Unp->StrMem=mem[0x1298]|mem[0x1299]<<8;
                memmove(mem+Unp->StrMem,mem+0x129a,p);
                Unp->EndAdr=p+Unp->StrMem;
                Unp->RetAdr=mem[0x4d8]|mem[0x4d9]<<8;
                PrintInfo(Unp,_I_BETASKIP);
                Unp->IdFlag=1;return;
            }
        }
    }
}
