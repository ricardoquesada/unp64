#################################################################
## Thanks to Groepaz for fixing this makefile for *nix
## make CFG=Debug  to build debug version
## tested also in MingW/MSYS
#################################################################

ifneq (,$(findstring Debug, $(CFG)))
  override CFG = Debug
else
  override CFG = Release
endif

PROJECT = unp64
CC = gcc

ifeq ($(CFG),Debug)
  OBJ_DIR = Debug
  OUTPUT_DIR = Debug
  TARGET = unp64
  C_INCLUDE_DIRS =
  C_PREPROC =
  CFLAGS = -pipe  -Wall -g2 -O0
  RC_INCLUDE_DIRS =
  RC_PREPROC =
  RCFLAGS =
  LIB_DIRS =
  LIBS =
  LDFLAGS = -pipe
endif

ifeq ($(CFG),Release)
  OBJ_DIR = Release
  OUTPUT_DIR = Release
  TARGET = unp64
  C_INCLUDE_DIRS =
  C_PREPROC =
  CFLAGS = -pipe  -Wall -g0 -O3
  RC_INCLUDE_DIRS =
  RC_PREPROC =
  RCFLAGS =
  LIB_DIRS =
  LIBS =
  LDFLAGS = -pipe -s
endif

ifeq ($(OS),Windows_NT)
  NULL =
else
  NULL = nul
endif

