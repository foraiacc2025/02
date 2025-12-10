#include <math.h>
#include <stdio.h>
#include <string.h>

#define WIDTH 80
#define HEIGHT 25
#define PI 3.14159265358979323846

// Верзьера Аньези с единичным диаметром: y = 1 / (x^2 + 1)
double verziera_agnesi(double x) {
    return 1.0 / (x * x + 1.0);
}

// Лемниската Бернулли: y = sqrt(sqrt(1 + 4x^2) - x^2 - 1) для Y > 0
double lemniscate_bernoulli(double x) {
    double x_squared = x * x;
    double inner = 1.0 + 4.0 * x_squared;
    double outer = sqrt(inner) - x_squared - 1.0;
    
    if (outer < 0) {
        return -1;
    }
    
    return sqrt(outer);
}

// Квадратичная гипербола: y = 1 / x^2
double quadratic_hyperbola(double x) {
    if (fabs(x) < 1e-10) {
        return -1;
    }
    return 1.0 / (x * x);
}

int main() {
    char canvas[HEIGHT][WIDTH + 1];
    
    // Инициализация canvas пробелами
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            canvas[i][j] = '.';
        }
        canvas[i][WIDTH] = '\0';
    }
    
    double start = -PI;
    double end = PI;
    double x_range = end - start;
    
    // Найдём минимальное и максимальное значение y для всех функций
    double y_min = 1e10;
    double y_max = -1e10;
    
    for (int col = 0; col < WIDTH; col++) {
        double x = start + (col * x_range) / (WIDTH - 1);
        
        double va = verziera_agnesi(x);
        double lb = lemniscate_bernoulli(x);
        double qh = quadratic_hyperbola(x);
        
        if (va > y_max) y_max = va;
        if (va < y_min) y_min = va;
        
        if (lb >= 0) {
            if (lb > y_max) y_max = lb;
            if (lb < y_min) y_min = lb;
        }
        
        if (qh != -1 && fabs(qh) < 10) {  // Ограничиваем гиперболу для отображения
            if (qh > y_max) y_max = qh;
            if (qh < y_min) y_min = qh;
        }
    }
    
    double y_range = y_max - y_min;
    
    // Отрисовка функций
    for (int col = 0; col < WIDTH; col++) {
        double x = start + (col * x_range) / (WIDTH - 1);
        
        // Верзьера Аньези
        double va = verziera_agnesi(x);
        int row_va = (int)((y_max - va) * (HEIGHT - 1) / y_range);
        if (row_va >= 0 && row_va < HEIGHT) {
            canvas[row_va][col] = '*';
        }
        
        // Лемниската Бернулли
        double lb = lemniscate_bernoulli(x);
        if (lb >= 0) {
            int row_lb = (int)((y_max - lb) * (HEIGHT - 1) / y_range);
            if (row_lb >= 0 && row_lb < HEIGHT) {
                canvas[row_lb][col] = '#';
            }
        }
        
        // Квадратичная гипербола
        double qh = quadratic_hyperbola(x);
        if (qh != -1 && fabs(qh) < 10) {
            int row_qh = (int)((y_max - qh) * (HEIGHT - 1) / y_range);
            if (row_qh >= 0 && row_qh < HEIGHT) {
                canvas[row_qh][col] = '+';
            }
        }
    }
    
    // Вывод canvas
    for (int i = 0; i < HEIGHT; i++) {
        printf("%s\n", canvas[i]);
    }
    
    return 0;
}
