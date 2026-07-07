/* Byterapers packer */
#include "../unp64.h"
void Scn_Byterapers(unpstr *Unp)
{
    unsigned char *mem;

    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x811)==0x8534A978) &&
            (*(unsigned int*)(mem+0x849)==0x2A2AFEB1) &&
            (*(unsigned int*)(mem+0x84d)==0x07292A2A) &&
            (*(unsigned int*)(mem+0x8f1)==0xC6016420) )
        {
            Unp->DepAdr=0x100;
            Unp->Forced=0x811;
            Unp->StrMem=mem[0x83e]|mem[0x83f]<<8;
            Unp->EndAdr=0xfc;
            Unp->RetAdr=mem[0x86e]|mem[0x86f]<<8;
            PrintInfo(Unp,_I_BYTERAPERS1);
            Unp->IdFlag=1;return;
        }
    }
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x811)==0x8534A978) &&
            (*(unsigned int*)(mem+0x823)==0xE800009D) &&
            (*(unsigned int*)(mem+0x867)==0xD0013020) &&
            (*(unsigned int*)(mem+0x899)==0xFEA56868) )
        {
            Unp->DepAdr=0x100;
            Unp->Forced=0x811;
            Unp->StrMem=mem[0x83c]|mem[0x83d]<<8;
            Unp->EndAdr=0xfe;
            Unp->RetAdr=mem[0x8a9]|mem[0x8aa]<<8;
            if(*(unsigned int*)(mem+0x8a8)==0x4CA65920)
            {
                mem[0x8a8]=0x2c;
                Unp->RetAdr=mem[0x8ac]|mem[0x8ad]<<8;
            }
            PrintInfo(Unp,_I_BYTERAPERS2);
            Unp->IdFlag=1;return;
        }
    }
}
