/* Charblaster */
#include "../unp64.h"
void Scn_Polonus(unpstr *Unp)
{
    unsigned char *mem;

    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x80b)==0xBE7800A0) &&
            (*(unsigned int*)(mem+0x80f)==0x81960782) &&
            (*(unsigned int*)(mem+0x817)==0x21A50024) &&
            (*(unsigned int*)(mem+0x837)==0xC9001820) )
        {
            Unp->Forced=0x80b;
            Unp->DepAdr=0x024;
            Unp->RetAdr=mem[0x84d]|mem[0x84e]<<8;
            Unp->EndAdr=mem[0x82e]|mem[0x82f]<<8;Unp->EndAdr+=mem[0x802];
            Unp->fStrAf=0x2d;
            Unp->StrAdC=0xffff|EA_USE_X;
            PrintInfo(Unp,_I_POLONCB);
            Unp->IdFlag=1;return;
        }
    }
    /* Krejzi/Polonus */
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x815)==0xBC5EA278) &&
           (*(unsigned int*)(mem+0x819)==0x01940823) &&
           (*(unsigned int*)(mem+0x81d)==0xE8F810CA) &&
           (*(unsigned int*)(mem+0x86e)==0x154C13B1) )
        {
            Unp->DepAdr=0x2;
            Unp->Forced=0x816;
            Unp->RetAdr=mem[0x87c]|mem[0x87d]<<8;
            Unp->EndAdr=mem[0x83b]|mem[0x83c]<<8;Unp->EndAdr+=0x100;
            Unp->StrMem=mem[0x828]|mem[0x829]<<8;Unp->StrMem+=2;
            PrintInfo(Unp,_I_POLONKR);
            Unp->IdFlag=1;return;
        }
    }
    /* Amigapacker/Polonus */
    if( Unp->DepAdr==0 )
    {
        if(((*(unsigned int*)(mem+0x823)&0x00ffffff)==0x007880A0) &&
           (*(unsigned int*)(mem+0x82b)==0x38B90185) &&
           (*(unsigned int*)(mem+0x861)==0x2E862D85) &&
           (*(unsigned int*)(mem+0x881)==0xD00394AD) )
        {
            Unp->DepAdr=0x340;
            Unp->Forced=0x823;
            Unp->RetAdr=mem[0x867]|mem[0x868]<<8;
            if(*(unsigned int*)(mem+0x866)==0x4CA65920)
            {
                mem[0x866]=0x2c;
                Unp->RetAdr=mem[0x86a]|mem[0x86b]<<8;
            }
            if(*(unsigned int*)(mem+0x85a)==0xA9E51820)
            {
                mem[0x85a]=0x2c;
            }
            else if(mem[0x85a]==0x4c) // weird hack but possible
            {
                Unp->RetAdr=mem[0x85b]|mem[0x85c]<<8;
            }
            //Unp->EndAdr=0x2d; // not always gets set
            Unp->EndAdr=mem[0x872]|mem[0x873]<<8;Unp->EndAdr+=0x100;
            Unp->fStrAf=0x0379;
            Unp->StrAdC=EA_ADDFF|EA_USE_Y|0xffff;
            PrintInfo(Unp,_I_POLONAM);
            Unp->IdFlag=1;return;
        }
    }
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x826)==0x8536A978) &&
           (*(unsigned int*)(mem+0x835)==0x04074CF7) &&
           (*(unsigned int*)(mem+0x8A5)==0x5CAD045B) &&
           (*(unsigned int*)(mem+0x8B5)==0x0458CE03) )
        {
            Unp->DepAdr=0x407;
            Unp->Forced=0x826;
            Unp->RetAdr=mem[0x8ce]|mem[0x8cf]<<8;
            Unp->EndAdr=0x2d;
            //Unp->StrMem=0x0801;
            PrintInfo(Unp,_I_POLONEQ);
            Unp->IdFlag=1;return;
        }
    }
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x812)==0x00BD1DA2) &&
           (*(unsigned int*)(mem+0x816)==0x04009D08) &&
           (*(unsigned int*)(mem+0x81a)==0x4CF7D0E8) &&
           (*(unsigned int*)(mem+0x81e)==0x00A9045C) &&
           (*(unsigned int*)(mem+0x8f2)==0x0404424C) )
        {
            Unp->DepAdr=0x45c;
            Unp->Forced=0x812;
            Unp->RetAdr=mem[0x8db]|mem[0x8dc]<<8;
            Unp->EndAdr=0x2d;
            //Unp->StrMem=0x0801;
            PrintInfo(Unp,_I_POLON4P);
            Unp->IdFlag=1;return;
        }
    }
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x810)==0x76A20185) &&
           (*(unsigned int*)(mem+0x814)==0x9D0821BD) &&
           (*(unsigned int*)(mem+0x81c)==0x01014CF7) &&
           (*(unsigned int*)(mem+0x870)==0x011B4CF6) )
        {
            Unp->DepAdr=0x101;
            if(Unp->info->run == -1)
               Unp->Forced=0x80d;
            Unp->RetAdr=mem[0x893]|mem[0x894]<<8;
            Unp->EndAdr=mem[0x821]|mem[0x822]<<8;Unp->EndAdr+=0x100;
            Unp->fStrAf=0xfb;
            Unp->StrAdC=EA_ADDFF|EA_USE_Y;
            PrintInfo(Unp,_I_POLON101);
            Unp->IdFlag=1;return;
        }
    }
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x81d)==0x47BD11A2) &&
           (*(unsigned int*)(mem+0x82d)==0x47BD11A2) &&
           (*(unsigned int*)(mem+0x844)==0x08594CFA) &&
           (*(unsigned int*)(mem+0x890)==0xCF03404C) )
        {
            Unp->DepAdr=0x340;
            if(Unp->info->run == -1)
               Unp->Forced=0x81d;
            Unp->RetAdr=mem[0x902]|mem[0x911]<<8;
            Unp->EndAdr=Unp->info->end-0x150;
            PrintInfo(Unp,_I_QRTPROT);
            Unp->IdFlag=1;return;
        }
    }
}
