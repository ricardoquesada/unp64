/* TrashCan, modified Abuzecrunch */
#include "../unp64.h"
void Scn_Trashcan(unpstr *Unp)
{
    unsigned char *mem;
    int p;
    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if( Unp->DepAdr==0)
    {
        if( (*(unsigned int*)(mem+0x80d)==0xE6781BA2) &&
            (*(unsigned int*)(mem+0x812)==0x05B006E0) &&
           ((*(unsigned int*)(mem+0x82b)==0x04D44CF7)||
            (*(unsigned int*)(mem+0x82d)==0x04D44CF7)) )
        {
            p=mem[0x817]|mem[0x818]<<8;
            if( (*(unsigned int*)(mem+p+0x022)==0xFCC7FFA9) &&
                (*(unsigned int*)(mem+p+0x112)==0xFFA9FA85) )
            {
                Unp->DepAdr=0x44d;
                Unp->Forced=0x80d;
                Unp->EndAdr=mem[p+0x004]|mem[p+0x005]<<8;Unp->EndAdr++;
                Unp->RetAdr=mem[p+0x107]|mem[p+0x108]<<8;
                Unp->fStrAf=0xfe;
                if(*(unsigned int*)(mem+0x82b)==0x04D44CF7)
                    PrintInfo(Unp,_I_TRASHC2);
                else
                    PrintInfo(Unp,_I_TRASHC1);
                Unp->IdFlag=1;return;
            }
        }
    }
    /* another Thrashcan/Abuze mod by dINO */
    if( Unp->DepAdr==0)
    {
        if( (*(unsigned int*)(mem+0x812)==0xA201E678) &&
            (*(unsigned int*)(mem+0x816)==0xB006E01B) &&
            (*(unsigned int*)(mem+0x839)==0x07004CEF)  )
        {
            p=mem[0x81c]|mem[0x81d]<<8;
            if( (*(unsigned int*)(mem+p+0x022)==0xFCC7FFA9) &&
                (*(unsigned int*)(mem+p+0x123)==0xFFA9FA85) )
            {
                Unp->DepAdr=0x700;
                Unp->Forced=0x812;
                Unp->EndAdr=mem[p+0x004]|mem[p+0x005]<<8;Unp->EndAdr++;
                Unp->RetAdr=mem[p+0x0f8]|mem[p+0x0f9]<<8;
                Unp->fStrAf=0xfe;
                PrintInfo(Unp,_I_TRASHCU);
                Unp->IdFlag=1;return;
            }
        }
    }
}
