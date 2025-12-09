#include <stdio.h>

int main() {
    double x, y;
    int valid_input = (scanf("%lf %lf", &x, &y) == 2);
    
    if (valid_input) {
        if (x * x + y * y < 25) {
            printf("GOTCHA");
        } else {
            printf("MISS");
        }
    } else {
        printf("n/a");
    }
    
    return 0;
}
