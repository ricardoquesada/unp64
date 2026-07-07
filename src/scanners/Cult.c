/* Cult packer? */
#include "../unp64.h"
void Scn_Cult(unpstr *Unp)
{
    unsigned char *mem;

    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x80d)==0x8500A978) &&
           (*(unsigned int*)(mem+0x813)==0x0821BD7D) &&
           (*(unsigned int*)(mem+0x83a)==0xFAB1FDE6) &&
           (*(unsigned int*)(mem+0x87f)==0xE602D0FC) )
        {
            Unp->DepAdr=0x100;
            Unp->Forced=0x80d;
            Unp->StrMem=mem[0x823]|(1+mem[0x828])<<8;
            Unp->EndAdr=mem[0x887]|mem[0x88d]<<8;
            Unp->RetAdr=mem[0x89a]|mem[0x89b]<<8;
            PrintInfo(Unp,_I_CULT);
            Unp->IdFlag=1;return;
        }
    }
}
