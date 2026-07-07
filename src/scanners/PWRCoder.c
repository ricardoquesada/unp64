/* Powerrun coder tries to format drive 8 if sysline is tampered */
#include "../unp64.h"
void Scn_PWRCoder(unpstr *Unp)
{
    unsigned char *mem;
    int p;
    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x81f)==0x2BB900A0) &&
           ((*(unsigned int*)(mem+0x823)&0xff00ffff)==0x99004908) &&
           (*(unsigned int*)(mem+0x827)==0xD0C8082B) )
        {
            p=mem[0x825];
            if(p==mem[0x85a])
            {
                // sysline check always good, make it compare with itself
                mem[0x832]=mem[0x82f] ;
                Unp->Forced=0x81f;
                Unp->DepAdr=(mem[0x852]^p)|(mem[0x853]^p)<<8;
                Unp->StrMem=(mem[0x875]^p)|(mem[0x876]^p)<<8;
                Unp->EndAdr=Unp->info->end-0xd9;
                Unp->RetAdr=(mem[0x89c]^p)|(mem[0x89d]^p)<<8;
                PrintInfo(Unp,_I_PWRCOD);
                Unp->IdFlag=1;return;
            }

        }
    }
}
