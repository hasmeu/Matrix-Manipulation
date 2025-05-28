#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
#include <string.h>
#include <stdbool.h>


//i decided to use a global variable, since the only time it is changed, is when the user calls the setter functions
bool row_Major = true;

//returns the data of struct Matrix established in matrix.h
struct Matrix initialize(FILE* fp, DataType type) {
    //col major version
    if (!row_Major) {
        
        struct Matrix matrix;
        matrix.type = type;
     
        //checks if the pointer is null
        if (fp == NULL) {
            printf("Could not open file. Ended Program");
            exit(EXIT_FAILURE);
        }

    
        // it only takes 8 bytes for an unsigned long long int. 
        //this is more reasonable than having a smaller datatype and running checks to make sure the number of rows and cols input is not too big.
        long long int rows, cols;
   
        //gets first line ints from txt and sets as rows and cols
        //if fscanf does not return 2 values, it means it read a char/string, or nothing
        if (fscanf(fp, "%llu %llu", &rows, &cols) != 2) {
            printf("Dimensions must be non-negative integers. Ended Program.");
            exit(EXIT_FAILURE);
        };
     
        // Check if dimensions are non-negative
        if (rows <= 0 || cols <= 0) {
            printf("Dimensions must be non-negative integers. Ended Program.");
            exit(EXIT_FAILURE);
            
        };
     
    
        //deletes the rest of the first line and skips to the second
        while (fgetc(fp) != '\n') {}
    
        //stores current location of the reader at the second line. Use long int because ftell function returns a long int.
        long int currentPosition = ftell(fp);

        //goes until there is not another element on the second line and increments totalElements for each one.
        int totalElements = 0;
    
        switch (type) {
            case INT: {
            //temporary int to store the result of fscanf
                int value;
                while (fscanf(fp, "%d", &value) == 1) {
                    totalElements++;
                }
                break;
            }
            case DOUBLE: {
                double dvalue;
                while (fscanf(fp, "%lf", &dvalue) == 1) {
                    totalElements++;
                }
                break;
            }
            case FLOAT: {
                float fvalue;
                while (fscanf(fp, "%f", &fvalue) == 1) {
                    totalElements++;
                }
                break;
            }
            case LONG: {
                long lvalue;
                while (fscanf(fp, "%ld", &lvalue) == 1) {
                    totalElements++;
                }
                break;
            }
            case SHORT_INT: {
                short int shortValue;
                while (fscanf(fp, "%hd", &shortValue) == 1) {
                    totalElements++;
                }
                break;
            }
            case UNSIGNED_SHORT_INT: {
                unsigned short int unsignedShortValue;
                while (fscanf(fp, "%hu", &unsignedShortValue) == 1) {
                    totalElements++;
                }
                break;
            }
            case UNSIGNED_INT: {
                unsigned int unsignedIntValue;
                while (fscanf(fp, "%u", &unsignedIntValue) == 1) {
                    totalElements++;
                }
                break; 
            }
            case LONG_INT: {
                long int longIntValue;
                while (fscanf(fp, "%ld", &longIntValue) == 1) {
                    totalElements++;
                }
                break; 
            }
            case UNSIGNED_LONG_INT: {
                unsigned long int unsignedLongIntValue;
                while (fscanf(fp, "%lu", &unsignedLongIntValue) == 1) {
                    totalElements++;
                }
                break;
            }
            case LONG_LONG_INT: {
                long long int longLongIntValue;
                while (fscanf(fp, "%lld", &longLongIntValue) == 1) {
                    totalElements++;
                }
                break;
            }
            case UNSIGNED_LONG_LONG_INT: {
                unsigned long long int unsignedLongLongIntValue;
                while (fscanf(fp, "%llu", &unsignedLongLongIntValue) == 1) {
                    totalElements++;
                }
                break;
            }
            case LONG_DOUBLE: {
                long double longDoubleValue;
                while (fscanf(fp, "%Lf", &longDoubleValue) == 1) {
                    totalElements++;
                }
                break;
            }
            default:
                printf("Unsupported data type. Ended Program.");
                exit(EXIT_FAILURE);
        }
    
    

        // checks if the counted number of elements matches the amount it should have
        if (totalElements < (rows * cols)) {
            printf("Not enough elements are in the file to fill the number of rows and columns. Or, entered a too small data type. Ended Program.\n");
            exit(EXIT_FAILURE);
        }
        //if there are more elements than space for a matrix, let the user know.
    
        if (totalElements > (rows * cols)) {
            printf("There are more elements in the file than matrix space \n");
        
        }

        // reset the file pointer to the second line. Seek set means the beginning of file. current position is the offset
        fseek(fp, currentPosition, SEEK_SET);
    

        //establishes an array of pointers
        DataValue** array = malloc(cols * sizeof(DataValue*));
        //if fails exit
        if (array == NULL) {
            printf("Memory allocation failed. Ended Program.");
            exit(EXIT_FAILURE);
            //removes memory allocated for array of pointers
            free(array);
        }
    
    
        //creates memory dedicated to each pointer in the array of pointers
        //iterates over each row
        for (unsigned long long int j = 0; j < cols; j++) {
            //creates memory for each col using the size of DataValue type
            array[j] = malloc(rows * sizeof(DataValue));
            //if any location in a row does not have memory, exit
            if (array[j] == NULL) {
                // cleans up previously allocated memory if fails
                for (unsigned long long int k = 0; k < j; k++) {
                    free(array[k]);
                }
                free(array);
                printf("Memory allocation failed. Ended Program.");
                exit(EXIT_FAILURE);
            }
            //copies second line of txt to array as ints in !!!!!! Row major order
            //iterates over each col
            //array of pointers to DataValue union types
            for (unsigned long long int i = 0; i < rows; i++) {
            
                switch (type) {
                    case INT:
                                        //store the read number to the address of the ith row and jth col as a certain data type from the union.
                        if (fscanf(fp, "%d", &(((DataValue*)array[j])[i].int_val)) != 1) {
                            printf("Error reading file. Ended Program.");
                            exit(EXIT_FAILURE);
                        }
                        break;
                    case SHORT_INT:
                        if (fscanf(fp, "%hd", &(((DataValue*)array[i])[j].short_int_val)) != 1) {
                            printf("Error reading file. Ended Program.");
                            exit(EXIT_FAILURE);
                        }
                        break;
                    case UNSIGNED_SHORT_INT:
                        if (fscanf(fp, "%hu", &(((DataValue*)array[i])[j].unsigned_short_int_val)) != 1) {
                            printf("Error reading file. Ended Program.");
                            exit(EXIT_FAILURE);
                        }
                        break;
                    case UNSIGNED_INT:
                        if (fscanf(fp, "%u", &(((DataValue*)array[i])[j].unsigned_int_val)) != 1) {
                            printf("Error reading file. Ended Program.");
                            exit(EXIT_FAILURE);
                        }
                        break;
                    case LONG:
                        if (fscanf(fp, "%ld", &(((DataValue*)array[i])[j].long_val)) != 1) {
                            printf("Error reading file. Ended Program.");
                            exit(EXIT_FAILURE);
                        }
                        break;
                    case LONG_INT:
                        if (fscanf(fp, "%ld", &(((DataValue*)array[i])[j].long_int_val)) != 1) {
                            printf("Error reading file. Ended Program.");
                            exit(EXIT_FAILURE);
                        }
                        break;
                    case UNSIGNED_LONG_INT:
                        if (fscanf(fp, "%lu", &(((DataValue*)array[i])[j].unsigned_long_int_val)) != 1) {
                            printf("Error reading file. Ended Program.");
                            exit(EXIT_FAILURE);
                        }
                        break;
                    case LONG_LONG_INT:
                        if (fscanf(fp, "%lld", &(((DataValue*)array[i])[j].long_long_int_val)) != 1) {
                            printf("Error reading file. Ended Program.");
                            exit(EXIT_FAILURE);
                        }
                        break;
                    case LONG_DOUBLE:
                        if (fscanf(fp, "%Lf", &(((DataValue*)array[i])[j].long_double_val)) != 1) {
                            printf("Error reading file. Ended Program.");
                            exit(EXIT_FAILURE);
                        }
                        break;
                    case UNSIGNED_LONG_LONG_INT:
                        if (fscanf(fp, "%llu", &(((DataValue*)array[i])[j].unsigned_long_long_int_val)) != 1) {
                            printf("Error reading file. Ended Program.");
                            exit(EXIT_FAILURE);
                        }
                        break;
                    case FLOAT:
                        if (fscanf(fp, "%f", &(((DataValue*)array[i])[j].float_val)) != 1) {
                            printf("Error reading file. Ended Program.");
                            exit(EXIT_FAILURE);
                        }
                        break;
                    case DOUBLE:
                        if (fscanf(fp, "%lf", &(((DataValue*)array[i])[j].double_val)) != 1) {
                            printf("Error reading file. Ended Program.");
                            exit(EXIT_FAILURE);
                        }
                        break;
                    default:
                        for (unsigned long long int j = 0; j < i; j++) {
                            free(array[j]);
                        }
                        free(array);
                        printf("Invalid data type. Ended Program.\n");
                        exit(EXIT_FAILURE);
                    
                }
            }
        }
        //assigns the required attributes
        matrix.rows = rows;
        matrix.cols = cols;
        matrix.data = array;
        return matrix;
    } 
    //row major version
    struct Matrix matrix;
    matrix.type = type;
     
