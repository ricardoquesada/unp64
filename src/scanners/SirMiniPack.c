/* SIR packer */
#include "../unp64.h"
/*****************************************************************************/
void Scn_SirMiniPack(unpstr *Unp)
{
    unsigned char *mem;
    int q,p=0,r=0,cnt=0,s;
    FILE *h;
    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        for(p=0x800;p<0x811;p++)
        {
            if( (*(unsigned int*)(mem+p+0x01)==0x32A001E6) &&
                (*(unsigned int*)(mem+p+0x07)==0x005B9908) &&
                (*(unsigned int*)(mem+p+0x3a)==0x005D4C00) &&
                (*(unsigned int*)(mem+p+0x6c)==0x60ADE602) )
            {
                Unp->DepAdr=0x05d;
                break;
            }
        }
        if( Unp->DepAdr )
        {
            Unp->RetAdr=mem[p+0x65]|mem[p+0x66]<<8;
            Unp->Forced=p+1;
            Unp->fEndAf=0xae;
            Unp->StrMem=mem[p+0x32]|mem[p+0x34]<<8;
            PrintInfo(Unp,_I_SIRMPACK);
            Unp->IdFlag=1;return;
        }
    }
    /* SIR MasterLinker */
    if( Unp->DepAdr==0 )
    {
        p=Unp->info->start;
        for(q=p+0x10;p<q;p++)
        {
            if( (*(unsigned int*)(mem+p     )==0x8530A978) &&
                (*(unsigned int*)(mem+p+0x04)==0xB900A001) &&
                (*(unsigned int*)(mem+p+0x52)==0xE8E8E8E8) &&
                (*(unsigned int*)(mem+p+0x6c)==0xE0E9D0FB) )
            {
                Unp->DepAdr=0x100;
                break;
            }
        }
        if( Unp->DepAdr )
        {
            Unp->Forced=p;
            Unp->RetAdr=mem[p+0x79]|mem[p+0x7a]<<8;
            Unp->StrMem=mem[p+0x7d]|mem[p+0x7e]<<8;
            Unp->EndAdr=0xfa;
            PrintInfo(Unp,_I_SIRMLINK);
            Unp->IdFlag=1;return;
        }
    }
    /* special case: SIR combine */
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x826)==0xFFD2200D) &&
            (*(unsigned int*)(mem+0x839)==0x0A0A0811) &&
            (*(unsigned int*)(mem+0x8bf)==0x2000A001) &&
            (*(unsigned int*)(mem+0x8c3)==0x13B0FCD1) )
        {
            p=0x977;
            cnt=mem[0x811];
            PrintInfo(Unp,_I_SIRCOMBIN1);
            Unp->IdFlag=2;
            if(Unp->IdOnly)
                return;
        }
        if( (*(unsigned int*)(mem+0x83f)==0xFFD2200D) &&
            (*(unsigned int*)(mem+0x84a)==0x0A0A0811) &&
            (*(unsigned int*)(mem+0x8d3)==0x2000A001) &&
            (*(unsigned int*)(mem+0x8d7)==0x13B0FCD1) )
        {
            p=0x96d;
            cnt=mem[0x811];
            PrintInfo(Unp,_I_SIRCOMBIN2);
            Unp->IdFlag=2;
            if(Unp->IdOnly)
                return;
        }
        if(Unp->IdFlag==2)
        {
            /* filescount@$0811

               array of pointers@$0977
               {
                 lo,hi:start of file
                 lo,hi: $ae/af (real end of file after move to $801)
               } * filescount
               array of filenames
               {
                 filename(zeroterminated)
               } * filescount
            */

            /* start of 1st filename */
            s=p+(cnt*4);

            for(q=0;q<cnt;q++)
            {
                Unp->StrMem=mem[p+(q*4)+0]|mem[p+(q*4)+1]<<8;
                Unp->EndAdr=mem[p+(q*4)+2]|mem[p+(q*4)+3]<<8;
                Unp->fEndAf=Unp->EndAdr-0x801;
                normalizechar(appstr,mem,&s);
                while(mem[s++]);
                h=fopen(appstr,"wb");
                putc(0x01,h);
                putc(0x08,h);
                fwrite(mem+Unp->StrMem,Unp->fEndAf,1,h);
                fclose(h);
                //if(Unp->DebugP)
                {
                    printf("%-20s:$%04x-$%04x\n",appstr,Unp->StrMem,Unp->StrMem+Unp->fEndAf);
                }
            }
            Unp->StrMem=0;
            Unp->EndAdr=0;
            Unp->fEndAf=0;

            return;
        }
    }
    /* special case: SIR combine v3? also has startaddress in the array */
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x8c6)==0xFFD2200D) &&
            (*(unsigned int*)(mem+0x84a)==0x850A0810) &&
            (*(unsigned int*)(mem+0x86f)==0x8509F8B9) &&
            (*(unsigned int*)(mem+0x90e)==0x20EDDD20) )
        {
            r=0x9f8;
            p=mem[0x857]|mem[0x85d]<<8;
            cnt=mem[0x810];
            PrintInfo(Unp,_I_SIRCOMBIN3);
            Unp->IdFlag=2;
            if(Unp->IdOnly)
                return;
        }
        if(Unp->IdFlag==2)
        {
            /* filescount@$0810

               array of pointers@$09f8
               {
                 lo,hi:start of file
                 lo,hi:end of file
                 lo,hi: real startaddr
               } * filescount
               array of filenames , could be at $0b30+filescount*6, depends
               {
                 filename(zeroterminated)
               } * filescount
            */

            /* start of 1st filename */
            s=p+(cnt*6);

            for(q=0;q<cnt;q++)
            {
                Unp->StrMem=mem[r+(q*6)+0]|mem[r+(q*6)+1]<<8;
                Unp->fEndAf=mem[r+(q*6)+2]|mem[r+(q*6)+3]<<8;
                Unp->fEndAf-=Unp->StrMem; /* size */
                Unp->EndAdr=mem[r+(q*6)+4]|mem[r+(q*6)+5]<<8;
                normalizechar(appstr,mem,&s);
                while(mem[s++]);
                h=fopen(appstr,"wb");
                putc(Unp->EndAdr&0xff,h);
                putc(Unp->EndAdr>>8,h);
                fwrite(mem+Unp->StrMem,Unp->fEndAf,1,h);
                fclose(h);
                //if(Unp->DebugP)
                {
                    printf("%-20s:$%04x-$%04x\n",appstr,Unp->StrMem,Unp->StrMem+Unp->fEndAf);
                }
            }
            Unp->StrMem=0;
            Unp->EndAdr=0;
            Unp->fEndAf=0;

            return;
        }
    }
}
