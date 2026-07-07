/* Lightmizer */
#include "../unp64.h"
void Scn_Lightmizer(unpstr *Unp)
{
    unsigned char *mem;
    int q,p;
    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        p=Unp->info->run;
        if(p!=0x80b)
            p=Unp->info->start;
        for(q=p+0x20;p<q;p++)
        {
            if( (*(unsigned short int*)(mem+p+2)==0xE678) &&
                (*(unsigned int*)(mem+p+0x04)==(((p+0x0d)<<16)|0xCE01)) &&
                (*(unsigned int*)(mem+p+0x20)==0xCA00FC9D) )
            {
                if(*(unsigned short int*)(mem+p  )!=0x00a0)
                    Unp->Forced=p+2;
                else
                    Unp->Forced=p  ;

                if  (*(unsigned int*)(mem+p+0x24)==0x114CF7D0)
                {
                    Unp->DepAdr=0x111; /* lightmizer */
                    Unp->RetAdr=mem[p+0x3a]|mem[p+0x3b]<<8;
                    for(p+=0x30,q=p+0x80;p<q;p++)
                    {
                        if(mem[p]==0x99 &&
                           (*(unsigned int*)(mem+p+0x3)==0xEE03D0C8))
                        {
                            Unp->StrMem=mem[p+1]|mem[p+2]<<8;
                            Unp->fEndAf=(mem[p+7]|mem[p+8]<<8)-1;
                            Unp->EndAdC=EA_USE_Y|0xffff;
                            break;
                        }
                    }
                    PrintInfo(Unp,_I_LIGHTM);
                    break;
                }
                if  (*(unsigned int*)(mem+p+0x24)==0x074CF7D0)
                {
                    Unp->DepAdr=0x107; /* visiomizer 6.3 */
                    for(p+=0x30,q=p+0x80;p<q;p++)
                    {
                        if(mem[p]==0x99 &&
                           (*(unsigned int*)(mem+p+0x3)==0xEE03D0C8))
                        {
                            Unp->StrMem=mem[p+1]|mem[p+2]<<8;
                            Unp->fEndAf=(mem[p+7]|mem[p+8]<<8)-1;
                            Unp->EndAdC=EA_USE_Y|0xffff;
                            /*if(mem[p+0x54]==0x4c)*/ /*totally wrong!*/
                            /*if(mem[p+0x15]==0x4c)*/ /*correct, but why bother?*/
                                Unp->RetAdr=mem[p+0x16]|mem[p+0x17]<<8;
                            break;
                        }
                    }
                    PrintInfo(Unp,_I_VISIOM63);
                    break;
                }
            }
        }
        if( Unp->DepAdr )
        {
            Unp->IdFlag=1;return;
        }
    }
}
