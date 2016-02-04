TOP=../..

include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE
#=============================

#=============================
# Build the IOC application

PROD_IOC = stepmotor
# stepmotor.dbd will be created and installed
DBD += stepmotor.dbd

# stepmotor.dbd will be made up from these files:
stepmotor_DBD += base.dbd
stepmotor_DBD += support.dbd
  
# Include dbd files from all support applications:
#stepmotor_DBD += xxx.dbd
#stepmotor_DBD += ds.dbd
stepmotor_SRCS += main.c
# Add all the support libraries needed by this IOC
#stepmotor_LIBS += xxx
stepmotor_LIBS += stream
stepmotor_LIBS += asyn

# stepmotor_registerRecordDeviceDriver.cpp derives from stepmotor.dbd
stepmotor_SRCS += stepmotor_registerRecordDeviceDriver.cpp

# Build the main IOC entry point on workstation OSs.
stepmotor_SRCS_DEFAULT += stepmotorMain.cpp
stepmotor_SRCS_vxWorks += -nil-

# Add support from base/src/vxWorks if needed
#stepmotor_OBJS_vxWorks += $(EPICS_BASE_BIN)/vxComLibrary

# Finally link to the EPICS Base libraries
stepmotor_LIBS += $(EPICS_BASE_IOC_LIBS)

#===========================

include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE

