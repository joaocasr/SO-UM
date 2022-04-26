CFLAGS=-Wall -Wextra -Wdouble-promotion -Wconversion -Wsign-conversion

all: createfifo read write

$createfifo : createfifo.c
	gcc $(CFLAGS) -o $@ $^

$read : read.c
	gcc $(CFLAGS) -o $@ $^

$write: write.c
	gcc $(CFLAGS) -o $@ $^
