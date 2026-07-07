/* ALZ64/Kabuto */
#include "../unp64.h"
void Scn_ALZ64(unpstr *Unp)
{
    unsigned char *mem;
    int q,p;
    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if(((*(unsigned int*)(mem+0x80b)&0xffffff00)==0x86780000) &&
            (*(unsigned int*)(mem+0x818)==0xCEF7D0CA) &&
            (*(unsigned int*)(mem+0x822)==0x03A2EED0) &&
            (*(unsigned int*)(mem+0x835)==0x005E4CF1) )
        {
            p=mem[0x813]|mem[0x814]<<8;
            if(mem[p+0xfd]==0x4c)
            {
                mem[0x80b]=0xa2; // Phuture/Arise
                Unp->RetAdr=mem[p+0xfe]|mem[p+0xff]<<8;
                Unp->DepAdr=0x05e;
                Unp->Forced=0x80b;
                Unp->EndAdr=0xcf;
                Unp->EndAdC=0xffff;
                for(q=p+0xe6;q<p+0xf0;q++)
                {
                    if(*(unsigned int*)(mem+q)==0x8dc7e602)
                    {
                        Unp->StrMem=mem[q+0x04]|mem[q+0x05]<<8;
                        break;
                    }
                }
                PrintInfo(Unp,_I_ALZ64);
                Unp->IdFlag=1;return;
            }
        }

        /* altered by Quiss/Reflex in "Boo!" */
        if( (*(unsigned int*)(mem+0x80b)==0xB57800A2) &&
            (*(unsigned int*)(mem+0x819)==0x03A2F3D0) &&
            (*(unsigned int*)(mem+0x824)==0x388910A2) &&
            (*(unsigned int*)(mem+0x82c)==0x005E4CF1) )
        {
            p=mem[0x814]|mem[0x815]<<8;
            if(mem[p+0xf1]==0x4c)
            {
                Unp->RtAFrc=1;
                Unp->RetAdr=mem[p+0xf2]|mem[p+0xf3]<<8;
                Unp->DepAdr=0x05e;
                Unp->Forced=0x80b;
                Unp->EndAdr=0xcf;
                Unp->EndAdC=0xffff;
                //Unp->StrMem=0x2000;
                for(q=p+0xcb;q<p+0xf0;q++)
                {
                    if(*(unsigned int*)(mem+q)==0x8dc7e602)
                    {
                        Unp->StrMem=mem[q+0x04]|mem[q+0x05]<<8;
                        break;
                    }
                }
                PrintInfo(Unp,_I_ALZ64Q);
                Unp->IdFlag=1;return;
            }
        }
    }
}
