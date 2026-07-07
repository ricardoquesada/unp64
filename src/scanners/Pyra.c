/* packer&coder by Italian Stallion/Pyra */
#include "../unp64.h"
void Scn_Pyra(unpstr *Unp)
{
    unsigned char *mem;
    int p,q;
    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x80d)==0x00A05DA2) &&
            (*(unsigned int*)(mem+0x81b)==0xA208075D) &&
            (*(unsigned int*)(mem+0x81f)==0x04009D00) &&
            (*(unsigned int*)(mem+0x827)==0xC208216C) )
        {
            Unp->DepAdr=0x400;
            Unp->Forced=0x80d;
            Unp->StrMem=0x801;
            Unp->EndAdr=Unp->info->end-0x87;
            PrintInfo(Unp,_I_PYRACOD1);
            Unp->IdFlag=1;return;
        }
    }
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x80d)==0x2BBD00A2) &&
            (*(unsigned int*)(mem+0x828)==0xA001004C) &&
            (mem[0x834]==0x5d) &&
            (*(unsigned int*)(mem+0x84b)==0xFCA5FCE6) )
        {
            Unp->DepAdr=0x100;
            Unp->Forced=0x80d;
            Unp->StrMem=mem[0x821]|mem[0x825]<<8;
            Unp->EndAdr=Unp->info->end-0x54;
            p=mem[0x835]|mem[0x836]<<8;
            q=p-0xe000;
            memcpy(mem+p, roms[1]+q,0x100);
            PrintInfo(Unp,_I_PYRACOD2);
            Unp->IdFlag=1;return;
        }
    }
}
