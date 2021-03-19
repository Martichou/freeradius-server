TARGETNAME	:= rlm_mschapv2_kerberos

ifneq "$(TARGETNAME)" ""
TARGET		:= $(TARGETNAME).a
endif

SOURCES		:= $(TARGETNAME).c smbdes.c mschap.c 

SRC_CFLAGS	:=  -I ../krb5/src/plugins/kdb/ldap/libkdb_ldap/ -I ../krb5/src/include/ -I ../krb5/src/lib/kdb/ -DHAVE_LDAP_INITIALIZE -std=gnu99
TGT_LDLIBS	:=   -ldl -lkrb5
