/* JEDI packer and linker */
#include "../unp64.h"
void Scn_Jedi(unpstr *Unp)
{
    unsigned char *mem;
    int p,q,r,strtmp,endtmp;
    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x812)==0xBDBAA287) &&
           (*(unsigned int*)(mem+0x816)==0xA048070D) &&
           (*(unsigned int*)(mem+0x852)==0x9FBDCA60) &&
           (*(unsigned int*)(mem+0x8b2)==0x01882068) )
        {
            Unp->DepAdr=0x19a;
            Unp->Forced=0x812;
            PrintInfo(Unp,_I_JEDILINK1);
        }
        else
        if((*(unsigned int*)(mem+0x822)==0x30B9DFA0) &&
           (*(unsigned int*)(mem+0x826)==0x00FF9908) &&
           (*(unsigned int*)(mem+0x852)==0x9FBDCA60) &&
           (*(unsigned int*)(mem+0x8a5)==0x01074C02) )
        {
            /* this version needs to be patched */
            Unp->DepAdr=0x19a;
            Unp->Forced=0x822;
            /* jsr $a3bf -> jsr $02bf */
            mem[0x865]=0x02;
            memcpy(mem+0x2bf,roms[0]+0x03bf,0x40);
            PrintInfo(Unp,_I_JEDILINK2);
        }
        if( Unp->DepAdr!=0 )
        {
            Unp->RtAFrc=1;
            Unp->RetAdr=mem[0x8cc]|mem[0x8cd]<<8;
            Unp->StrMem=0x10000;
            Unp->EndAdr=0;
            q=0x8d0;
            r=Unp->info->end;
            for(p=mem[q-1];p>0;p-=4) /* max $10*4 bytes */
            {
                endtmp=(mem[q+p-2]|mem[q+p-1]<<8);
                strtmp=endtmp-r;
                r=(mem[q+p-4]|mem[q+p-3]<<8);
                strtmp+=r;
                if(endtmp==0)
                    endtmp=0x10000;
                if(endtmp>Unp->EndAdr)
                    Unp->EndAdr=endtmp;
                if(strtmp<Unp->StrMem)
                    Unp->StrMem=strtmp;
                if(Unp->DebugP)
                {
                    printf("$%04x-$%04x\n",strtmp,endtmp);
                }
            }
            Unp->IdFlag=1;return;
        }
    }
    /* similar preamble, different depacker code, used in some JEDI warez */
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x812)==0xBDBAA24B) &&
           (*(unsigned int*)(mem+0x816)==0xA048070D) &&
           (*(unsigned int*)(mem+0x822)==0xE349F7D0) &&
           (*(unsigned int*)(mem+0x867)==0xAF85AE86) )
        {
            Unp->DepAdr=0x100;
            Unp->Forced=0x812;
            if(mem[0x81a]==0xdf)
            {
                Unp->RetAdr=mem[0x8c6]|mem[0x8c7]<<8;
                mem[0x8ba]=0x2c;
            }
            else if(mem[0x81a]==0x8f)
            {
                Unp->RetAdr=mem[0x8be]|mem[0x8bf]<<8;
                mem[0x8b2]=0x2c;
            }
            Unp->StrMem=mem[0x864]|mem[0x866]<<8;
            Unp->fEndAf=0xae;
            PrintInfo(Unp,_I_JEDIPACK);
            Unp->IdFlag=1;return;
        }
    }
}
