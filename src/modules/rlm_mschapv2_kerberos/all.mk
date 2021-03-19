SUBMAKEFILES := rlm_mschapv2_kerberos.mk smbencrypt.mk

src/modules/rlm_mschapv2_kerberos/rlm_mschapv2_kerberos.mk: src/modules/rlm_mschapv2_kerberos/rlm_mschapv2_kerberos.mk.in src/modules/rlm_mschapv2_kerberos/configure
	@echo CONFIGURE $(dir $<)
	@cd $(dir $<) && ./configure $(CONFIGURE_ARGS)
