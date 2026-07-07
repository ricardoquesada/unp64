/* DSC/RAF/PIC coder */
#include "../unp64.h"
void Scn_DSCcoder(unpstr *Unp)
{
    unsigned char *mem;
    int p;
    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        p=0x8f1;
        if((*(unsigned int*)(mem+p+0x000)==0xC0BD00A2) &&
           (*(unsigned int*)(mem+p+0x004)==0x04009D09) &&
           (*(unsigned int*)(mem+p+0x008)==0xBDF7D0E8) &&
           (*(unsigned int*)(mem+p+0x00c)==0x409D0820) &&
           (*(unsigned int*)(mem+p+0x093)==0x03148D31)   )
        {   /* modify unpacker to execute irq as sequential code. */
            mem[p+0x94]=0x2c;
            mem[p+0x99]=0x2c;
            mem[p+0xb0]=0x78;
            mem[p+0xe1]=0x00;
            mem[p+0xe4]=0x00;
            //mem[p+0x11d]=0x60;
            mem[p+0x11d]=0xd0;
            mem[p+0x11e]=0xe6;
            mem[p+0x13b]=0x60;
            *(unsigned int*)(mem+p+0x0cf  )=0xAD043120;
            *(unsigned int*)(mem+p+0x0cf+4)=0xF8D007CF;
            *(unsigned int*)(mem+p+0x0cf+8)=0x00A000A2;
            Unp->DepAdr=0x400;
            Unp->Forced=0x8f1;
            Unp->RetAdr=mem[p+0xfb]|mem[p+0xfc]<<8;
            Unp->EndAdr=0x2d;
            PrintInfo(Unp,_I_DSCCOD);
            Unp->IdFlag=1;return;
        }
    }
}
