/* bytecompactor, max 16 files linker */
#include "../unp64.h"
void Scn_ByteCompactor(unpstr *Unp)
{
    unsigned char *mem;
    int q,p;
    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x810)      ==0x8534A978) &&
           (*(unsigned short int*)(mem+0x814)==0x4C01    ) )
        {
            p=mem[0x816]|mem[0x817]<<8;
            if(((*(unsigned int*)(mem+p+0x00)&0xffff00ff)==0xAC8500A9) &&
                (*(unsigned int*)(mem+p+0x21)==0x04004CF2) &&
                (*(unsigned int*)(mem+p+0xc0)==0x1DA4AEB1) )
            {
                Unp->DepAdr=0x40c;
                if( Unp->info->run == -1)
                    Unp->Forced=0x810;
                Unp->RetAdr=mem[p+0x109]|mem[p+0x10a]<<8;
                q=mem[p+0x26]|mem[p+0x2a]<<8;
                Unp->EndAdr=mem[q]|mem[q+1]<<8;
                if(Unp->EndAdr==0)
                {
                    Unp->EndAdr=0x10000;
                }
                /* last part, literal cpy of 1st few bytes */
                if(mem[p+0xde]==0x38)
                {
                    Unp->StrMem=mem[p+0xe2]|mem[p+0xe6]<<8;
                }
                else
                {
                    /* test but should be already correct */
                    Unp->MonStr=0x001d<<16|0x001e;
                }
                PrintInfo(Unp,_I_BYTECOMP);
                Unp->IdFlag=1;return;
            }
        }
    }
}
/*
.C:0400   A9 8E      LDA #$8E
.C:0402   85 AC      STA $AC
.C:0404   A9 1D      LDA #$1D
.C:0406   85 AD      STA $AD
.C:0408   A0 00      LDY #$00
.C:040a   B1 AC      LDA ($AC),Y
.C:040c   85 1D      STA $1D    ; destpointer
.C:040e   C8         INY
.C:040f   B1 AC      LDA ($AC),Y
.C:0411   85 1E      STA $1E
.C:0413   C8         INY
*/
