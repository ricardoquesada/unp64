/* Crush/Taboo */
#include "../unp64.h"
void Scn_Crush(unpstr *Unp)
{
    unsigned char *mem;
    int q,p;
    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        for(q=0x801;q<0x880;q++)
        {
            if((*(unsigned int*)(mem+q+0x00)==0xA2F7D0E8) &&
               (*(unsigned int*)(mem+q+0x0a)==0xC8FF0099) &&
               (*(unsigned int*)(mem+q+0x57)==0xAEB100A0) &&
               (*(unsigned int*)(mem+q+0x5b)==0x02D0AEE6)   )
            {
                Unp->DepAdr=mem[q+0x2c]|mem[q+0x2d]<<8;
                break;
            }
        }
        if(Unp->DepAdr)
        {
            if(Unp->info->run==-1)
            {
                for(p=0x801;p<q;p++)
                {
                    if(mem[p]==0x78)
                    {
                        Unp->Forced=p;
                        break;
                    }
                }
            }
            Unp->fStrBf=0x2d;
            Unp->fEndAf=0x2d;
            Unp->EndAdC=0xffff;
            for(p=q+0x95;p<q+0xa1;p++)
            {
                if(mem[p]==0x4c)
                    Unp->RetAdr=mem[p+1]|mem[p+2]<<8;
            }
            PrintInfo(Unp,_I_TABOOCRUSH);
            Unp->IdFlag=1;return;
        }
    }
    /* Unknown cruncher by Taboo, found in their rels */
    if( Unp->DepAdr==0 )
    {
        for(q=0x801;q<0x880;q++)
        {
            if((*(unsigned int*)(mem+q+0x00)==0xE805009D) &&
               (*(unsigned int*)(mem+q+0x04)==0x464CF1D0) &&
               (*(unsigned int*)(mem+q+0x08)==0x8500A904) &&
               (*(unsigned int*)(mem+q+0x0c)==0xF05AA457) &&
               (*(unsigned int*)(mem+q+0xb0)==0x85FEA5FB) )
            {
                Unp->DepAdr=0x463; /* a little later, to let it set $2d/2e */
                break;
            }
        }
        if(Unp->DepAdr)
        {
            if(Unp->info->run==-1)
            {
                for(p=0x801;p<q;p++)
                {
                    if(mem[p]==0x78)
                    {
                        Unp->Forced=p;
                        break;
                    }
                }
            }
            Unp->fStrBf=0x2d;
            Unp->fEndAf=0x2d;
            Unp->EndAdC=0xffff;
            Unp->RetAdr=mem[q+0x123]|mem[q+0x124]<<8;
            PrintInfo(Unp,_I_TABOOCRNCH);
            Unp->IdFlag=1;return;
        }
    }
    /* Unknown packer by Taboo, found in the same rels after decrunch */
    if( Unp->DepAdr==0 )
    {
        for(q=0x801;q<0x830;q++)
        {
            if((*(unsigned int*)(mem+q+0x00)==0x9AF6A278) &&
               (*(unsigned int*)(mem+q+0x14)==0xAE852D85) &&
               (*(unsigned int*)(mem+q+0x28)==0x01004CF7) &&
               (*(unsigned int*)(mem+q+0x54)==0xCA016E20) )
            {
                Unp->DepAdr=0x100;
                break;
            }
        }
        if(Unp->DepAdr)
        {
            Unp->Forced=q;
            Unp->fStrAf=0xfe;
            Unp->EndAdr=mem[q+0x2e]|mem[q+0x2f]<<8;Unp->EndAdr++;
            Unp->RetAdr=mem[q+0x91]|mem[q+0x92]<<8;
            PrintInfo(Unp,_I_TABOOPACK );
            Unp->IdFlag=1;return;
        }
    }
    /* Pack64/Taboo have variable code and entrypoint, sys&sysless */
    if( Unp->DepAdr==0 )
    {
        p=0;
        for(q=0x801;q<0x830;q++)
        {
            if((mem[q]==0xa2)&&(!p))
                p=q;
            if((*(unsigned int*)(mem+q+0x00)==0x018534A9) &&
               (*(unsigned int*)(mem+q+0x08)==0x00FB9D08) &&
               (*(unsigned int*)(mem+q+0x1d)==0xC8033499) &&
               (*(unsigned int*)(mem+q+0x21)==0x06EEF7D0) )
            {
                Unp->DepAdr=0x100;
                break;
            }
        }
        if(Unp->DepAdr)
        {
            Unp->Forced=p;
            Unp->fStrAf=0xfe;
            Unp->EndAdr=mem[q+0x14]|mem[q+0x15]<<8;Unp->EndAdr++;
            for(p=q+0x3c;p<q+0x4b;p++)
            {
                if(mem[p]==0x4c)
                {
                    Unp->RetAdr=mem[p+1]|mem[p+2]<<8;
                    break;
                }
            }
            PrintInfo(Unp,_I_TABOOPACK64 );
            Unp->IdFlag=1;return;
        }
    }
}
