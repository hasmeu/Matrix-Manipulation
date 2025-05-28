output: main.o matrix.o matrix_math.o resize.o rotate.o isEqual.o mathTests.o tests.o
	gcc main.o matrix.o matrix_math.o resize.o rotate.o isEqual.o mathTests.o tests.o -g -o output 


main.o: main.c 
	gcc -c main.c 

matrix.o: matrix.c matrix.h 
	gcc -c matrix.c 

matrix_math.o: matrix_math.c matrix.h 
	gcc -c matrix_math.c

resize.o: resize.c matrix.h 
	gcc -c resize.c

rotate.o: rotate.c matrix.h 
	gcc -c rotate.c

isEqual.o: isEqual.c matrix.h 
	gcc -c isEqual.c

mathTests.o: mathTests.c matrix.h
	gcc -c mathTests.c 

tests.o: tests.c matrix.h
	gcc -c tests.c

clean:
	rm *.o output

