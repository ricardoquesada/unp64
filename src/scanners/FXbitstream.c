/* bitstreamer  */
#include "../unp64.h"
void Scn_FXbitstream(unpstr *Unp)
{
    unsigned char *mem;
    int p,q;
    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    /* FX bitstream  */
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x811)==0x9AFFA278) &&
            (*(unsigned int*)(mem+0x815)==0x018400A0) &&
            (*(unsigned int*)(mem+0x819)==0x2EC607A2) &&
            (*(unsigned int*)(mem+0x889)==0x0E0430FF) )
        {
            Unp->DepAdr=0x100;
            Unp->Forced=0x811;
            Unp->StrMem=mem[0x875]|mem[0x876]<<8;
            Unp->EndAdr=mem[0x8a4]|mem[0x8a6]<<8; /* sets $ae and $2d */
            Unp->RetAdr=mem[0x8b3]|mem[0x8b4]<<8;
            PrintInfo(Unp,_I_FXBITST);
            Unp->IdFlag=1;return;
        }
    }
    /* bitstreamer 1.1/frank bossen in 1991*/
    if( Unp->DepAdr==0 )
    {
        if((mem[0x810]==0x85)&&
           (mem[0x811]==0x01)&&
           (mem[0x812]==0x4c) )
        {
            p=mem[0x813]|mem[0x814]<<8;
            q=mem[p+1]|mem[p+2]<<8; /* should be exactly p-0x100 */
            if( (q==(p-0x100))&&(mem[p]==0xbd)&&
                (*(unsigned int*)(mem+p+0x03)==0xBD07159D) &&
                (*(unsigned int*)(mem+p+0x18)==0x07154CF8) )
            {
                Unp->DepAdr=0x715;
                if(Unp->info->run==-1)
                {
                    Unp->Forced=0x80b;
                }
                Unp->fStrAf=0xfc;
                Unp->StrAdC=0xffff;
                Unp->EndAdr=mem[p+0x27]|mem[p+0x28]<<8;
                Unp->RetAdr=mem[q+0x8d]|mem[q+0x8e]<<8;
                PrintInfo(Unp,_I_BITST11);
                Unp->IdFlag=1;return;
            }
        }
    }
}
