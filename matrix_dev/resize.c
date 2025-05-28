#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"


//creates a subset of a given matrix also. also is a deep copy because it does not just point to the same location in memory, but rather creates a new location and deletes the old one.
struct Matrix resize(struct Matrix matrix, unsigned long long int rows, unsigned long long int cols) {
    if ((rows < 0) || (cols < 0) || (rows > matrix.rows) || (cols > matrix.cols)) {
        printf("Rows and Cols must be non-negative and smaller than the matrix's original size");
        exit(0);
    }
    
    // allocates memory for the new smaller matrix
    DataValue** newArray = malloc(rows * sizeof(DataValue*));
    if (newArray == NULL) {
        printf("Memory allocation failed");
        free(newArray);
        exit(EXIT_FAILURE);
        
    }
    for (unsigned long long int i = 0; i < rows; i++) {
        newArray[i] = malloc(cols * sizeof(DataValue));
        if (newArray[i] == NULL) {
            // cleans
            for (unsigned long long int j = 0; j < i; j++) {
                free(newArray[j]);
            }
            free(newArray);
            printf("Memory allocation failed");
            exit(EXIT_FAILURE);
        }
    }

    // copy values from the original matrix to the new matrix
    for (unsigned long long int i = 0; i < rows; i++) {
        for (unsigned long long int j = 0; j < cols; j++) {
            newArray[i][j] = matrix.data[i][j];
        }
    }

    // free the memory allocated for the original matrix
    //clean(matrix);

    // update the original matrix with the new values and size
    matrix.data = newArray;
    matrix.rows = rows;
    matrix.cols = cols;

    return matrix;
}