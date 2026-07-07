/* Beeftrucker/Zipplink */
#include "../unp64.h"
void Scn_BeefTrucker(unpstr *Unp)
{
    unsigned char *mem;
    int q;
    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0 )
    {
        if( (*(unsigned int*)(mem+0x80d)==0x0798BC78) &&
            (*(unsigned int*)(mem+0x811)==0x30CA8194) &&
            (*(unsigned int*)(mem+0x815)==0x00024CF8) &&
            mem[0x834]==0x2f &&
            mem[0x838]==0x2f )
        {
            Unp->DepAdr=0x002;
            Unp->Forced=0x80d;
            Unp->EndAdr=mem[0x825]|mem[0x826]<<8;
            Unp->RetAdr=mem[0x842]|mem[0x843]<<8;
            Unp->fStrAf=0x0e;
            Unp->StrAdC=0xffff|EA_ADDFF;
            if(mem[0x824]==0x9d)
            {
                Unp->StrAdC|=EA_USE_X;
                Unp->EndAdr+=0xff;
            }
            else
            {
                if(mem[0x825] == 0)
                    Unp->EndAdr+=0x100; /* to check */
            }
            if(mem[0x836]==0xaa) /* Oneway zipplink 1.2, 2 byte shorter */
                PrintInfo(Unp,_I_BEEFTR54);
            else
                PrintInfo(Unp,_I_BEEFTR56);
            Unp->IdFlag=1;return;
        }
        if( (*(unsigned int*)(mem+0x80d)==0x0799BC78) &&
            (*(unsigned int*)(mem+0x811)==0x30CA8194) &&
            (*(unsigned int*)(mem+0x815)==0x00024CF8) &&
            mem[0x825]==0x2f &&
            mem[0x82a]==0x2f )
        {
            Unp->DepAdr=0x002;
            Unp->Forced=0x80d;
            Unp->EndAdr=mem[0x845]|mem[0x846]<<8;
            Unp->RetAdr=mem[0x843]|mem[0x844]<<8;
            Unp->fStrAf=0x1a;
            Unp->StrAdC=0xffff;
            if(mem[0x831]==0x99)
            {
                Unp->StrAdC|=EA_USE_Y;
            }
            PrintInfo(Unp,_I_BEEFTR2);
            Unp->IdFlag=1;return;
        }
        /* Lord Brainwave Zip Link 2.1? */
        if( (*(unsigned int*)(mem+0x80b)==0xA07800A2) &&
            (*(unsigned int*)(mem+0x80f)==0x081FB94C) &&
            (*(unsigned int*)(mem+0x813)==0x8800FF99) &&
            (*(unsigned int*)(mem+0x83f)==0xC9013D20) )
        {
            Unp->DepAdr=0x100;
            Unp->Forced=0x80b;
            Unp->EndAdr=mem[0x835]|mem[0x836]<<8;
            Unp->EndAdr+=0x100;
            Unp->RetAdr=mem[0x85b]|mem[0x85c]<<8;
            Unp->fStrAf=0x115;
            Unp->StrAdC=0xffff|EA_ADDFF;
            Unp->StrAdC|=EA_USE_X;
            PrintInfo(Unp,_I_ZIPLINK21);
            Unp->IdFlag=1;return;
        }
        /* Lord Brainwave Zip Link 2.5 */
        if( (*(unsigned int*)(mem+0x80b)==0x847800A0) &&
            (*(unsigned int*)(mem+0x812)==0x081FBD9A) &&
            (*(unsigned int*)(mem+0x816)==0xF910CA48) &&
            (*(unsigned int*)(mem+0x840)==0xC9013F20) )
        {
            Unp->DepAdr=0x100;
            Unp->Forced=0x80b;
            Unp->EndAdr=mem[0x836]|mem[0x837]<<8;
            Unp->EndAdr+=0x100;
            Unp->RetAdr=mem[0x85c]|mem[0x85d]<<8;
            Unp->fStrAf=0x117;
            Unp->StrAdC=0xffff|EA_ADDFF;
            Unp->StrAdC|=EA_USE_X;
            PrintInfo(Unp,_I_ZIPLINK25);
            Unp->IdFlag=1;return;
        }
    }
    /* zipplink loadback, actually just a relocator from $xx00 to $0801 */
    if( Unp->DepAdr==0 )
    {
        q=Unp->info->start;
        if( (*(unsigned int*)(mem+q)==0x10BD00A2) &&
            mem[q+4]==(q>>8) &&
            (*(unsigned int*)(mem+q+5)==0xE803409D) &&
            (*(unsigned int*)(mem+q+0x31)==0x080B4C58) &&
            (*(unsigned int*)(mem+q+0x62)==0x002F20F4) )
        {
            Unp->Forced=q;
            Unp->DepAdr=0x340;
            Unp->RetAdr=0x80b;
            Unp->StrMem=0x801;
            Unp->EndAdr=0x801+(Unp->info->end-q-0x36);
            PrintInfo(Unp,_I_BEEFTLB);
            Unp->IdFlag=1;return;
        }
    }
}
