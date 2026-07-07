/* MartinPiper's LZMi (compress.exe found in codebase64.org) */
#include "../unp64.h"
void Scn_MartinPiper(unpstr *Unp)
{
    unsigned char *mem;

    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if(((*(unsigned int*)(mem+0x80d)&0xffffff00)==0x8520A900)&&
            (*(unsigned int*)(mem+0x811)==0xBDCBA201)&&
            (*(unsigned int*)(mem+0x815)==0x4F9D082B)&&
            (*(unsigned int*)(mem+0x98a)==0x5BA55185) )
        {
            Unp->Forced=0x080e;
            Unp->DepAdr=0x6d;
            Unp->RetAdr=mem[0x8e5]|mem[0x8e6]<<8;
            Unp->StrMem=mem[0x836]|mem[0x837]<<8;
            Unp->fEndAf=0x5a;
            Unp->EndAdC=0xffff;
            PrintInfo(Unp,_I_LZMPI1);
            Unp->IdFlag=1;return;
        }
    }
    if( Unp->DepAdr==0 )
    {
        if(((*(unsigned int*)(mem+0x80d)&0xffffff00)==0x8520A900)&&
            (*(unsigned int*)(mem+0x811)==0xBD33A201)&&
            (*(unsigned int*)(mem+0x815)==0x4F95082f)&&
            (*(unsigned int*)(mem+0x98e)==0x5BA55185) )
        {
            Unp->Forced=0x080e;
            Unp->DepAdr=0x6d;
            Unp->RetAdr=mem[0x8e9]|mem[0x8ea]<<8;
            Unp->StrMem=mem[0x83a]|mem[0x83b]<<8;
            Unp->fEndAf=0x5a;
            Unp->EndAdC=0xffff;
            PrintInfo(Unp,_I_LZMPI2);
            Unp->IdFlag=1;return;
        }
    }
    /* new version dated 7 feb 2025
    https://github.com/martinpiper/C64Public/blob/master/bin/LZMPi.exe
    */
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x80d)==0x9AFFA278)&&
            (*(unsigned int*)(mem+0x811)==0x018520A9)&&
            (*(unsigned int*)(mem+0x815)==0x9D0820BD)&&
            (*(unsigned int*)(mem+0x87F)==0xFF49A8FF) )
        {
            Unp->Forced=0x080d;
            Unp->DepAdr=0x100;
            if(mem[0x8AE]==0x4c)
            {
                Unp->RetAdr=mem[0x8AF]|mem[0x8B0]<<8;
            }
            else if((mem[0x8AE]==0xA9)&&(mem[0x8B2]==0x4c))
            {
                Unp->RetAdr=mem[0x8B3]|mem[0x8B4]<<8;
            }
            Unp->StrMem=mem[0x821]|mem[0x822]<<8;
            Unp->fEndAf=0xf8;
            Unp->EndAdC=0xffff;
            PrintInfo(Unp,_I_LZMPI3UM);
            Unp->IdFlag=1;return;
        }
    }
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x80d)==0x9AFFA278)&&
            (*(unsigned int*)(mem+0x811)==0x018520A9)&&
            (*(unsigned int*)(mem+0x815)==0xE6BD00A2)&&
            (*(unsigned int*)(mem+0x857)==0x8F4CEDD0) )
        {
            Unp->Forced=0x080d;
            Unp->DepAdr=0x100;
            Unp->RetAdr=mem[0x8e8]|mem[0x8e9]<<8;
            Unp->StrMem=mem[0x833]|mem[0x834]<<8;
            Unp->fEndAf=0x4c;
            Unp->EndAdC=0xffff;
            PrintInfo(Unp,_I_LZMPI3M);
            Unp->IdFlag=1;return;
        }
    }
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x80d)==0x8520A978)&&
            (*(unsigned int*)(mem+0x811)==0xBD33A201)&&
            (*(unsigned int*)(mem+0x815)==0x4F95082F)&&
            (*(unsigned int*)(mem+0x82b)==0x6D4CF1D0) )
        {
            Unp->Forced=0x080d;
            Unp->DepAdr=0x6d;
            Unp->RetAdr=mem[0x900]|mem[0x901]<<8;
            Unp->StrMem=mem[0x83a]|mem[0x83b]<<8;
            Unp->fEndAf=0x5a;
            Unp->EndAdC=0xffff;
            PrintInfo(Unp,_I_LZMPI3E);
            Unp->IdFlag=1;return;
        }
    }
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x80d)==0x9AFFA278)&&
            (*(unsigned int*)(mem+0x811)==0x018520A9)&&
            (*(unsigned int*)(mem+0x815)==0x23BD00A2)&&
            (*(unsigned int*)(mem+0x81F)==0x00E44CF7)&&
            (*(unsigned int*)(mem+0x848)==0xFA4CEDD0) )
        {
            Unp->Forced=0x080d;
            Unp->DepAdr=0xe4;
            Unp->RetAdr=mem[0x87e]|mem[0x87f]<<8;
            Unp->StrMem=mem[0x824]|mem[0x825]<<8;
            Unp->fEndAf=0xd1;
            Unp->EndAdC=0xffff;
            PrintInfo(Unp,_I_LZMPI3RM);
            Unp->IdFlag=1;return;
        }
    }
}
