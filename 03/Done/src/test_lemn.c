#include <stdio.h>
#include <math.h>
#define PI 3.14159265358979323846

double lemniscate_bernoulli(double x) {
    double x_squared = x * x;
    double inner = 1.0 + 4.0 * x_squared;
    double outer = sqrt(inner) - x_squared - 1.0;
    printf("x=%.2f: inner=%.4f, outer=%.4f", x, inner, outer);
    if (outer < 0) {
        printf(" -> не определена\n");
        return -1;
    }
    double result = sqrt(outer);
    printf(" -> y=%.4f\n", result);
    return result;
}

int main() {
    printf("Проверка лемнискаты:\n");
    lemniscate_bernoulli(0.0);
    lemniscate_bernoulli(0.3);
    lemniscate_bernoulli(0.6);
    lemniscate_bernoulli(1.0);
    lemniscate_bernoulli(PI);
    return 0;
}
