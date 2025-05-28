#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
#include <string.h>

void rotate(struct Matrix matrix, int numberOfRotations) {
    
    if (matrix.data == NULL) {
        printf("Invalid matrix");
        exit(EXIT_FAILURE);
    }
    
    if (numberOfRotations < 0 || numberOfRotations == 0) {
        printf("\nThe number of rotations must be positive and greater than 0. Ended Program.");
        exit(EXIT_FAILURE);
    }

    //Allows for Swapping
    DataValue temp;
    int i = 0;
    while ( numberOfRotations > i) {
        //Diagonal Swapping
        for (unsigned long long int i = 0; i < matrix.rows; i++) {
            for (unsigned long long int j = i + 1; j < matrix.cols; j++) {
                switch (matrix.type) {
                    case INT:
                        temp.int_val = matrix.data[i][j].int_val;
                        matrix.data[i][j].int_val = matrix.data[j][i].int_val;
                        matrix.data[j][i].int_val = temp.int_val;
                        break;
                    case LONG:
                        temp.long_int_val = matrix.data[i][j].long_int_val;
                        matrix.data[i][j].long_int_val = matrix.data[j][i].long_int_val;
                        matrix.data[j][i].long_int_val = temp.long_int_val;
                        break;
                    case FLOAT:
                        temp.float_val = matrix.data[i][j].float_val;
                        matrix.data[i][j].float_val = matrix.data[j][i].float_val;
                        matrix.data[j][i].float_val = temp.float_val;
                        break;
                    case DOUBLE:
                        temp.double_val = matrix.data[i][j].double_val;
                        matrix.data[i][j].double_val = matrix.data[j][i].double_val;
                        matrix.data[j][i].double_val = temp.double_val;
                        break;
                    case SHORT_INT:
                        temp.short_int_val = matrix.data[i][j].short_int_val;
                        matrix.data[i][j].short_int_val = matrix.data[j][i].short_int_val;
                        matrix.data[j][i].short_int_val = temp.short_int_val;
                        break;
                    case UNSIGNED_SHORT_INT:
                        temp.unsigned_short_int_val = matrix.data[i][j].unsigned_short_int_val;
                        matrix.data[i][j].unsigned_short_int_val = matrix.data[j][i].unsigned_short_int_val;
                        matrix.data[j][i].unsigned_short_int_val = temp.unsigned_short_int_val;
                        break;
                    case UNSIGNED_INT:
                        temp.unsigned_int_val = matrix.data[i][j].unsigned_int_val;
                        matrix.data[i][j].unsigned_int_val = matrix.data[j][i].unsigned_int_val;
                        matrix.data[j][i].unsigned_int_val = temp.unsigned_int_val;
                        break;
                    case LONG_INT:
                        temp.long_int_val = matrix.data[i][j].long_int_val;
                        matrix.data[i][j].long_int_val = matrix.data[j][i].long_int_val;
                        matrix.data[j][i].long_int_val = temp.long_int_val;
                        break;
                    case UNSIGNED_LONG_INT:
                        temp.unsigned_long_int_val = matrix.data[i][j].unsigned_long_int_val;
                        matrix.data[i][j].unsigned_long_int_val = matrix.data[j][i].unsigned_long_int_val;
                        matrix.data[j][i].unsigned_long_int_val = temp.unsigned_long_int_val;
                        break;
                    case LONG_LONG_INT:
                        temp.long_long_int_val = matrix.data[i][j].long_long_int_val;
                        matrix.data[i][j].long_long_int_val = matrix.data[j][i].long_long_int_val;
                        matrix.data[j][i].long_long_int_val = temp.long_long_int_val;
                        break;
                    case UNSIGNED_LONG_LONG_INT:
                        temp.unsigned_long_long_int_val = matrix.data[i][j].unsigned_long_long_int_val;
                        matrix.data[i][j].unsigned_long_long_int_val = matrix.data[j][i].unsigned_long_long_int_val;
                        matrix.data[j][i].unsigned_long_long_int_val = temp.unsigned_long_long_int_val;
                        break;
                    case LONG_DOUBLE:
                        temp.long_double_val = matrix.data[i][j].long_double_val;
                        matrix.data[i][j].long_double_val = matrix.data[j][i].long_double_val;
                        matrix.data[j][i].long_double_val = temp.long_double_val;
                        break;
                    default:
                        printf("Unsupported data type");
                        exit(EXIT_FAILURE);
                }
            }
        }
         //Row Reversal
        for (unsigned long long int i = 0; i < matrix.rows; i++) {
            for (unsigned long long int j = 0; j < matrix.cols / 2; j++) {
                switch (matrix.type) {
                    case INT:
                        temp.int_val = matrix.data[i][j].int_val;
                        matrix.data[i][j].int_val = matrix.data[i][matrix.cols - j - 1].int_val;
                        matrix.data[i][matrix.cols - j - 1].int_val = temp.int_val;
                        break;
                    case LONG:
                        temp.long_int_val = matrix.data[i][j].long_int_val;
                        matrix.data[i][j].long_int_val = matrix.data[i][matrix.cols - j - 1].long_int_val;
                        matrix.data[i][matrix.cols - j - 1].long_int_val = temp.long_int_val;
                        break;
                    case FLOAT:
                        temp.float_val = matrix.data[i][j].float_val;
                        matrix.data[i][j].float_val = matrix.data[i][matrix.cols - j - 1].float_val;
                        matrix.data[i][matrix.cols - j - 1].float_val = temp.float_val;
                        break;
                    case DOUBLE:
                        temp.double_val = matrix.data[i][j].double_val;
                        matrix.data[i][j].double_val = matrix.data[i][matrix.cols - j - 1].double_val;
                        matrix.data[i][matrix.cols - j - 1].double_val = temp.double_val;
                        break;
                    case SHORT_INT:
                        temp.short_int_val = matrix.data[i][j].short_int_val;
                        matrix.data[i][j].short_int_val = matrix.data[i][matrix.cols - j - 1].short_int_val;
                        matrix.data[i][matrix.cols - j - 1].short_int_val = temp.short_int_val;
                        break;
                    case UNSIGNED_SHORT_INT:
                        temp.unsigned_short_int_val = matrix.data[i][j].unsigned_short_int_val;
                        matrix.data[i][j].unsigned_short_int_val = matrix.data[i][matrix.cols - j - 1].unsigned_short_int_val;
                        matrix.data[i][matrix.cols - j - 1].unsigned_short_int_val = temp.unsigned_short_int_val;
                        break;
                    case UNSIGNED_INT:
                        temp.unsigned_int_val = matrix.data[i][j].unsigned_int_val;
                        matrix.data[i][j].unsigned_int_val = matrix.data[i][matrix.cols - j - 1].unsigned_int_val;
                        matrix.data[i][matrix.cols - j - 1].unsigned_int_val = temp.unsigned_int_val;
                        break;
                    case LONG_INT:
                        temp.long_int_val = matrix.data[i][j].long_int_val;
                        matrix.data[i][j].long_int_val = matrix.data[i][matrix.cols - j - 1].long_int_val;
                        matrix.data[i][matrix.cols - j - 1].long_int_val = temp.long_int_val;
                        break;
                    case UNSIGNED_LONG_INT:
                        temp.unsigned_long_int_val = matrix.data[i][j].unsigned_long_int_val;
                        matrix.data[i][j].unsigned_long_int_val = matrix.data[i][matrix.cols - j - 1].unsigned_long_int_val;
                        matrix.data[i][matrix.cols - j - 1].unsigned_long_int_val = temp.unsigned_long_int_val;
                        break;
                    case LONG_LONG_INT:
                        temp.long_long_int_val = matrix.data[i][j].long_long_int_val;
                        matrix.data[i][j].long_long_int_val = matrix.data[i][matrix.cols - j - 1].long_long_int_val;
                        matrix.data[i][matrix.cols - j - 1].long_long_int_val = temp.long_long_int_val;
                        break;
                    case UNSIGNED_LONG_LONG_INT:
                        temp.unsigned_long_long_int_val = matrix.data[i][j].unsigned_long_long_int_val;
                        matrix.data[i][j].unsigned_long_long_int_val = matrix.data[i][matrix.cols - j - 1].unsigned_long_long_int_val;
                        matrix.data[i][matrix.cols - j - 1].unsigned_long_long_int_val = temp.unsigned_long_long_int_val;
                        break;
                    case LONG_DOUBLE:
                        temp.long_double_val = matrix.data[i][j].long_double_val;
                        matrix.data[i][j].long_double_val = matrix.data[i][matrix.cols - j - 1].long_double_val;
                        matrix.data[i][matrix.cols - j - 1].long_double_val = temp.long_double_val;
                        break;
                    default:
                        printf("Unsupported data type");
                        exit(EXIT_FAILURE);
                }
            }
        }
        i++;
    }
}
    

