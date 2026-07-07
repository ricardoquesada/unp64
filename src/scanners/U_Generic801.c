/* generic $0801 packer */
#include "../unp64.h"
void Scn_U_Generic801(unpstr *Unp)
{
    unsigned char *mem;
    int p;
    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x802 )==0x01E67800) &&
            ((mem[0x801]==0xa0)||(mem[0x801]==0xa2)) )
        {
            Unp->Forced=0x801;
            PrintInfo(Unp,_I_GENSYSL);
            Unp->IdFlag=1;return;
        }
        else if( Unp->info->run == -1 )
        {
            for(p=0x800;p<0x830;p++)
            {
                if (mem[p]==0x78)
                {
                    Unp->Forced=p;
                    sprintf(appstr,"Guessed entry=$%04x",Unp->Forced);
                    for(;p<0x900;p++)
                    {
                        if(mem[p]==0x60)
                        {
                            if(Unp->DebugP)
                                printf("%s\n",appstr);
                            break;
                        }
                        if( (mem[p]==0x4c) && (mem[p+2]<0x08) )
                        {
                            Unp->DepAdr=mem[p+1]|mem[p+2]<<8;
                            printf(DEPMASK,appstr,Unp->DepAdr);
                            break;
                        }
                    }
                    break;
                }
            }
            if(Unp->DepAdr)
            {
                Unp->IdFlag=1;return;
            }
        }
    }
}
