TARGETNAME=ndasinfo
TARGETTYPE=PROGRAM
TARGETPATH=obj

!IF $(USE_NDASCOMM_DLL)
!ELSE
C_DEFINES=$(C_DEFINES) /DNDASCOMM_SLIB
!ENDIF

INCLUDES=$(PSDK_INC_PATH);$(NDAS_PUBLIC_INC_PATH)

MSC_WARNING_LEVEL=-W3 -WX -Wp64
UMTYPE=console

#USE_UNICODE=1
!IFDEF USE_UNICODE
C_DEFINES=$(C_DEFINES) /DUNICODE /D_UNICODE
UMENTRY=wmain
!ELSE
C_DEFINES=$(C_DEFINES)
UMENTRY=main
!ENDIF

RC_OPTIONS=/i $(NDAS_INC_PATH)

!IF $(FREEBUILD)
USE_MSVCRT=1
!ELSE
USE_LIBCMT=1
DEBUG_CRTS=1
!ENDIF

!IF $(USE_NDASCOMM_DLL)
TARGETLIBS= \
	$(SDK_LIB_PATH)\user32.lib \
	$(NDAS_PUBLIC_LIB_PATH)\ndascomm.lib
!ELSE

TARGETLIBS= \
	$(PSDK_LIB_PATH)\ws2_32.lib \
	$(PSDK_LIB_PATH)\ole32.lib \
	$(SDK_LIB_PATH)\ntdll.lib \
	$(NDAS_LIB_PATH)\libndascomm.lib \
	$(NDAS_LIB_PATH)\libndashixnotify.lib \
	$(NDAS_LIB_PATH)\liblpxtrans.lib \
	$(NDAS_LIB_PATH)\liblspx.lib \
	$(NDAS_LIB_PATH)\libdes.lib \
	$(NDAS_LIB_PATH)\libscrc32.lib \
	$(NDAS_LIB_PATH)\libndasid.lib \
	$(NDAS_LIB_PATH)\libndasidenc.lib
!ENDIF

SOURCES=..\ndasinfo.c \
	..\addrstr.c


