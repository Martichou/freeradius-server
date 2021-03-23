/* Copyright 2006-2015 The FreeRADIUS server project */

#ifndef _RLM_MSCHAPV2_KERBEROS_H
#define _RLM_MSCHAPV2_KERBEROS_H

RCSIDH(rlm_mschapv2_kerberos_h, "$Id$")

#include "config.h"

#ifdef WITH_AUTH_WINBIND
#  include <wbclient.h>
#endif

#include <kdb_ldap.h>
#include <dlfcn.h>

/* Method of authentication we are going to use */
typedef enum {
	AUTH_INTERNAL		= 0,
	AUTH_NTLMAUTH_EXEC	= 1
#ifdef WITH_AUTH_WINBIND
	,AUTH_WBCLIENT       	= 2
#endif
} MSCHAP_AUTH_METHOD;

typedef struct rlm_mschapv2_kerberos_t {
	bool			use_mppe;
	bool			require_encryption;
	bool			require_strong;
	bool			with_ntdomain_hack;	/* this should be in another module */
	char const		*xlat_name;
	char const		*ntlm_auth;
	uint32_t		ntlm_auth_timeout;
	char const		*ntlm_cpw;
	char const		*ntlm_cpw_username;
	char const		*ntlm_cpw_domain;
	char const		*local_cpw;
	char const		*auth_type;
	bool			allow_retry;
	char const		*retry_msg;
	MSCHAP_AUTH_METHOD	method;
	vp_tmpl_t		*wb_username;
	vp_tmpl_t		*wb_domain;
	fr_connection_pool_t    *wb_pool;
	bool			wb_retry_with_normalised_username;
#ifdef __APPLE__
	bool			open_directory;
#endif
	char const*		libkdb_ldap_path;
	char const*		libkdb_path;
	void*			kdb_ldap;
	void*			kdb;
	krb5_context	krb_context;
	krb5_ldap_context*	krb_ldap_context;
	krb5_keyblock	master_keyblock;
	krb5_error_code	(*krb5_ldap_lib_init)(void);
	krb5_error_code	(*krb5_db_setup_lib_handle)(krb5_context);
	krb5_error_code	(*krb5_ldap_read_server_params)(krb5_context, char*, int);
	krb5_error_code	(*krb5_ldap_db_init)(krb5_context, krb5_ldap_context*);
	krb5_error_code	(*krb5_ldap_read_startup_information)(krb5_context);
	krb5_error_code	(*krb5_db_setup_mkey_name)(krb5_context, const char*, const char*, char**, krb5_principal*);
	krb5_error_code	(*krb5_db_fetch_mkey)(krb5_context, krb5_principal, krb5_enctype, krb5_boolean, krb5_boolean, char*, krb5_kvno*, krb5_data*, krb5_keyblock*);
	krb5_error_code	(*krb5_db_fetch_mkey_list)(krb5_context, krb5_principal, krb5_keyblock*);
	krb5_error_code	(*krb5_dbe_decrypt_key_data)(krb5_context, const krb5_keyblock*, const krb5_key_data*, krb5_keyblock*, krb5_keysalt*);
	krb5_error_code	(*krb5_ldap_get_principal)(krb5_context, krb5_const_principal, unsigned int, krb5_db_entry*, int*, krb5_boolean*);
	krb5_error_code	(*krb5_ldap_free_principal)(krb5_context, krb5_db_entry*, int);
	krb5_error_code	(*krb5_ldap_lib_cleanup)(void);
	krb5_error_code	(*krb5_ldap_close)(krb5_context);
} rlm_mschapv2_kerberos_t;

#endif

