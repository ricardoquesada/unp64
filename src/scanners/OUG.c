/* OUG? autostarer and decrypt */
#include "../unp64.h"
void Scn_OUG(unpstr *Unp)
{
    unsigned char *mem;

    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if(Unp->info->run == -1)
    {
        if(Unp->info->start == 0x326 )
        {
            if( (*(unsigned int*)(mem+0x326)==0xF6ED0334) &&
                (*(unsigned int*)(mem+0x336)==0x268DCAA9) &&
                (*(unsigned int*)(mem+0x3ba)==0xCA80039D) )
            {
                Unp->DepAdr=0x335;
                Unp->Forced=Unp->DepAdr;
                Unp->RetAdr=0xa7ae;
                Unp->StrMem=0x0801;
                /* carry IS set on start and is needed for an adc#$03 intended
                   as 3+1 (move $401 to $801)
                */
                mem[0x335]=0x38;
                /* jsr $a3bf -> jsr $02bf */
                mem[0x372]=0x02;
                memcpy(mem+0x2bf,roms[0]+0x03bf,0x40);
                Unp->EndAdr=Unp->info->end+0x400;
                PrintInfo(Unp,_I_OUGCOD);
                Unp->IdFlag=1;return;
            }
        }
    }
}
