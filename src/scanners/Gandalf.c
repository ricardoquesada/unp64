/* Gandalf packer */
#include "../unp64.h"
void Scn_Gandalf(unpstr *Unp)
{
    unsigned char *mem;
    int q,p;
    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        q=0x801;
        if( (*(unsigned int*)(mem+q+0x10)==0x01C600A0) &&
            (*(unsigned int*)(mem+q+0x14)==0x990820B9) &&
            (*(unsigned int*)(mem+q+0x18)==0xD0880333) &&
            (*(unsigned int*)(mem+q+0x1c)==0x03344CF7) &&
            (*(unsigned int*)(mem+q+0x31)==0x76201ED0) )
        {
            Unp->DepAdr=0x334;
            if(*(unsigned int*)(mem+q+0x3c)==0xA9E51820)
               mem[q+0x3c]=0x2c;
            Unp->Forced=0x811;
            p=0x47;
            Unp->RetAdr=mem[q+p+1]|mem[q+p+2]<<8;
            if((mem[q+p]==0x20)&&(mem[q+p+3]==0x4c))
            {
                if((Unp->RetAdr == 0xa659) ||
                   (Unp->RetAdr == 0xff81) ||
                   (Unp->RetAdr == 0xe3bf) ||
                   (Unp->RetAdr == 0xe5a0) ||
                   (Unp->RetAdr == 0xe518) )
                {
                    mem[q+p]=0x2c;
                    Unp->RetAdr=mem[q+p+4]|mem[q+p+5]<<8;
                }
            }
            Unp->EndAdr=mem[q+0x40]|mem[q+0x42]<<8;/*Unp->EndAdr++;*/
            Unp->fStrAf=0x367;
            Unp->StrAdC=0xffff|EA_USE_Y|EA_ADDFF;
            PrintInfo(Unp,_I_GANDALF);
            Unp->IdFlag=1;return;
        }
    }
}
