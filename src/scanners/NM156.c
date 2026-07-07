/* NM156 */
#include "../unp64.h"
void Scn_NM156(unpstr *Unp)
{
    unsigned char *mem;
    int strtmp,endtmp,p;
    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x81b)==0x8534A978) &&
           (*(unsigned int*)(mem+0x823)==0x0830BDE8) &&
           (*(unsigned int*)(mem+0x853)==0xA5018520) &&
           (*(unsigned int*)(mem+0x8ab)==0x01854CFC) )
        {
            Unp->DepAdr=0x100;
            Unp->Forced=0x81b;
            Unp->RetAdr=mem[0x88f]|mem[0x890]<<8;
            Unp->fEndAf=0xfb; /*it's always +0xbaf*/
            Unp->EndAdC=0xffff-0xbaf;
            Unp->StrMem=mem[0x863]|mem[0x867]<<8;
            PrintInfo(Unp,_I_NM156PACK);
            Unp->IdFlag=1;return;
        }
    }
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x821)==0x0BBD19A2) &&
           (*(unsigned int*)(mem+0x825)==0x04009D09) &&
           (*(unsigned int*)(mem+0x86f)==0x85018620) &&
           (*(unsigned int*)(mem+0x873)==0x018620FB) )
        {
            Unp->DepAdr=0x100;
            Unp->Forced=0x821;
            Unp->RetAdr=mem[0x8a3]|mem[0x8a4]<<8;
            //Unp->fEndAf=0xfb;
            //Unp->StrMem=mem[0x8c9]|mem[0x8ca]<<8;
            Unp->StrMem=0x10000;
            Unp->EndAdr=0;
            for(p=0x8c9;p<0x90a;p+=4)
            {
                strtmp=mem[p]|mem[p+1]<<8;
                endtmp=mem[p+2]|mem[p+3]<<8;
                if(endtmp==0)
                    break;
                if(strtmp<Unp->StrMem)
                    Unp->StrMem=strtmp;
                if(endtmp>Unp->EndAdr)
                    Unp->EndAdr=endtmp;
                if(Unp->DebugP)
                {
                    printf("$%04x-$%04x\n",strtmp,endtmp-1);
                }
            }
            PrintInfo(Unp,_I_NM156LINK);
            if(Unp->DebugP)
                printmsg(mem,0x90b,0x1a);
            Unp->IdFlag=1;return;
        }
    }
}
