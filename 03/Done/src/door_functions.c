#include <math.h>
#include <stdio.h>

#define PI 3.14159265358979323846

double verziера_agnesi(double x) {
    return 1.0 / (x * x + 1.0);
}

double lemniscate_bernoulli(double x) {
    double x_squared = x * x;
    double inner = 1.0 + 4.0 * x_squared;
    double outer = sqrt(inner) - x_squared - 1.0;
    double result = -1;
    
    if (outer >= 0) {
        result = sqrt(outer);
    }
    
    return result;
}

double quadratic_hyperbola(double x) {
    double result = -1;
    
    if (fabs(x) >= 1e-10) {
        result = 1.0 / (x * x);
    }
    
    return result;
}

int main() {
    double start = -PI;
    double end = PI;
    int measurements = 42;
    double step = (end - start) / (measurements - 1);
    
    for (int i = 0; i < measurements; i++) {
        double x = start + i * step;
        
        double va = verziера_agnesi(x);
        double lb = lemniscate_bernoulli(x);
        double qh = quadratic_hyperbola(x);
        
        printf("%.7f | ", x);
        printf("%.7f | ", va);
        
        if (lb < 0) {
            printf("-- | ");
        } else {
            printf("%.7f | ", lb);
        }
        
        if (qh == -1) {
            printf("--");
        } else {
            printf("%.7f", qh);
        }
        
        printf("\n");
    }
    
    return 0;
}
