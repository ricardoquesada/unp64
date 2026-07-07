/* Excalibur 666/Syndacate packer&coder */
#include "../unp64.h"
void Scn_Excalibur(unpstr *Unp)
{
    unsigned char *mem;

    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x817)==0xBD00A278) &&
           (*(unsigned int*)(mem+0x81b)==0x009D0828) &&
           (*(unsigned int*)(mem+0x88f)==0x45200132) &&
           (*(unsigned int*)(mem+0x893)==0x45204801) )
        {
            Unp->DepAdr=0x100;
            if(Unp->info->run == -1)
                Unp->Forced=0x817;
            Unp->StrMem=mem[0x853]|mem[0x857]<<8;
            Unp->RetAdr=mem[0x8b0]|mem[0x8b1]<<8;
            Unp->EndAdr=0xae;
            PrintInfo(Unp,_I_EXCPACK);
            Unp->IdFlag=1;return;
        }
    }
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x817)==0xA0FFA278) &&
           (*(unsigned int*)(mem+0x81b)==0x84018400) &&
           (*(unsigned int*)(mem+0x88f)==0x2068AA08) &&
           (*(unsigned int*)(mem+0x893)==0x284C0146) )
        {
            Unp->DepAdr=0x177;
            if(Unp->info->run == -1)
                Unp->Forced=0x817;
            Unp->StrMem=mem[0x850]|mem[0x854]<<8;
            Unp->RetAdr=mem[0x8a3]|mem[0x8a4]<<8;
            Unp->EndAdr=0xae;
            PrintInfo(Unp,_I_EXCCOD);
            Unp->IdFlag=1;return;
        }
    }
    /*Change-protector 2.0, probably unrelated by always by Syndacate */
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x836)==0x000A004C) &&
           (*(unsigned int*)(mem+0x83a)==0x34A97800) &&
           (*(unsigned int*)(mem+0xa00)==0xA208A020) &&
           (*(unsigned int*)(mem+0xa33)==0xD0C80A39) )
        {
            Unp->DepAdr=0x700;
            if(Unp->info->run == -1)
                Unp->Forced=0xa00;
            Unp->StrMem=mem[0x8da]|mem[0x8de]<<8;
            Unp->RetAdr=mem[0x8fb]|mem[0x8fc]<<8;
            Unp->EndAdr=Unp->info->end-(mem[0x8d2]|mem[0x8d6]<<8)+Unp->StrMem;
            PrintInfo(Unp,_I_CHGPROT2);
            Unp->IdFlag=1;return;
        }
    }

}
