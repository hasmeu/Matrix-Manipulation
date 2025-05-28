#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

int isEqual(struct Matrix matrix1, struct Matrix matrix2) {
    //checks if the two matrix pointers are equal. If yes then they are memory equivalent.
    if (matrix1.data == matrix2.data) {
        printf("The arrays are memory equivalent.");
        return(1);
    }
    if (matrix1.type != matrix2.type) {
        printf("The arrays are of different types");
        return(1);
    }
    
     if (matrix1.rows != matrix2.rows || matrix1.cols != matrix2.cols) {
        printf("The dimensions of the matrices are not equal.");
        return(0);
        
    }
    
    for (unsigned long long int i = 0; i < matrix1.rows; i++) {
        for (unsigned long long int j = 0; j < matrix1.cols; j++) {
            switch (matrix1.type) {
                    case INT:
                        if (matrix1.data[i][j].int_val != matrix2.data[i][j].int_val) {
                            printf("At least one element of the arrays are not equal.");
                            return(0);
                        }
                        break;
                    case LONG:
                        if (matrix1.data[i][j].long_val != matrix2.data[i][j].long_val) {
                            printf("At least one element of the arrays are not equal.");
                            return(0);
                        }
                        break;
                    case FLOAT:
                        if (matrix1.data[i][j].float_val != matrix2.data[i][j].float_val) {
                            printf("At least one element of the arrays are not equal.");
                            return(0);
                        }
                        break;
                    case DOUBLE:
                        if (matrix1.data[i][j].double_val != matrix2.data[i][j].double_val) {
                            printf("At least one element of the arrays are not equal.");
                            return(0);
                        }
                        break;
                    case SHORT_INT:
                        if (matrix1.data[i][j].short_int_val != matrix2.data[i][j].short_int_val) {
                            printf("At least one element of the arrays are not equal.");
                            return(0);
                        }
                        break;
                    case UNSIGNED_SHORT_INT:
                        if (matrix1.data[i][j].unsigned_short_int_val != matrix2.data[i][j].unsigned_short_int_val) {
                            printf("At least one element of the arrays are not equal.");
                            return(0);
                        }
                        break;
                    case UNSIGNED_INT:
                        if (matrix1.data[i][j].unsigned_int_val != matrix2.data[i][j].unsigned_int_val) {
                            printf("At least one element of the arrays are not equal.");
                            return(0);
                        }
                        break;
                    case LONG_INT:
                        if (matrix1.data[i][j].long_int_val != matrix2.data[i][j].long_int_val) {
                            printf("At least one element of the arrays are not equal.");
                            return(0);
                        }
                        break;
                    case UNSIGNED_LONG_INT:
                        if (matrix1.data[i][j].unsigned_long_int_val != matrix2.data[i][j].unsigned_long_int_val) {
                            printf("At least one element of the arrays are not equal.");
                            return(0);
                        }
                        break;
                    case LONG_LONG_INT:
                        if (matrix1.data[i][j].long_long_int_val != matrix2.data[i][j].long_long_int_val) {
                            printf("At least one element of the arrays are not equal.");
                            return(0);
                        }
                        break;
                    case UNSIGNED_LONG_LONG_INT:
                        if (matrix1.data[i][j].unsigned_long_long_int_val != matrix2.data[i][j].unsigned_long_long_int_val) {
                            printf("At least one element of the arrays are not equal.");
                            return(0);
                        }
                        break;
                    case LONG_DOUBLE:
                        if (matrix1.data[i][j].long_double_val != matrix2.data[i][j].long_double_val) {
                            printf("At least one element of the arrays are not equal.");
                            return(0);
                        }
                        break;
                    default:
                        printf("Unsupported data type. Ended Program.");
                        exit(EXIT_FAILURE);
                }
        
        }
    }
    
    printf("\nThe arrays are element equivalent.");
    return(1);

}