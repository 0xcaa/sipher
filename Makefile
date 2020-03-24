CC=gcc
CFLAGS=-g -Wall -pedantic 
OBJS=sipher.o sipherfuncs.o usage.o list.o
PREFIX=/usr/local

sipher: $(OBJS)
	$(CC) -o sipher $(OBJS)

sipher.o: sipherfuncs.h usage.h list.h

clean:
	rm sipher $(OBJS)

install:
		cp sipher $(DESTDIR)$(PREFIX)/bin/sipher

uninstall:	
		rm sipher $(DESTDIR)$(PREFIX)/bin/sipher
