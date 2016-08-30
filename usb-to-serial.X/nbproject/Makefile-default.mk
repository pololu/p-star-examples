#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/usb-to-serial.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/usb-to-serial.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=--mafrlcsj
else
COMPARISON_BUILD=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=main.c usb/src/usb_device.c usb/src/usb_device_audio.c usb/src/usb_device_ccid.c usb/src/usb_device_cdc.c usb/src/usb_device_generic.c usb/src/usb_device_hid.c usb/src/usb_device_msd.c usb/src/usb_device_msd_multi_sector.c usb/src/usb_device_phdc.c usb/src/usb_device_phdc_com_model.c usb/src/usb_hal_16bit.c usb/src/usb_hal_dspic33e.c usb/src/usb_hal_pic24.c usb/src/usb_hal_pic24e.c usb/src/usb_hal_pic24f.c usb/src/usb_host.c usb/src/usb_host_android.c usb/src/usb_host_audio_v1.c usb/src/usb_host_cdc.c usb/src/usb_host_cdc_interface.c usb/src/usb_host_generic.c usb/src/usb_host_hid.c usb/src/usb_host_hid_parser.c usb/src/usb_host_midi.c usb/src/usb_host_msd.c usb/src/usb_host_msd_scsi.c usb/src/usb_host_printer.c usb/src/usb_host_printer_esc_pos.c usb/src/usb_host_printer_pcl_5.c usb/src/usb_host_printer_postscript.c usb/src/usb_host_printer_primitives.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/main.p1 ${OBJECTDIR}/usb/src/usb_device.p1 ${OBJECTDIR}/usb/src/usb_device_audio.p1 ${OBJECTDIR}/usb/src/usb_device_ccid.p1 ${OBJECTDIR}/usb/src/usb_device_cdc.p1 ${OBJECTDIR}/usb/src/usb_device_generic.p1 ${OBJECTDIR}/usb/src/usb_device_hid.p1 ${OBJECTDIR}/usb/src/usb_device_msd.p1 ${OBJECTDIR}/usb/src/usb_device_msd_multi_sector.p1 ${OBJECTDIR}/usb/src/usb_device_phdc.p1 ${OBJECTDIR}/usb/src/usb_device_phdc_com_model.p1 ${OBJECTDIR}/usb/src/usb_hal_16bit.p1 ${OBJECTDIR}/usb/src/usb_hal_dspic33e.p1 ${OBJECTDIR}/usb/src/usb_hal_pic24.p1 ${OBJECTDIR}/usb/src/usb_hal_pic24e.p1 ${OBJECTDIR}/usb/src/usb_hal_pic24f.p1 ${OBJECTDIR}/usb/src/usb_host.p1 ${OBJECTDIR}/usb/src/usb_host_android.p1 ${OBJECTDIR}/usb/src/usb_host_audio_v1.p1 ${OBJECTDIR}/usb/src/usb_host_cdc.p1 ${OBJECTDIR}/usb/src/usb_host_cdc_interface.p1 ${OBJECTDIR}/usb/src/usb_host_generic.p1 ${OBJECTDIR}/usb/src/usb_host_hid.p1 ${OBJECTDIR}/usb/src/usb_host_hid_parser.p1 ${OBJECTDIR}/usb/src/usb_host_midi.p1 ${OBJECTDIR}/usb/src/usb_host_msd.p1 ${OBJECTDIR}/usb/src/usb_host_msd_scsi.p1 ${OBJECTDIR}/usb/src/usb_host_printer.p1 ${OBJECTDIR}/usb/src/usb_host_printer_esc_pos.p1 ${OBJECTDIR}/usb/src/usb_host_printer_pcl_5.p1 ${OBJECTDIR}/usb/src/usb_host_printer_postscript.p1 ${OBJECTDIR}/usb/src/usb_host_printer_primitives.p1
POSSIBLE_DEPFILES=${OBJECTDIR}/main.p1.d ${OBJECTDIR}/usb/src/usb_device.p1.d ${OBJECTDIR}/usb/src/usb_device_audio.p1.d ${OBJECTDIR}/usb/src/usb_device_ccid.p1.d ${OBJECTDIR}/usb/src/usb_device_cdc.p1.d ${OBJECTDIR}/usb/src/usb_device_generic.p1.d ${OBJECTDIR}/usb/src/usb_device_hid.p1.d ${OBJECTDIR}/usb/src/usb_device_msd.p1.d ${OBJECTDIR}/usb/src/usb_device_msd_multi_sector.p1.d ${OBJECTDIR}/usb/src/usb_device_phdc.p1.d ${OBJECTDIR}/usb/src/usb_device_phdc_com_model.p1.d ${OBJECTDIR}/usb/src/usb_hal_16bit.p1.d ${OBJECTDIR}/usb/src/usb_hal_dspic33e.p1.d ${OBJECTDIR}/usb/src/usb_hal_pic24.p1.d ${OBJECTDIR}/usb/src/usb_hal_pic24e.p1.d ${OBJECTDIR}/usb/src/usb_hal_pic24f.p1.d ${OBJECTDIR}/usb/src/usb_host.p1.d ${OBJECTDIR}/usb/src/usb_host_android.p1.d ${OBJECTDIR}/usb/src/usb_host_audio_v1.p1.d ${OBJECTDIR}/usb/src/usb_host_cdc.p1.d ${OBJECTDIR}/usb/src/usb_host_cdc_interface.p1.d ${OBJECTDIR}/usb/src/usb_host_generic.p1.d ${OBJECTDIR}/usb/src/usb_host_hid.p1.d ${OBJECTDIR}/usb/src/usb_host_hid_parser.p1.d ${OBJECTDIR}/usb/src/usb_host_midi.p1.d ${OBJECTDIR}/usb/src/usb_host_msd.p1.d ${OBJECTDIR}/usb/src/usb_host_msd_scsi.p1.d ${OBJECTDIR}/usb/src/usb_host_printer.p1.d ${OBJECTDIR}/usb/src/usb_host_printer_esc_pos.p1.d ${OBJECTDIR}/usb/src/usb_host_printer_pcl_5.p1.d ${OBJECTDIR}/usb/src/usb_host_printer_postscript.p1.d ${OBJECTDIR}/usb/src/usb_host_printer_primitives.p1.d

