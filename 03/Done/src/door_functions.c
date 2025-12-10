#include <math.h>
#include <stdio.h>

#define PI 3.14159265358979323846

// Верзьера Аньези с единичным диаметром: y = 1 / (x^2 + 1)
double verziера_agnesi(double x) {
    return 1.0 / (x * x + 1.0);
}

// Лемниската Бернулли: y = sqrt(sqrt(1 + 4x^2) - x^2 - 1) для Y > 0
double lemniscate_bernoulli(double x) {
    double x_squared = x * x;
    double inner = 1.0 + 4.0 * x_squared;
    double outer = sqrt(inner) - x_squared - 1.0;
    
    // Функция определена только когда outer >= 0
    if (outer < 0) {
        return -1;  // Не определена
    }
    
    return sqrt(outer);
}

// Квадратичная гипербола: y = 1 / x^2
double quadratic_hyperbola(double x) {
    if (fabs(x) < 1e-10) {
        return -1;  // Не определена в точке x = 0
    }
    return 1.0 / (x * x);
}

int main() {
    double start = -PI;
    double end = PI;
    int measurements = 42;
    double step = (end - start) / (measurements - 1);
    
    for (int i = 0; i < measurements; i++) {
        double x = start + i * step;
        
        // Вычисляем значения функций
        double va = verziера_agnesi(x);
        double lb = lemniscate_bernoulli(x);
        double qh = quadratic_hyperbola(x);
        
        // Выводим x
        printf("%.7f | ", x);
        
        // Выводим Верзьеру Аньези
        printf("%.7f | ", va);
        
        // Выводим лемнискату Бернулли (или "--" если не определена)
        if (lb < 0) {
            printf("-- | ");
        } else {
            printf("%.7f | ", lb);
        }
        
        // Выводим квадратичную гиперболу (или "--" если не определена)
        if (qh == -1) {
            printf("--");
        } else {
            printf("%.7f", qh);
        }
        
        printf("\n");
    }
    
    return 0;
}
