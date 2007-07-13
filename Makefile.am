bin_PROGRAMS = matchbox-terminal

AM_CPPFLAGS = $(VTE_CFLAGS)
AM_CFLAGS = -Wall
LDADD = $(VTE_LIBS)

matchbox_terminal_SOURCES = main.c

# make maintainer-clean should remove *everything* 
MAINTAINERCLEANFILES = \
	aclocal.m4 \
	compile \
	config.guess \
	config.h.in \
	configure \
	depcomp \
	install-sh \
	Makefile.in \
	missing
