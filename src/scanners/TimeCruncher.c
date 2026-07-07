/* TimeCruncher and clones */
#include "../unp64.h"
void Scn_TimeCruncher(unpstr *Unp)
{
    unsigned char *mem;
    int q,p;
    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {   /*TimeCruncher 4.0 */
        if( (*(unsigned int*)(mem+0x811)==0x00A201E6) &&
            (*(unsigned int*)(mem+0x82e)==0xAD4C2E85) &&
            (*(unsigned int*)(mem+0x83d)==0x0377204C) )
        {
            Unp->DepAdr=0x3ad;
            if(Unp->info->run == -1)
                Unp->Forced=0x811;
            Unp->RetAdr=mem[0x966]|mem[0x967]<<8;
            Unp->EndAdr=mem[0x829]|mem[0x82d]<<8;
            Unp->fStrAf=0xfc;  /* to test */
            PrintInfo(Unp,_I_TC40   );
            Unp->IdFlag=1;return;
        }
    }
    /*TimeCruncher 4.2 pre-header*/
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x811+0x84)==0x31BD0186) &&
            (*(unsigned int*)(mem+0x82c+0x84)==0xAD4C2E85) &&
            (*(unsigned int*)(mem+0x83b+0x84)==0x0377204C) &&
            (*(unsigned int*)(mem+0x842)==0x9D088FBD) &&
            (*(unsigned int*)(mem+0x846)==0xD0E8080B) )
        {
            Unp->DepAdr=mem[0x839]|mem[0x83a]<<8;
            if(Unp->info->run == -1)
                Unp->Forced=0x80d;
            Unp->RetAdr=mem[0x864]|mem[0x865]<<8;
            Unp->EndAdr=Unp->info->end-0x84;
            Unp->StrMem=0x801;
            if( (*(unsigned int*)(mem+0x85c)==0xFDA32058) &&
                (*(unsigned int*)(mem+0x860)==0x4CFD1520) )
            {
                mem[0x85d]=0x2c;
                mem[0x860]=0x2c;
            }
            mem[0x808]=0x35;
            mem[0x809]=0x39;
            mem[0x80a]=0x00;
            PrintInfo(Unp,_I_TC42H  );
            if(Unp->DebugP)
                printmsg(mem,0x867,40);
            Unp->IdFlag=1;return;
        }
    }
    /*TimeCruncher 4.2 pre-header / ILS */
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x811+0x9d)==0x31BD0186) &&
            (*(unsigned int*)(mem+0x82c+0x9d)==0xAD4C2E85) &&
            (*(unsigned int*)(mem+0x83b+0x9d)==0x0377204C) &&
            (*(unsigned int*)(mem+0x84d)==0x9D08a8BD) &&
            (*(unsigned int*)(mem+0x851)==0xD0E8080B) )
        {
            Unp->DepAdr=mem[0x844]|mem[0x845]<<8;
            if(Unp->info->run == -1)
                Unp->Forced=0x810;
            Unp->RetAdr=mem[0x86f]|mem[0x870]<<8;
            Unp->EndAdr=Unp->info->end-0x9d;
            Unp->StrMem=0x801;
            if( (*(unsigned int*)(mem+0x867)==0xFDA32058) &&
                (*(unsigned int*)(mem+0x86b)==0x4CFD1520) )
            {
                mem[0x868]=0x2c;
                mem[0x86b]=0x2c;
            }
            if( (mem[0x961]==0xf2)&&
                (mem[0x962]==0x03) )
            {
                mem[0x961]=0x0;
                mem[0x962]=0x1;
            }
            mem[0x808]=0x35;
            mem[0x809]=0x39;
            mem[0x80a]=0x00;
            PrintInfo(Unp,_I_TC40HIL);
            if(Unp->DebugP)
                printmsg(mem,0x880,40);
            Unp->IdFlag=1;return;
        }
    }
    /*TimeCruncher pre-header by Vikings */
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x81a)==0x018535a9) &&
            (*(unsigned int*)(mem+0x81e)==0x2CBD00A2) &&
            (*(unsigned int*)(mem+0x822)==0x04009D08) &&
            (*(unsigned int*)(mem+0x833)==0xEE08019D) &&
            (*(unsigned int*)(mem+0x846)==0xD0C90404) )
        {
            Unp->DepAdr=0x400;
            if(Unp->info->run == -1)
                Unp->Forced=0x81a;
            Unp->RetAdr=mem[0x861]|mem[0x862]<<8;
            Unp->EndAdr=Unp->info->end-0x62;
            Unp->StrMem=0x801;
            PrintInfo(Unp,_I_TCHVIK);
            Unp->IdFlag=1;return;
        }
    }
    /*TimeCruncher 4.2 */
    if( Unp->DepAdr==0 )
    {
        if( /*((*(unsigned int*)(mem+0x80b)&0x00ffffff)==0x007800A2) &&*/
            (*(unsigned int*)(mem+0x811)==0x31BD0186) &&
           ((*(unsigned int*)(mem+0x82c)==0xAD4C2E85)||(*(unsigned int*)(mem+0x82c)==0xAD4Caf85))&&
           ((*(unsigned int*)(mem+0x83b)&0xf0ffffff)==0x0077204C) &&
           ((*(unsigned int*)(mem+0x951)&0xf0ffffff)==0x003C4C68) )
        {
            Unp->DepAdr=mem[0x82f]|mem[0x830]<<8;
            //if( Unp->info->run == -1 )
            Unp->Forced=0x811;
            for(q=0x95f;q<0x964;q++)
            {
                if(mem[q]==0x4c)
                {
                    Unp->RetAdr=mem[q+1]|mem[q+2]<<8;
                    break;
                }
            }
            Unp->EndAdr=mem[0x833]|mem[0x834]<<8;
            Unp->StrMem=0x801; /* tested crunching a prg starting at $1000, it's decrunched at $801 anyway! */
            /* ILS hack, has border flash at $3f2 left there by the preheader */
            if( (mem[0x8c4]==0xf2)&&
                (mem[0x8c5]==0x03) )
            {
                mem[0x8c4]=0x0;
                mem[0x8c5]=0x1;
            }
            PrintInfo(Unp,_I_TC42   );
            Unp->IdFlag=1;return;
        }
    }
    /*TimeCruncher 4.3? */
    if( Unp->DepAdr==0 )
    {
        if(((*(unsigned int*)(mem+0x82b)&0x00ffffff)==0x0003AA4C) &&
            (*(unsigned int*)(mem+0x80a)==0x7800A200) &&
            (*(unsigned int*)(mem+0x834)==0x90037420) &&
            (*(unsigned int*)(mem+0x954)==0xF2D007C0) )
        {
            Unp->DepAdr=0x3aa;
            if(Unp->info->run == -1)
                Unp->Forced=0x80b;
            Unp->RetAdr=mem[0x95e]|mem[0x95f]<<8;
            Unp->EndAdr=mem[0x830]|mem[0x831]<<8;
            Unp->StrMem=0x801;
            PrintInfo(Unp,_I_TC43   );
            Unp->IdFlag=1;return;
        }
    }
    /*TimeCruncher 4.4 */
    if( Unp->DepAdr==0 )
    {
        if(((*(unsigned short int*)(mem+0x80b)&0xfff0)==0x00A0) &&
           (*(unsigned int*)(mem+0x811)==0xFA9D082E) &&
           (*(unsigned int*)(mem+0x82a)==0x03AE4C00) &&
           (*(unsigned int*)(mem+0x83a)==0x04B00374) )
        {
            Unp->DepAdr=0x3ae;
            if(Unp->info->run == -1)
                Unp->Forced=0x80b;
            Unp->RetAdr=mem[0x95e]|mem[0x95f]<<8;
            Unp->EndAdr=mem[0x830]|mem[0x831]<<8;
            Unp->fStrAf=0xfc;
            PrintInfo(Unp,_I_TC44   );
            Unp->IdFlag=1;return;
        }
    }
    /*TimeCruncher 5 */
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x813)==0xBD9AFFA2) &&
           (*(unsigned int*)(mem+0x817)==0xF89D0837) &&
           (*(unsigned int*)(mem+0x81b)==0xF7D0CA00) &&
           (*(unsigned int*)(mem+0x82b)==0x2E842D85) )
        {
            Unp->IdFlag=1;
            if(Unp->info->run == -1)
                Unp->Forced=0x813;
            Unp->EndAdr=mem[0x828]|mem[0x82a]<<8;
            Unp->DepAdr=0x100;
            /* same as Stoat&Tim Timecrunch 2mhz v5 */
            PrintInfo(Unp,_I_TC50   );
        }
        else
        if((*(unsigned int*)(mem+0x80f)==0x9AFFA278) &&
           (*(unsigned int*)(mem+0x813)==0x9D0837BD) &&
           (*(unsigned int*)(mem+0x817)==0xD0CA00F8) &&
           (*(unsigned int*)(mem+0x82b)==0x2E842D85) )
        {
            Unp->IdFlag=1;
            if(Unp->info->run == -1)
                Unp->Forced=0x812;
            Unp->DepAdr=0x100;
            Unp->EndAdr=mem[0x828]|mem[0x82a]<<8;
            PrintInfo(Unp,_I_TC51   );
        }
        else
        if((*(unsigned int*)(mem+0x819)==0x9AFFA278) &&
           (*(unsigned int*)(mem+0x81d)==0x9D0837BD) &&
           (*(unsigned int*)(mem+0x821)==0xD0CA00F8) &&
           (*(unsigned int*)(mem+0x82f)==0x2E842D85) )
        {
            Unp->IdFlag=1;
            if(Unp->info->run == -1)
                Unp->Forced=0x819;
            Unp->DepAdr=0x100;
            Unp->EndAdr=mem[0x82c]|mem[0x82e]<<8;
            PrintInfo(Unp,_I_TC52   );
        }
        else
        if((*(unsigned int*)(mem+0x810)==0x9AFFA278) &&
           (*(unsigned int*)(mem+0x814)==0x9D0837BD) &&
           (*(unsigned int*)(mem+0x818)==0xD0CA00F8) &&
           (*(unsigned int*)(mem+0x82b)==0x2E842D85) )
        {
            Unp->IdFlag=1;
            if(Unp->info->run == -1)
                Unp->Forced=0x810;
            Unp->DepAdr=0x100;
            Unp->EndAdr=mem[0x828]|mem[0x82a]<<8; /* also at $83d/e (add 1) */
            PrintInfo(Unp,_I_TC53 ); /* hack at 2064 found in Mentallic/PD */
        }
        else /* 5.0 gen hack */
        if((*(unsigned int*)(mem+0x841)==0x07E89D09) &&
           (*(unsigned int*)(mem+0x851)==0x9D2002A2) &&
           (*(unsigned int*)(mem+0x861)==0x90066901) &&
           (*(unsigned int*)(mem+0x901)==0xC0FCC6FD) )
        {
            Unp->IdFlag=1;
            for(q=0x801;q<0x830;q++)
            {
                if(mem[q]==0x78)
                {
                    if(Unp->info->run == -1)
                    {
                        Unp->Forced=q;
                        Unp->info->run=q;
                    }
                }
                if((Unp->EndAdr==0x10000)&&
                   (mem[q]==0xa9)&&
                   (mem[q+2]==0xa0)&&
                   (*(unsigned int*)(mem+q+4)==0x2E842D85)
                  )
                {
                    Unp->EndAdr=mem[q+1]|mem[q+3]<<8;
                }
            }
            Unp->DepAdr=0x100;
            PrintInfo(Unp,_I_TC5GEN );
        }
        if( Unp->IdFlag )
        {
            for(q=0x912;q<0x927;q++)
            {
                if(mem[q]==0xa9)
                {
                    q++;
                    continue;
                }
                if((mem[q]==0x8d)||
                   (mem[q]==0xce)||
                   (mem[q]==0x2c) )
                {
                    q+=2;
                    continue;
                }
                if(mem[q]==0x20)
                {
                    if( (*(unsigned short int*)(mem+q+1) == 0xa659) ||
                        (*(unsigned short int*)(mem+q+1) == 0xff81) ||
                        (*(unsigned short int*)(mem+q+1) == 0xe3bf) ||
                        (*(unsigned short int*)(mem+q+1) == 0xe544) ||
                        (*(unsigned short int*)(mem+q+1) == 0xe5a0) ||
                        (*(unsigned short int*)(mem+q+1) == 0xe518) )
                    {
                        mem[q]=0x2c;q+=2;
                        continue;
                    }
                    else
                    {
                        Unp->RetAdr=mem[q+1]|mem[q+2]<<8;
                        break;
                    }
                }
                if(mem[q]==0x4c)
                {
                    Unp->RetAdr=mem[q+1]|mem[q+2]<<8;
                    break;
                }
            }
            Unp->fStrAf=0xfe;
            return;
        }
    }
    /*TimeCruncher 3.0? */
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x818)==0x8534A978) &&
           (*(unsigned int*)(mem+0x81c)==0xBDD2A201) &&
           (*(unsigned int*)(mem+0x820)==0xF99D0850) &&
           (*(unsigned int*)(mem+0x824)==0xB079E000) &&
           (*(unsigned int*)(mem+0x8c1)==0xa0033420) )
        {
            Unp->DepAdr=0x100;
            if(Unp->info->run == -1)
                Unp->Forced=0x818;
            Unp->RetAdr=mem[0x95c]|mem[0x95d]<<8;
            Unp->EndAdr=0x2d;
            Unp->StrMem=0x0801;
            PrintInfo(Unp,_I_TC30   );
            Unp->IdFlag=1;return;
        }
    }
    /*TimeCruncher 3.1+ */
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x847)==0xC807E899) &&
           (*(unsigned int*)(mem+0x84b)==0x02EEF7D0) &&
           (*(unsigned int*)(mem+0x84f)==0x0105EE01) &&
           (*(unsigned int*)(mem+0x816)==0x3CB9C4A0) &&
           (*(unsigned int*)(mem+0x967)==0x4C01E678) )
        {
            Unp->DepAdr=0x100;
            if(Unp->info->run == -1)
                Unp->Forced=0x967;
            Unp->RetAdr=mem[0x934]|mem[0x935]<<8;
            Unp->EndAdr=mem[0x833]|mem[0x837]<<8;
            Unp->fStrAf=0xfc;

            PrintInfo(Unp,_I_TC31PLUS );
            if(Unp->RetAdr == 0x277 )
            { /* this version only issues RUN and has no text */
                Unp->RetAdr=0xa7ae;
            }
            else if(Unp->DebugP)
                printmsg(mem, 0x80d,9);
            Unp->IdFlag=1;return;
        }
    }
    /*TimeCruncher 3.3/2066 */
    if( Unp->DepAdr==0 )
    {
        if((mem[0x812]==0x78) &&
           ((*(unsigned int*)(mem+0x818)&0xfffff0ff)==0x018530a9)&&
           (*(unsigned int*)(mem+0x820)==0xF899083C) &&
           (*(unsigned int*)(mem+0x82b)==0x03339908) &&
           (*(unsigned int*)(mem+0x838)==0x004C2E85) )
        {
            Unp->DepAdr=0x100;
            if(Unp->info->run == -1)
                Unp->Forced=0x812;
            Unp->EndAdr=mem[0x833]|mem[0x837]<<8;
            for(p=0x91a;p<0x931;p++)
            {
                if((*(unsigned int*)(mem+p)&0xff00ffff)==0x4c000185)
                {
                    Unp->RetAdr=mem[p+4]|mem[p+5]<<8;
                    Unp->fStrAf=0xfc;
                }
            }
            PrintInfo(Unp,_I_TC33   );
            Unp->IdFlag=1;return;
        }
    }

    /* Stoat&Tim Timecrunch 2mhz v1 */
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x813)==0xBDBFA278) &&
           (*(unsigned int*)(mem+0x817)==0xF99D0841) &&
           (*(unsigned int*)(mem+0x81b)==0x0900BD00) &&
           (*(unsigned int*)(mem+0x833)==0xAE852D85) &&
           (*(unsigned int*)(mem+0x930)==0xA9D6D007) )
        {
            Unp->DepAdr=0x100;
            if(Unp->info->run == -1)
                Unp->Forced=0x813;
            Unp->RetAdr=mem[0x941]|mem[0x942]<<8;
            Unp->EndAdr=mem[0x832]|mem[0x838]<<8;
            Unp->fStrAf=0xfc;
            PrintInfo(Unp,_I_TC2MHZ1);
            Unp->IdFlag=1;return;
        }
    }
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x813)==0xB9BFA078) &&
           (*(unsigned int*)(mem+0x817)==0xF9990840) &&
           (*(unsigned int*)(mem+0x81b)==0x08ffB900) &&
           (*(unsigned int*)(mem+0x832)==0xAE852D85) &&
           (*(unsigned int*)(mem+0x92f)==0xA9D6D007) )
        {
            Unp->DepAdr=0x100;
            Unp->Forced=0x813;
            Unp->RetAdr=mem[0x940]|mem[0x941]<<8;
            Unp->EndAdr=mem[0x831]|mem[0x837]<<8;
            Unp->fStrAf=0xfc;
            PrintInfo(Unp,_I_TC2MHZ2);
            Unp->IdFlag=1;return;
        }
    }

    /*TimeCruncher 3.1+/2061 */
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x80d)==0x8534A978)||
           (((mem[0x80d]==0x20)||(mem[0x080d]==0x4c))&&(mem[0x810]==0x85)) )
        {
            if((*(unsigned int*)(mem+0x811)==0xB9C4A001) &&
               (*(unsigned int*)(mem+0x815)==0xF899083C) &&
               (*(unsigned int*)(mem+0x838)==0x004C2E85) )
            {
                Unp->DepAdr=0x100;
                if( Unp->info->run == -1 )
                    Unp->Forced=0x80d;
                Unp->RetAdr=mem[0x934]|mem[0x935]<<8;
                Unp->EndAdr=mem[0x833]|mem[0x837]<<8;
                Unp->fStrAf=0xfc;
                PrintInfo(Unp,_I_TC32061);
                Unp->IdFlag=1;return;
            }
            if((*(unsigned int*)(mem+0x811)==0xB9C1A001) &&
               (*(unsigned int*)(mem+0x815)==0xF8990831) &&
               (*(unsigned int*)(mem+0x82d)==0x004Caf85) )
            {
                Unp->DepAdr=0x100;
                if( Unp->info->run == -1 )
                    Unp->Forced=0x80d;
                Unp->RetAdr=mem[0x929]|mem[0x92a]<<8;
                Unp->EndAdr=mem[0x824]|mem[0x82a]<<8;
                Unp->fStrAf=0xfc;
                PrintInfo(Unp,_I_TCMC4  );
                Unp->IdFlag=1;return;
            }
        }
    }
    /*TimeCruncher 3.1 aka Matcham Speed-Packer (sys2072) */
    if( Unp->DepAdr==0 )
    {
        if(((((*(unsigned int*)(mem+0x818))&0xfff0ffff)==0x8530A978)||
              (*(unsigned int*)(mem+0x818)==0x8578d020)  )  &&
              (*(unsigned int*)(mem+0x81c)==0xB9C4A001)     &&
              (*(unsigned int*)(mem+0x820)==0xF899083C)     &&
             ((*(unsigned int*)(mem+0x838)==0x004C2E85)||
              (*(unsigned int*)(mem+0x838)==0x004Caf85))    &&
           mem[0x83c]==0x01)
        {
            Unp->DepAdr=0x100;
            if(mem[0x081a]==0x78)
            {
                if( Unp->info->run == -1 )
                    Unp->Forced=0x81a;
            }
            else
            {
                if( Unp->info->run == -1 )
                    Unp->Forced=0x818;
            }
            if((mem[0x91d]==0x4c) && (mem[0x896]==0x19))
                PrintInfo(Unp,_I_TC31SP);
            else
                PrintInfo(Unp,_I_TC31);
            Unp->EndAdr=mem[0x833]|mem[0x837]<<8;
            // Henk/HTL, RWE & Speed-packer $91a, Timecr 3.1 Matcham/NET $930
            for(p=0x91a;p<0x931;p++)
            {
                if((*(unsigned int*)(mem+p)&0xff00ffff)==0x4c000185)
                {
                    Unp->RetAdr=mem[p+4]|mem[p+5]<<8;
                    Unp->fStrAf=0xfc;
                    Unp->StrAdC=0xffff;
                }
            }
            Unp->IdFlag=1;return;
        }
    }
    /*TimeCruncher /Radical? */
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x80b)==0x3CB900A0) &&
           (*(unsigned int*)(mem+0x80f)==0x00F89908) &&
           (*(unsigned int*)(mem+0x820)==0xF899083C) &&
           (*(unsigned int*)(mem+0x839)==0x04004C2E))
        {
            Unp->DepAdr=0x400;
            Unp->Forced=0x80b;
            Unp->EndAdr=mem[0x833]|mem[0x837]<<8;
            Unp->RetAdr=mem[0x91e]|mem[0x91f]<<8;
            Unp->fStrAf=0xfc;
            PrintInfo(Unp,_I_TC3RAD );
            Unp->IdFlag=1;return;
        }
    }
    /*TimeCruncher /2074 */
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x81a)==0xC4A00185) &&
           (*(unsigned int*)(mem+0x81e)==0x99083DB9) &&
           (*(unsigned int*)(mem+0x822)==0xFDB900F9) &&
           (*(unsigned int*)(mem+0x836)==0xA2AF852E))
        {
            Unp->DepAdr=0x101;
            if(Unp->info->run == -1)
                Unp->Forced=0x81a;
            Unp->EndAdr=mem[0x82e]|mem[0x834]<<8;
            for(p=0x935;p<0x93a;p++)
            {
                if(*(mem+p)==0x4c)
                {
                    Unp->RetAdr=mem[p+1]|mem[p+2]<<8;
                    Unp->fStrAf=0xfc;
                }
            }
            PrintInfo(Unp,_I_TC32074);
            Unp->IdFlag=1;return;
        }
    }
    /*TimeCruncher /Fast pack'em */
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x84f)==0x4909C8BD) &&
           (*(unsigned int*)(mem+0x857)==0xA0F510CA) &&
           (*(unsigned int*)(mem+0x85b)==0x087DB9C1) &&
           (*(unsigned int*)(mem+0x885)==0x9909EEB9) )
        {
            Unp->DepAdr=0x100;
            if(Unp->info->run==-1)
            {
                p=0x830;
                if(mem[p]==0x78)
                    Unp->Forced=p;
                else
                {
                    p=0x834;
                    if(mem[p]==0x78)
                        Unp->Forced=p;
                }
            }
            Unp->RetAdr=mem[0x975]|mem[0x976]<<8;
            Unp->EndAdr=mem[0x86c]|mem[0x872]<<8;
            Unp->fStrAf=0xfc;
            PrintInfo(Unp,_I_TC3FPE );
            if(Unp->DebugP)
            {
                p=mem[0x850]|mem[0x851]<<8;
                q=40;
                if(mem[0x852]==0x49)
                {
                    for(q=0;q<40&&mem[p+q];q++)
                    {
                        mem[p+q]^=mem[0x853];
                    }
                }
                printmsg(mem, p, q);
            }
            Unp->IdFlag=1;return;
        }
    }
    /*TimeCruncher /FBI */
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x888)==0xC807E899) &&
           (*(unsigned int*)(mem+0x88c)==0x02EEF7D0) &&
           (*(unsigned int*)(mem+0x890)==0x0105EE01) &&
           (*(unsigned int*)(mem+0x80d)==0xFFA2D878) &&
           (*(unsigned int*)(mem+0x971)==0x4C580185) )
        {
            Unp->DepAdr=0x100;
            Unp->Forced=0x80d;
            Unp->RetAdr=mem[0x975]|mem[0x976]<<8;
            Unp->EndAdr=mem[0x86c]|mem[0x872]<<8;
            Unp->fStrAf=0xfc;
            PrintInfo(Unp,_I_TC3FBI );
            if(Unp->DebugP)
                printmsg(mem,(mem[0x823]|mem[0x824]<<8),mem[0x82a]);
            Unp->IdFlag=1;return;
        }
    }
    /*TimeCruncher /Triumwyrat aka Final Cut Compressor */
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x822)==0x04289D09) &&
           (*(unsigned int*)(mem+0x85b)==0x087DB9C1) &&
           (*(unsigned int*)(mem+0x87a)==0x01004c01)
          )
        {
            if(Unp->info->run == -1)
                Unp->Forced=0x818;
            Unp->DepAdr=0x100;
            Unp->EndAdr=mem[0x86c]|mem[0x872]<<8;
            Unp->fStrAf=0xfc;
            Unp->RetAdr=mem[0x975]|mem[0x976]<<8;
            if (Unp->RetAdr == 0x3cd )
            {
                Unp->RetAdr=mem[0x9e3]|mem[0x9e4]<<8;
                if (Unp->RetAdr == 0xa659 )
                {
                    mem[0x9e2]=0x2c;
                    Unp->RetAdr=mem[0x9e6]|mem[0x9e7]<<8;
                }
            }
            PrintInfo(Unp,_I_TC3TRI );
            if(Unp->DebugP)
                printmsg(mem, 0x9a8,40);
            Unp->IdFlag=1;return;
        }
    }
    /*TimeCruncher generic hacks*/
    if( Unp->DepAdr==0 )
    {
        if(((*(unsigned int*)(mem+0x839)&0xffffff00)==0x01004C00)&&
           ((*(unsigned int*)(mem+0x847)&0xfffff0ff)==0xC807E099)&&
           (*(unsigned int*)(mem+0x84b)==0x02EEF7D0) &&
           (*(unsigned int*)(mem+0x84f)==0x0105EE01) &&
           (*(unsigned int*)(mem+0x91f)==0xC6FFC602) )
        {
            if(Unp->info->run == -1)
            {
                for(p=0x80b;p<0x820;p++)
                {
                    if(mem[p]==0x78)
                    {
                        Unp->Forced=p;
                        break;
                    }
                }
            }
            Unp->DepAdr=0x100;
            Unp->EndAdr=mem[0x833]|mem[0x837]<<8;
            Unp->RetAdr=mem[0x934]|mem[0x935]<<8;
            Unp->fStrAf=0xfc;
            /*HTL hack (lax $dd07)*/
            if( *(unsigned int*)(mem+0x822)==0xE0DD07AF )
            {
                mem[0x0822]=0xa9;
                mem[0x0823]=0xff;
                mem[0x0824]=0xaa;
                PrintInfo(Unp,_I_TC3HTL );
            }
            else
            {
                PrintInfo(Unp,_I_TCGENH );
            }
            Unp->IdFlag=1;return;
        }
    }
    /* File Press Expert/SIR crunch 1 */
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x824)==0x018534A9) &&
           (*(unsigned int*)(mem+0x82a)==0x99083CB9) &&
           (*(unsigned int*)(mem+0x82e)==0xB9D800F8) &&
           (*(unsigned int*)(mem+0x892)==0xD0033420) &&
           (*(unsigned int*)(mem+0x940)==0x01E6EC10) )
        {
            Unp->DepAdr=0x100;
            if(Unp->info->run == -1)
                Unp->Forced=0x81e;
            Unp->EndAdr=mem[0x840]|mem[0x841]<<8;
            Unp->StrMem=0x801;
            p=0x96f;
            if( mem[p]==0x4c )
            {
                PrintInfo(Unp,_I_TCFPEX );
                Unp->RetAdr=mem[p+1]|mem[p+2]<<8;
            }
            else if( mem[p+1]==0x4c )
            {
                PrintInfo(Unp,_I_TCSIR1 );
                Unp->RetAdr=mem[p+2]|mem[p+3]<<8;
            }
            else
            {
                PrintInfo(Unp,_I_TCUNKH );
            }
            Unp->IdFlag=1;return;
        }
    }
    /* SIR crunch 4 */
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x81b)==0x018534A9) &&
           (*(unsigned int*)(mem+0x81f)==0x3BB9C4A0) &&
           (*(unsigned int*)(mem+0x82b)==0x88033399) &&
           (*(unsigned int*)(mem+0x95F)==0xA2F0FEC6) )
        {
            Unp->DepAdr=0x100;
            if(Unp->info->run == -1)
                Unp->Forced=0x81b;
            Unp->RetAdr=mem[0x970]|mem[0x971]<<8;
            Unp->EndAdr=mem[0x83f]|mem[0x840]<<8;
            Unp->StrMem=0x801;
            PrintInfo(Unp,_I_TCSIR4 );
            Unp->IdFlag=1;return;
        }
    }
    /* SIR crunch 3 */
    if( Unp->DepAdr==0 )
    {
        if((mem[0x81e]==0x78) &&
           (*(unsigned int*)(mem+0x824)==0x018534A9) &&
           (*(unsigned int*)(mem+0x828)==0x48B9C4A0) &&
           (*(unsigned int*)(mem+0x834)==0x88033399) &&
           (*(unsigned int*)(mem+0x96c)==0xA2F0FEC6) )
        {
            Unp->DepAdr=0x100;
            Unp->Forced=0x824;
            p=mem[0x980]|mem[0x981]<<8;
            if((mem[0x97c]==0x20) || (mem[0x97c]==0x4c))
            {
                q=mem[0x97d]|mem[0x97e]<<8;
                if( q != 0xa659 )
                    p=q;
            }
            Unp->RetAdr=p;
            Unp->EndAdr=mem[0x84c]|mem[0x84d]<<8;
            //Unp->fStrAf=0xfc;
            PrintInfo(Unp,_I_TCSIR3 );
            Unp->IdFlag=1;return;
        }
    }
    /* SIR crunch 2.x */
    if( Unp->DepAdr==0 )
    {
        if((mem[0x81e]==0x78) &&
           (*(unsigned int*)(mem+0x824)==0x018534A9) &&
           (*(unsigned int*)(mem+0x828)==0x4aB9C4A0) &&
           (*(unsigned int*)(mem+0x834)==0x88033399) &&
           (*(unsigned int*)(mem+0x96e)==0xA2F0FEC6) )
        {
            Unp->DepAdr=0x100;
            Unp->Forced=0x824;
            p=mem[0x982]|mem[0x983]<<8;
            if((mem[0x97e]==0x20) || (mem[0x97e]==0x4c))
            {
                q=mem[0x97f]|mem[0x980]<<8;
                if( q != 0xa659 )
                    p=q;
            }
            Unp->RetAdr=p;
            Unp->EndAdr=mem[0x84e]|mem[0x84f]<<8;
            Unp->StrMem=0x801;
            PrintInfo(Unp,_I_TCSIR2 );
            Unp->IdFlag=1;return;
        }
    }
    /* Entropy hack? similar to SIR crunch 3, at $80d */
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x80e)==0x23B9C4A0) &&
           (*(unsigned int*)(mem+0x816)==0x9908E4B9) &&
           (*(unsigned int*)(mem+0x81a)==0xD0880333) &&
           (*(unsigned int*)(mem+0x947)==0xA2F0FEC6) )
        {
            Unp->DepAdr=0x100;
            Unp->Forced=0x80e;
            Unp->RetAdr=mem[0x94e]|mem[0x94f]<<8;
            Unp->StrMem=0x801;
            Unp->EndAdr=mem[0x827]|mem[0x828]<<8;
            PrintInfo(Unp,_I_TC3ENT);
            Unp->IdFlag=1;return;
        }
    }
    /* SupraCompactor 2.0/TKC - TC 5 clone + unpacktext */
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x817)==0xBD9ACA78) &&
           (*(unsigned int*)(mem+0x81b)==0xF89D0842) &&
           (*(unsigned int*)(mem+0x84b)==0xE89D0935) &&
           (*(unsigned int*)(mem+0x90f)==0xDCD0E7C0) )
        {
            Unp->DepAdr=0x100;
            Unp->Forced=0x817;
            if (*(unsigned int*)(mem+0x91f)==0xA6592008)
            {
                mem[0x920]=0x2c;
                Unp->RetAdr=mem[0x925]|mem[0x926]<<8;
            }
            else
            {
                Unp->RetAdr=mem[0x921]|mem[0x922]<<8;
            }
            Unp->EndAdr=mem[0x848]|mem[0x849]<<8;Unp->EndAdr++;
            Unp->fStrAf=0xfe;
            PrintInfo(Unp,_I_TC5SC  );
            if(Unp->DebugP)
                printmsg(mem,0x834,0x0f);
            Unp->IdFlag=1;return;
        }
    }
    /* Relax Timer, TimeCruncher 3.0 hack? very similar to mastercompr/relax */
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x816)==0x8534A978) &&
           (*(unsigned int*)(mem+0x81a)==0xBDD2A201) &&
           (*(unsigned int*)(mem+0x81e)==0xF99D084e) &&
           (*(unsigned int*)(mem+0x822)==0xB073E000) &&
           (*(unsigned int*)(mem+0x8bf)==0xa0033420) )
        {
            Unp->DepAdr=0x100;
            Unp->Forced=0x816;
            Unp->RetAdr=mem[0x94d]|mem[0x94e]<<8;
            Unp->EndAdr=0x2d;
            Unp->StrMem=0x0801;
            PrintInfo(Unp,_I_TC3RLX );
            Unp->IdFlag=1;return;
        }
    }
    /* TimeCruncher 3/Triad, same as Relax but at $812 */
    if( Unp->DepAdr==0 )
    {
        if((mem[0x812]==0x78) && (mem[0x813]==0xe6) &&
           (*(unsigned int*)(mem+0x814)==0xBDD2A201) &&
           (*(unsigned int*)(mem+0x818)==0xF99D0848) &&
           (*(unsigned int*)(mem+0x81c)==0xB073E000) &&
           (*(unsigned int*)(mem+0x8b9)==0xa0033420) )
        {
            Unp->DepAdr=0x100;
            if(Unp->info->run == -1)
                Unp->Forced=0x812;
            Unp->RetAdr=mem[0x947]|mem[0x948]<<8;
            Unp->EndAdr=0x2d;
            Unp->StrMem=0x0801;
            PrintInfo(Unp,_I_TC33AD );
            Unp->IdFlag=1;return;
        }
    }
    /* TimeCruncher 3/PC */
    if( Unp->DepAdr==0 )
    {
        if((mem[0x810]==0x78) && (mem[0x813]==0x85) &&
           (*(unsigned int*)(mem+0x814)==0xBD00A201) &&
           (*(unsigned int*)(mem+0x818)==0x349D0920) &&
           (*(unsigned int*)(mem+0x81c)==0x73E0E803) &&
           (*(unsigned int*)(mem+0x8bf)==0xa0033420) )
        {
            Unp->DepAdr=0x100;
            if(Unp->info->run == -1)
                Unp->Forced=0x810;
            Unp->RetAdr=mem[0x94c]|mem[0x94d]<<8;
            Unp->EndAdr=0x2d;
            Unp->StrMem=0x0801;
            PrintInfo(Unp,_I_TC3PC );
            Unp->IdFlag=1;return;
        }
    }
    /* TimeCruncher 4.2/Triad */
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x81a)==0x00A201E6) &&
            (*(unsigned int*)(mem+0x81e)==0x9D083CBD) &&
            (*(unsigned int*)(mem+0x837)==0xAD4C2E85) &&
            (*(unsigned int*)(mem+0x846)==0x0377204C) &&
            (*(unsigned int*)(mem+0x95c)==0x033C4C68) )
        {
            Unp->DepAdr=0x3ad;
            if( Unp->info->run == -1 )
                Unp->Forced=0x81a;
            Unp->RetAdr=mem[0x96f]|mem[0x970]<<8;
            Unp->EndAdr=mem[0x832]|mem[0x836]<<8;
            Unp->StrMem=0x801;
            PrintInfo(Unp,_I_TC423AD);
            Unp->IdFlag=1;return;
        }
    }
    /*TimeCruncher 4.2 generic hack */
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned short int*)(mem+0x82e)==0xAD4C) &&
            (*(unsigned int*)(mem+0x875)==0xF785FEA5) &&
            (*(unsigned int*)(mem+0x8c3)==0x2001004C) &&
            (*(unsigned int*)(mem+0x9B4)==0x01004C02) )
        {
            Unp->DepAdr=mem[0x82f]|mem[0x830]<<8;
            if( Unp->info->run == -1 )
            {
                for(q=0x810;q<0x820;q++)
                {
                    if( *(unsigned int*)(mem+q)==0x8600A278 )
                    {
                        Unp->Forced=q;
                        break;
                    }
                    if( *(unsigned int*)(mem+q)==0x31BD0186 )
                    {
                        Unp->Forced=q;
                        break;
                    }
                }
            }
            for(q=0x95f;q<0x964;q++)
            {
                if(mem[q]==0x4c)
                {
                    Unp->RetAdr=mem[q+1]|mem[q+2]<<8;
                    break;
                }
            }
            Unp->EndAdr=mem[0x833]|mem[0x834]<<8;
            Unp->StrMem=0x801;
            PrintInfo(Unp,_I_TC42GEN);
            Unp->IdFlag=1;return;
        }
    }
    /*TimeCruncher 6/different hacks
      almost identical to TimeCruncher 6 henk/htl but different preamble
    */
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x844)==0x990958B9) &&
            (*(unsigned int*)(mem+0x848)==0xD0C807E8) &&
            (*(unsigned int*)(mem+0x84c)==0x0102EEF7) &&
            (*(unsigned int*)(mem+0x8c1)==0x033420E8) )
        {
            Unp->DepAdr=0x100;
            Unp->fStrAf=0xfc;
            Unp->StrAdC=0xffff;
            Unp->RetAdr=mem[0x91e]|mem[0x91f]<<8;
            Unp->EndAdr=mem[0x840]|mem[0x841]<<8;
            if((mem[0x813]==0x78) && (mem[0x91d]==0xee) &&
               (*(unsigned int*)(mem+0x819)==0xF899083C))
            {
                Unp->Forced=0x813;
                if(*(unsigned int*)(mem+0x918)==0x35D001C6)
                {
                   Unp->RetAdr=mem[0x953]|mem[0x954]<<8;
                   if(Unp->RetAdr==0xa659)
                       Unp->RetAdr=mem[0x956]|mem[0x957]<<8;
                }
                else if(mem[0x091A]==0x4c)
                {
                    Unp->RetAdr=mem[0x91b]|mem[0x91c]<<8;
                }
                PrintInfo(Unp,_I_TC3TDF );
                Unp->IdFlag=1;return;
            }
            else if((mem[0x810]==0x78) &&
               (*(unsigned int*)(mem+0x820)==0xF899083C))
            {
                Unp->Forced=0x810;
                PrintInfo(Unp,_I_TC3ATC );
                Unp->IdFlag=1;return;
            }
            else if((mem[0x812]==0x78) &&
               (*(unsigned int*)(mem+0x824)==0xF899083C))
            {
                Unp->Forced=0x812;
                PrintInfo(Unp,_I_TC3F4CG);
                Unp->IdFlag=1;return;
            }
            else if((mem[0x80e]==0xe6) &&
               (*(unsigned int*)(mem+0x820)==0xF899083C))
            {
                Unp->Forced=0x80e;
                PrintInfo(Unp,_I_TC3HSCG);
                Unp->IdFlag=1;return;
            }
            else if((mem[0x819]==0xe6) &&
               (*(unsigned int*)(mem+0x824)==0xF899083C))
            {
                Unp->Forced=0x819;
                PrintInfo(Unp,_I_TC3HSFE);
                Unp->IdFlag=1;return;
            }
            else if((mem[0x80d]==0x78) &&
               (*(unsigned int*)(mem+0x811)==0xF899083C))
            {
                Unp->Forced=0x80d;
                PrintInfo(Unp,_I_TC3TTN );
                Unp->IdFlag=1;return;
            }
            else
            {
                PrintInfo(Unp,_I_TC3U   );
                if(Unp->RetAdr<Unp->DepAdr)
                {   // dirty workaround, found ONE single case like this
                    // retaddr=$00f0 and it contains just JSR $A660+JMP $A7AE
                    Unp->RetAdr=0xa7ae;
                }
                Unp->IdFlag=1;return;
            }
        }
    }
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x844)==0x990976B9) &&
            (*(unsigned int*)(mem+0x848)==0xD0C807E8) &&
            (*(unsigned int*)(mem+0x831)==0x01004CED) &&
            (*(unsigned int*)(mem+0x8c1)==0x08F00334) )
        {
            Unp->DepAdr=0x100;
            if( Unp->info->run == -1 )
            {
                if(mem[0x818]==0x78)
                    Unp->Forced=0x818;
            }
            Unp->RetAdr=mem[0x974]|mem[0x975]<<8;
            Unp->EndAdr=mem[0x840]|mem[0x841]<<8;
            PrintInfo(Unp,_I_TC3MULE);
            Unp->IdFlag=1;return;
        }
    }
    /* time 3.3 2mhz/galleon */
    if( Unp->DepAdr==0 )
    {
        if( (mem[0x80b]==0xa0) && (mem[0x80c]==0x00) &&
            (*(unsigned int*)(mem+0x810)==0x990829B9) &&
            (*(unsigned int*)(mem+0x817)==0x339908EA) &&
            (*(unsigned int*)(mem+0x825)==0x004C2E85) &&
            (*(unsigned int*)(mem+0x8ae)==0x08F00334) )
        {
            Unp->DepAdr=0x100;
            Unp->Forced=0x80b;
            Unp->RetAdr=mem[0x921]|mem[0x922]<<8;
            if(Unp->RetAdr < 0x800)
                Unp->RtAFrc=1;
            Unp->EndAdr=mem[0x820]|mem[0x824]<<8;
            PrintInfo(Unp,_I_TC3AGILE);
            Unp->IdFlag=1;return;
        }
    }
    /* science451, variable entry and depacker */
    if( Unp->DepAdr==0 )
    {
        if( (mem[0x81e]==0x78) && (mem[0x820]==0x01) &&
            (*(unsigned int*)(mem+0x821)==0x9D084EBD) &&
            (*(unsigned int*)(mem+0x82d)==0xCAF1D0CA) &&
            (*(unsigned int*)(mem+0x831)==0xC600A09A) &&
            (*(unsigned int*)(mem+0x835)==0x083DCEFD) )
        {
            Unp->DepAdr=0x100;
            Unp->Forced=0x81e;
            Unp->RetAdr=mem[0x94d]|mem[0x94e]<<8;
            if(Unp->RetAdr < 0x800)
                Unp->RtAFrc=1;
            Unp->EndAdr=0x2d;
            PrintInfo(Unp,_I_TC3S451);
            Unp->IdFlag=1;return;
        }
    }
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x80b)==0xE67800A0) &&
            (*(unsigned int*)(mem+0x813)==0x9D083CBD) &&
            (*(unsigned int*)(mem+0x817)==0xFBBD00F9) &&
            (*(unsigned int*)(mem+0x81b)==0x04329D08) &&
            (*(unsigned int*)(mem+0x8d1)==0xD0066918) )
        {
            Unp->DepAdr=0x100;
            Unp->Forced=0x80b;
            Unp->RetAdr=mem[0x929]|mem[0x92a]<<8;
            if(Unp->RetAdr < 0x800)
                Unp->RtAFrc=1;
            Unp->EndAdr=0x2d;
            PrintInfo(Unp,_I_TC3S451V2);
            Unp->IdFlag=1;return;
        }
    }
    /* Ikari, hack of s451 variant */
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x817)==0xE678FFA2) &&
            (*(unsigned int*)(mem+0x81c)==0x9D084EBD) &&
            (*(unsigned int*)(mem+0x82d)==0xCAecD0CA) &&
            (*(unsigned int*)(mem+0x831)==0xC600A09A) &&
            (*(unsigned int*)(mem+0x835)==0x083DCEFD) )
        {
            Unp->DepAdr=0x100;
            Unp->Forced=0x817;
            Unp->RetAdr=mem[0x94d]|mem[0x94e]<<8;
            if(Unp->RetAdr < 0x800)
                Unp->RtAFrc=1;
            Unp->EndAdr=0x2d;
            PrintInfo(Unp,_I_TC3IKARI);
            Unp->IdFlag=1;return;
        }
    }
}
