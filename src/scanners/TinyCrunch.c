/* TinyCrunch/ChristopherJam */
#include "../unp64.h"
void Scn_TinyCrunch(unpstr *Unp)
{
    unsigned char *mem;
    int q;
    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x80d)==0xBDBBA278) &&
           (*(unsigned int*)(mem+0x811)==0xFF9D081D) &&
           (*(unsigned int*)(mem+0x8d1)==0x01644C07) &&
           (*(unsigned int*)(mem+0x8d5)==0xF3B005E6) )
        {
            Unp->DepAdr=0x10e;
            Unp->Forced=0x80d;
            Unp->RetAdr=mem[0x838]|mem[0x839]<<8;
            Unp->fEndBf=0x04; printf("Matched Variant 1\n");
            Unp->EndAdC=EA_USE_Y;
            q=mem[0x82d]|mem[0x82f]<<8;
            q++;
            Unp->StrMem=mem[q]|mem[q+1]<<8;
            Unp->StrMem++;
            PrintInfo(Unp,_I_TINYCRUN09);
            Unp->IdFlag=1;return;
        }
        if((*(unsigned int*)(mem+0x80d)==0xBDBBA278) &&
           (*(unsigned int*)(mem+0x811)==0xFF9D081B) &&
           (*(unsigned int*)(mem+0x8a9)==0xDC100AA8) &&
           (*(unsigned int*)(mem+0x8d0)==0xE601644C) )
        {
            Unp->DepAdr=0x10e;
            Unp->Forced=0x80d;
            Unp->RetAdr=mem[0x836]|mem[0x837]<<8;
            Unp->fEndBf=mem[0x83d]|mem[0x83e]<<8; printf("Matched Variant 2, fEndBf=%04x\n", Unp->fEndBf);
            Unp->EndAdC=EA_USE_Y;
            if (mem[0x82e]==0x20) // JSR normally, or LDA if no 2nd pass
            {
                q=mem[0x82b]|mem[0x82d]<<8;
                q++;
            }
            else
            {
                q=0x8d8;
            }
            Unp->StrMem=mem[q]|mem[q+1]<<8;
            Unp->StrMem++;
            PrintInfo(Unp,_I_TINYCRUNCH);
            Unp->IdFlag=1;return;
        }
        /*
        unknown version found in soci's
        arok_2025_invit.prg and Lights_Off_Lights_On.prg
        */
        /*usually (mem+0x80d)==0xBDC1A278) but arok_2025_invit has a jsr that
          ends in LDX #$C1 RTS anyway */
        if((*(unsigned int*)(mem+0x811)==0xFF9D081B) &&
           (*(unsigned int*)(mem+0x845)==0x54D003A0) &&
           (*(unsigned int*)(mem+0x883)==0x4A4A4A8A) )
        {
            Unp->DepAdr=0x10e;
            Unp->Forced=0x80d;
            Unp->RetAdr=mem[0x836]|mem[0x837]<<8;
            Unp->fEndBf=mem[0x83d]|mem[0x83e]<<8; printf("Matched Variant 2, fEndBf=%04x\n", Unp->fEndBf);
            Unp->EndAdC=EA_USE_Y;
            //if (mem[0x82e]==0x20) // JSR normally, or LDA if no 2nd pass
            //{
                q=mem[0x82b]|mem[0x82d]<<8;
                q++;
            //}
            //else
            //{
                //q=0x8d8;   ???
            //}
            Unp->StrMem=mem[q]|mem[q+1]<<8; /* $07fd */
            Unp->StrMem+=mem[0x846];        /* ldy #03 */
            Unp->StrMem+=1;
            PrintInfo(Unp,_I_TINYCR_UNK);
            Unp->IdFlag=1;return;
        }
    }
}
