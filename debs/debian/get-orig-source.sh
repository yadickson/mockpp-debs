#!/bin/sh

set -ex

PKG="${1}"
VERSION="${2}"
ZIPFILE="mockpp-${VERSION}-src.zip"
ORIG_TARBALL="../${PKG}_${VERSION}.orig.tar.xz"

[ ! -f ${ORIG_TARBALL} ] || exit 0

rm -rf "${PKG}-${VERSION}"
rm -f "${ZIPFILE}"
rm -rf tmp

wget -c -t 1 -T 5 "http://downloads.sourceforge.net/project/mockpp/mockpp/${VERSION}/${ZIPFILE}"

unzip "${ZIPFILE}" -d tmp || exit 1

mv tmp/"${PKG}-${VERSION}" "${PKG}-${VERSION}"
rm -rf tmp

find "${PKG}-${VERSION}" -type f -name '*.cvs' -exec rm -f '{}' \;
find "${PKG}-${VERSION}" -type f -name '*.sh' -exec rm -f '{}' \;
find "${PKG}-${VERSION}" -type f -name '*.kdevelop' -exec rm -f '{}' \;
find "${PKG}-${VERSION}" -type f -name '*.lsm' -exec rm -f '{}' \;
find "${PKG}-${VERSION}" -type f -name 'Makefile.in' -exec rm -f '{}' \;

rm -rf "${PKG}-${VERSION}"/3party
rm -f "${PKG}-${VERSION}"/configure
rm -f "${PKG}-${VERSION}"/config.h.in

tar -cJf "${ORIG_TARBALL}" --exclude-vcs "${PKG}-${VERSION}" || exit 1

rm -rf "${PKG}-${VERSION}"
rm -f "${ZIPFILE}"

