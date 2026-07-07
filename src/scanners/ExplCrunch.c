/* Exploding cruncher */
#include "../unp64.h"
void Scn_ExplCrunch(unpstr *Unp)
{
    unsigned char *mem;
    int p;
    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    /* exploding cruel 2.6 */
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x80d)==0x8D00A978) &&
            (*(unsigned int*)(mem+0x82b)==0x7803D14C) &&
            (*(unsigned int*)(mem+0x8a1)==0xE67800A0)
          )
        {
            Unp->Forced=0x80d;
            Unp->DepAdr=0x100;
            p=mem[0x8a7]|mem[0x8a8]<<8;p+=0x98;
            Unp->fStrAf=0xfc;
            Unp->EndAdr=mem[p]|mem[p+1]<<8;
            PrintInfo(Unp,_I_EXPLCRUNCH1X);
            Unp->IdFlag=1;return;
        }
    }
    /* Epic/Faces exploding crunch v2 */
    if( Unp->DepAdr==0 )
    {
        if(
        /* (*(unsigned int*)(mem+0x80d)==0x208D00A9) && this code can be safely nopped so it's not a good ID
           (*(unsigned int*)(mem+0x81b)==0x08A037A9) && */
           (*(unsigned int*)(mem+0x822)==0x47B900A0) &&
           (*(unsigned int*)(mem+0x824)==0x990847B9) &&
           (*(unsigned int*)(mem+0x831)==0x4C78F1D0) &&
          ((*(unsigned int*)(mem+0x869)&0xff0fffff)==0x4C080185) )
        {
            Unp->DepAdr=mem[0x835]|mem[0x836]<<8;
            if(Unp->info->run == -1)
                Unp->Forced=0x822;
            Unp->RetAdr=mem[0x86d]|mem[0x86e]<<8;
            Unp->StrMem=mem[0x85a]|mem[0x85b]<<8;
            Unp->EndAdr=Unp->StrMem+((0x100-mem[0x858])<<8)-mem[0x857]+1;
            PrintInfo(Unp,_I_EXPLCRUNCH2X);
            if(Unp->DebugP)
                printmsg(mem,(mem[0x81c]|mem[0x81e]<<8),50);
            Unp->IdFlag=1;return;
        }
    }
    /* Tempest exploding crunch v2 hack? */
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x827)==0x990840B9) &&
           (*(unsigned int*)(mem+0x82b)==0xB3B90410) &&
           (*(unsigned int*)(mem+0x8a2)==0xB22002A2) &&
           (*(unsigned int*)(mem+0x8b2)==0xB2200AF0) )
        {
            Unp->DepAdr=mem[0x838]|mem[0x839]<<8;
            if(Unp->info->run == -1)
                Unp->Forced=0x827;
            Unp->RetAdr=mem[0x866]|mem[0x867]<<8;
            Unp->StrMem=mem[0x853]|mem[0x854]<<8;
            Unp->EndAdr=Unp->StrMem+((0x100-mem[0x851])<<8)-mem[0x850]+1;
            PrintInfo(Unp,_I_EXPLCRUNCH21);
            Unp->IdFlag=1;return;
        }
    }
    /* faces 2.2 */
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x81b)==0x99082EB9) &&
           (*(unsigned int*)(mem+0x81f)==0x2EB90410) &&
           (*(unsigned int*)(mem+0x890)==0xB22002A2) &&
           (*(unsigned int*)(mem+0x8a0)==0xB2200AF0) )
        {
            Unp->DepAdr=mem[0x82c]|mem[0x82d]<<8;
            if(Unp->info->run == -1)
                Unp->Forced=0x81b;
            Unp->RetAdr=mem[0x854]|mem[0x855]<<8;
            Unp->StrMem=mem[0x841]|mem[0x842]<<8;
            Unp->EndAdr=Unp->StrMem+((0x100-mem[0x83f])<<8)-mem[0x83e]/*+1*/;
            PrintInfo(Unp,_I_EXPLCRUNCH22);
            Unp->IdFlag=1;return;
        }
    }
    /* Exploding Coder */
    if( Unp->DepAdr==0 )
    {
        if((mem[0x828]==0xa2) &&
           (*(unsigned int*)(mem+0x83d)==0x9D0853BD) &&
           (*(unsigned int*)(mem+0x850)==0xA204504C) &&
           (*(unsigned int*)(mem+0x8b4)==0xCA04339D) )
        {
            Unp->DepAdr=0x450;
            if(Unp->info->run == -1)
                Unp->Forced=0x828;
            Unp->RetAdr=mem[0x890]|mem[0x891]<<8;
            Unp->StrMem=mem[0x854]|mem[0x856]<<8;
            Unp->EndAdr=mem[0x887]|mem[0x889]<<8;
            PrintInfo(Unp,_I_EXPLCOD     );
            Unp->IdFlag=1;return;
        }
    }
}
