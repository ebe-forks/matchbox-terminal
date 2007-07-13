CFLAGS=-g -Wall `pkg-config --cflags gtk+-2.0 vte`
LDFLAGS=`pkg-config --libs gtk+-2.0 vte`

matchbox-terminal: main.c
	$(LINK.c) -o $@ $<

install:
	install -m 755 matchbox-terminal $(DESTDIR)/usr/bin/
clean:
	rm -f matchbox-terminal

.PHONY: install clean
