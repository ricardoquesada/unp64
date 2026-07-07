/* Excell/Ikari Intro*/
#include "../unp64.h"
void Scn_Ikari(unpstr *Unp)
{
    unsigned char *mem;
    int q,p;
    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        p=0x822;
        if((*(unsigned int*)(mem+p+0x000)==0x8D00A978) &&
           (*(unsigned int*)(mem+p+0x010)==0x9D00A201) &&
           (*(unsigned int*)(mem+p+0x020)==0x009D0749) &&
           (*(unsigned int*)(mem+p+0x080)==0x058107A5) &&
           (*(unsigned int*)(mem+p+0x090)==0x8230AEF4)   )
        {   /* modify unpacker so it doesn't loop in case of alterations */
            q=mem[p+0x21]; /* cryptval, usually 0x07 */
            mem[p+0x99]=0x24^q;
            Unp->DepAdr=0x428;
            Unp->Forced=0x822;
            Unp->RetAdr=(mem[p+0x9e]^q)|((mem[p+0x9f]^q)<<8);
            Unp->EndAdr=Unp->info->end - 0xf0;
            PrintInfo(Unp,_I_EXCELCOD);
            if(Unp->DebugP)
            {
                for(p=0x851;p<0x879;p++)
                    mem[p]^=q;
                printmsg(mem,0x851,40);
            }
            Unp->IdFlag=1;return;
        }
    }
    if( Unp->DepAdr==0 )
    {
        if((*(unsigned int*)(mem+0x814)==0xA201E678) &&
           (*(unsigned int*)(mem+0x818)==0xB006E01B) &&
           (*(unsigned int*)(mem+0x825)==0x10CAA095) )
        {
            p=mem[0x81e]|mem[0x81f]<<8;
            if((*(unsigned int*)(mem+p+0x024)==0xFCC7FFA9) &&
               (*(unsigned int*)(mem+p+0x048)==0x00200226) )
            {
                Unp->Forced=0x814;
                Unp->DepAdr=0x1e8;
                Unp->RetAdr=mem[p+0x11b]|mem[p+0x11c]<<8;Unp->RetAdr++;
                Unp->EndAdr=mem[p+4]|mem[p+5]<<8;Unp->EndAdr++;
                PrintInfo(Unp,_I_IKARICR);
                Unp->IdFlag=1;return;
            }
        }
    }
}
