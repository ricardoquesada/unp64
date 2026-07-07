/* XDS Coder v1 */
#include "../unp64.h"
void Scn_XDScoder(unpstr *Unp)
{
    unsigned char *mem;

    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x811)==0xA0E54420) &&
           (*(unsigned int*)(mem+0x839)==0xB2A901E6) &&
           (*(unsigned int*)(mem+0x83d)==0xFC8508A2) &&
           (*(unsigned int*)(mem+0x85d)==0x1849FCB1) )
        {
            Unp->DepAdr=0x100;
            Unp->Forced=0x811;
            Unp->RetAdr=mem[0x89d]|mem[0x89e]<<8;
            Unp->EndAdr=Unp->info->end-0xb1;
            Unp->StrMem=0x0801;
            PrintInfo(Unp,_I_XDSV1);
            Unp->IdFlag=1;return;
        }
    }
    /* XDS Coder v2 */
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x80d)==0x8536A978) &&
           (*(unsigned int*)(mem+0x813)==0x804907E7) &&
           (*(unsigned int*)(mem+0x82b)==0x03344CF5) &&
           (*(unsigned int*)(mem+0x86a)==0xE78D8049) )
        {
            Unp->DepAdr=0x334;
            Unp->Forced=0x80d;
            Unp->RetAdr=mem[0x871]|mem[0x872]<<8;
            Unp->EndAdr=Unp->info->end-0x75;
            Unp->StrMem=0x0801;
            PrintInfo(Unp,_I_XDSV2);
            Unp->IdFlag=1;return;
        }
    }
    /* XDS Coder v3 */
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x80d)==0x08A2A3A9) &&
           (*(unsigned int*)(mem+0x841)==0x29590428) &&
           (*(unsigned int*)(mem+0x89f)==0xAD754C70) )
        {
            Unp->DepAdr=0x100;
            Unp->Forced=0x80d;
            Unp->RetAdr=0xa7ae;
            Unp->EndAdr=Unp->info->end-0xa2;
            Unp->StrMem=0x0801;
            PrintInfo(Unp,_I_XDSV3);
            Unp->IdFlag=1;return;
        }
    }
    /* this version searches for "run" or "rU" on screen, else decrypt fails */
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x80b)==0x041800A0) &&
           (*(unsigned int*)(mem+0x813)==0x0826B99A) &&
           (*(unsigned int*)(mem+0x817)==0xB900FA99) &&
           (*(unsigned int*)(mem+0x857)==0x10D01249) )
        {
            Unp->DepAdr=0x100;
            Unp->Forced=0x80b;
            Unp->EndAdr=Unp->info->end-0xb6;
            Unp->StrMem=0x0801;
            mem[0x400]=0x12;
            mem[0x401]=0x15;
            PrintInfo(Unp,_I_XDSK1);
            Unp->IdFlag=1;return;
        }
    }
    /* this uses also kernal fixed values */
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x80d)==0x8D0BA978) &&
           (*(unsigned int*)(mem+0x816)==0xBAA901C6) &&
           (*(unsigned int*)(mem+0x82a)==0x38E015AF) &&
           (*(unsigned int*)(mem+0x86b)==0xECDF6C10) )
        {
            mem[0x82a]=0xa9; /* LAX $E015 -> lda #$81 tax */
            mem[0x82b]=0x81;
            mem[0x82c]=0xaa;
            mem[0x86c]=0x4c; /* JMP ($ECDF) -> jmp $0100 */
            mem[0x86d]=0x00;
            mem[0x86e]=0x01;
            Unp->DepAdr=0x100;
            Unp->Forced=0x80d;
            Unp->EndAdr=Unp->info->end-0xbb;
            Unp->RetAdr=0xa7ae;
            Unp->StrMem=0x0801;
            PrintInfo(Unp,_I_XDSK2);
            Unp->IdFlag=1;return;
        }
    }
    /* this combines kernal codes and check for "run" on screen */
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x80b)==0x6E7800A0) &&
           (*(unsigned int*)(mem+0x816)==0xFD8504A9) &&
           (*(unsigned int*)(mem+0x822)==0x13D01249) &&
           (*(unsigned int*)(mem+0x84e)==0x38E015AF) )
        {
            mem[0x400]=0x12;
            mem[0x401]=0x15;
            mem[0xb2]=0;
            mem[0xb3]=3;
            mem[0xc3]=1; /* must be inited pointing to $0801 */
            mem[0xc4]=8;
            mem[0x84e]=0xa9; /* LAX $E015 -> lda #$81 tax */
            mem[0x84f]=0x81;
            mem[0x850]=0xaa;
            mem[0x8a5]=0x4c; /* JMP ($FB11) -> jmp $0100 */
            mem[0x8a6]=0x00;
            mem[0x8a7]=0x01;
            Unp->DepAdr=0x100;
            Unp->Forced=0x80b;
            Unp->EndAdr=Unp->info->end-0xea;
            Unp->RetAdr=0xa7ae;
            Unp->StrMem=0x0801;
            PrintInfo(Unp,_I_XDSK3);
            Unp->IdFlag=1;return;
        }
    }
}
