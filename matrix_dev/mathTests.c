#include <stdio.h>
#include "matrix.h"
#include <stdlib.h>

//add tests

//adding different types is not allowed. A conversion function could be made to avoid this issue.
void addDifferentTypes() {
    FILE* fptr;
    fptr = fopen("posInt.txt", "r");
    if (fptr == NULL) {
        printf("Could not open file");
        exit(EXIT_FAILURE);
    }
    
    struct Matrix m1;
    m1 = initialize(fptr, INT);
    
    fptr = fopen("posDouble.txt", "r");
    if (fptr == NULL) {
        printf("Could not open file");
        exit(EXIT_FAILURE);
    }
    struct Matrix m2;
    m2 = initialize(fptr, DOUBLE);
    
    struct Matrix m3;
    
    m3 = add(m1, m2);
    printArray(m3);
    
    clean(m1);
    clean(m2);
    clean(m3);
    fclose(fptr);
}


void addNegativeInt() {
    FILE* fptr;
    fptr = fopen("posInt.txt", "r");
    if (fptr == NULL) {
        printf("Could not open file");
        exit(EXIT_FAILURE);
    }
    
    struct Matrix m1;
    m1 = initialize(fptr, INT);
    
    fptr = fopen("negInt.txt", "r");
    if (fptr == NULL) {
        printf("Could not open file");
        exit(EXIT_FAILURE);
    }
    struct Matrix m2;
    m2 = initialize(fptr, INT);
    
    //cannot set m1 = add(m1,m2);  This would make the user lose access to the data of the original m1.
    struct Matrix m3;
    
    m3 = add(m1, m2);
    printArray(m3);
    
    clean(m1);
    clean(m2);
    clean(m3);
    fclose(fptr);
}

void addNegativeDouble() {
    FILE* fptr;
    fptr = fopen("posDouble.txt", "r");
    if (fptr == NULL) {
        printf("Could not open file");
        exit(EXIT_FAILURE);
    }
    
    struct Matrix m1;
    m1 = initialize(fptr, DOUBLE);
    
    fptr = fopen("negDouble.txt", "r");
    if (fptr == NULL) {
        printf("Could not open file");
        exit(EXIT_FAILURE);
    }
    struct Matrix m2;
    m2 = initialize(fptr, DOUBLE);
    
    //cannot set m1 = add(m1,m2);  This would make the user lose access to the data of the original m1.
    struct Matrix m3;
    
    m3 = add(m1, m2);
    printArray(m3);
    
    clean(m1);
    clean(m2);
    clean(m3);
    fclose(fptr);
}


//subtract tests

void subtractDifferentTypes() {
    FILE* fptr;
    fptr = fopen("posInt.txt", "r");
    if (fptr == NULL) {
        printf("Could not open file");
        exit(EXIT_FAILURE);
    }
    
    struct Matrix m1;
    m1 = initialize(fptr, INT);
    
    fptr = fopen("posDouble.txt", "r");
    if (fptr == NULL) {
        printf("Could not open file");
        exit(EXIT_FAILURE);
    }
    struct Matrix m2;
    m2 = initialize(fptr, DOUBLE);
    
    struct Matrix m3;
    
    m3 = subtract(m1, m2);
    printArray(m3);
    
    clean(m1);
    clean(m2);
    clean(m3);
    fclose(fptr);
}

void subtractNegativeInt() {
    FILE* fptr;
    fptr = fopen("posInt.txt", "r");
    if (fptr == NULL) {
        printf("Could not open file");
        exit(EXIT_FAILURE);
    }
    
    struct Matrix m1;
    m1 = initialize(fptr, INT);
    
    fptr = fopen("negInt.txt", "r");
    if (fptr == NULL) {
        printf("Could not open file");
        exit(EXIT_FAILURE);
    }
    struct Matrix m2;
    m2 = initialize(fptr, INT);
    
    //cannot set m1 = add(m1,m2);  This would make the user lose access to the data of the original m1.
    struct Matrix m3;
    
    m3 = subtract(m1, m2);
    printArray(m3);
    
    clean(m1);
    clean(m2);
    clean(m3);
    fclose(fptr);
}

