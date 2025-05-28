#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
#include <string.h>

struct Matrix add(struct Matrix matrix1, struct Matrix matrix2) {
    //Check if the matrices can be added.
    if ((matrix1.rows + matrix1.cols) != (matrix2.rows + matrix2.cols) || (matrix1.type != matrix2.type)) {
        printf("Matrices can only be added if their dimensions are the same and they are of the same type.");
        exit(0);
    }
    
    //Create return Matrix
    struct Matrix result;
    result.type = matrix1.type;
    result.rows = matrix1.rows;
    result.cols = matrix1.cols;
    
    // Allocate memory for return Matrix
    result.data = (DataValue**)malloc(result.rows * sizeof(DataValue*));
    for (int i = 0; i < result.rows; i++) {
        result.data[i] = (DataValue*)malloc(result.cols * sizeof(DataValue));
    }
    
    //Iterates and Adds elements
    for (int i = 0; i < matrix1.rows; i++) {
        for (int j = 0; j < matrix1.cols; j++) {
            switch (matrix1.type) {
                case INT:
                    result.data[i][j].int_val = matrix1.data[i][j].int_val + matrix2.data[i][j].int_val;
                    break;
                case FLOAT:
                    result.data[i][j].float_val = matrix1.data[i][j].float_val + matrix2.data[i][j].float_val;
                    break;
                case SHORT_INT:
                    result.data[i][j].short_int_val = matrix1.data[i][j].short_int_val + matrix2.data[i][j].short_int_val;
                    break;
                case UNSIGNED_SHORT_INT:
                    result.data[i][j].unsigned_short_int_val = matrix1.data[i][j].unsigned_short_int_val + matrix2.data[i][j].unsigned_short_int_val;
                    break;
                case UNSIGNED_INT:
                    result.data[i][j].unsigned_int_val = matrix1.data[i][j].unsigned_int_val + matrix2.data[i][j].unsigned_int_val;
                    break;
                case LONG_INT:
                    result.data[i][j].long_int_val = matrix1.data[i][j].long_int_val + matrix2.data[i][j].long_int_val;
                    break;
                case UNSIGNED_LONG_INT:
                    result.data[i][j].unsigned_long_int_val = matrix1.data[i][j].unsigned_long_int_val + matrix2.data[i][j].unsigned_long_int_val;
                    break;
                case LONG_LONG_INT:
                    result.data[i][j].long_long_int_val = matrix1.data[i][j].long_long_int_val + matrix2.data[i][j].long_long_int_val;
                    break;
                case UNSIGNED_LONG_LONG_INT:
                    result.data[i][j].unsigned_long_long_int_val = matrix1.data[i][j].unsigned_long_long_int_val + matrix2.data[i][j].unsigned_long_long_int_val;
                    break;
                case LONG_DOUBLE:
                    result.data[i][j].long_double_val = matrix1.data[i][j].long_double_val + matrix2.data[i][j].long_double_val;
                    break;
                case LONG:
                    result.data[i][j].long_val = matrix1.data[i][j].long_val + matrix2.data[i][j].long_val;
                    break;
                case DOUBLE:
                    result.data[i][j].double_val = matrix1.data[i][j].double_val + matrix2.data[i][j].double_val;
                    break;
                default:
                    printf("There was an error");
                    clean(result);
                    break;
            }
        }
    }
    return result;
}

 
struct Matrix subtract(struct Matrix matrix1, struct Matrix matrix2) {
    //Checks if the matrices can be subtracted.
    if ((matrix1.rows + matrix1.cols) != (matrix2.rows + matrix2.cols) || (matrix1.type != matrix2.type)) {
        printf("Matrices can only be added if their dimensions are the same and they are of the same type..");
        exit(0);
    }
    
    //Create return Matrix
    struct Matrix result;
    result.type = matrix1.type;
    result.rows = matrix1.rows;
    result.cols = matrix1.cols;
    
    // Allocate memory for return Matrix
    result.data = (DataValue**)malloc(result.rows * sizeof(DataValue*));
    for (int i = 0; i < result.rows; i++) {
        result.data[i] = (DataValue*)malloc(result.cols * sizeof(DataValue));
    }
    
    //Iterates and Subtracts elements
    for (int i = 0; i < matrix1.rows; i++) {
        for (int j = 0; j < matrix1.cols; j++) {
            switch (matrix1.type) {
                case INT:
                    result.data[i][j].int_val = matrix1.data[i][j].int_val - matrix2.data[i][j].int_val;
                    break;
                case FLOAT:
                    result.data[i][j].float_val = matrix1.data[i][j].float_val - matrix2.data[i][j].float_val;
                    break;
                case SHORT_INT:
                    result.data[i][j].short_int_val = matrix1.data[i][j].short_int_val - matrix2.data[i][j].short_int_val;
                    break;
                case UNSIGNED_SHORT_INT:
                    result.data[i][j].unsigned_short_int_val = matrix1.data[i][j].unsigned_short_int_val - matrix2.data[i][j].unsigned_short_int_val;
                    break;
                case UNSIGNED_INT:
                    result.data[i][j].unsigned_int_val = matrix1.data[i][j].unsigned_int_val - matrix2.data[i][j].unsigned_int_val;
                    break;
                case LONG_INT:
                    result.data[i][j].long_int_val = matrix1.data[i][j].long_int_val - matrix2.data[i][j].long_int_val;
                    break;
                case UNSIGNED_LONG_INT:
                    result.data[i][j].unsigned_long_int_val = matrix1.data[i][j].unsigned_long_int_val - matrix2.data[i][j].unsigned_long_int_val;
                    break;
                case LONG_LONG_INT:
                    result.data[i][j].long_long_int_val = matrix1.data[i][j].long_long_int_val - matrix2.data[i][j].long_long_int_val;
                    break;
                case UNSIGNED_LONG_LONG_INT:
                    result.data[i][j].unsigned_long_long_int_val = matrix1.data[i][j].unsigned_long_long_int_val - matrix2.data[i][j].unsigned_long_long_int_val;
                    break;
                case LONG_DOUBLE:
                    result.data[i][j].long_double_val = matrix1.data[i][j].long_double_val - matrix2.data[i][j].long_double_val;
                    break;
                case LONG:
                    result.data[i][j].long_val = matrix1.data[i][j].long_val - matrix2.data[i][j].long_val;
                    break;
                case DOUBLE:
                    result.data[i][j].double_val = matrix1.data[i][j].double_val - matrix2.data[i][j].double_val;
                    break;
                default:
                    printf("There was an error");
                    clean(result);
                    break;
            }
        }
    }
    return result;
}

