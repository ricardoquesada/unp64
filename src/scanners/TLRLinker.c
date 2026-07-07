/* T.L.R. cld (cbmtools) 0.6: cbm binary linker */
#include "../unp64.h"
void Scn_TLRLinker(unpstr *Unp)
{
    unsigned char *mem;
    int q,p,s;
    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    /* normal */
    if( Unp->DepAdr==0 )
    {
        p=Unp->info->run;
        if(p!=0x815)
            p=Unp->info->start;
        for(q=p+0x16;p<q;p++)
        {
            s=p+0x11;s<<=8;
            if(((*(unsigned int*)(mem+p     )&0xff00ffff)==0xA000A278) &&
                (*(unsigned int*)(mem+p+0x05)==(0x950000BD|s)) &&
                (*(unsigned int*)(mem+p+0x26)==0xE80EB10F) &&
                (*(unsigned int*)(mem+p+0x36)==0xE6D9D0C8) )
            {
                Unp->DepAdr=mem[p+0xf];
                break;
            }
        }
        if( Unp->DepAdr )
        {
            Unp->Forced=p;
            q=p+0x41;
            if(mem[q]==0x58)
                q++;
            Unp->RetAdr=mem[q+1]|mem[q+2]<<8;
            Unp->StrMem=mem[p+0x2b]|mem[p+0x2c]<<8;
            Unp->EndAdr=0x1b;
            PrintInfo(Unp,_I_TLRLINK);
            Unp->IdFlag=1;return;
        }
    }
    /* fullmem, can be a problem, as it has end code in $d000 (sprite pos!) */
    if( Unp->DepAdr==0 )
    {
        p=Unp->info->run;
        if(p!=0x815)
            p=Unp->info->start;
        for(q=p+0x16;p<q;p++)
        {
            s=p+0x19;s<<=8;
            if(((*(unsigned int*)(mem+p     )&0xff00ffff)==0xA000A278) &&
                (*(unsigned int*)(mem+p+0x05)==(0xE00000BD|s)) &&
                (*(unsigned int*)(mem+p+0x2e)==0xE80EB10F) &&
                (*(unsigned int*)(mem+p+0x3e)==0xE6D9D0C8) )
            {
                Unp->DepAdr=mem[p+0x17];
                break;
            }
        }
        if( Unp->DepAdr )
        {
            Unp->Forced=p;
            q=p+0x61;
            if(mem[q]==0x58)
                q++;
            Unp->RetAdr=mem[q+1]|mem[q+2]<<8;
            /* patch: code at $d000 only clears the last copy code,
            not a big deal to leave it in memory but at least use
            the real retaddr
            */
            s=mem[p+0x46]|mem[p+0x47]<<8;
            mem[p+0x46]=mem[q+1];
            mem[p+0x47]=mem[q+2];
            Unp->StrMem=mem[p+0x33]|mem[p+0x34]<<8;
            Unp->EndAdr=0x1b;
            PrintInfo(Unp,_I_TLRLINKFM);
            if(Unp->DebugP)
            {
                printf("Cleanup leftover at $%04x-$%04x\n",s-0x30,s+0x10);
            }
            Unp->IdFlag=1;return;
        }
    }
}
