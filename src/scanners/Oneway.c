/* unknown sysless packers, found in some Oneway warez */
#include "../unp64.h"
void Scn_Oneway(unpstr *Unp)
{
    unsigned char *mem;
    int p,q;
    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    /* depacker at $f2 */
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x801)==0xE67800A2) &&
            (*(unsigned int*)(mem+0x80a)==0x2E852D84) &&
            (*(unsigned int*)(mem+0x816)==0x00F24CF7) )
        {
            p=mem[0x80f]|mem[0x810]<<8;
            if( (*(unsigned int*)(mem+p)==0x06D0EFA5) )
            {
                Unp->DepAdr=0xf2;
                Unp->Forced=0x801;
                Unp->RetAdr=mem[p+0x57]|mem[p+0x58]<<8;
                Unp->fStrAf=0xfe;
                Unp->StrAdC=EA_ADDFF|EA_USE_Y|0xffff;
                Unp->EndAdr=mem[0x807]|mem[0x809]<<8;Unp->EndAdr++;
                PrintInfo(Unp,_I_U_1WF2);
                Unp->IdFlag=1;return;
            }
        }
    }
    /* variant at $da */
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x801)==0xE67800A2) &&
            (*(unsigned int*)(mem+0x80a)==0x2E852D84) &&
            (*(unsigned int*)(mem+0x816)==0x00da4CF7) )
        {
            p=mem[0x80f]|mem[0x810]<<8;
            if( (*(unsigned int*)(mem+p)==0x06D0d7A5) )
            {
                Unp->DepAdr=0xda;
                Unp->Forced=0x801;
                Unp->RetAdr=mem[p+0x43]|mem[p+0x44]<<8;
                Unp->fStrAf=0xfe;
                Unp->StrAdC=EA_ADDFF|EA_USE_Y|0xffff;
                Unp->EndAdr=mem[0x807]|mem[0x809]<<8;Unp->EndAdr++;
                PrintInfo(Unp,_I_U_1WDA);
                Unp->IdFlag=1;return;
            }
        }
    }
    /* Maktlink 2 */
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x801)==0xE67800A2) &&
            (mem[0x805]==0x01) && (mem[0x806]==0x4c) )
        {
            p=mem[0x807]|mem[0x808]<<8;
            if((mem[p]==0xbd)&&
               (*(unsigned int*)(mem+p+0x03)==0x10E80295) &&
               (*(unsigned int*)(mem+p+0x1e)==0xA000024C) )
            {

                Unp->DepAdr=0x02;
                Unp->Forced=0x801;
                Unp->RetAdr=mem[p+0x3c]|mem[p+0x3d]<<8;
                Unp->fStrAf=0x27;
                Unp->StrAdC=0xffff;
                Unp->EndAdr=mem[p+0x46]|mem[p+0x47]<<8;
                PrintInfo(Unp,_I_1WMKL2);

                /* dirty workaround: this packer is probably bugged,
                sometime happens that overwrites itself during the 1st
                copy loop. Add enough $2c at eof else it would find BRKs.
                */
                if(!Unp->IdOnly)
                {
                    for (q=p+0x51;(q<0x10000)&&(q<p+0x220);q++)
                        mem[q]=0x2c;
                }
                Unp->IdFlag=1;return;
            }
        }
    }
}
