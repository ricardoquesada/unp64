/*   stop scanning   */
/* put here basic and other languages compilers, loaders and whatever it's
   known to be a non self-unpacking program
*/
#include "../unp64.h"
void Scn_NotPackers(unpstr *Unp)
{
    unsigned char *mem;
    int q,p;
    if ( Unp->IdFlag )
        return;
    mem=Unp->mem;
    if(Unp->DepAdr==0)
    {
        if(Unp->info->start == 0x102)
        {
            if( (*(unsigned int*)(mem+0x102)==0xA9FF8420) &&
                (*(unsigned int*)(mem+0x1d6)==0x4D039C4C) )
            {
                PrintInfo(Unp,_I_ISEPICLD);
                Unp->IdFlag=2;return;
            }
            if( (*(unsigned int*)(mem+0x102)==0xA9FF8420) &&
                (*(unsigned int*)(mem+0x1d6)==0x4D03c24C) )
            {
                PrintInfo(Unp,_I_ISEPICLD);
                Unp->IdFlag=2;return;
            }
            if( (*(unsigned int*)(mem+0x102)==0x0D8D7FA9) &&
                (*(unsigned int*)(mem+0x1cd)==0x039C4CED) )
            {
                PrintInfo(Unp,_I_ISEPICLD);
                Unp->IdFlag=2;return;
            }
        }
        if( (mem[0x81c]==0x4c) &&
            (mem[0x81f]==0x4c) &&
            (mem[0x825]==0x09) &&
            (mem[0x8eb]==0x00) )
        {
            p=mem[0x81d]|mem[0x81e]<<8;
            if((mem[p]==0x20)&&
               (*(unsigned int*)(mem+p+0x14)==0x398550A5) &&
               (*(unsigned int*)(mem+p+0x40)==0x6598F9D0))
            {
                p=*(unsigned short int*)(mem+0x826);
                switch( p )
                {
                case 0x1647:
                    PrintInfo(Unp,_I_AUSTROV1);
                    break;
                case 0x1653:
                    PrintInfo(Unp,_I_AUSTROV2);
                    break;
                case 0x163b:
                    PrintInfo(Unp,_I_AUSTROE1);
                    break;
                case 0x1e09:
                    q=*(unsigned int*)(mem+0x1ed6);
                    switch(q)
                    {
                    case 0x4CE16F20:
                        PrintInfo(Unp,_I_AUSTRO88);
                        break;
                    case 0xA948A7A9:
                        PrintInfo(Unp,_I_BLITZCOM);
                        break;
                    default:
                        PrintInfo(Unp,_I_AUSTRO_U);
                        break;
                    }
                    break;
                case 0x1d09:
                    PrintInfo(Unp,_I_AUSTROS1);
                    break;
                default:
                    PrintInfo(Unp,_I_AUSTROBL);
                    break;
                }
                Unp->IdFlag=2;return;
            }
        }
        if((mem[0x819]==0x4c)&&
           (*(unsigned int*)(mem+0x93f+0x00)==0xC54C03B0) &&
           (*(unsigned int*)(mem+0x93f+0x04)==0x09D74C0A) &&
           (*(unsigned int*)(mem+0x93f+0x34)==0x8509264C))
        {
            PrintInfo(Unp,_I_PETSPEED);
            Unp->IdFlag=2;return;
        }
        if((mem[0x819]==0x4c)&&
           (*(unsigned int*)(mem+0x935+0x00)==0xBB4C03B0) &&
           (*(unsigned int*)(mem+0x935+0x04)==0x09CD4C0A) &&
           (*(unsigned int*)(mem+0x935+0x34)==0x85091C4C))
        {
            PrintInfo(Unp,_I_PETSPEED);
            Unp->IdFlag=2;return;
        }
        if( (mem[0x81e]==0x6c) &&
            (mem[0x820]==0x1d) &&
            (mem[0x821]==0x4c) )
        {
            p=0x97f;
            if((*(unsigned int*)(mem+p+0x00)==0x0E840D85) &&
               (*(unsigned int*)(mem+p+0x20)==0x20604A85) &&
               (*(unsigned int*)(mem+p+0x30)==0x9148A5C8))
            {
                PrintInfo(Unp,_I_BASIC64 );
                Unp->IdFlag=2;return;
            }
        }
        if( (mem[0x825]==0x4c) &&
            (*(unsigned int*)(mem+0x828)==0x01B5B5A2) &&
            (*(unsigned int*)(mem+0x82c)==0xCA08329D) &&
            (*(unsigned int*)(mem+0x830)==0x0060F8D0) )
        {
            q=mem[0x826]|mem[0x827]<<8;
            if((*(unsigned int*)(mem+q)&0x00ffffff)==0x00082820)
            {
                PrintInfo(Unp,_I_BASICBS );
                Unp->IdFlag=2;return;
            }
        }
        if( (*(unsigned int*)(mem+0x900)==0x0E500ACA) &&
            (*(unsigned int*)(mem+0xA38)==0xAD1EFEAE) &&
            (*(unsigned int*)(mem+0xA3c)==0x16861EFF) &&
            (*(unsigned int*)(mem+0xA71)==0x0ACA4C03) )
        {
            PrintInfo(Unp,_I_SPEEDCM );
            Unp->IdFlag=2;return;
        }
        if( (*(unsigned int*)(mem+0x81c)==0x209AF8A2) &&
            (*(unsigned int*)(mem+0x83b)==0x0A002D20) &&
            (*(unsigned int*)(mem+0x85b)==0xA9E37B4C) &&
            (*(unsigned int*)(mem+0x862)==0x083B4CFF) )
        {
            PrintInfo(Unp,_I_SPEEDY64 );
            Unp->IdFlag=2;return;
        }
        if( (mem[0x811]==0x9d) &&
            (*(unsigned int*)(mem+0x80d)==0x02B519A2) &&
            (*(unsigned int*)(mem+0x816)==0xFFCC20F8) &&
            (*(unsigned int*)(mem+0x823)==0x850609F8) &&
            (*(unsigned int*)(mem+0x833)==0x028500A9) )
        {
            PrintInfo(Unp,_I_CC65    );
            Unp->IdFlag=2;return;
        }
        if( (mem[0x811]==0x9d) &&
            (*(unsigned int*)(mem+0x80d)==0x02B519A2) &&
            (*(unsigned int*)(mem+0x81c)==0x294801A5) &&
            (*(unsigned int*)(mem+0x820)==0x850609F8) &&
            (*(unsigned int*)(mem+0x830)==0x028500A9) )
        {
            PrintInfo(Unp,_I_CC6522  );
            Unp->IdFlag=2;return;
        }
        if( (mem[0x80d]==0xa5) &&
            (*(unsigned int*)(mem+0x812)==0x0609F829) &&
            (*(unsigned int*)(mem+0x816)==0x8EBA0185) &&
            (*(unsigned int*)(mem+0x82e)==0x10CA0295) &&
            (*(unsigned int*)(mem+0x832)==0x908568F8) )
        {
            PrintInfo(Unp,_I_CC65218  );
            Unp->IdFlag=2;return;
        }
        if( (mem[0x819]==0x20) && (mem[0x81a]==0x52) &&  (mem[0x81b]==0x08) &&
            (*(unsigned int*)(mem+0x848)==0x20AF7120) &&
            (*(unsigned int*)(mem+0x860)==0x000503A9) &&
            (*(unsigned int*)(mem+0x870)==0xA3472008) )
        {
            PrintInfo(Unp,_I_DTL64   );
            Unp->IdFlag=2;return;
        }
        if( (*(unsigned int*)(mem+0x868)==0xA99AFCA2) &&
            (*(unsigned int*)(mem+0x86c)==0xA2018536) &&
           ((*(unsigned int*)(mem+0x870)&0xfff0fff0)==0x9D20B520) )
        {
            PrintInfo(Unp,_I_LASERBAS);
            Unp->IdFlag=2;return;
        }
        if( (*(unsigned int*)(mem+0x80e)==0x4C081420) &&
            (*(unsigned int*)(mem+0x842)==0x31856042) &&
            (*(unsigned int*)(mem+0x8a2)==0xD44C34A4) )
        {
            PrintInfo(Unp,_I_HYPRA   );
            Unp->IdFlag=2;return;
        }
        if(mem[0x80e]==0x4c)
        {
            p=mem[0x80f]|mem[0x810]<<8;
            if((*(unsigned int*)(mem+p+0x00)==0xFE2901A5) &&
               (*(unsigned int*)(mem+p+0x14)==0x00A94C85) &&
               (*(unsigned int*)(mem+p+0x2a)==0x4C4CE602)
              )
            {
                PrintInfo(Unp,_I_POWERC);
                Unp->IdFlag=2;return;
            }
        }
        if( (*(unsigned int*)(mem+0x80f)==0x018535A9) &&
            (*(unsigned int*)(mem+0x813)==0xA99AFFA2) &&
            (*(unsigned int*)(mem+0x817)==0xFFFA8D32) &&
            (*(unsigned int*)(mem+0x851)==0xEEF1D0E8) )
        {
            PrintInfo(Unp,_I_EMUFUX1);
            Unp->IdFlag=2;return;
        }
        if( (*(unsigned int*)(mem+0x80f)==0xA9018535) &&
            (*(unsigned int*)(mem+0x813)==0xFFFA8D32) &&
            (*(unsigned int*)(mem+0x817)==0xFB8D08A9) &&
            (*(unsigned int*)(mem+0x851)==0xEEF1D0E8) )
        {
            PrintInfo(Unp,_I_EMUFUX2);
            Unp->IdFlag=2;return;
        }
        if( (*(unsigned int*)(mem+0x813)==0xA9E51820) &&
            (*(unsigned int*)(mem+0x81F)==0xFFE42002) &&
            (*(unsigned int*)(mem+0x82F)==0xEB10CA04) &&
            (*(unsigned int*)(mem+0x83F)==0xDDB05BC9) )
        {
            PrintInfo(Unp,_I_PWCOPSH);
            Unp->IdFlag=2;return;
        }
        if( (*(unsigned int*)(mem+0x812)==0x018537A9) &&
            (*(unsigned int*)(mem+0x84e)==0x80C9DC90) &&
            (*(unsigned int*)(mem+0x85e)==0x0284C808) &&
            (*(unsigned int*)(mem+0x88c)==0xA908F34C) )
        {
            PrintInfo(Unp,_I_PWTIMEC);
            Unp->IdFlag=2;return;
        }
        if( (*(unsigned int*)(mem+0x822)==0x08A017A9) &&
            (*(unsigned int*)(mem+0x832)==0x1AF00DC9) &&
            (*(unsigned int*)(mem+0x842)==0x8510A906) &&
            (*(unsigned int*)(mem+0x852)==0xE801009D) )
        {
            PrintInfo(Unp,_I_PWSNACKY);
            Unp->IdFlag=2;return;
        }
        if( (*(unsigned int*)(mem+0x81d)==0x083520FF) &&
            (*(unsigned int*)(mem+0x821)==0x3520FB85) &&
            (*(unsigned int*)(mem+0x831)==0x08404CFE) &&
            (*(unsigned int*)(mem+0x891)==0xE6FD91FB) )
        {
            PrintInfo(Unp,_I_PWTCD);
            Unp->IdFlag=2;return;
        }
        if( (*(unsigned int*)(mem+0x815)==0x08A0CCA9) &&
            (*(unsigned int*)(mem+0x835)==0xFBF0FFE4) &&
            (*(unsigned int*)(mem+0x845)==0xC0C80433) &&
            (*(unsigned int*)(mem+0x855)==0x0433992A) )
        {
            PrintInfo(Unp,_I_PWJCH);
            Unp->IdFlag=2;return;
        }
        if( (*(unsigned int*)(mem+0x80b)==0x028600A2) &&
            (*(unsigned int*)(mem+0x817)==0xFF9D089E) &&
            (*(unsigned int*)(mem+0x827)==0xFFF0200F) &&
            (*(unsigned int*)(mem+0x82b)==0xF0FFE420) )
        {
            PrintInfo(Unp,_I_PWFILEPR);
            Unp->IdFlag=2;return;
        }
        if( (*(unsigned int*)(mem+0x80d)==0x08A08CA9) &&
            (*(unsigned int*)(mem+0x81d)==0xFFE420FF) &&
            (*(unsigned int*)(mem+0x82c)==0x03349DFF) &&
            (*(unsigned int*)(mem+0x8e1)==0xDC074DDD) )
        {
            PrintInfo(Unp,_I_PWFLT);
            Unp->IdFlag=2;return;
        }
        /*
        as of V2.5.0 (Sep 06, 2025) AGPX Game Maker was renamed to Yormesyx64
        */
        if( (*(unsigned short int*)(mem+0x80d)==0x8eba) &&
            (*(unsigned int*)(mem+0x817)==0x26862585)   &&
            (*(unsigned short int*)(mem+0x835)==0x2030) &&
            (*(unsigned int*)(mem+0x839)==0x54854CA9)   &&
            (*(unsigned int*)(mem+0x842)==0x60168519) )
        {
            PrintInfo(Unp,_I_AGPXGM);
            Unp->IdFlag=2;return;
        }
        if( (*(unsigned int*)(mem+0x80d)==0x0E85FFA9) &&
            (*(unsigned int*)(mem+0x811)==0x0F8500A9) &&
            (*(unsigned int*)(mem+0x815)==0x1085CFA9) &&
            (*(unsigned int*)(mem+0x824)==0xFBD0CA16) )
        {
            PrintInfo(Unp,_I_AGPXGMO);
            Unp->IdFlag=2;return;
        }
        if( (*(unsigned short int*)(mem+0x80d)==0x8eba) &&
            (*(unsigned int*)(mem+0x817)==0xA9381A85) &&
            (*(unsigned int*)(mem+0x836)==0x8800A9A8) &&
            (*(unsigned int*)(mem+0x83b)==0xA9FBD019) )
        {
            PrintInfo(Unp,_I_OSCAR64_1);
            Unp->IdFlag=2;return;
        }
        if( (*(unsigned short int*)(mem+0x80d)==0x8eba) &&
            ((*(unsigned int*)(mem+0x817)&0xffff00ff)==0xA9380085) &&
            (*(unsigned int*)(mem+0x836)==0x8800A9A8) &&
            (*(unsigned int*)(mem+0x83b)==(0xA2FBD000|(mem[0x82b]-1))) )
        {
            PrintInfo(Unp,_I_OSCAR64_2);
            Unp->IdFlag=2;return;
        }
        if( (*(unsigned short int*)(mem+0x80d)==0x8eba) &&
            (*(unsigned int*)(mem+0x817)==0x1A861985) &&
            (*(unsigned int*)(mem+0x836)==0xD0F7E0E8) &&
            ((*(unsigned int*)(mem+0x841)&0x00ffffff)==0x00202485) )
        {
            PrintInfo(Unp,_I_OSCAR64_3);
            Unp->IdFlag=2;return;
        }
        if( (*(unsigned short int*)(mem+0x80d)==0x8eba) &&
            (*(unsigned int*)(mem+0x817)==0xA9382685) &&
            (*(unsigned int*)(mem+0x836)==0x8800A9A8) &&
            (*(unsigned int*)(mem+0x83b)==0xA9FBD025) )
        {
            PrintInfo(Unp,_I_OSCAR64_4);
            Unp->IdFlag=2;return;
        }
    }
}

