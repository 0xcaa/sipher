CC=gcc
CFLAGS=-g -Wall -pedantic 
OBJS=sipher.o sipherfuncs.o usage.o list.o

sipher: $(OBJS)
	$(CC) -o sipher $(OBJS)

sipher.o: sipherfuncs.h usage.h list.h

clean:
	rm sipher $(OBJS)
