#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void invert_matrix(double **matrix, double **result, int n, int m);
void input(double **matrix, int *n, int *m);
void output(double **matrix, int n, int m);
double **allocate_matrix(int n, int m);
void free_matrix(double **matrix, int n);
double det(double **matrix, int n);
double **get_minor(double **matrix, int n, int row, int col);

int main() {
    int n = 0;
    int m = 0;
    
    if (scanf("%d %d", &n, &m) != 2 || n <= 0 || m <= 0 || n != m) {
        printf("n/a");
        return 1;
    }
    
    double **matrix = allocate_matrix(n, m);
    double **result = allocate_matrix(n, m);
    
    if (matrix == NULL || result == NULL) {
        printf("n/a");
        if (matrix != NULL) free_matrix(matrix, n);
        if (result != NULL) free_matrix(result, n);
        return 1;
    }
    
    input(matrix, &n, &m);
    
    double det_value = det(matrix, n);
    if (fabs(det_value) < 1e-10) {
        printf("n/a");
        free_matrix(matrix, n);
        free_matrix(result, n);
        return 1;
    }
    
    invert_matrix(matrix, result, n, m);
    output(result, n, m);
    
    free_matrix(matrix, n);
    free_matrix(result, n);
    return 0;
}

double **allocate_matrix(int n, int m) {
    double **matrix = (double **)malloc(n * sizeof(double *));
    if (matrix == NULL) {
        return NULL;
    }
    
    for (int i = 0; i < n; i++) {
        matrix[i] = (double *)malloc(m * sizeof(double));
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

void free_matrix(double **matrix, int n) {
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

void input(double **matrix, int *n, int *m) {
    for (int i = 0; i < *n; i++) {
        for (int j = 0; j < *m; j++) {
            scanf("%lf", &matrix[i][j]);
        }
    }
}

void output(double **matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%.6f", matrix[i][j]);
            if (j < m - 1) {
                printf(" ");
            }
        }
        if (i < n - 1) {
            printf("\n");
        }
    }
}

double **get_minor(double **matrix, int n, int row, int col) {
    double **minor = allocate_matrix(n - 1, n - 1);
    if (minor == NULL) {
        return NULL;
    }
    
    int mi = 0;
    for (int i = 0; i < n; i++) {
        if (i == row) continue;
        int mj = 0;
        for (int j = 0; j < n; j++) {
            if (j == col) continue;
            minor[mi][mj] = matrix[i][j];
            mj++;
        }
        mi++;
    }
    return minor;
}

double det(double **matrix, int n) {
    if (n == 1) {
        return matrix[0][0];
    }
    
    if (n == 2) {
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    }
    
    double result = 0.0;
    for (int j = 0; j < n; j++) {
        double **minor = get_minor(matrix, n, 0, j);
        if (minor != NULL) {
            double sign = (j % 2 == 0) ? 1.0 : -1.0;
            result += sign * matrix[0][j] * det(minor, n - 1);
            free_matrix(minor, n - 1);
        }
    }
    
    return result;
}

void invert_matrix(double **matrix, double **result, int n, int m) {
    (void)m;
    double det_value = det(matrix, n);
    
    double **cofactors = allocate_matrix(n, n);
    if (cofactors == NULL) {
        return;
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            double **minor = get_minor(matrix, n, i, j);
            if (minor != NULL) {
                double sign = ((i + j) % 2 == 0) ? 1.0 : -1.0;
                cofactors[i][j] = sign * det(minor, n - 1);
                free_matrix(minor, n - 1);
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = cofactors[j][i] / det_value;
        }
    }
    
    free_matrix(cofactors, n);
}
