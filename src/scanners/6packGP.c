/* 6pack/G*P by Six/G*P^DLoC (based on ZX0)
   found for example in Petrodungeon Preview V3/G*P
*/
#include "../unp64.h"
void Scn_6PackGP(unpstr *Unp)
{
    unsigned char *mem;
    int p=0;
    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x80d)==0x789AFFA2) &&
            (*(unsigned int*)(mem+0x819)==0x01009D08) &&
            (*(unsigned int*)(mem+0x81d)==0xD080E0E8) &&
            (*(unsigned int*)(mem+0x83d)==0x38EE0835) &&
            (*(unsigned int*)(mem+0x841)==0xEED0CA08) )
        {
            if (*(unsigned int*)(mem+0x854)==0x01004CFB)
            {
            	p=0x858;
            }
            else if (*(unsigned int*)(mem+0x861)==0x01004CF5)
            {
                p=0x865;
            }
            if(p)
            {
                Unp->Forced=0x80d;
                Unp->DepAdr=0x100;
                Unp->StrMem=mem[0x84e]|mem[0x852]<<8;
                Unp->RetAdr=mem[p+0x6b]|mem[p+0x6c]<<8;
                Unp->fEndAf=0xfa;
                PrintInfo(Unp,_I_6PACKGP);
                Unp->IdFlag=1;return;
            }
        }
    }
}
