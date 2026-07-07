/* ISEPIC
   reloads and applies patch like in isepicker
*/
#include "../unp64.h"
void Scn_IsePic(unpstr *Unp)
{
    unsigned char *mem;
    char tmpbuf[512];
    int q,p;
    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if(Unp->DepAdr == 0)
    {
        if((Unp->info->start == 0xffa2) && (Unp->info->end == 0x10000))
        {
            if( (*(unsigned int*)(mem+0xffa2)==0xb913a09a) &&
                (*(unsigned int*)(mem+0xffc0)==0xC406B010) )
            {
                if(mem[0xffa6]==0x80)
                {
                    p=0x0596;
                    q=0x039e;
                }
                else if(mem[0xffa6]==0x82)
                {
                    p=0x05b2; /* unknown variant, not handled by various isepic onefilers! */
                    q=0x03c4; /* initial code is offset by some bytes, depaddr is always at $07b7 */
                }
                else
                {
                    p=0;
                    q=0;
                }
                if(p)
                {
                    /* force reload */
                    memset(mem+(Unp->Filler>>16),Unp->Filler&0xff,0x10000-(Unp->Filler>>16));
                    sprintf(tmpbuf,"%s,$%04x",Unp->name,q);
                    load_located(tmpbuf, mem, Unp->info);
                    Unp->Forced=p;
                    Unp->RTIFrc=1;
                    Unp->DepAdr=mem[0x7b7]|mem[0x7b8]<<8; /* actually it's just the final routine, must check like Expert for the final RTI */
                    Unp->RtAFrc=1;
                    Unp->RetAdr=Unp->DepAdr+0x45;
                    Unp->StrMem=0x2;
                    Unp->EndAdr=0x10000;
                    Unp->FStack=0;
                    mem[p++]=0xA9            ;
                    mem[p++]=0x00            ;
                    mem[p++]=0x8D            ;
                    mem[p++]=0x20            ;
                    mem[p++]=0xD0            ;
                    mem[p++]=0x8D            ;
                    mem[p++]=0x11            ;
                    mem[p++]=0xD0            ;
                    mem[p++]=0xA9            ;
                    mem[p++]=(Unp->info->end&0xff);
                    mem[p++]=0x85            ;
                    mem[p++]=0xAE            ;
                    mem[p++]=0xA9            ;
                    mem[p++]=(Unp->info->end>>8); ;
                    mem[p++]=0x85            ;
                    mem[p++]=0xAF            ;
                    mem[p++]=0xA9            ;
                    mem[p++]=0x7F            ;
                    mem[p++]=0x8D            ;
                    mem[p++]=0x0D            ;
                    mem[p++]=0xDC            ;
                    Unp->IseFlg=1; /* flag */
                    PrintInfo(Unp,_I_ISEPIC);
                    Unp->IdFlag=1;return;
                }
            }
        }
    }
    /* Various Isepics onefilers */
    if(Unp->DepAdr == 0)
    {
        if((*(unsigned int*)(mem+0x0596)==0x208D00A9) &&
           (*(unsigned int*)(mem+0x05a6)==0x0D8D7FA9) &&
           (*(unsigned int*)(mem+0x05f1)==0x4a4a4a4a) )
        {
            Unp->Forced=0x596;
            Unp->DepAdr=mem[0x7b7]|mem[0x7b8]<<8;
            Unp->RtAFrc=1;
            Unp->RetAdr=Unp->DepAdr+0x45;
            Unp->StrMem=0x2;
            Unp->EndAdr=0x10000;
            Unp->RTIFrc=1;
            Unp->FStack=0;
            Unp->IseFlg=1; /* flag */
            PrintInfo(Unp,_I_ISEPDD);
            Unp->IdFlag=1;return;
        }
    }
    if(Unp->DepAdr == 0)
    {
        if((*(unsigned int*)(mem+0x0810)==0x8D7FA978) &&
           (*(unsigned int*)(mem+0x0814)==0xFFA2DC0D) &&
           (*(unsigned int*)(mem+0x0835)==0x01104C01) &&
           (*(unsigned int*)(mem+0x0855)==0x05AB4CEE) &&
           (*(unsigned int*)(mem+0x0cb3)==0x4CE8F810) )
        {
            if(Unp->info->run == -1 )
                Unp->Forced=0x810;
            Unp->DepAdr=mem[0xcb7]|mem[0xcb8]<<8;
            Unp->RtAFrc=1;
            Unp->RetAdr=Unp->DepAdr+0x45;
            Unp->StrMem=0x2;
            Unp->EndAdr=0x10000;
            Unp->RTIFrc=1;
            Unp->FStack=0;
            Unp->IseFlg=1; /* flag */
            PrintInfo(Unp,_I_ISEPCT1);
            Unp->IdFlag=1;return;
        }
    }
    if(Unp->DepAdr == 0)
    {
        if((*(unsigned int*)(mem+0xc750)==0x8530A978) &&
           (*(unsigned int*)(mem+0xc754)==0xA208A001) &&
           (*(unsigned int*)(mem+0xc758)==0xC800BD00) &&
           (*(unsigned int*)(mem+0xc777)==0x05AB4CF5) &&
           (*(unsigned int*)(mem+0xcfb3)==0x4CE8F810) )
        {
            if(Unp->info->run == -1 )
                Unp->Forced=0xc750;
            Unp->DepAdr=mem[0xcfb7]|mem[0xcfb8]<<8;
            Unp->RtAFrc=1;
            Unp->RetAdr=Unp->DepAdr+0x45;
            Unp->StrMem=0x2;
            Unp->EndAdr=0x10000;
            Unp->RTIFrc=1;
            Unp->FStack=0;
            Unp->IseFlg=1; /* flag */
            PrintInfo(Unp,_I_ISEPCT2);
            Unp->IdFlag=1;return;
        }
    }
    if(Unp->DepAdr == 0)
    {
        if((*(unsigned int*)(mem+0x0820)==0x0D8D7FA9) &&
           (*(unsigned int*)(mem+0x0824)==0xBD50A2DC) &&
           (*(unsigned int*)(mem+0x0828)==0x3C9D083B) &&
           (*(unsigned int*)(mem+0x08f4)==0x05AB4CAC) &&
           (*(unsigned int*)(mem+0x0cb3)==0x4CE8F810) )
        {
            if(Unp->info->run == -1 )
                Unp->Forced=0x820;
            Unp->DepAdr=mem[0xcb7]|mem[0xcb8]<<8;
            Unp->RtAFrc=1;
            Unp->RetAdr=Unp->DepAdr+0x45;
            Unp->StrMem=0x2;
            Unp->EndAdr=0x10000;
            Unp->RTIFrc=1;
            Unp->FStack=0;
            Unp->IseFlg=1; /* flag */
            PrintInfo(Unp,_I_ISEP7U1);
            Unp->IdFlag=1;return;
        }
    }
    if(Unp->DepAdr == 0)
    {
        if((*(unsigned int*)(mem+0x0812)==0x0D8D7FA9) &&
           (*(unsigned int*)(mem+0x0816)==0x8D0BA9DC) &&
           (*(unsigned int*)(mem+0x081a)==0x30A9D011) &&
          ((*(unsigned int*)(mem+0x081e)&0x00ffffff)==0x004C0185) )
        {
            p=mem[0x821]|mem[0x822]<<8;
            q=p-0x70;
            if((*(unsigned int*)(mem+p+0x04)==0xAD85AC84) &&
               (*(unsigned int*)(mem+p+0x32)==0x05AB4C9A) &&
               (*(unsigned int*)(mem+q     )==0x4CE8F810) )
            {
                if(Unp->info->run == -1 )
                    Unp->Forced=0x812;
                Unp->DepAdr=mem[q+4]|mem[q+5]<<8;
                Unp->RtAFrc=1;
                Unp->RetAdr=Unp->DepAdr+0x45;
                Unp->StrMem=0x2;
                Unp->EndAdr=0x10000;
                Unp->RTIFrc=1;
                Unp->FStack=0;
                Unp->IseFlg=1; /* flag */
                PrintInfo(Unp,_I_ISEP7U2);
                Unp->IdFlag=1;return;
            }
        }
    }
    if(Unp->DepAdr == 0)
    {
        if((*(unsigned int*)(mem+0x0827)==0x0D8D7FA9) &&
           (*(unsigned int*)(mem+0x082b)==0xECFEA2DC) &&
           (*(unsigned int*)(mem+0x082f)==0x06D0086B) &&
           (*(unsigned int*)(mem+0x0833)==0x086DECE8) &&
           (*(unsigned int*)(mem+0x0ab7)==0x4CE8F810) )
        {
            if(Unp->info->run == -1 )
                Unp->Forced=0x827;
            Unp->DepAdr=mem[0xabb]|mem[0xabc]<<8;
            Unp->RtAFrc=1;
            Unp->RetAdr=Unp->DepAdr+0x45;
            Unp->StrMem=0x2;
            Unp->EndAdr=0x10000;
            Unp->RTIFrc=1;
            Unp->FStack=0;
            Unp->IseFlg=1; /* flag */
            PrintInfo(Unp,_I_ISEPGS1);
            Unp->IdFlag=1;return;
        }
    }
    if(Unp->DepAdr == 0)
    {
        if((*(unsigned int*)(mem+0x080d)==0x2901A578) &&
           (*(unsigned int*)(mem+0x0811)==0xAD0185FE) &&
           (*(unsigned int*)(mem+0x0855)==0x05AB4CAF) &&
           (*(unsigned int*)(mem+0x08dc)==0x2005AB4C) &&
           (*(unsigned int*)(mem+0x0c70)==0x4CE8F810) )
        {
            if(Unp->info->run == -1 )
                Unp->Forced=0x80d;
            Unp->DepAdr=mem[0xc74]|mem[0xc75]<<8;
            Unp->RtAFrc=1;
            Unp->RetAdr=Unp->DepAdr+0x45;
            Unp->StrMem=0x2;
            Unp->EndAdr=0x10000;
            Unp->RTIFrc=1;
            Unp->FStack=0;
            Unp->IseFlg=1; /* flag */
            /* replace jsr $fcdx with jsr $00dx */
            memcpy(mem+0xd1, roms[1]+0x1cd1,0x32);
            mem[0x848]=0;
            mem[0x84b]=0;
            PrintInfo(Unp,_I_ISEPNC);
            Unp->IdFlag=1;return;
        }
    }
    if(Unp->DepAdr == 0)
    {
        if((*(unsigned int*)(mem+0x0816)==0x23B927A0) &&
           (*(unsigned int*)(mem+0x0846)==0x974CAE86) &&
           (*(unsigned int*)(mem+0x08a6)==0x4CAC1088) &&
           (*(unsigned int*)(mem+0x08aa)==0xA92905AB) &&
           (*(unsigned int*)(mem+0x0C67)==0x4CE8F810) )
        {
            if(Unp->info->run == -1 )
                Unp->Forced=0x816;
            Unp->DepAdr=mem[0xc6b]|mem[0xc6c]<<8;
            Unp->RtAFrc=1;
            Unp->RetAdr=Unp->DepAdr+0x45;
            Unp->StrMem=0x2;
            Unp->EndAdr=0x10000;
            Unp->RTIFrc=1;
            Unp->FStack=0;
            Unp->IseFlg=1; /* flag */
            PrintInfo(Unp,_I_ISEPAMG);
            Unp->IdFlag=1;return;
        }
    }
    if(Unp->DepAdr == 0)
    {
        if((*(unsigned int*)(mem+0x05ab)==0xB084FFA0) &&
           (*(unsigned int*)(mem+0x067C)==0x003E4CC8) &&
           (*(unsigned int*)(mem+0x05f1)==0x4a4a4a4a) &&
           (*(unsigned int*)(mem+0x05fe)==0x4a4a4a4a) )
        {
            Unp->Forced=0x5ab;
            Unp->DepAdr=mem[0x7b7]|mem[0x7b8]<<8;
            Unp->RtAFrc=1;
            Unp->RetAdr=Unp->DepAdr+0x45;
            Unp->StrMem=0x2;
            Unp->EndAdr=0x10000;
            Unp->RTIFrc=1;
            Unp->FStack=0;
            Unp->IseFlg=1; /* flag */
            PrintInfo(Unp,_I_ISEPGEN);
            Unp->IdFlag=1;return;
        }
    }
}
