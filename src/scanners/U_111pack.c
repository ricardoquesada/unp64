/* unknown $111 */
#include "../unp64.h"
void Scn_U_111pack(unpstr *Unp)
{
    unsigned char *mem;
    int q,p;
    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x80b)==0xA27800A0) &&
            (*(unsigned int*)(mem+0x80f)==0x84D89AFF) &&
            (*(unsigned int*)(mem+0x817)==0xC8010099) &&
            (*(unsigned int*)(mem+0x81b)==0x114CF7D0) )
        {
            p=mem[0x815]|mem[0x816]<<8;
            if( (*(unsigned int*)(mem+p     )==0xD0010CAD) &&
                (*(unsigned int*)(mem+p+0x23)==0x0121CE03) )
            {
                Unp->DepAdr=0x13c;
                if(Unp->info->run == -1)
                    Unp->Forced=0x80b;
                q=0x3e;
                if( (mem[p+q]==0x85) && (mem[p+q+3]==0x4c) )
                    Unp->RetAdr=mem[p+q+4]|mem[p+q+5]<<8;
                else
                {
                    q=0x4e;
                    if( (mem[p+q]==0x85) && (mem[p+q+3]==0x4c) )
                    {
                        memset(mem+p+0x3c,0xea,0x10);
                        Unp->RetAdr=mem[p+q+4]|mem[p+q+5]<<8;
                    }
                }
                Unp->fStrBf=0x120;
                Unp->StrAdC=EA_USE_Y;
                Unp->EndAdr= mem[p+0x20]|mem[p+0x21]<<8;Unp->EndAdr+=0x100;
                PrintInfo(Unp,_I_U_111);
                Unp->IdFlag=1;return;
            }
        }
    }
}
