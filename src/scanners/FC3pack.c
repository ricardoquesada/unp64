/* FinalCart3 pack */
#include "../unp64.h"

static int FCxOpenFile(FILE **h, unpstr *Unp, int p);

void Scn_FC3pack(unpstr *Unp)
{
    unsigned char *mem;
    int q,p;
    FILE *h=NULL;

    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if(((*(unsigned int*)(mem+0x812)&0xffff00ff)==0xAE8500A9) &&
            (*(unsigned int*)(mem+0x818)==0x2EC6AF85) &&
            (*(unsigned int*)(mem+0x884)==0x0110ACAE) &&
            (*(unsigned int*)(mem+0x89b)==0xEFD00156) )
        {
            if(Unp->info->run == -1)
                Unp->Forced=0x80e;
            Unp->DepAdr=0x100;
            for(p=0x868;p<0x86f;p++)
            {
                if((mem[p]==0x20)||(mem[p]==0x4c))
                {
                    q=mem[p+1]|mem[p+2]<<8;
                    if((mem[p]==0x20)&&(q==0xa659))
                    {
                        mem[p]=0x2c;
                    }
                    else
                    {
                        Unp->RetAdr=q;
                        break;
                    }
                }
            }
            Unp->fEndAf=0x10f;
            Unp->EndAdC=EA_USE_X|0xffff;
            Unp->StrMem=mem[0x84c]|mem[0x84d]<<8;
            PrintInfo(Unp,_I_FC3PACK);
            Unp->IdFlag=1;return;
        }
    }
    /* split freeze files */
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x80d)==0xB100A078) &&
            (*(unsigned int*)(mem+0x815)==0xF00FC0C8) &&
            (*(unsigned int*)(mem+0x819)==0xD0B7C404) &&
            (*(unsigned int*)(mem+0x81d)==0x9900A9F2) )
        {
            if(*(unsigned short int*)(mem+0x821)==0x0C33)
            {
                PrintInfo(Unp,_I_FC3LD);
                if(Unp->IdOnly)
                {
                    Unp->IdFlag=2;return;
                }
                Unp->DepAdr=0;
                /* zp */
                memmove(mem+0,mem+0xc43,0x200);
                memmove(mem+0x200,mem+0xac8,0x17a);

                q=mem[0xd4]|mem[0xd5]<<8;
                if(Unp->DebugP)
                {
                    printf("after-depack return address=$%04x\n",q);
                }
                if((q>=0x200)&&(q<0x400))
                {
                    if(Unp->DebugP)
                        printf("DepAdr/RetAdr forced to $%04x\n",q);
                    Unp->DepAdr=q;
                    Unp->RetAdr=q;
                    Unp->RtAFrc=1;
                }
                q--;
                mem[0x341]=q&0xff;
                mem[0x33e]=q>>8;
                mem[0x311]=0x34;
                memset(mem+0x200,0x60,0x78);
                memset(mem+0x324,0xea,0x19);
                memset(mem+0x344,0x60,0x26);
                memmove(mem+0x400,mem+0x1072,3);
                p=strlen(Unp->name)+1;
                memcpy(appstr+1,Unp->name,p);
                appstr[p]=0;
                appstr[0]=mem[0x36a]; /* '-' but could be hacked */

                if( FCxOpenFile(&h, Unp, p) > 0)
                {
                    Unp->IdFlag=2;return;
                }
                mem[0x37b]=fgetc(h);
                mem[0x37c]=fgetc(h);
                mem[0x37d]=fgetc(h);
                mem[0x27d]=fgetc(h);
                mem[0x281]=fgetc(h);
                q=mem[0x27d]|mem[0x281]<<8;

                fread(mem+q,0x10000-q,1,h);
                fclose(h);
                if(!Unp->DepAdr)
                {
                    for(q=0x1ff;q>0x100;q--)
                    {
                        if((mem[q]==0x40)&&(mem[q-1]==0x68)&&(mem[q-0xf]==0x9d))
                        {
                            Unp->DepAdr=q-0x0f;
                            break;
                        }
                    }
                }
                Unp->info->start=0x200;
                Unp->info->end=0xffff;
                Unp->Forced=0x278;
                Unp->RTIFrc=1;
                Unp->StrMem=0x2;
                Unp->EndAdr=0x10000;
                Unp->FStack=0;
                Unp->IdFlag=1;return;
            }
            else if(*(unsigned short int*)(mem+0x821)==0x0B9B)
            {
                PrintInfo(Unp,_I_FC2LD);
                if(Unp->IdOnly)
                {
                    Unp->IdFlag=2;return;
                }
                /* zp */
                memmove(mem+0x000,mem+0xbab,0x200);
                memmove(mem+0x200,mem+0xa56,0x200);

                mem[0x2eb]=0x34;
                //memset(mem+0x200,0x78,0x4f);
                memset(mem+0x2fe,0xea,0x19);
                memset(mem+0x31e,0x60,0x26);
                memmove(mem+0x400,mem+0x0fda,3);
                p=strlen(Unp->name)+1;
                memcpy(appstr+1,Unp->name,p);
                appstr[p]=0;
                appstr[0]=mem[0x344]; /* '-' but could be hacked */

                if( FCxOpenFile(&h, Unp, p) > 0)
                {
                    Unp->IdFlag=2;return;
                }
                mem[0x355]=fgetc(h);
                mem[0x356]=fgetc(h);
                mem[0x357]=fgetc(h);
                mem[0x254]=fgetc(h);
                mem[0x258]=fgetc(h);
                q=mem[0x254]|mem[0x258]<<8;

                fread(mem+q,0x10000-q,1,h);
                fclose(h);
                for(q=0x1ff;q>0x100;q--)
                {
                    if((mem[q]==0x40)&&(mem[q-1]==0x68)&&(mem[q-0xf]==0x9d))
                    {
                        Unp->DepAdr=q-0x0f;
                        q=mem[Unp->DepAdr-2]|mem[Unp->DepAdr-1]<<8;
                        if(Unp->DebugP)
                        {
                            printf("after-depack return address=$%04x\n",q+1);
                        }
                        if((q>=0x200)&&(q<0x400))
                        {
                            if(Unp->DebugP)
                                printf("DepAdr/RetAdr forced to $%04x\n",q+1);
                            Unp->DepAdr=q+1;
                            Unp->RetAdr=q+1;
                            Unp->RtAFrc=1;
                        }
                        mem[0x31b]=q&0xff;
                        mem[0x318]=q>>8;
                        break;
                    }
                }
                Unp->info->start=0x200;
                Unp->info->end=0xffff;
                Unp->Forced=0x24f;
                Unp->RTIFrc=1;
                Unp->StrMem=0x2;
                Unp->EndAdr=0x10000;
                Unp->FStack=0;
                Unp->IdFlag=1;return;
            }
            else if(*(unsigned short int*)(mem+0x821)==0x0B98) /* FC1? TODO */
            {
                PrintInfo(Unp,_I_FCU1LD);
                if(Unp->IdOnly)
                {
                    Unp->IdFlag=2;return;
                }
                /* zp */
                memmove(mem+0x000,mem+0xba8,0x200);
                memmove(mem+0x200,mem+0xa56,0x200);

                mem[0x2e8]=0x34; /* a9 36 -> a9 34*/
                //memset(mem+0x200,0x78,0x4f);
                memset(mem+0x2fb,0xea,0x19);
                memset(mem+0x31b,0x60,0x26);
                memmove(mem+0x400,mem+0x0fd7,3);
                p=strlen(Unp->name)+1;
                memcpy(appstr+1,Unp->name,p);
                appstr[p]=0;
                appstr[0]=mem[0x341]; /* '-' but could be hacked */

                if( FCxOpenFile(&h, Unp, p) > 0)
                {
                    Unp->IdFlag=2;return;
                }
                mem[0x352]=fgetc(h);
                mem[0x353]=fgetc(h);
                mem[0x354]=fgetc(h);
                mem[0x254]=fgetc(h);
                mem[0x258]=fgetc(h);
                q=mem[0x254]|mem[0x258]<<8;

                fread(mem+q,0x10000-q,1,h);
                fclose(h);
                for(q=0x1ff;q>0x100;q--)
                {
                    if((mem[q]==0x40)&&(mem[q-1]==0x68)&&(mem[q-0xf]==0x9d))
                    {
                        Unp->DepAdr=q-0x0f;
                        q=mem[Unp->DepAdr-2]|mem[Unp->DepAdr-1]<<8;
                        if(Unp->DebugP)
                        {
                            printf("after-depack return address=$%04x\n",q+1);
                        }
                        if((q>=0x200)&&(q<0x400))
                        {
                            if(Unp->DebugP)
                                printf("DepAdr/RetAdr forced to $%04x\n",q+1);
                            Unp->DepAdr=q+1;
                            Unp->RetAdr=q+1;
                            Unp->RtAFrc=1;
                        }
                        mem[0x318]=q&0xff;
                        mem[0x315]=q>>8;
                        break;
                    }
                }
                Unp->info->start=0x200;
                Unp->info->end=0xffff;
                Unp->Forced=0x24f;
                Unp->RTIFrc=1;
                Unp->StrMem=0x2;
                Unp->EndAdr=0x10000;
                Unp->FStack=0;
                Unp->IdFlag=1;return;
            }
            else
            {
                PrintInfo(Unp,_I_FCULD);
                Unp->IdFlag=2;return;
            }
        }
    }
}

static int FCxOpenFile(FILE **hh, unpstr *Unp, int p)
{
    int retval;
    retval=xxOpenFile(hh, Unp, p);
    if(retval==0)
        fseek(*hh,0x200,0);
    return retval;
}

