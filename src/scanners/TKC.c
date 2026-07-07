/* TKC Equal bytepress */
#include "../unp64.h"
void Scn_TKC(unpstr *Unp)
{
    unsigned char *mem;

    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x80b)==0xE67800A2) &&
            (*(unsigned int*)(mem+0x812)==0x9D081DBD) &&
            (*(unsigned int*)(mem+0x82b)==0x0102EEF7) &&
            (*(unsigned int*)(mem+0x83b)==0x85FFA5AE) )
        {
            if(*(unsigned int*)(mem+0x845)==0x8120018C)
            {
                Unp->Forced=0x80b;
                Unp->DepAdr=0x100;
                Unp->EndAdr=mem[0x821]|mem[0x822]<<8;
                Unp->fStrAf=0xfe;
                Unp->RetAdr=mem[0x869]|mem[0x86a]<<8;
                if(Unp->RetAdr==0xa659)
                {
                    mem[0x868]=0x2c;
                    Unp->RetAdr=mem[0x86c]|mem[0x86d]<<8;
                }
                PrintInfo(Unp,_I_TKCEQB1);
                Unp->IdFlag=1;return;
            }
            if(*(unsigned int*)(mem+0x845)==0x7e20018b)
            {
                Unp->Forced=0x80b;
                Unp->DepAdr=0x100;
                Unp->EndAdr=mem[0x821]|mem[0x822]<<8;
                Unp->fStrAf=0xfe;
                Unp->RetAdr=mem[0x85a]|mem[0x85b]<<8;
                if(Unp->RetAdr==0xa659)
                {
                    mem[0x859]=0x2c;
                    Unp->RetAdr=mem[0x85d]|mem[0x85e]<<8;
                }
                PrintInfo(Unp,_I_TKCEQB2);
                Unp->IdFlag=1;return;
            }
        }
    }
}
