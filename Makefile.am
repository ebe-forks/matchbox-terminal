AM_CPPFLAGS = $(MBTERM_CFLAGS)
AM_CFLAGS = -Wall
LDADD = $(MBTERM_LIBS)

bin_PROGRAMS = matchbox-terminal
matchbox_terminal_SOURCES = main.c

desktopdir = $(datadir)/applications
dist_desktop_DATA = matchbox-terminal.desktop

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
