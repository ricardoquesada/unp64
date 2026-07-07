/* unknown TRI! */
#include "../unp64.h"
void Scn_Trianon(unpstr *Unp)
{
    unsigned char *mem;
    int q,p;
    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x812)==0x8400A078) &&
            (*(unsigned int*)(mem+0x816)==0x0850B901) &&
            (*(unsigned int*)(mem+0x81a)==0xB9040099) &&
           ((*(unsigned int*)(mem+0x81e)&0xfffffff0)==0x009908C0))
        {
            p=0x85c;
            q=mem[0x81e]&0x0f;
            if(mem[p+q-1]==0x4c)
            {
                Unp->DepAdr=mem[0x84e]|mem[0x84f]<<8;
                if(Unp->info->run == -1)
                    Unp->Forced=0x812;
                Unp->StrMem=mem[0x843]|mem[0x848]<<8;
                Unp->EndAdr=0xae;
                Unp->RetAdr=mem[p+q]|mem[p+q+1]<<8;
                PrintInfo(Unp,_I_TRIANP);
                Unp->IdFlag=1;return;
            }
        }
    }
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x812)==0x8400A078) &&
            (*(unsigned int*)(mem+0x816)==0x083fB901) &&
            (*(unsigned int*)(mem+0x81a)==0xc8040099) &&
            (*(unsigned int*)(mem+0x81e)==0xFE84F7D0) &&
            (*(unsigned int*)(mem+0x8ad)==0x04524CAF))
        {
            Unp->DepAdr=mem[0x83d]|mem[0x83e]<<8;
            Unp->StrMem=mem[0x840]|mem[0x844]<<8;
            Unp->EndAdr=0xae;
            Unp->RetAdr=mem[0x8dc]|mem[0x8dd]<<8;
            if(Unp->info->run == -1)
            {
                if((mem[0x0801]==0xa9) &&
                   (mem[0x0803]==0x85) &&
                   (mem[0x0804]==0xae) &&
                   (mem[0x0808]==0xaf) )
                {
                    Unp->Forced=0x801;
                }
                else
                {
                    Unp->Forced=0x812;
                }
            }
            /* note: this unpacker is very sensitive to $ae/af */
            PrintInfo(Unp,_I_TRIAN2);
            Unp->IdFlag=1;return;
        }
    }
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x812)==0x8400A078) &&
            (*(unsigned int*)(mem+0x816)==0x84FB8401) &&
            (*(unsigned int*)(mem+0x81a)==0xD0FBA5FC) &&
            (*(unsigned int*)(mem+0x81e)==0xC6FCC602) &&
            (*(unsigned int*)(mem+0x84e)==0xB101004C))
        {
            Unp->DepAdr=0x100;
            Unp->StrMem=mem[0x845]|mem[0x849]<<8;
            Unp->EndAdr=0xae; Unp->EndAdC=1;
            Unp->RetAdr=mem[0x89a]|mem[0x89b]<<8;
            if(Unp->info->run == -1)
                Unp->Forced=0x812;
            PrintInfo(Unp,_I_TRIAN3);
            Unp->IdFlag=1;return;
        }
    }
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x812)==0x8600A278) &&
            (*(unsigned int*)(mem+0x816)==0x0829BD01) &&
            (*(unsigned int*)(mem+0x81a)==0xBD04009D) &&
            (*(unsigned int*)(mem+0x81e)==0xFA9D08B9) &&
            (*(unsigned int*)(mem+0x9aa)==0xA6D0043C) )
        {
            Unp->DepAdr=0x400;
            Unp->Forced=0x812;
            Unp->StrMem=mem[0x8bb]|mem[0x8bc]<<8;
            Unp->EndAdr=0xfc;
            Unp->RetAdr=mem[0x85d]|mem[0x85e]<<8;
            PrintInfo(Unp,_I_TRIANC);
            Unp->IdFlag=1;return;
        }
    }
}
