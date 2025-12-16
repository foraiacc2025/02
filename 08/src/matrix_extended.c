#include <stdio.h>
#include <stdlib.h>

#define MAX_STATIC 100

int **allocate_matrix_1(int rows, int cols);
int **allocate_matrix_2(int rows, int cols);
int **allocate_matrix_3(int rows, int cols);
int input_matrix_static(int matrix[MAX_STATIC][MAX_STATIC], int *rows, int *cols);
int input_dynamic_matrix(int **matrix, int rows, int cols);
void output_matrix_static(int matrix[MAX_STATIC][MAX_STATIC], int rows, int cols);
void output_matrix_dynamic(int **matrix, int rows, int cols);
void free_matrix_1(int **matrix, int rows);
void free_matrix_2(int **matrix);
void free_matrix_3(int **matrix);
void find_max_in_rows_static(int matrix[MAX_STATIC][MAX_STATIC], int rows, int cols, int *max_array);
void find_max_in_rows_dynamic(int **matrix, int rows, int cols, int *max_array);
void find_min_in_cols_static(int matrix[MAX_STATIC][MAX_STATIC], int rows, int cols, int *min_array);
void find_min_in_cols_dynamic(int **matrix, int rows, int cols, int *min_array);

int main() {
    int mode = 0;
    int rows = 0;
    int cols = 0;
    int result = 0;
    
    if (scanf("%d", &mode) != 1 || mode < 1 || mode > 4) {
        printf("n/a");
        return 1;
    }
    
    if (mode == 1) {
        int matrix[MAX_STATIC][MAX_STATIC];
        if (input_matrix_static(matrix, &rows, &cols)) {
            printf("n/a");
            result = 1;
        } else {
            output_matrix_static(matrix, rows, cols);
            int *max_array = (int *)malloc(rows * sizeof(int));
            int *min_array = (int *)malloc(cols * sizeof(int));
            if (max_array != NULL && min_array != NULL) {
                find_max_in_rows_static(matrix, rows, cols, max_array);
                find_min_in_cols_static(matrix, rows, cols, min_array);
                printf("\n");
                for (int i = 0; i < rows; i++) {
                    printf("%d", max_array[i]);
                    if (i < rows - 1) {
                        printf(" ");
                    }
                }
                printf("\n");
                for (int i = 0; i < cols; i++) {
                    printf("%d", min_array[i]);
                    if (i < cols - 1) {
                        printf(" ");
                    }
                }
                free(max_array);
                free(min_array);
            } else {
                printf("n/a");
                result = 1;
                if (max_array != NULL) free(max_array);
                if (min_array != NULL) free(min_array);
            }
        }
    } else {
        if (scanf("%d %d", &rows, &cols) != 2 || rows <= 0 || cols <= 0) {
            printf("n/a");
            return 1;
        }
        
        int **matrix = NULL;
        if (mode == 2) {
            matrix = allocate_matrix_1(rows, cols);
        } else if (mode == 3) {
            matrix = allocate_matrix_2(rows, cols);
        } else if (mode == 4) {
            matrix = allocate_matrix_3(rows, cols);
        }
        
        if (matrix == NULL) {
            printf("n/a");
            return 1;
        }
        
        if (input_dynamic_matrix(matrix, rows, cols)) {
            printf("n/a");
            result = 1;
        } else {
            output_matrix_dynamic(matrix, rows, cols);
            int *max_array = (int *)malloc(rows * sizeof(int));
            int *min_array = (int *)malloc(cols * sizeof(int));
            if (max_array != NULL && min_array != NULL) {
                find_max_in_rows_dynamic(matrix, rows, cols, max_array);
                find_min_in_cols_dynamic(matrix, rows, cols, min_array);
                printf("\n");
                for (int i = 0; i < rows; i++) {
                    printf("%d", max_array[i]);
                    if (i < rows - 1) {
                        printf(" ");
                    }
                }
                printf("\n");
                for (int i = 0; i < cols; i++) {
                    printf("%d", min_array[i]);
                    if (i < cols - 1) {
                        printf(" ");
                    }
                }
                free(max_array);
                free(min_array);
            } else {
                printf("n/a");
                result = 1;
                if (max_array != NULL) free(max_array);
                if (min_array != NULL) free(min_array);
            }
        }
        
        if (mode == 2) {
            free_matrix_1(matrix, rows);
        } else if (mode == 3) {
            free_matrix_2(matrix);
        } else if (mode == 4) {
            free_matrix_3(matrix);
        }
    }
    
    return result;
}

