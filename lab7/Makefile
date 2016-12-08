#===========================================================================
#
# EECS461 at the University of Michigan
# 5643/Metrowerks Makefile for Lab 3
#
# Created 6-15-06, Jeff Lovell, Eric Williams
#
# Last Revised:
# 	7-3-06	lovelljc
# 	8-28-06	ericjw
# 	6-14-14	gpcz
#
#===========================================================================

# Commands to invoke this file:
# 	gmake
# 	gmake scope
# 	gmake clean


#---------------------------------TOOLCHAIN------------------------------------
#---------- Define metrowerks tools to build using command line ---------------
#------------------------------------------------------------------------------

TOOL_OPTS= -proc Zen
LCF_FILE = ../freescale/MPC5643L_DEBUG.lcf

COMPILE_TOOL	 	= $(MW_TOOL)/PowerPC_EABI_Tools/Command_Line_Tools/mwcceppc
COMPILE_TOOL_OPTS	= -vle -DVLE_IS_ON -DROM_VERSION=1 -gdwarf-2 -fp soft -spe_vector -char unsigned $(TOOL_OPTS) -gccincludes -nostdinc -nosyspath -ansi off -bool on -Cpp_exceptions off -ppc_asm_to_vle -O0
# added -O0 flag above to turn off code optimizations; removed "-opt all" - JCL

LINK_TOOL		= $(MW_TOOL)/PowerPC_EABI_Tools/Command_Line_Tools/mwldeppc
LINK_TOOL_OPTS		= -gdwarf-2 -fp soft -char unsigned $(TOOL_OPTS) -nostdlib -srec -lcf $(LCF_FILE)

TOOL_INCLUDES		= -I$(MW_TOOL)/PowerPC_EABI_Support/Runtime/Include \
			  -I$(MW_TOOL)/PowerPC_EABI_Support/Runtime/Src \
			  -I$(MW_TOOL)/PowerPC_EABI_Support/Runtime/Lib \
			  -I$(MW_TOOL)/PowerPC_EABI_Support/MSL/MSL_C/PPC_EABI/Lib \
			  -I$(MW_TOOL)/PowerPC_EABI_Support/MSL/MSL_C/PPC_EABI/Include \
			  -I$(MW_TOOL)/PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/Include \
			  -I$(MW_TOOL)/PowerPC_EABI_Support/MSL/MSL_C++/PPC_EABI/Lib \
			  -I$(MW_TOOL)/PowerPC_EABI_Support/MSL/MSL_C++/PPC_EABI/Include \
			  -I$(MW_TOOL)/PowerPC_EABI_Support/MSL/MSL_C++/MSL_Common/Include

TOOL_CFiles		= IntcInterrupts_p0.c ivor_branch_table_p0.c MPC55xx_init_debug.c MPC5643L_HWInit.c __ppc_eabi_init.c Exceptions.c

TOOL_LIB		= $(MW_TOOL)/PowerPC_EABI_Support/Runtime/Lib/Runtime.PPCEABI.VS.UC.a \
			  $(MW_TOOL)/PowerPC_EABI_Support/MSL/MSL_C/PPC_EABI/Lib/MSL_C.PPCEABI.bare.VS.UC.a

EECS461_CFiles		= serial.c eecs461.c pwm.c pit.c flexcan.c qd.c worlds.c

EECS461_INCLUDES	= -I../include \
			  -I../lib \
			  -I../freescale

#------------------------------------------------------------------------------
#------------------------------------------------------------------------------
#------------------------------------------------------------------------------

INCLUDES 		=  -I. \
			  $(TOOL_INCLUDES) \
			  $(EECS461_INCLUDES)

#-------------------- Definitons for application files: -----------------------
#
# LAB_FILES		= overall lab C code (if applicable)
# ()_FILES		= C code for subcomponents of lab  (if applicable)
# SUPPORT_FILES		= supplimental C files
# S_FILES       	= all application specific assembly source files.
# APP_INCS		= all application specific include files.

#====================================
#============ LAB NAME ==============
#====================================
LAB 			= lab7

SUPPORT_FILES 		= $(TOOL_CFiles)\
			  $(EECS461_CFiles)

LAB_FILES 		= $(LAB).c

CFLAGS 		= $(INCLUDES) \
			  $(CPP_REQ_DEFINES) \
			  $(EXT_CC_OPTS)

LFLAGS 		= $(TOOL_LIB) \
			  $(EXT_LIB) \
			  $(S_FUNCTIONS_LIB) \
			  -Map $(LAB)_$(PART).map

#
#------------------------ Construct the object file lists------------------------
#
SUPPORT_OBJECTS 	= $(addprefix ../freescale/,$(TOOL_CFiles:.c=.o)) $(addprefix ../lib/,$(EECS461_CFiles:.c=.o))
LAB_OBJECTS 		= $(LAB_FILES:.c=_$(PART).o)
OBJ_FILES 		= $(SUPPORT_OBJECTS) $(LAB_OBJECTS)

#
#---------------------------------------Build rules------------------------------
#
#all: $(LAB).elf
#	@echo ################ C Files ################
#	@echo $(SUPPORT_FILES) $(LAB_FILES)
#	@echo ################ Objects ################
#	@echo $(OBJ_FILES)
#	@echo ################ Binary ################
#	@echo $^