    //checks if the pointer is null
    if (fp == NULL) {
        printf("Could not open file. Ended Program.");
        exit(EXIT_FAILURE);
    }

    
    // it only takes 8 bytes for an unsigned long long int. 
    //this is more reasonable than having a smaller datatype and running checks to make sure the number of rows and cols input is not too big.
    long long int rows, cols;
   
    //gets first line ints from txt and sets as rows and cols
    //if fscanf does not return 2 values, it means it read a char/string, or nothing
    if (fscanf(fp, "%llu %llu", &rows, &cols) != 2) {
        printf("Dimensions must be non-negative integers. Ended Program.");
        exit(EXIT_FAILURE);
    };
     
     // Check if dimensions are non-negative
    if (rows <= 0 || cols <= 0) {
        printf("Dimensions must be non-negative integers. Ended Program.");
        exit(EXIT_FAILURE);
    };
     
    
    //deletes the rest of the first line and skips to the second
    while (fgetc(fp) != '\n') {}
    
    //stores current location of the reader at the second line. Use long int because ftell function returns a long int.
    long int currentPosition = ftell(fp);

    //goes until there is not another element on the second line and increments totalElements for each one.
    int totalElements = 0;
    
    switch (type) {
        case INT: {
        //temporary int to store the result of fscanf
            int value;
            while (fscanf(fp, "%d", &value) == 1) {
                totalElements++;
            }
            break;
        }
        case DOUBLE: {
            double dvalue;
            while (fscanf(fp, "%lf", &dvalue) == 1) {
                totalElements++;
            }
            break;
        }
        case FLOAT: {
            float fvalue;
            while (fscanf(fp, "%f", &fvalue) == 1) {
                totalElements++;
            }
            break;
        }
        case LONG: {
            long lvalue;
            while (fscanf(fp, "%ld", &lvalue) == 1) {
                totalElements++;
            }
            break;
        }
        case SHORT_INT: {
            short int shortValue;
            while (fscanf(fp, "%hd", &shortValue) == 1) {
                totalElements++;
            }
            break;
        }
        case UNSIGNED_SHORT_INT: {
            unsigned short int unsignedShortValue;
            while (fscanf(fp, "%hu", &unsignedShortValue) == 1) {
                totalElements++;
            }
            break;
        }
        case UNSIGNED_INT: {
            unsigned int unsignedIntValue;
            while (fscanf(fp, "%u", &unsignedIntValue) == 1) {
                totalElements++;
            }
            break; 
        }
        case LONG_INT: {
            long int longIntValue;
            while (fscanf(fp, "%ld", &longIntValue) == 1) {
                totalElements++;
            }
            break; 
        }
        case UNSIGNED_LONG_INT: {
            unsigned long int unsignedLongIntValue;
            while (fscanf(fp, "%lu", &unsignedLongIntValue) == 1) {
                totalElements++;
            }
            break;
        }
        case LONG_LONG_INT: {
            long long int longLongIntValue;
            while (fscanf(fp, "%lld", &longLongIntValue) == 1) {
                totalElements++;
            }
            break;
        }
        case UNSIGNED_LONG_LONG_INT: {
            unsigned long long int unsignedLongLongIntValue;
            while (fscanf(fp, "%llu", &unsignedLongLongIntValue) == 1) {
                totalElements++;
            }
            break;
        }
        case LONG_DOUBLE: {
            long double longDoubleValue;
            while (fscanf(fp, "%Lf", &longDoubleValue) == 1) {
                totalElements++;
            }
            break;
        }
        default:
            printf("Unsupported data type. Ended Program.");
            exit(EXIT_FAILURE);
            
    }
    
    

