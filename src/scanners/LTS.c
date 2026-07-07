/* lts packer ? */
#include "../unp64.h"
void Scn_LTS(unpstr *Unp)
{
    unsigned char *mem;
    int p;
    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x80f)==0xA97800A2) &&
           (*(unsigned int*)(mem+0x817)==0xA3BD9A01) &&
           (*(unsigned int*)(mem+0x81f)==0x01804CF9) &&
           (*(unsigned int*)(mem+0x86f)==0xD5EE09F0) )
        {
            Unp->DepAdr=0x180;
            Unp->Forced=0x80f;
            for(p=0x87e;p<0x880;p++)
            {
                if(!((mem[p]==0x20)||(mem[p]==0x4c)))
                    continue;
                Unp->RetAdr=mem[p+1]|mem[p+2]<<8;
                break;
            }
            Unp->StrMem=mem[0x852]|mem[0x853]<<8;
            Unp->fEndAf=0x1af;
            PrintInfo(Unp,_I_LTSPACK);
            Unp->IdFlag=1;return;
        }
    }
}
