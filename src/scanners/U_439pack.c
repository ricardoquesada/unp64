/* unknown $439 packer
   found for Madness 4/5 noter, several Byterapers and some WOW warez.
*/
#include "../unp64.h"
void Scn_U_439pack(unpstr *Unp)
{
    unsigned char *mem;
    int p;
    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x81e)==0xAE84AC84) &&
            (*(unsigned int*)(mem+0x83e)==0x04FFCDAD) &&
            (*(unsigned int*)(mem+0x8c6)==0x6868E7D0) )
        {
            if(Unp->info->run == -1)
            {
                Unp->Forced=0x81e;
                for(p=0x816;p<0x81f;p++)
                {
                    if(mem[p]==0x78)
                    {
                        Unp->Forced=p;
                        break;
                    }
                }
            }
            Unp->DepAdr=0x439;
            if(mem[0x8ca]==0x4c)
                Unp->RetAdr=mem[0x8cb]|mem[0x8cc]<<8;
            else
            {
                for(p=0x8cb;p<0x8df;p++)
                {
                    if(mem[p]==0x4c)
                    {
                        Unp->RetAdr=mem[p+1]|mem[p+2]<<8;
                        break;
                    }
                }
                if(Unp->RetAdr==0x7e8)
                {
                    for(p=0x8e0;p<0x8fb;p++)
                    {
                        if(mem[p]==0x4c||mem[p]==0x20)
                        {
                            Unp->RetAdr=mem[p+1]|mem[p+2]<<8;
                            if(Unp->RetAdr<0xe000)
                                break;
                        }
                    }
                }
            }
            Unp->EndAdr=mem[0x8fc]|mem[0x8fd]<<8;
            Unp->fStrAf=0xfb;
            PrintInfo(Unp,_I_U_439);
            Unp->IdFlag=1;return;
        }
    }
}