int **allocate_matrix_1(int rows, int cols) {
    int **matrix = (int **)malloc(rows * sizeof(int *));
    if (matrix == NULL) {
        return NULL;
    }
    
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
        if (matrix[i] == NULL) {
            for (int j = 0; j < i; j++) {
                free(matrix[j]);
            }
            free(matrix);
            return NULL;
        }
    }
    return matrix;
}

int **allocate_matrix_2(int rows, int cols) {
    int **matrix = (int **)malloc(rows * sizeof(int *));
    if (matrix == NULL) {
        return NULL;
    }
    
    int *data = (int *)malloc(rows * cols * sizeof(int));
    if (data == NULL) {
        free(matrix);
        return NULL;
    }
    
    for (int i = 0; i < rows; i++) {
        matrix[i] = data + i * cols;
    }
    return matrix;
}

int **allocate_matrix_3(int rows, int cols) {
    int **matrix = (int **)malloc(rows * sizeof(int *) + rows * cols * sizeof(int));
    if (matrix == NULL) {
        return NULL;
    }
    
    int *data = (int *)(matrix + rows);
    for (int i = 0; i < rows; i++) {
        matrix[i] = data + i * cols;
    }
    return matrix;
}

int input_dynamic_matrix(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (scanf("%d", &matrix[i][j]) != 1) {
                return 1;
            }
        }
    }
    return 0;
}

int input_matrix_static(int matrix[MAX_STATIC][MAX_STATIC], int *rows, int *cols) {
    if (scanf("%d %d", rows, cols) != 2 || *rows <= 0 || *cols <= 0) {
        return 1;
    }
    if (*rows > MAX_STATIC || *cols > MAX_STATIC) {
        return 1;
    }
    
    for (int i = 0; i < *rows; i++) {
        for (int j = 0; j < *cols; j++) {
            if (scanf("%d", &matrix[i][j]) != 1) {
                return 1;
            }
        }
    }
    return 0;
}

void output_matrix_static(int matrix[MAX_STATIC][MAX_STATIC], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d", matrix[i][j]);
            if (j < cols - 1) {
                printf(" ");
            }
        }
        if (i < rows - 1) {
            printf("\n");
        }
    }
}

void output_matrix_dynamic(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d", matrix[i][j]);
            if (j < cols - 1) {
                printf(" ");
            }
        }
        if (i < rows - 1) {
            printf("\n");
        }
    }
}

void free_matrix_1(int **matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

void free_matrix_2(int **matrix) {
    if (matrix != NULL) {
        free(matrix[0]);
        free(matrix);
    }
}

void free_matrix_3(int **matrix) {
    free(matrix);
}

void find_max_in_rows_static(int matrix[MAX_STATIC][MAX_STATIC], int rows, int cols, int *max_array) {
    for (int i = 0; i < rows; i++) {
        int max = matrix[i][0];
        for (int j = 1; j < cols; j++) {
            if (matrix[i][j] > max) {
                max = matrix[i][j];
            }
        }
        max_array[i] = max;
    }
}

void find_max_in_rows_dynamic(int **matrix, int rows, int cols, int *max_array) {
    for (int i = 0; i < rows; i++) {
        int max = matrix[i][0];
        for (int j = 1; j < cols; j++) {
            if (matrix[i][j] > max) {
                max = matrix[i][j];
            }
        }
        max_array[i] = max;
    }
}

void find_min_in_cols_static(int matrix[MAX_STATIC][MAX_STATIC], int rows, int cols, int *min_array) {
    for (int j = 0; j < cols; j++) {
        int min = matrix[0][j];
        for (int i = 1; i < rows; i++) {
            if (matrix[i][j] < min) {
                min = matrix[i][j];
            }
        }
        min_array[j] = min;
    }
}

void find_min_in_cols_dynamic(int **matrix, int rows, int cols, int *min_array) {
    for (int j = 0; j < cols; j++) {
        int min = matrix[0][j];
        for (int i = 1; i < rows; i++) {
            if (matrix[i][j] < min) {
                min = matrix[i][j];
            }
        }
        min_array[j] = min;
    }
}
