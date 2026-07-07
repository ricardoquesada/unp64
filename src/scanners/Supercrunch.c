/* Supercrunch */
#include "../unp64.h"
void Scn_Supercrunch(unpstr *Unp)
{
    unsigned char *mem;
    int p=0;

    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x818)==0xB9C0A001) &&
            (*(unsigned int*)(mem+0x81c)==0xF899082C) &&
            (*(unsigned int*)(mem+0x93c)==0x606802F0) )
        {
            Unp->DepAdr=0;
            if( (*(unsigned int*)(mem+0x810)==0x9AFBA278) &&
                (*(unsigned int*)(mem+0x814)==0x8538A9D8) )
            {
                Unp->DepAdr=0x100;
                Unp->Forced=0x810;
                p=0x946;
            }
            else if( (*(unsigned int*)(mem+0x810)==0xA2780000) &&
                     (*(unsigned int*)(mem+0x814)==0x8538A9FB) )
            {
                Unp->DepAdr=0x100;
                Unp->Forced=0x812;
                p=0x944;
            }
            if(Unp->DepAdr)
            {
                Unp->EndAdr=mem[0x832]|mem[0x833]<<8;
                while(p<0x94c)
                {
                    if((mem[p]!=0x20)&&(mem[p]!=0x4c))
                        p++;
                    else
                        break;
                }
                Unp->RetAdr=mem[p+1]|mem[p+2]<<8;
                if(((Unp->RetAdr==0xa871)&&(mem[p]==0x20))||
                   ((mem[p]!=0x20)&&(mem[p]!=0x4c)))
                {
                    mem[p]=0x2c;
                    Unp->RetAdr=mem[p+4]|mem[p+5]<<8;
                }
                Unp->fStrAf=0x104;
                Unp->StrAdC=0xffff;
                PrintInfo(Unp,_I_SUPCRUNCH);
                Unp->IdFlag=1;return;
            }
        }
    }
}
