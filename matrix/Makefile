CC = cc
CFLAGS = -Wall -g -std=c99

objects = main.c isEqual.c mathTests.c matrix_math.c matrix.c resize.c rotate.c tests.c

output : $(objects)
		$(CC) $(CFLAGS) -o output $(objects)

$(objects) : matrix.h

clean:
		rm -f output *.o
