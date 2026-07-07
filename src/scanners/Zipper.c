/* Zipper/Oneway and hacks */
#include "../unp64.h"
void Scn_Zipper(unpstr *Unp)
{
    unsigned char *mem;

    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if (*(unsigned int*)(mem+0x801)==0xE67800A2)
        {
            if (*(unsigned int*)(mem+0x807)==0xF59D0812)
            {
                Unp->Forced=0x801;
                Unp->DepAdr=0x101;
                /* Chromizer $0801 packer */
                if((*(unsigned int*)(mem+0x80e)==0x01014CF7) &&
                   (*(unsigned int*)(mem+0x85c)==0x858AE9D0))
                {
                    Unp->RetAdr=mem[0x863]|mem[0x864]<<8;
                    Unp->EndAdr=mem[0x849]|mem[0x84a]<<8;Unp->EndAdr+=0x100;
                    Unp->fStrAf=0x12c;
                    Unp->StrAdC=0xffff|EA_ADDFF|EA_USE_Y;
                    PrintInfo(Unp,_I_ZIP50C);
                }
                else if ((*(unsigned int*)(mem+0x867 )&0xff0fffff)==0x4C080186)
                {
                    Unp->RetAdr=mem[0x86b]|mem[0x86c]<<8;
                    Unp->EndAdr=mem[0x852]|mem[0x853]<<8;Unp->EndAdr+=0x100;
                    Unp->fStrAf=0x135;
                    Unp->StrAdC=0xffff|EA_ADDFF|EA_USE_Y;
                    PrintInfo(Unp,_I_ZIP511);
                }
            }
            else if (*(unsigned int*)(mem+0x807 )==0xF59D0813)
            {
                Unp->Forced=0x801;
                Unp->DepAdr=0x101;
                Unp->RetAdr=mem[0x86c]|mem[0x86d]<<8;
                Unp->EndAdr=mem[0x853]|mem[0x854]<<8;Unp->EndAdr+=0x100;
                Unp->fStrAf=0x135;
                Unp->StrAdC=0xffff|EA_ADDFF|EA_USE_Y;
                PrintInfo(Unp,_I_ZIP513);

            }
            else if (*(unsigned int*)(mem+0x807 )==0xF19D0812)
            {
                Unp->Forced=0x801;
                Unp->DepAdr=0x101;
                Unp->RetAdr=mem[0x855]|mem[0x856]<<8;
                Unp->EndAdr=mem[0x843]|mem[0x844]<<8;Unp->EndAdr+=0x100;
                Unp->fStrAf=0x122;
                Unp->StrAdC=0xffff|EA_ADDFF|EA_USE_Y;
                PrintInfo(Unp,_I_ZIP3);
            }
            if(Unp->DepAdr)
            {
                Unp->IdFlag=1;return;
            }
        }
    }
    /* ALTERED zip50 */
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x803)==0xbd018678) &&
           (*(unsigned int*)(mem+0x807)==0xF59D0812) &&
           (*(unsigned int*)(mem+0x80e)==0x01014CF7) &&
           (*(unsigned int*)(mem+0x85c)==0x858AE9D0))
        {
            Unp->Forced=0x803; /* assumes X=0 on enter */
            Unp->DepAdr=0x101;
            Unp->RetAdr=mem[0x863]|mem[0x864]<<8;
            Unp->EndAdr=mem[0x849]|mem[0x84a]<<8;Unp->EndAdr+=0x100;
            Unp->fStrAf=0x12c;
            Unp->StrAdC=0xffff|EA_ADDFF|EA_USE_Y;
            PrintInfo(Unp,_I_ZIP50H);
            Unp->IdFlag=1;return;
        }
    }
    /* Zipper 5.1/2 */
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x801)==0xE67861A2) &&
            (*(unsigned int*)(mem+0x807)==0xF49D0811) )
        {
            Unp->Forced=0x801;
            Unp->DepAdr=0x101;
            Unp->RetAdr=mem[0x857]|mem[0x858]<<8;
            Unp->EndAdr=mem[0x83e]|mem[0x83f]<<8;Unp->EndAdr+=0x100;
            Unp->fStrAf=0x121; // approximate, Y at that point should be added
            Unp->StrAdC=0xffff|EA_ADDFF|EA_USE_Y;
            PrintInfo(Unp,_I_ZIP512);
            Unp->IdFlag=1;return;
        }
    }
    /* Zipper 8 */
    if( Unp->DepAdr==0 )
    {
        if(((*(unsigned int*)(mem+0x803)&0xff00ffff)==0x8500A978) &&
            (*(unsigned int*)(mem+0x809)==0xE89D0814) &&
            (*(unsigned int*)(mem+0x87e)==0x4A4A4A98) &&
            (*(unsigned int*)(mem+0x80d)==0xF7D0E800) )
        {
            Unp->Forced=0x803;
            Unp->DepAdr=0x100;
            Unp->RetAdr=mem[0x869]|mem[0x86a]<<8;
            Unp->EndAdr=mem[0x81d]|mem[0x81e]<<8;
            Unp->fStrAf=0xf1;
            Unp->StrAdC=0xffff;
            PrintInfo(Unp,_I_ZIP8);
            Unp->IdFlag=1;return;
        }
    }
    /* Zipper 5.1/Xenon */
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x812)==0xBD01E678) &&
            (*(unsigned int*)(mem+0x816)==0xF59D0825) &&
            (*(unsigned int*)(mem+0x822)==0xA501014C) &&
            (*(unsigned int*)(mem+0x826)==0xC602D0FE) &&
            (*(unsigned int*)(mem+0x88e)==0xF9D0E8CB) )
        {
            Unp->DepAdr=0x101;
            Unp->Forced=0x812;
            Unp->EndAdr=mem[0x85c]|mem[0x85d]<<8;Unp->EndAdr+=0x100;
            Unp->RetAdr=mem[0x876]|mem[0x877]<<8;
            Unp->fStrAf=0x12c;
            Unp->StrAdC=EA_USE_Y|EA_ADDFF|0xffff;
            PrintInfo(Unp,_I_ZIP51XEN);
            Unp->IdFlag=1;return;
        }
    }
}
