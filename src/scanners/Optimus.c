/* Optimus $07c5 */
#include "../unp64.h"
void Scn_Optimus(unpstr *Unp)
{
    unsigned char *mem;
    int q;
    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        q=0x7c5;
        if( (*(unsigned int*)(mem+q+0x00)==0xA201E678) &&
            (*(unsigned int*)(mem+q+0x04)==0xCAFFA001) &&
            (*(unsigned int*)(mem+q+0x23)==0x01C6E2D0) &&
            (*(unsigned int*)(mem+q+0x33)==0xAD07FCCE) )
        {
            Unp->DepAdr=q;
            Unp->Forced=q;
            Unp->RetAdr=mem[q+0x29]|mem[q+0x2a]<<8;
            Unp->EndAdr=mem[q+0x09]|mem[q+0x0a]<<8;/*Unp->EndAdr++;*/
            Unp->fStrAf=0x07ce;
            Unp->StrAdC=0xffff|EA_USE_X;
            PrintInfo(Unp,_I_OPTIMUS);
            Unp->IdFlag=1;return;
        }
    }
    /* hack, relocated to $xxc5, no $01 set, often no final JMP
       found only in one demo "Ciacho/Seminary"
    */
    if( Unp->DepAdr==0 )
    {
        q=Unp->info->start;
        if( (q&0xff) == 0xc5 && mem[q+3]==0xa2 &&
            (*(unsigned int*)(mem+q+0x04)==0xCAFFA001) &&
           ((*(unsigned int*)(mem+q+0x23)&0x00ffffff)==0x0060E2D0) &&
            (*(unsigned int*)(mem+q+0x33)==((0xAD00FCCE)|(((int)q&0xff00)<<8))) )
        {
            Unp->DepAdr=q+3;
            Unp->Forced=q+3;
            if(mem[q+0x28]==0x4c)
                Unp->RetAdr=mem[q+0x29]|mem[q+0x2a]<<8;
            else
                Unp->RetAdr=q+0x25;
            Unp->RtAFrc=1;
            Unp->EndAdr=mem[q+0x09]|mem[q+0x0a]<<8;/*Unp->EndAdr++;*/
            Unp->fStrAf=q+0x09;
            Unp->StrAdC=0xffff|EA_USE_X;
            PrintInfo(Unp,_I_OPTIMH);
            Unp->IdFlag=1;return;
        }
    }
}
