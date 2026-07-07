/* Jazzcat cruncher(?) */
#include "../unp64.h"
void Scn_Jazzcat(unpstr *Unp)
{
    unsigned char *mem;
    int q,p;
    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        q=0x81A;
        p=0x93c;
        if((*(unsigned int*)(mem+q+0x00)==0x40B900A0) &&
           (*(unsigned int*)(mem+q+0x04)==0x03349909) &&
           (*(unsigned int*)(mem+q+0x08)==0x990859B9) &&
           (*(unsigned int*)(mem+q+0x0c)==0xD0C80500) &&
           (*(unsigned int*)(mem+p     )==0x053C4C03) )
        {
            Unp->DepAdr=0x500;
            if(Unp->info->run == -1)
                Unp->Forced=0x81a;
            q=0x8da+4;
            Unp->RetAdr=mem[q]|mem[q+1]<<8;
            Unp->fEndAf=0x53d;
            Unp->StrMem=mem[0x896]|mem[0x897]<<8;
            if((Unp->StrMem==0x814) && (Unp->RetAdr==0x814)) /* next layer uses leftover pointers */
                Unp->StrMem=0x53d;
            PrintInfo(Unp,_I_JCTCR);
            Unp->IdFlag=1;return;
        }
    }
    if( Unp->DepAdr==0 )
    {
        q=0x814;
        p=0x53d;
        if((*(unsigned int*)(mem+q+0x00)==0x85053DAD) &&
           (*(unsigned int*)(mem+q+0x04)==0x053EADAE) &&
           (*(unsigned int*)(mem+q+0x08)==0xFFA0AF85) &&
           (*(unsigned int*)(mem+q+0x8e)==0x00FD6C58) )
        {
            Unp->DepAdr=0x100;
            Unp->Forced=0x810;
            /* if it's not complete with previous layer better patch */
            if((*(unsigned int*)(mem+p+2)!=0x3DEEFBA5) )
            {
                mem[0x817]=0x24;
                mem[0x81C]=0x24;
            }
            mem[0x80f]=0x78;
            mem[0x810]=0xa9;
            mem[0x811]=0x34;
            mem[0x812]=0x85;
            mem[0x813]=0x01;
            Unp->RetAdr=mem[0x853]|mem[0x854]<<8;
            if(Unp->RetAdr == 0x124)
                Unp->RetAdr = 0xa7ae;
            Unp->fEndAf=0xfb;
            Unp->StrMem=mem[0x851]|mem[0x852]<<8;
            PrintInfo(Unp,_I_JCTPACK);
            Unp->IdFlag=1;return;
        }
    }
}
