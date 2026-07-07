/* scan for Exomizer */
#include "../unp64.h"
void Scn_Exomizer(unpstr *Unp)
{
    unsigned char GP_hack[]={ /*0x34,0x03,*/
    0xA9,0x20,0xA0,0x00,0x99,0x00,0x04,0x99,0x00,0x05,0x99,0x00,0x06,0x99,
    0xE8,0x06,0xC8,0xD0,0xF1,0xA9,0xFF,0xA0,0x17,0x99,0xE8,0x07,0x88,0x10,0xFA,0xA9,
    0x0B,0x85,0x7A,0xA9,0x08,0x85,0x7B,0xA9,0x04,0x85,0xD2,0xA9,0xD8,0x85,0xF4,0xA2,
    0x00,0x86,0xD1,0x86,0xF3,0xA0,0x03,0xA9,0x08,0x48,0xA9,0xF6,0x4C,0x1B,0x08
    };
    unsigned char *mem;
    int q,p;

    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    /* exomizer 3.x */
    if( Unp->DepAdr==0 )
    {
        for (p=Unp->info->end;p>Unp->info->start;p--)
        {
            if((*(unsigned int*)(mem+p  )==0x100A8069) &&
               (*(unsigned int*)(mem+p+4)==0xD0FD060F) &&
               mem[p-6]==0x4c &&
               mem[p-4]==0x01 )
            {
                p-=5;
                q=2;
                if(mem[p-q]==0x8a)
                    q++;

                /* low byte of EndAdr, it's a lda $ff00,y */

                if( (mem[p-q-1]==mem[p-q-3]) && (mem[p-q-2]==mem[p-q]))
                {/* a0 xx a0 xx -> exomizer 3.0/3.01 */
                    Unp->ExoFnd=0x30;
                }
                else
                {   /* d0 c1 a0 xx -> exomizer 3.0.2, force +1 in start/end */
                    Unp->ExoFnd=0x32;
                    /* G*P intro hack, after jsr $ab1e expects Y=3 */
                    if(((*(unsigned int*)(mem+0x080d)&0xffff00ff)==0x08A000A9) &&
                       (*(unsigned int*)(mem+0x0811)==0x78AB1E20) )
                    {
                        if (Unp->DebugP)
                            printf("%s %s\r\n","G*P Intro Hack","1");
                        mem[0x810]=3;
                    }
                    else if(((*(unsigned int*)(mem+0x080d)&0x00ffffff)==0x00a908A0) &&
                            (*(unsigned int*)(mem+0x0811)==0x78AB1E20) )
                    {
                        if (Unp->DebugP)
                            printf("%s %s\r\n", "G*P Intro Hack", "2");
                        mem[0x80e]=3;
                    }
                    else if(((*(unsigned int*)(mem+0x0810)&0x00ffffff)==0x00a908A0) &&
                            (*(unsigned int*)(mem+0x0814)==0x78AB1E20) )
                    {
                        if (Unp->DebugP)
                            printf("%s %s\r\n", "G*P Intro Hack", "3");
                        mem[0x811]=3;
                    }
                    else if((*(unsigned int*)(mem+0x0809)==0x50472031) &&
                            (*(unsigned int*)(mem+0x0810)==0xFBA908A0) &&
                            (*(unsigned int*)(mem+0x0814)==0x48AB1E20) &&
                            (*(unsigned int*)(mem+0x082e)==0x04ED6CF2) )
                    {
                        Unp->Forced=0x334;
                        if (Unp->DebugP)
                            printf("%s %s - patch installed at $%04x\r\n", "G*P Intro Hack", "4", Unp->Forced);
                        memcpy(mem+Unp->Forced,GP_hack,sizeof(GP_hack));
                    }
                }
                Unp->ExoFnd|=(mem[p-q]<<8);
                break;
            }
        }
        if(Unp->ExoFnd)
        {
            Unp->DepAdr=0x100|mem[p];
            if((Unp->ExoFnd&0xff)==0x30)
                PrintInfo(Unp,_I_EXOM3);
            else
                PrintInfo(Unp,_I_EXOM302);
            for(;p<Unp->info->end;p++)
            {
                if( *(unsigned int*)(mem+p)==0x7d010020 )
                    break;
            }
            for(;p<Unp->info->end;p++)
            {
                if(mem[p]==0x4c)
                {
                    Unp->RetAdr=0;
                    if((Unp->RetAdr=mem[p+1]|mem[p+2]<<8)>=0x200)
                    {
                        if(!Unp->IdOnly && Unp->DebugP)
                            printf("return = $%04x\n",Unp->RetAdr);
                        break;
                    }
                    else
                    {   /* it's a jmp $01xx, goto next */
                        p++;
                        p++;
                    }
                }
            }
            if(Unp->info->run == -1)
            {
                p=Unp->info->start;
                q=p+0x10;
                for(;p<q;p++)
                {
                    if((mem[p]==0xba) && (mem[p+1]==0xbd))
                    {
                        Unp->Forced=p;
                        break;
                    }
                }
                for(q=p-1;q>=Unp->info->start;q--)
                {
                    if(mem[q]==0xe6)
                        Unp->Forced=q;
                    if(mem[q]==0xa0)
                        Unp->Forced=q;
                    if(mem[q]==0x78)
                        Unp->Forced=q;
                }
            }
        }
    }
    /* exomizer 1.x/2.x */
    if( Unp->DepAdr==0 )
    {
        for (p=Unp->info->end;p>Unp->info->start;p--)
        {
            if((((*(unsigned int*)(mem+p     )==0x4CF7D088) &&
                 (*(unsigned int*)(mem+p-0x0d)==0xD034C0C8)) ||
                ((*(unsigned int*)(mem+p     )==0x4CA7A438) &&
                 (*(unsigned int*)(mem+p-0x0c)==0x799FA5AE)) ||
                ((*(unsigned int*)(mem+p     )==0x4CECD08A) &&
                 (*(unsigned int*)(mem+p-0x13)==0xCECA0EB0)) ||
                ((*(unsigned int*)(mem+p     )==0x4C00A0D3) &&
                 (*(unsigned int*)(mem+p-0x04)==0xD034C0C8)) ||
                ((*(unsigned int*)(mem+p     )==0x4C00A0D2) &&
                 (*(unsigned int*)(mem+p-0x04)==0xD034C0C8))
               ) && mem[p+5]==1
              )
                {
                p+=4;Unp->ExoFnd=1;
                break;
            }
            else if((((*(unsigned int*)(mem+p     )==0x8C00A0d2) &&
                      (*(unsigned int*)(mem+p-0x04)==0xD034C0C8)) ||
                     ((*(unsigned int*)(mem+p     )==0x8C00A0d3) &&
                      (*(unsigned int*)(mem+p-0x04)==0xD034C0C8))||
                     ((*(unsigned int*)(mem+p     )==0x8C00A0cf) &&
                      (*(unsigned int*)(mem+p-0x04)==0xD034C0C8))
                    ) && mem[p+6]==0x4c && mem[p+8]==1
                   )
            {
                p+=7;Unp->ExoFnd=1;
                break;
            }
        }
        if(Unp->ExoFnd)
        {
            Unp->DepAdr=0x100|mem[p];
            PrintInfo(Unp,_I_EXOM);
            if(Unp->DepAdr>=0x134&&Unp->DepAdr<=0x14a/*0x13e*/)
            {
                for(p=Unp->info->end-4;p>Unp->info->start;p--)
                { /* 02 04 04 30 20 10 80 00 */
                    if( *(unsigned int*)(mem+p)==0x30040402  )
                        break;
                }
            }
            else
            {
                // exception for exo v1.x, otherwise add 8 to the counter and
                // scan backward from here
                if(Unp->DepAdr!=0x143)
                    p+=0x08;
                else
                    p-=0xb8;
            }
            for(;p>Unp->info->start;p--)
            {
                // incredibly there can be a program starting at $4c00 :P
                if((mem[p]==0x4c)&&(mem[p-1]!=0x4c)&&(mem[p-2]!=0x4c))
                {
                    Unp->RetAdr=0;
                    if((Unp->RetAdr=mem[p+1]|mem[p+2]<<8)>=0x200)
                    {
                        if(!Unp->IdOnly && Unp->DebugP)
                            printf("return = $%04x\n",Unp->RetAdr);
                        break;
                    }
                }
            }
            if(Unp->info->run == -1)
            {
                p=Unp->info->start;
                q=p+0x10;
                for(;p<q;p++)
                {
                    if((mem[p]==0xba) && (mem[p+1]==0xbd))
                    {
                        Unp->Forced=p;
                        break;
                    }
                }
                for(q=p-1;q>=Unp->info->start;q--)
                {
                    if(mem[q]==0xe6)
                        Unp->Forced=q;
                    if(mem[q]==0xa0)
                        Unp->Forced=q;
                    if(mem[q]==0x78)
                        Unp->Forced=q;
                }
            }
        }
    }
    if( Unp->DepAdr!=0 )
    {
        Unp->IdFlag=1;return;
    }
}
