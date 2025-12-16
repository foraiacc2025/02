#include <stdio.h>
#include <stdlib.h>
#include "../data_libs/data_io.h"
#include "data_process.h"

int main() {
    int n;
    scanf("%d", &n);
    
    if (n <= 0) {
        printf("n/a\n");
        return 1;
    }
    
    double *data = (double *)malloc(n * sizeof(double));
    if (data == NULL) {
        printf("n/a\n");
        return 1;
    }

    input(data, n);

    if (normalization(data, n))
        output(data, n);
    else
        printf("ERROR\n");
    
    free(data);
    return 0;
}
