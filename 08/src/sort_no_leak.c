#include <stdio.h>
#include <stdlib.h>

int input(int **data, int *n) {
    if (scanf("%d", n) != 1 || *n <= 0) {
        return 0;
    }
    
    *data = (int *)malloc(*n * sizeof(int));
    if (*data == NULL) {
        return 0;
    }
    
    for (int i = 0; i < *n; i++) {
        if (scanf("%d", &(*data)[i]) != 1) {
            free(*data);
            return 0;
        }
    }
    
    return 1;
}

void sort(int *data, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (data[j] > data[j + 1]) {
                int temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
}

void output(int *data, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d", data[i]);
        if (i < n - 1) {
            printf(" ");
        }
    }
}

int main() {
    int *data = NULL;
    int n = 0;
    int result = 0;
    
    if (input(&data, &n)) {
        sort(data, n);
        output(data, n);
        free(data);
    } else {
        printf("n/a");
        result = 1;
    }
    
    return result;
}