    // checks if the counted number of elements matches the amount it should have
    if (totalElements < (rows * cols)) {
        printf("Not enough elements are in the file to fill the number of rows and columns. Or, entered a too small data type. Ended Program.\n");
        exit(EXIT_FAILURE);
    }
    //if there are more elements than space for a matrix, let the user know.
    
    if (totalElements > (rows * cols)) {
        printf("There are more elements in the file than matrix space. Ended Program. \n");
        
    }

    // reset the file pointer to the second line. Seek set means the beginning of file. current position is the offset
    fseek(fp, currentPosition, SEEK_SET);
    

    //establishes an array of pointers
    DataValue** array = malloc(rows * sizeof(DataValue*));
    //if fails exit
    if (array == NULL) {
        printf("Memory allocation failed. Ended Program.");
        free(array);
        exit(EXIT_FAILURE);
        //removes memory allocated for array of pointers
        
    }
    
    
    //creates memory dedicated to each pointer in the array of pointers
    //iterates over each row
    for (unsigned long long int i = 0; i < rows; i++) {
        //creates memory for each col using the size of DataValue type
        array[i] = malloc(cols * sizeof(DataValue));
        //if any location in a row does not have memory, exit
        if (array[i] == NULL) {
            // cleans up previously allocated memory if fails
            for (unsigned long long int j = 0; j < i; j++) {
                free(array[j]);
            }
            free(array);
            printf("Memory allocation failed. Ended Program.");
            exit(EXIT_FAILURE);
           
        }
        //copies second line of txt to array as ints in !!!!!! Row major order
        //iterates over each col
        //array of pointers to DataValue union types
        for (unsigned long long int j = 0; j < cols; j++) {
            
            switch (type) {
                case INT:
                                        //store the read number to the address of the ith row and jth col as a certain data type from the union.
                    if (fscanf(fp, "%d", &(((DataValue*)array[i])[j].int_val)) != 1) {
                        printf("Error reading file. Ended Program.");
                        for (unsigned long long int j = 0; j < i; j++) {
                            free(array[j]);
                        }
                        free(array);
                        exit(EXIT_FAILURE);
                        
                    }
                    break;
                case SHORT_INT:
                    if (fscanf(fp, "%hd", &(((DataValue*)array[i])[j].short_int_val)) != 1) {
                        printf("Error reading file. Ended Program.");
                        for (unsigned long long int j = 0; j < i; j++) {
                            free(array[j]);
                        }
                        free(array);
                        exit(EXIT_FAILURE);
                    }
                    break;
                case UNSIGNED_SHORT_INT:
                    if (fscanf(fp, "%hu", &(((DataValue*)array[i])[j].unsigned_short_int_val)) != 1) {
                        printf("Error reading file. Ended Program.");
                        for (unsigned long long int j = 0; j < i; j++) {
                            free(array[j]);
                        }
                        free(array);
                        exit(EXIT_FAILURE);
                    }
                    break;
                case UNSIGNED_INT:
                    if (fscanf(fp, "%u", &(((DataValue*)array[i])[j].unsigned_int_val)) != 1) {
                        printf("Error reading file. Ended Program.");
                        for (unsigned long long int j = 0; j < i; j++) {
                            free(array[j]);
                        }
                        free(array);
                        exit(EXIT_FAILURE);
                    }
                    break;
                case LONG:
                    if (fscanf(fp, "%ld", &(((DataValue*)array[i])[j].long_val)) != 1) {
                        printf("Error reading file. Ended Program.");
                        for (unsigned long long int j = 0; j < i; j++) {
                            free(array[j]);
                        }
                        free(array);
                        exit(EXIT_FAILURE);
                    }
                    break;
                
                case LONG_INT:
                    if (fscanf(fp, "%ld", &(((DataValue*)array[i])[j].long_int_val)) != 1) {
                        printf("Error reading file. Ended Program.");
                        for (unsigned long long int j = 0; j < i; j++) {
                            free(array[j]);
                        }
                        free(array);
                        exit(EXIT_FAILURE);
                    }
                    break;
                case UNSIGNED_LONG_INT:
                    if (fscanf(fp, "%lu", &(((DataValue*)array[i])[j].unsigned_long_int_val)) != 1) {
                        printf("Error reading file. Ended Program.");
                        for (unsigned long long int j = 0; j < i; j++) {
                            free(array[j]);
                        }
                        free(array);
                        exit(EXIT_FAILURE);
                    }
                    break;
                case LONG_LONG_INT:
                    if (fscanf(fp, "%lld", &(((DataValue*)array[i])[j].long_long_int_val)) != 1) {
                        printf("Error reading file. Ended Program.");
                        for (unsigned long long int j = 0; j < i; j++) {
                            free(array[j]);
                        }
                        free(array);
                        exit(EXIT_FAILURE);
                    }
                    break;
                case LONG_DOUBLE:
                    if (fscanf(fp, "%Lf", &(((DataValue*)array[i])[j].long_double_val)) != 1) {
                        printf("Error reading file. Ended Program.");
                        for (unsigned long long int j = 0; j < i; j++) {
                            free(array[j]);
                        }
                        free(array);
                        exit(EXIT_FAILURE);
                    }
                    break;
                case UNSIGNED_LONG_LONG_INT:
                    if (fscanf(fp, "%llu", &(((DataValue*)array[i])[j].unsigned_long_long_int_val)) != 1) {
                        printf("Error reading file. Ended Program.");
                        for (unsigned long long int j = 0; j < i; j++) {
                            free(array[j]);
                        }
                        free(array);
                        exit(EXIT_FAILURE);
                    }
                    break;
                case FLOAT:
                    if (fscanf(fp, "%f", &(((DataValue*)array[i])[j].float_val)) != 1) {
                        printf("Error reading file. Ended Program.");
                        for (unsigned long long int j = 0; j < i; j++) {
                            free(array[j]);
                        }
                        free(array);
                        exit(EXIT_FAILURE);
                    }
                    break;
                case DOUBLE:
                    if (fscanf(fp, "%lf", &(((DataValue*)array[i])[j].double_val)) != 1) {
                        printf("Error reading file. Ended Program.");
                        for (unsigned long long int j = 0; j < i; j++) {
                            free(array[j]);
                        }
                        free(array);
                        exit(EXIT_FAILURE);
                    }
                    break;
                default:
                    for (unsigned long long int j = 0; j < i; j++) {
                        free(array[j]);
                    }
                    free(array);
                    printf("Invalid data type\n");
                    exit(EXIT_FAILURE);
            }
        }
    }
    //assigns the required attributes
    
