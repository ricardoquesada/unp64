/* TCD packer 2 */
#include "../unp64.h"
void Scn_TCD(unpstr *Unp)
{
    unsigned char *mem;
    int q,p,strtmp;
    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if(((*(unsigned int*)(mem+0x810)&0xffffff00)==0x9AFBA200) &&
            (*(unsigned int*)(mem+0x814)==0x23BD01E6) &&
            (*(unsigned int*)(mem+0x821)==0xA001014C) &&
            (*(unsigned int*)(mem+0x890)==0x02D0FDE6)   )
        {
            /*
            Found a packed program that's a result of a "inside" linking
            need to monitor end ptr, which is also start ptr...

            ;info->end ignored, real end of prg+1
            eofprg = mem[0x827]|mem[0x828]<<8;eofprg+=0x100;
            ;pointer of datastream start after relocation at end of memory
            eofptr     = mem[0x839]|mem[0x83d]<<8;
            ;dimension of data stream
            datadim    = 0x10000-eofptr
            ;start of datastream in prg
            datastart  = eofprg-datadim
            ;linked part start addresses table
            table      = 0x8a6
            ;table dimension
            tabdim     = datastart-table
            ;number of linked files
            filenum    = tabdim / 2
            */
            p=mem[0x827]|mem[0x828]<<8;p+=0x100;
            q=0x10000-(mem[0x839]|mem[0x83d]<<8);
            p-=q;
            Unp->StrMem=0x10000;
            for(q=0x8a6;q<p;q+=2)
            {
                strtmp=mem[q]|mem[q+1]<<8;
                if(Unp->DebugP)
                    printf("$%04x\n",strtmp);
                if( Unp->StrMem > strtmp )
                    Unp->StrMem = strtmp;
            }

            /*
            1st usage of this mixed technique: both monitor $fd and also set it as
            end pointer after depack. Added special handling at end of unp.c
            */
            Unp->fEndAf=0xfd;
            Unp->MonEnd=0x00fd<<16|0x00fe;
            Unp->RetAdr=mem[0x8a4]|mem[0x8a5]<<8;
            Unp->DepAdr=0x14d;
            Unp->Forced=0x811;
            PrintInfo(Unp,_I_TCDLC2);
            Unp->IdFlag=1;return;
        }
    }
    /* packer/linker 1.4 */
    if( Unp->DepAdr==0 )
    {
        if(((*(unsigned int*)(mem+0x810)&0xffffff00)==0xBD00A200) &&
            (*(unsigned int*)(mem+0x814)==0x009D0830) &&
            (*(unsigned int*)(mem+0x824)==0x004C2E85) &&
            (*(unsigned int*)(mem+0x87a)==0x8501B8BD) )
        {
            //Unp->DepAdr=0x100;
            Unp->DepAdr=0x1a2;
            Unp->Forced=0x811;
            Unp->RetAdr=mem[0x8da]|mem[0x8db]<<8;
            Unp->StrMem=0x10000;
            p=0x8e8;
            /* determine minimal start */
            for(q=mem[0x8e7];q&&(p<0x900);p+=2,q--)
            {
                strtmp=(mem[p+0]|mem[p+1]<<8);
                if(Unp->StrMem > strtmp)
                {
                    Unp->StrMem = strtmp;
                }
                if(Unp->DebugP)
                {
                    printf("$%04x\n",strtmp);
                }
            }
            //Unp->EndAdr=0xc1;
            Unp->fEndAf=0xc1;
            Unp->MonEnd=0x00c1<<16|0x00c2;
            PrintInfo(Unp,_I_TCDLC1);
            Unp->IdFlag=1;return;
        }
    }
}
