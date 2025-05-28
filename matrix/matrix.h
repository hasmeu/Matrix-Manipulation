#ifndef HEADER_FILE
#define HEADER_FILE

#include <stdio.h>
#include <stdbool.h>


typedef enum {
    SHORT_INT, UNSIGNED_SHORT_INT, UNSIGNED_INT, INT, LONG_INT, UNSIGNED_LONG_INT, LONG_LONG_INT, FLOAT, DOUBLE, LONG_DOUBLE, 
    UNSIGNED_LONG_LONG_INT, LONG
} DataType;

typedef union {
    short int short_int_val;
    unsigned short int unsigned_short_int_val;
    unsigned int unsigned_int_val;
    int int_val;
    long int long_int_val;
    unsigned long int unsigned_long_int_val;
    long long int long_long_int_val;
    float float_val;
    double double_val;
    long double long_double_val;
    unsigned long long int unsigned_long_long_int_val;
    long long_val;

} DataValue;

struct Matrix {
    unsigned long long int rows;
    unsigned long long int cols;
    DataType type; 
    DataValue** data;
};

//functions

struct Matrix initialize(FILE* fp, DataType type);

void printArray(struct Matrix matrix1);

void clean(struct Matrix matrix);

struct Matrix add(struct Matrix matrix1, struct Matrix matrix2);

struct Matrix subtract(struct Matrix matrix1, struct Matrix matrix2);

struct Matrix multiply(struct Matrix matrix1, struct Matrix matrix2);

struct Matrix resize(struct Matrix matrix, unsigned long long int rows, unsigned long long int cols);

int isEqual(struct Matrix matrix1, struct Matrix matrix2);

void rotate(struct Matrix matrix, int numberOfRotations);

bool rowStorage(const char* boolean);

void columnMajor();

void rowMajor();





//testing initialize
void initializePosInt();

void initializeNegInt();

void initializeNegRow_Col();

void initializePosDouble();

void initializeNegDouble();

void initializeInvalidType();

void initializeDecimalOnInt();

void initializePosIntColMajor();

void initializeNegIntColMajor();

void initializeNegRow_ColColMajor();

void initializePosDoubleColMajor();

void initializeNegDoubleColMajor();

void initializeInvalidTypeColMajor();

void initializeDecimalOnIntColMajor();


//add tests

void addDifferentTypes();

void addNegativeInts();

void addNegativeDouble();

//subtract tests

void subtractDifferentTypes();

void subtractNegativeInt();

void subtractNegativeDouble();

//multiply tests

void multiplyDifferentTypes();

void multiplyNegativeInt();

void multiplyNegativeDouble();

void multiplyNegatives();

void multiplyColEqualsRow();

//rotate tests

void rotate0();

void rotate1();

//isEqual tests

void isEqualNegative();

void isEqualSame();

void isEqualDouble();

void isEqualDoubleEQ();

//resize tests

void resizeTestInt();

void resizeTestFloat();

#endif