    matrix.rows = rows;
    matrix.cols = cols;
    matrix.data = array;
    

    return matrix;
}

void printArray(struct Matrix matrix1) {
    
    if (matrix1.data == NULL) {
        printf("The object being printed must have a 2d array assigned to it");
        exit(0);
    }
    //col major version
    if (!row_Major) {
        for (unsigned long long int j = 0; j < matrix1.cols; j++) {
        //prints all results inside one row
        for (unsigned long long int i = 0; i < matrix1.rows; i++) {
            switch (matrix1.type) {
                case INT:
                    printf("%d ", ((DataValue*)matrix1.data[i])[j].int_val);
                    break;
                case LONG:
                    printf("%ld ", ((DataValue*)matrix1.data[i])[j].long_int_val);
                    break;
                case FLOAT:
                    printf("%f ", ((DataValue*)matrix1.data[i])[j].float_val);
                    break;
                case DOUBLE:
                    printf("%lf ", ((DataValue*)matrix1.data[i])[j].double_val);
                    break;
                case SHORT_INT:
                    printf("%hd ", ((DataValue*)matrix1.data[i])[j].short_int_val);
                    break;
                case UNSIGNED_SHORT_INT:
                    printf("%hu ", ((DataValue*)matrix1.data[i])[j].unsigned_short_int_val);
                    break;
                case UNSIGNED_INT:
                    printf("%u ", ((DataValue*)matrix1.data[i])[j].unsigned_int_val);
                    break;
                case LONG_INT:
                    printf("%ld ", ((DataValue*)matrix1.data[i])[j].long_int_val);
                    break;
                case UNSIGNED_LONG_INT:
                    printf("%lu ", ((DataValue*)matrix1.data[i])[j].unsigned_long_int_val);
                    break;
                case LONG_LONG_INT:
                    printf("%lld ", ((DataValue*)matrix1.data[i])[j].long_long_int_val);
                    break;
                case LONG_DOUBLE:
                    printf("%Lf ", ((DataValue*)matrix1.data[i])[j].long_double_val);
                    break;
                case UNSIGNED_LONG_LONG_INT:
                    printf("%llu ", ((DataValue*)matrix1.data[i])[j].unsigned_long_long_int_val);
                    break;
                default:
                    printf("Unsupported data type. Ended Program.");
                    exit(EXIT_FAILURE);
                    
            }
        }
        printf("\n");
        
        
    }
        
    } else {
    
    //starts at first pointer in array of pointers
    for (unsigned long long int i = 0; i < matrix1.rows; i++) {
        //prints all results inside one row
        for (unsigned long long int j = 0; j < matrix1.cols; j++) {
            switch (matrix1.type) {
                case INT:
                    printf("%d ", ((DataValue*)matrix1.data[i])[j].int_val);
                    break;
                case LONG:
                    printf("%ld ", ((DataValue*)matrix1.data[i])[j].long_int_val);
                    break;
                case FLOAT:
                    printf("%f ", ((DataValue*)matrix1.data[i])[j].float_val);
                    break;
                case DOUBLE:
                    printf("%lf ", ((DataValue*)matrix1.data[i])[j].double_val);
                    break;
                case SHORT_INT:
                    printf("%hd ", ((DataValue*)matrix1.data[i])[j].short_int_val);
                    break;
                case UNSIGNED_SHORT_INT:
                    printf("%hu ", ((DataValue*)matrix1.data[i])[j].unsigned_short_int_val);
                    break;
                case UNSIGNED_INT:
                    printf("%u ", ((DataValue*)matrix1.data[i])[j].unsigned_int_val);
                    break;
                case LONG_INT:
                    printf("%ld ", ((DataValue*)matrix1.data[i])[j].long_int_val);
                    break;
                case UNSIGNED_LONG_INT:
                    printf("%lu ", ((DataValue*)matrix1.data[i])[j].unsigned_long_int_val);
                    break;
                case LONG_LONG_INT:
                    printf("%lld ", ((DataValue*)matrix1.data[i])[j].long_long_int_val);
                    break;
                case LONG_DOUBLE:
                    printf("%Lf ", ((DataValue*)matrix1.data[i])[j].long_double_val);
                    break;
                case UNSIGNED_LONG_LONG_INT:
                    printf("%llu ", ((DataValue*)matrix1.data[i])[j].unsigned_long_long_int_val);
                    break;
                default:
                    printf("Unsupported data type. Ended Program.");
                    exit(EXIT_FAILURE);
                    
            }
        }
        printf("\n");
        
    }
    }
    printf("\n");
}

void clean(struct Matrix matrix) {
    //colmajor version
    if (!row_Major) {
        //frees the memory for each col inside the array of pointers
        for (unsigned long long int j = 0; j < matrix.cols; j++) {
            free(matrix.data[j]);
        }
        //frees the array of pointers
        free(matrix.data);
        
    } else {
        //frees the memory for each row inside the array of pointers
        for (unsigned long long int i = 0; i < matrix.rows; i++) {
            free(matrix.data[i]);
        }
        //frees the array of pointers
        free(matrix.data);
    }
}


void columnMajor() {
    row_Major = false;
}

void rowMajor() {
    row_Major = true;
}
