/* compact fc1/mtb */
#include "../unp64.h"
void Scn_FilecompactorMTB(unpstr *Unp)
{
    unsigned char *mem;
    int q,p;
    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x828)==0x7EBD00A2) &&
            (*(unsigned int*)(mem+0x82c)==0x033C9D08) &&
            (*(unsigned int*)(mem+0x844)==0x2EA62DA5) &&
            (*(unsigned int*)(mem+0x8d9)==0xA0036D4C) )
        {
            if(Unp->info->run == -1)
            {
                Unp->Forced=0x828;
            }
            Unp->DepAdr=0x33c;
            Unp->StrMem=mem[0x874]|mem[0x876]<<8;
            Unp->EndAdr=0x2d;
            for(q=0,p=0x8bf;p<0x8c3;p+=3)
            {
                if(*(unsigned int*)(mem+p)==0x4CA65920)
                {
                    mem[p]=0x2c;
                }
                if((mem[p]==0x4c)||(mem[p]==0x20))
                {
                    q=p;
                    break;
                }
            }
            if(q)
            {
                Unp->RetAdr=mem[q+1]|mem[q+2]<<8;
            }
            PrintInfo(Unp,_I_FCOMPMTB);
            Unp->IdFlag=1;return;
        }
    }
}
