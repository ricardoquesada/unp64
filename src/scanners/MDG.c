/* MDG Packer */
#include "../unp64.h"
void Scn_MDG(unpstr *Unp)
{
    unsigned char *mem;
    int q,p;
    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        p=Unp->info->run;
        if(p==0x818)
            p=0x800;
        else
            p=Unp->info->start;
        for (q=p+0x1b;p<q;p++)
        {
            if((mem[p+0x17]==0xD8) && (mem[p+0x34]==0x49) &&
               (*(unsigned int*)(mem+p+0x1d)==0x00BD77A2+((p+0x52)<<24)) &&
               (*(unsigned int*)(mem+p+0x28)==0xA2F410CA) &&
               //(*(unsigned int*)(mem+p+0x4b)==0x2E842D86) // pointers CAN be different than 2d/2e
               (mem[p+0x4b]==0x86) &&
               (mem[p+0x4d]==0x84) &&
               (mem[p+0x4f]==0x4c)
              )
            {
                break;
            }
        }
        if(p<q)
        {
            Unp->EndAdr=0xae;
            q=mem[p+0x35];
            Unp->StrMem=(mem[p+0xcb]^q)|(mem[p+0xcc]^q)<<8;
            Unp->DepAdr=mem[p+0x50]|mem[p+0x51]<<8;
            Unp->Forced=p+0x17;
            Unp->RetAdr=mem[p+0x52+0x6f]|(mem[p+0x52+0x70]<<8);
            if(mem[p+0x22]==0x5d) /* some have the xor nopped */
            {
                Unp->RetAdr^=mem[p+0x02+0x6f]|(mem[p+0x02+0x70]<<8);
            }
            Unp->RtAFrc=1;
            PrintInfo(Unp,_I_MDGPACK);
            Unp->IdFlag=1;return;
        }
    }
}