# Object Files
OBJECTFILES=${OBJECTDIR}/main.p1 ${OBJECTDIR}/usb/src/usb_device.p1 ${OBJECTDIR}/usb/src/usb_device_audio.p1 ${OBJECTDIR}/usb/src/usb_device_ccid.p1 ${OBJECTDIR}/usb/src/usb_device_cdc.p1 ${OBJECTDIR}/usb/src/usb_device_generic.p1 ${OBJECTDIR}/usb/src/usb_device_hid.p1 ${OBJECTDIR}/usb/src/usb_device_msd.p1 ${OBJECTDIR}/usb/src/usb_device_msd_multi_sector.p1 ${OBJECTDIR}/usb/src/usb_device_phdc.p1 ${OBJECTDIR}/usb/src/usb_device_phdc_com_model.p1 ${OBJECTDIR}/usb/src/usb_hal_16bit.p1 ${OBJECTDIR}/usb/src/usb_hal_dspic33e.p1 ${OBJECTDIR}/usb/src/usb_hal_pic24.p1 ${OBJECTDIR}/usb/src/usb_hal_pic24e.p1 ${OBJECTDIR}/usb/src/usb_hal_pic24f.p1 ${OBJECTDIR}/usb/src/usb_host.p1 ${OBJECTDIR}/usb/src/usb_host_android.p1 ${OBJECTDIR}/usb/src/usb_host_audio_v1.p1 ${OBJECTDIR}/usb/src/usb_host_cdc.p1 ${OBJECTDIR}/usb/src/usb_host_cdc_interface.p1 ${OBJECTDIR}/usb/src/usb_host_generic.p1 ${OBJECTDIR}/usb/src/usb_host_hid.p1 ${OBJECTDIR}/usb/src/usb_host_hid_parser.p1 ${OBJECTDIR}/usb/src/usb_host_midi.p1 ${OBJECTDIR}/usb/src/usb_host_msd.p1 ${OBJECTDIR}/usb/src/usb_host_msd_scsi.p1 ${OBJECTDIR}/usb/src/usb_host_printer.p1 ${OBJECTDIR}/usb/src/usb_host_printer_esc_pos.p1 ${OBJECTDIR}/usb/src/usb_host_printer_pcl_5.p1 ${OBJECTDIR}/usb/src/usb_host_printer_postscript.p1 ${OBJECTDIR}/usb/src/usb_host_printer_primitives.p1

# Source Files
SOURCEFILES=main.c usb/src/usb_device.c usb/src/usb_device_audio.c usb/src/usb_device_ccid.c usb/src/usb_device_cdc.c usb/src/usb_device_generic.c usb/src/usb_device_hid.c usb/src/usb_device_msd.c usb/src/usb_device_msd_multi_sector.c usb/src/usb_device_phdc.c usb/src/usb_device_phdc_com_model.c usb/src/usb_hal_16bit.c usb/src/usb_hal_dspic33e.c usb/src/usb_hal_pic24.c usb/src/usb_hal_pic24e.c usb/src/usb_hal_pic24f.c usb/src/usb_host.c usb/src/usb_host_android.c usb/src/usb_host_audio_v1.c usb/src/usb_host_cdc.c usb/src/usb_host_cdc_interface.c usb/src/usb_host_generic.c usb/src/usb_host_hid.c usb/src/usb_host_hid_parser.c usb/src/usb_host_midi.c usb/src/usb_host_msd.c usb/src/usb_host_msd_scsi.c usb/src/usb_host_printer.c usb/src/usb_host_printer_esc_pos.c usb/src/usb_host_printer_pcl_5.c usb/src/usb_host_printer_postscript.c usb/src/usb_host_printer_primitives.c


CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/usb-to-serial.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=18F25K50
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/main.p1: main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.p1.d 
	@${RM} ${OBJECTDIR}/main.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 -I"usb/inc" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --codeoffset=0x2000 --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/main.p1  main.c 
	@-${MV} ${OBJECTDIR}/main.d ${OBJECTDIR}/main.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/main.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/usb/src/usb_device.p1: usb/src/usb_device.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/usb/src" 
	@${RM} ${OBJECTDIR}/usb/src/usb_device.p1.d 
	@${RM} ${OBJECTDIR}/usb/src/usb_device.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 -I"usb/inc" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --codeoffset=0x2000 --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/usb/src/usb_device.p1  usb/src/usb_device.c 
	@-${MV} ${OBJECTDIR}/usb/src/usb_device.d ${OBJECTDIR}/usb/src/usb_device.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/usb/src/usb_device.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/usb/src/usb_device_audio.p1: usb/src/usb_device_audio.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/usb/src" 
	@${RM} ${OBJECTDIR}/usb/src/usb_device_audio.p1.d 
	@${RM} ${OBJECTDIR}/usb/src/usb_device_audio.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 -I"usb/inc" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --codeoffset=0x2000 --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/usb/src/usb_device_audio.p1  usb/src/usb_device_audio.c 
	@-${MV} ${OBJECTDIR}/usb/src/usb_device_audio.d ${OBJECTDIR}/usb/src/usb_device_audio.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/usb/src/usb_device_audio.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/usb/src/usb_device_ccid.p1: usb/src/usb_device_ccid.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/usb/src" 
	@${RM} ${OBJECTDIR}/usb/src/usb_device_ccid.p1.d 
	@${RM} ${OBJECTDIR}/usb/src/usb_device_ccid.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 -I"usb/inc" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --codeoffset=0x2000 --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/usb/src/usb_device_ccid.p1  usb/src/usb_device_ccid.c 
	@-${MV} ${OBJECTDIR}/usb/src/usb_device_ccid.d ${OBJECTDIR}/usb/src/usb_device_ccid.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/usb/src/usb_device_ccid.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/usb/src/usb_device_cdc.p1: usb/src/usb_device_cdc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/usb/src" 
	@${RM} ${OBJECTDIR}/usb/src/usb_device_cdc.p1.d 
	@${RM} ${OBJECTDIR}/usb/src/usb_device_cdc.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 -I"usb/inc" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --codeoffset=0x2000 --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/usb/src/usb_device_cdc.p1  usb/src/usb_device_cdc.c 
	@-${MV} ${OBJECTDIR}/usb/src/usb_device_cdc.d ${OBJECTDIR}/usb/src/usb_device_cdc.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/usb/src/usb_device_cdc.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/usb/src/usb_device_generic.p1: usb/src/usb_device_generic.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/usb/src" 
	@${RM} ${OBJECTDIR}/usb/src/usb_device_generic.p1.d 
	@${RM} ${OBJECTDIR}/usb/src/usb_device_generic.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 -I"usb/inc" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --codeoffset=0x2000 --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/usb/src/usb_device_generic.p1  usb/src/usb_device_generic.c 
	@-${MV} ${OBJECTDIR}/usb/src/usb_device_generic.d ${OBJECTDIR}/usb/src/usb_device_generic.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/usb/src/usb_device_generic.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/usb/src/usb_device_hid.p1: usb/src/usb_device_hid.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/usb/src" 
	@${RM} ${OBJECTDIR}/usb/src/usb_device_hid.p1.d 
	@${RM} ${OBJECTDIR}/usb/src/usb_device_hid.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 -I"usb/inc" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --codeoffset=0x2000 --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/usb/src/usb_device_hid.p1  usb/src/usb_device_hid.c 
	@-${MV} ${OBJECTDIR}/usb/src/usb_device_hid.d ${OBJECTDIR}/usb/src/usb_device_hid.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/usb/src/usb_device_hid.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/usb/src/usb_device_msd.p1: usb/src/usb_device_msd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/usb/src" 
	@${RM} ${OBJECTDIR}/usb/src/usb_device_msd.p1.d 
	@${RM} ${OBJECTDIR}/usb/src/usb_device_msd.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 -I"usb/inc" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --codeoffset=0x2000 --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/usb/src/usb_device_msd.p1  usb/src/usb_device_msd.c 
	@-${MV} ${OBJECTDIR}/usb/src/usb_device_msd.d ${OBJECTDIR}/usb/src/usb_device_msd.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/usb/src/usb_device_msd.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/usb/src/usb_device_msd_multi_sector.p1: usb/src/usb_device_msd_multi_sector.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/usb/src" 
	@${RM} ${OBJECTDIR}/usb/src/usb_device_msd_multi_sector.p1.d 
	@${RM} ${OBJECTDIR}/usb/src/usb_device_msd_multi_sector.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 -I"usb/inc" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --codeoffset=0x2000 --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/usb/src/usb_device_msd_multi_sector.p1  usb/src/usb_device_msd_multi_sector.c 
	@-${MV} ${OBJECTDIR}/usb/src/usb_device_msd_multi_sector.d ${OBJECTDIR}/usb/src/usb_device_msd_multi_sector.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/usb/src/usb_device_msd_multi_sector.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/usb/src/usb_device_phdc.p1: usb/src/usb_device_phdc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/usb/src" 
	@${RM} ${OBJECTDIR}/usb/src/usb_device_phdc.p1.d 
	@${RM} ${OBJECTDIR}/usb/src/usb_device_phdc.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 -I"usb/inc" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --codeoffset=0x2000 --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/usb/src/usb_device_phdc.p1  usb/src/usb_device_phdc.c 
	@-${MV} ${OBJECTDIR}/usb/src/usb_device_phdc.d ${OBJECTDIR}/usb/src/usb_device_phdc.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/usb/src/usb_device_phdc.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/usb/src/usb_device_phdc_com_model.p1: usb/src/usb_device_phdc_com_model.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/usb/src" 
	@${RM} ${OBJECTDIR}/usb/src/usb_device_phdc_com_model.p1.d 
	@${RM} ${OBJECTDIR}/usb/src/usb_device_phdc_com_model.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 -I"usb/inc" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --codeoffset=0x2000 --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/usb/src/usb_device_phdc_com_model.p1  usb/src/usb_device_phdc_com_model.c 
	@-${MV} ${OBJECTDIR}/usb/src/usb_device_phdc_com_model.d ${OBJECTDIR}/usb/src/usb_device_phdc_com_model.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/usb/src/usb_device_phdc_com_model.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/usb/src/usb_hal_16bit.p1: usb/src/usb_hal_16bit.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/usb/src" 
	@${RM} ${OBJECTDIR}/usb/src/usb_hal_16bit.p1.d 
	@${RM} ${OBJECTDIR}/usb/src/usb_hal_16bit.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 -I"usb/inc" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --codeoffset=0x2000 --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/usb/src/usb_hal_16bit.p1  usb/src/usb_hal_16bit.c 
	@-${MV} ${OBJECTDIR}/usb/src/usb_hal_16bit.d ${OBJECTDIR}/usb/src/usb_hal_16bit.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/usb/src/usb_hal_16bit.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/usb/src/usb_hal_dspic33e.p1: usb/src/usb_hal_dspic33e.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/usb/src" 
	@${RM} ${OBJECTDIR}/usb/src/usb_hal_dspic33e.p1.d 
	@${RM} ${OBJECTDIR}/usb/src/usb_hal_dspic33e.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 -I"usb/inc" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --codeoffset=0x2000 --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/usb/src/usb_hal_dspic33e.p1  usb/src/usb_hal_dspic33e.c 
	@-${MV} ${OBJECTDIR}/usb/src/usb_hal_dspic33e.d ${OBJECTDIR}/usb/src/usb_hal_dspic33e.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/usb/src/usb_hal_dspic33e.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/usb/src/usb_hal_pic24.p1: usb/src/usb_hal_pic24.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/usb/src" 
	@${RM} ${OBJECTDIR}/usb/src/usb_hal_pic24.p1.d 
	@${RM} ${OBJECTDIR}/usb/src/usb_hal_pic24.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 -I"usb/inc" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --codeoffset=0x2000 --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/usb/src/usb_hal_pic24.p1  usb/src/usb_hal_pic24.c 
	@-${MV} ${OBJECTDIR}/usb/src/usb_hal_pic24.d ${OBJECTDIR}/usb/src/usb_hal_pic24.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/usb/src/usb_hal_pic24.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/usb/src/usb_hal_pic24e.p1: usb/src/usb_hal_pic24e.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/usb/src" 
	@${RM} ${OBJECTDIR}/usb/src/usb_hal_pic24e.p1.d 
	@${RM} ${OBJECTDIR}/usb/src/usb_hal_pic24e.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 -I"usb/inc" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --codeoffset=0x2000 --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/usb/src/usb_hal_pic24e.p1  usb/src/usb_hal_pic24e.c 
	@-${MV} ${OBJECTDIR}/usb/src/usb_hal_pic24e.d ${OBJECTDIR}/usb/src/usb_hal_pic24e.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/usb/src/usb_hal_pic24e.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/usb/src/usb_hal_pic24f.p1: usb/src/usb_hal_pic24f.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/usb/src" 
	@${RM} ${OBJECTDIR}/usb/src/usb_hal_pic24f.p1.d 
	@${RM} ${OBJECTDIR}/usb/src/usb_hal_pic24f.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 -I"usb/inc" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --codeoffset=0x2000 --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/usb/src/usb_hal_pic24f.p1  usb/src/usb_hal_pic24f.c 
	@-${MV} ${OBJECTDIR}/usb/src/usb_hal_pic24f.d ${OBJECTDIR}/usb/src/usb_hal_pic24f.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/usb/src/usb_hal_pic24f.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/usb/src/usb_host.p1: usb/src/usb_host.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/usb/src" 
	@${RM} ${OBJECTDIR}/usb/src/usb_host.p1.d 
	@${RM} ${OBJECTDIR}/usb/src/usb_host.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 -I"usb/inc" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --codeoffset=0x2000 --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/usb/src/usb_host.p1  usb/src/usb_host.c 
	@-${MV} ${OBJECTDIR}/usb/src/usb_host.d ${OBJECTDIR}/usb/src/usb_host.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/usb/src/usb_host.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/usb/src/usb_host_android.p1: usb/src/usb_host_android.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/usb/src" 
	@${RM} ${OBJECTDIR}/usb/src/usb_host_android.p1.d 
	@${RM} ${OBJECTDIR}/usb/src/usb_host_android.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 -I"usb/inc" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --codeoffset=0x2000 --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/usb/src/usb_host_android.p1  usb/src/usb_host_android.c 
	@-${MV} ${OBJECTDIR}/usb/src/usb_host_android.d ${OBJECTDIR}/usb/src/usb_host_android.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/usb/src/usb_host_android.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/usb/src/usb_host_audio_v1.p1: usb/src/usb_host_audio_v1.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/usb/src" 
	@${RM} ${OBJECTDIR}/usb/src/usb_host_audio_v1.p1.d 
	@${RM} ${OBJECTDIR}/usb/src/usb_host_audio_v1.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 -I"usb/inc" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --codeoffset=0x2000 --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/usb/src/usb_host_audio_v1.p1  usb/src/usb_host_audio_v1.c 
	@-${MV} ${OBJECTDIR}/usb/src/usb_host_audio_v1.d ${OBJECTDIR}/usb/src/usb_host_audio_v1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/usb/src/usb_host_audio_v1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/usb/src/usb_host_cdc.p1: usb/src/usb_host_cdc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/usb/src" 
	@${RM} ${OBJECTDIR}/usb/src/usb_host_cdc.p1.d 
	@${RM} ${OBJECTDIR}/usb/src/usb_host_cdc.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 -I"usb/inc" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --codeoffset=0x2000 --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/usb/src/usb_host_cdc.p1  usb/src/usb_host_cdc.c 
	@-${MV} ${OBJECTDIR}/usb/src/usb_host_cdc.d ${OBJECTDIR}/usb/src/usb_host_cdc.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/usb/src/usb_host_cdc.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/usb/src/usb_host_cdc_interface.p1: usb/src/usb_host_cdc_interface.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/usb/src" 
	@${RM} ${OBJECTDIR}/usb/src/usb_host_cdc_interface.p1.d 
	@${RM} ${OBJECTDIR}/usb/src/usb_host_cdc_interface.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 -I"usb/inc" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --codeoffset=0x2000 --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/usb/src/usb_host_cdc_interface.p1  usb/src/usb_host_cdc_interface.c 
	@-${MV} ${OBJECTDIR}/usb/src/usb_host_cdc_interface.d ${OBJECTDIR}/usb/src/usb_host_cdc_interface.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/usb/src/usb_host_cdc_interface.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/usb/src/usb_host_generic.p1: usb/src/usb_host_generic.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/usb/src" 
	@${RM} ${OBJECTDIR}/usb/src/usb_host_generic.p1.d 
	@${RM} ${OBJECTDIR}/usb/src/usb_host_generic.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 -I"usb/inc" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --codeoffset=0x2000 --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/usb/src/usb_host_generic.p1  usb/src/usb_host_generic.c 
	@-${MV} ${OBJECTDIR}/usb/src/usb_host_generic.d ${OBJECTDIR}/usb/src/usb_host_generic.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/usb/src/usb_host_generic.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/usb/src/usb_host_hid.p1: usb/src/usb_host_hid.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/usb/src" 
	@${RM} ${OBJECTDIR}/usb/src/usb_host_hid.p1.d 
	@${RM} ${OBJECTDIR}/usb/src/usb_host_hid.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 -I"usb/inc" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --codeoffset=0x2000 --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/usb/src/usb_host_hid.p1  usb/src/usb_host_hid.c 
	@-${MV} ${OBJECTDIR}/usb/src/usb_host_hid.d ${OBJECTDIR}/usb/src/usb_host_hid.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/usb/src/usb_host_hid.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/usb/src/usb_host_hid_parser.p1: usb/src/usb_host_hid_parser.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/usb/src" 
	@${RM} ${OBJECTDIR}/usb/src/usb_host_hid_parser.p1.d 
	@${RM} ${OBJECTDIR}/usb/src/usb_host_hid_parser.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 -I"usb/inc" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --codeoffset=0x2000 --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/usb/src/usb_host_hid_parser.p1  usb/src/usb_host_hid_parser.c 
	@-${MV} ${OBJECTDIR}/usb/src/usb_host_hid_parser.d ${OBJECTDIR}/usb/src/usb_host_hid_parser.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/usb/src/usb_host_hid_parser.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/usb/src/usb_host_midi.p1: usb/src/usb_host_midi.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/usb/src" 
	@${RM} ${OBJECTDIR}/usb/src/usb_host_midi.p1.d 
	@${RM} ${OBJECTDIR}/usb/src/usb_host_midi.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 -I"usb/inc" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --codeoffset=0x2000 --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/usb/src/usb_host_midi.p1  usb/src/usb_host_midi.c 
	@-${MV} ${OBJECTDIR}/usb/src/usb_host_midi.d ${OBJECTDIR}/usb/src/usb_host_midi.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/usb/src/usb_host_midi.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/usb/src/usb_host_msd.p1: usb/src/usb_host_msd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/usb/src" 
	@${RM} ${OBJECTDIR}/usb/src/usb_host_msd.p1.d 
	@${RM} ${OBJECTDIR}/usb/src/usb_host_msd.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 -I"usb/inc" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --codeoffset=0x2000 --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/usb/src/usb_host_msd.p1  usb/src/usb_host_msd.c 
	@-${MV} ${OBJECTDIR}/usb/src/usb_host_msd.d ${OBJECTDIR}/usb/src/usb_host_msd.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/usb/src/usb_host_msd.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/usb/src/usb_host_msd_scsi.p1: usb/src/usb_host_msd_scsi.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/usb/src" 
	@${RM} ${OBJECTDIR}/usb/src/usb_host_msd_scsi.p1.d 
	@${RM} ${OBJECTDIR}/usb/src/usb_host_msd_scsi.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 -I"usb/inc" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --codeoffset=0x2000 --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/usb/src/usb_host_msd_scsi.p1  usb/src/usb_host_msd_scsi.c 
	@-${MV} ${OBJECTDIR}/usb/src/usb_host_msd_scsi.d ${OBJECTDIR}/usb/src/usb_host_msd_scsi.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/usb/src/usb_host_msd_scsi.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/usb/src/usb_host_printer.p1: usb/src/usb_host_printer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/usb/src" 
	@${RM} ${OBJECTDIR}/usb/src/usb_host_printer.p1.d 
	@${RM} ${OBJECTDIR}/usb/src/usb_host_printer.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 -I"usb/inc" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --codeoffset=0x2000 --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/usb/src/usb_host_printer.p1  usb/src/usb_host_printer.c 
	@-${MV} ${OBJECTDIR}/usb/src/usb_host_printer.d ${OBJECTDIR}/usb/src/usb_host_printer.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/usb/src/usb_host_printer.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/usb/src/usb_host_printer_esc_pos.p1: usb/src/usb_host_printer_esc_pos.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/usb/src" 
	@${RM} ${OBJECTDIR}/usb/src/usb_host_printer_esc_pos.p1.d 
	@${RM} ${OBJECTDIR}/usb/src/usb_host_printer_esc_pos.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 -I"usb/inc" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --codeoffset=0x2000 --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/usb/src/usb_host_printer_esc_pos.p1  usb/src/usb_host_printer_esc_pos.c 
	@-${MV} ${OBJECTDIR}/usb/src/usb_host_printer_esc_pos.d ${OBJECTDIR}/usb/src/usb_host_printer_esc_pos.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/usb/src/usb_host_printer_esc_pos.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/usb/src/usb_host_printer_pcl_5.p1: usb/src/usb_host_printer_pcl_5.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/usb/src" 
	@${RM} ${OBJECTDIR}/usb/src/usb_host_printer_pcl_5.p1.d 
	@${RM} ${OBJECTDIR}/usb/src/usb_host_printer_pcl_5.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 -I"usb/inc" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --codeoffset=0x2000 --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/usb/src/usb_host_printer_pcl_5.p1  usb/src/usb_host_printer_pcl_5.c 
	@-${MV} ${OBJECTDIR}/usb/src/usb_host_printer_pcl_5.d ${OBJECTDIR}/usb/src/usb_host_printer_pcl_5.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/usb/src/usb_host_printer_pcl_5.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/usb/src/usb_host_printer_postscript.p1: usb/src/usb_host_printer_postscript.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/usb/src" 
	@${RM} ${OBJECTDIR}/usb/src/usb_host_printer_postscript.p1.d 
	@${RM} ${OBJECTDIR}/usb/src/usb_host_printer_postscript.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 -I"usb/inc" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --codeoffset=0x2000 --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/usb/src/usb_host_printer_postscript.p1  usb/src/usb_host_printer_postscript.c 
	@-${MV} ${OBJECTDIR}/usb/src/usb_host_printer_postscript.d ${OBJECTDIR}/usb/src/usb_host_printer_postscript.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/usb/src/usb_host_printer_postscript.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/usb/src/usb_host_printer_primitives.p1: usb/src/usb_host_printer_primitives.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/usb/src" 
	@${RM} ${OBJECTDIR}/usb/src/usb_host_printer_primitives.p1.d 
	@${RM} ${OBJECTDIR}/usb/src/usb_host_printer_primitives.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 -I"usb/inc" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --codeoffset=0x2000 --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/usb/src/usb_host_printer_primitives.p1  usb/src/usb_host_printer_primitives.c 
	@-${MV} ${OBJECTDIR}/usb/src/usb_host_printer_primitives.d ${OBJECTDIR}/usb/src/usb_host_printer_primitives.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/usb/src/usb_host_printer_primitives.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
