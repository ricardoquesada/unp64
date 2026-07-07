/* check for Action Replay - and similar freeze carts */
#include "../unp64.h"

static int ARxOpenFile(unpstr *Unp, int p);

void Scn_AR(unpstr *Unp)
{
    unsigned char *mem;
    char tmpbuf[512];
    int q,p;

    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if(Unp->DepAdr==0)
    {
        if( (*(unsigned int*)(mem+0x80f)==0xDD0D8D7F) &&
            (*(unsigned int*)(mem+0x927)==0x4CE7D0CA) )
        {
            for(q=0xa00,p=0;p<0x100;p++)
            {
                if(mem[q+p]==0x99 &&
                   mem[q+p+1]==mem[0x092b] &&
                   mem[q+p+2]==mem[0x092c] &&
                   mem[q+p+0x11]==0x40 )
                {
                    Unp->DepAdr=0x100+p;
                    PrintInfo(Unp,_I_AR4  );
                    break;
                }
                if(mem[q+p]==0x99 &&
                   mem[q+p+1]==mem[0x092b] &&
                   mem[q+p+2]==mem[0x092c] &&
                   mem[q+p+0x10]==0x40 )
                {
                    Unp->DepAdr=0x100+p;
                    PrintInfo(Unp,_I_AR3  );
                    break;
                }
            }
            if(!Unp->DepAdr)
            {
                Unp->DepAdr=mem[0x092b]|mem[0x092c]<<8;
                PrintInfo(Unp,_I_ARU  );
            }
            Unp->RTIFrc=1;
            if(Unp->info->run==-1)
                Unp->Forced=0x080d;
        }
        else if(*(unsigned int*)(mem+0x812)==0xDD0D8DDC)
        {
            for(p=0x900;p<0xcfff;p++)
            {
                if( (*(unsigned int*)(mem+p     )==0xA9DC0E8D) &&
                    (*(unsigned int*)(mem+p+0x0a)==0xA9DD0E8D) &&
                    mem[p+0x18]==0x4c)
                {
                    Unp->DepAdr=mem[p+0x19]|mem[p+0x1a]<<8;
                    Unp->RTIFrc=1;
                    if(Unp->info->run==-1)
                        Unp->Forced=0x080d;
                    PrintInfo(Unp,_I_SSNAP);
                    break;
                }
            }
        }
        else if( (*(unsigned int*)(mem+0x80f)==0xDD0D8D7F) &&
            (*(unsigned int*)(mem+0x8ef)==0x0330BD01) &&
            (*(unsigned int*)(mem+0x8fa)==0x7E4C00A0) &&
            (*(unsigned int*)(mem+0xbc8)==0x4C01C6DF) ) /*found ONE case with DE instead of DF, searching for more*/
        {
            Unp->DepAdr=mem[0x0bcc]|mem[0x0bcd]<<8;
            Unp->StrMem=2;
            Unp->EndAdr=0x10000;
            Unp->RTIFrc=1;
            if(Unp->info->run==-1)
                Unp->Forced=0x080d;
            PrintInfo(Unp,_I_FRZMACH);
        }
        /* special treatment: onefile 2-filed freeze files */
        /* ar4/rr: from 0847 to $d000, 2nd filename is "1"+filname */
        if( (*(unsigned int*)(mem+0x80d)==0xA201E678) &&
            (*(unsigned int*)(mem+0x814)==0x990847B9) &&
            (*(unsigned int*)(mem+0x818)==0xD0C8D000) &&
            (*(unsigned int*)(mem+0x834)==0xFFD54C8A) )
        {
            PrintInfo(Unp,_I_AR42F);
            if(Unp->IdOnly)
            {
                Unp->IdFlag=2;return;
            }
            p=strlen(Unp->name)+1;
            memcpy(appstr+1,Unp->name,p);
            appstr[p]=0;
            appstr[0]=mem[0x843];
            if( ARxOpenFile(Unp,p) > 0 )
            {
                Unp->IdFlag=2;return;
            }
            q=mem[0x0818]|mem[0x0819]<<8; /* $d000 */
            q+=Unp->info->start;
            q-=mem[0x0815]|mem[0x0816]<<8;/* $0847 */
            strcpy(tmpbuf,Unp->name);
            p=strlen(Unp->name);
            sprintf(tmpbuf+p,",$%04x",q);
            load_located(tmpbuf, mem, Unp->info);
            Unp->EndAdr=Unp->info->end;
            load_located(appstr, mem, Unp->info);
            Unp->StrMem=Unp->info->start;
            Unp->DepAdr=Unp->RetAdr=Unp->Forced=0x80d;
            Unp->IdFlag=1;return;
        }
        /* FreezeMachine: from $900 to a000, complete 2nd filename at $880 */
        if( (*(unsigned int*)(mem+0x80d)==0x8D7FA978) &&
            (*(unsigned int*)(mem+0x811)==0x34A9DD0D) &&
            (*(unsigned int*)(mem+0x819)==0x990900B9) &&
            (*(unsigned int*)(mem+0x847)==0xFFD54C00) )
        {
            PrintInfo(Unp,_I_FRZMACH2F);
            if(Unp->IdOnly)
            {
                Unp->IdFlag=2;return;
            }

            p=mem[0x82f]; /* filename lenght */
            memcpy(appstr,mem+0x880,p);
            appstr[p]=0;
            if( ARxOpenFile(Unp,p) > 0 )
            {
                Unp->IdFlag=2;return;
            }
            q=mem[0x081d]|mem[0x081e]<<8; /* $a000 */
            q+=Unp->info->start;
            q-=mem[0x081a]|mem[0x081b]<<8;/* $0900 */
            strcpy(tmpbuf,Unp->name);
            p=strlen(Unp->name);
            sprintf(tmpbuf+p,",$%04x",q);
            load_located(tmpbuf, mem, Unp->info);
            Unp->EndAdr=Unp->info->end;
            load_located(appstr, mem, Unp->info);
            Unp->StrMem=Unp->info->start;
            Unp->DepAdr=Unp->RetAdr=Unp->Forced=0x80d;
            Unp->IdFlag=1;return;
        }
    }
    if( Unp->DepAdr!=0 )
    {
        Unp->IdFlag=1;return;
    }
}

static int ARxOpenFile(unpstr *Unp, int p)
{
    FILE *h;
    return xxOpenFile(&h, Unp, p);
}
