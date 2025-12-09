#include <math.h>
#include <stdio.h>

int main() {
    double x;
    int valid_input = (scanf("%lf", &x) == 1);
    int valid_value = valid_input && (fabs(x) >= 1e-9);
    
    if (valid_value) {
        double term1 = 7e-3 * pow(x, 4);
        double term2 = ((22.8 * pow(x, 1.0 / 3.0) - 1e3) * x + 3) / (x * x / 2);
        double term3 = x * pow(10 + x, 2 / x);
        double y = term1 + term2 - term3 - 1.01;
        printf("%.1f", y);
    } else {
        printf("n/a");
    }
    
    return 0;
}
