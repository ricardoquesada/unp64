/* Rows Cruncher by RCC/Spirit */
#include "../unp64.h"
void Scn_Rows(unpstr *Unp)
{
    unsigned char *mem;
    int q=0,i;
    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        for(i=0x800;i<0x830;i++)
        {
            if(!q&&(mem[i]==0xa0)&&(mem[i+1]==0x00))
                q=i;
            if( (mem[i]==0x4c)&&
                (*(unsigned int*)(mem+i+0x03)==0x02D0FAA5) &&
                (*(unsigned int*)(mem+i+0x2c)==0xDD4830CA) &&
                (*(unsigned int*)(mem+i+0x30)==0xF8D00500) )
            {
                Unp->DepAdr=0x152;
                break;
            }
        }
        if(Unp->DepAdr)
        {
            Unp->RetAdr=mem[i+1]|mem[i+2]<<8;
            if(q&&(Unp->info->run == -1))
                Unp->Forced=q;
            Unp->fStrAf=0xfe;
            Unp->EndAdr=mem[i+0x1a]|mem[i+0x1b]<<8;/*Unp->EndAdr++;*/
            PrintInfo(Unp,_I_ROWS);
            Unp->IdFlag=1;return;
        }
    }
}
