CFLAGS=-g -Wall `pkg-config --cflags gtk+-2.0 vte`
LDFLAGS=`pkg-config --libs gtk+-2.0 vte`

matchbox-terminal: main.c
	$(LINK.c) -o $@ $<

clean:
	rm -f matchbox-terminal
