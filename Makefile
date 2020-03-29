CC=gcc
CFLAGS=-g -Wall -pedantic 
OBJS=sipher.o goldbug.o usage.o rot.o atbash.o
PREFIX=/usr/local

sipher: $(OBJS)
	$(CC) -o sipher $(OBJS)

sipher.o: goldbug.h usage.h rot.h atbash.h

clean:
	rm sipher $(OBJS)

install:
		cp sipher $(DESTDIR)$(PREFIX)/bin/sipher

uninstall:	
		rm sipher $(DESTDIR)$(PREFIX)/bin/sipher
