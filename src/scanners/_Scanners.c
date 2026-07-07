#include "../unp64.h"

Scnptr ScanFunc[]=
    {Scn_NotPackers
    ,Scn_Autostarters
    ,Scn_XIP
    ,Scn_OUG
    ,Scn_IsePic
    ,Scn_Optimus
    ,Scn_ECA
    ,Scn_xCodeZippers
    ,Scn_Expert
    ,Scn_AR
    ,Scn_BitImploder
    ,Scn_Jox
    ,Scn_ExplCrunch
    ,Scn_ExplFaces
    ,Scn_Facepacker
    ,Scn_ABCruncher
    ,Scn_BYG
    ,Scn_FilecompactorTMC
    ,Scn_ASCprot
    ,Scn_CFB
    ,Scn_Zipper
    ,Scn_NSU
    ,Scn_IDT
    ,Scn_Cruel
    ,Scn_PuCrunch
    ,Scn_MDG
    ,Scn_AbuzeCrunch
    ,Scn_SledgeHammer
    ,Scn_TimCrunch
    ,Scn_TimeCruncher
    ,Scn_BetaDynamic
    ,Scn_DarkSqueezer
    ,Scn_ByteBoiler
    ,Scn_MrCross
    ,Scn_1001card
    ,Scn_WDRsoftp
    ,Scn_DSCcoder
    ,Scn_BonanzaBros
    ,Scn_Agony
    ,Scn_ExplXRated
    ,Scn_ByteCompactor
    ,Scn_MasterCompressor
    ,Scn_ScreenCrunch
    ,Scn_MCCrackenComp
    ,Scn_FinalSuperComp
    ,Scn_4cPack
    ,Scn_FXbytepress
    ,Scn_FXbitstream
    ,Scn_Trianon
    ,Scn_KompressMaster711
    ,Scn_TurboPacker
    ,Scn_TCScrunch
    ,Scn_TBCMultiComp
    ,Scn_ByteBoozer
    ,Scn_ALZ64
    ,Scn_XTC
    ,Scn_UniPacker
    ,Scn_TCD
    ,Scn_Matcham
    ,Scn_Supercrunch
    ,Scn_Superpack
    ,Scn_BeefTrucker
    ,Scn_TSB
    ,Scn_ISC
    ,Scn_TMM
    ,Scn_FilecompactorMTB
    ,Scn_EqByteComp
    ,Scn_Galleon
    ,Scn_BeastLink
    ,Scn_BronxPacker
    ,Scn_Oneway
    ,Scn_CeleriPack
    ,Scn_CadgersPacker
    ,Scn_Crush
    ,Scn_Lightmizer
    ,Scn_Frog
    ,Scn_FrontPacker
    ,Scn_MartinPiper
    ,Scn_Apack
    ,Scn_ONS
    ,Scn_FC3pack
    ,Scn_Amnesia
    ,Scn_Polonus
    ,Scn_KressCrunch
    ,Scn_SirMiniPack
    ,Scn_MRD
    ,Scn_CCS
    ,Scn_PZW
    ,Scn_C4MRP
    ,Scn_ILSCoder
    ,Scn_MSI
    ,Scn_U_111pack
    ,Scn_Hawk
    ,Scn_TSMcoder
    ,Scn_Ikari
    ,Scn_WGIcoder
    ,Scn_HTLcoder
    ,Scn_XDScoder
    ,Scn_FDTcoder
    ,Scn_SKLcoder
    ,Scn_SpeediComp
    ,Scn_U_DSC_MA
    ,Scn_P100
    ,Scn_MaschSprache
    ,Scn_MegaCruncher
    ,Scn_VIP
    ,Scn_Gandalf
    ,Scn_AEKcoder
    ,Scn_LSTcoder
    ,Scn_Eastlinker
    ,Scn_Jazzcat
    ,Scn_PITcoder
    ,Scn_BitPacker
    ,Scn_Rows
    ,Scn_U_400All
    ,Scn_U_439pack
    ,Scn_64er
    ,Scn_TMCcoder
    ,Scn_ALScoder
    ,Scn_UltraComp
    ,Scn_FCG
    ,Scn_Megabyte
    ,Scn_Zigag
    ,Scn_Brains
    ,Scn_Graffity
    ,Scn_Section8
    ,Scn_MrZ
    ,Scn_DD
    ,Scn_PackOpt
    ,Scn_Warlock
    ,Scn_U_100pack
    ,Scn_U_101pack
    ,Scn_SyncroPack
    ,Scn_Relax
    ,Scn_Jazoo
    ,Scn_WCC
    ,Scn_LTS
    ,Scn_Low
    ,Scn_C_Noack
    ,Scn_Koncina
    ,Scn_U_Triad
    ,Scn_RapEq
    ,Scn_ByteKiller
    ,Scn_Loadstar
    ,Scn_Trashcan
    ,Scn_Caution
    ,Scn_U_25_pack
    ,Scn_U_8e_pack
    ,Scn_U_P3_pack
    ,Scn_U_fd_pack
    ,Scn_FalcoPack
    ,Scn_FP
    ,Scn_FinalCompactor
    ,Scn_NEC
    ,Scn_EnigmaMFFL
    ,Scn_Shurigen
    ,Scn_STL
    ,Scn_GrafBinaer
    ,Scn_AbyssCoder
    ,Scn_SPC
    ,Scn_FSW
    ,Scn_BAM
    ,Scn_Cobra
    ,Scn_ByteBuster
    ,Scn_Mekker
    ,Scn_ByteStrainer
    ,Scn_Jedi
    ,Scn_Pride
    ,Scn_StarCrunch
    ,Scn_SpyPack
    ,Scn_GPacker
    ,Scn_Cadaver
    ,Scn_Helmet
    ,Scn_Excalibur
    ,Scn_CNCD
    ,Scn_Anticom
    ,Scn_Antiram
    ,Scn_BN1872
    ,Scn_4wd
    ,Scn_Huffer
    ,Scn_NM156
    ,Scn_Ratt
    ,Scn_Byterapers
    ,Scn_CIACrypt
    ,Scn_PAN
    ,Scn_TKC
    ,Scn_UProt
    ,Scn_YetiCoder
    ,Scn_Panoramic
    ,Scn_THS
    ,Scn_WHO
    ,Scn_KGBcoder
    ,Scn_Pyra
    ,Scn_ActionPacker
    ,Scn_CCrypt
    ,Scn_TDT
    ,Scn_Cult
    ,Scn_Gimzo
    ,Scn_BlackAdder
    ,Scn_ICS8
    ,Scn_Paradroid
    ,Scn_Plasma
    ,Scn_DrZoom
    ,Scn_ExactCoder
    ,Scn_CNETFixer
    ,Scn_Triangle
    ,Scn_SFLinker
    ,Scn_Bongo
    ,Scn_Jemasoft
    ,Scn_TATCoder
    ,Scn_RFOCoder
    ,Scn_Doynamite
    ,Scn_Nibbit
    ,Scn_TLRLinker
    ,Scn_TLRSubsizer
    ,Scn_AdmiralP4kbar
    ,Scn_ZeroCoder
    ,Scn_NuCrunch
    ,Scn_TinyCrunch
    ,Scn_FileLinkerSDA
    ,Scn_Inceria
    ,Scn_ZX0
    ,Scn_TSCrunch
    ,Scn_PWRCoder
    ,Scn_BitPickler
    ,Scn_Maimer
    ,Scn_OrionCoder
    ,Scn_TAG
    ,Scn_AEB
    ,Scn_Comp64k
    ,Scn_Lzss
    ,Scn_Exomizer
    ,Scn_Intros
    ,Scn_U_Generic801
    };