struct Matrix multiply(struct Matrix matrix1, struct Matrix matrix2) {
    
    if ((matrix1.cols != matrix2.rows) || (matrix1.type != matrix2.type)) {
        printf("Matrices can only be multiplied if the number of columnes in the first matrix matches the number of rows in the second matrix and the type matches.");
        exit(0);
    }
    
    struct Matrix result;
    result.type = matrix1.type;
    result.rows = matrix2.cols;
    result.cols = matrix1.rows;
    
    result.data = (DataValue**)malloc(result.rows * sizeof(DataValue*));
    for (int i = 0; i < result.rows; i++) {
        result.data[i] = (DataValue*)malloc(result.cols * sizeof(DataValue));
    }
    //Iterates over the new Matrix and assigns its value
    for (int i = 0; i < matrix1.rows; i++) {
        for (int j = 0; j < matrix2.cols; j++) {
            switch (matrix1.type) {
                case INT:
                    result.data[i][j].int_val = 0;
                    for (int k = 0; k < matrix1.cols; k++) {
                        result.data[i][j].int_val += matrix1.data[i][k].int_val * matrix2.data[k][j].int_val;
                    }
                    break;
                case FLOAT:
                    result.data[i][j].float_val = 0.0f;
                    for (int k = 0; k < matrix1.cols; k++) {
                        result.data[i][j].float_val += matrix1.data[i][k].float_val * matrix2.data[k][j].float_val;
                    }
                    break;
                case SHORT_INT:
                    result.data[i][j].short_int_val = 0;
                    for (int k = 0; k < matrix1.cols; k++) {
                        result.data[i][j].short_int_val += matrix1.data[i][k].short_int_val * matrix2.data[k][j].short_int_val;
                    }
                    break;
                case UNSIGNED_SHORT_INT:
                    result.data[i][j].unsigned_short_int_val = 0;
                    for (int k = 0; k < matrix1.cols; k++) {
                        result.data[i][j].unsigned_short_int_val += matrix1.data[i][k].unsigned_short_int_val * matrix2.data[k][j].unsigned_short_int_val;
                    }
                    break;
                case UNSIGNED_INT:
                    result.data[i][j].unsigned_int_val = 0;
                    for (int k = 0; k < matrix1.cols; k++) {
                        result.data[i][j].unsigned_int_val += matrix1.data[i][k].unsigned_int_val * matrix2.data[k][j].unsigned_int_val;
                    }
                    break;
                case LONG_INT:
                    result.data[i][j].long_int_val = 0;
                    for (int k = 0; k < matrix1.cols; k++) {
                        result.data[i][j].long_int_val += matrix1.data[i][k].long_int_val * matrix2.data[k][j].long_int_val;
                    }
                    break;
                case UNSIGNED_LONG_INT:
                    result.data[i][j].unsigned_long_int_val = 0;
                    for (int k = 0; k < matrix1.cols; k++) {
                        result.data[i][j].unsigned_long_int_val += matrix1.data[i][k].unsigned_long_int_val * matrix2.data[k][j].unsigned_long_int_val;
                    }
                    break;
                case LONG_LONG_INT:
                    result.data[i][j].long_long_int_val = 0;
                    for (int k = 0; k < matrix1.cols; k++) {
                        result.data[i][j].long_long_int_val += matrix1.data[i][k].long_long_int_val * matrix2.data[k][j].long_long_int_val;
                    }
                    break;
                case UNSIGNED_LONG_LONG_INT:
                    result.data[i][j].unsigned_long_long_int_val = 0;
                    for (int k = 0; k < matrix1.cols; k++) {
                        result.data[i][j].unsigned_long_long_int_val += matrix1.data[i][k].unsigned_long_long_int_val * matrix2.data[k][j].unsigned_long_long_int_val;
                    }
                    break;
                case LONG_DOUBLE:
                    result.data[i][j].long_double_val = 0.0L;
                    for (int k = 0; k < matrix1.cols; k++) {
                        result.data[i][j].long_double_val += matrix1.data[i][k].long_double_val * matrix2.data[k][j].long_double_val;
                    }
                    break;
                case LONG:
                    result.data[i][j].long_val = 0;
                    for (int k = 0; k < matrix1.cols; k++) {
                        result.data[i][j].long_val += matrix1.data[i][k].long_val * matrix2.data[k][j].long_val;
                    }
                    break;
                case DOUBLE:
                    result.data[i][j].double_val = 0.0;
                    for (int k = 0; k < matrix1.cols; k++) {
                        result.data[i][j].double_val += matrix1.data[i][k].double_val * matrix2.data[k][j].double_val;
                    }
                    break;
                default:
                    printf("There was an error");
                    clean(result);
                    break;
            }
        }
    }
    return result;
}
    






