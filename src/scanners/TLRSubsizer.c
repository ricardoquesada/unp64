/* T.L.R. Subsizer */
#include "../unp64.h"
void Scn_TLRSubsizer(unpstr *Unp)
{
    unsigned char *mem;
    int q,p,s,off;
    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    /* normal */
    if( Unp->DepAdr==0 )
    {
        p=Unp->info->run;
        /* ss 0.7 has "SYS2063 SUBSIZER!" but it actually starts at $0815
           the LDY #$00 can be skipped and the relevant code is at $0817
           after that, all is identical to 0.6. Sysless stub is unchanged
        */
        if(p==0x80f)
            p=0x817;
        else if(p!=0x815)
            p=Unp->info->start;
        for(s=p,q=0;p<=s+0x17;p+=1)
        {
            if((*(unsigned int*)(mem+p)==0x8534A978) &&
               (*(unsigned short int*)(mem+p+4)==0x4c01) )
            {
                q=p;
                break;
            }
        }
        if(q)
        {
            q=mem[p+6]|mem[p+7]<<8;
            if(((*(unsigned int*)(mem+q     )&0x00fff0ff)==0x00b9b0a0) &&
               ((*(unsigned int*)(mem+q+0x05)&0x00ffffff)==0x0000fc99) )
            {
                q+=8;
                for(off=0;off<=0x0a;off+=0x0a)
                {
                    if(mem[q+off]==0x88)
                    {
                        q+=off+3;
                        for(off=0;off<=0x16;off+=0x16)
                        {
                            if( (*(unsigned int*)(mem+q+off     )==0x7A2004A2) &&
                                (*(unsigned int*)(mem+q+off+0x0c)==0x03349908) &&
                                (*(unsigned int*)(mem+q+off+0x35)==0x4C00A0CA) )
                            {
                                Unp->DepAdr=mem[q+off+0x39]|mem[q+off+0x3a]<<8;
                                Unp->Forced=p;
                                s=q+off+0xed;
                                if(mem[s]==0xa9)
                                    s+=4;
                                if((mem[s]==0x58)||(mem[s]==0x78))
                                    s++;
                                if(mem[s]==0x4c)
                                    Unp->RetAdr=mem[s+1]|mem[s+2]<<8;
                                Unp->fStrAf=0xfd;
                                Unp->StrAdC=EA_USE_Y;
                                Unp->EndAdr=mem[q+off+0x3b]|mem[q+off+0x3c]<<8;
                                PrintInfo(Unp,_I_TLRSSIZER);
                                Unp->IdFlag=1;return;
                            }
                        }
                    }
                }
            }
            if(((*(unsigned int*)(mem+q     )&0x00fff0ff)==0x00bdc0a2) &&
               ((*(unsigned int*)(mem+q+0x05)&0x00ffffff)==0x0000be9d) )
            {
                q+=8;
                for(off=0;off<=0x0a;off+=0x0a)
                {
                    if(mem[q+off]==0xca)
                    {
                        q+=off+3;
                        for(off=0;off<=0x16;off+=0x16)
                        {
                            if( (*(unsigned int*)(mem+q+off     )==0xBF06E0A9) &&
                                (*(unsigned int*)(mem+q+off+0x07)==0x2a00c820) &&
                                (*(unsigned int*)(mem+q+off+0x38)==0x4Cc8c6d0) )
                            {
                                Unp->DepAdr=mem[q+off+0x3c]|mem[q+off+0x3d]<<8;
                                Unp->Forced=p;
                                s=q+off+0x102;
                                if(mem[s]==0xa9)
                                    s+=4;
                                if((mem[s]==0x58)||(mem[s]==0x78))
                                    s++;
                                if(mem[s]==0x4c)
                                    Unp->RetAdr=mem[s+1]|mem[s+2]<<8;
                                Unp->fStrAf=0xdc;
                                Unp->StrAdC=EA_USE_X;
                                Unp->EndAdr=mem[q+off+0x5b]|mem[q+off+0x5c]<<8;
                                PrintInfo(Unp,_I_TLRSSIZD5);
                                Unp->IdFlag=1;return;
                            }
                            if( (*(unsigned int*)(mem+q+off     )==0xBF06E0A9) &&
                                (*(unsigned int*)(mem+q+off+0x07)==0x2a00c420) &&
                                (*(unsigned int*)(mem+q+off+0x34)==0x00a0cad0) )
                            {
                                Unp->DepAdr=mem[q+off+0x39]|mem[q+off+0x3a]<<8;
                                Unp->Forced=p;
                                s=q+off+0xf8;
                                if(mem[s]==0xa9)
                                    s+=4;
                                if((mem[s]==0x58)||(mem[s]==0x78))
                                    s++;
                                if(mem[s]==0x4c)
                                    Unp->RetAdr=mem[s+1]|mem[s+2]<<8;
                                Unp->fStrAf=0xd8;
                                Unp->StrAdC=EA_USE_X;
                                Unp->EndAdr=mem[q+off+0x54]|mem[q+off+0x55]<<8;
                                PrintInfo(Unp,_I_TLRSSIZD6);
                                Unp->IdFlag=1;return;
                            }
                        }
                    }
                }
            }
        }
    }
}
