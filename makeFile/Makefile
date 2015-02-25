CFLAGS=-Wall -g 
CC=gcc
DEPS=*.h

%.o: %.c $(DEPS)
	$(CC) *.c -I. 

build:
	$(CC) *.c -I. 

clean:
	rm -f *.o a.out
