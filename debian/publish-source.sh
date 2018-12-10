#!/bin/bash

set -ex

PKG="${PACKAGE_NAME:-${1}}"
VERSION="${PACKAGE_VERSION:-${2}}"
ORIG_TARBALL="../${PKG}_${VERSION}.orig.tar.gz"

[ -f "${ORIG_TARBALL}" ] || exit 1

rm -rf .pc bcb5 bcb10 config generator mockpp msvc8 msvc71 tool
rm -f *.m4 AUTHORS bug-report ChangeLog configure.in Makefile.am COPYING INSTALL mockpp.* README TODO
rm -f libtool  Makefile stamp-h1 CMakeLists.txt  config.h  config.log  config.status

tar --strip-components=1 -xzf "${ORIG_TARBALL}" "${PKG}-${VERSION}" || exit 1

