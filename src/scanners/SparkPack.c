/* Spark Packer  (temp name)
   found in Spark cracks
*/
#include "../unp64.h"
void Scn_SparkPack(unpstr *Unp)
{
    unsigned char *mem;
    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x80d)==0x844CA078) &&
            (*(unsigned int*)(mem+0x813)==0xFA990843) &&
            (*(unsigned int*)(mem+0x84F)==0x3C202CF0) &&
            (*(unsigned int*)(mem+0x879)==0x01004CF1) )
        {
            Unp->Forced=0x80d;
            Unp->DepAdr=0x100;
            Unp->StrMem=mem[0x847]|mem[0x858]<<8;
            Unp->RetAdr=mem[0x883]|mem[0x884]<<8;
            Unp->fEndAf=0xfe;
            PrintInfo(Unp,_I_SPARKPACK);
            Unp->IdFlag=1;return;
        }
    }
}
