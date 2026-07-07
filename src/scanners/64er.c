/*
64er crunchers&packers, and similar ones
found as 64'er Packer and as Happy Packer (C)1987 Peter Arndt,
cartridge only packer systems.

according to this site also Kompressmaster is from the same author.
http://www.stcarchiv.de/hc1988/07_progkarriere.php

note: most versions are COMPLETELY made up =)
*/
#include "../unp64.h"
void Scn_64er(unpstr *Unp)
{
    unsigned char *mem;
    int /*q,*/p;
    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x17a)==0xACE6ACB3) && (mem[0x827]==0xa0) &&
           (*(unsigned int*)(mem+0x829)==0x99085AB9) &&
           (*(unsigned int*)(mem+0x82f)==0xA5F7D088) &&
           (*(unsigned int*)(mem+0x861)==0xA5015F20) )
        {
            Unp->FStack=0;
            Unp->DepAdr=mem[0x859]|mem[0x85a]<<8;
            mem[0x825]=0x85;
            mem[0x826]=0x01;
            Unp->Forced=0x825;
            Unp->StrMem=mem[0x851]|mem[0x855]<<8;
            Unp->EndAdr=0xae;
            if(Unp->DepAdr==0x114)
            {
                Unp->RetAdr=mem[0x876]|mem[0x877]<<8;
                PrintInfo(Unp,_I_64ER_SP22);
            }
            else if(Unp->DepAdr==0x11c)
            {
                Unp->RetAdr=mem[0x86e]|mem[0x86f]<<8;
                PrintInfo(Unp,_I_64ER_SP23);
            }
            else
            {
                for(p=0x860;p<0x880;p++)
                {
                    if((mem[p]==0x4c) &&
                       (*(unsigned int*)(mem+p+2)==0x20017C20) )
                    {
                        Unp->RetAdr=mem[p+1]|mem[p+2]<<8;
                        break;
                    }
                }
                PrintInfo(Unp,_I_64ER_SP2U);
            }
            Unp->IdFlag=1;return;
        }
    }
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x1b2)==0xACE6ACB3) && (mem[0x827]==0xa0) &&
           (*(unsigned int*)(mem+0x829)==0x990858B9) &&
           (*(unsigned int*)(mem+0x82f)==0xA2F7D088) &&
           (*(unsigned int*)(mem+0x85f)==0xA5019720) )
        {
            Unp->FStack=0;
            Unp->DepAdr=mem[0x857]|mem[0x858]<<8;
            mem[0x825]=0x85;
            mem[0x826]=0x01;
            Unp->Forced=0x825;
            Unp->StrMem=mem[0x84f]|mem[0x853]<<8;
            Unp->EndAdr=0xae;
            if(Unp->DepAdr==0x14b)
            {
                Unp->RetAdr=mem[0x875]|mem[0x876]<<8;
                PrintInfo(Unp,_I_64ER_SP12);
            }
            else if(Unp->DepAdr==0x154)
            {
                Unp->RetAdr=mem[0x86c]|mem[0x86d]<<8;
                PrintInfo(Unp,_I_64ER_SP13);
            }
            else if(Unp->DepAdr==0x14c)
            {
                Unp->RetAdr=mem[0x874]|mem[0x875]<<8;
                PrintInfo(Unp,_I_64ER_SP14);
            }
            else if(Unp->DepAdr==0x156)
            {
                Unp->RetAdr=mem[0x86a]|mem[0x86b]<<8;
                PrintInfo(Unp,_I_64ER_SP15);
            }
            else
            {
                for(p=0x860;p<0x880;p++)
                {
                    if((mem[p]==0x4c) &&
                       (*(unsigned int*)(mem+p+2)==0x2001b420) )
                    {
                        Unp->RetAdr=mem[p+1]|mem[p+2]<<8;
                        break;
                    }
                }
                PrintInfo(Unp,_I_64ER_SP1U);
            }
            Unp->IdFlag=1;return;
        }
    }
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x80f)==0xA48401A0) &&
           (*(unsigned int*)(mem+0x813)==0x84AC8488) &&
           (*(unsigned int*)(mem+0x81f)==0xA2ACC6AD) &&
           (*(unsigned int*)(mem+0x823)==0x85FFA901) )
        {
            Unp->DepAdr=mem[0x8ae]|mem[0x8af]<<8;
            if(Unp->info->run == -1 )
                Unp->Forced=0x80f;
            Unp->StrMem=mem[0x8a6]|mem[0x8aa]<<8;
            Unp->RetAdr=Unp->StrMem;// todo, it's encrypted in different ways??
            Unp->EndAdr=0xae;
            if(Unp->StrMem==0x827)
            {
                PrintInfo(Unp,_I_64ERBITP1);
                Unp->StrMem=0x0100;
            }
            else
            {
                PrintInfo(Unp,_I_64ERBITP);
                /* happypacker/bitkompress 2.2
                   64er/bitkompress 3.2        */
            }
            Unp->IdFlag=1;return;
        }
    }
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x80f)==0x46B970A0) &&
           (*(unsigned int*)(mem+0x813)==0x01539908) &&
           (*(unsigned int*)(mem+0x81f)==0xB504A2AD) &&
           (*(unsigned int*)(mem+0x843)==0x01544CAF) )
        {
            Unp->DepAdr=0x154;
            if(Unp->info->run== -1 )
                Unp->Forced=0x80f;
            Unp->StrMem=mem[0x83d]|mem[0x841]<<8;
            Unp->RetAdr=mem[0x85a]|mem[0x85b]<<8;
            Unp->EndAdr=0xae;
            PrintInfo(Unp,_I_64ERS41A); /* 64erpacker/eqseq 4.1A */
            Unp->IdFlag=1;return;
        }
    }
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x80f)==0x46B978A0) &&
           (*(unsigned int*)(mem+0x813)==0x014B9908) &&
           (*(unsigned int*)(mem+0x81f)==0xB504A2AD) &&
           (*(unsigned int*)(mem+0x843)==0x014C4CAF) )
        {
            Unp->DepAdr=0x14c;
            if(Unp->info->run == -1 )
                Unp->Forced=0x80f;
            Unp->StrMem=mem[0x83d]|mem[0x841]<<8;
            Unp->RetAdr=mem[0x862]|mem[0x863]<<8;
            Unp->EndAdr=0xae;
            PrintInfo(Unp,_I_64ERS41B); /* 64erpacker/eqseq 4.1B */
            Unp->IdFlag=1;return;
        }
    }
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x80f)==0x46B979A0) &&
           (*(unsigned int*)(mem+0x813)==0x014A9908) &&
           (*(unsigned int*)(mem+0x81f)==0xB504A2AD) &&
           (*(unsigned int*)(mem+0x843)==0x014b4CAF) )
        {
            Unp->DepAdr=0x14b;
            if(Unp->info->run== -1 )
                Unp->Forced=0x80f;
            Unp->StrMem=mem[0x83d]|mem[0x841]<<8;
            Unp->RetAdr=mem[0x85f]|mem[0x860]<<8;
            Unp->EndAdr=0xae;
            PrintInfo(Unp,_I_64ERS41C); /* 64erpacker/eqseq 4.1C */
            Unp->IdFlag=1;return;
        }
    }
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x80f)==0x46B9B3A0) &&
           (*(unsigned int*)(mem+0x813)==0x01109908) &&
           (*(unsigned int*)(mem+0x81f)==0xB504A2AD) &&
           (*(unsigned int*)(mem+0x843)==0x01114CAF) )
        {
            Unp->DepAdr=0x111;
            if(Unp->info->run== -1 )
                Unp->Forced=0x80f;
            Unp->StrMem=mem[0x83d]|mem[0x841]<<8;
            Unp->RetAdr=mem[0x8c6]|mem[0x8c7]<<8;
            Unp->EndAdr=0xae;
            if((Unp->StrMem==0x827)&&(Unp->RetAdr==0x827))
            {
                Unp->StrMem=0x0100;
            }
            PrintInfo(Unp,_I_64ERS40A);  /* 64er seq II 4.0 A */
            Unp->IdFlag=1;return;
        }
    }
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x80f)==0x46B998A0) &&
           (*(unsigned int*)(mem+0x813)==0x012B9908) &&
           (*(unsigned int*)(mem+0x81f)==0xB504A2AD) &&
           (*(unsigned int*)(mem+0x843)==0x012c4CAF) )
        {
            Unp->DepAdr=0x12c;
            if(Unp->info->run== -1 )
                Unp->Forced=0x80f;
            Unp->StrMem=mem[0x83d]|mem[0x841]<<8;
            Unp->RetAdr=mem[0x8b3]|mem[0x8b4]<<8;
            Unp->EndAdr=0xae;
            if((Unp->StrMem==0x827)&&(Unp->RetAdr==0x827))
            {
                Unp->StrMem=0x0100;
            }
            PrintInfo(Unp,_I_64ERS40B); /* 64er seq II 4.0 B */
            Unp->IdFlag=1;return;
        }
    }
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x80f)==0x46B9c5A0) &&
           (*(unsigned int*)(mem+0x813)==0x00fe9908) &&
           (*(unsigned int*)(mem+0x81f)==0xB504A2AD) &&
           (*(unsigned int*)(mem+0x843)==0x00ff4CAF) )
        {
            Unp->DepAdr=0xff;
            if(Unp->info->run== -1 )
                Unp->Forced=0x80f;
            Unp->StrMem=mem[0x83d]|mem[0x841]<<8;
            Unp->RetAdr=mem[0x8f8]|mem[0x8f9]<<8;
            Unp->EndAdr=0xae;
            PrintInfo(Unp,_I_64ER_15);
            Unp->IdFlag=1;return;
        }
    }
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x80f)==0x46B96BA0) &&
           (*(unsigned int*)(mem+0x813)==0x01589908) &&
           (*(unsigned int*)(mem+0x81f)==0xB504A2AD) &&
           (*(unsigned int*)(mem+0x823)==0xD602D0AA) )
        {
            Unp->DepAdr=mem[0x845]|mem[0x846]<<8;
            if(Unp->info->run == -1 )
                Unp->Forced=0x80f;
            Unp->StrMem=mem[0x83d]|mem[0x841]<<8;
            Unp->RetAdr=mem[0x871]|mem[0x872]<<8;
            Unp->EndAdr=0xae;
            PrintInfo(Unp,_I_64ERS40F); /* 64er seq II 4.0 F/A */
            Unp->IdFlag=1;return;
        }
    }
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x80f)==0x46B966A0) &&
           (*(unsigned int*)(mem+0x813)==0x015D9908) &&
           (*(unsigned int*)(mem+0x81f)==0xB504A2AD) &&
           (*(unsigned int*)(mem+0x868)==0x4CDCD0AD) )
        {
            Unp->DepAdr=0x15e;
            if(Unp->info->run == -1 )
                Unp->Forced=0x80f;
            Unp->StrMem=mem[0x83d]|mem[0x841]<<8;
            Unp->RetAdr=mem[0x86c]|mem[0x86d]<<8;
            Unp->EndAdr=0xae;
            if((Unp->StrMem==0x827)&&(Unp->RetAdr==0x827))
            {
                Unp->StrMem=0x0100;
                PrintInfo(Unp,_I_64ERS40C); /* 64er seq II 4.0 B */
            }
            else
            { /* 64er seq II 4.0 B w/o 2nd layer? not found yet, just in case */
                PrintInfo(Unp,_I_64ER_21);
            }
            Unp->IdFlag=1;return;
        }
    }
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x80f)==0x46B9B8A0) &&
           (*(unsigned int*)(mem+0x813)==0x010B9908) &&
           (*(unsigned int*)(mem+0x81f)==0xB504A2AD) &&
           (*(unsigned int*)(mem+0x8c2)==0xA98AD0AD) )
        {
            Unp->DepAdr=0x10c;
            if(Unp->info->run == -1 )
                Unp->Forced=0x80f;
            Unp->StrMem=mem[0x83d]|mem[0x841]<<8;
            Unp->RetAdr=mem[0x8cb]|mem[0x8cc]<<8;
            Unp->EndAdr=0xae;
            PrintInfo(Unp,_I_64ERS40D); /* 64er seq II 4.0 D */
            Unp->IdFlag=1;return;
        }
    }
    if( Unp->DepAdr==0 )
    {
        if(((*(unsigned int*)(mem+0x80f)&0xfffff0ff)==0x46B9c0A0) &&
           ((*(unsigned int*)(mem+0x813)&0xfff0ffff)==0x01009908) &&
            (*(unsigned int*)(mem+0x81f)==0xB504A2AD) &&
            (*(unsigned int*)(mem+0x8c2)==0xA58AD0AD) )
        {
            Unp->DepAdr=mem[0x845]|mem[0x846]<<8;
            if(Unp->info->run == -1 )
                Unp->Forced=0x80f;
            Unp->StrMem=mem[0x83d]|mem[0x841]<<8;
            if (Unp->DepAdr==0x103)
            {
                p=0x8d4;
            }
            else
            {
                p=0x8d3;
            }
            Unp->RetAdr=mem[p]|mem[p+1]<<8;
            Unp->EndAdr=0xae;
            PrintInfo(Unp,_I_64ERS40DB); /* 64er seq II 4.0 D-B/C */
            Unp->IdFlag=1;return;
        }
    }
    if( Unp->DepAdr==0 )
    {
        if(((*(unsigned int*)(mem+0x80f)&0xfffff0ff)==0x48B970A0) &&
           ((*(unsigned int*)(mem+0x813)&0xfff0ffff)==0x01109908) &&
            (*(unsigned int*)(mem+0x817)==0x84F7D088) &&
            (*(unsigned int*)(mem+0x84f)==0xA5015F20) )
        {
            Unp->DepAdr=mem[0x847]|mem[0x848]<<8;
            for(p=0x85a;p<0x867;p++)
            {
                if((mem[p]==0x85)||(mem[p]==0xa5))
                {
                    p++;
                    continue;
                }
                if(mem[p]==0x20)
                {
                    if((mem[p+1]==0x59)&&(mem[p+1]==0xa6))
                    {
                        mem[p]=0x2c;
                        p+=2;
                        continue;
                    }
                    else
                    {
                        Unp->RetAdr=mem[p+1]|mem[p+2]<<8;
                        break;
                    }
                }
                if(mem[p]==0x4c)
                {
                    Unp->RetAdr=mem[p+1]|mem[p+2]<<8;
                    break;
                }
            }
            Unp->Forced=0x80f;
            Unp->EndAdr=0xae;
            Unp->StrMem=mem[0x83f]|mem[0x843]<<8;
            PrintInfo(Unp,_I_HAPPYS32); /* happypacker/eqseq 3.2(ABC) */
            Unp->IdFlag=1;return;
        }
    }
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x80f)==0x48B947A0) &&
           (*(unsigned int*)(mem+0x813)==0x01449908) &&
           (*(unsigned int*)(mem+0x88b)==0xAFE602D0) &&
           (*(unsigned int*)(mem+0x845)==0x01454CAF) )
        {
            Unp->DepAdr=0x145;
            if(Unp->info->run== -1 )
                Unp->Forced=0x80f;
            Unp->StrMem=mem[0x83f]|mem[0x843]<<8;
            Unp->RetAdr=mem[0x87c]|mem[0x87d]<<8;
            Unp->EndAdr=0xae;
            if((Unp->StrMem==0x827)&&(Unp->RetAdr==0x827))
            {
                Unp->StrMem=0x0100;
            }
            PrintInfo(Unp,_I_HAPPYS22);  /* happypacker seq II 2.2 A */
            Unp->IdFlag=1;return;
        }
    }
}
