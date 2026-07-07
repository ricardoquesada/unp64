/*
   some Enigma releases are 1 filed IFFL (MFFL as Chrysagon calls it)
   Found in:

   JOSH+4M  _ENIGMA.prg         =   42186
   JOSH+4M  _ENIGMA.prg.080b    =   33867    after "unpacking" this layer
   MOONS+M  _ENIGMA.prg         =   39173
   MOONS+M  _ENIGMA.prg.0801    =   27401
   TROLLS+  _ENIGMA.prg         =   44215
   TROLLS+  _ENIGMA.prg.080b    =   22486 << half size!

*/
#include "../unp64.h"
void Scn_EnigmaMFFL(unpstr *Unp)
{
    unsigned char *mem;
    int p;
    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x80d)==0xBD01E678) &&
           (*(unsigned int*)(mem+0x811)==0x109D081E) &&
           (*(unsigned int*)(mem+0x815)==0x19E0E801) &&
           (*(unsigned int*)(mem+0x823)==0xE807FF9D) )
        {
            Unp->DepAdr=0x110;
            Unp->Forced=0x80b;
            p=mem[0x821]|mem[0x822]<<8;p+=1;
            Unp->StrMem=0x801;
            Unp->RetAdr=mem[0x835]|mem[0x836]<<8;
            Unp->EndAdr=Unp->info->end - p + Unp->StrMem -1;
            PrintInfo(Unp,_I_ENIGMAMFFL);
            Unp->IdFlag=1;return;
        }
    }
}
