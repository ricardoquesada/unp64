/* Flexible Code Compactor aka TMC Filecompactor III / FP */
#include "../unp64.h"
void Scn_FilecompactorTMC(unpstr *Unp)
{
    unsigned char *mem;
    int q=0,p;
    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x8b9)==0xF786FFA2) &&
            (*(unsigned int*)(mem+0x927)==0x4607904A) &&
            (*(unsigned int*)(mem+0x92b)==0x4CF766F8)
          )
        {
            for(p=0x820;p<0x82B;p++)
            {
                if((*(unsigned int*)(mem+p )==0x4CEBD0C8 ))
                {
                    Unp->DepAdr=mem[p+4]|mem[p+5]<<8;
                    break;
                }
                if((*(unsigned int*)(mem+p )==0x4CE9D0C8 ))
                {
                    Unp->DepAdr=mem[p+4]|mem[p+5]<<8;
                    break;
                }
                if((*(unsigned int*)(mem+p )==0x4CEED0CA ))
                {
                    Unp->DepAdr=mem[p+4]|mem[p+5]<<8;
                    break;
                }
            }
            if(Unp->DepAdr)
            {
                for (p=0x880;p<0x888;p++)
                {
                    if(*(unsigned int*)(mem+p )==0x651898F9)
                    {
                        q=mem[p+4]<<24|(mem[p+4]+1)<<8;
                        q|=0x00850086; /* 0x2D852E86 / 0xae85af86 */
                        Unp->EndAdr=mem[p+4];
                        break;
                    }
                }
                for (p=0x859;p<0x85e;p++)
                {
                    if( (mem[p]==0xa2)&&
                        (*(unsigned int*)(mem+p+4 )==q ))
                    {
                        Unp->StrMem=mem[p+3]|mem[p+1]<<8;
                        break;
                    }
                }
                PrintInfo(Unp,_I_FCOMPTMC);
                for (p=0x8ad;p<0x8b8;p++)
                {
                    if((mem[p]==0xa9)||(mem[p]==0xa2)||(mem[p]==0xa0))
                    {
                        p++;
                        continue;
                    }
                    if((mem[p]==0x8d)||(mem[p]==0x8e)||(mem[p]==0x8c))
                    {
                        p+=2;
                        continue;
                    }
                    if(*(unsigned int*)(mem+p)==0x4CA65920)
                    {
                        mem[p]=0x2c;
                        p+=3;
                    }
                    if((mem[p]==0x4c)||(mem[p]==0x20))
                    {
                        Unp->RetAdr=0;
                        if((Unp->RetAdr=mem[p+1]|mem[p+2]<<8)>=0x400)
                        {
                            Unp->RtAFrc=1;
                            //if(!Unp->IdOnly)
                                //printf("return == $%04x\n",Unp->RetAdr);
                            break;
                        }
                    }
                }
                if(Unp->info->run == -1)
                {
                    for (p=0x80a;p<0x820;p++)
                    {
                        if((mem[p]==0xa0)&&(mem[p+1]==0))
                        {
                            Unp->Forced=p;
                            break;
                        }
                    }
                }
                Unp->IdFlag=1;return;
            }
        }
    }
    /* MeanTeam Crunch*/
    if( Unp->DepAdr==0 )
    {
       /* unpacker is very similar to TMC/FP */
        if( (*(unsigned int*)(mem+0x80f)==0x00A003A2) &&
            (*(unsigned int*)(mem+0x813)==0x990769B9) &&
            (*(unsigned int*)(mem+0x817)==0xD0C80400) &&
            (*(unsigned int*)(mem+0x92c)==0xBE4CF766)
          )
        {
            Unp->Forced=0x80f;
            Unp->DepAdr=mem[0x829]|mem[0x82a]<<8;
            Unp->EndAdr=0x2d;
            Unp->RetAdr=mem[0x8b4]|mem[0x8b5]<<8;
            Unp->StrMem=mem[0x860]|mem[0x85e]<<8;
            PrintInfo(Unp,_I_FCOMPMTC);
            Unp->IdFlag=1;return;
        }
    }
    /* Kinetic 2 */
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x812)==0xE78DA0A9) &&
            (*(unsigned int*)(mem+0x816)==0x34A97807) &&
            (*(unsigned int*)(mem+0x81e)==0x99083DB9) &&
            (*(unsigned int*)(mem+0x8d0)==0x014F4CF1)
          )
        {
            Unp->Forced=0x812;
            Unp->DepAdr=0x0100;
            Unp->EndAdr=0xfc;
            Unp->StrMem=mem[0x841]|mem[0x842]<<8;
            Unp->RetAdr=mem[0x8f7]|mem[0x8f8]<<8;
            PrintInfo(Unp,_I_FCOMPK2);
            Unp->IdFlag=1;return;
        }
    }
    /* Bandits compactor system */
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x80d)==0x69B900A0) &&
            (*(unsigned int*)(mem+0x824)==0x4CE8D0C8) &&
            (*(unsigned int*)(mem+0x927)==0x4607904A) &&
            (*(unsigned int*)(mem+0x92b)==0x4CF766F8)
          )
        {
            Unp->Forced=0x80d;
            Unp->DepAdr=mem[0x828]|mem[0x829]<<8;
            Unp->EndAdr=0x2d;
            Unp->StrMem=mem[0x85c]|mem[0x85a]<<8;
            p=0x8ad;
            if(*(unsigned int*)(mem+p)==0x4CA65920)
            {
                mem[p]=0x2c;
                Unp->RetAdr=mem[p+4]|mem[p+5]<<8;
            }
            else
                Unp->RetAdr=mem[p+1]|mem[p+2]<<8;
            PrintInfo(Unp,_I_FCOMPSYS3);
            Unp->IdFlag=1;return;
        }
    }
}
