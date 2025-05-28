#include <stdio.h>
#include "matrix.h"
#include <stdlib.h>

void initializePosInt() {
    FILE* fptr;
    fptr = fopen("posInt.txt", "r");
    if (fptr == NULL) {
        printf("Could not open file");
        exit(EXIT_FAILURE);
    }
    
    struct Matrix m1;
    m1 = initialize(fptr, INT);
    printArray(m1);
    clean(m1);
    fclose(fptr);
}

void initializeNegInt() {
    FILE* fptr;
    fptr = fopen("negInt.txt", "r");
    if (fptr == NULL) {
        printf("Could not open file");
        exit(EXIT_FAILURE);
    }
    
    struct Matrix m1;
    m1 = initialize(fptr, INT);
    printArray(m1);
    clean(m1);
    fclose(fptr);
}

void initializeNegRow_Col() {
    FILE* fptr;
    fptr = fopen("negRow_Col.txt", "r");
    if (fptr == NULL) {
        printf("Could not open file");
        exit(EXIT_FAILURE);
    }
    
    struct Matrix m1;
    m1 = initialize(fptr, INT);
    printArray(m1);
    clean(m1);
    fclose(fptr);
}

void initializePosDouble() {
    FILE* fptr;
    fptr = fopen("posDouble.txt", "r");
    if (fptr == NULL) {
        printf("Could not open file");
        exit(EXIT_FAILURE);
    }
    
    struct Matrix m1;
    m1 = initialize(fptr, DOUBLE);
    printArray(m1);
    clean(m1);
    fclose(fptr);
}

void initializeNegDouble() {
    FILE* fptr;
    fptr = fopen("negDouble.txt", "r");
    if (fptr == NULL) {
        printf("Could not open file");
        exit(EXIT_FAILURE);
    }
    
    struct Matrix m1;
    m1 = initialize(fptr, DOUBLE);
    printArray(m1);
    clean(m1);
    fclose(fptr);
}

void initializeInvalidType() {
    FILE* fptr;
    fptr = fopen("posDouble.txt", "r");
    if (fptr == NULL) {
        printf("Could not open file");
        exit(EXIT_FAILURE);
    }
    
    struct Matrix m1;
    m1 = initialize(fptr, INT);
    printArray(m1);
    clean(m1);
    fclose(fptr);
}

void initializeDecimalOnInt() {
    FILE* fptr;
    fptr = fopen("posInt.txt", "r");
    if (fptr == NULL) {
        printf("Could not open file");
        exit(EXIT_FAILURE);
    }
    
    struct Matrix m1;
    m1 = initialize(fptr, DOUBLE);
    printArray(m1);
    clean(m1);
    fclose(fptr);
}

void initializePosIntColMajor() {
    FILE* fptr;
    fptr = fopen("posInt.txt", "r");
    if (fptr == NULL) {
        printf("Could not open file");
        exit(EXIT_FAILURE);
    }
    
    struct Matrix m1;
    m1 = initialize(fptr, INT);
    printArray(m1);
    clean(m1);
    fclose(fptr);
}

void initializeNegIntColMajor() {
    FILE* fptr;
    fptr = fopen("negInt.txt", "r");
    if (fptr == NULL) {
        printf("Could not open file");
        exit(EXIT_FAILURE);
    }
    
    struct Matrix m1;
    m1 = initialize(fptr, INT);
    printArray(m1);
    clean(m1);
    fclose(fptr);
}

void initializeNegRow_ColColMajor() {
    FILE* fptr;
    fptr = fopen("negRow_Col.txt", "r");
    if (fptr == NULL) {
        printf("Could not open file");
        exit(EXIT_FAILURE);
    }
    
    struct Matrix m1;
    m1 = initialize(fptr, INT);
    printArray(m1);
    clean(m1);
    fclose(fptr);
}

void initializePosDoubleColMajor() {
    FILE* fptr;
    fptr = fopen("posDouble.txt", "r");
    if (fptr == NULL) {
        printf("Could not open file");
        exit(EXIT_FAILURE);
    }
    
    struct Matrix m1;
    m1 = initialize(fptr, DOUBLE);
    printArray(m1);
    clean(m1);
    fclose(fptr);
}

