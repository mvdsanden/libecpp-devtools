#!/bin/sh

if [ "x$1" = "xclean" ]; then
	echo Cleaning
	echo TODO
	exit 1
	make distclean
  rm -f confi
  rm -rf autom4te.cache config.aux m4
	exit
fi

## Generate Makefile.am from MD5SUMS
LSOURCE=libecpp-devtools.cc
LNAME=`basename "${LSOURCE}" .cc`
echo "Generating src/${LSOURCE}"
echo "//THIS IS AUTOMATICALLY OVERWRITTEN BY ../bootstrap.sh DO NOT EDIT" > src/${LSOURCE}
( cd src; find . -name '*.hh' | perl -ne 'chomp; print "#include \""; print; print "\"\n";' >> ${LSOURCE} )

echo "Generating Makefile.am from MD5SUMS"
#Update MD5SUMS
which ccbuild && (ccbuild -C src md5 "${LSOURCE}" > MD5SUMS)
which ccbuild && (ccbuild makefile --nodefargs "src/${LSOURCE}" > Makefile.ccbuild)

SOURCES=`sed  -r 's/^[a-z0-9]+  //; s/ /\\ /' < MD5SUMS | tr '\n' ' '`
HEADERS=`ccbuild -C src deps ${LSOURCE} | head -n 1`
USLNAME=`echo -n "${LNAME}"|tr '.-' '__'`

#Main Makefile.am
cat > Makefile.am <<EOF
#THIS FILE IS AUTOMATICALLY GENERATED BY bootstrap.sh
# DO NOT EDIT THIS, BUT EDIT THAT
PACKAGE = @PACKAGE@
VERSION = @VERSION@

ACLOCAL_AMFLAGS = -I m4

EXTRA_DIST = AUTHORS COPYING INSTALL README

SUBDIRS = src

EOF

# src Makefile.am
cat > src/Makefile.am <<EOF
#THIS FILE IS AUTOMATICALLY GENERATED BY ../bootstrap.sh
# DO NOT EDIT THIS, BUT EDIT THAT
PACKAGE = @PACKAGE@
VERSION = @VERSION@

bin_PROGRAMS = ecpp-project
ecpp_project_SOURCES = ecpp-project.cc
ecpp_project_LDFLAGS = -lecpp-devtools -lecpp-common -lecpp-filesystem

AUTOMAKE_OPTIONS = subdir-objects

lib_LTLIBRARIES = ${LNAME}.la

#nobase_pkginclude_HEADERS = ${HEADERS}
pkgincludedir = \$(prefix)/include/ecpp
nobase_pkginclude_HEADERS = ${HEADERS}

#List of source files needed to build the library:
${USLNAME}_la_SOURCES = ${SOURCES}

AM_CPPFLAGS = -Wall -O2 \$(DEPS_CFLAGS)
AM_LDFLAGS = \$(DEPS_LIBS)
EOF

rm -f config.cache acconfig.h

echo "- libtoolize."    && \
libtoolize --copy && \
echo "- aclocal."		&& \
aclocal	&& \
echo "- autoconf."		&& \
autoconf			&& \
echo "- automake."		&& \
automake --add-missing --copy

