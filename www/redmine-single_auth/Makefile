# Created by: Mark Felder <feld@FreeBSD.org>
# $FreeBSD$

PORTNAME=	single_auth
PORTVERSION=	2.0.1
PORTREVISION=	0
CATEGORIES=	www
MASTER_SITES=	http://bitbucket.org/dkuk/${PORTNAME}/get/
PKGNAMEPREFIX=	redmine-
DISTNAME=	${BB_COMMIT}
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SSO authentication method for Redmine

RUN_DEPENDS=	redmine-a_common_libs>0:www/redmine-a_common_libs

NO_ARCH=	yes

BB_COMMIT=	7cf9e17fae44

REDMINE_PLUGIN_NAME=	${PORTNAME}

WRKSRC=	${WRKDIR}/dkuk-${PORTNAME}-${BB_COMMIT}

.include "${.CURDIR}/../../www/redmine/bsd.redmine.mk"
