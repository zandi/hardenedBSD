# $FreeBSD$

LIB=		ssl
SHLIB_MAJOR=	7

NO_LINT=

.if exists(Makefile.man)
.include "Makefile.man"
.endif
.include "../libcrypto/Makefile.inc"

SRCS=\
	s3_meth.c s3_srvr.c s3_clnt.c s3_lib.c s3_enc.c s3_pkt.c s3_both.c \
	s23_meth.c s23_srvr.c s23_clnt.c s23_lib.c s23_pkt.c \
	t1_meth.c t1_srvr.c t1_clnt.c t1_lib.c t1_enc.c \
	d1_meth.c d1_srvr.c d1_clnt.c d1_lib.c d1_pkt.c \
	d1_both.c d1_enc.c d1_srtp.c \
	ssl_lib.c ssl_err2.c ssl_cert.c ssl_sess.c \
	ssl_ciph.c ssl_stat.c ssl_rsa.c \
	ssl_asn1.c ssl_txt.c ssl_algs.c \
	bio_ssl.c ssl_err.c t1_reneg.c \
	pqueue.c
SRCS+=	s3_cbc.c

HDRS=	srtp.h ssl.h ssl2.h ssl3.h ssl23.h tls1.h dtls1.h 
INCSDIR=${INCLUDEDIR}/openssl/include

CFLAGS+=	-DOPENSSL_NO_RC5
LIBADD=	crypto

.include <bsd.lib.mk>

.PATH:	${LCRYPTO_SRC}/ssl \
	${LCRYPTO_SRC}/include/openssl \
	${.CURDIR}/man
