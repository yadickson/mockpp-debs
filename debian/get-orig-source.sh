#!/bin/sh

set -ex

PKG="${PACKAGE_NAME:-${1}}"
VERSION="${PACKAGE_VERSION:-${2}}"
ADD_PATCH="${3:-false}"
ZIPFILE="mockpp-${VERSION}-src.zip"
ORIG_TARBALL="../${PKG}_${VERSION}.orig.tar.gz"

[ ! -f ${ORIG_TARBALL} ] || exit 0

rm -rf "${PKG}-${VERSION}"
rm -f "${ZIPFILE}"
rm -rf tmp

wget -c "http://downloads.sourceforge.net/project/mockpp/mockpp/${VERSION}/${ZIPFILE}"

unzip "${ZIPFILE}" -d tmp || exit 1

mv tmp/"${PKG}-${VERSION}" "${PKG}-${VERSION}"
rm -rf tmp

find "${PKG}-${VERSION}" -type f -name '*.cvs' -exec rm -f '{}' \;
find "${PKG}-${VERSION}" -type f -name '*.kdevelop' -exec rm -f '{}' \;
find "${PKG}-${VERSION}" -type f -name '*.lsm' -exec rm -f '{}' \;
find "${PKG}-${VERSION}" -type f -name 'Makefile.in' -exec rm -f '{}' \;
find "${PKG}-${VERSION}" -type f -name 'Makefile' -exec rm -f '{}' \;
find "${PKG}-${VERSION}" -type f -name '*.bat' -exec rm -f '{}' \;
find "${PKG}-${VERSION}" -type f -name 'CMakeLists.txt' -exec rm -f '{}' \;

find "${PKG}-${VERSION}" -type f -name '*.sh' -exec rm -f '{}' \;
find "${PKG}-${VERSION}" -type f -name '*.pl' -exec rm -f '{}' \;

find "${PKG}-${VERSION}" -type f -name 'config.guess' -exec rm -f '{}' \;
find "${PKG}-${VERSION}" -type f -name 'config.sub' -exec rm -f '{}' \;
find "${PKG}-${VERSION}" -type f -name 'depcomp' -exec rm -f '{}' \;
find "${PKG}-${VERSION}" -type f -name 'install-sh' -exec rm -f '{}' \;
find "${PKG}-${VERSION}" -type f -name 'ltconfig' -exec rm -f '{}' \;
find "${PKG}-${VERSION}" -type f -name 'missing' -exec rm -f '{}' \;
find "${PKG}-${VERSION}" -type f -name 'mkinstalldirs' -exec rm -f '{}' \;

rm -rf "${PKG}-${VERSION}"/3party
rm -rf "${PKG}-${VERSION}"/bcb5
rm -rf "${PKG}-${VERSION}"/bcb10
rm -rf "${PKG}-${VERSION}"/generator
rm -rf "${PKG}-${VERSION}"/msvc8
rm -rf "${PKG}-${VERSION}"/msvc71
rm -rf "${PKG}-${VERSION}"/tool
rm -rf "${PKG}-${VERSION}"/mockpp/docs

rm -f "${PKG}-${VERSION}"/configure
rm -f "${PKG}-${VERSION}"/config.h.in
rm -f "${PKG}-${VERSION}"/stamp-h1
rm -f "${PKG}-${VERSION}"/mockpp.spec
rm -f "${PKG}-${VERSION}"/mockpp.pc
rm -f "${PKG}-${VERSION}"/mockpp.doxygen
rm -f "${PKG}-${VERSION}"/ChangeLog
rm -f "${PKG}-${VERSION}"/bug-report
rm -f "${PKG}-${VERSION}"/libtool
rm -f "${PKG}-${VERSION}"/COPYING
rm -f "${PKG}-${VERSION}"/INSTALL
rm -f "${PKG}-${VERSION}"/TODO
rm -f "${PKG}-${VERSION}"/aclocal.m4

if [ "${ADD_PATCH}" != "false" ]
then
   while read -r line
   do
      patch -d "${PKG}-${VERSION}" -p1 < "debian/patches/${line}"
   done < debian/patches/series
fi

tar -czf "${ORIG_TARBALL}" --exclude-vcs "${PKG}-${VERSION}" || exit 1

rm -rf "${PKG}-${VERSION}"
rm -f "${ZIPFILE}"

