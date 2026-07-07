/* Helmet/TempesT */
#include "../unp64.h"
void Scn_Helmet(unpstr *Unp)
{
    unsigned char *mem;
    int p,q;
    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if((mem[0x80e]==0x4c)&&
           (*(unsigned int*)(mem+0x81d)==0xFC86FB85) &&
           (*(unsigned int*)(mem+0x83d)==0x033C9908) &&
           (*(unsigned int*)(mem+0x84d)==0x033C4C06) &&
           (*(unsigned int*)(mem+0x859)==0xC5FBB1C8) )
        {
            Unp->DepAdr=0x33c;
            Unp->Forced=0x80e;
            q=mem[0x826];
            if(q==0xa3)
                q=0x8cd;
            else if(q==0xfd)
                q=0x8cf;
            else
                q=0;
            if(q)
            {
                Unp->StrMem=mem[q+3]|mem[q+4]<<8;
                p=mem[q+0]|mem[q+1]<<8;
                p-=Unp->StrMem;
                Unp->EndAdr=(mem[0x822]|mem[0x824]<<8)-p+1;
            }
            Unp->RetAdr=mem[0x847]|mem[0x849]<<8;
            PrintInfo(Unp,_I_HELMET2);
            if(Unp->DebugP)
            {
                if((*(unsigned int*)(mem+0x911)==0x99091FB9) )
                    printmsg(mem,0x91f,40);
                else if((*(unsigned int*)(mem+0x916)==0x99097DB9) )
                    printmsg(mem,0x97d,40);
            }
            Unp->IdFlag=1;return;
        }
    }
}
