#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"


//Can create a deep subset of a given matrix. 
struct Matrix resize(struct Matrix matrix, unsigned long long int rows, unsigned long long int cols) {
    if ((rows < 0) || (cols < 0) || (rows > matrix.rows) || (cols > matrix.cols)) {
        printf("Rows and Cols must be non-negative and smaller than the matrix's original size");
        exit(0);
    }
    
    //Allocate return Matrix
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

    // Copy values
    for (unsigned long long int i = 0; i < rows; i++) {
        for (unsigned long long int j = 0; j < cols; j++) {
            newArray[i][j] = matrix.data[i][j];
        }
    }

    matrix.data = newArray;
    matrix.rows = rows;
    matrix.cols = cols;

    return matrix;
}