SRC_OBJS = \
  $(OBJ_DIR)/1001card.o \
  $(OBJ_DIR)/4cPack.o   \
  $(OBJ_DIR)/4wd.o   \
  $(OBJ_DIR)/64er.o \
  $(OBJ_DIR)/6502emu.o  \
  $(OBJ_DIR)/ABCruncher.o   \
  $(OBJ_DIR)/AbuzeCrunch.o  \
  $(OBJ_DIR)/AbyssCoder.o   \
  $(OBJ_DIR)/AdmiralP4kbar.o \
  $(OBJ_DIR)/AEB.o \
  $(OBJ_DIR)/AEKcoder.o \
  $(OBJ_DIR)/ActionPacker.o \
  $(OBJ_DIR)/Agony.o    \
  $(OBJ_DIR)/ALScoder.o \
  $(OBJ_DIR)/ALZ64.o    \
  $(OBJ_DIR)/Amnesia.o  \
  $(OBJ_DIR)/Apack.o    \
  $(OBJ_DIR)/AR.o   \
  $(OBJ_DIR)/ASCprot.o  \
  $(OBJ_DIR)/Autostarters.o  \
  $(OBJ_DIR)/BAM.o  \
  $(OBJ_DIR)/BeastLink.o    \
  $(OBJ_DIR)/BeefTrucker.o  \
  $(OBJ_DIR)/BetaDynamic.o  \
  $(OBJ_DIR)/BitImploder.o  \
  $(OBJ_DIR)/BitPacker.o    \
  $(OBJ_DIR)/BitPickler.o    \
  $(OBJ_DIR)/BlackAdder.o    \
  $(OBJ_DIR)/BN1872.o  \
  $(OBJ_DIR)/BonanzaBros.o  \
  $(OBJ_DIR)/Bongo.o  \
  $(OBJ_DIR)/Brains.o   \
  $(OBJ_DIR)/BronxPacker.o  \
  $(OBJ_DIR)/BYG.o  \
  $(OBJ_DIR)/ByteBoiler.o   \
  $(OBJ_DIR)/ByteBoozer.o   \
  $(OBJ_DIR)/ByteBuster.o   \
  $(OBJ_DIR)/ByteCompactor.o    \
  $(OBJ_DIR)/ByteKiller.o   \
  $(OBJ_DIR)/Byterapers.o   \
  $(OBJ_DIR)/ByteStrainer.o   \
  $(OBJ_DIR)/C4MRP.o    \
  $(OBJ_DIR)/Cadaver.o    \
  $(OBJ_DIR)/CadgersPacker.o    \
  $(OBJ_DIR)/Caution.o  \
  $(OBJ_DIR)/CC.o  \
  $(OBJ_DIR)/CCS.o  \
  $(OBJ_DIR)/CeleriPack.o   \
  $(OBJ_DIR)/CFB.o  \
  $(OBJ_DIR)/CIACrypt.o  \
  $(OBJ_DIR)/CNCD.o    \
  $(OBJ_DIR)/CNETFixer.o    \
  $(OBJ_DIR)/Cobra.o    \
  $(OBJ_DIR)/Comp64k.o    \
  $(OBJ_DIR)/Cruel.o    \
  $(OBJ_DIR)/Crush.o    \
  $(OBJ_DIR)/Cult.o    \
  $(OBJ_DIR)/C_Noack.o  \
  $(OBJ_DIR)/DarkSqueezer.o \
  $(OBJ_DIR)/DD.o   \
  $(OBJ_DIR)/DSCcoder.o \
  $(OBJ_DIR)/Doynamite.o \
  $(OBJ_DIR)/DrZoom.o \
  $(OBJ_DIR)/Eastlinker.o   \
  $(OBJ_DIR)/ECA.o  \
  $(OBJ_DIR)/EnigmaMFFL.o   \
  $(OBJ_DIR)/EqByteComp.o   \
  $(OBJ_DIR)/ExactCoder.o \
  $(OBJ_DIR)/Excalibur.o \
  $(OBJ_DIR)/Exomizer.o \
  $(OBJ_DIR)/exo_util.o \
  $(OBJ_DIR)/Expert.o   \
  $(OBJ_DIR)/ExplCrunch.o   \
  $(OBJ_DIR)/ExplFaces.o    \
  $(OBJ_DIR)/ExplXRated.o   \
  $(OBJ_DIR)/Facepacker.o   \
  $(OBJ_DIR)/FC3pack.o  \
  $(OBJ_DIR)/FCG.o  \
  $(OBJ_DIR)/FDTcoder.o \
  $(OBJ_DIR)/FilecompactorMTB.o \
  $(OBJ_DIR)/FilecompactorTMC.o \
  $(OBJ_DIR)/FileLinkerAgony.o \
  $(OBJ_DIR)/FinalCompactor.o   \
  $(OBJ_DIR)/FinalSuperComp.o   \
  $(OBJ_DIR)/FP.o   \
  $(OBJ_DIR)/Frog.o  \
  $(OBJ_DIR)/FrontPacker.o  \
  $(OBJ_DIR)/FSW.o  \
  $(OBJ_DIR)/FXbitstream.o  \
  $(OBJ_DIR)/FXbytepress.o  \
  $(OBJ_DIR)/Galleon.o  \
  $(OBJ_DIR)/Gandalf.o  \
  $(OBJ_DIR)/Anticom.o   \
  $(OBJ_DIR)/Antiram.o   \
  $(OBJ_DIR)/Gimzo.o   \
  $(OBJ_DIR)/GPacker.o   \
  $(OBJ_DIR)/GrafBinaer.o   \
  $(OBJ_DIR)/Graffity.o \
  $(OBJ_DIR)/Hawk.o \
  $(OBJ_DIR)/Helmet.o \
  $(OBJ_DIR)/HTLcoder.o \
  $(OBJ_DIR)/Huffer.o \
  $(OBJ_DIR)/ICS8.o  \
  $(OBJ_DIR)/IDT.o  \
  $(OBJ_DIR)/Ikari.o    \
  $(OBJ_DIR)/ILSCoder.o \
  $(OBJ_DIR)/Inceria.o   \
  $(OBJ_DIR)/Intros.o   \
  $(OBJ_DIR)/ISC.o  \
  $(OBJ_DIR)/IsePic.o   \
  $(OBJ_DIR)/Jazoo.o    \
  $(OBJ_DIR)/Jazzcat.o  \
  $(OBJ_DIR)/Jox.o  \
  $(OBJ_DIR)/Jedi.o    \
  $(OBJ_DIR)/Jemasoft.o    \
  $(OBJ_DIR)/KompressMaster711.o    \
  $(OBJ_DIR)/Koncina.o  \
  $(OBJ_DIR)/KGB.o  \
  $(OBJ_DIR)/Lightmizer.o   \
  $(OBJ_DIR)/Loadstar.o \
  $(OBJ_DIR)/log.o  \
  $(OBJ_DIR)/Low.o  \
  $(OBJ_DIR)/LSTcoder.o \
  $(OBJ_DIR)/LTS.o  \
  $(OBJ_DIR)/Lzss.o  \
  $(OBJ_DIR)/Maimer.o  \
  $(OBJ_DIR)/MartinPiper.o  \
  $(OBJ_DIR)/MaschSprache.o \
  $(OBJ_DIR)/MasterCompressor.o \
  $(OBJ_DIR)/Matcham.o  \
  $(OBJ_DIR)/MCCrackenComp.o    \
  $(OBJ_DIR)/MDG.o  \
  $(OBJ_DIR)/Megabyte.o \
  $(OBJ_DIR)/MegaCruncher.o \
  $(OBJ_DIR)/Mekker.o\
  $(OBJ_DIR)/MrCross.o  \
  $(OBJ_DIR)/MRD.o  \
  $(OBJ_DIR)/MrZ.o  \
  $(OBJ_DIR)/MSI.o  \
  $(OBJ_DIR)/NEC.o  \
  $(OBJ_DIR)/Nibbit.o   \
  $(OBJ_DIR)/NotPackers.o   \
  $(OBJ_DIR)/NM156.o  \
  $(OBJ_DIR)/NSU.o  \
  $(OBJ_DIR)/NuCrunch.o  \
  $(OBJ_DIR)/Oneway.o    \
  $(OBJ_DIR)/ONS.o  \
  $(OBJ_DIR)/Optimus.o  \
  $(OBJ_DIR)/OUG.o  \
  $(OBJ_DIR)/P100.o \
  $(OBJ_DIR)/PackOpt.o  \
  $(OBJ_DIR)/PAN.o  \
  $(OBJ_DIR)/Panoramic.o	\
  $(OBJ_DIR)/Paradroid.o	\
  $(OBJ_DIR)/Plasma.o	\
  $(OBJ_DIR)/PITcoder.o \
  $(OBJ_DIR)/Polonus.o  \
  $(OBJ_DIR)/PuCrunch.o \
  $(OBJ_DIR)/OrionCoder.o  \
  $(OBJ_DIR)/PWRCoder.o  \
  $(OBJ_DIR)/PZW.o  \
  $(OBJ_DIR)/Pride.o  \
  $(OBJ_DIR)/Pyra.o  \
  $(OBJ_DIR)/RapEq.o    \
  $(OBJ_DIR)/Ratt.o    \
  $(OBJ_DIR)/Relax.o    \
  $(OBJ_DIR)/RFOCod.o    \
  $(OBJ_DIR)/ScreenCrunch.o \
  $(OBJ_DIR)/Section8.o \
  $(OBJ_DIR)/Shurigen.o \
  $(OBJ_DIR)/SirMiniPack.o  \
  $(OBJ_DIR)/SFLinker.o \
  $(OBJ_DIR)/SKLcoder.o \
  $(OBJ_DIR)/SledgeHammer.o \
  $(OBJ_DIR)/SPC.o  \
  $(OBJ_DIR)/SpyPack.o  \
  $(OBJ_DIR)/SpeediComp.o   \
  $(OBJ_DIR)/STL.o  \
  $(OBJ_DIR)/StarCrunch.o  \
  $(OBJ_DIR)/Supercrunch.o  \
  $(OBJ_DIR)/Superpack.o  \
  $(OBJ_DIR)/SyncroPack.o    \
  $(OBJ_DIR)/TAG.o \
  $(OBJ_DIR)/TATCod.o \
  $(OBJ_DIR)/TBCMultiComp.o \
  $(OBJ_DIR)/TCD.o  \
  $(OBJ_DIR)/TCScrunch.o    \
  $(OBJ_DIR)/TDT.o  \
  $(OBJ_DIR)/TimCrunch.o \
  $(OBJ_DIR)/TimeCruncher.o \
  $(OBJ_DIR)/TinyCrunch.o \
  $(OBJ_DIR)/THS.o \
  $(OBJ_DIR)/TKC.o \
  $(OBJ_DIR)/TLRLinker.o \
  $(OBJ_DIR)/TLRSubsizer.o \
  $(OBJ_DIR)/TMCcoder.o \
  $(OBJ_DIR)/TMM.o  \
  $(OBJ_DIR)/Trashcan.o \
  $(OBJ_DIR)/Triangle.o  \
  $(OBJ_DIR)/Trianon.o  \
  $(OBJ_DIR)/TSB.o  \
  $(OBJ_DIR)/TSCrunch.o  \
  $(OBJ_DIR)/TSMcoder.o \
  $(OBJ_DIR)/TurboPacker.o  \
  $(OBJ_DIR)/UltraComp.o    \
  $(OBJ_DIR)/UniPacker.o    \
  $(OBJ_DIR)/unp64.o    \
  $(OBJ_DIR)/U_100pack.o    \
  $(OBJ_DIR)/U_101pack.o    \
  $(OBJ_DIR)/U_111pack.o    \
  $(OBJ_DIR)/Rows.o    \
  $(OBJ_DIR)/FalcoPack.o  \
  $(OBJ_DIR)/U_400All.o \
  $(OBJ_DIR)/U_439pack.o \
  $(OBJ_DIR)/U_25_pack.o    \
  $(OBJ_DIR)/U_8e_pack.o    \
  $(OBJ_DIR)/U_DSC_MA.o \
  $(OBJ_DIR)/KressCrunch.o  \
  $(OBJ_DIR)/U_Generic801.o \
  $(OBJ_DIR)/U_P3_pack.o    \
  $(OBJ_DIR)/U_fd_pack.o    \
  $(OBJ_DIR)/U_Triad.o  \
  $(OBJ_DIR)/UProt.o  \
  $(OBJ_DIR)/VIP.o  \
  $(OBJ_DIR)/Warlock.o  \
  $(OBJ_DIR)/WCC.o  \
  $(OBJ_DIR)/WDRsoftp.o \
  $(OBJ_DIR)/WGIcoder.o \
  $(OBJ_DIR)/WHO.o \
  $(OBJ_DIR)/XDScoder.o \
  $(OBJ_DIR)/XIP.o  \
  $(OBJ_DIR)/XTC.o  \
  $(OBJ_DIR)/Zigag.o    \
  $(OBJ_DIR)/Zipper.o   \
  $(OBJ_DIR)/xCodeZippers.o	\
  $(OBJ_DIR)/YetiCoder.o	\
  $(OBJ_DIR)/ZeroCoder.o	\
  $(OBJ_DIR)/ZX0.o	\
  $(OBJ_DIR)/_Scanners.o

