/* WGI Coder */
#include "../unp64.h"
void Scn_WGIcoder(unpstr *Unp)
{
    unsigned char *mem;

    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        /*found also altered by TWG so better make this generic*/
        if((*(unsigned int*)(mem+0x826)==0x4D0831BD) &&
           (*(unsigned int*)(mem+0x82c)==0xe808319D) &&
           (*(unsigned int*)(mem+0x987)==0x2A3E67E0) )
        {
            Unp->DepAdr=0x336;
            Unp->Forced=0x81e;
            Unp->RetAdr=(mem[0x98b]^0x66)|(mem[0x98c]^0x66)<<8;
            Unp->EndAdr=0xae;
            PrintInfo(Unp,_I_WGICOD);
            Unp->IdFlag=1;return;
        }
    }
}
