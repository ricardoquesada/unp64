/* Unipacker generic detection
   version 1: fixed with sys and text output
   version 2: fixed with sys and with/out text
   version 3: sys/sysless and with/out text
   note: 9 codes charpacker (!)
*/
#include "../unp64.h"
void Scn_UniPacker(unpstr *Unp)
{
    unsigned char *mem;
    int q,p;
    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        for(q=0x801;q<0x838;q++)
        {
            if( mem[q]==0x01 && mem[q+1]==0xa2 && mem[q+3]==0xb9)
            {
                if((*(unsigned int*)(mem+q+0x06)==0xC8FF0099) &&
                   (*(unsigned int*)(mem+q+0x11)==0xEED0CA08) &&
                   (*(unsigned int*)(mem+q+0x1f)==0x01004CF7) &&
                   (*(unsigned int*)(mem+q+0x84)==0xA901284C)   )
                {
                    Unp->DepAdr=0x100;
                    Unp->fEndAf=0x129;
                    Unp->EndAdC=0xffff|EA_USE_Y;
                    Unp->StrMem=mem[q+0x57]|mem[q+0x58]<<8;
                    Unp->RetAdr=mem[q+0x77]|mem[q+0x78]<<8;
                    /* parameter lowmemfill sets start to $07e8 and fills with 0 */
                    if(Unp->StrMem==0x7e8)
                        Unp->StrMem=0x800;
                    if(Unp->info->run == -1)
                    {
                        for(p=0x801;p<q;p++)
                        {
                            if(mem[p]==0x78)
                            {
                                Unp->Forced=p;
                                break;
                            }
                            else if( (mem[p  ]==0xa9)&&
                                     (mem[p+2]==0x85)&&
                                     (mem[p+3]==0x01)
                                   )
                            {
                                Unp->Forced=p;
                                break;
                            }
                            else if( (mem[p  ]==0x84)&&
                                     (mem[p+1]==0x01)&&
                                     (mem[p+2]==0xa2)
                                   )
                            {
                                Unp->Forced=p;
                                break;
                            }
                        }
                    }
                    if(mem[q-1]==0x85)
                    {
                        PrintInfo(Unp,_I_UNIPACK1);
                    }
                    else /*if(mem[q-1]==0x84)*/
                    {
                        if(mem[q+0x41]==0x56)
                        {
                            PrintInfo(Unp,_I_UNIPACK3);
                        }
                        else /*if(mem[q+0x41]==0x57)*/
                        {
                            PrintInfo(Unp,_I_UNIPACK2);
                        }
                    }
                    if(Unp->DebugP)
                    {
                         for(p=0x801;p<q;p++)
                         {
                             if(mem[p]==0xb9 &&
                                (*(unsigned int*)(mem+p+3)==0x9903FF99)
                               )
                             {
                                 printmsg(mem,1+(mem[p+1]|mem[p+2]<<8),40);
                                 break;
                             }
                         }
                    }
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
