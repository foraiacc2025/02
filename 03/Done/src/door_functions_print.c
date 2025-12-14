#include <math.h>
#include <stdio.h>

#define WIDTH 42
#define HEIGHT 21
#define PI 3.14159265358979323846

double verziera_agnesi(double x) {
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

void compute_values(double (*func)(double), double values[WIDTH]) {
    for (int i = 0; i < WIDTH; i++) {
        double x = -PI + (i * 2 * PI) / (WIDTH - 1);
        values[i] = func(x);
    }
}

void find_range(double values[WIDTH], double *min, double *max) {
    *min = 1e10;
    *max = -1e10;
    
    for (int i = 0; i < WIDTH; i++) {
        if (values[i] >= 0) {
            if (values[i] > *max) *max = values[i];
            if (values[i] < *min) *min = values[i];
        }
    }
    
    if (*min > *max) {
        *min = 0;
        *max = 1;
    }
}

void draw_graph(double values[WIDTH], double y_min, double y_max) {
    double y_range = y_max - y_min;
    
    for (int row = 0; row < HEIGHT; row++) {
        for (int col = 0; col < WIDTH; col++) {
            char ch = '.';
            if (values[col] >= 0) {
                int target_row = (int)((y_max - values[col]) * (HEIGHT - 1) / y_range);
                if (target_row == row) {
                    ch = '*';
                }
            }
            printf("%c", ch);
        }
        printf("\n");
    }
}

void plot_function(double (*func)(double)) {
    double values[WIDTH];
    double y_min;
    double y_max;
    
    compute_values(func, values);
    find_range(values, &y_min, &y_max);
    draw_graph(values, y_min, y_max);
}

int main() {
    plot_function(verziera_agnesi);
    plot_function(lemniscate_bernoulli);
    plot_function(quadratic_hyperbola);
    
    return 0;
}
