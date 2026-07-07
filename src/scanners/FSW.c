/* Florasoft packer/coder */
#include "../unp64.h"
void Scn_FSW(unpstr *Unp)
{
    unsigned char *mem;

    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x80d)==0x081EBD78) &&
           (*(unsigned int*)(mem+0x81a)==0x01004C01) &&
           (*(unsigned int*)(mem+0x88c)==0xD003A201) &&
           (*(unsigned int*)(mem+0x8dc)==0x8CD08AE2) )
        {
            Unp->DepAdr=0x100;
            Unp->Forced=0x80d;
            Unp->StrMem=0x800;
            if(mem[0x887]==0x4c)
                Unp->RetAdr=mem[0x888]|mem[0x889]<<8;
            mem[0xaa]=0x00; // assumes it's 0, starts always at $800
            Unp->EndAdr=0xaa;
            PrintInfo(Unp,_I_FSWPACK1);
            Unp->IdFlag=1;return;
        }
    }
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x80d)==0xBD00A278) &&
           (*(unsigned int*)(mem+0x811)==0x009D0822) &&
           (*(unsigned int*)(mem+0x81e)==0x01004C01) &&
           (*(unsigned int*)(mem+0x894)==0xD003A201) &&
           (*(unsigned int*)(mem+0x8e5)==0x8bD08AE2) )
        {
            Unp->DepAdr=0x100;
            Unp->Forced=0x80d;
            Unp->StrMem=0x800;
            if(mem[0x88f]==0x4c)
                Unp->RetAdr=mem[0x890]|mem[0x891]<<8;
            mem[0xfc]=0x00; // assumes it's 0, starts always at $800
            Unp->EndAdr=0xfc;
            PrintInfo(Unp,_I_FSWPACK2);
            Unp->IdFlag=1;return;
        }
    }
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x827)==0x0834BD78) &&
           (*(unsigned int*)(mem+0x82b)==0x349DEA49) &&
           (*(unsigned int*)(mem+0x837)==0xC31AEA0A) &&
           (*(unsigned int*)(mem+0x83b)==0xEA0A174C) )
        {
            Unp->DepAdr=0x334;
            Unp->Forced=0x827;
            Unp->StrMem=0x801;
            /* remove antihack protection which would format and reset */
            memset(mem+0x83d,0,0x90); /* $ea eor $ea =) */
            if(*(unsigned int*)(mem+0x8fa)==0xA64CB3CA) /* jsr $a659 (eor $ea) */
                mem[0x8fa]=0x2c^0xea;
            Unp->RetAdr=0xa7ae;
            Unp->EndAdr=Unp->info->end-0xff;
            PrintInfo(Unp,_I_FSWPROT);
            Unp->IdFlag=1;return;
        }
    }
    /* sys 2061 */
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x80e)==0x9D081CBD) &&
            (*(unsigned int*)(mem+0x82e)==0xCE0106CE) &&
            (*(unsigned int*)(mem+0x84e)==0x49AA12F0) &&
            (*(unsigned int*)(mem+0x85e)==0xE4D0ABE6) )
        {
            Unp->Forced=0x80e;
            Unp->DepAdr=0x100;
            Unp->RetAdr=mem[0x866]|mem[0x867]<<8;
            Unp->StrMem=mem[0x83f]|mem[0x843]<<8;
            Unp->EndAdr=0xaa;
            PrintInfo(Unp,_I_FSWPACK3);
            Unp->IdFlag=1;return;
        }
    }
}
