# $FreeBSD$

# Vendor sources and generated files
LDNSDIR= ${.CURDIR}/../../../contrib/ldns
UNBOUNDDIR= ${.CURDIR}/../../../contrib/unbound

.PATH: ${UNBOUNDDIR} ${UNBOUNDDIR}/smallapp ${UNBOUNDDIR}/doc

PROG=	unbound-checkconf
SRCS=	unbound-checkconf.c worker_cb.c
CFLAGS=	-I${UNBOUNDDIR} -I${LDNSDIR}
CFLAGS+= -I${.CURDIR}/../../../crypto/openssl/include
LIBADD=	unbound pthread
MAN=	unbound-checkconf.8

.include <bsd.prog.mk>
