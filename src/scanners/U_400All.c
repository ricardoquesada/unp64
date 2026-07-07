/* Unknown $0400 all mem packer?
   found few times but seems that only supports $0800-ffff packing
   so all this shouldn't be even needed =)
*/
#include "../unp64.h"
void Scn_U_400All(unpstr *Unp)
{
    unsigned char *mem;

    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    /* PSQ-Linker v3, type 1 $0800-$ffff */
    if( Unp->DepAdr==0 )
    {
        if((mem[0x80d]==0x78) &&
           (*(unsigned int*)(mem+0x811)==0x01852FA9) &&
           (*(unsigned int*)(mem+0x82d)==0xFE85FFA9) &&
           (*(unsigned int*)(mem+0x8a0)==0x4A4A4A4A) &&
           (*(unsigned int*)(mem+0x934)==0x01394CF8) )
        {
            Unp->DepAdr=0x10f;
            if(Unp->info->run == -1 )
                Unp->Forced=0x80d;
            Unp->fStrAf=0xfe;
            Unp->RetAdr=mem[0x895]|mem[0x896]<<8;
            Unp->fEndBf=0xfe;
            PrintInfo(Unp,_I_PSQLINK1);
            Unp->IdFlag=1;return;
        }
    } 
    /* another $400 packer found in a couple of entropy noters */
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x81e)==0x2BBD99A2) &&
           (*(unsigned int*)(mem+0x822)==0x03FF9D08) &&
           (*(unsigned int*)(mem+0x89d)==0xD004A9FE) &&
           (*(unsigned int*)(mem+0x8ad)==0x1801A9FE) )
        {
            Unp->DepAdr=0x400;
            if(Unp->info->run == -1 )
                Unp->Forced=0x81e;
            Unp->StrMem=mem[0x86d]|mem[0x871]<<8;
            Unp->RetAdr=mem[0x8c3]|mem[0x8c4]<<8;
            Unp->EndAdr=0xfd;
            PrintInfo(Unp,_I_ENTROPYPK);
            Unp->IdFlag=1;return;
        }
    }
    /* another $400 packer, apparently by Thundercats */
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x816)==0x9D0826BD) &&
           (*(unsigned int*)(mem+0x81e)==0x8534A9F7) &&
           (*(unsigned int*)(mem+0x822)==0x04004C01) &&
           (*(unsigned int*)(mem+0x8c1)==0x04384CFA) )
        {
            Unp->DepAdr=0x400;
            if(Unp->info->run == -1 )
                Unp->Forced=0x816;
            Unp->StrMem=mem[0x857]|mem[0x859]<<8;
            Unp->RetAdr=mem[0x8d9]|mem[0x8da]<<8;
            //Unp->EndAdr=0x04; // no use, always ends at $ffff
            PrintInfo(Unp,_I_THUNCATSPK);
            Unp->IdFlag=1;return;
        }
    }
    /* another $400 packer, apparently by United Artists */
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x811)==0x2AB900A0) &&
           (*(unsigned int*)(mem+0x815)==0x04009908) &&
           (*(unsigned int*)(mem+0x871)==0x04812013) &&
           (*(unsigned int*)(mem+0x890)==0xB028AF85) )
        {
            Unp->DepAdr=0x400;
            if(Unp->info->run == -1 )
                Unp->Forced=0x811;
            Unp->StrMem=mem[0x8a0]|mem[0x8a1]<<8;
            Unp->RetAdr=mem[0x896]|mem[0x897]<<8;
            if(Unp->RetAdr==0xffff)
            {
                mem[0x895]=0x2c;
                Unp->RetAdr=mem[0x899]|mem[0x89a]<<8;
                if(Unp->RetAdr==0xa659)
                {
                    mem[0x898]=0x2c;
                    Unp->RetAdr=mem[0x89c]|mem[0x89d]<<8;
                }
            }
            Unp->EndAdr=0xae;
            PrintInfo(Unp,_I_UAPACK);
            Unp->IdFlag=1;return;
        }
    }
}
