/* ABCrunch/Oneway 1993 (sys pi*656) */
#include "../unp64.h"
void Scn_ABCruncher(unpstr *Unp)
{
    unsigned char *mem;
    int q,p;
    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if(((*(unsigned int*)(mem+0x81a)==0xC8034099)||  /* normal */
            (*(unsigned int*)(mem+0x81a)==0xe803409d))&& /* SCS hack? */
            (*(unsigned int*)(mem+0x81e)==0x404CF7D0)&&
            mem[0x822]==0x03)
        {
            p=mem[0x818]|mem[0x819]<<8;p+=0xcd;
            if( (mem[p  ]==0x8d) &&
                (mem[p+3]==0xad) )
            {
                q=Unp->info->run;
                if(q==-1)
                {
                    for(q=0x80b;q<0x816;q++)
                    {
                        if((mem[q]==0x78)||(mem[q]==0xa0))
                        {
                            Unp->Forced=q;
                            break;
                        }
                    }
                }
                Unp->DepAdr=mem[0x821]|mem[0x822]<<8;
                for(q=p-0xb;q<p;q++)
                {
                    if(mem[q]==0x4c)
                        break;
                    if((mem[q]==0x8d)||(mem[q]==0x9d)||(mem[q]==0xce))
                        q+=2;
                    if(mem[q]==0xa9)
                        q++;
                }
                if(q<p)
                    Unp->RetAdr=mem[q+1]|mem[q+2]<<8;
                Unp->EndAdr=mem[p+1]|mem[p+2]<<8;Unp->EndAdr++;
                Unp->fStrAf=0x40e;
                PrintInfo(Unp,_I_AB_CRUNCH);
                Unp->IdFlag=1;return;
            }
        }
    }
}
