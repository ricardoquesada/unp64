/* Morris/Agony Packers */
#include "../unp64.h"
void Scn_Agony(unpstr *Unp)
{
    unsigned char *mem;
    int p;
    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    /* Agony packer v2 */
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x80b)==0xB97800A0) &&
           (*(unsigned int*)(mem+0x80f)==0xE299081E) &&
           (*(unsigned int*)(mem+0x813)==0xF7D0C800) &&
           (*(unsigned int*)(mem+0x865)==0x4C012D8D) )
        {
            Unp->DepAdr=mem[0x81c]|mem[0x81d]<<8;
            Unp->Forced=0x80b;
            Unp->fStrAf=0xf7;
            Unp->StrAdC=0xffff;
            Unp->RetAdr=mem[0x8aa]|mem[0x8ab]<<8;
            Unp->EndAdr=mem[0x833]|mem[0x834]<<8;
            PrintInfo(Unp,_I_AGONYPACK);
            Unp->IdFlag=1;return;
        }
    }
    /* DarkPacker v2.0 */
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x80d)==0xBE7855A0) &&
            (*(unsigned int*)(mem+0x811)==0x00960819) &&
            (*(unsigned int*)(mem+0x815)==0x4CF8D088) &&
            (*(unsigned int*)(mem+0x863)==0x02D053A5) )
        {
            Unp->Forced=0x80d;
            Unp->DepAdr=0x002;
            Unp->RetAdr=mem[0x861]|mem[0x862]<<8;
            Unp->EndAdr=mem[0x853]|mem[0x854]<<8;
            Unp->fStrAf=0x3a;
            Unp->StrAdC=0xffff;
            PrintInfo(Unp,_I_DARKP20);
            Unp->IdFlag=1;return;
        }
        if( (*(unsigned int*)(mem+0x80d)==0xBE7857A0) &&
            (*(unsigned int*)(mem+0x811)==0x00960819) &&
            (*(unsigned int*)(mem+0x815)==0x4CF8D088) &&
            (*(unsigned int*)(mem+0x865)==0x02D055A5) )
        {
            Unp->Forced=0x80d;
            Unp->DepAdr=0x002;
            Unp->RetAdr=mem[0x863]|mem[0x864]<<8;
            Unp->EndAdr=mem[0x853]|mem[0x854]<<8;
            Unp->fStrAf=0x3a;
            Unp->StrAdC=0xffff;
            PrintInfo(Unp,_I_DARKP21);
            Unp->IdFlag=1;return;
        }
    }
    /* DarkPacker v3.1 */
    if( Unp->DepAdr==0 )
    {
        for(p=0x801;p<0x80c;p+=0xa)
        {
            if((*(unsigned int*)(mem+p+0x00)==0x52A200A0) &&
               (*(unsigned int*)(mem+p+0x08)==0xD0CA0095) &&
               (*(unsigned int*)(mem+p+0x0c)==0x00024CF8) &&
               (*(unsigned int*)(mem+p+0x55)==0x02D050A5)   )
            {
                Unp->DepAdr=0x2;
                break;
            }
        }
        if( Unp->DepAdr )
        {
            if(Unp->info->run == -1)
                Unp->Forced=p;
            Unp->EndAdr=mem[p+0x3e]|mem[p+0x3f]<<8;
            Unp->EndAdr+=0x100;
            Unp->fStrAf=0x30;
            Unp->StrAdC=0xffff|EA_USE_Y|EA_ADDFF;
            Unp->RetAdr=mem[p+0x53]|mem[p+0x54]<<8;
            PrintInfo(Unp,_I_DARKP31);
            Unp->IdFlag=1;return;
        }
    }
    /* JustAPacker v2.0 */
    if( Unp->DepAdr==0 )
    {
        for(p=0x801;p<0x80c;p+=0xa)
        {
            if((*(unsigned int*)(mem+p+0x00)==0x847800A0) &&
               (*(unsigned int*)(mem+p+0x07)==0x00ED9908) &&
               (*(unsigned int*)(mem+p+0x0b)==0xA2F7D0C8) &&
               (*(unsigned int*)(mem+p+0x5f)==0xFF8500EE)   )
            {
                Unp->DepAdr=0xfa;
                break;
            }
        }
        if( Unp->DepAdr )
        {
            if(Unp->info->run == -1)
                Unp->Forced=p;
            Unp->EndAdr=mem[p+0x43]|mem[p+0x44]<<8;
            Unp->EndAdr+=0x100;
            Unp->fStrAf=0x11e;
            Unp->StrAdC=0xffff|EA_USE_Y|EA_ADDFF;
            Unp->RetAdr=mem[p+0x9c]|mem[p+0x9d]<<8;
            /* problem: y is lost on exit, but i need its value for startmem*/
            /* load Y back from $ed instead of setting $01 to #$37 */
            mem[p+0x96]=0xa4;
            mem[p+0x97]=0xed;

            PrintInfo(Unp,_I_JAP2);
            Unp->IdFlag=1;return;
        }
    }
}
