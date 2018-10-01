# $FreeBSD$

PORTNAME=	prometheus-node-exporter
DISTVERSIONPREFIX=	v
DISTVERSION=	0.16.0
CATEGORIES=	www

MAINTAINER=	jonathan@FreeBSD.org
COMMENT=	Prometheus exporter for hardware and OS metrics exposed by *NIX kernels

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go
USE_GITHUB=	yes
GH_ACCOUNT=	prometheus
GH_PROJECT=	node_exporter
GO_PKGNAME=	github.com/prometheus/node_exporter

PLIST_FILES=	bin/node_exporter

.include <bsd.port.mk>