define build_target
@echo Linking...
@$(CC) -o "$(OUTPUT_DIR)/$(TARGET)" $(SRC_OBJS) $(LIB_DIRS) $(LIBS) $(LDFLAGS)
endef

define compile_source
@echo Compiling $<
@$(CC) $(CFLAGS) $(C_PREPROC) $(C_INCLUDE_DIRS) -c "$<" -o "$@"
endef

.PHONY: print_header directories

$(TARGET): print_header directories $(SRC_OBJS)
	$(build_target)

.PHONY: clean cleanall

cleanall:
	@echo Deleting intermediate files for 'unp64 - $(CFG)'
	-@rm -f $(OBJ_DIR)/*.o
	-@rm -f "$(OUTPUT_DIR)/$(TARGET)"
	-@rmdir "$(OUTPUT_DIR)"

clean:
	@echo Deleting intermediate files for 'unp64 - $(CFG)'
	-@rm -f $(OBJ_DIR)/*.o

print_header:
	@echo ----------Configuration: unp64 - $(CFG)----------

$(SRC_OBJS): | directories

directories:
	-@mkdir -p "$(OUTPUT_DIR)" 2>/dev/null || mkdir "$(OUTPUT_DIR)" 2>/dev/null || true
	-@mkdir -p "$(OBJ_DIR)" 2>/dev/null || mkdir "$(OBJ_DIR)" 2>/dev/null || true

$(OBJ_DIR)/6502emu.o: 6502emu.c	\
6502emu.h	\
int.h	\
log.h
	$(compile_source)

$(OBJ_DIR)/exo_util.o: exo_util.c	\
exo_util.h	\
log.h	\
membuf.h
	$(compile_source)

$(OBJ_DIR)/log.o: log.c	\
log.h
	$(compile_source)

$(OBJ_DIR)/unp64.o: unp64.c	\
unp64.h	\
exo_util.h	\
log.h	\
membuf.h	\
6502emu.h	\
int.h	\
roms.h
	$(compile_source)

$(OBJ_DIR)/1001card.o: scanners/1001card.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/4cPack.o: scanners/4cPack.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/4wd.o: scanners/4wd.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/64er.o: scanners/64er.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/ABCruncher.o: scanners/ABCruncher.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/AdmiralP4kbar.o: scanners/AdmiralP4kbar.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/AEB.o: scanners/AEB.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/AEKcoder.o: scanners/AEKcoder.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/ActionPacker.o: scanners/ActionPacker.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/ALScoder.o: scanners/ALScoder.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/ALZ64.o: scanners/ALZ64.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/AR.o: scanners/AR.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/ASCprot.o: scanners/ASCprot.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/AbuzeCrunch.o: scanners/AbuzeCrunch.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/Agony.o: scanners/Agony.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/Amnesia.o: scanners/Amnesia.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/Apack.o: scanners/Apack.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/BYG.o: scanners/BYG.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/BeastLink.o: scanners/BeastLink.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/BeefTrucker.o: scanners/BeefTrucker.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/BetaDynamic.o: scanners/BetaDynamic.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/BitImploder.o: scanners/BitImploder.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/BitPacker.o: scanners/BitPacker.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/BitPickler.o: scanners/BitPickler.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/BlackAdder.o: scanners/BlackAdder.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/BN1872.o: scanners/BN1872.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/BonanzaBros.o: scanners/BonanzaBros.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/Bongo.o: scanners/Bongo.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/Brains.o: scanners/Brains.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/BronxPacker.o: scanners/BronxPacker.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/ByteBoiler.o: scanners/ByteBoiler.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/ByteBoozer.o: scanners/ByteBoozer.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/ByteBuster.o: scanners/ByteBuster.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/ByteCompactor.o: scanners/ByteCompactor.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/ByteKiller.o: scanners/ByteKiller.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/Byterapers.o: scanners/Byterapers.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/ByteStrainer.o: scanners/ByteStrainer.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/C4MRP.o: scanners/C4MRP.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/CCS.o: scanners/CCS.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/CFB.o: scanners/CFB.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/CIACrypt.o: scanners/CIACrypt.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/CNCD.o: scanners/CNCD.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/CNETFixer.o: scanners/CNETFixer.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/C_Noack.o: scanners/C_Noack.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/CadgersPacker.o: scanners/CadgersPacker.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/Caution.o: scanners/Caution.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/CeleriPack.o: scanners/CeleriPack.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/Cruel.o: scanners/Cruel.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/Crush.o: scanners/Crush.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/Cult.o: scanners/Cult.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/DD.o: scanners/DD.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/DSCcoder.o: scanners/DSCcoder.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/Doynamite.o: scanners/Doynamite.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/DrZoom.o: scanners/DrZoom.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/DarkSqueezer.o: scanners/DarkSqueezer.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/ECA.o: scanners/ECA.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/Eastlinker.o: scanners/Eastlinker.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/EnigmaMFFL.o: scanners/EnigmaMFFL.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/EqByteComp.o: scanners/EqByteComp.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/ExactCoder.o: scanners/ExactCoder.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/Excalibur.o: scanners/Excalibur.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/Exomizer.o: scanners/Exomizer.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/Expert.o: scanners/Expert.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/ExplCrunch.o: scanners/ExplCrunch.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/ExplFaces.o: scanners/ExplFaces.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/ExplXRated.o: scanners/ExplXRated.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/FC3pack.o: scanners/FC3pack.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/FCG.o: scanners/FCG.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/FDTcoder.o: scanners/FDTcoder.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/FP.o: scanners/FP.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/FXbytepress.o: scanners/FXbytepress.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/FXbitstream.o: scanners/FXbitstream.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/Facepacker.o: scanners/Facepacker.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/FilecompactorMTB.o: scanners/FilecompactorMTB.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/FilecompactorTMC.o: scanners/FilecompactorTMC.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/FileLinkerAgony.o: scanners/FileLinkerAgony.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/FinalCompactor.o: scanners/FinalCompactor.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/FinalSuperComp.o: scanners/FinalSuperComp.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/Frog.o: scanners/Frog.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/FrontPacker.o: scanners/FrontPacker.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/Galleon.o: scanners/Galleon.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/Gandalf.o: scanners/Gandalf.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/Anticom.o: scanners/Anticom.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/Antiram.o: scanners/Antiram.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/Gimzo.o: scanners/Gimzo.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/Graffity.o: scanners/Graffity.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/HTLcoder.o: scanners/HTLcoder.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/Huffer.o: scanners/Huffer.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/Hawk.o: scanners/Hawk.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/Helmet.o: scanners/Helmet.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/ICS8.o: scanners/ICS8.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/IDT.o: scanners/IDT.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/ILSCoder.o: scanners/ILSCoder.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/ISC.o: scanners/ISC.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/Ikari.o: scanners/Ikari.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/IsePic.o: scanners/IsePic.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/Jazoo.o: scanners/Jazoo.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/Jazzcat.o: scanners/Jazzcat.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/Jox.o: scanners/Jox.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/Jedi.o: scanners/Jedi.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/Jemasoft.o: scanners/Jemasoft.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/KompressMaster711.o: scanners/KompressMaster711.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/Koncina.o: scanners/Koncina.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/KGB.o: scanners/KGB.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/LSTcoder.o: scanners/LSTcoder.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/LTS.o: scanners/LTS.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/Lightmizer.o: scanners/Lightmizer.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/Loadstar.o: scanners/Loadstar.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/Low.o: scanners/Low.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/Lzss.o: scanners/Lzss.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/MCCrackenComp.o: scanners/MCCrackenComp.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/MDG.o: scanners/MDG.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/MRD.o: scanners/MRD.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/MSI.o: scanners/MSI.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/Maimer.o: scanners/Maimer.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/MartinPiper.o: scanners/MartinPiper.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/MaschSprache.o: scanners/MaschSprache.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/MasterCompressor.o: scanners/MasterCompressor.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/Matcham.o: scanners/Matcham.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/MegaCruncher.o: scanners/MegaCruncher.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/Megabyte.o: scanners/Megabyte.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/MrCross.o: scanners/MrCross.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/MrZ.o: scanners/MrZ.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/NEC.o: scanners/NEC.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/NM156.o: scanners/NM156.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/NSU.o: scanners/NSU.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/NuCrunch.o: scanners/NuCrunch.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/Nibbit.o: scanners/Nibbit.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/ONS.o: scanners/ONS.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/OUG.o: scanners/OUG.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/Optimus.o: scanners/Optimus.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/P100.o: scanners/P100.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/OrionCoder.o: scanners/OrionCoder.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/PWRCoder.o: scanners/PWRCoder.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/PZW.o: scanners/PZW.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/Pride.o: scanners/Pride.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/PackOpt.o: scanners/PackOpt.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/PAN.o: scanners/PAN.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/Panoramic.o: scanners/Panoramic.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/Paradroid.o: scanners/Paradroid.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/Plasma.o: scanners/Plasma.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/PITcoder.o: scanners/PITcoder.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/Polonus.o: scanners/Polonus.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/PuCrunch.o: scanners/PuCrunch.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/Pyra.o: scanners/Pyra.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/RapEq.o: scanners/RapEq.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/Ratt.o: scanners/Ratt.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/Relax.o: scanners/Relax.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/RFOCod.o: scanners/RFOCod.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/SFLinker.o: scanners/SFLinker.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/SKLcoder.o: scanners/SKLcoder.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/ScreenCrunch.o: scanners/ScreenCrunch.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/Section8.o: scanners/Section8.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/Shurigen.o: scanners/Shurigen.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/SirMiniPack.o: scanners/SirMiniPack.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/SledgeHammer.o: scanners/SledgeHammer.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/SpeediComp.o: scanners/SpeediComp.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/Supercrunch.o: scanners/Supercrunch.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/Superpack.o: scanners/Superpack.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/SyncroPack.o: scanners/SyncroPack.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/TAG.o: scanners/TAG.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/TATCod.o: scanners/TATCod.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/TBCMultiComp.o: scanners/TBCMultiComp.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/TCD.o: scanners/TCD.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/TCScrunch.o: scanners/TCScrunch.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/TDT.o: scanners/TDT.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/TMCcoder.o: scanners/TMCcoder.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/THS.o: scanners/THS.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/TKC.o: scanners/TKC.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/TLRLinker.o: scanners/TLRLinker.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/TLRSubsizer.o: scanners/TLRSubsizer.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/TMM.o: scanners/TMM.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/TSB.o: scanners/TSB.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/TSCrunch.o: scanners/TSCrunch.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/TSMcoder.o: scanners/TSMcoder.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/TimeCruncher.o: scanners/TimeCruncher.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/TimCrunch.o: scanners/TimCrunch.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/TinyCrunch.o: scanners/TinyCrunch.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/Trashcan.o: scanners/Trashcan.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/Triangle.o: scanners/Triangle.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/Trianon.o: scanners/Trianon.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/TurboPacker.o: scanners/TurboPacker.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/U_100pack.o: scanners/U_100pack.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/U_101pack.o: scanners/U_101pack.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/U_111pack.o: scanners/U_111pack.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/Rows.o: scanners/Rows.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/FalcoPack.o: scanners/FalcoPack.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/U_400All.o: scanners/U_400All.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/U_439pack.o: scanners/U_439pack.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/U_25_pack.o: scanners/U_25_pack.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/U_8e_pack.o: scanners/U_8e_pack.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/U_DSC_MA.o: scanners/U_DSC_MA.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/U_Generic801.o: scanners/U_Generic801.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/U_P3_pack.o: scanners/U_P3_pack.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/U_fd_pack.o: scanners/U_fd_pack.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/U_Triad.o: scanners/U_Triad.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/KressCrunch.o: scanners/KressCrunch.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/Oneway.o: scanners/Oneway.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/UltraComp.o: scanners/UltraComp.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/UniPacker.o: scanners/UniPacker.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/UProt.o: scanners/UProt.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/VIP.o: scanners/VIP.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/WCC.o: scanners/WCC.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/CC.o: scanners/CC.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/STL.o: scanners/STL.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/WDRsoftp.o: scanners/WDRsoftp.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/WGIcoder.o: scanners/WGIcoder.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/WHO.o: scanners/WHO.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/Warlock.o: scanners/Warlock.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/XDScoder.o: scanners/XDScoder.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/XIP.o: scanners/XIP.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/XTC.o: scanners/XTC.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/GrafBinaer.o: scanners/GrafBinaer.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/Zigag.o: scanners/Zigag.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/Zipper.o: scanners/Zipper.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/Inceria.o: scanners/Inceria.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/Intros.o: scanners/Intros.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/NotPackers.o: scanners/NotPackers.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/xCodeZippers.o: scanners/xCodeZippers.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/AbyssCoder.o: scanners/AbyssCoder.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/SPC.o: scanners/SPC.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/FSW.o: scanners/FSW.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/BAM.o: scanners/BAM.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/Cobra.o: scanners/Cobra.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/Comp64k.o: scanners/Comp64k.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/Mekker.o: scanners/Mekker.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/Autostarters.o: scanners/Autostarters.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/StarCrunch.o: scanners/StarCrunch.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/SpyPack.o: scanners/SpyPack.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/GPacker.o: scanners/GPacker.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/Cadaver.o: scanners/Cadaver.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/YetiCoder.o: scanners/YetiCoder.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/ZeroCoder.o: scanners/ZeroCoder.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/ZX0.o: scanners/ZX0.c	\
unp64.h
	$(compile_source)

$(OBJ_DIR)/_Scanners.o: scanners/_Scanners.c	\
unp64.h
	$(compile_source)

