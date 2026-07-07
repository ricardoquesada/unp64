/* Graf Binaer aka F4CG compactor 2.0 */
#include "../unp64.h"
void Scn_GrafBinaer(unpstr *Unp)
{
    unsigned char *mem;
    int p,q;
    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x828)==0x78094C1C) &&
           (*(unsigned int*)(mem+0x82c)==0x9ACA0034) &&
           (*(unsigned int*)(mem+0x838)==0x00607CC8) &&
           (*(unsigned int*)(mem+0x83c)==0xBC800594) )
        {
            Unp->Forced=0x828;
            /* decrypt the depacker in place when it needs the basic ROM */
            q=mem[0x84f]|mem[0x850]<<8;
            if( (q >= 0xa000) && (q < 0xc000) )
            {
                mem[0x84e]=0x2c; //084E  59 7B A0  EOR $A07B,Y
                for(p=0;p<0xdc;p++)
                    mem[p+0x863] ^= *(roms[0]+(q-0xa000)+p);
            }
            Unp->DepAdr=0x15a;
            Unp->fStrBf=0xae;
            Unp->EndAdr=0xae;
            //Unp->RetAdr=0x0800;
            PrintInfo(Unp,_I_GRFBIN);
            Unp->IdFlag=1;return;

        }
    }
}
