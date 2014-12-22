# $FreeBSD$

# Vendor sources and generated files
LDNSDIR= ${.CURDIR}/../../contrib/ldns

.PATH: ${LDNSDIR}/drill

PROG=	drill
SRCS=	drill.c drill_util.c error.c root.c work.c \
	chasetrace.c dnssec.c securetrace.c
CFLAGS+= -I${LDNSDIR}
CFLAGS+= -I${.CURDIR}/../../crypto/openssl/include
NO_WERROR= true
MAN=	drill.1

LIBADD=	ldns crypto

.include <bsd.prog.mk>
