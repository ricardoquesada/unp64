/* Allstars Coder */
#include "../unp64.h"
void Scn_ALScoder(unpstr *Unp)
{
    unsigned char *mem;
    int q,p;
    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x828)==0x34BD00A2) &&
          ((*(unsigned int*)(mem+0x82c)&0xff00ffff)==0x9D004908) &&
           (*(unsigned int*)(mem+0x830)==0xD0E80834) )
        {
            q=mem[0x82e];
            if(((mem[0x83e]^q) == 0x49) &&
               ((mem[0x845]^q) == 0xF6) &&
               ((mem[0x846]^q) == 0x4C) &&
               ((mem[0x847]^q) == 0x48) &&
               ((mem[0x848]^q) == 0x04) )
            {
                p=mem[0x83f];
                p<<=8;
                p|=mem[0x83f];
                p<<=8;
                p|=mem[0x83f];
                p<<=8;
                p|=mem[0x83f];
                Unp->DepAdr=0x448;
                Unp->Forced=0x828;
                if((*(unsigned int*)(mem+0x87a)^p)==0x4CA65920)
                {
                    mem[0x87a]=0x2c^(p&0xff);
                }
                Unp->RetAdr=(mem[0x87e]|mem[0x87f]<<8)^(p&0xffff);
                Unp->EndAdr=Unp->info->end - 0xfe;
                Unp->StrMem=0x801;
                PrintInfo(Unp,_I_ALSCODER);
                Unp->IdFlag=1;return;
            }
        }
    }
}
