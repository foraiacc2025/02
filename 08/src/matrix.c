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
