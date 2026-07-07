/* FileLinker/Agony (SDA) */
#include "../unp64.h"
/*****************************************************************************/
void Scn_FileLinkerSDA(unpstr *Unp)
{
    unsigned char *mem;
    int q,p,t=0,s;
    FILE *h;
    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x811)==0xA2FDA320) &&
            (*(unsigned int*)(mem+0x815)==0xE5AA2020) &&
            (*(unsigned int*)(mem+0x851)==0xA9AC85DB) &&
            (*(unsigned int*)(mem+0x855)==0xADAD850F) )
        {
            p=0x0fdb;
            PrintInfo(Unp,_I_FLINKSDA);
            Unp->IdFlag=2;
            if(Unp->IdOnly)
                return;
        }
        if(Unp->IdFlag==2)
        {
            /* 1st file name at $0fdb
               L: 1 byte len of filename (including ,P) or $FF if EOF
               L bytes: filename
               W: 1 word, length of data (including W and B)
               B: 1 byte, number of blocks to display during save (irrilevant)
               W-3 bytes: prg data, so save W-3 bytes from here
               repeat
            */

            while(p < Unp->info->end)
            {
                s=mem[p];
                if(s==0xff)
                {
                    break;
                }
                p++;                   // start of filename
                q=p+s;                 // end of filename+1, datalen
                t=mem[q]|mem[q+1]<<8;  // save data len after filename
                t-=3;
                mem[q]=0;              // zero end filename
                if(mem[q-2]==',')
                {
                    mem[q-2]=0;        // no need of ,P
                }
                normalizechar(appstr,mem,&p);
                p=q;
                Unp->StrMem=p+3;
                Unp->EndAdr=Unp->StrMem+t;
                Unp->EndAdr=(Unp->EndAdr<Unp->info->end?Unp->EndAdr:Unp->info->end);
                Unp->fEndAf=Unp->EndAdr-Unp->StrMem;
                h=fopen(appstr,"wb");
                fwrite(mem+Unp->StrMem,Unp->fEndAf,1,h);
                fclose(h);
                //if(Unp->DebugP)
                {
                    printf("%-20s:$%04x-$%04x\n",appstr,Unp->StrMem,Unp->StrMem+Unp->fEndAf);
                }

                if((Unp->EndAdr>=Unp->info->end) && Unp->DebugP)
                {
                    printf("Premature EOF, last file truncated\n");
                }
                p=Unp->EndAdr;
            }
            Unp->StrMem=0;
            Unp->EndAdr=0;
            Unp->fEndAf=0;

            return;
        }
    }
}
