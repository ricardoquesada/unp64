/* Cadaver's packer */
#include "../unp64.h"
void Scn_Cadaver(unpstr *Unp)
{
    unsigned char *mem;
    int p=0,q=0;
    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        for(p=0x801;p<=0x828;p++)
        {
            if( mem[p    ]==0xa0 &&
                mem[p+0x2]==0xb9 &&
                mem[p+0x5]==0x99 &&
               (*(unsigned int*)(mem+p+0x08)==0x84F7D088) &&
               (*(unsigned int*)(mem+p+0x0c)==0xA9FD84FC) )
            {
                for(q=p+0x19;q<p+0x1c;q+=2)
                {
                    if((*(unsigned int*)(mem+q     )==0xD0FEA501)&&
                       (*(unsigned int*)(mem+q+0x55)==0xFFE6FEB1))
                    {
                        Unp->DepAdr=mem[q+0x2c]|mem[q+0x2d]<<8;
                        break;
                    }
                }
                if(Unp->DepAdr)
                    break;
            }
        }
        if(Unp->DepAdr)
        {
            if(Unp->info->run == -1 )
                Unp->Forced=p;

            Unp->StrMem=mem[q+0x22]|mem[q+0x26]<<8;
            Unp->EndAdr=0xfe;
            for(p=q+0x6d;p<q+0x75;p++)
            {
                if (mem[p  ]==0xa2 &&
                    mem[p+1]==0xff &&
                    mem[p+2]==0x9a )
                {
                    p+=3;
                    while (p<q+0x80)
                    {
                        if(mem[p]==0x4c)
                        {
                            Unp->RetAdr=mem[p+1]|mem[p+2]<<8;
                            break;
                        }
                        if((mem[p]==0xc6)||
                           (mem[p]==0xa9)||
                           (mem[p]==0x85))
                           p++;
                        p++;
                    }

                    break;
                }
            }
            PrintInfo(Unp, _I_CADAVERPACK);
            Unp->IdFlag=1;return;
        }
    }
}
