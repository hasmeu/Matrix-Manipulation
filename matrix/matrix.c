#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
#include <string.h>
#include <stdbool.h>


//I decided to use a global variable, since the only time it is changed, is when the user calls the setter functions
bool row_Major = true;


struct Matrix initialize(FILE* fp, DataType type) {
    //Column Major
    if (!row_Major) {
        
        struct Matrix matrix;
        matrix.type = type;
     
        if (fp == NULL) {
            printf("Could not open file. Ended Program");
            exit(EXIT_FAILURE);
        }

        // it only takes 8 bytes for an unsigned long long int. 
        //this is more reasonable than having a smaller datatype and running into issues if the value is too large
        long long int rows, cols;
   
        
        if (fscanf(fp, "%llu %llu", &rows, &cols) != 2) {
            printf("Dimensions must be non-negative integers. Ended Program.");
            exit(EXIT_FAILURE);
        };
     
        
        if (rows <= 0 || cols <= 0) {
            printf("Dimensions must be non-negative integers. Ended Program.");
            exit(EXIT_FAILURE);
            
        };
     
    
        //Deletes the rest of the first line and skips to the second
        while (fgetc(fp) != '\n') {}
    
        //stores current location of the reader at the second line. Use long int because ftell function returns a long int.
        long int currentPosition = ftell(fp);

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
    
    

        if (totalElements < (rows * cols)) {
            printf("Not enough elements are in the file to fill the number of rows and columns. Or, entered a too small data type. Ended Program.\n");
            exit(EXIT_FAILURE);
        }
    
        if (totalElements > (rows * cols)) {
            printf("There are more elements in the file than matrix space \n");
        
        }

        //Reset the file pointer to the second line. 
        fseek(fp, currentPosition, SEEK_SET);
    

        //Array of pointers to DataValue union types
        DataValue** array = malloc(cols * sizeof(DataValue*));
        
        if (array == NULL) {
            printf("Memory allocation failed. Ended Program.");
            free(array);
            exit(EXIT_FAILURE);
        }
    
    
        for (unsigned long long int j = 0; j < cols; j++) {
            array[j] = malloc(rows * sizeof(DataValue));
            if (array[j] == NULL) {
                for (unsigned long long int k = 0; k < j; k++) {
                    free(array[k]);
                }
                free(array);
                printf("Memory allocation failed. Ended Program.");
                exit(EXIT_FAILURE);
            }
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
        matrix.rows = rows;
        matrix.cols = cols;
        matrix.data = array;
        return matrix;
    } 
    //row major version
    struct Matrix matrix;
    matrix.type = type;
     
    if (fp == NULL) {
        printf("Could not open file. Ended Program.");
        exit(EXIT_FAILURE);
    }

    
    long long int rows, cols;
   
    if (fscanf(fp, "%llu %llu", &rows, &cols) != 2) {
        printf("Dimensions must be non-negative integers. Ended Program.");
        exit(EXIT_FAILURE);
    };
     
    if (rows <= 0 || cols <= 0) {
        printf("Dimensions must be non-negative integers. Ended Program.");
        exit(EXIT_FAILURE);
    };
     
    
    while (fgetc(fp) != '\n') {}
    
    long int currentPosition = ftell(fp);

    int totalElements = 0;
    
    switch (type) {
        case INT: {
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
    
    

    if (totalElements < (rows * cols)) {
        printf("Not enough elements are in the file to fill the number of rows and columns. Or, entered a too small data type. Ended Program.\n");
        exit(EXIT_FAILURE);
    }
    
    if (totalElements > (rows * cols)) {
        printf("There are more elements in the file than matrix space. Ended Program. \n");
        
    }

    fseek(fp, currentPosition, SEEK_SET);
    

    DataValue** array = malloc(rows * sizeof(DataValue*));
    if (array == NULL) {
        printf("Memory allocation failed. Ended Program.");
        free(array);
        exit(EXIT_FAILURE);
        
    }
    
    
    for (unsigned long long int i = 0; i < rows; i++) {
        array[i] = malloc(cols * sizeof(DataValue));
        if (array[i] == NULL) {
            for (unsigned long long int j = 0; j < i; j++) {
                free(array[j]);
            }
            free(array);
            printf("Memory allocation failed. Ended Program.");
            exit(EXIT_FAILURE);
           
        }
        
        for (unsigned long long int j = 0; j < cols; j++) {
            
            switch (type) {
                case INT:
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
    //Column Major
    if (!row_Major) {
        for (unsigned long long int j = 0; j < matrix1.cols; j++) {
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
    //Row Major
    for (unsigned long long int i = 0; i < matrix1.rows; i++) {
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
    //Column Major
    if (!row_Major) {
        //Free Data Values
        for (unsigned long long int j = 0; j < matrix.cols; j++) {
            free(matrix.data[j]);
        }
        //Free Array of Pointers
        free(matrix.data);
        
    } else {
        for (unsigned long long int i = 0; i < matrix.rows; i++) {
            free(matrix.data[i]);
        }
        free(matrix.data);
    }
}


void columnMajor() {
    row_Major = false;
}

void rowMajor() {
    row_Major = true;
}
