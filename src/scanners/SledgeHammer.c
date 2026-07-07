/* SledgeHammer & variants */
#include "../unp64.h"
void Scn_SledgeHammer(unpstr *Unp)
{
    unsigned char *mem;
    int q,p;
    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x816)==0x05A00185) &&
            (*(unsigned int*)(mem+0x81a)==0x9608EABE) &&
            (*(unsigned int*)(mem+0x889)==0xB104434C) &&
           ((*(unsigned int*)(mem+0x8cb)&0xff0000ff)==0xe600004c) )
        {
            Unp->EndAdr=0x2d;
            Unp->DepAdr=0x400;
            Unp->Forced=0x816;
            Unp->StrMem=mem[0x8ea]|mem[0x8eb]<<8;
            Unp->RetAdr=mem[0x8cc]|mem[0x8cd]<<8;
            PrintInfo(Unp, _I_SLEDGE10);
            Unp->IdFlag=1;return;
        }
        if( (*(unsigned int*)(mem+0x816)==0x05A00185) &&
            (*(unsigned int*)(mem+0x8C2)==0xAF86AE85) &&
           ((*(unsigned int*)(mem+0x889)&0xff00ffff)==0xB100434C) &&
           ((*(unsigned int*)(mem+0x8c8)&0xff00ffff)==0x4C000185) &&
            mem[0x80d]==0x78)
        {
            Unp->EndAdr=0x2d;
            Unp->DepAdr=mem[0x82e]|mem[0x82f]<<8;
            Unp->Forced=0x80d;
            Unp->StrMem=mem[0x8ea]|mem[0x8eb]<<8;
            Unp->RetAdr=mem[0x8cc]|mem[0x8cd]<<8;
            PrintInfo(Unp, _I_SLEDGE11);
            Unp->IdFlag=1;return;
        }
        /* Dream Packer V2/Aspect, SH1.0 hacked */
        if( (*(unsigned int*)(mem+0x812)==0x8500A978) &&
            (*(unsigned int*)(mem+0x8C2)==0xAF86AE85) &&
           ((*(unsigned int*)(mem+0x889)&0xff00ffff)==0xB100834C) &&
           ((*(unsigned int*)(mem+0x8c8)&0xff00ffff)==0x4C000185) )
        {
            Unp->EndAdr=0x2d;
            Unp->DepAdr=mem[0x82e]|mem[0x82f]<<8;
            Unp->Forced=0x812;
            Unp->StrMem=mem[0x8ea]|mem[0x8eb]<<8;
            Unp->RetAdr=mem[0x8cc]|mem[0x8cd]<<8;
            PrintInfo(Unp, _I_SLEDGE1DP);
            Unp->IdFlag=1;return;
        }
    }
    /* Sledge v1+/v1.2 */
    if( Unp->DepAdr==0 )
    {
        if(((*(unsigned int*)(mem+0x810)&0x00ffffff)==0x0000A978) &&
            (*(unsigned int*)(mem+0x894)            ==0xB1044e4C) &&
           ((*(unsigned int*)(mem+0x8d3)&0xff00ffff)==0x4C000185) )
        {
            Unp->EndAdr=0x2d;
            Unp->DepAdr=0x400;
            Unp->Forced=0x810;
            Unp->StrMem=mem[0x8ea]|mem[0x8eb]<<8;
            Unp->RetAdr=mem[0x8d7]|mem[0x8d8]<<8;
            PrintInfo(Unp, _I_SLEDGE12);
            Unp->IdFlag=1;return;
        }
    }
    /* Kreator Packer (altered Sledgehammer v1.0)
       found in some Crime demos
    */
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x815)==0xA001E678) &&
           (*(unsigned int*)(mem+0x819)==0x08EABE05) &&
           (*(unsigned int*)(mem+0x8a0)==0x01AC208B) &&
           (*(unsigned int*)(mem+0x8a4)==0x20AA31B1) )
        {
            Unp->DepAdr=0x100;
            Unp->Forced=0x815;
            Unp->fEndAf=0x2d;
            Unp->EndAdC=0xffff;
            Unp->StrMem=mem[0x8ea]|mem[0x8eb]<<8;
            Unp->RetAdr=mem[0x8cc]|mem[0x8cd]<<8;
            PrintInfo(Unp,_I_KREATOR);
            Unp->IdFlag=1;return;
        }
    }
    /* Sledge II ($040b & $020b variants) */
    if( Unp->DepAdr==0 )
    {
        if((mem[0x80d]==0x78) && (mem[0x87d]==0x4c) &&
           (*(unsigned int*)(mem+0x810)==0x018478A0) &&
           (*(unsigned int*)(mem+0x814)==0x990831B9) &&
           (*(unsigned int*)(mem+0x82c)==0x4CEED0CA) )
        {
            Unp->EndAdr=0x2d;
            Unp->DepAdr=mem[0x830]|mem[0x831]<<8; /* $40b, $20b, $33b */
            Unp->Forced=0x80d;
            Unp->RetAdr=mem[0x87e]|mem[0x87f]<<8;
            if((mem[0x831]==0x02)&&(mem[0x832]==0x8d))
                q=0x833;
            else
                q=0x859;
            Unp->StrMem=mem[q]|mem[q+1]<<8; // always $07e8...
            Unp->StrMem=desledge( 0x88c, 0x843, Unp->StrMem, mem );
            PrintInfo(Unp, _I_SLEDGE20);
            Unp->IdFlag=1;return;
        }
    }
    /* Sledge 2.1+ */
    if( Unp->DepAdr==0 )
    {
        q=Unp->info->start&0xff00;
        if((mem[q+0x0e]==0xa2) &&
           (*(unsigned int*)(mem+q+0x10)==0x018478A0) &&
           (*(unsigned int*)(mem+q+0x14)==(0x990031B9+(q<<8))) &&
           (*(unsigned int*)(mem+q+0x2e)==0x01004CEE) &&
           (*(unsigned int*)(mem+q+0x4a)==0x8D014320) )
        {
            //Unp->EndAdr=0x2d;
            Unp->fEndAf=0x11c;
            Unp->DepAdr=0x100;
            Unp->Forced=q+0x0e;
            if(mem[q+0x72]==0x4c)
                Unp->RetAdr=mem[q+0x73]|mem[q+0x74]<<8;
            else
            {
                /* hacks have it anywhere here */
                for(p=q+0x68;p<=q+0x72;p++)
                {
                    if(mem[p]==0x4c)
                    {
                        Unp->RetAdr=mem[p+1]|mem[p+2]<<8;
                        break;
                    }
                }
            }
            Unp->StrMem=mem[q+0x4e]|mem[q+0x4f]<<8; // always $07e8...
            //p=0x881; // not fixed, must be calced, some are at $88c
            p=mem[q+0x1e]|mem[q+0x1f]<<8;
            p-=((mem[q+0x21]|mem[q+0x22]<<8)-(mem[q+0x76]|mem[q+0x77]<<8));
            Unp->StrMem=desledge( p, q+0x38, Unp->StrMem, mem );
            PrintInfo(Unp, _I_SLEDGE21);
            Unp->IdFlag=1;return;
        }
    }
    /* Sledge II+ */
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x80d)==0x8D00A978) &&
           (*(unsigned int*)(mem+0x84b)==0x46CEF7D0) &&
           (*(unsigned int*)(mem+0x855)==0x050B4CEE) )
        {
            Unp->EndAdr=0x2d;
            Unp->DepAdr=0x50b;
            Unp->Forced=0x80d;
            Unp->RetAdr=mem[0x8a5]|mem[0x8a6]<<8;
            Unp->StrMem=mem[0x880]|mem[0x881]<<8;
            Unp->StrMem=desledge( 0x8e2, 0x86a, Unp->StrMem, mem );
            PrintInfo(Unp, _I_SLEDGE23);
            if(Unp->DebugP)
                if((*(unsigned int*)(mem+0x81d)==0x08BABD27) )
                    printmsg(mem,0x8ba,40);
            Unp->IdFlag=1;return;
        }
    }
    /* Sledge II+ very similar but code moved around */
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x81b)==0x52BD00A2) &&
           (*(unsigned int*)(mem+0x844)==0x3FCEF7D0) &&
           (*(unsigned int*)(mem+0x84e)==0x050B4CEE) )
        {
            Unp->EndAdr=0x2d;
            Unp->DepAdr=0x50b;
            if(Unp->info->run==-1)
                Unp->Forced=0x81b;
            Unp->RetAdr=mem[0x8c6]|mem[0x8c7]<<8;
            Unp->StrMem=mem[0x8d5]|mem[0x8d6]<<8;
            Unp->StrMem=desledge( 0x8e8, 0x88b, Unp->StrMem, mem );
            PrintInfo(Unp, _I_SLEDGE24);
            if(Unp->DebugP)
                if((*(unsigned int*)(mem+0x81d)==0x9D0852BD) )
                    printmsg(mem,0x852,40);
            Unp->IdFlag=1;return;
        }
    }
    /* Sledge 2.2/CCS always all mem 07e8-ffff */
    if( Unp->DepAdr==0 )
    {
        if((mem[0x801]==0x78) && (mem[0x802]==0xa0) &&
           (*(unsigned int*)(mem+0x804)==0x018654A2) &&
           (*(unsigned int*)(mem+0x808)==0x950812BD) &&
           (*(unsigned int*)(mem+0x810)==0xBD00024C) &&
           (*(unsigned int*)(mem+0x833)==0xA8004B20))
        {
            Unp->fEndAf=0x2e;
            Unp->DepAdr=0x2;
            Unp->Forced=0x801;
            Unp->RetAdr=mem[0x85a]|mem[0x85b]<<8;
            Unp->StrMem=mem[0x83f]|mem[0x840]<<8;
            Unp->StrMem=desledge( 0x866, 0x829, Unp->StrMem, mem );
            PrintInfo(Unp, _I_SLEDGE2C);
            Unp->IdFlag=1;return;
        }
    }
    /* Sledge 2.2? always all mem 07e8-ffff */
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x80b)==0xA27800A0) &&
           (*(unsigned int*)(mem+0x810)==0x30B90184) &&
           (*(unsigned int*)(mem+0x814)==0x04009908) &&
           (*(unsigned int*)(mem+0x857)==0xCCEFD088))
        {
            Unp->fEndAf=0x41a;
            //end_add=0xffff;
            Unp->DepAdr=0x400;
            Unp->Forced=0x80b;
            Unp->RetAdr=mem[0x865]|mem[0x866]<<8;
            Unp->StrMem=mem[0x84a]|mem[0x84b]<<8; // always $07e8...
            Unp->StrMem=desledge( 0x873, 0x836, Unp->StrMem, mem );
            PrintInfo(Unp, _I_SLEDGE22);
            Unp->IdFlag=1;return;
        }
    }
    /* Sledge v3 */
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x82e)==0x8530A978) &&
           (*(unsigned int*)(mem+0x8a3)==0xC804CFAC) &&
           (*(unsigned int*)(mem+0x875)==0x04284CF1) )
        {
          //  Unp->EndAdr=0xfd; /* not necessarily true */
          //  Unp->DepAdr=0x428;
            Unp->DepAdr=0x443 ;
            Unp->MonEnd=0x00fd<<16|0x00fe;
            Unp->Forced=0x82f;
            Unp->RetAdr=mem[0x8c9]|mem[0x8ca]<<8;
            Unp->StrMem=mem[0x94d]|mem[0x94e]<<8;
            PrintInfo(Unp, _I_SLEDGE30);
            if(Unp->DebugP)
                if((*(unsigned int*)(mem+0x81e)&0x00ffffff)==0x00A927A2 )
                    printmsg(mem,0x87b,40);
            Unp->IdFlag=1;return;
        }
    }
    /* Trap/Bonzai packer, probably derived from SledgeHammer 2.x */
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x812)==0x8478A078) &&
           (*(unsigned int*)(mem+0x816)==0x0836B901) &&
           (*(unsigned int*)(mem+0x81a)==0x8800FF99) &&
           (*(unsigned int*)(mem+0x85a)==0xD00121EE) )
        {
            Unp->DepAdr=0x100;
            Unp->Forced=0x812;
            Unp->StrMem=mem[0x858]|mem[0x859]<<8;
            Unp->StrMem=desledge( 0x87f, 0x83f, Unp->StrMem, mem );
            Unp->RetAdr=mem[0x871]|mem[0x872]<<8;
            Unp->fEndAf=0x121;
            PrintInfo(Unp,_I_SLEDGETRAP);
            Unp->IdFlag=1;return;
        }
    }
    /* UltimateSledgeHammer/Sorex */
    if( Unp->DepAdr==0 )
    {
        /* sysless version found, organism+6/triad */
        for(p=0x0801,q=0;p<=0x080d;p+=0xc)
        {
            if((*(unsigned int*)(mem+0x01+p)==((((p&0x0f)+0x0d)<<24)|0x00BD4DA2)) &&
               (*(unsigned int*)(mem+0x0b+p)==0x3800024C) &&
               (*(unsigned int*)(mem+0x33+p)==0x4420AA00) &&
               (*(unsigned int*)(mem+0x43+p)==0xF1D088F4) )
            {
                q=p;
                break;
            }
        }
        if(q>0)
        {
            Unp->DepAdr=0x0002;
            Unp->Forced=q;
            Unp->StrMem=mem[0x39+q]|mem[0x3a+q]<<8;
            Unp->RetAdr=mem[0x4f+q]|mem[0x50+q]<<8;
            Unp->fEndAf=0x2c;
            PrintInfo(Unp,_I_ULTIM8SH);
            Unp->IdFlag=1;return;
        }
    }
}
/*
Note about Sledge 3
Found a packed program that's a result of a "inside" linking. That's worst than
overlapping.
At first I thought that some bugged SH3 did not sort the load address, but
after tracing it in vicemonitor i've found that SH3 has no error.

2 parts were linked like this
1: $1000-$8711
2: $2000-$5000

as a result, for unp64, the final address in $fd/$fe is $5000, not $8711

If I find the same problem on other SH I'd have to set a monitored pointer
for the Unp->EndAdress. Shouldn't be the case as it seems that older versions set
$2d/2e themselves.
Luckily at least startaddress of all linked parts are already sorted by
SH3, I've made many tests changing order from the selector and even swapping
them phisically on the disk. =)
*/
