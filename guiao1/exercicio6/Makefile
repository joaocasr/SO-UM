CC = gcc
CFLAGS = -O2 -Wall
INCLUDE = pessoas.h
DEPS = pessoas.o

.PHONY: all clean
all: pessoas

ex6: $(DEPS)
	$(CC) -o $@ $^ $(CFLAGS)

%.o: %.c $(INCLUDE)
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -f pessoas *.o