void subtractNegativeDouble() {
    FILE* fptr;
    fptr = fopen("posDouble.txt", "r");
    if (fptr == NULL) {
        printf("Could not open file");
        exit(EXIT_FAILURE);
    }
    
    struct Matrix m1;
    m1 = initialize(fptr, DOUBLE);
    
    fptr = fopen("negDouble.txt", "r");
    if (fptr == NULL) {
        printf("Could not open file");
        exit(EXIT_FAILURE);
    }
    struct Matrix m2;
    m2 = initialize(fptr, DOUBLE);
    
    //cannot set m1 = add(m1,m2);  This would make the user lose access to the data of the original m1.
    struct Matrix m3;
    
    m3 = subtract(m1, m2);
    printArray(m3);
    
    clean(m1);
    clean(m2);
    clean(m3);
    fclose(fptr);
}


//multiply tests

void multiplyDifferentTypes() {
    FILE* fptr;
    fptr = fopen("posInt.txt", "r");
    if (fptr == NULL) {
        printf("Could not open file");
        exit(EXIT_FAILURE);
    }
    
    struct Matrix m1;
    m1 = initialize(fptr, INT);
    
    fptr = fopen("posDouble.txt", "r");
    if (fptr == NULL) {
        printf("Could not open file");
        exit(EXIT_FAILURE);
    }
    struct Matrix m2;
    m2 = initialize(fptr, DOUBLE);
    
    struct Matrix m3;
    
    m3 = multiply(m1, m2);
    printArray(m3);
    
    clean(m1);
    clean(m2);
    clean(m3);
    fclose(fptr);
}

void multiplyNegativeInt() {
    FILE* fptr;
    fptr = fopen("posInt.txt", "r");
    if (fptr == NULL) {
        printf("Could not open file");
        exit(EXIT_FAILURE);
    }
    
    struct Matrix m1;
    m1 = initialize(fptr, INT);
    
    fptr = fopen("negInt.txt", "r");
    if (fptr == NULL) {
        printf("Could not open file");
        exit(EXIT_FAILURE);
    }
    struct Matrix m2;
    m2 = initialize(fptr, INT);
    
    //cannot set m1 = add(m1,m2);  This would make the user lose access to the data of the original m1.
    struct Matrix m3;
    
    m3 = multiply(m1, m2);
    printArray(m3);
    
    clean(m1);
    clean(m2);
    clean(m3);
    fclose(fptr);
}

void multiplyNegativeDouble() {
    FILE* fptr;
    fptr = fopen("posDouble.txt", "r");
    if (fptr == NULL) {
        printf("Could not open file");
        exit(EXIT_FAILURE);
    }
    
    struct Matrix m1;
    m1 = initialize(fptr, DOUBLE);
    
    fptr = fopen("negDouble.txt", "r");
    if (fptr == NULL) {
        printf("Could not open file");
        exit(EXIT_FAILURE);
    }
    struct Matrix m2;
    m2 = initialize(fptr, DOUBLE);
    
    //cannot set m1 = add(m1,m2);  This would make the user lose access to the data of the original m1.
    struct Matrix m3;
    
    m3 = multiply(m1, m2);
    printArray(m3);
    
    clean(m1);
    clean(m2);
    clean(m3);
    fclose(fptr);
}

void multiplyNegatives() {
    FILE* fptr;
    fptr = fopen("negInt.txt", "r");
    if (fptr == NULL) {
        printf("Could not open file");
        exit(EXIT_FAILURE);
    }
    
    struct Matrix m1;
    m1 = initialize(fptr, INT);
    
    fptr = fopen("negInt.txt", "r");
    if (fptr == NULL) {
        printf("Could not open file");
        exit(EXIT_FAILURE);
    }
    struct Matrix m2;
    m2 = initialize(fptr, INT);
    
    //cannot set m1 = add(m1,m2);  This would make the user lose access to the data of the original m1.
    struct Matrix m3;
    
    m3 = multiply(m1, m2);
    printArray(m3);
    
    clean(m1);
    clean(m2);
    clean(m3);
    fclose(fptr);
}

void multiplyColEqualsRow() {
    FILE* fptr;
    fptr = fopen("multiplyTest1.txt", "r");
    if (fptr == NULL) {
        printf("Could not open file");
        exit(EXIT_FAILURE);
    }
    
    struct Matrix m1;
    m1 = initialize(fptr, INT);
    
    fptr = fopen("multiplyTest2.txt", "r");
    if (fptr == NULL) {
        printf("Could not open file");
        exit(EXIT_FAILURE);
    }
    struct Matrix m2;
    m2 = initialize(fptr, INT);
    
    //cannot set m1 = add(m1,m2);  This would make the user lose access to the data of the original m1.
    struct Matrix m3;
    
    m3 = multiply(m1, m2);
    printArray(m3);
    
    clean(m1);
    clean(m2);
    clean(m3);
    fclose(fptr);
}






