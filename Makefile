CC=gcc
cflags=-Wall -pedantic 
OBJS=sipher.o sipherfuncs.o usage.o

sipher: $(OBJS)
	$(CC) -o sipher $(OBJS)

sipher.o: sipherfuncs.h usage.h

clean:
	rm sipher $(OBJS)
