<div align="center">
  <h1>Freeradius-server</h1>
  <p>
    <strong>Modified for the <a href="https://www.42.fr/42-network/">42Network</a></strong>
  </p>
  <p>

[![GNU](https://img.shields.io/badge/license-GNU%202-blue.svg)](LICENSE)

  </p>
</div>

Speculare server is intended to recieve data from speculare-client childrens.

This project is meant to evolve in something more complete and more complexe in a somewhat near future.

Server setup / Dev setup
--------------------------

- Install all deps
```bash
$ apt install git libldap-dev libssl1.0-dev make gcc libsasl2-modules-gssapi-mit ldap-utils libtalloc-dev
# Your working env should looks like :
# - working dir
# |- krb5
# |- freeradius-server
# That's because freeradius will looks for ../../krb5.
```

Changes
--------------------------
As per GNUv2 we must specify which change we've made to the source code. 
This repo provide an additional modules, named rlm_mschapv2_kerberos which aims to provide compatibility between KRB5 and MSCHAPv2 protocole (based on [Ether42](https://github.com/ether42/freeradius-ldap-kerberos)).

### rlm_mschap_kerberos
Config sample:
```
mschapv2_kerberos {
	#
	# libkdb path for dynamic linking
	#
	libkdb_path = /usr/local/lib/libkdb5.so

	#
	# libkdb_ldap path for dynamic linking
	#
	libkdb_ldap_path = /usr/local/lib/libkdb_ldap.so
   [...]
}
```