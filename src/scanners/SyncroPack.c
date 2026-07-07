/* Syncro packers */
#include "../unp64.h"
void Scn_SyncroPack(unpstr *Unp)
{
    unsigned char *mem;
    int p;
    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    /* Syncro Packer 1.3 */
    if( Unp->DepAdr==0 )
    {
        for(p=0x800;p<0x80c;p+=0x0a)
        {
            if(((*(unsigned int*)(mem+p+0x07)==0x1fBD83A2) ||
                (*(unsigned int*)(mem+p+0x07)==0x15BD86A2)) &&
                (*(unsigned int*)(mem+p+0x13)==0xA200094C) &&
                (*(unsigned int*)(mem+p+0x6a)==0x00144C15) &&
               ((*(unsigned int*)(mem+p+0x94)==0x564CEDD0) ||
                (*(unsigned int*)(mem+p+0x97)==0x564CEDD0) )
              )
            {
                Unp->Forced=p+0x07; /* at 801 there's only screen blank */
                Unp->DepAdr=0x009;
                Unp->EndAdr=mem[p+0x2d]|mem[p+0x2e]<<8;Unp->EndAdr++;
                Unp->fStrAf=0x20;
                Unp->StrAdC=EA_USE_Y;
                if((mem[p+0x73]==0x20)&&
                   (mem[p+0x74]==0xbf)&&
                   (mem[p+0x75]==0xe3)&&
                   (mem[p+0x77]==0x4c) )
                {
                    mem[p+0x73]=0x2c; /* jsr $e3bf */
                    Unp->RetAdr=mem[p+0x78]|mem[p+0x79]<<8;
                }
                else if(mem[p+0x74]==0x4c)
                    Unp->RetAdr=mem[p+0x75]|mem[p+0x76]<<8;
                PrintInfo(Unp,_I_SYNCRO13);
                Unp->IdFlag=1;return;
            }
        }
    }
    /* Syncro Packer 1.4 */
    if( Unp->DepAdr==0 )
    {
        for(p=0x800;p<0x80c;p+=0x0a)
        {
            if( (*(unsigned int*)(mem+p+0x07)==0x1fBD88A2) &&
                (*(unsigned int*)(mem+p+0x13)==0xA200094C) &&
                (*(unsigned int*)(mem+p+0x6a)==0x00144C15) &&
                (*(unsigned int*)(mem+p+0x99)==0x564CEDD0)
              )
            {
                Unp->Forced=p+0x07; /* at 801 there's only screen blank */
                Unp->DepAdr=0x009;
                Unp->EndAdr=mem[p+0x2d]|mem[p+0x2e]<<8;Unp->EndAdr++;
                Unp->fStrAf=0x20;
                Unp->StrAdC=EA_USE_Y;
                if((mem[p+0x75]==0x20)&&
                   (mem[p+0x76]==0xbf)&&
                   (mem[p+0x77]==0xe3)&&
                   (mem[p+0x79]==0x4c) )
                {
                    mem[p+0x75]=0x2c; /* jsr $e3bf */
                    Unp->RetAdr=mem[p+0x7a]|mem[p+0x7b]<<8;
                }
                PrintInfo(Unp,_I_SYNCRO14);
                Unp->IdFlag=1;return;
            }
        }
    }
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x801)==0x86A200A0) &&
            (*(unsigned int*)(mem+0x809)==0x950815BD) &&
            (*(unsigned int*)(mem+0x86a)==0x00144C15) &&
            (*(unsigned int*)(mem+0x897)==0x564CEDD0) )
        {
            Unp->Forced=0x801;
            Unp->DepAdr=0x009;
            Unp->RetAdr=mem[0x878]|mem[0x879]<<8;
            Unp->EndAdr=mem[0x82d]|mem[0x82e]<<8;Unp->EndAdr++;
            Unp->fStrAf=0x20;
            Unp->StrAdC=EA_USE_Y;
            mem[0x873]=0x2c; /* jsr $e3bf */
            PrintInfo(Unp,_I_SYNCRO155);
            Unp->IdFlag=1;return;
        }
    }
    /* slightly different, with sysline */
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x80e)==0x1CBD88A2) &&
            (*(unsigned int*)(mem+0x81a)==0xA200094C) &&
            (*(unsigned int*)(mem+0x85f)==0x144C0075) &&
            (*(unsigned int*)(mem+0x88b)==0x16C602D0) )
        {
            Unp->Forced=0x80e;
            Unp->DepAdr=0x009;
            if(mem[0x869]==0x20||mem[0x869]==0x4c)
            {
                Unp->RetAdr=mem[0x86a]|mem[0x86b]<<8;
                if((mem[0x869]==0x20) &&
                   (Unp->RetAdr==0xff81||Unp->RetAdr==0xe3bf))
                {
                    mem[0x869]=0x2c;
                    Unp->RetAdr=mem[0x86d]|mem[0x86e]<<8;
                }
            }

            Unp->EndAdr=mem[0x834]|mem[0x835]<<8;Unp->EndAdr++;
            Unp->fStrAf=0x20;
            Unp->StrAdC=EA_USE_Y;
            PrintInfo(Unp,_I_SYNCRO12);
            Unp->IdFlag=1;return;
        }
    }
    /* TLR packer */
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x81b)==0x8534A978) &&
            (*(unsigned int*)(mem+0x823)==0x349D086F) &&
            (*(unsigned int*)(mem+0x827)==0x9AE0E803) &&
            (*(unsigned int*)(mem+0x8ab)==0xAA037A4C) )
        {
            Unp->Forced=0x81b;
            Unp->DepAdr=0x360;
            Unp->RetAdr=mem[0x8e7]|mem[0x8e8]<<8;
            Unp->StrMem=mem[0x865]|mem[0x867]<<8;
            Unp->EndAdr=0x2d;
            PrintInfo(Unp,_I_TLRPACK);
            Unp->IdFlag=1;return;
        }
    }
    /* TLR prot 1 */
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x81b)==0x00BD29A2) &&
            (*(unsigned int*)(mem+0x81f)==0x9DEA4908) &&
            (*(unsigned int*)(mem+0x823)==0xE0E80800) &&
            (*(unsigned int*)(mem+0x84c)==0x0A114C1B) )
        {
            Unp->Forced=0x81b;
            Unp->DepAdr=0x334;
            Unp->RetAdr=0xa7ae;
            Unp->StrMem=0x0801;
            Unp->EndAdr=Unp->info->end-0xa0;
            PrintInfo(Unp,_I_TLRPROT1);
            Unp->IdFlag=1;return;
        }
    }
    /* TLR prot 2 */
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x81b)==0x27BD00A2) &&
            (*(unsigned int*)(mem+0x81f)==0x9D854908) &&
            (*(unsigned int*)(mem+0x823)==0xD0E80827) &&
            (*(unsigned int*)(mem+0x87f)==0x1CBBADBC) )
        {
            Unp->Forced=0x81b;
            Unp->DepAdr=0x334;
            Unp->RetAdr=0xa7ae;
            Unp->StrMem=0x0801;
            Unp->EndAdr=0x2d;
            PrintInfo(Unp,_I_TLRPROT2);
            Unp->IdFlag=1;return;
        }
    }
    /*BF packer*/
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x810)==0xBD52A278) &&
            (*(unsigned int*)(mem+0x814)==0xFF9D082A) &&
            (*(unsigned int*)(mem+0x828)==0xBD04004C) &&
            (*(unsigned int*)(mem+0x868)==0x04F00443) )
        {
            Unp->Forced=0x810;
            Unp->DepAdr=0x400;
            Unp->RetAdr=mem[0x878]|mem[0x879]<<8;
            Unp->StrMem=mem[0x855]|mem[0x856]<<8;Unp->StrMem+=mem[0x827];
            Unp->EndAdr=mem[0x81f]|mem[0x821]<<8;
            PrintInfo(Unp,_I_BFPACK);
            Unp->IdFlag=1;return;
        }
    }

}
