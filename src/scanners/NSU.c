/* NSU packer, Betaskip & NSU 1.1 both by Crisp/Action */
#include "../unp64.h"
void Scn_NSU(unpstr *Unp)
{
    unsigned char *mem;

    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if(/*((*(unsigned int*)(mem+0x80d)&0xff00ffff)==0x9A00A278) &&*/
            (*(unsigned int*)(mem+0x811)==0x1EBD49A2) &&
            (*(unsigned int*)(mem+0x81f)==0x0FB1E800) &&
            (*(unsigned int*)(mem+0x82f)==0xE602D0C8) )
        {
            if(mem[0x80e]==0xa2)
                Unp->Forced=0x80e;
            else
                Unp->Forced=0x811;
            Unp->DepAdr=mem[0x81e]|mem[0x81f]<<8;
            if(Unp->DepAdr==0x37)
            {
                Unp->EndAdr=0x1e;
                Unp->StrMem=mem[0x83c]|mem[0x83d]<<8;
                Unp->RetAdr=mem[0x853]|mem[0x854]<<8;
                PrintInfo(Unp,_I_NSUPACK11);
            }
            else if(Unp->DepAdr==0x35)
            {
                Unp->EndAdr=0x19;
                Unp->StrMem=mem[0x837]|mem[0x838]<<8;
                Unp->RetAdr=mem[0x851]|mem[0x852]<<8;
                PrintInfo(Unp,_I_NSUPACK10);
            }
            Unp->IdFlag=1;return;
        }
    }
}
