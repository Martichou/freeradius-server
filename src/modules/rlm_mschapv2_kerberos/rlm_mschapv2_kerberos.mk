TARGETNAME	:= rlm_mschapv2_kerberos

ifneq "$(TARGETNAME)" ""
TARGET		:= $(TARGETNAME).a
endif

SOURCES		:= $(TARGETNAME).c smbdes.c mschap.c 

SRC_CFLAGS	:= 
TGT_LDLIBS	:=  
