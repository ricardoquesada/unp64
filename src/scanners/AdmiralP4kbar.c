/* Admiral P4kbar / Ferris/Logicoma */
#include "../unp64.h"
void Scn_AdmiralP4kbar(unpstr *Unp)
{
    unsigned char *mem;
    int p;
    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if( mem[0x80d]==0x78 )
        {
            for(p=0x80e;p<0x818;p++)
            {
                if(((*(unsigned int*)(mem+p)&0x00ffffff)==0x00A200A0) &&
                    (*(unsigned int*)(mem+p+0x020)==0x9486E895 ) &&
                    (*(unsigned int*)(mem+p+0x024)==0xD00F2998 ) &&
                    (*(unsigned int*)(mem+p+0x108)==0xA2600129 )
                  )
                {
                    Unp->Forced=0x80d;
                    Unp->DepAdr=mem[p+0x017]|mem[p+0x018]<<8;
                    Unp->StrMem=mem[p+0x130]|mem[p+0x131]<<8;
                    Unp->EndAdr=mem[p+0x0df]|mem[p+0x0e6]<<8;
                    Unp->RetAdr=mem[p+0x0ea]|mem[p+0x0eb]<<8;
                    Unp->RtAFrc=1;
                    break;
                }
            }
            if(Unp->DepAdr)
            {
                PrintInfo(Unp,_I_ADP4KBAR);
                Unp->IdFlag=1;return;
            }
        }
    }
}
