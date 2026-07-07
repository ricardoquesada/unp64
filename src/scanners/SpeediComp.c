/* Michael Winterberg's Speedi Compactor (from 1st compacker disk/NSC)
   Found especially in some (abused) intromaker and notemakers
*/
#include "../unp64.h"
void Scn_SpeediComp(unpstr *Unp)
{
    unsigned char *mem;
    int p;
    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x816)==0x00B500D6) &&
           (*(unsigned int*)(mem+0x81a)==0x02D0FFC9) &&
           (*(unsigned int*)(mem+0x81e)==0xA96001D6) &&
           (*(unsigned int*)(mem+0x8a5)==0x08454C08) )
        {
            Unp->DepAdr=mem[0x85d]|mem[0x85e]<<8;
            if(Unp->DepAdr>0x800)
                Unp->RtAFrc=1;
            if(Unp->info->run == -1)
            {
                if((mem[0x80d]==0xa9)&&
                   (*(unsigned int*)(mem+0x80f)==0x0ED00185) )
                {
                    Unp->Forced=0x80d;
                }
                else
                {
                    Unp->Forced=0x8dc;
                }
            }
            /* many hacks, always different pos */
            if(mem[0x8dd]==0x4c)
            {
                Unp->RetAdr=mem[0x8de]|mem[0x8df]<<8;
            }
            else if ( *(unsigned int*)(mem+0x8d8)==0x08F05800 )
            {
                if( *(unsigned int*)(mem+0x8e4)==0x778D52A9 )
                {
                    mem[0x8e4]=0x4c;
                    mem[0x8e5]=0xae;
                    mem[0x8e6]=0xa7;
                    Unp->RetAdr=0xa7ae;
                }
                else
                {
                    for( p=0x8e4;p<0x8ff;p++)
                    {
                        if(mem[p]==0x4c)
                        {
                            Unp->RetAdr=mem[p+1]|mem[p+2]<<8;
                            break;
                        }
                    }
                }
            }
            Unp->EndAdr=0x2d;
            PrintInfo(Unp,_I_MWSPCOMP);
            Unp->IdFlag=1;return;
        }
    }
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x812)==0x2E842D85) &&
           (*(unsigned int*)(mem+0x81b)==0x04354C13) &&
           (*(unsigned int*)(mem+0x822)==0x274C0185) &&
           (*(unsigned int*)(mem+0x832)==0x20043C4C) )
        {
            Unp->DepAdr=mem[0x81d]|mem[0x81e]<<8;
            Unp->RetAdr=mem[0x83a]|mem[0x83b]<<8;
            Unp->EndAdr=mem[0x845]|mem[0x847]<<8;
            Unp->fStrAf=0xfe;
            PrintInfo(Unp,_I_MWPACK);
            Unp->IdFlag=1;return;
        }
    }
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x811)==0x8534A978) &&
           (*(unsigned int*)(mem+0x82d)==0x00A0FD85) &&
           (*(unsigned int*)(mem+0x835)==0xFE9133F0) &&
           (*(unsigned int*)(mem+0x87b)==0x08374CFC) )
        {
            Unp->DepAdr=0x334;
            Unp->RetAdr=mem[0x8ec]|mem[0x8ed]<<8; /* always run ? */
            Unp->EndAdr=mem[0x818]|mem[0x81c]<<8;
            Unp->StrMem=mem[0x8ce]|mem[0x8cf]<<8; /* $0800 fixed ? */
            PrintInfo(Unp,_I_MWSPCR1);
            Unp->IdFlag=1;return;
        }
    }
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x811)==0x018534A9) &&
           (*(unsigned int*)(mem+0x828)==0xA2092420) &&
           (*(unsigned int*)(mem+0x82c)==0x092420AE) &&
           (*(unsigned int*)(mem+0x924)==0x00B500D6) )
        {
            Unp->DepAdr=0x100;
            Unp->RetAdr=mem[0x87c]|mem[0x87d]<<8;
            Unp->fEndAf=0xac;
            Unp->StrMem=mem[0x850]|mem[0x854]<<8;
            PrintInfo(Unp,_I_MWSPCR2);
            Unp->IdFlag=1;return;
        }
    }
}
