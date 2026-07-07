/* TMM Pack */
#include "../unp64.h"
void Scn_TMM(unpstr *Unp)
{
    unsigned char *mem;
    int q,p;
    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    /* The Magic Man packer */
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x80e)==0xC601E678) &&
            (*(unsigned int*)(mem+0x812)==0x081CCEAF) &&
            (*(unsigned int*)(mem+0x816)==0xAEB100A0) &&
            (*(unsigned int*)(mem+0x81a)==0xC8000099) )
        {
            for(q=0,p=0x852;p<0x859;p+=6)
            {
                if((*(unsigned int*)(mem+p)==0xD0CAC8AE) &&
                   mem[p+0x15]==0x4c )
                {
                    q=p;
                    break;
                }
            }
            if(q)
            {
                if(Unp->info->run == -1)
                {
                    Unp->Forced=0x80e;
                }
                Unp->DepAdr=0x400;
                Unp->fStrBf=0xae;
                Unp->EndAdr=0xae;
                Unp->RetAdr=mem[q+0x16]|mem[q+0x17]<<8;
                PrintInfo(Unp,_I_TMMPACK);
                Unp->IdFlag=1;return;
            }
        }
    }
    /* Pico Packer v1.0/The Magic Man (so far never actually found used anywhere) */
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x80d)==0xBC40A278) &&
            (*(unsigned int*)(mem+0x818)==0xBD00024C) &&
            (*(unsigned int*)(mem+0x838)==0x99003520) &&
            (*(unsigned int*)(mem+0x851)==0x04D036E6) )
        {
            Unp->Forced=0x80d;
            Unp->DepAdr=0x2;
            Unp->StrMem=mem[0x83c]|mem[0x83d]<<8;
            Unp->fEndAf=0x23;
            Unp->EndAdC=0xffff|EA_USE_Y;
            Unp->RetAdr=mem[0x84c]|mem[0x84d]<<8;
            PrintInfo(Unp,_I_PICOPACK);
            Unp->IdFlag=1;return;
        }
    }
}
