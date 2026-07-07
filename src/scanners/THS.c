/* THS coder */
#include "../unp64.h"
void Scn_THS(unpstr *Unp)
{
    unsigned char *mem;

    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x82a)==0xFDA32078) &&
           (*(unsigned int*)(mem+0x82e)==0x3CEF0345) &&
           (*(unsigned int*)(mem+0x83a)==0xD1E7083F) &&
           (*(unsigned int*)(mem+0x83e)==0xFC0EB0FA) )
        {
            Unp->DepAdr=0x345;
            Unp->Forced=0x82a;
            //Unp->fEndAf=0x2d;
            Unp->EndAdr=Unp->info->end-0xa2;
            mem[0x0003]=0xaa;
            mem[0x00b2]=0x3c;
            mem[0x00b3]=0x03;
            mem[0xe055]=0x00;
            mem[0xfb0d]=0x35;
            mem[0x0288]=0x04;
            memset(mem+0x07f8, 0xff,8);
            memcpy(mem+0xf222, roms[1]+0x1222,0x100);
            //Unp->RetAdr=0x801;
            PrintInfo(Unp,_I_THSCOD);
            Unp->IdFlag=1;return;
        }
    }
}
