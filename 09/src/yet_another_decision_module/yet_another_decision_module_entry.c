#include <stdio.h>
#include <stdlib.h>
#include "../data_libs/data_io.h"
#include "decision.h"

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
    
    if (make_decision(data, n))
        printf("YES\n"); 
    else
        printf("NO\n");
    
    free(data);
    return 0;
}
