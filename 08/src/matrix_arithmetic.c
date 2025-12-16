#include <stdio.h>
#include <stdlib.h>

int **allocate_matrix(int rows, int cols);
void free_matrix(int **matrix, int rows);
int input_matrix(int **matrix, int rows, int cols);
void output_matrix(int **matrix, int rows, int cols);
int add_matrices(int **m1, int **m2, int **result, int rows, int cols);
int multiply_matrices(int **m1, int **m2, int **result, int r1, int c1, int c2);
int transpose_matrix(int **matrix, int **result, int rows, int cols);

int main() {
    int operation = 0;
    int result_code = 0;
    
    if (scanf("%d", &operation) != 1 || operation < 1 || operation > 3) {
        printf("n/a");
        return 1;
    }
    
    if (operation == 1) {
        int rows = 0;
        int cols = 0;
        if (scanf("%d %d", &rows, &cols) != 2 || rows <= 0 || cols <= 0) {
            printf("n/a");
            return 1;
        }
        
        int **m1 = allocate_matrix(rows, cols);
        if (m1 == NULL) {
            printf("n/a");
            return 1;
        }
        
        if (input_matrix(m1, rows, cols)) {
            printf("n/a");
            free_matrix(m1, rows);
            return 1;
        }
        
        int rows2 = 0;
        int cols2 = 0;
        if (scanf("%d %d", &rows2, &cols2) != 2 || rows2 != rows || cols2 != cols) {
            printf("n/a");
            free_matrix(m1, rows);
            return 1;
        }
        
        int **m2 = allocate_matrix(rows, cols);
        int **result = allocate_matrix(rows, cols);
        
        if (m2 == NULL || result == NULL) {
            printf("n/a");
            free_matrix(m1, rows);
            if (m2 != NULL) free_matrix(m2, rows);
            if (result != NULL) free_matrix(result, rows);
            return 1;
        }
        
        if (input_matrix(m2, rows, cols)) {
            printf("n/a");
            result_code = 1;
        } else {
            if (add_matrices(m1, m2, result, rows, cols)) {
                printf("n/a");
                result_code = 1;
            } else {
                output_matrix(result, rows, cols);
            }
        }
        
        free_matrix(m1, rows);
        free_matrix(m2, rows);
        free_matrix(result, rows);
    } else if (operation == 2) {
        int r1 = 0;
        int c1 = 0;
        if (scanf("%d %d", &r1, &c1) != 2 || r1 <= 0 || c1 <= 0) {
            printf("n/a");
            return 1;
        }
        
        int **m1 = allocate_matrix(r1, c1);
        if (m1 == NULL) {
            printf("n/a");
            return 1;
        }
        
        if (input_matrix(m1, r1, c1)) {
            printf("n/a");
            free_matrix(m1, r1);
            return 1;
        }
        
        int r2 = 0;
        int c2 = 0;
        if (scanf("%d %d", &r2, &c2) != 2 || r2 <= 0 || c2 <= 0) {
            printf("n/a");
            free_matrix(m1, r1);
            return 1;
        }
        
        if (c1 != r2) {
            printf("n/a");
            free_matrix(m1, r1);
            return 1;
        }
        
        int **m2 = allocate_matrix(r2, c2);
        int **result = allocate_matrix(r1, c2);
        
        if (m2 == NULL || result == NULL) {
            printf("n/a");
            free_matrix(m1, r1);
            if (m2 != NULL) free_matrix(m2, r2);
            if (result != NULL) free_matrix(result, r1);
            return 1;
        }
        
        if (input_matrix(m2, r2, c2)) {
            printf("n/a");
            result_code = 1;
        } else {
            if (multiply_matrices(m1, m2, result, r1, c1, c2)) {
                printf("n/a");
                result_code = 1;
            } else {
                output_matrix(result, r1, c2);
            }
        }
        
        free_matrix(m1, r1);
        free_matrix(m2, r2);
        free_matrix(result, r1);
    } else if (operation == 3) {
        int rows = 0;
        int cols = 0;
        if (scanf("%d %d", &rows, &cols) != 2 || rows <= 0 || cols <= 0) {
            printf("n/a");
            return 1;
        }
        
        int **matrix = allocate_matrix(rows, cols);
        int **result = allocate_matrix(cols, rows);
        
        if (matrix == NULL || result == NULL) {
            printf("n/a");
            if (matrix != NULL) free_matrix(matrix, rows);
            if (result != NULL) free_matrix(result, cols);
            return 1;
        }
        
        if (input_matrix(matrix, rows, cols)) {
            printf("n/a");
            result_code = 1;
        } else {
            if (transpose_matrix(matrix, result, rows, cols)) {
                printf("n/a");
                result_code = 1;
            } else {
                output_matrix(result, cols, rows);
            }
        }
        
        free_matrix(matrix, rows);
        free_matrix(result, cols);
    }
    
    return result_code;
}

int **allocate_matrix(int rows, int cols) {
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

void free_matrix(int **matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

int input_matrix(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (scanf("%d", &matrix[i][j]) != 1) {
                return 1;
            }
        }
    }
    return 0;
}

void output_matrix(int **matrix, int rows, int cols) {
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

int add_matrices(int **m1, int **m2, int **result, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = m1[i][j] + m2[i][j];
        }
    }
    return 0;
}

int multiply_matrices(int **m1, int **m2, int **result, int r1, int c1, int c2) {
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                result[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
    return 0;
}

int transpose_matrix(int **matrix, int **result, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
    return 0;
}