void initializeNegDoubleColMajor() {
    FILE* fptr;
    fptr = fopen("negDouble.txt", "r");
    if (fptr == NULL) {
        printf("Could not open file");
        exit(EXIT_FAILURE);
    }
    
    struct Matrix m1;
    m1 = initialize(fptr, DOUBLE);
    printArray(m1);
    clean(m1);
    fclose(fptr);
}

void initializeInvalidTypeColMajor() {
    FILE* fptr;
    fptr = fopen("posDouble.txt", "r");
    if (fptr == NULL) {
        printf("Could not open file");
        exit(EXIT_FAILURE);
    }
    
    struct Matrix m1;
    m1 = initialize(fptr, INT);
    printArray(m1);
    clean(m1);
    fclose(fptr);
}

void initializeDecimalOnIntColMajor() {
    FILE* fptr;
    fptr = fopen("posInt.txt", "r");
    if (fptr == NULL) {
        printf("Could not open file");
        exit(EXIT_FAILURE);
    }
    
    struct Matrix m1;
    m1 = initialize(fptr, DOUBLE);
    printArray(m1);
    clean(m1);
    fclose(fptr);
}  




//rotate tests


void rotate0() {
    FILE* fptr;
    fptr = fopen("posInt.txt", "r");
    if (fptr == NULL) {
        printf("Could not open file");
        exit(EXIT_FAILURE);
    }
    
    struct Matrix m1;
    m1 = initialize(fptr, INT);
    printArray(m1);
    rotate(m1, 0);
    printArray(m1);
    clean(m1);
    fclose(fptr);
}

void rotate1() {
    FILE* fptr;
    fptr = fopen("posInt.txt", "r");
    if (fptr == NULL) {
        printf("Could not open file");
        exit(EXIT_FAILURE);
    }
    
    struct Matrix m1;
    m1 = initialize(fptr, INT);
    printArray(m1);
    rotate(m1, 1);
    printArray(m1);
    clean(m1);
    fclose(fptr);
}




//isEqual tests

void isEqualNegative() {
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
    
    
    isEqual(m1, m2);
    
    
    clean(m1);
    clean(m2);
    fclose(fptr);
}

void isEqualSame() {
    FILE* fptr;
    fptr = fopen("posInt.txt", "r");
    if (fptr == NULL) {
        printf("Could not open file");
        exit(EXIT_FAILURE);
    }
    
    struct Matrix m1;
    m1 = initialize(fptr, INT);
    
    isEqual(m1, m1);
    
    clean(m1);
    
    fclose(fptr);
}

void isEqualDouble() {
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
    
    
    isEqual(m1, m2);
    
    
    clean(m1);
    clean(m2);
    fclose(fptr);
}

void isEqualDoubleEQ() {
    FILE* fptr;
    fptr = fopen("posDouble.txt", "r");
    if (fptr == NULL) {
        printf("Could not open file");
        exit(EXIT_FAILURE);
    }
    
    struct Matrix m1;
    m1 = initialize(fptr, DOUBLE);
    
    fptr = fopen("posDouble.txt", "r");
    if (fptr == NULL) {
        printf("Could not open file");
        exit(EXIT_FAILURE);
    }
    struct Matrix m2;
    m2 = initialize(fptr, DOUBLE);
    
    
    isEqual(m1, m2);
    
    
    clean(m1);
    clean(m2);
    fclose(fptr);
}


//resize tests

void resizeTestInt() {
    FILE* fptr;
    fptr = fopen("posInt.txt", "r");
    if (fptr == NULL) {
        printf("Could not open file");
        exit(EXIT_FAILURE);
    }
    
    struct Matrix m1;
    m1 = initialize(fptr, INT);
    printArray(m1);
    
    struct Matrix m2;
    m2 = resize(m1, 1, 2);
    printArray(m2);
    
    clean(m1);
    clean(m2);
    fclose(fptr);
}

void resizeTestFloat() {
    FILE* fptr;
    fptr = fopen("posInt.txt", "r");
    if (fptr == NULL) {
        printf("Could not open file");
        exit(EXIT_FAILURE);
    }
    
    struct Matrix m1;
    m1 = initialize(fptr, FLOAT);
    printArray(m1);
    
    struct Matrix m2;
    m2 = resize(m1, 1, 2);
    printArray(m2);
    
    clean(m1);
    clean(m2);
    fclose(fptr);
}