void Scanners(unpstr *Unp)
{
    int x,y;
    y=sizeof(ScanFunc)/sizeof(*ScanFunc);
    for (x=0;x<y;x++)
    {
        (ScanFunc[x])(Unp);
        if ( Unp->IdFlag )
            break;
    }
}
/* all this to make a central strings pool with unique const strings
   else every module would have own local strings, duplicated many times.
*/
void PrintInfo(unpstr *Unp, int id)
{
    switch(id)
    {
    case _I_1001_4:
    printf(DEPMASK2,"1001 CardCruncher","v4.x",Unp->DepAdr);
    break;
    case _I_1001_NEWPACK:
    sprintf(appstr,"%s %s","1001 CardCruncher","New");
    printf(DEPMASK2,appstr,"Packer",Unp->DepAdr);
    break;
    case _I_1001_OLDPACK:
    sprintf(appstr,"%s %s","1001 CardCruncher","Old");
    printf(DEPMASK2,appstr,"Packer",Unp->DepAdr);
    break;
    case _I_1001_CRAM:
    printf(DEPMASK2,"1001 CardCruncher","CRAM",Unp->DepAdr);
    break;
    case _I_1001_ACM:
    printf(DEPMASK2,"1001 CardCruncher","ACM",Unp->DepAdr);
    break;
    case _I_1001_HTL:
    printf(DEPMASK2,"1001 CardCruncher","HTL",Unp->DepAdr);
    break;
    case _I_DATELUC:
    printf(DEPMASK2,"Datel UltraCompander","Cruncher",Unp->DepAdr);
    break;
    case _I_DATELUCP:
    printf(DEPMASK2,"Datel UltraCompander","Packer",Unp->DepAdr);
    break;
    case _I_DATELUCC:
    printf(DEPMASK2,"Datel UltraCompander","Compactor",Unp->DepAdr);
    break;
    case _I_4CPACK:
    printf(DEPMASK2,"4C","Packer",Unp->DepAdr);
    break;
    case _I_64ER_SP22:
    sprintf(appstr,"%s %s","/ special","v2.2");
    printf(DEPMASK2,"64er",appstr,Unp->DepAdr);
    break;
    case _I_64ER_SP23:
    sprintf(appstr,"%s %s","/ special","v2.3");
    printf(DEPMASK2,"64er",appstr,Unp->DepAdr);
    break;
    case _I_64ER_SP2U:
    sprintf(appstr,"%s %s","/ special","v2.?");
    printf(DEPMASK2,"64er",appstr,Unp->DepAdr);
    break;
    case _I_64ER_SP12:
    sprintf(appstr,"%s %s","/ special","v1.2");
    printf(DEPMASK2,"64er",appstr,Unp->DepAdr);
    break;
    case _I_64ER_SP13:
    sprintf(appstr,"%s %s","/ special","v1.3");
    printf(DEPMASK2,"64er",appstr,Unp->DepAdr);
    break;
    case _I_64ER_SP14:
    sprintf(appstr,"%s %s","/ special","v1.4");
    printf(DEPMASK2,"64er",appstr,Unp->DepAdr);
    break;
    case _I_64ER_SP15:
    sprintf(appstr,"%s %s","/ special","v1.5");
    printf(DEPMASK2,"64er",appstr,Unp->DepAdr);
    break;
    case _I_64ER_SP1U:
    sprintf(appstr,"%s %s","/ special","v1.?");
    printf(DEPMASK2,"64er",appstr,Unp->DepAdr);
    break;
    case _I_64ERBITP:
    sprintf(appstr,"%s%s","Bit","Packer");
    printf(DEPMASK2,"64er",appstr,Unp->DepAdr);
    break;
    case _I_64ERBITP1:
    sprintf(appstr,"%s%s","Bit","Packer");
    strcat(appstr," ");
    strcat(appstr,"/ special");
    printf(DEPMASK2,"64er",appstr,Unp->DepAdr);
    break;
    case _I_64ERS41A:
    strcpy(appstr,"64er");
    strcat(appstr," ");
    strcat(appstr,"/ Equal sequences");
    strcat(appstr," ");
    strcat(appstr,"v4.1");strcat(appstr,"A");
    printf(DEPMASK,appstr,Unp->DepAdr);
    break;
    case _I_64ERS41B:
    strcpy(appstr,"64er");
    strcat(appstr," ");
    strcat(appstr,"/ Equal sequences");
    strcat(appstr," ");
    strcat(appstr,"v4.1");strcat(appstr,"B");
    printf(DEPMASK,appstr,Unp->DepAdr);
    break;
    case _I_64ERS41C:
    strcpy(appstr,"64er");
    strcat(appstr," ");
    strcat(appstr,"/ Equal sequences");
    strcat(appstr," ");
    strcat(appstr,"v4.1");strcat(appstr,"C");
    printf(DEPMASK,appstr,Unp->DepAdr);
    break;
    case _I_64ERS40A:
    strcpy(appstr,"64er");
    strcat(appstr," ");
    strcat(appstr,"/ Equal sequences");
    strcat(appstr," ");
    strcat(appstr,"v4.0");strcat(appstr,"A");
    printf(DEPMASK,appstr,Unp->DepAdr);
    break;
    break;
    case _I_64ERS40B:
    strcpy(appstr,"64er");
    strcat(appstr," ");
    strcat(appstr,"/ Equal sequences");
    strcat(appstr," ");
    strcat(appstr,"v4.0");strcat(appstr,"B");
    printf(DEPMASK,appstr,Unp->DepAdr);
    break;
    case _I_64ERS40C:
    strcpy(appstr,"64er");
    strcat(appstr," ");
    strcat(appstr,"/ Equal sequences");
    strcat(appstr," ");
    strcat(appstr,"v4.0");strcat(appstr,"C");
    printf(DEPMASK,appstr,Unp->DepAdr);
    break;
    case _I_64ERS40D:
    strcpy(appstr,"64er");
    strcat(appstr," ");
    strcat(appstr,"/ Equal sequences");
    strcat(appstr," ");
    strcat(appstr,"v4.0");strcat(appstr,"D");
    printf(DEPMASK,appstr,Unp->DepAdr);
    break;
    case _I_64ERS40DB:
    strcpy(appstr,"64er");
    strcat(appstr," ");
    strcat(appstr,"/ Equal sequences");
    strcat(appstr," ");
    strcat(appstr,"v4.0");strcat(appstr,"DB");
    printf(DEPMASK,appstr,Unp->DepAdr);
    break;
    case _I_64ERS40F:
    strcpy(appstr,"64er");
    strcat(appstr," ");
    strcat(appstr,"/ Equal sequences");
    strcat(appstr," ");
    strcat(appstr,"v4.0");strcat(appstr,"F");
    printf(DEPMASK,appstr,Unp->DepAdr);
    break;
    case _I_64ER_15:
    printf(DEPMASK2,"64er","v1.5",Unp->DepAdr);
    break;
    case _I_64ER_21:
    printf(DEPMASK2,"64er","v2.1",Unp->DepAdr);
    break;
    case _I_HAPPYS32:
    strcpy(appstr,"Happy-");strcat(appstr,"Packer");
    strcat(appstr," ");
    strcat(appstr,"/ Equal sequences");
    strcat(appstr," ");
    strcat(appstr,"v3.2");
    printf(DEPMASK,appstr,Unp->DepAdr);
    break;
    case _I_HAPPYS22:
    strcpy(appstr,"Happy-");strcat(appstr,"Packer");
    strcat(appstr," ");
    strcat(appstr,"/ Equal sequences");
    strcat(appstr," ");
    strcat(appstr,"v2.2");
    printf(DEPMASK,appstr,Unp->DepAdr);
    break;
    case _I_64ERAUTO:
    printf(DEPMASK2,"64er","Autostarter",Unp->DepAdr);
    break;
    case _I_AB_CRUNCH:
    sprintf(appstr,"%s%s","AB","Cruncher");
    printf(DEPMASK,appstr,Unp->DepAdr);
    break;
    case _I_ABUZECRUNCH:
    printf(DEPMASK,"AbuzeCrunch",Unp->DepAdr);
    break;
    case _I_ABUZECR37:
    printf(DEPMASK2,"AbuzeCrunch","v3.7",Unp->DepAdr);
    break;
    case _I_ABUZECR50:
    printf(DEPMASK2,"AbuzeCrunch","v5.0",Unp->DepAdr);
    break;
    case _I_AEKCOD20 :
    sprintf(appstr,"%s %s","AEK","Coder");
    printf(DEPMASK2,appstr,"v2.0",Unp->DepAdr);
    break;
    case _I_AEKCOD11 :
    sprintf(appstr,"%s %s","AEK","Coder");
    printf(DEPMASK2,appstr,"v1.1",Unp->DepAdr);
    break;
    case _I_SYNCRO13:
    sprintf(appstr,"%s %s","Syncro","Packer");
    printf(DEPMASK2,appstr,"v1.3",Unp->DepAdr);
    break;
    case _I_SYNCRO14:
    sprintf(appstr,"%s %s","Syncro","Packer");
    printf(DEPMASK2,appstr,"v1.4",Unp->DepAdr);
    break;
    case _I_SYNCRO155:
    sprintf(appstr,"%s %s","Syncro","Packer");
    printf(DEPMASK2,appstr,"v1.55",Unp->DepAdr);
    break;
    case _I_SYNCRO12 :
    sprintf(appstr,"%s %s","Syncro","Packer");
    printf(DEPMASK2,appstr,"v1.2",Unp->DepAdr);
    break;
    case _I_TLRPACK:
    printf(DEPMASK2,"T.L.R.","Packer",Unp->DepAdr);
    break;
    case _I_TLRPROT1:
    sprintf(appstr,"%s %s","T.L.R.","Protector");
    printf(DEPMASK2,appstr,"v1.0",Unp->DepAdr);
    break;
    case _I_TLRPROT2:
    sprintf(appstr,"%s %s","T.L.R.","Protector");
    printf(DEPMASK2,appstr,"v2.0",Unp->DepAdr);
    break;
    case _I_TLRLINK:
    printf(DEPMASK2,"T.L.R.","Linker",Unp->DepAdr);
    break;
    case _I_TLRLINKFM:
    sprintf(appstr,"%s %s","T.L.R.","Linker");
    printf(DEPMASK2,appstr,"FullMem",Unp->DepAdr);
    break;
    case _I_TLRSSIZER:
    printf(DEPMASK2,"T.L.R.","Subsizer",Unp->DepAdr);
    break;
    case _I_TLRSSIZD5:
    sprintf(appstr,"%s %s","T.L.R.","Subsizer");
    strcat(appstr," 0.5");
    printf(DEPMASK2,appstr,"/ dirty",Unp->DepAdr);
    break;
    case _I_TLRSSIZD6:
    sprintf(appstr,"%s %s","T.L.R.","Subsizer");
    strcat(appstr," 0.6");
    printf(DEPMASK2,appstr,"/ dirty",Unp->DepAdr);
    break;
    case _I_AGONYPACK:
    sprintf(appstr,"%s %s","Agony","Packer");
    printf(DEPMASK2,appstr,"v2.x",Unp->DepAdr);
    break;
    case _I_DARKP20:
    sprintf(appstr,"%s %s","Dark","Packer");
    printf(DEPMASK2,appstr,"v2.0",Unp->DepAdr);
    break;
    case _I_DARKP21:
    sprintf(appstr,"%s %s","Dark","Packer");
    printf(DEPMASK2,appstr,"v2.1",Unp->DepAdr);
    break;
    case _I_DARKP31:
    sprintf(appstr,"%s %s","Dark","Packer");
    printf(DEPMASK2,appstr,"v3.1",Unp->DepAdr);
    break;
    case _I_JAP2:
    sprintf(appstr,"%s %s","Just A","Packer");
    printf(DEPMASK2,appstr,"v2.0",Unp->DepAdr);
    break;
    case _I_ALSCODER:
    printf(DEPMASK2,"ALS","Coder",Unp->DepAdr);
    break;
    case _I_ALZ64:
    printf(DEPMASK,"ALZ64/Kabuto",Unp->DepAdr);
    break;
    case _I_ALZ64Q:
    printf(DEPMASK,"ALZ64/Quiss",Unp->DepAdr);
    break;
    case _I_AMNESIA1:
    sprintf(appstr,"%s %s","Amnesia","Packer");
    printf(DEPMASK2,appstr,"v1.x",Unp->DepAdr);
    break;
    case _I_AMNESIA2:
    sprintf(appstr,"%s %s","Amnesia","Packer");
    printf(DEPMASK2,appstr,"v2.x",Unp->DepAdr);
    break;
    case _I_APACK:
    printf(DEPMASK,"Apack/MadRom",Unp->DepAdr);
    break;
    case _I_GPACK:
    printf(DEPMASK,"G-Packer/Oxyron",Unp->DepAdr);
    break;
    case _I_AR4  :
    printf(DEPMASK2,"Action Replay","v4.x",Unp->DepAdr);
    break;
    case _I_AR3  :
    printf(DEPMASK2,"Action Replay","v3.x",Unp->DepAdr);
    break;
    case _I_ARU  :
    printf(DEPMASK2,"Action Replay","Unknown",Unp->DepAdr);
    break;
    case _I_AR42F:
    sprintf(appstr,"%s %s","Action Replay","v4.x");
    printf(DEPMASK2,appstr,"Split Freeze",Unp->DepAdr);
    break;
    case _I_SSNAP:
    sprintf(appstr,"%s %s","Super","Snapshot");
    printf(DEPMASK,appstr,Unp->DepAdr);
    break;
    case _I_FRZMACH:
    printf(DEPMASK,"Freeze Machine",Unp->DepAdr);
    break;
    case _I_FRZMACH2F:
    printf(DEPMASK2,"Freeze Machine","Split Freeze",Unp->DepAdr);
    break;
    case _I_ASCPROT:
    printf(DEPMASK2,"ASC/SCF","Protector",Unp->DepAdr);
    break;
    case _I_BEASTLINK:
    printf(DEPMASK,"BeastLink",Unp->DepAdr);
    break;
    case _I_BEEFTR56:
    printf(DEPMASK2,"BeefTrucker","$56",Unp->DepAdr);
    break;
    case _I_BEEFTR54:
    printf(DEPMASK2,"Zipplink","$54",Unp->DepAdr);
    break;
    case _I_BEEFTR2:
    strcpy(appstr,"BeefTrucker");strcat(appstr,"/");strcat(appstr,"Zipplink");
    printf(DEPMASK2,appstr,"v2.x",Unp->DepAdr);
    break;
    case _I_BEEFTLB:
    strcpy(appstr,"BeefTrucker");strcat(appstr,"/");strcat(appstr,"Zipplink");
    printf(DEPMASK2,appstr,"LoadBack",Unp->DepAdr);
    break;
    case _I_ZIPLINK21:
    printf(DEPMASK2,"Zip Link","v2.1",Unp->DepAdr);
    break;
    case _I_ZIPLINK25:
    printf(DEPMASK2,"Zip Link","v2.5",Unp->DepAdr);
    break;
    case _I_BETADYN3:
    sprintf(appstr,"%s %s","Beta Dynamic","Compressor");
    printf(DEPMASK2,appstr,"v3.x",Unp->DepAdr);
    break;
    case _I_BETADYN3FX:
    sprintf(appstr,"%s %s","Beta Dynamic","Compressor");
    strcat(appstr," ");
    strcat(appstr,"v3.x");strcat(appstr,"/");strcat(appstr,"FX");
    printf(DEPMASK,appstr,Unp->DepAdr);
    break;
    case _I_BETADYN3CCS:
    sprintf(appstr,"%s %s","Beta Dynamic","Compressor");
    strcat(appstr," ");
    strcat(appstr,"v3.x");strcat(appstr,"/");strcat(appstr,"CCS");
    printf(DEPMASK,appstr,Unp->DepAdr);
    break;
    case _I_BETADYN2:
    sprintf(appstr,"%s %s","Beta Dynamic","Compressor");
    printf(DEPMASK2,appstr,"v2.x",Unp->DepAdr);
    break;
    case _I_BITIMP:
    sprintf(appstr,"%s%s","Bit","Imploder");
    printf(DEPMASK,appstr,Unp->DepAdr);
    break;
    case _I_BITPACK2:
    sprintf(appstr,"%s%s","Bit","Packer");
    printf(DEPMASK2,appstr,"v2.x",Unp->DepAdr);
    break;
    case _I_BONANZA:
    printf(DEPMASK2,"BonanzaBros","Coder",Unp->DepAdr);
    break;
    case _I_BRAINS:
    printf(DEPMASK2,"Brains","Packer",Unp->DepAdr);
    break;
    case _I_BRONX:
    printf(DEPMASK2,"Bronx","Packer",Unp->DepAdr);
    break;
    case _I_BYG1:
    sprintf(appstr,"%s %s","BYG","Compactor");
    printf(DEPMASK2,appstr,"v1.x",Unp->DepAdr);
    break;
    case _I_BYG2:
    sprintf(appstr,"%s %s","BYG","Compactor");
    printf(DEPMASK2,appstr,"v2.x",Unp->DepAdr);
    break;
    case _I_BYGBB:
    printf(DEPMASK2,"Byte","Baby",Unp->DepAdr);
    break;
    case _I_BYTEBOILER:
    sprintf(appstr,"%s%s","Byte","Boiler");
    printf(DEPMASK,appstr,Unp->DepAdr);
    break;
    case _I_BYTEBOICPX:
    sprintf(appstr,"%s%s","Byte","Boiler");
    printf(DEPMASK2,appstr,"CPX",Unp->DepAdr);
    break;
    case _I_BYTEBOISCS:
    sprintf(appstr,"%s%s","Byte","Boiler");
    printf(DEPMASK2,appstr,"SCS",Unp->DepAdr);
    break;
    case _I_BYTEBOOZER:
    sprintf(appstr,"%s%s","Byte","Boozer");
    printf(DEPMASK,appstr,Unp->DepAdr);
    break;
    case _I_BYTEBOOZ20:
    sprintf(appstr,"%s%s","Byte","Boozer");
    printf(DEPMASK2,appstr,"v2.0",Unp->DepAdr);
    break;
    case _I_BYTEBOOZ11C:
    sprintf(appstr,"%s%s","Byte","Boozer");
    strcat(appstr," ");
    strcat(appstr,"v1.1");strcat(appstr,"C");
    printf(DEPMASK,appstr,Unp->DepAdr);
    break;
    case _I_BYTEBOOZ11E:
    sprintf(appstr,"%s%s","Byte","Boozer");
    strcat(appstr," ");
    strcat(appstr,"v1.1");strcat(appstr,"E");
    printf(DEPMASK,appstr,Unp->DepAdr);
    break;
    case _I_LAMEBOOZER:
    sprintf(appstr,"%s%s","Lamer","Boozer");
    printf(DEPMASK,appstr,Unp->DepAdr);
    break;
    case _I_BYTECOMP:
    sprintf(appstr,"%s%s","Byte","Compactor");
    printf(DEPMASK,appstr,Unp->DepAdr);
    break;
    case _I_BYTEKILL:
    sprintf(appstr,"%s%s","Byte","Killer");
    printf(DEPMASK2,appstr,"v1.x",Unp->DepAdr);
    break;
    case _I_C4MRP:
    printf(DEPMASK,"C4MRP/RSi",Unp->DepAdr);
    break;
    case _I_CADGERS:
    printf(DEPMASK2,"Cadgers","Packer",Unp->DepAdr);
    break;
    case _I_CAUTION10:
    sprintf(appstr,"%s%s","Quick","Packer");
    printf(DEPMASK2,appstr,"v1.0",Unp->DepAdr);
    break;
    case _I_CAUTION25:
    sprintf(appstr,"%s%s","Quick","Packer");
    printf(DEPMASK2,appstr,"v2.5",Unp->DepAdr);
    break;
    case _I_CAUTION25SS:
    sprintf(appstr,"%s%s","Quick","Packer");strcat(appstr,"/sysless");
    printf(DEPMASK2,appstr,"v2.5",Unp->DepAdr);
    break;
    case _I_CAUTION20:
    sprintf(appstr,"%s%s","Quick","Packer");
    printf(DEPMASK2,appstr,"v2.0",Unp->DepAdr);
    break;
    case _I_CAUTION20SS:
    sprintf(appstr,"%s%s","Quick","Packer");strcat(appstr,"/sysless");
    printf(DEPMASK2,appstr,"v2.0",Unp->DepAdr);
    break;
    case _I_CAUTIONHP:
    sprintf(appstr,"%s%s","Hard","Packer");
    printf(DEPMASK2,appstr,"v1.0",Unp->DepAdr);
    break;
    case _I_CCSMAXS:
    printf(DEPMASK2,"CCS","MaxShorter",Unp->DepAdr);
    break;
    case _I_CCSBITTOS1:
    sprintf(appstr,"%s %s","CCS","Bittos");
    printf(DEPMASK2,appstr,"v1.0",Unp->DepAdr);
    break;
    case _I_CCSBITTOS4:
    sprintf(appstr,"%s %s","CCS","Bittos");
    printf(DEPMASK2,appstr,"v4.0",Unp->DepAdr);
    break;
    case _I_CCSPACK:
    sprintf(appstr,"%s %s","Executer","Packer");
    printf(DEPMASK2,"CCS",appstr,Unp->DepAdr);
    break;
    case _I_CCSSCRE:
    sprintf(appstr,"%s %s","CCS","ScreenShorter");
    printf(DEPMASK2,appstr,"v1.0",Unp->DepAdr);
    break;
    case _I_CCSSPEC:
    printf(DEPMASK2,"CCS","Special",Unp->DepAdr);
    break;
    case _I_CCSEXEC:
    printf(DEPMASK2,"CCS","Executer",Unp->DepAdr);
    break;
    case _I_CCSUNKN:
    printf(DEPMASK2,"CCS","Unknown",Unp->DepAdr);
    break;
    case _I_CCSHACK:
    sprintf(appstr,"%s %s","MaxShorter","Hack");
    printf(DEPMASK2,"CCS",appstr,Unp->DepAdr);
    break;
    case _I_CELERIP:
    printf(DEPMASK,"CeleriPack",Unp->DepAdr);
    break;
    case _I_CFBCOD1:
    sprintf(appstr,"%s %s","CFB","Coder");
    printf(DEPMASK2,appstr,"v1.x",Unp->DepAdr);
    break;
    case _I_CFBCOD2:
    sprintf(appstr,"%s %s","CFB","Coder");
    printf(DEPMASK2,appstr,"v2.x",Unp->DepAdr);
    break;
    case _I_CRUEL22:
    printf(DEPMASK2,"CruelCrunch","v2.2",Unp->DepAdr);
    break;
    case _I_CRUEL2MHZ:
    sprintf(appstr,"%s / %s","v2.2+","2MHZ");
    printf(DEPMASK2,"CruelCrunch",appstr,Unp->DepAdr);
    break;
    case _I_CRUELFAST2:
    sprintf(appstr,"%s / %s","v2.5","fast");
    printf(DEPMASK2,"CruelCrunch",appstr,Unp->DepAdr);
    break;
    case _I_CRUELFAST4:
    sprintf(appstr,"%s / %s","v4.0","fast");
    printf(DEPMASK2,"CruelCrunch",appstr,Unp->DepAdr);
    break;
    case _I_CRUEL_X  :
    printf(DEPMASK2,"CruelCrunch","vx.x",Unp->DepAdr);
    break;
    case _I_CRUELMS15:
    printf(DEPMASK2,"MSCrunch","v1.5",Unp->DepAdr);
    break;
    case _I_CRUELMS10:
    printf(DEPMASK2,"MSCrunch","v1.0",Unp->DepAdr);
    break;
    case _I_CRUELMS1X:
    printf(DEPMASK2,"MSCrunch","v1.x",Unp->DepAdr);
    break;
    case _I_CRUELMS_U:
    printf(DEPMASK2,"MSCrunch","Unknown",Unp->DepAdr);
    break;
    case _I_CRUMSABS:
    sprintf(appstr,"%s / %s","v1.5","ABS");
    printf(DEPMASK2,"MSCrunch",appstr,Unp->DepAdr);
    break;
    case _I_CRUEL_HDR:
    sprintf(appstr,"%s / %s","CruelCrunch","header");
    printf(DEPMASK,appstr,Unp->DepAdr);
    break;
    case _I_CRUEL_H22:
    sprintf(appstr,"%s / %s","CruelCrunch","header");
    printf(DEPMASK2,appstr,"v2.2",Unp->DepAdr);
    break;
    case _I_CRUEL_H20:
    sprintf(appstr,"%s / %s","CruelCrunch","header");
    printf(DEPMASK2,appstr,"v2.0",Unp->DepAdr);
    break;
    case _I_CRUEL_HTC:
    sprintf(appstr,"%s / %s","CruelCrunch","header");
    printf(DEPMASK2,appstr,"TCOM",Unp->DepAdr);
    break;
    case _I_CRUEL20:
    printf(DEPMASK2,"CruelCrunch","v2.0",Unp->DepAdr);
    break;
    case _I_CRUEL21:
    printf(DEPMASK2,"CruelCrunch","v2.1",Unp->DepAdr);
    break;
    case _I_CRUEL_ILS:
    sprintf(appstr,"%s / %s","v2.x","ILS");
    printf(DEPMASK2,"CruelCrunch",appstr,Unp->DepAdr);
    break;
    case _I_CRUEL_RND:
    sprintf(appstr,"%s / %s","v2.x","RND");
    printf(DEPMASK2,"CruelCrunch",appstr,Unp->DepAdr);
    break;
    case _I_CRUEL10:
    printf(DEPMASK2,"CruelCrunch","v1.0",Unp->DepAdr);
    break;
    case _I_CRUEL12:
    printf(DEPMASK2,"CruelCrunch","v1.2",Unp->DepAdr);
    break;
    case _I_CRUEL14:
    sprintf(appstr,"%s / %s","v1.4","Light");
    printf(DEPMASK2,"CruelCrunch",appstr,Unp->DepAdr);
    break;
    case _I_CRUEL_TKC:
    sprintf(appstr,"%s / %s","v2.3","TKC");
    printf(DEPMASK2,"CruelCrunch",appstr,Unp->DepAdr);
    break;
    case _I_TABOOCRUSH:
    printf(DEPMASK2,"Crush","/ Taboo",Unp->DepAdr);
    break;
    case _I_TABOOCRNCH:
    sprintf(appstr,"%s %s","Unknown","Cruncher");
    printf(DEPMASK2,appstr,"/ Taboo",Unp->DepAdr);
    break;
    case _I_TABOOPACK:
    sprintf(appstr,"%s %s","Unknown","Packer");
    printf(DEPMASK2,appstr,"/ Taboo",Unp->DepAdr);
    break;
    case _I_TABOOPACK64:
    sprintf(appstr,"%s %s","Packer","64");
    printf(DEPMASK2,appstr,"/ Taboo",Unp->DepAdr);
    break;
    case _I_CNOACK:
    sprintf(appstr,"%s %s","Chris Noack","Mega");
    strcat(appstr," ");strcat(appstr,"Byte");
    printf(DEPMASK2,appstr,"Packer",Unp->DepAdr);
    break;
    case _I_CNOACKLXT:
    sprintf(appstr,"%s %s","Chris Noack","Packer");
    printf(DEPMASK2,appstr,"/ Laxity",Unp->DepAdr);
    break;
    case _I_DARKSQ08  :
    printf(DEPMASK2,"DarkSqueezer","v0.8",Unp->DepAdr);
    break;
    case _I_DARKSQ21  :
    printf(DEPMASK2,"DarkSqueezer","v2.1",Unp->DepAdr);
    break;
    case _I_DARKSQ2X  :
    printf(DEPMASK2,"DarkSqueezer","v2.x",Unp->DepAdr);
    break;
    case _I_DARKSQ4   :
    printf(DEPMASK2,"DarkSqueezer","v4.x",Unp->DepAdr);
    break;
    case _I_DARKSQF4  :
    sprintf(appstr,"%s / %s","DarkSqueezer","F4CG");
    printf(DEPMASK,appstr,Unp->DepAdr);
    break;
    case _I_DARKSQXTC :
    sprintf(appstr,"%s / %s","DarkSqueezer","XTC");
    printf(DEPMASK,appstr,Unp->DepAdr);
    break;
    case _I_DARKSQWOW:
    sprintf(appstr,"%s / %s","DarkSqueezer","Darkfiler");
    printf(DEPMASK2,appstr,"v1.0",Unp->DepAdr);
    break;
    case _I_DARKSQGP  :
    sprintf(appstr,"%s / %s","DarkSqueezer","G*P");
    printf(DEPMASK,appstr,Unp->DepAdr);
    break;
    case _I_DARKSQDOM  :
    sprintf(appstr,"%s / %s","DarkSqueezer","DOM");
    printf(DEPMASK,appstr,Unp->DepAdr);
    break;
    case _I_DARKSQPAR  :
    sprintf(appstr,"%s / %s","DarkSqueezer","Paradroid");
    printf(DEPMASK,appstr,Unp->DepAdr);
    break;
    case _I_DARKSQ4SHK :
    sprintf(appstr,"%s / %s","DarkSqueezer","Sharks");
    printf(DEPMASK,appstr,Unp->DepAdr);
    break;
    case _I_DARKSQ22:
    printf(DEPMASK2,"DarkSqueezer","v2.2",Unp->DepAdr);
    break;
    case _I_DARKSQBB1 :
    sprintf(appstr,"%s / %s","DarkSqueezer","ByteBonker");
    printf(DEPMASK,appstr,Unp->DepAdr);
    break;
    case _I_DARKSQBB2 :
    sprintf(appstr,"%s / %s","DarkSqueezer","ByteBonker");
    printf(DEPMASK2,appstr,"v2.x",Unp->DepAdr);
    break;
    case _I_DDINTROC :
    printf(DEPMASK2,"DD Intro","Coder",Unp->DepAdr);
    break;
    case _I_DSCCOD :
    printf(DEPMASK2,"DSCompware","Coder",Unp->DepAdr);
    break;
    case _I_EASTLINK :
    printf(DEPMASK2,"East","Linker",Unp->DepAdr);
    break;
    case _I_ECA:
    strcpy(appstr,"Compactor");strcat(appstr,"/");strcat(appstr,"Linker");
    printf(DEPMASK2,"ECA",appstr,Unp->DepAdr);
    break;
    case _I_ECAOLD:
    printf(DEPMASK2,"ECA","/ old?",Unp->DepAdr);
    break;
    case _I_ENIGMAMFFL:
    printf(DEPMASK,"Enigma MFFL",Unp->DepAdr);
    break;
    case _I_EQBYTEC12:
    sprintf(appstr,"%s %s","Equal Byte","Compressor");
    printf(DEPMASK2,appstr,"v1.2",Unp->DepAdr);
    break;
    case _I_EQBYTEC14:
    sprintf(appstr,"%s %s","Equal Byte","Compressor");
    printf(DEPMASK2,appstr,"v1.4",Unp->DepAdr);
    break;
    case _I_EQBYTEC17:
    sprintf(appstr,"%s %s","Equal Byte","Compressor");
    printf(DEPMASK2,appstr,"v1.7",Unp->DepAdr);
    break;
    case _I_EQBYTEC19:
    sprintf(appstr,"%s %s","Equal Byte","Compressor");
    printf(DEPMASK2,appstr,"v1.9",Unp->DepAdr);
    break;
    case _I_EQBYTEC19TAL:
    sprintf(appstr,"%s %s","Equal Byte","Compressor");
    printf(DEPMASK2,appstr,"v1.9/TAL",Unp->DepAdr);
    break;
    case _I_EXOM:
    printf(DEPMASK,"Exomizer",Unp->DepAdr);
    break;
    case _I_EXOM3:
    printf(DEPMASK2,"Exomizer","v3.0",Unp->DepAdr);
    break;
    case _I_EXOM302:
    printf(DEPMASK2,"Exomizer","v3.02+",Unp->DepAdr);
    break;
    case _I_EXPERT1X:
    printf(DEPMASK2,"Trilogic Expert","v1.x",Unp->DepAdr);
    break;
    case _I_EXPERT27:
    printf(DEPMASK2,"Trilogic Expert","v2.7",Unp->DepAdr);
    break;
    case _I_EXPERT29:
    printf(DEPMASK2,"Trilogic Expert","v2.9",Unp->DepAdr);
    break;
    case _I_EXPERT29EUC:
    strcpy(appstr,"v2.9");strcat(appstr,"a/EUC");
    printf(DEPMASK2,"Trilogic Expert",appstr,Unp->DepAdr);
    break;
    case _I_EXPERT2X:
    printf(DEPMASK2,"Trilogic Expert","v2.x",Unp->DepAdr);
    break;
    case _I_EXPERT20:
    printf(DEPMASK2,"Trilogic Expert","v2.0",Unp->DepAdr);
    break;
    case _I_EXPERT21:
    strcpy(appstr,"v2.1");strcat(appstr,"0MMC");
    printf(DEPMASK2,"Trilogic Expert",appstr,Unp->DepAdr);
    break;
    case _I_EXPERT4X:
    printf(DEPMASK2,"Trilogic Expert","v4.x",Unp->DepAdr);
    break;
    case _I_EXPERT3X:
    printf(DEPMASK2,"Trilogic Expert","v3.x",Unp->DepAdr);
    break;
    case _I_EXPERTASS:
    sprintf(appstr,"%s / %s","Trilogic Expert","ASS");
    printf(DEPMASK,appstr,Unp->DepAdr);
    break;
    case _I_EXPERT211:
    printf(DEPMASK2,"Trilogic Expert","v2.11",Unp->DepAdr);
    break;
    case _I_EXPERTTS1:
    sprintf(appstr,"%s / %s","Trilogic Expert","Trigsoft");
    printf(DEPMASK,appstr,Unp->DepAdr);
    break;
    case _I_EXPERTSTAR:
    sprintf(appstr,"%s / %s","StarExpert","Fast Freeze");
    printf(DEPMASK,appstr,Unp->DepAdr);
    break;
    case _I_EXPLCRUNCH1X:
    sprintf(appstr,"%s %s","Exploding","CruelCrunch"); appstr[15]=0;
    printf(DEPMASK2,appstr,"v2.6",Unp->DepAdr);
    break;
    case _I_EXPLCRUNCH2X:
    sprintf(appstr,"%s %s","Exploding","Cruncher");
    printf(DEPMASK2,appstr,"v2.x",Unp->DepAdr);
    break;
    case _I_EXPLCRUNCH21:
    sprintf(appstr,"%s %s","Exploding","Cruncher");
    printf(DEPMASK2,appstr,"v2.1",Unp->DepAdr);
    break;
    case _I_EXPLCRUNCH22:
    sprintf(appstr,"%s %s","Exploding","Cruncher");
    printf(DEPMASK2,appstr,"v2.2",Unp->DepAdr);
    break;
    case _I_EXPLCOD:
    printf(DEPMASK2,"Exploding","Coder",Unp->DepAdr);
    break;
    case _I_EXPLFAC1    :
    sprintf(appstr,"%s %s","Exploding","Faces");
    printf(DEPMASK2,appstr,"v1.x",Unp->DepAdr);
    break;
    case _I_EXPLFAC2    :
    sprintf(appstr,"%s %s","Exploding","Faces");
    printf(DEPMASK2,appstr,"v2.x",Unp->DepAdr);
    break;
    case _I_XRPOWC71    :
    sprintf(appstr,"%s %s","PowerCrunch","v7.1");
    printf(DEPMASK2,"X-Rated",appstr,Unp->DepAdr);
    break;
    case _I_XREXPLCR    :
    sprintf(appstr,"%s %s","Exploding","Cruncher");
    printf(DEPMASK2,"X-Rated",appstr,Unp->DepAdr);
    break;
    case _I_XRPOWC74    :
    sprintf(appstr,"%s %s","PowerCrunch","v7.4");
    printf(DEPMASK2,"X-Rated",appstr,Unp->DepAdr);
    break;
    case _I_FACEPACK10:
    strcpy(appstr,"Face");strcat(appstr,"Packer");
    printf(DEPMASK2,appstr,"v1.0",Unp->DepAdr);
    break;
    case _I_FACEPACK11:
    strcpy(appstr,"Face");strcat(appstr,"Packer");
    printf(DEPMASK2,appstr,"v1.1",Unp->DepAdr);
    break;
    case _I_FC3PACK:
    sprintf(appstr,"%s %s","FinalCart","III");
    printf(DEPMASK2,appstr,"Packer",Unp->DepAdr);
    break;
    case _I_FC3LD:
    sprintf(appstr,"%s %s","FinalCart","III");
    printf(DEPMASK2,appstr,"Split Freeze",Unp->DepAdr);
    break;
    case _I_FC2LD:
    sprintf(appstr,"%s %s","FinalCart","II");
    printf(DEPMASK2,appstr,"Split Freeze",Unp->DepAdr);
    break;
    case _I_FCU1LD:
    sprintf(appstr,"%s %s","FinalCart","v1.?");
    printf(DEPMASK2,appstr,"Split Freeze",Unp->DepAdr);
    break;
    case _I_FCULD:
    sprintf(appstr,"%s %s","FinalCart","Unknown");
    printf(DEPMASK2,appstr,"Split Freeze",Unp->DepAdr);
    break;
    case _I_FCGPACK10:
    sprintf(appstr,"%s %s","FCG","Packer");
    printf(DEPMASK2,appstr,"v1.0",Unp->DepAdr);
    break;
    case _I_FCGPACK30:
    sprintf(appstr,"%s %s","FCG","Packer");
    printf(DEPMASK2,appstr,"v3.0",Unp->DepAdr);
    break;
    case _I_FCGPACK12:
    sprintf(appstr,"%s %s","FCG","Packer");
    printf(DEPMASK2,appstr,"v1.2",Unp->DepAdr);
    break;
    case _I_FCGPACK13:
    sprintf(appstr,"%s %s","FCG","Packer");
    printf(DEPMASK2,appstr,"v1.3",Unp->DepAdr);
    break;
    case _I_FCGLINK:
    printf(DEPMASK2,"FCG","Linker",Unp->DepAdr);
    break;
    case _I_TFGPACK:
    printf(DEPMASK2,"TFG","Packer",Unp->DepAdr);
    break;
    case _I_TFGCODE:
    printf(DEPMASK2,"TFG","Coder",Unp->DepAdr);
    break;
    case _I_TMCULINK:
    sprintf(appstr,"%s %s","Ultimate","Linker");
    printf(DEPMASK2,"TMC",appstr,Unp->DepAdr);
    break;
    case _I_FCGCODER:
    printf(DEPMASK2,"FCG","Coder",Unp->DepAdr);
    break;
    case _I_HLEISEP:
    printf(DEPMASK2,"H.Leise","Protector",Unp->DepAdr);
    break;
    case _I_FCGPROT:
    sprintf(appstr,"%s %s","Checksum","Protector");
    printf(DEPMASK2,"FCG",appstr,Unp->DepAdr);
    break;
    case _I_EXPROT:
    strcpy(appstr,"Ex");strcat(appstr,"Protector");appstr[9]=0;
    printf(DEPMASK2,"FCG",appstr,Unp->DepAdr);
    break;
    case _I_FLSPROT33:
    sprintf(appstr,"%s %s","Flash","Protector");
    printf(DEPMASK2,appstr,"v3.3",Unp->DepAdr);
    break;
    case _I_FCCPROT:
    printf(DEPMASK2,"FCC","Protector",Unp->DepAdr);
    break;
    case _I_FDTCOD:
    printf(DEPMASK2,"FDT","Coder",Unp->DepAdr);
    break;
    case _I_FCOMPMTB:
    strcpy(appstr,"File");strcat(appstr,"Compactor");
    printf(DEPMASK2,appstr,"I/MTB",Unp->DepAdr);
    break;
    case _I_FCOMPTMC:
    sprintf(appstr,"%s %s","/ Flexible"+2,"Code");
    printf(DEPMASK2,appstr,"Compactor",Unp->DepAdr);
    break;
    case _I_FCOMPMTC:
    printf(DEPMASK2,"MeanTeam","Cruncher",Unp->DepAdr);
    break;
    case _I_FCOMPK2:
    sprintf(appstr,"%s %s","/ Flexible"+2,"Code");
    strcat(appstr," "); strcat(appstr,"Compactor");
    printf(DEPMASK2,appstr,"v2.x",Unp->DepAdr);
    break;
    case _I_FCOMPSYS3:
    sprintf(appstr,"%s %s","/ Flexible"+2,"Code");
    strcat(appstr," "); strcat(appstr,"Compactor");
    printf(DEPMASK2,appstr,"v3.x",Unp->DepAdr);
    break;
    case _I_FINCOMP:
    printf(DEPMASK2,"Final","Compactor",Unp->DepAdr);
    break;
    case _I_SUPCOMFLEX:
    sprintf(appstr,"%s %s","Super","Compressor");
    printf(DEPMASK2,appstr,"/ Flexible",Unp->DepAdr);
    break;
    case _I_SUPCOMEQSE:
    sprintf(appstr,"%s %s","Super","Compressor");
    printf(DEPMASK2,appstr,"/ Equal sequences",Unp->DepAdr);
    break;
    case _I_SUPCOMEQB9:
    sprintf(appstr,"%s %s","Super","Compressor");
    strcat(appstr," "); strcat(appstr,"/ Equal sequences");
    printf(DEPMASK2,appstr,"Hack",Unp->DepAdr);
    break;
    case _I_SUPCOMEQCCS:
    sprintf(appstr,"%s %s","Super","Compressor");
    strcat(appstr," "); strcat(appstr,"/ Equal sequences");
    printf(DEPMASK2,appstr,"CCS",Unp->DepAdr);
    break;
    case _I_SUPCOMEQC9:
    sprintf(appstr,"%s %s","Super","Compressor");
    strcat(appstr," "); strcat(appstr,"/ Equal chars");
    printf(DEPMASK2,appstr,"Hack",Unp->DepAdr);
    break;
    case _I_SUPCOMEQCH:
    sprintf(appstr,"%s %s","Super","Compressor");
    printf(DEPMASK2,appstr,"/ Equal chars",Unp->DepAdr);
    break;
    case _I_SUPCOMFH11:
    sprintf(appstr,"%s %s %s %c %s %c","Super","Compressor","Hack", '1',"layer",'1');
    printf(DEPMASK,appstr,Unp->DepAdr);
    break;
    case _I_SUPCOMFH12:
    sprintf(appstr,"%s %s %s %c %s %c","Super","Compressor","Hack", '1',"layer",'2');
    printf(DEPMASK,appstr,Unp->DepAdr);
    break;
    case _I_SUPCOMFH13:
    sprintf(appstr,"%s %s %s %c %s %c","Super","Compressor","Hack", '1',"layer",'3');
    printf(DEPMASK,appstr,Unp->DepAdr);
    break;
    case _I_SUPCOMFH21:
    sprintf(appstr,"%s %s %s %c %s %c","Super","Compressor","Hack", '2',"layer",'1');
    printf(DEPMASK,appstr,Unp->DepAdr);
    break;
    case _I_SUPCOMHACK:
    sprintf(appstr,"%s %s","Super","Compressor");
    strcat(appstr," "); strcat(appstr,"/ Flexible");
    printf(DEPMASK2,appstr,"Hack",Unp->DepAdr);
    break;
    case _I_FPCOD:
    printf(DEPMASK2,"FP","Coder",Unp->DepAdr);
    break;
    case _I_FROGPACK:
    printf(DEPMASK2,"Frog","Packer",Unp->DepAdr);
    break;
    case _I_FRONTPACK:
    printf(DEPMASK2,"Front","Packer",Unp->DepAdr);
    break;
    case _I_FXBYTEP:
    sprintf(appstr,"%s %s","FX","Bytepress");
    printf(DEPMASK,appstr,Unp->DepAdr);
    break;
    case _I_FXBP_BBSP:
    sprintf(appstr,"%s %s","/ BB","(Soundpacker)");
    printf(DEPMASK2,"FX Bytepress",appstr,Unp->DepAdr);
    break;
    case _I_FXBP_BB:
    printf(DEPMASK2,"FX Bytepress","/ BB",Unp->DepAdr);
    break;
    case _I_FXBP_JW:
    printf(DEPMASK2,"FX Bytepress","/ Jewels",Unp->DepAdr);
    break;
    case _I_FXBP_SN:
    printf(DEPMASK2,"FX Bytepress","/ Seen",Unp->DepAdr);
    break;
    case _I_FXBITST:
    printf(DEPMASK2,"FX","Bitstreamer",Unp->DepAdr);
    break;
    case _I_BITST11:
    printf(DEPMASK2,"Bitstreamer","v1.1",Unp->DepAdr);
    break;
    case _I_GALLEONEQ:
    printf(DEPMASK2,"Galleon","/ Equal chars",Unp->DepAdr);
    break;
    case _I_GALLCP35:
    sprintf(appstr,"%s %s","Galleon","Compactor");
    printf(DEPMASK2,appstr,"v3.5",Unp->DepAdr);
    break;
    case _I_GALLCP36:
    sprintf(appstr,"%s %s","Galleon","Compactor");
    printf(DEPMASK2,appstr,"v3.6",Unp->DepAdr);
    break;
    case _I_GALLCP37:
    sprintf(appstr,"%s %s","Galleon","Compactor");
    printf(DEPMASK2,appstr,"v3.7",Unp->DepAdr);
    break;
    case _I_GALLCP38:
    sprintf(appstr,"%s %s","Galleon","Compactor");
    printf(DEPMASK2,appstr,"v3.8",Unp->DepAdr);
    break;
    case _I_GALLCP39:
    sprintf(appstr,"%s %s","Galleon","Compactor");
    printf(DEPMASK2,appstr,"v3.9",Unp->DepAdr);
    break;
    case _I_GALLCP3X:
    sprintf(appstr,"%s %s","Galleon","Compactor");
    printf(DEPMASK2,appstr,"v3.x",Unp->DepAdr);
    break;
    case _I_GALLFW4C:
    printf(DEPMASK2,"Galleon","FW4C",Unp->DepAdr);
    break;
    case _I_GALLFW4C2:
    sprintf(appstr,"%s %s","Galleon","FW4C");
    printf(DEPMASK2,appstr,"v2.x",Unp->DepAdr);
    break;
    case _I_GALLFW4C3:
    sprintf(appstr,"%s %s","Galleon","FW4C");
    printf(DEPMASK2,appstr,"v3.0",Unp->DepAdr);
    break;
    case _I_GALLFW4C31:
    sprintf(appstr,"%s %s","Galleon","FW4C");
    printf(DEPMASK2,appstr,"v3.1",Unp->DepAdr);
    break;
    case _I_GALLBRPR:
    strcpy(appstr,"Byterapers");appstr[9]=0;
    printf(DEPMASK2,"Galleon",appstr,Unp->DepAdr);
    break;
    case _I_GALLU02:
    sprintf(appstr,"%s %s","Galleon","$02");
    printf(DEPMASK2,appstr,"Packer",Unp->DepAdr);
    break;
    case _I_GALLU100:
    sprintf(appstr,"%s %s","Galleon","$100");
    printf(DEPMASK2,appstr,"Packer",Unp->DepAdr);
    break;
    case _I_GALLWHOM1:
    sprintf(appstr,"%s %s","Galleon","Whom");
    strcat(appstr," ");strcat(appstr,"Packer");
    printf(DEPMASK2,appstr,"v1.0",Unp->DepAdr);
    break;
    case _I_GALLWHOM11:
    sprintf(appstr,"%s %s","Galleon","Whom");
    strcat(appstr," ");strcat(appstr,"Packer");
    printf(DEPMASK2,appstr,"v1.1",Unp->DepAdr);
    break;
    case _I_GALLWHOM2:
    sprintf(appstr,"%s %s","Galleon","Whom");
    strcat(appstr," ");strcat(appstr,"Packer");
    printf(DEPMASK2,appstr,"v2.x",Unp->DepAdr);
    break;
    case _I_GALLWHOM4:
    sprintf(appstr,"%s %s","Galleon","Whom");
    strcat(appstr," ");strcat(appstr,"Packer");
    printf(DEPMASK2,appstr,"v4.x",Unp->DepAdr);
    break;
    case _I_GALLWHOM4S:
    sprintf(appstr,"%s %s","Galleon","Whom");
    strcat(appstr," ");strcat(appstr,"Packer");
    strcat(appstr," ");strcat(appstr,"v4.x");strcat(appstr,"/sysless");
    printf(DEPMASK,appstr,Unp->DepAdr);
    break;
    case _I_GALLVEST:
    printf(DEPMASK,"Alvesta Link",Unp->DepAdr);
    break;
    case _I_GANDALF:
    printf(DEPMASK2,"Gandalf","Packer",Unp->DepAdr);
    break;
    case _I_GRAFFITY:
    printf(DEPMASK2,"Graffity","Packer",Unp->DepAdr);
    break;
    case _I_HAWK:
    printf(DEPMASK2,"Hawk","Packer",Unp->DepAdr);
    break;
    case _I_HTLCOD:
    printf(DEPMASK2,"HTL","Coder",Unp->DepAdr);
    break;
    case _I_IDT10:
    sprintf(appstr,"%s %s","Idiots","FX");
    strcat(appstr," ");strcat(appstr,"Packer");
    printf(DEPMASK2,appstr,"v1.0",Unp->DepAdr);
    break;
    case _I_IDTFX21:
    sprintf(appstr,"%s %s","Idiots","FX");
    strcat(appstr," ");strcat(appstr,"Packer");
    printf(DEPMASK2,appstr,"v2.1",Unp->DepAdr);
    break;
    case _I_IDTFX20:
    sprintf(appstr,"%s %s","Idiots","FX");
    strcat(appstr," ");strcat(appstr,"Packer");
    printf(DEPMASK2,appstr,"v2.0",Unp->DepAdr);
    break;
    case _I_GNTFX20:
    sprintf(appstr,"%s %s","Gentlemen","FX");
    strcat(appstr," ");strcat(appstr,"Packer");
    printf(DEPMASK2,appstr,"v2.0",Unp->DepAdr);
    break;
    case _I_GNTSTATP:
    sprintf(appstr,"%s %s","Gentlemen","Stat");
    printf(DEPMASK2,appstr,"Packer",Unp->DepAdr);
    break;
    case _I_EXCELCOD:
    printf(DEPMASK2,"Excell/Ikari","Coder",Unp->DepAdr);
    break;
    case _I_IKARICR:
    printf(DEPMASK2,"Ikari","Cruncher",Unp->DepAdr);
    break;
    case _I_ILSCOD:
    strcpy(appstr,"ILS");strcat(appstr,"/");strcat(appstr,"RND");
    printf(DEPMASK2,appstr,"Coder",Unp->DepAdr);
    break;
    case _I_IRELAX1:
    sprintf(appstr,"%s %s","Intro:","Relax");
    strcat(appstr,"-01");
    printf(DEPMASK,appstr,Unp->DepAdr);
    break;
    case _I_IRELAX2:
    sprintf(appstr,"%s %s","Intro:","Relax");
    strcat(appstr,"-02");
    printf(DEPMASK,appstr,Unp->DepAdr);
    break;
    case _I_IF4CG23:
    sprintf(appstr,"%s %s","Intro:","F4CG");
    strcat(appstr,"-23");
    printf(DEPMASK,appstr,Unp->DepAdr);
    break;
    case _I_ITRIAD1:
    sprintf(appstr,"%s %s","Intro:","Triad");
    strcat(appstr,"-01");
    printf(DEPMASK,appstr,Unp->DepAdr);
    break;
    case _I_ITRIAD2:
    sprintf(appstr,"%s %s","Intro:","Triad");
    strcat(appstr,"-02");
    printf(DEPMASK,appstr,Unp->DepAdr);
    break;
    case _I_ITRIAD5:
    sprintf(appstr,"%s %s","Intro:","Triad");
    strcat(appstr,"-05");
    printf(DEPMASK,appstr,Unp->DepAdr);
    break;
    case _I_IGP2:
    sprintf(appstr,"%s %s","Intro:","G*P");
    strcat(appstr,"-02");
    printf(DEPMASK,appstr,Unp->DepAdr);
    break;
    case _I_I711ID3:
    sprintf(appstr,"%s %s","711","IntroDesigner3");
    printf(DEPMASK2,"Intro:",appstr,Unp->DepAdr);
    break;
    case _I_IBN1872:
    printf(DEPMASK2,"Intro:","BN 1872",Unp->DepAdr);
    break;
    case _I_BN1872PK:
    printf(DEPMASK2,"BN 1872","Packer",Unp->DepAdr);
    break;
    case _I_IEXIKARI:
    sprintf(appstr,"%s %s","Intro:","Excell/Ikari");
    printf(DEPMASK,appstr,Unp->DepAdr);
    break;
    case _I_IIKARI06:
    sprintf(appstr,"%s %s","Intro:","Ikari");
    strcat(appstr,"-06");
    printf(DEPMASK,appstr,Unp->DepAdr);
    break;
    case _I_IFLT01:
    sprintf(appstr,"%s %s","Intro:","FLT");
    strcat(appstr,"-01");
    printf(DEPMASK,appstr,Unp->DepAdr);
    break;
    case _I_IS45109:
    sprintf(appstr,"%s %s","Intro:","S451");
    strcat(appstr,"-09");
    printf(DEPMASK,appstr,Unp->DepAdr);
    break;
    case _I_ISCN:
    sprintf(appstr,"%s %s", "Normal","Cruncher");
    printf(DEPMASK2,"ISC /",appstr,Unp->DepAdr);
    break;
    case _I_ISCP:
    printf(DEPMASK2,"ISC /","Packer",Unp->DepAdr);
    break;
    case _I_ISCBS:
    sprintf(appstr,"%s %s", "Bitstream","Cruncher");
    printf(DEPMASK2,"ISC /",appstr,Unp->DepAdr);
    break;
    case _I_ISEPIC:
    printf(DEPMASK,"IsePic",Unp->DepAdr);
    break;
    case _I_ISEPDD:
    sprintf(appstr,"%sker/DD","IsePic");
    printf(DEPMASK,appstr,Unp->DepAdr);
    break;
    case _I_ISEPCT1:
    sprintf(appstr,"Why %s/CT","IsePic");
    printf(DEPMASK2,appstr,"v1.x",Unp->DepAdr);
    break;
    case _I_ISEPCT2:
    sprintf(appstr,"Why %s/CT","IsePic");
    printf(DEPMASK2,appstr,"v2.x",Unp->DepAdr);
    break;
    case _I_ISEP7U1:
    sprintf(appstr,"Anti-%s / %s %s","IsePic", "7up","v1.x");
    printf(DEPMASK,appstr,Unp->DepAdr);
    break;
    case _I_ISEP7U2:
    sprintf(appstr,"Anti-%s / %s %s","IsePic", "7up","v2.x");
    printf(DEPMASK,appstr,Unp->DepAdr);
    break;
    case _I_ISEPGS1:
    sprintf(appstr,"Anti-%s / %s %s","IsePic", "GSS","v1.1");
    printf(DEPMASK,appstr,Unp->DepAdr);
    break;
    case _I_ISEPNC:
    strcpy(appstr,"Defroster");strcat(appstr,"/");strcat(appstr,"NC");
    printf(DEPMASK2,"IsePic",appstr,Unp->DepAdr);
    break;
    case _I_ISEPAMG:
    strcpy(appstr,"Defroster");strcat(appstr,"/");strcat(appstr,"Amigo");
    printf(DEPMASK2,"IsePic",appstr,Unp->DepAdr);
    break;
    case _I_ISEPGEN:
    printf(DEPMASK2,"Generic","IsePic",Unp->DepAdr);
    break;
    case _I_JAZOOCOD:
    printf(DEPMASK2,"Jazoo","Coder",Unp->DepAdr);
    break;
    case _I_JCTCR:
    printf(DEPMASK2,"JCT","Cruncher",Unp->DepAdr);
    break;
    case _I_JCTPACK:
    printf(DEPMASK2,"JCT","Packer",Unp->DepAdr);
    break;
    case _I_JOXCR:
    printf(DEPMASK2,"J0xstrap","Cruncher",Unp->DepAdr);
    break;
    case _I_KOMPSP:
    /* eq sequence 4.1A/4.3a */
    printf(DEPMASK2,"Kompressmaster","/ special",Unp->DepAdr);
    break;
    case _I_KOMP711:
    /* eq sequence 4.1B */
    sprintf(appstr,"%s / %s","Kompressmaster","711");
    printf(DEPMASK2,appstr,"Cruncher",Unp->DepAdr);
    break;
    case _I_KOMPBB:
    sprintf(appstr,"%s / %s","Kompressmaster","BB");
    printf(DEPMASK,appstr,Unp->DepAdr);
    break;
    case _I_KOMP71PS:
    /* packer after 4.1a/4.3a */
    sprintf(appstr,"%s %s","Kompressmaster","Packer");
    printf(DEPMASK2,appstr,"/ special",Unp->DepAdr);
    break;
    case _I_KOMP71P1:
    /* packer 4.3a */
    sprintf(appstr,"%s %s","Kompressmaster","Packer");
    printf(DEPMASK2,appstr,"v1.x",Unp->DepAdr);
    break;
    case _I_KOMP71P2:
    /* packer 4.1 */
    sprintf(appstr,"%s %s","Kompressmaster","Packer");
    printf(DEPMASK2,appstr,"v2.x",Unp->DepAdr);
    break;
    case _I_KONCINA:
    printf(DEPMASK2,"Koncina","Packer",Unp->DepAdr);
    break;
    case _I_LIGHTM:
    printf(DEPMASK,"Lightmizer",Unp->DepAdr);
    break;
    case _I_VISIOM63:
    printf(DEPMASK2,"Visiomizer","v6.3",Unp->DepAdr);
    break;
    case _I_VISIOM62:
    printf(DEPMASK2,"Visiomizer","v6.2",Unp->DepAdr);
    break;
    case _I_LSMODL:
    sprintf(appstr,"%s %s","Loadstar","Mod");
    printf(DEPMASK2,appstr,"Linker",Unp->DepAdr);
    break;
    case _I_LSPACK:
    printf(DEPMASK2,"Loadstar","Packer",Unp->DepAdr);
    break;
    case _I_LSLNK2:
    sprintf(appstr,"%s %s","Loadstar","Linker");
    printf(DEPMASK2,appstr,"v2.0",Unp->DepAdr);
    break;
    case _I_LSSTLNK:
    sprintf(appstr,"%s %s","Loadstar","Star");
    printf(DEPMASK2,appstr,"Linker",Unp->DepAdr);
    break;
    case _I_LOWCR:
    printf(DEPMASK2,"Low","Cruncher",Unp->DepAdr);
    break;
    case _I_LSTCOD1:
    sprintf(appstr,"%s %s","LST","Coder");
    printf(DEPMASK2,appstr,"v1.x",Unp->DepAdr);
    break;
    case _I_LSTCOD2:
    sprintf(appstr,"%s %s","LST","Coder");
    printf(DEPMASK2,appstr,"v2.x",Unp->DepAdr);
    break;
    case _I_LTSPACK:
    printf(DEPMASK2,"LTS","Packer",Unp->DepAdr);
    break;
    case _I_LZMPI1:
    printf(DEPMASK2,"LZMPi/MartinPiper","v1.x",Unp->DepAdr);
    break;
    case _I_LZMPI2:
    printf(DEPMASK2,"LZMPi/MartinPiper","v2.x",Unp->DepAdr);
    break;
    case _I_LZMPI3E:
    sprintf(appstr,"%s / %s","v3.x","E mode");
    printf(DEPMASK2,"LZMPi/MartinPiper",appstr,Unp->DepAdr);
    break;
    case _I_LZMPI3M:
    sprintf(appstr,"%s / %s","v3.x","M mode");
    printf(DEPMASK2,"LZMPi/MartinPiper",appstr,Unp->DepAdr);
    break;
    case _I_LZMPI3UM:
    sprintf(appstr,"%s / %s","v3.x","UM mode");
    printf(DEPMASK2,"LZMPi/MartinPiper",appstr,Unp->DepAdr);
    break;
    case _I_LZMPI3RM:
    sprintf(appstr,"%s / %s","v3.x","RM mode");
    printf(DEPMASK2,"LZMPi/MartinPiper",appstr,Unp->DepAdr);
    break;
    case _I_MASCHK:
    printf(DEPMASK,"MaschinenSprache-Kompressor",Unp->DepAdr);
    break;
    case _I_MASTCOMP:
    sprintf(appstr,"%s%s","Master","Compressor");
    printf(DEPMASK,appstr,Unp->DepAdr);
    break;
    case _I_MASTCRLX:
    sprintf(appstr,"%s%s","Master","Compressor");strcat(appstr," /");
    printf(DEPMASK2,appstr,"Relax",Unp->DepAdr);
    break;
    case _I_MASTCAGL:
    sprintf(appstr,"%s%s","Master","Compressor");strcat(appstr," /");
    printf(DEPMASK2,appstr,"Agile",Unp->DepAdr);
    break;
    case _I_MASTCHF:
    sprintf(appstr,"%s%s","Master","Compressor");strcat(appstr," ");
    strcat(appstr,"v3.5");strcat(appstr," /");
    printf(DEPMASK2,appstr,"Channel4",Unp->DepAdr);
    break;
    case _I_MATCHARP:
    sprintf(appstr,"%s%s","Char","Packer");
    printf(DEPMASK2,"Matcham",appstr,Unp->DepAdr);
    break;
    case _I_MATCBASP:
    sprintf(appstr,"%s%s","Basic","Packer");
    printf(DEPMASK2,"Matcham",appstr,Unp->DepAdr);
    break;
    case _I_MATCDNEQ:
    sprintf(appstr,"%s %s","Matcham","Denser");
    printf(DEPMASK2,appstr,"/ Equal chars",Unp->DepAdr);
    break;
    case _I_MATCDN25:
    sprintf(appstr,"%s %s","Matcham","Denser");
    printf(DEPMASK2,appstr,"/ 251",Unp->DepAdr);
    break;
    case _I_MATCDNFL:
    sprintf(appstr,"%s %s","Matcham","Denser");
    printf(DEPMASK2,appstr,"/ Flexible",Unp->DepAdr);
    break;
    case _I_MATCLNK2:
    sprintf(appstr,"%s %s","Matcham","Linker");
    printf(DEPMASK2,appstr,"/ 251",Unp->DepAdr);
    break;
    case _I_MATCFLEX:
    printf(DEPMASK2,"Matcham","Flexer",Unp->DepAdr);
    break;
    case _I_MCCCOMP:
    printf(DEPMASK2,"MC-Cracken","Compressor",Unp->DepAdr);
    break;
    case _I_MCTSS3  :
    printf(DEPMASK2,"TSS v3","(MC-CC hack)",Unp->DepAdr);
    break;
    case _I_MCTSSIP :
    printf(DEPMASK2,"TSS v3","IsePic",Unp->DepAdr);
    break;
    case _I_MCUNK   :
    printf(DEPMASK2,"Unknown","(MC-CC hack)",Unp->DepAdr);
    break;
    case _I_MCCRUSH3:
    printf(DEPMASK2,"Crusher v3.0","(MC-CC hack)",Unp->DepAdr);
    break;
    case _I_MCCOBRA :
    printf(DEPMASK2,"Cobra","(MC-CC hack)",Unp->DepAdr);
    break;
    case _I_MCCSCC  :
    printf(DEPMASK2,"SCC","(MC-CC hack)",Unp->DepAdr);
    break;
    case _I_MCCRYPT :
    printf(DEPMASK2,"MC-Cracken","Coder",Unp->DepAdr);
    break;
    case _I_MDGPACK:
    printf(DEPMASK2,"MDG","Packer",Unp->DepAdr);
    break;
    case _I_MBCR1:
    sprintf(appstr,"%s%s","Mega","Byte");
    strcat(appstr," ");
    strcat(appstr,"Cruncher");
    printf(DEPMASK2,appstr,"v1.x",Unp->DepAdr);
    break;
    case _I_MBCR2:
    sprintf(appstr,"%s%s","Mega","Byte");
    strcat(appstr," ");
    strcat(appstr,"Cruncher");
    printf(DEPMASK2,appstr,"v2.x",Unp->DepAdr);
    break;
    case _I_MEGCRBD:
    sprintf(appstr,"%s%s","Mega","Cruncher");
    printf(DEPMASK2,appstr,"/ BlackDuke",Unp->DepAdr);
    break;
    case _I_MEGCR23:
    sprintf(appstr,"%s%s","Mega","Cruncher");
    printf(DEPMASK2,appstr,"v2.3",Unp->DepAdr);
    break;
    case _I_MRCROSS1:
    printf(DEPMASK2,"Mr.Cross","v1.x",Unp->DepAdr);
    break;
    case _I_MRCROSS2:
    printf(DEPMASK2,"Mr.Cross","v2.x",Unp->DepAdr);
    break;
    case _I_MRDCR1:
    sprintf(appstr,"%s %s","Marauder","Cruncher");
    printf(DEPMASK2,appstr,"v1.x",Unp->DepAdr);
    break;
    case _I_MRDCRCOD1:
    sprintf(appstr,"%s %s","Marauder","Cruncher");
    strcat(appstr,"&");strcat(appstr,"Coder");
    printf(DEPMASK2,appstr,"v1.x",Unp->DepAdr);
    break;
    case _I_MRDLNK2:
    sprintf(appstr,"%s %s","Marauder","Linker");
    printf(DEPMASK2,appstr,"v2.x",Unp->DepAdr);
    break;
    case _I_GSSCO12:
    sprintf(appstr,"%s %s","GSS","Coder");
    printf(DEPMASK2,appstr,"v1.2",Unp->DepAdr);
    break;
    case _I_MRZPACK:
    printf(DEPMASK2,"Mr.Z","Packer",Unp->DepAdr);
    break;
    case _I_MSICR2:
    sprintf(appstr,"%s %s","MSI","Cruncher");
    printf(DEPMASK2,appstr,"v2.x",Unp->DepAdr);
    break;
    case _I_MSICR3:
    sprintf(appstr,"%s %s","MSI","Cruncher");
    printf(DEPMASK2,appstr,"v3.x",Unp->DepAdr);
    break;
    case _I_MSICOD:
    printf(DEPMASK2,"MSI","Coder",Unp->DepAdr);
    break;
    case _I_NECPACK:
    printf(DEPMASK2,"NEC","Packer",Unp->DepAdr);
    break;
    case _I_AUSTROV1:
    printf(DEPMASK2,"Austro-Comp","v1.0",Unp->DepAdr);
    break;
    case _I_AUSTROV2:
    printf(DEPMASK2,"Austro-Comp","v2.0",Unp->DepAdr);
    break;
    case _I_AUSTROE1:
    printf(DEPMASK2,"Austro-Comp","E1-J/Simons",Unp->DepAdr);
    break;
    case _I_AUSTRO88:
    printf(DEPMASK2,"AustroSpeed","88",Unp->DepAdr);
    break;
    case _I_BLITZCOM:
    printf(DEPMASK2,"Blitz","Compiler",Unp->DepAdr);
    break;
    case _I_AUSTRO_U:
    printf(DEPMASK2,"Austro/Blitz","Unknown",Unp->DepAdr);
    break;
    case _I_AUSTROS1:
    printf(DEPMASK2,"AustroSpeed","v1.0",Unp->DepAdr);
    break;
    case _I_AUSTROBL:
    printf(DEPMASK2,"Austro/Blitz","Compiler",Unp->DepAdr);
    break;
    case _I_PETSPEED:
    printf(DEPMASK2,"PetSpeed","Compiler",Unp->DepAdr);
    break;
    case _I_BASIC64 :
    printf(DEPMASK2,"Basic64","Compiler",Unp->DepAdr);
    break;
    case _I_BASICBS :
    printf(DEPMASK2,"BasicBoss","Compiler",Unp->DepAdr);
    break;
    case _I_SPEEDCM :
    printf(DEPMASK2,"Speed","Compiler",Unp->DepAdr);
    break;
    case _I_SPEEDY64:
    printf(DEPMASK2,"Speedy 64","Compiler",Unp->DepAdr);
    break;
    case _I_CC65    :
    printf(DEPMASK2,"CC65","Compiler",Unp->DepAdr);
    break;
    case _I_CC6522  :
    sprintf(appstr,"%s %s","CC65","v2.2");
    printf(DEPMASK2,appstr,"Compiler",Unp->DepAdr);
    break;
    case _I_CC65218 :
    sprintf(appstr,"%s %s","CC65","v2.18");
    printf(DEPMASK2,appstr,"Compiler",Unp->DepAdr);
    break;
    case _I_DTL64   :
    printf(DEPMASK2,"DTL-64","Compiler",Unp->DepAdr);
    break;
    case _I_LASERBAS:
    printf(DEPMASK2,"LaserBasic","Compiler",Unp->DepAdr);
    break;
    case _I_HYPRA   :
    printf(DEPMASK2,"Hypra","Compiler",Unp->DepAdr);
    break;
    case _I_POWERC :
    printf(DEPMASK2,"Power C","Compiler",Unp->DepAdr);
    break;
    case _I_ISEPICLD:
    printf(DEPMASK2,"IsePic","Loader",Unp->DepAdr);
    break;
    case _I_NSUPACK10:
    sprintf(appstr,"%s %s","NSU","Packer");
    printf(DEPMASK2,appstr,"v1.0",Unp->DepAdr);
    break;
    case _I_NSUPACK11:
    sprintf(appstr,"%s %s","NSU","Packer");
    printf(DEPMASK2,appstr,"v1.1",Unp->DepAdr);
    break;
    case _I_ONSPACK:
    printf(DEPMASK2,"ONS","Packer",Unp->DepAdr);
    break;
    case _I_OPTIMUS:
    printf(DEPMASK2,"Optimus","Packer",Unp->DepAdr);
    break;
    case _I_OPTIMH:
    printf(DEPMASK2,"Optimus","Hack",Unp->DepAdr);
    break;
    case _I_OUGCOD:
    printf(DEPMASK2,"OUG","Coder",Unp->DepAdr);
    break;
    case _I_P100:
    printf(DEPMASK2,"P100","Cruncher",Unp->DepAdr);
    break;
    case _I_PAKOPT:
    printf(DEPMASK2,"Packer","Optimizer",Unp->DepAdr);
    break;
    case _I_PITCOD:
    printf(DEPMASK2,"PIT","Coder",Unp->DepAdr);
    break;
    case _I_POLONCB:
    printf(DEPMASK2,"Polonus","Charblaster",Unp->DepAdr);
    break;
    case _I_POLONKR:
    sprintf(appstr,"%s %s","Krejzi","Packer");
    printf(DEPMASK2,"Polonus",appstr,Unp->DepAdr);
    break;
    case _I_POLONAM:
    sprintf(appstr,"%s %s","C64/+4/Amiga","Packer");
    printf(DEPMASK2,"Polonus",appstr,Unp->DepAdr);
    break;
    case _I_POLONEQ:
    printf(DEPMASK2,"Polonus","/ Equal chars",Unp->DepAdr);
    break;
    case _I_POLON4P:
    sprintf(appstr,"%s %s","$45c","Packer");
    printf(DEPMASK2,"Polonus",appstr,Unp->DepAdr);
    break;
    case _I_POLON101:
    sprintf(appstr,"%s %s","$101","Packer");
    printf(DEPMASK2,"Polonus",appstr,Unp->DepAdr);
    break;
    case _I_QRTPROT:
    printf(DEPMASK2,"Quartet","Protector",Unp->DepAdr);
    break;
    case _I_PUCRUNCH:
    printf(DEPMASK,"PUCrunch",Unp->DepAdr);
    break;
    case _I_PUCRUNCW:
    printf(DEPMASK2,"PUCrunch","/ wrap",Unp->DepAdr);
    break;
    case _I_PUCRUNCS:
    printf(DEPMASK2,"PUCrunch","/ short",Unp->DepAdr);
    break;
    case _I_PUCRUNCO:
    printf(DEPMASK2,"PUCrunch","/ old?",Unp->DepAdr);
    break;
    case _I_PUCRUNCG:
    printf(DEPMASK2,"PUCrunch","Generic Hack",Unp->DepAdr);
    break;
    case _I_PZWCOM:
    printf(DEPMASK2,"PZW","Compactor",Unp->DepAdr);
    break;
    case _I_RAPEQC:
    printf(DEPMASK2,"Rap","/ Equal chars",Unp->DepAdr);
    break;
    case _I_RLX3B:
    printf(DEPMASK2,"Relax","3-byter",Unp->DepAdr);
    break;
    case _I_RLXP2:
    sprintf(appstr,"%s %s","Relax","Packer");
    printf(DEPMASK2,appstr,"v2.x",Unp->DepAdr);
    break;
    case _I_SCRCR4:
    sprintf(appstr,"%s / %s","ScreenCrunch","2064");
    printf(DEPMASK,appstr,Unp->DepAdr);
    break;
    case _I_SCRCR6:
    sprintf(appstr,"%s / %s","ScreenCrunch","2066");
    printf(DEPMASK,appstr,Unp->DepAdr);
    break;
    case _I_SCRCRFCG:
    sprintf(appstr,"%s / %s","ScreenCrunch","FCG");
    printf(DEPMASK,appstr,Unp->DepAdr);
    break;
    case _I_S8PACK:
    printf(DEPMASK2,"Section8","Packer",Unp->DepAdr);
    break;
    case _I_CRMPACK:
    printf(DEPMASK2,"CRM","Packer",Unp->DepAdr);
    break;
    case _I_SHRPACK:
    printf(DEPMASK2,"Shurigen","Packer",Unp->DepAdr);
    break;
    case _I_SIRMPACK:
    strcpy(appstr,"Mini");strcat(appstr,"Packer");
    printf(DEPMASK2,"SIR",appstr,Unp->DepAdr);
    break;
    case _I_SIRMLINK:
    strcpy(appstr,"Master");strcat(appstr,"Linker");
    printf(DEPMASK2,"SIR",appstr,Unp->DepAdr);
    break;
    case _I_SIRCOMBIN1:
    sprintf(appstr,"%s %s","SIR","Combine");
    printf(DEPMASK2,appstr,"v1.x",Unp->DepAdr);
    break;
    case _I_SIRCOMBIN2:
    sprintf(appstr,"%s %s","SIR","Combine");
    printf(DEPMASK2,appstr,"v2.x",Unp->DepAdr);
    break;
    case _I_SIRCOMBIN3:
    sprintf(appstr,"%s %s","SIR","Combine");
    printf(DEPMASK2,appstr,"v3.x",Unp->DepAdr);
    break;
    case _I_SKLCOD:
    printf(DEPMASK2,"Skylight","Protector",Unp->DepAdr);
    break;
    case _I_SLEDGE10:
    printf(DEPMASK2,"SledgeHammer","v1.0",Unp->DepAdr);
    break;
    case _I_SLEDGE11:
    printf(DEPMASK2,"SledgeHammer","v1.1",Unp->DepAdr);
    break;
    case _I_SLEDGE12:
    printf(DEPMASK2,"SledgeHammer","v1.2",Unp->DepAdr);
    break;
    case _I_KREATOR:
    strcpy(appstr,"v1.0");
    strcat(appstr,"/");
    strcat(appstr,"Kreator");
    printf(DEPMASK2,"SledgeHammer",appstr,Unp->DepAdr);
    break;
    case _I_SLEDGE20:
    printf(DEPMASK2,"SledgeHammer","v2.0",Unp->DepAdr);
    break;
    case _I_SLEDGE21:
    printf(DEPMASK2,"SledgeHammer","v2.1",Unp->DepAdr);
    break;
    case _I_SLEDGE23:
    printf(DEPMASK2,"SledgeHammer","v2.3",Unp->DepAdr);
    break;
    case _I_SLEDGE24:
    printf(DEPMASK2,"SledgeHammer","v2.4",Unp->DepAdr);
    break;
    case _I_SLEDGE2C:
    strcpy(appstr,"v2.2");
    strcat(appstr,"/");
    strcat(appstr,"CCS");
    printf(DEPMASK2,"SledgeHammer",appstr,Unp->DepAdr);
    break;
    case _I_SLEDGETRAP:
    strcpy(appstr,"v2.x");
    strcat(appstr,"/");
    strcat(appstr,"Trap");
    printf(DEPMASK2,"SledgeHammer",appstr,Unp->DepAdr);
    break;
    case _I_SLEDGE22:
    printf(DEPMASK2,"SledgeHammer","v2.2",Unp->DepAdr);
    break;
    case _I_SLEDGE30:
    printf(DEPMASK2,"SledgeHammer","v3.0",Unp->DepAdr);
    break;
    case _I_ULTIM8SH:
    printf(DEPMASK2,"Ultimate","SledgeHammer",Unp->DepAdr);
    break;
    case _I_SLEDGE1DP:
    sprintf(appstr,"%s %s","Packer","v2");
    printf(DEPMASK2,"Dreamr",appstr,Unp->DepAdr);
    break;
    case _I_MWSPCOMP:
    sprintf(appstr,"%s%s","Speedi","Compactor");
    printf(DEPMASK2,"Winterberg",appstr,Unp->DepAdr);
    break;
    case _I_MWPACK:
    printf(DEPMASK2,"Winterberg","Packer",Unp->DepAdr);
    break;
    case _I_MWSPCR1:
    sprintf(appstr,"%s%s","Speedi","Cruncher");
    printf(DEPMASK2,appstr,"MW1",Unp->DepAdr);
    break;
    case _I_MWSPCR2:
    sprintf(appstr,"%s%s","Speedi","Cruncher");
    printf(DEPMASK2,appstr,"MW2",Unp->DepAdr);
    break;
    case _I_SUPCRUNCH:
    sprintf(appstr,"%s%s","Super","Cruncher");appstr[strlen(appstr)-2]=0;
    printf(DEPMASK,appstr,Unp->DepAdr);
    break;
    case _I_TBCMULTI:
    printf(DEPMASK,"TBC Multicompactor",Unp->DepAdr);
    break;
    case _I_TBCMULT2:
    printf(DEPMASK2,"TBC Multicompactor","v2.x",Unp->DepAdr);
    break;
    case _I_TBCMULTMOW:
    sprintf(appstr,"%s / %s","AutoBreakSystem","Manowar");
    printf(DEPMASK2,"TBC Multicompactor",appstr,Unp->DepAdr);
    break;
    case _I_TCDLC1:
    printf(DEPMASK2,"TCD Link&Crunch","v1.x",Unp->DepAdr);
    break;
    case _I_TCDLC2:
    printf(DEPMASK2,"TCD Link&Crunch","v2.x",Unp->DepAdr);
    break;
    case _I_TCSCR2:
    sprintf(appstr,"%s %s","TCS","Cruncher");
    printf(DEPMASK2,appstr,"v2.0",Unp->DepAdr);
    break;
    case _I_TCSCR3:
    sprintf(appstr,"%s %s","TCS","Cruncher");
    printf(DEPMASK2,appstr,"v3.0",Unp->DepAdr);
    break;
    case _I_TC40   :
    printf(DEPMASK2,"Time Cruncher","v4.0",Unp->DepAdr);
    break;
    case _I_TC42H  :
    sprintf(appstr,"%s / %s","v4.2","header");
    printf(DEPMASK2,"Time Cruncher",appstr,Unp->DepAdr);
    break;
    case _I_TC40HIL:
    sprintf(appstr,"%s / %s","v4.2","header");
    strcat(appstr," ");strcat(appstr,"ILS");
    printf(DEPMASK2,"Time Cruncher",appstr,Unp->DepAdr);
    break;
    case _I_TCHVIK:
    sprintf(appstr,"%s %s","Vikings","header");
    printf(DEPMASK2,"Time Cruncher",appstr,Unp->DepAdr);
    break;
    case _I_TC42   :
    printf(DEPMASK2,"Time Cruncher","v4.2",Unp->DepAdr);
    break;
    case _I_TC43   :
    printf(DEPMASK2,"Time Cruncher","v4.3",Unp->DepAdr);
    break;
    case _I_TC44   :
    printf(DEPMASK2,"Time Cruncher","v4.4",Unp->DepAdr);
    break;
    case _I_TC50   :
    printf(DEPMASK2,"Time Cruncher","v5.0",Unp->DepAdr);
    break;
    case _I_TC51   :
    printf(DEPMASK2,"Time Cruncher","v5.1",Unp->DepAdr);
    break;
    case _I_TC52   :
    printf(DEPMASK2,"Time Cruncher","v5.2",Unp->DepAdr);
    break;
    case _I_TC53   :
    printf(DEPMASK2,"Time Cruncher","v5.3",Unp->DepAdr);
    break;
    case _I_TC5GEN:
    sprintf(appstr,"%s / %s","v5.x","Generic Hack");
    printf(DEPMASK2,"Time Cruncher",appstr,Unp->DepAdr);
    break;
    case _I_TC30   :
    printf(DEPMASK2,"Time Cruncher","v3.0",Unp->DepAdr);
    break;
    case _I_TC31   :
    printf(DEPMASK2,"Time Cruncher","v3.1",Unp->DepAdr);
    break;
    case _I_TC31SP:
    sprintf(appstr,"%s / %s","v3.1","Speed");
    strcat(appstr,"Packer");
    printf(DEPMASK2,"Time Cruncher",appstr,Unp->DepAdr);
    break;
    case _I_TC31PLUS:
    sprintf(appstr,"%s%s","v3.1","+");
    printf(DEPMASK2,"Time Cruncher",appstr,Unp->DepAdr);
    break;
    case _I_TC33   :
    printf(DEPMASK2,"Time Cruncher","v3.3",Unp->DepAdr);
    break;
    case _I_TC2MHZ1:
    sprintf(appstr,"%s %s","2MHZ","v1.0");
    printf(DEPMASK2,"Time Cruncher",appstr,Unp->DepAdr);
    break;
    case _I_TC2MHZ2:
    sprintf(appstr,"%s %s","2MHZ","v2.0");
    printf(DEPMASK2,"Time Cruncher",appstr,Unp->DepAdr);
    break;
    case _I_TC32061:
    sprintf(appstr,"%s / %s","v3.x","2061");
    printf(DEPMASK2,"Time Cruncher",appstr,Unp->DepAdr);
    break;
    case _I_TCMC4  :
    printf(DEPMASK2,"Time Cruncher","/ MegaCrunch 4.0",Unp->DepAdr);
    break;
    case _I_TC3RAD :
    sprintf(appstr,"%s / %s","v3.x","Radical");
    printf(DEPMASK2,"Time Cruncher",appstr,Unp->DepAdr);
    break;
    case _I_TC32074:
    sprintf(appstr,"%s / %s","v3.x","2074");
    printf(DEPMASK2,"Time Cruncher",appstr,Unp->DepAdr);
    break;
    case _I_TC3FPE :
    sprintf(appstr,"%s / %s","v3.x","Fast Pack'Em ");
    strcat(appstr,"v2.1");
    printf(DEPMASK2,"Time Cruncher",appstr,Unp->DepAdr);
    break;
    case _I_TC3FBI :
    sprintf(appstr,"%s / %s","v3.x","FBI");
    printf(DEPMASK2,"Time Cruncher",appstr,Unp->DepAdr);
    break;
    case _I_TC3TRI :
    sprintf(appstr,"%s / %s","v3.x","Triumwyrat");
    printf(DEPMASK2,"Time Cruncher",appstr,Unp->DepAdr);
    break;
    case _I_TC3HTL :
    sprintf(appstr,"%s / %s","v3.x","HTL");
    printf(DEPMASK2,"Time Cruncher",appstr,Unp->DepAdr);
    break;
    case _I_TC3ENT :
    sprintf(appstr,"%s / %s","v3.x","Entropy");
    printf(DEPMASK2,"Time Cruncher",appstr,Unp->DepAdr);
    break;
    case _I_TCGENH :
    sprintf(appstr,"%s / %s","Time Cruncher","Generic Hack");
    printf(DEPMASK,appstr,Unp->DepAdr);
    break;
    case _I_TCFPEX :
    printf(DEPMASK,"File Press Expert",Unp->DepAdr);
    break;
    case _I_TCSIR1 :
    printf(DEPMASK2,"SIR Compact","v1.x",Unp->DepAdr);
    break;
    case _I_TCUNKH :
    printf(DEPMASK2,"Unknown","TC hack",Unp->DepAdr);
    break;
    case _I_TCSIR4 :
    printf(DEPMASK2,"SIR Compact","v4.x",Unp->DepAdr);
    break;
    case _I_TCSIR3 :
    printf(DEPMASK2,"SIR Compact","v3.x",Unp->DepAdr);
    break;
    case _I_TCSIR2 :
    printf(DEPMASK2,"SIR Compact","v2.x",Unp->DepAdr);
    break;
    case _I_TC5SC  :
    sprintf(appstr,"%s / %s","v5.x","SupraCompactor");
    printf(DEPMASK2,"Time Cruncher",appstr,Unp->DepAdr);
    break;
    case _I_TC3RLX :
    sprintf(appstr,"%s / %s","v3.x","Relax");
    printf(DEPMASK2,"Time Cruncher",appstr,Unp->DepAdr);
    break;
    case _I_TC33AD :
    sprintf(appstr,"%s / %s","v3.x","Triad");
    printf(DEPMASK2,"Time Cruncher",appstr,Unp->DepAdr);
    break;
    case _I_TC3PC :
    sprintf(appstr,"%s / %s","v3.x","PC");
    printf(DEPMASK2,"Time Cruncher",appstr,Unp->DepAdr);
    break;
    case _I_TC423AD:
    sprintf(appstr,"%s / %s","v4.2","Triad");
    printf(DEPMASK2,"Time Cruncher",appstr,Unp->DepAdr);
    break;
    case _I_TC42GEN:
    sprintf(appstr,"%s / %s","v4.2","Generic Hack");
    printf(DEPMASK2,"Time Cruncher",appstr,Unp->DepAdr);
    break;
    case _I_TC3TDF :
    sprintf(appstr,"%s / %s","v3.x","TDF");
    printf(DEPMASK2,"Time Cruncher",appstr,Unp->DepAdr);
    break;
    case _I_TC3ATC :
    sprintf(appstr,"%s / %s","v3.x","ATC");
    printf(DEPMASK2,"Time Cruncher",appstr,Unp->DepAdr);
    break;
    case _I_TC3F4CG:
    sprintf(appstr,"%s / %s","v3.x","F4CG");
    printf(DEPMASK2,"Time Cruncher",appstr,Unp->DepAdr);
    break;
    case _I_TC3HSCG:
    sprintf(appstr,"%s / %s","v3.x","HSCG");
    printf(DEPMASK2,"Time Cruncher",appstr,Unp->DepAdr);
    break;
    case _I_TC3HSFE:
    sprintf(appstr,"%s / %s","v3.x","HSCG");strcat(appstr,"+FE");
    printf(DEPMASK2,"Time Cruncher",appstr,Unp->DepAdr);
    break;
    case _I_TC3TTN :
    sprintf(appstr,"%s / %s","v3.x","Triton");
    printf(DEPMASK2,"Time Cruncher",appstr,Unp->DepAdr);
    break;
    case _I_TC3MULE:
    sprintf(appstr,"%s / %s","v3.x","Mule");
    printf(DEPMASK2,"Time Cruncher",appstr,Unp->DepAdr);
    break;
    case _I_TC3AGILE:
    sprintf(appstr,"%s / %s","v3.x","Agile");
    printf(DEPMASK2,"Time Cruncher",appstr,Unp->DepAdr);
    break;
    case _I_TC3S451:
    sprintf(appstr,"%s / %s","v3.1","S451");
    printf(DEPMASK2,"Time Cruncher",appstr,Unp->DepAdr);
    break;
    case _I_TC3S451V2:
    sprintf(appstr,"%s / %s","v3.2","S451");
    printf(DEPMASK2,"Time Cruncher",appstr,Unp->DepAdr);
    break;
    case _I_TC3IKARI:
    sprintf(appstr,"%s / %s","v3.x","Ikari");
    printf(DEPMASK2,"Time Cruncher",appstr,Unp->DepAdr);
    break;
    case _I_TC3U   :
    sprintf(appstr,"%s / %s","v3.x","Unknown");
    printf(DEPMASK2,"Time Cruncher",appstr,Unp->DepAdr);
    break;
    case _I_TMCCOD :
    printf(DEPMASK2,"TMC","Coder",Unp->DepAdr);
    break;
    case _I_TMMPACK:
    printf(DEPMASK2,"TMM","Packer",Unp->DepAdr);
    break;
    case _I_TRASHC1:
    printf(DEPMASK2,"Trashcan","v1.x",Unp->DepAdr);
    break;
    case _I_TRASHC2:
    printf(DEPMASK2,"Trashcan","v2.x",Unp->DepAdr);
    break;
    case _I_TRASHCU:
    printf(DEPMASK2,"Trashcan","Unknown",Unp->DepAdr);
    break;
    case _I_TRIANP:
    printf(DEPMASK2,"Trianon","Packer",Unp->DepAdr);
    break;
    case _I_TRIAN2:
    printf(DEPMASK2,"Trianon","v2.x",Unp->DepAdr);
    break;
    case _I_TRIAN3:
    printf(DEPMASK2,"Trianon","v3.x",Unp->DepAdr);
    break;
    case _I_TRIANC:
    printf(DEPMASK2,"Trianon","Cruncher",Unp->DepAdr);
    break;
    case _I_TSBP1:
    sprintf(appstr,"%s %s","TSB","Packer");
    printf(DEPMASK2,appstr,"v1.x",Unp->DepAdr);
    break;
    case _I_TSBP21:
    sprintf(appstr,"%s %s","TSB","Packer");
    printf(DEPMASK2,appstr,"v2.1",Unp->DepAdr);
    break;
    case _I_TSBP3:
    sprintf(appstr,"%s %s","TSB","Packer");
    printf(DEPMASK2,appstr,"v3.x",Unp->DepAdr);
    break;
    case _I_TSMCOD:
    sprintf(appstr,"%s %s","Lamer","Scrambler");
    printf(DEPMASK2,"TSM",appstr,Unp->DepAdr);
    break;
    case _I_TSMPACK:
    printf(DEPMASK2,"TSM","Packer",Unp->DepAdr);
    break;
    case _I_TURBOP:
    printf(DEPMASK2,"Turbo","Packer",Unp->DepAdr);
    break;
    case _I_ULTRAC3:
    printf(DEPMASK2,"UltraComp","v3.0",Unp->DepAdr);
    break;
    case _I_UNIPACK1:
    sprintf(appstr,"%s%s","Uni","Packer");
    printf(DEPMASK2,appstr,"v1.x",Unp->DepAdr);
    break;
    case _I_UNIPACK2:
    sprintf(appstr,"%s%s","Uni","Packer");
    printf(DEPMASK2,appstr,"v2.x",Unp->DepAdr);
    break;
    case _I_UNIPACK3:
    sprintf(appstr,"%s%s","Uni","Packer");
    printf(DEPMASK2,appstr,"v3.x",Unp->DepAdr);
    break;
    case _I_U_100_P2:
    sprintf(appstr,"%s %s","$100","Packer");
    strcat(appstr," ");strcat(appstr,"v2.x");
    printf(DEPMASK2,"Unknown",appstr,Unp->DepAdr);
    break;
    case _I_U_100_P3:
    sprintf(appstr,"%s %s","$100","Packer");
    strcat(appstr," ");strcat(appstr,"v3.x");
    printf(DEPMASK2,"Unknown",appstr,Unp->DepAdr);
    break;
    case _I_U_100_P4:
    sprintf(appstr,"%s %s","$100","Packer");
    strcat(appstr," ");strcat(appstr,"v4.x");
    printf(DEPMASK2,"Unknown",appstr,Unp->DepAdr);
    break;
    case _I_U_100_P5:
    sprintf(appstr,"%s %s","$100","Packer");
    strcat(appstr," ");strcat(appstr,"v5.x");
    printf(DEPMASK2,"Unknown",appstr,Unp->DepAdr);
    break;
    case _I_U_101:
    sprintf(appstr,"%s %s","$101","Packer");
    printf(DEPMASK2,"Unknown",appstr,Unp->DepAdr);
    break;
    case _I_U_111:
    sprintf(appstr,"%s %s","$111","Packer");
    printf(DEPMASK2,"Unknown",appstr,Unp->DepAdr);
    break;
    case _I_U_FD:
    sprintf(appstr,"%s %s","$fd","Packer");
    printf(DEPMASK2,"Unknown",appstr,Unp->DepAdr);
    break;
    case _I_ROWS:
    printf(DEPMASK2,"Rows","Cruncher",Unp->DepAdr);
    break;
    case _I_FALCOP:
    printf(DEPMASK2,"Falco Paul","Packer",Unp->DepAdr);
    break;
    case _I_PSQLINK1:
    sprintf(appstr,"%s %s","PSQ","Linker");
    printf(DEPMASK2,appstr,"v3.1",Unp->DepAdr);
    break;
    case _I_U_439:
    sprintf(appstr,"%s %s","$439","Packer");
    printf(DEPMASK2,"Unknown",appstr,Unp->DepAdr);
    break;
    case _I_ENTROPYPK:
    printf(DEPMASK2,"Entropy","Packer",Unp->DepAdr);
    break;
    case _I_U_8E:
    sprintf(appstr,"%s %s","$8e","Packer");
    printf(DEPMASK2,"Unknown",appstr,Unp->DepAdr);
    break;
    case _I_U_25:
    sprintf(appstr,"%s %s","$25","Packer");
    printf(DEPMASK2,"Unknown",appstr,Unp->DepAdr);
    break;
    case _I_DSCTITMK:
    printf(DEPMASK2,"DSCompware","Super-TitleMaker",Unp->DepAdr);
    break;
    case _I_DSCCR:
    printf(DEPMASK2,"DSCompware","Cruncher",Unp->DepAdr);
    break;
    case _I_DSCPK:
    printf(DEPMASK2,"DSCompware","Packer",Unp->DepAdr);
    break;
    case _I_DSCPK2:
    sprintf(appstr,"%s %s","DSCompware","Packer");
    printf(DEPMASK2,appstr,"v2.0",Unp->DepAdr);
    break;
    case _I_KRESS:
    printf(DEPMASK2,"Kress","Cruncher",Unp->DepAdr);
    break;
    case _I_U_1WF2:
    sprintf(appstr,"%s %s","$f2","Packer");
    printf(DEPMASK2,"Oneway",appstr,Unp->DepAdr);
    break;
    case _I_U_1WDA:
    sprintf(appstr,"%s %s","$da","Packer");
    printf(DEPMASK2,"Oneway",appstr,Unp->DepAdr);
    break;
    case _I_GENSYSL:
    printf("Generic SYS-less %s $%04x\n","Packer",Unp->Forced);
    break;
    case _I_U_P3:
    printf(DEPMASK2,"Unknown","P3",Unp->DepAdr);
    break;
    case _I_U_3ADCR:
    sprintf(appstr,"%s %s","Unknown","Triad");
    printf(DEPMASK2,appstr,"Cruncher",Unp->DepAdr);
    break;
    case _I_VIP1X:
    printf(DEPMASK2,"VIP","v1.x",Unp->DepAdr);
    break;
    case _I_VIP20:
    printf(DEPMASK2,"VIP","v2.0",Unp->DepAdr);
    break;
    case _I_TOTP1X:
    sprintf(appstr,"%s %s","Total","Packer");
    printf(DEPMASK2,appstr,"v1.x",Unp->DepAdr);
    break;
    case _I_TOTP20:
    sprintf(appstr,"%s %s","Total","Packer");
    printf(DEPMASK2,appstr,"v2.0",Unp->DepAdr);
    break;
    case _I_VIP3X:
    printf(DEPMASK2,"VIP","v3.x",Unp->DepAdr);
    break;
    case _I_HIT02:
    sprintf(appstr,"%s %s","HitMen","$02");
    printf(DEPMASK2,appstr,"Packer",Unp->DepAdr);
    break;
    case _I_HIT20:
    sprintf(appstr,"%s %s","HitMen","$20");
    printf(DEPMASK2,appstr,"Linker",Unp->DepAdr);
    break;
    case _I_AGNUS02:
    sprintf(appstr,"%s %s","Agnus","$02");
    printf(DEPMASK2,appstr,"Packer",Unp->DepAdr);
    break;
    case _I_BUK02:
    sprintf(appstr,"%s %s","Buraki","$02");
    printf(DEPMASK2,appstr,"Packer",Unp->DepAdr);
    break;
    case _I_WARLOCK:
    printf(DEPMASK2,"Warlock","Packer",Unp->DepAdr);
    break;
    case _I_WCCMC:
    printf(DEPMASK2,"WCC","Modem Converter",Unp->DepAdr);
    break;
    case _I_WDRPROT:
    sprintf(appstr,"%s %s","Soft","Protector");
    printf(DEPMASK2,"WDR",appstr,Unp->DepAdr);
    break;
    case _I_WDRLAMEK:
    sprintf(appstr,"%s %s","Lamer","Killer");
    printf(DEPMASK2,"WDR",appstr,Unp->DepAdr);
    break;
    case _I_WGICOD:
    printf(DEPMASK2,"WGI","Coder",Unp->DepAdr);
    break;
    case _I_3CZIP:
    printf(DEPMASK2,"3Code","Zipper",Unp->DepAdr);
    break;
    case _I_4CZIP:
    sprintf(appstr,"%s %s","Zipper","v2.0");
    printf(DEPMASK2,"4Code",appstr,Unp->DepAdr);
    break;
    case _I_4CZIP2S:
    sprintf(appstr,"%s %s","Zipper","v2.S");
    printf(DEPMASK2,"4Code",appstr,Unp->DepAdr);
    break;
    case _I_XTERM:
    sprintf(appstr,"%s %s","X-Terminator","v2.0");strcat(appstr," /");
    printf(DEPMASK2,appstr,"FLT",Unp->DepAdr);
    break;
    case _I_ILSCOMP3X:
    sprintf(appstr,"%s %s","ILS","Compacker");
    printf(DEPMASK2,appstr,"v3.x",Unp->DepAdr);
    break;
    case _I_ILSCOMP2X:
    sprintf(appstr,"%s %s","ILS","Compacker");
    printf(DEPMASK2,appstr,"v2.x",Unp->DepAdr);
    break;
    case _I_UPACK2:
    sprintf(appstr,"%s%s","U-","Packer");
    printf(DEPMASK2,appstr,"II",Unp->DepAdr);
    break;
    case _I_XDSV1:
    sprintf(appstr,"%s %s","XDS","Coder");
    printf(DEPMASK2,appstr,"v1.0",Unp->DepAdr);
    break;
    case _I_XDSV2:
    sprintf(appstr,"%s %s","XDS","Coder");
    printf(DEPMASK2,appstr,"v2.0",Unp->DepAdr);
    break;
    case _I_XDSV3:
    sprintf(appstr,"%s %s","XDS","Coder");
    printf(DEPMASK2,appstr,"v3.0",Unp->DepAdr);
    break;
    case _I_XDSK1:
    sprintf(appstr,"%s %s","XDS","Coder");
    printf(DEPMASK2,appstr,"K1",Unp->DepAdr);
    break;break;
    case _I_XDSK2:
    sprintf(appstr,"%s %s","XDS","Coder");
    printf(DEPMASK2,appstr,"K2",Unp->DepAdr);
    break;
    case _I_XDSK3:
    sprintf(appstr,"%s %s","XDS","Coder");
    printf(DEPMASK2,appstr,"K3",Unp->DepAdr);
    break;
    case _I_XIP:
    printf(DEPMASK,"XIP",Unp->DepAdr);
    break;
    case _I_XTC10:
    sprintf(appstr,"%s %s","XTC","Packer");
    printf(DEPMASK2,appstr,"v1.0",Unp->DepAdr);
    break;
    case _I_XTC21:
    sprintf(appstr,"%s %s","XTC","Packer");
    printf(DEPMASK2,appstr,"v2.1",Unp->DepAdr);
    break;
    case _I_XTC22:
    sprintf(appstr,"%s %s","XTC","Packer");
    printf(DEPMASK2,appstr,"v2.2",Unp->DepAdr);
    break;
    case _I_XTC23:
    sprintf(appstr,"%s %s","XTC","Packer");
    printf(DEPMASK2,appstr,"v2.3",Unp->DepAdr);
    break;
    case _I_XTC23GP:
    sprintf(appstr,"%s %s","XTC","Packer");
    strcat(appstr," ");
    strcat(appstr,"v2.3");
    strcat(appstr," /");
    printf(DEPMASK2,appstr,"G*P",Unp->DepAdr);
    break;
    case _I_XTC2XGP:
    sprintf(appstr,"%s %s","XTC","Packer");
    strcat(appstr," ");
    strcat(appstr,"v2.x");
    strcat(appstr," /");
    printf(DEPMASK2,appstr,"G*P",Unp->DepAdr);
    break;
    case _I_ZIGAG:
    printf(DEPMASK2,"Zigag","Packer",Unp->DepAdr);
    break;
    case _I_ZIP50C:
    sprintf(appstr,"%s%s","v5.0","/Chromizer");
    printf(DEPMASK2,"Zipper",appstr,Unp->DepAdr);
    break;
    case _I_ZIP50H:
    sprintf(appstr,"%s %s","v5.0","Hack");
    printf(DEPMASK2,"Zipper",appstr,Unp->DepAdr);
    break;
    case _I_ZIP511:
    sprintf(appstr,"%s%s","v5.1","/1");
    printf(DEPMASK2,"Zipper",appstr,Unp->DepAdr);
    break;
    case _I_ZIP512:
    sprintf(appstr,"%s%s","v5.1","/2");
    printf(DEPMASK2,"Zipper",appstr,Unp->DepAdr);
    break;
    case _I_ZIP513:
    sprintf(appstr,"%s%s","v5.1","/3");
    printf(DEPMASK2,"Zipper",appstr,Unp->DepAdr);
    break;
    case _I_ZIP51XEN:
    sprintf(appstr,"%s%s","v5.1","/Xenon");
    printf(DEPMASK2,"Zipper",appstr,Unp->DepAdr);
    break;
    case _I_ZIP3:
    printf(DEPMASK2,"Zipper","v3.0",Unp->DepAdr);
    break;
    case _I_ZIP8:
    printf(DEPMASK2,"Zipper","v8.x",Unp->DepAdr);
    break;
    case _I_STLPROT:
    printf(DEPMASK2,"STL","Protector",Unp->DepAdr);
    break;
    case _I_GRFBIN:
    printf(DEPMASK2,"GrafBinaer","Coder",Unp->DepAdr);
    break;
    case _I_ABYSSCOD1:
    sprintf(appstr,"%s %s","Abyss","Coder");
    printf(DEPMASK2,appstr,"v1.0",Unp->DepAdr);
    break;
    case _I_ABYSSCOD2:
    sprintf(appstr,"%s %s","Abyss","Coder");
    printf(DEPMASK2,appstr,"v2.0",Unp->DepAdr);
    break;
    case _I_SPCCOD:
    printf(DEPMASK2,"SPC","Coder",Unp->DepAdr);
    break;
    case _I_SPCPROT:
    printf(DEPMASK2,"SPC","Protector",Unp->DepAdr);
    break;
    case _I_COBRACOD:
    printf(DEPMASK2,"Cobra","Coder",Unp->DepAdr);
    break;
    case _I_FSWPACK1:
    sprintf(appstr,"%s %s","FSW","Packer");
    printf(DEPMASK2,appstr,"v1.0",Unp->DepAdr);
    break;
    case _I_FSWPACK2:
    sprintf(appstr,"%s %s","FSW","Packer");
    printf(DEPMASK2,appstr,"v2.0",Unp->DepAdr);
    break;
    case _I_FSWPACK3:
    sprintf(appstr,"%s %s","FSW","Packer");
    printf(DEPMASK2,appstr,"v3.0",Unp->DepAdr);
    break;
    case _I_FSWPROT:
    printf(DEPMASK2,"FSW","Protector",Unp->DepAdr);
    break;
    case _I_BAMCOD1:
    printf(DEPMASK2,"BAM","Compacker",Unp->DepAdr);
    break;
    case _I_BAMCOD2:
    sprintf(appstr,"%s %s","BAM","Reductor");
    printf(DEPMASK2,appstr,"v3.3",Unp->DepAdr);
    break;
    case _I_BAMCOD3:
    sprintf(appstr,"%s %s","BAM","Reductor");
    printf(DEPMASK2,appstr,"v3.0",Unp->DepAdr);
    break;
    case _I_BYTEBUST4L:
    sprintf(appstr,"%s%s","Byte","Buster");
    printf(DEPMASK2,appstr,"/ Low",Unp->DepAdr);
    break;
    case _I_BYTEBUST4H:
    sprintf(appstr,"%s%s","Byte","Buster");
    printf(DEPMASK2,appstr,"/ High",Unp->DepAdr);
    break;
    case _I_MEKKER:
    printf(DEPMASK,"Mekker",Unp->DepAdr);
    break;
    case _I_BYTESTRN:
    sprintf(appstr,"%s%s","Byte","Strainer");
    printf(DEPMASK2,appstr,"v1.x",Unp->DepAdr);
    break;
    case _I_JEDILINK1:
    sprintf(appstr,"%s %s","Jedi","Linker");
    printf(DEPMASK2,appstr,"v1.x",Unp->DepAdr);
    break;
    case _I_JEDILINK2:
    sprintf(appstr,"%s %s","Jedi","Linker");
    printf(DEPMASK2,appstr,"v2.x",Unp->DepAdr);
    break;
    case _I_JEDIPACK:
    printf(DEPMASK2,"Jedi","Packer",Unp->DepAdr);
    break;
    case _I_PRIDE:
    printf(DEPMASK2,"Pride","Packer",Unp->DepAdr);
    break;
    case _I_STARCRUNCH:
    printf(DEPMASK,"StarCrunch",Unp->DepAdr);
    break;
    case _I_SPYPACK:
    printf(DEPMASK2,"Spy","Packer",Unp->DepAdr);
    break;
    case _I_PETPACK:
    printf(DEPMASK2,"PET","Packer",Unp->DepAdr);
    break;
    case _I_CADAVERPACK:
    printf(DEPMASK2,"Cadaver","Packer",Unp->DepAdr);
    break;
    case _I_HELMET2:
    printf(DEPMASK2,"Helmet","v2.x",Unp->DepAdr);
    break;
    case _I_ANTIRAM1:
    sprintf(appstr,"%s %s","Antiram","Packer");
    printf(DEPMASK2,appstr,"v1.0",Unp->DepAdr);
    break;
    case _I_ANTIRAM2:
    sprintf(appstr,"%s %s","Antiram","Packer");
    printf(DEPMASK2,appstr,"v2.0",Unp->DepAdr);
    break;
    case _I_ANTICOM:
    printf(DEPMASK2,"Anticom","Packer",Unp->DepAdr);
    break;
    case _I_GCSAUTO:
    printf(DEPMASK2,"GCS","Autostarter",Unp->DepAdr);
    break;
    case _I_AUTOFLG:
    printf(DEPMASK2,"AFLG/M.Pall","Autostarter",Unp->DepAdr);
    break;
    case _I_EXCPACK:
    printf(DEPMASK2,"Excalibur 666","Packer",Unp->DepAdr);
    break;
    case _I_EXCCOD:
    printf(DEPMASK2,"Excalibur 666","Coder",Unp->DepAdr);
    break;
    case _I_CNCD:
    sprintf(appstr,"%s %s","CNCD","Classic");
    printf(DEPMASK2,appstr,"Packer",Unp->DepAdr);
    break;
    case _I_4WD:
    printf(DEPMASK2,"4WD-Soft","Packer",Unp->DepAdr);
    break;
    case _I_1WMKL2:
    sprintf(appstr,"%s %s","Oneway","Makt-Link");
    printf(DEPMASK2,appstr,"v2.0",Unp->DepAdr);
    break;
    case _I_EMUFUX1:
    sprintf(appstr,"%s %s","Plush","Emu-Fuxx0r");
    printf(DEPMASK2,appstr,"v1.0",Unp->DepAdr);
    break;
    case _I_EMUFUX2:
    sprintf(appstr,"%s %s","Plush","Emu-Fuxx0r");
    printf(DEPMASK2,appstr,"v2.0",Unp->DepAdr);
    break;
    case _I_HUFFER:
    sprintf(appstr,"%s / %s","v1.0","FLT");
    printf(DEPMASK2,"Huffer",appstr,Unp->DepAdr);
    break;
    case _I_HUFFERQC:
    sprintf(appstr,"%s / %s","v1.1","Quick");strcat(appstr,"Cruncher");
    printf(DEPMASK2,"Huffer",appstr,Unp->DepAdr);
    break;
    case _I_NM156PACK:
    printf(DEPMASK2,"NM156","Packer",Unp->DepAdr);
    break;
    case _I_NM156LINK:
    printf(DEPMASK2,"NM156","Linker",Unp->DepAdr);
    break;
    case _I_RATTPACK:
    printf(DEPMASK2,"Ratt","Packer",Unp->DepAdr);
    break;
    case _I_RATTLINK:
    printf(DEPMASK2,"Ratt","Linker",Unp->DepAdr);
    break;
    case _I_BYTERAPERS1:
    sprintf(appstr,"%s %s","Byterapers","Packer");
    printf(DEPMASK2,appstr,"v1.x",Unp->DepAdr);
    break;
    case _I_BYTERAPERS2:
    sprintf(appstr,"%s %s","Byterapers","Packer");
    printf(DEPMASK2,appstr,"v2.x",Unp->DepAdr);
    break;
    case _I_CIACRP:
    sprintf(appstr,"%s %s","CIA","Crypt");
    printf(DEPMASK2,appstr,"v2.x",Unp->DepAdr);
    break;
    case _I_PANPACK:
    sprintf(appstr,"%s %s","PAN","Packer");
    printf(DEPMASK2,appstr,"v1.0",Unp->DepAdr);
    break;
    case _I_PANPACK2:
    sprintf(appstr,"%s %s","PAN","Packer");
    printf(DEPMASK2,appstr,"v2.0",Unp->DepAdr);
    break;
    case _I_TKCEQB1:
    sprintf(appstr,"%s %s","TKC","Bytepress");
    printf(DEPMASK2,appstr,"v1.0",Unp->DepAdr);
    break;
    case _I_TKCEQB2:
    sprintf(appstr,"%s %s","TKC","Bytepress");
    printf(DEPMASK2,appstr,"v2.0",Unp->DepAdr);
    break;
    case _I_UPROT420:
    sprintf(appstr,"%s %s","$420","Coder");
    printf(DEPMASK2,"Unknown",appstr,Unp->DepAdr);
    break;
    case _I_HIVIRUS:
    printf(DEPMASK2,"HIV","Virus",Unp->DepAdr);
    break;
    case _I_BHPVIRUS:
    printf(DEPMASK2,"BHP","Virus",Unp->DepAdr);
    break;
    case _I_BULAVIRUS:
    printf(DEPMASK2,"Bula","Virus",Unp->DepAdr);
    break;
    case _I_CODERVIRUS:
    printf(DEPMASK2,"Coder","Virus",Unp->DepAdr);
    break;
    case _I_BOAVIRUS:
    printf(DEPMASK2,"Boa","Virus",Unp->DepAdr);
    break;
    case _I_PLUSHZ:
    sprintf(appstr,"%s %s","Plush","Packer");
    printf(DEPMASK2,appstr,"/ fast",Unp->DepAdr);
    break;
    case _I_PLUSHZS:
    sprintf(appstr,"%s %s","Plush","Packer");
    printf(DEPMASK2,appstr,"/ short",Unp->DepAdr);
    break;
    case _I_REBELP:
    printf(DEPMASK2,"Rebels","Packer",Unp->DepAdr);
    break;
    case _I_YETICOD:
    printf(DEPMASK2,"Yeti","Coder",Unp->DepAdr);
    break;
    case _I_ZEROCOD:
    printf(DEPMASK2,"Zero","Coder",Unp->DepAdr);
    break;
    case _I_CHGPROT2:
    sprintf(appstr,"%s %s","Change","Protector");
    printf(DEPMASK2,appstr,"v2.0",Unp->DepAdr);
    break;
    case _I_PDPACK1:
    sprintf(appstr,"%s %s","Panoramic","Packer");
    printf(DEPMASK2,appstr,"v1.0",Unp->DepAdr);
    break;
    case _I_PDPACK2:
    sprintf(appstr,"%s %s","Panoramic","Packer");
    printf(DEPMASK2,appstr,"v2.0",Unp->DepAdr);
    break;
    case _I_PDPACK30:
    sprintf(appstr,"%s %s","Panoramic","Packer");
    printf(DEPMASK2,appstr,"v3.0",Unp->DepAdr);
    break;
    case _I_PDPACK31:
    sprintf(appstr,"%s %s","Panoramic","Packer");
    printf(DEPMASK2,appstr,"v3.1",Unp->DepAdr);
    break;
    case _I_PDPACK32:
    sprintf(appstr,"%s %s","Panoramic","Packer");
    printf(DEPMASK2,appstr,"v3.2",Unp->DepAdr);
    break;
    case _I_PDEQLZ15:
    sprintf(appstr,"%s %s","Panoramic","Equalizer");
    printf(DEPMASK2,appstr,"v1.5",Unp->DepAdr);
    break;
    case _I_SUPERPACK4:
    sprintf(appstr,"%s%s","Super","Packer");appstr[strlen(appstr)-2]=0;
    printf(DEPMASK,appstr,Unp->DepAdr);
    break;
    case _I_THSCOD:
    sprintf(appstr,"%s%s","Bit","Coder");
    printf(DEPMASK2,"THS",appstr,Unp->DepAdr);
    break;
    case _I_PWCOPSH:
    sprintf(appstr,"%s %s","Password","Protector");strcat(appstr,":");
    printf(DEPMASK2,appstr,"Cop Shocker",Unp->DepAdr);
    break;
    case _I_PWTIMEC:
    sprintf(appstr,"%s %s","Password","Protector");strcat(appstr,":");
    printf(DEPMASK2,appstr,"Time Coder/Trap",Unp->DepAdr);
    break;
    case _I_PWSNACKY:
    sprintf(appstr,"%s %s","Password","Protector");strcat(appstr,":");
    printf(DEPMASK2,appstr,"Snacky",Unp->DepAdr);
    break;
    case _I_PWTCD:
    sprintf(appstr,"%s %s","Password","Protector");strcat(appstr,":");
    printf(DEPMASK2,appstr,"TCD",Unp->DepAdr);
    break;
    case _I_PWJCH:
    sprintf(appstr,"%s %s","Password","Protector");strcat(appstr,":");
    printf(DEPMASK2,appstr,"J-Coder v1.0/JCH",Unp->DepAdr);
    break;
    case _I_PWFILEPR:
    sprintf(appstr,"%s %s","Password","Protector");strcat(appstr,":");
    printf(DEPMASK2,appstr,"FileProtect v1.0/Syncro",Unp->DepAdr);
    break;
    case _I_PWFLT:
    sprintf(appstr,"%s %s","Password","Protector");strcat(appstr,":");
    printf(DEPMASK2,appstr,"Lamer-Protection/FLT",Unp->DepAdr);
    break;
    case _I_WHO:
    printf(DEPMASK2,"WHO","Coder",Unp->DepAdr);
    break;
    case _I_PYRACOD1:
    sprintf(appstr,"%s %s","Pyra","Coder");
    printf(DEPMASK2,appstr,"v1.x",Unp->DepAdr);
    break;
    case _I_PYRACOD2:
    sprintf(appstr,"%s %s","Pyra","Coder");
    printf(DEPMASK2,appstr,"v2.x",Unp->DepAdr);
    break;
    case _I_BFPACK:
    printf(DEPMASK2,"BeyondForce","Packer",Unp->DepAdr);
    break;
    case _I_THUNCATSPK:
    printf(DEPMASK2,"ThunderCats","Packer",Unp->DepAdr);
    break;
    case _I_ACTIONP:
    printf(DEPMASK2,"Action","Packer",Unp->DepAdr);
    break;
    case _I_KGBCOD:
    printf(DEPMASK2,"KGB","Coder",Unp->DepAdr);
    break;
    case _I_CCRYPT:
    printf(DEPMASK2,"C+C","Coder",Unp->DepAdr);
    break;
    case _I_TDT:
    printf(DEPMASK2,"DreamTeam","Packer",Unp->DepAdr);
    break;
    case _I_TDTPETC1:
    sprintf(appstr,"%s %s","PET","Cruncher");
    printf(DEPMASK2,appstr,"v1.0",Unp->DepAdr);
    break;
    case _I_TDTPETC2:
    sprintf(appstr,"%s %s","PET","Cruncher");
    printf(DEPMASK2,appstr,"v1.1",Unp->DepAdr);
    break;
    case _I_TDTPETCU:
    sprintf(appstr,"%s %s","PET","Cruncher");
    printf(DEPMASK2,appstr,"Unknown",Unp->DepAdr);
    break;
    case _I_TDTPETL:
    printf(DEPMASK2,"PET","Linker",Unp->DepAdr);
    break;
    case _I_CULT:
    printf(DEPMASK2,"Cult","Packer",Unp->DepAdr);
    break;
    case _I_GIMZO:
    printf(DEPMASK2,"Gimzo","Packer",Unp->DepAdr);
    break;
    case _I_BETASKIP:
    printf(DEPMASK2,"BetasSkip","Autostarter",Unp->DepAdr);
    break;
    case _I_BLACKADDER:
    printf(DEPMASK2,"BlackAdder","header",Unp->DepAdr);
    break;
    case _I_ICS8:
    printf(DEPMASK2,"ICS Drive 8","Coder",Unp->DepAdr);
    break;
    case _I_PARADROID1:
    sprintf(appstr,"%s %s","Paradroid","Packer");
    printf(DEPMASK2,appstr,"v1.x",Unp->DepAdr);
    break;
    case _I_PARADROID2:
    sprintf(appstr,"%s %s","Paradroid","Packer");
    printf(DEPMASK2,appstr,"v2.x",Unp->DepAdr);
    break;
    case _I_PARADROIDL:
    printf(DEPMASK2,"Paradroid","Linker",Unp->DepAdr);
    break;
    case _I_PLASMACOD:
    printf(DEPMASK2,"Plasma","Coder",Unp->DepAdr);
    break;
    case _I_EXACTCOD:
    printf(DEPMASK2,"Exact","Coder",Unp->DepAdr);
    break;
    case _I_DRZOOM:
    sprintf(appstr,"%s %s","Dr Zoom","Packer");
    printf(DEPMASK2,appstr,"v1.0",Unp->DepAdr);
    break;
    case _I_TIMCR:
    strcpy(appstr,"Cruncher");appstr[6]=0;
    printf(DEPMASK2,"Tim",appstr,Unp->DepAdr);
    break;
    case _I_CNETFIX:
    printf(DEPMASK2,"CNET Fixer","Coder",Unp->DepAdr);
    break;
    case _I_TRIANGLECOD:
    printf(DEPMASK2,"Triangle","Coder",Unp->DepAdr);
    break;
    case _I_SFLINK:
    printf(DEPMASK2,"Super File","Linker",Unp->DepAdr);
    break;
    case _I_BONGO:
    printf(DEPMASK2,"Bongo","Cruncher",Unp->DepAdr);
    break;
    case _I_JEMABASIC:
    sprintf(appstr,"%s %s","Jemasoft","Basic");
    printf(DEPMASK2,appstr,"Packer",Unp->DepAdr);
    break;
    case _I_TATCOD:
    printf(DEPMASK2,"TAT","Coder",Unp->DepAdr);
    break;
    case _I_RFOCOD:
    printf(DEPMASK2,"RFO","Coder",Unp->DepAdr);
    break;
    case _I_DOYNAMITE:
    printf(DEPMASK2,"Doynamite","v1.1",Unp->DepAdr);
    break;
    case _I_BITNAX04:
    printf(DEPMASK2,"Doynamite/Bitnax","v0.4",Unp->DepAdr);
    break;
    case _I_NIBBIT:
    printf(DEPMASK,"Nibb-it",Unp->DepAdr);
    break;
    case _I_UAPACK:
    printf(DEPMASK2,"UA","Packer",Unp->DepAdr);
    break;
    case _I_ADP4KBAR:
    printf(DEPMASK,"Admiral P4Kbar/Ferris",Unp->DepAdr);
    break;
    case _I_NUCRUNCH:
    sprintf(appstr,"%s%s/%s","Nu","Crunch","ChristopherJam");
    printf(DEPMASK,appstr,Unp->DepAdr);
    break;
    case _I_TINYCRUN09:
    sprintf(appstr,"%s%s %s/%s","Tiny","Crunch","v0.9","ChristopherJam");
    printf(DEPMASK,appstr,Unp->DepAdr);
    break;
    case _I_TINYCRUNCH:
    sprintf(appstr,"%s%s %s/%s","Tiny","Crunch","v1.0","ChristopherJam");
    printf(DEPMASK,appstr,Unp->DepAdr);
    break;
    case _I_TINYCR_UNK:
    sprintf(appstr,"%s%s %s/%s","Tiny","Crunch","v1.?","ChristopherJam");
    printf(DEPMASK,appstr,Unp->DepAdr);
    break;
    case _I_BITPICK1:
    sprintf(appstr,"%s%s %s/%s","Bit","Pickler","v1.0","ChristopherJam");
    printf(DEPMASK,appstr,Unp->DepAdr);
    break;
    case _I_BITPICK1T:
    sprintf(appstr,"%s%s %s/%s","Bit","Pickler","v1.0","Tiny");
    printf(DEPMASK,appstr,Unp->DepAdr);
    break;
    case _I_FLINKSDA:
    sprintf(appstr,"%s / %s","Linker","Agony");
    printf(DEPMASK2,"File",appstr,Unp->DepAdr);
    break;
    case _I_INCERIAPK:
    printf(DEPMASK2,"Inceria","Packer",Unp->DepAdr);
    break;
    case _I_ZX009:
    printf(DEPMASK2,"ZX0","v1.0-alpha",Unp->DepAdr);
    break;
    case _I_ZX010:
    printf(DEPMASK2,"ZX0","v1.0",Unp->DepAdr);
    break;
    case _I_ZX015:
    printf(DEPMASK2,"ZX0","v1.5",Unp->DepAdr);
    break;
    case _I_DALI03F:
    sprintf(appstr,"%s / %s","v0.3","fast");
    printf(DEPMASK2,"Dali",appstr,Unp->DepAdr);
    break;
    case _I_DALI03S:
    sprintf(appstr,"%s / %s","v0.3","small");
    printf(DEPMASK2,"Dali",appstr,Unp->DepAdr);
    break;
    case _I_DALI031F:
    sprintf(appstr,"%s / %s","v0.3.1","fast");
    printf(DEPMASK2,"Dali",appstr,Unp->DepAdr);
    break;
    case _I_DALI032F:
    sprintf(appstr,"%s / %s","v0.3.2","fast");
    printf(DEPMASK2,"Dali",appstr,Unp->DepAdr);
    break;
    case _I_DALI033F:
    sprintf(appstr,"%s / %s","v0.3.3","fast");
    printf(DEPMASK2,"Dali",appstr,Unp->DepAdr);
    break;
    case _I_DALI032S:
    sprintf(appstr,"%s / %s","v0.3.2","small");
    printf(DEPMASK2,"Dali",appstr,Unp->DepAdr);
    break;
    case _I_DALI033S:
    sprintf(appstr,"%s / %s","v0.3.3","small");
    printf(DEPMASK2,"Dali",appstr,Unp->DepAdr);
    break;
    case _I_DALI034SFX:
    sprintf(appstr,"%s / %s","v0.3.4","small");
    strcat(appstr,"/");strcat(appstr,"FX");
    printf(DEPMASK2,"Dali",appstr,Unp->DepAdr);
    break;
    case _I_DALI035SFX:
    sprintf(appstr,"%s / %s","v0.3.5","small");
    strcat(appstr,"/");strcat(appstr,"FX");
    printf(DEPMASK2,"Dali",appstr,Unp->DepAdr);
    break;
    case _I_PICOPACK:
    printf(DEPMASK2,"Pico","Packer",Unp->DepAdr);
    break;
    case _I_TSCRUNCH10:
    strcpy(appstr,"TS");strcat(appstr,"Crunch");
    printf(DEPMASK2,appstr,"v1.0",Unp->DepAdr);
    break;
    case _I_TSCRUNCH12:
    strcpy(appstr,"TS");strcat(appstr,"Crunch");
    printf(DEPMASK2,appstr,"v1.2",Unp->DepAdr);
    break;
    case _I_TSCRUNCH13:
    strcpy(appstr,"TS");strcat(appstr,"Crunch");
    printf(DEPMASK2,appstr,"v1.3",Unp->DepAdr);
    break;
    case _I_TSCRUNCH131:
    strcpy(appstr,"TS");strcat(appstr,"Crunch");
    printf(DEPMASK2,appstr,"v1.3.1",Unp->DepAdr);
    break;
    case _I_TSCRUNCH131B:
    strcpy(appstr,"TS");strcat(appstr,"Crunch");
    printf(DEPMASK2,appstr,"v1.3.1-B",Unp->DepAdr);
    break;
    case _I_TSCRUNCH131X2:
    strcpy(appstr,"TS");strcat(appstr,"Crunch");
    printf(DEPMASK2,appstr,"v1.3.1-X2",Unp->DepAdr);
    break;
    case _I_PWRCOD:
    printf(DEPMASK2,"PWR","Coder",Unp->DepAdr);
    break;
    case _I_ORIONCOD:
    printf(DEPMASK2,"Orion","Coder",Unp->DepAdr);
    break;
    case _I_MAIMER1X:
    strcpy(appstr,"Topaz Maimer");
    printf(DEPMASK2,appstr,"v1.x",Unp->DepAdr);
    break;
    case _I_MAIMER23:
    strcpy(appstr,"Topaz Maimer");
    printf(DEPMASK2,appstr,"v2.3",Unp->DepAdr);
    break;
    case _I_GPINTROH4:
    strcpy(appstr, "G*P Intro Hack"); strcat(appstr, " 4");
    printf(DEPMASK,appstr,Unp->DepAdr);
    break;
    case _I_TAG:
    printf(DEPMASK2,"TAG","Cruncher",Unp->DepAdr);
    break;
    case _I_AEB1:
    sprintf(appstr,"%s %s","Baskerville","Cruncher");
    printf(DEPMASK2,appstr,"v0.7x",Unp->DepAdr);
    break;
    case _I_AEB2:
    sprintf(appstr,"%s %s","Baskerville","Cruncher");
    printf(DEPMASK2,appstr,"v0.6x",Unp->DepAdr);
    break;
    case _I_AGPXGM :
    printf(DEPMASK2,"AGPX","Compiler",Unp->DepAdr);
    break;
    case _I_AGPXGMO:
    sprintf(appstr,"%s %s","AGPX","Compiler");
    printf(DEPMASK2,appstr,"/ old?",Unp->DepAdr);
    break;
    case _I_OSCAR64_1:
    sprintf(appstr,"%s %s","Oscar64","Compiler");
    printf(DEPMASK2,appstr,"V1",Unp->DepAdr);
    break;
    case _I_OSCAR64_2:
    sprintf(appstr,"%s %s","Oscar64","Compiler");
    printf(DEPMASK2,appstr,"V2",Unp->DepAdr);
    break;
    case _I_OSCAR64_3:
    sprintf(appstr,"%s %s","Oscar64","Compiler");
    printf(DEPMASK2,appstr,"V3",Unp->DepAdr);
    break;
    case _I_OSCAR64_4:
    sprintf(appstr,"%s %s","Oscar64","Compiler");
    printf(DEPMASK2,appstr,"V4",Unp->DepAdr);
    break;
    case _I_COMP64K11:
    sprintf(appstr,"%s%s","Compress64k","/Hermit");
    printf(DEPMASK2,appstr,"v1.1",Unp->DepAdr);
    break;
    case _I_COMP64K12:
    sprintf(appstr,"%s%s","Compress64k","/Hermit");
    printf(DEPMASK2,appstr,"v1.2",Unp->DepAdr);
    break;
    case _I_LZSS1:
    sprintf(appstr,"%s%s","Fast","Packer");
    printf(DEPMASK2,appstr,"v1.0",Unp->DepAdr);
    break;
    }
}