all: vwalla vwallb vchain
	@echo ################ C Files ################
	@echo $(SUPPORT_FILES) $(LAB_FILES)
	@echo ################ Objects ################
	@echo $(OBJ_FILES)
	@echo ################ Binary ################
	@echo $^

.PHONY: vwalla
vwalla: 
	$(MAKE) $(LAB)_VWALLA.elf PART=VWALLA
	@echo ################ C Files ################
	@echo $(SUPPORT_FILES) $(LAB_FILES)
	@echo ################ Objects ################
	@echo $(OBJ_FILES)
	@echo ################ Binary ################
	@echo $^

.PHONY: vwallb
vwallb: 
	$(MAKE) $(LAB)_VWALLB.elf PART=VWALLB
	@echo ################ C Files ################
	@echo $(SUPPORT_FILES) $(LAB_FILES)
	@echo ################ Objects ################
	@echo $(OBJ_FILES)
	@echo ################ Binary ################
	@echo $^

.PHONY: vchain
vchain: 
	$(MAKE) $(LAB)_VCHAIN.elf PART=VCHAIN
	@echo ################ C Files ################
	@echo $(SUPPORT_FILES) $(LAB_FILES)
	@echo ################ Objects ################
	@echo $(OBJ_FILES)
	@echo ################ Binary ################
	@echo $^

.PHONY: loopback
loopback: 
	$(MAKE) $(LAB)_LOOPBACK.elf PART=LOOPBACK
	@echo ################ C Files ################
	@echo $(SUPPORT_FILES) $(LAB_FILES)
	@echo ################ Objects ################
	@echo $(OBJ_FILES)
	@echo ################ Binary ################
	@echo $^

clean:
	@echo clean
	@echo ==== Removing object files from build directory ====
	if exist *.o del *.o
	if exist ..\freescale\*.o del ..\freescale\*.o
	if exist ..\lib\*.o del ..\lib\*.o
	if exist *.elf del *.elf
	if exist *.out del *.out
	if exist *.mot del *.mot
	if exist *.map del *.map
	if exist *.bin del *.bin

installvwalla:
	$(MAKE) $(LAB)_VWALLA.elf PART=VWALLA
	$(MW_TOOL)/pemicro/CW_ICDPPCNEXUS.exe $(LAB)_VWALLA.elf LOADTORAM -RESETFILE "mpc5643l_vle.mac"

installvwallb:
	$(MAKE) $(LAB)_VWALLB.elf PART=VWALLB
	$(MW_TOOL)/pemicro/CW_ICDPPCNEXUS.exe $(LAB)_VWALLB.elf LOADTORAM -RESETFILE "mpc5643l_vle.mac"

installvchain:
	$(MAKE) $(LAB)_VCHAIN.elf PART=VCHAIN
	$(MW_TOOL)/pemicro/CW_ICDPPCNEXUS.exe $(LAB)_VCHAIN.elf LOADTORAM -RESETFILE "mpc5643l_vle.mac"

installloopback:
	$(MAKE) $(LAB)_LOOPBACK.elf PART=LOOPBACK
	$(MW_TOOL)/pemicro/CW_ICDPPCNEXUS.exe $(LAB)_LOOPBACK.elf LOADTORAM -RESETFILE "mpc5643l_vle.mac"

#$(LAB).elf: $(OBJ_FILES)
#	@echo **************** BUILDING BINARY $@ ****************
#	if exist $@ del $@
#	$(LINK_TOOL) $^ -o $@ $(LINK_TOOL_OPTS) $(LFLAGS)

$(LAB)_$(PART).elf: $(OBJ_FILES)
	@echo **************** BUILDING BINARY $@ ****************
	if exist $@ del $@
	$(LINK_TOOL) $^ -o $@ $(LINK_TOOL_OPTS) $(LFLAGS)

%.o: %.c
	@echo **************** BUILDING LAB FILE $@ ****************
	$(COMPILE_TOOL) $(COMPILE_TOOL_OPTS) $(CFLAGS) -D$(PART) -o $@ -c $(@:.o=.c)

# this rule matches with stem lab7, and is used to make separate 
# object files for separate debug information sets
%_$(PART).o: %.c
	@echo **************** BUILDING LAB FILE $@ ****************
	@echo $(subst _$(PART),,$(@:.o=.c))
	$(COMPILE_TOOL) $(COMPILE_TOOL_OPTS) $(CFLAGS) -D$(PART) -o $@ -c $(LAB).c

../lib/%.o: ../lib/%.c
	@echo **************** BUILDING LIBRARY FILE $@ ****************
	$(COMPILE_TOOL) $(COMPILE_TOOL_OPTS) $(CFLAGS) -o $@ -c ../lib/$(@:.o=.c)

../freescale/%.o: ../freescale/%.c
	@echo **************** BUILDING TOOL FILE $@ ****************
	$(COMPILE_TOOL) $(COMPILE_TOOL_OPTS) $(CFLAGS) -o $@ -c $(@:.o=.c)

# EOF: MAKEFILE
