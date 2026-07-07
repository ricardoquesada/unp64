/* xrated exploding packer */
#include "../unp64.h"
void Scn_ExplXRated(unpstr *Unp)
{
    unsigned char *mem;
    int p;
    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x812)==0x9AFFA278) &&
           (*(unsigned int*)(mem+0x94F)==0x65FDA5F7) &&
           (*(unsigned int*)(mem+0x83a)==0x042E4C01) )
        {
            Unp->DepAdr=0x42e;
            Unp->Forced=0x812;
            Unp->RetAdr=mem[0xa0d]|mem[0xa0e]<<8;
            Unp->EndAdr=mem[0x89b]|mem[0x89c]<<8; // 0x2d or 0xae
            Unp->fStrAf=0xfc;
            Unp->StrAdC=0xffff;
            PrintInfo(Unp,_I_XRPOWC71);
            if(Unp->DebugP)
                printmsg(mem,0x841,40);
            Unp->IdFlag=1;return;
        }
    }
    /* xrated exploding crunch 6 */
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x812)==0x9AFFA278) &&
           (*(unsigned int*)(mem+0x81d)==0xF7D0CA00) &&
           (*(unsigned int*)(mem+0x85b)==0xA0AF84AE) &&
          ((*(unsigned int*)(mem+0x85f)&0xffffff00)==0x04284C00) )
        {
            Unp->DepAdr=0x428;
            Unp->Forced=0x812;
            for(p=0x987;p<0x993;p++)
            {
                if(mem[p]==0x4c)
                {
                    Unp->RetAdr=mem[p+1]|mem[p+2]<<8;
                    break;
                }
            }
            Unp->EndAdr=mem[0x853]|mem[0x855]<<8; // 0x2d or 0xae
            Unp->fStrAf=0xfe;
            PrintInfo(Unp,_I_XREXPLCR);
            if(Unp->DebugP)
                printmsg(mem,0x86a,40);
            Unp->IdFlag=1;return;
        }
    }
    /* xrated power crunch 7 */
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x812)==0xC7A0D878) &&
           (*(unsigned int*)(mem+0x816)==0x99082EB9) &&
           (*(unsigned int*)(mem+0x81a)==0xF5B90333) &&
           (*(unsigned int*)(mem+0x9a4)==0xAEC6AEB1) )
        {
            Unp->DepAdr=0x334;
            Unp->Forced=0x812;
            if(mem[0x9b2]==0xc6 && mem[0x9b7]==0xe6 )
            {   /* normally ee 20 d0 but some has a hack like 20 00 05 */
                mem[0x9b4]=0xea;
                mem[0x9b5]=0xea;
                mem[0x9b6]=0xea;
            }
            Unp->EndAdr=mem[0x87c]|mem[0x87a]<<8; // 0x2d or 0xae
            Unp->fStrAf=0xfc;
            Unp->StrAdC=0xffff;
            Unp->RetAdr=mem[0x887]|mem[0x888]<<8;
            PrintInfo(Unp,_I_XRPOWC74);
            Unp->IdFlag=1;return;
        }
    }
}