else
${OBJECTDIR}/main.p1: main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.p1.d 
	@${RM} ${OBJECTDIR}/main.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 -I"usb/inc" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --codeoffset=0x2000 --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/main.p1  main.c 
	@-${MV} ${OBJECTDIR}/main.d ${OBJECTDIR}/main.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/main.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/usb/src/usb_device.p1: usb/src/usb_device.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/usb/src" 
	@${RM} ${OBJECTDIR}/usb/src/usb_device.p1.d 
	@${RM} ${OBJECTDIR}/usb/src/usb_device.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 -I"usb/inc" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --codeoffset=0x2000 --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/usb/src/usb_device.p1  usb/src/usb_device.c 
	@-${MV} ${OBJECTDIR}/usb/src/usb_device.d ${OBJECTDIR}/usb/src/usb_device.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/usb/src/usb_device.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/usb/src/usb_device_audio.p1: usb/src/usb_device_audio.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/usb/src" 
	@${RM} ${OBJECTDIR}/usb/src/usb_device_audio.p1.d 
	@${RM} ${OBJECTDIR}/usb/src/usb_device_audio.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 -I"usb/inc" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --codeoffset=0x2000 --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/usb/src/usb_device_audio.p1  usb/src/usb_device_audio.c 
	@-${MV} ${OBJECTDIR}/usb/src/usb_device_audio.d ${OBJECTDIR}/usb/src/usb_device_audio.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/usb/src/usb_device_audio.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/usb/src/usb_device_ccid.p1: usb/src/usb_device_ccid.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/usb/src" 
	@${RM} ${OBJECTDIR}/usb/src/usb_device_ccid.p1.d 
	@${RM} ${OBJECTDIR}/usb/src/usb_device_ccid.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 -I"usb/inc" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --codeoffset=0x2000 --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/usb/src/usb_device_ccid.p1  usb/src/usb_device_ccid.c 
	@-${MV} ${OBJECTDIR}/usb/src/usb_device_ccid.d ${OBJECTDIR}/usb/src/usb_device_ccid.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/usb/src/usb_device_ccid.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/usb/src/usb_device_cdc.p1: usb/src/usb_device_cdc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/usb/src" 
	@${RM} ${OBJECTDIR}/usb/src/usb_device_cdc.p1.d 
	@${RM} ${OBJECTDIR}/usb/src/usb_device_cdc.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 -I"usb/inc" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --codeoffset=0x2000 --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/usb/src/usb_device_cdc.p1  usb/src/usb_device_cdc.c 
	@-${MV} ${OBJECTDIR}/usb/src/usb_device_cdc.d ${OBJECTDIR}/usb/src/usb_device_cdc.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/usb/src/usb_device_cdc.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/usb/src/usb_device_generic.p1: usb/src/usb_device_generic.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/usb/src" 
	@${RM} ${OBJECTDIR}/usb/src/usb_device_generic.p1.d 
	@${RM} ${OBJECTDIR}/usb/src/usb_device_generic.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 -I"usb/inc" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --codeoffset=0x2000 --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/usb/src/usb_device_generic.p1  usb/src/usb_device_generic.c 
	@-${MV} ${OBJECTDIR}/usb/src/usb_device_generic.d ${OBJECTDIR}/usb/src/usb_device_generic.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/usb/src/usb_device_generic.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/usb/src/usb_device_hid.p1: usb/src/usb_device_hid.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/usb/src" 
	@${RM} ${OBJECTDIR}/usb/src/usb_device_hid.p1.d 
	@${RM} ${OBJECTDIR}/usb/src/usb_device_hid.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 -I"usb/inc" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --codeoffset=0x2000 --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/usb/src/usb_device_hid.p1  usb/src/usb_device_hid.c 
	@-${MV} ${OBJECTDIR}/usb/src/usb_device_hid.d ${OBJECTDIR}/usb/src/usb_device_hid.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/usb/src/usb_device_hid.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/usb/src/usb_device_msd.p1: usb/src/usb_device_msd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/usb/src" 
	@${RM} ${OBJECTDIR}/usb/src/usb_device_msd.p1.d 
	@${RM} ${OBJECTDIR}/usb/src/usb_device_msd.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 -I"usb/inc" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --codeoffset=0x2000 --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/usb/src/usb_device_msd.p1  usb/src/usb_device_msd.c 
	@-${MV} ${OBJECTDIR}/usb/src/usb_device_msd.d ${OBJECTDIR}/usb/src/usb_device_msd.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/usb/src/usb_device_msd.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/usb/src/usb_device_msd_multi_sector.p1: usb/src/usb_device_msd_multi_sector.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/usb/src" 
	@${RM} ${OBJECTDIR}/usb/src/usb_device_msd_multi_sector.p1.d 
	@${RM} ${OBJECTDIR}/usb/src/usb_device_msd_multi_sector.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 -I"usb/inc" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --codeoffset=0x2000 --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/usb/src/usb_device_msd_multi_sector.p1  usb/src/usb_device_msd_multi_sector.c 
	@-${MV} ${OBJECTDIR}/usb/src/usb_device_msd_multi_sector.d ${OBJECTDIR}/usb/src/usb_device_msd_multi_sector.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/usb/src/usb_device_msd_multi_sector.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/usb/src/usb_device_phdc.p1: usb/src/usb_device_phdc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/usb/src" 
	@${RM} ${OBJECTDIR}/usb/src/usb_device_phdc.p1.d 
	@${RM} ${OBJECTDIR}/usb/src/usb_device_phdc.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 -I"usb/inc" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --codeoffset=0x2000 --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/usb/src/usb_device_phdc.p1  usb/src/usb_device_phdc.c 
	@-${MV} ${OBJECTDIR}/usb/src/usb_device_phdc.d ${OBJECTDIR}/usb/src/usb_device_phdc.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/usb/src/usb_device_phdc.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/usb/src/usb_device_phdc_com_model.p1: usb/src/usb_device_phdc_com_model.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/usb/src" 
	@${RM} ${OBJECTDIR}/usb/src/usb_device_phdc_com_model.p1.d 
	@${RM} ${OBJECTDIR}/usb/src/usb_device_phdc_com_model.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 -I"usb/inc" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --codeoffset=0x2000 --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/usb/src/usb_device_phdc_com_model.p1  usb/src/usb_device_phdc_com_model.c 
	@-${MV} ${OBJECTDIR}/usb/src/usb_device_phdc_com_model.d ${OBJECTDIR}/usb/src/usb_device_phdc_com_model.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/usb/src/usb_device_phdc_com_model.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/usb/src/usb_hal_16bit.p1: usb/src/usb_hal_16bit.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/usb/src" 
	@${RM} ${OBJECTDIR}/usb/src/usb_hal_16bit.p1.d 
	@${RM} ${OBJECTDIR}/usb/src/usb_hal_16bit.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 -I"usb/inc" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --codeoffset=0x2000 --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/usb/src/usb_hal_16bit.p1  usb/src/usb_hal_16bit.c 
	@-${MV} ${OBJECTDIR}/usb/src/usb_hal_16bit.d ${OBJECTDIR}/usb/src/usb_hal_16bit.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/usb/src/usb_hal_16bit.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/usb/src/usb_hal_dspic33e.p1: usb/src/usb_hal_dspic33e.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/usb/src" 
	@${RM} ${OBJECTDIR}/usb/src/usb_hal_dspic33e.p1.d 
	@${RM} ${OBJECTDIR}/usb/src/usb_hal_dspic33e.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 -I"usb/inc" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --codeoffset=0x2000 --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/usb/src/usb_hal_dspic33e.p1  usb/src/usb_hal_dspic33e.c 
	@-${MV} ${OBJECTDIR}/usb/src/usb_hal_dspic33e.d ${OBJECTDIR}/usb/src/usb_hal_dspic33e.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/usb/src/usb_hal_dspic33e.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/usb/src/usb_hal_pic24.p1: usb/src/usb_hal_pic24.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/usb/src" 
	@${RM} ${OBJECTDIR}/usb/src/usb_hal_pic24.p1.d 
	@${RM} ${OBJECTDIR}/usb/src/usb_hal_pic24.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 -I"usb/inc" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --codeoffset=0x2000 --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/usb/src/usb_hal_pic24.p1  usb/src/usb_hal_pic24.c 
	@-${MV} ${OBJECTDIR}/usb/src/usb_hal_pic24.d ${OBJECTDIR}/usb/src/usb_hal_pic24.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/usb/src/usb_hal_pic24.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/usb/src/usb_hal_pic24e.p1: usb/src/usb_hal_pic24e.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/usb/src" 
	@${RM} ${OBJECTDIR}/usb/src/usb_hal_pic24e.p1.d 
	@${RM} ${OBJECTDIR}/usb/src/usb_hal_pic24e.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 -I"usb/inc" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --codeoffset=0x2000 --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/usb/src/usb_hal_pic24e.p1  usb/src/usb_hal_pic24e.c 
	@-${MV} ${OBJECTDIR}/usb/src/usb_hal_pic24e.d ${OBJECTDIR}/usb/src/usb_hal_pic24e.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/usb/src/usb_hal_pic24e.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/usb/src/usb_hal_pic24f.p1: usb/src/usb_hal_pic24f.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/usb/src" 
	@${RM} ${OBJECTDIR}/usb/src/usb_hal_pic24f.p1.d 
	@${RM} ${OBJECTDIR}/usb/src/usb_hal_pic24f.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 -I"usb/inc" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --codeoffset=0x2000 --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/usb/src/usb_hal_pic24f.p1  usb/src/usb_hal_pic24f.c 
	@-${MV} ${OBJECTDIR}/usb/src/usb_hal_pic24f.d ${OBJECTDIR}/usb/src/usb_hal_pic24f.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/usb/src/usb_hal_pic24f.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/usb/src/usb_host.p1: usb/src/usb_host.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/usb/src" 
	@${RM} ${OBJECTDIR}/usb/src/usb_host.p1.d 
	@${RM} ${OBJECTDIR}/usb/src/usb_host.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 -I"usb/inc" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --codeoffset=0x2000 --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/usb/src/usb_host.p1  usb/src/usb_host.c 
	@-${MV} ${OBJECTDIR}/usb/src/usb_host.d ${OBJECTDIR}/usb/src/usb_host.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/usb/src/usb_host.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/usb/src/usb_host_android.p1: usb/src/usb_host_android.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/usb/src" 
	@${RM} ${OBJECTDIR}/usb/src/usb_host_android.p1.d 
	@${RM} ${OBJECTDIR}/usb/src/usb_host_android.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 -I"usb/inc" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --codeoffset=0x2000 --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/usb/src/usb_host_android.p1  usb/src/usb_host_android.c 
	@-${MV} ${OBJECTDIR}/usb/src/usb_host_android.d ${OBJECTDIR}/usb/src/usb_host_android.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/usb/src/usb_host_android.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/usb/src/usb_host_audio_v1.p1: usb/src/usb_host_audio_v1.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/usb/src" 
	@${RM} ${OBJECTDIR}/usb/src/usb_host_audio_v1.p1.d 
	@${RM} ${OBJECTDIR}/usb/src/usb_host_audio_v1.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 -I"usb/inc" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --codeoffset=0x2000 --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/usb/src/usb_host_audio_v1.p1  usb/src/usb_host_audio_v1.c 
	@-${MV} ${OBJECTDIR}/usb/src/usb_host_audio_v1.d ${OBJECTDIR}/usb/src/usb_host_audio_v1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/usb/src/usb_host_audio_v1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/usb/src/usb_host_cdc.p1: usb/src/usb_host_cdc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/usb/src" 
	@${RM} ${OBJECTDIR}/usb/src/usb_host_cdc.p1.d 
	@${RM} ${OBJECTDIR}/usb/src/usb_host_cdc.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 -I"usb/inc" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --codeoffset=0x2000 --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/usb/src/usb_host_cdc.p1  usb/src/usb_host_cdc.c 
	@-${MV} ${OBJECTDIR}/usb/src/usb_host_cdc.d ${OBJECTDIR}/usb/src/usb_host_cdc.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/usb/src/usb_host_cdc.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/usb/src/usb_host_cdc_interface.p1: usb/src/usb_host_cdc_interface.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/usb/src" 
	@${RM} ${OBJECTDIR}/usb/src/usb_host_cdc_interface.p1.d 
	@${RM} ${OBJECTDIR}/usb/src/usb_host_cdc_interface.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 -I"usb/inc" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --codeoffset=0x2000 --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/usb/src/usb_host_cdc_interface.p1  usb/src/usb_host_cdc_interface.c 
	@-${MV} ${OBJECTDIR}/usb/src/usb_host_cdc_interface.d ${OBJECTDIR}/usb/src/usb_host_cdc_interface.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/usb/src/usb_host_cdc_interface.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/usb/src/usb_host_generic.p1: usb/src/usb_host_generic.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/usb/src" 
	@${RM} ${OBJECTDIR}/usb/src/usb_host_generic.p1.d 
	@${RM} ${OBJECTDIR}/usb/src/usb_host_generic.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 -I"usb/inc" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --codeoffset=0x2000 --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/usb/src/usb_host_generic.p1  usb/src/usb_host_generic.c 
	@-${MV} ${OBJECTDIR}/usb/src/usb_host_generic.d ${OBJECTDIR}/usb/src/usb_host_generic.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/usb/src/usb_host_generic.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/usb/src/usb_host_hid.p1: usb/src/usb_host_hid.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/usb/src" 
	@${RM} ${OBJECTDIR}/usb/src/usb_host_hid.p1.d 
	@${RM} ${OBJECTDIR}/usb/src/usb_host_hid.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 -I"usb/inc" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --codeoffset=0x2000 --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/usb/src/usb_host_hid.p1  usb/src/usb_host_hid.c 
	@-${MV} ${OBJECTDIR}/usb/src/usb_host_hid.d ${OBJECTDIR}/usb/src/usb_host_hid.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/usb/src/usb_host_hid.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/usb/src/usb_host_hid_parser.p1: usb/src/usb_host_hid_parser.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/usb/src" 
	@${RM} ${OBJECTDIR}/usb/src/usb_host_hid_parser.p1.d 
	@${RM} ${OBJECTDIR}/usb/src/usb_host_hid_parser.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 -I"usb/inc" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --codeoffset=0x2000 --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/usb/src/usb_host_hid_parser.p1  usb/src/usb_host_hid_parser.c 
	@-${MV} ${OBJECTDIR}/usb/src/usb_host_hid_parser.d ${OBJECTDIR}/usb/src/usb_host_hid_parser.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/usb/src/usb_host_hid_parser.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/usb/src/usb_host_midi.p1: usb/src/usb_host_midi.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/usb/src" 
	@${RM} ${OBJECTDIR}/usb/src/usb_host_midi.p1.d 
	@${RM} ${OBJECTDIR}/usb/src/usb_host_midi.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 -I"usb/inc" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --codeoffset=0x2000 --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/usb/src/usb_host_midi.p1  usb/src/usb_host_midi.c 
	@-${MV} ${OBJECTDIR}/usb/src/usb_host_midi.d ${OBJECTDIR}/usb/src/usb_host_midi.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/usb/src/usb_host_midi.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/usb/src/usb_host_msd.p1: usb/src/usb_host_msd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/usb/src" 
	@${RM} ${OBJECTDIR}/usb/src/usb_host_msd.p1.d 
	@${RM} ${OBJECTDIR}/usb/src/usb_host_msd.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 -I"usb/inc" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --codeoffset=0x2000 --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/usb/src/usb_host_msd.p1  usb/src/usb_host_msd.c 
	@-${MV} ${OBJECTDIR}/usb/src/usb_host_msd.d ${OBJECTDIR}/usb/src/usb_host_msd.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/usb/src/usb_host_msd.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/usb/src/usb_host_msd_scsi.p1: usb/src/usb_host_msd_scsi.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/usb/src" 
	@${RM} ${OBJECTDIR}/usb/src/usb_host_msd_scsi.p1.d 
	@${RM} ${OBJECTDIR}/usb/src/usb_host_msd_scsi.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 -I"usb/inc" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --codeoffset=0x2000 --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/usb/src/usb_host_msd_scsi.p1  usb/src/usb_host_msd_scsi.c 
	@-${MV} ${OBJECTDIR}/usb/src/usb_host_msd_scsi.d ${OBJECTDIR}/usb/src/usb_host_msd_scsi.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/usb/src/usb_host_msd_scsi.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/usb/src/usb_host_printer.p1: usb/src/usb_host_printer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/usb/src" 
	@${RM} ${OBJECTDIR}/usb/src/usb_host_printer.p1.d 
	@${RM} ${OBJECTDIR}/usb/src/usb_host_printer.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 -I"usb/inc" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --codeoffset=0x2000 --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/usb/src/usb_host_printer.p1  usb/src/usb_host_printer.c 
	@-${MV} ${OBJECTDIR}/usb/src/usb_host_printer.d ${OBJECTDIR}/usb/src/usb_host_printer.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/usb/src/usb_host_printer.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/usb/src/usb_host_printer_esc_pos.p1: usb/src/usb_host_printer_esc_pos.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/usb/src" 
	@${RM} ${OBJECTDIR}/usb/src/usb_host_printer_esc_pos.p1.d 
	@${RM} ${OBJECTDIR}/usb/src/usb_host_printer_esc_pos.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 -I"usb/inc" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --codeoffset=0x2000 --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/usb/src/usb_host_printer_esc_pos.p1  usb/src/usb_host_printer_esc_pos.c 
	@-${MV} ${OBJECTDIR}/usb/src/usb_host_printer_esc_pos.d ${OBJECTDIR}/usb/src/usb_host_printer_esc_pos.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/usb/src/usb_host_printer_esc_pos.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/usb/src/usb_host_printer_pcl_5.p1: usb/src/usb_host_printer_pcl_5.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/usb/src" 
	@${RM} ${OBJECTDIR}/usb/src/usb_host_printer_pcl_5.p1.d 
	@${RM} ${OBJECTDIR}/usb/src/usb_host_printer_pcl_5.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 -I"usb/inc" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --codeoffset=0x2000 --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/usb/src/usb_host_printer_pcl_5.p1  usb/src/usb_host_printer_pcl_5.c 
	@-${MV} ${OBJECTDIR}/usb/src/usb_host_printer_pcl_5.d ${OBJECTDIR}/usb/src/usb_host_printer_pcl_5.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/usb/src/usb_host_printer_pcl_5.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/usb/src/usb_host_printer_postscript.p1: usb/src/usb_host_printer_postscript.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/usb/src" 
	@${RM} ${OBJECTDIR}/usb/src/usb_host_printer_postscript.p1.d 
	@${RM} ${OBJECTDIR}/usb/src/usb_host_printer_postscript.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 -I"usb/inc" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --codeoffset=0x2000 --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/usb/src/usb_host_printer_postscript.p1  usb/src/usb_host_printer_postscript.c 
	@-${MV} ${OBJECTDIR}/usb/src/usb_host_printer_postscript.d ${OBJECTDIR}/usb/src/usb_host_printer_postscript.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/usb/src/usb_host_printer_postscript.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/usb/src/usb_host_printer_primitives.p1: usb/src/usb_host_printer_primitives.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/usb/src" 
	@${RM} ${OBJECTDIR}/usb/src/usb_host_printer_primitives.p1.d 
	@${RM} ${OBJECTDIR}/usb/src/usb_host_printer_primitives.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 -I"usb/inc" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --codeoffset=0x2000 --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/usb/src/usb_host_printer_primitives.p1  usb/src/usb_host_printer_primitives.c 
	@-${MV} ${OBJECTDIR}/usb/src/usb_host_printer_primitives.d ${OBJECTDIR}/usb/src/usb_host_printer_primitives.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/usb/src/usb_host_printer_primitives.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/usb-to-serial.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) --chip=$(MP_PROCESSOR_OPTION) -G -mdist/${CND_CONF}/${IMAGE_TYPE}/usb-to-serial.X.${IMAGE_TYPE}.map  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 -I"usb/inc" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --codeoffset=0x2000 --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"        $(COMPARISON_BUILD) --memorysummary dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -odist/${CND_CONF}/${IMAGE_TYPE}/usb-to-serial.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	@${RM} dist/${CND_CONF}/${IMAGE_TYPE}/usb-to-serial.X.${IMAGE_TYPE}.hex 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/usb-to-serial.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) --chip=$(MP_PROCESSOR_OPTION) -G -mdist/${CND_CONF}/${IMAGE_TYPE}/usb-to-serial.X.${IMAGE_TYPE}.map  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 -I"usb/inc" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --codeoffset=0x2000 --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"     $(COMPARISON_BUILD) --memorysummary dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -odist/${CND_CONF}/${IMAGE_TYPE}/usb-to-serial.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
