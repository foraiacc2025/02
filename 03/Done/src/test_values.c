#include <stdio.h>
#include <math.h>
#define PI 3.14159265358979323846

double verziera_agnesi(double x) { return 1.0 / (x * x + 1.0); }
double lemniscate_bernoulli(double x) {
    double x_squared = x * x;
    double inner = 1.0 + 4.0 * x_squared;
    double outer = sqrt(inner) - x_squared - 1.0;
    if (outer < 0) return -1;
    return sqrt(outer);
}
double quadratic_hyperbola(double x) {
    if (fabs(x) < 1e-10) return -1;
    return 1.0 / (x * x);
}

int main() {
    printf("=== Верзьера Аньези ===\n");
    printf("x=0:    y=%.4f (должно быть ~1)\n", verziera_agnesi(0));
    printf("x=-PI:  y=%.4f\n", verziera_agnesi(-PI));
    printf("x=+PI:  y=%.4f\n\n", verziera_agnesi(PI));
    
    printf("=== Лемниската Бернулли ===\n");
    printf("x=0:    y=%.4f (должно быть 0)\n", lemniscate_bernoulli(0));
    printf("x=-PI:  y=%.4f (может быть не определена)\n", lemniscate_bernoulli(-PI));
    printf("x=+PI:  y=%.4f\n\n", lemniscate_bernoulli(PI));
    
    printf("=== Квадратичная гипербола ===\n");
    printf("x=0:    y=%.4f (не определена)\n", quadratic_hyperbola(0));
    printf("x=1:    y=%.4f (должно быть 1)\n", quadratic_hyperbola(1));
    printf("x=0.1:  y=%.4f (должно быть 100)\n", quadratic_hyperbola(0.1));
    return 0;
}
