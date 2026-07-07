/* Abyss coder, probably an hack of ASC/SCF protector */
#include "../unp64.h"
void Scn_AbyssCoder(unpstr *Unp)
{
    unsigned char *mem;
    int p;
    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        p=0x815;
        if((*(unsigned int*)(mem+p+0x000)==0x00A98CC2) &&
           (*(unsigned int*)(mem+p+0x004)==0x3CAE91A8) &&
           (*(unsigned int*)(mem+p+0x008)==0x0DAD8E8A) &&
           (*(unsigned int*)(mem+  0x86a)==0x046E4B2E) )
        {
            Unp->DepAdr=0x46e;
            Unp->Forced=p;
            Unp->EndAdr=0x2d;
            Unp->StrMem=0x801;
            PrintInfo(Unp,_I_ABYSSCOD1);
            Unp->IdFlag=1;return;
        }
    }
    if( Unp->DepAdr==0 )
    {
        p=0x815;
        if((*(unsigned int*)(mem+p+0x000)==0xE8080DAE) &&
           (*(unsigned int*)(mem+p+0x004)==0xE8E8E8E8) &&
           (*(unsigned int*)(mem+  0x835)==0xCACACACA) &&
           (*(unsigned int*)(mem+  0x86a)==0x03FF4C2E) )
        {
            Unp->Forced=p;
            p=mem[0x84a]; /* xorval */
            if(((mem[0x8de]^p) == 0x20) &&
               ((mem[0x8df]^p) == 0x59) &&
               ((mem[0x8e0]^p) == 0xa6) )
            {
                mem[0x8de]=0x2c^p;
                Unp->RetAdr=(mem[0x8e5]^p)|(mem[0x8e6]^p)<<8;
            }
            Unp->DepAdr=0x33c;
            Unp->EndAdr=0x2d;
            Unp->StrMem=0x801;
            PrintInfo(Unp,_I_ABYSSCOD2);
            Unp->IdFlag=1;return;
        }
    }
}
