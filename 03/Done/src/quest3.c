#include <stdio.h>

// Рекурсивная функция для вычисления n-ого числа Фибоначчи
int fibonacci(int n) {
    int result = -1;
    
    if (n >= 0) {
        if (n == 0) {
            result = 0;
        } else if (n == 1) {
            result = 1;
        } else {
            result = fibonacci(n - 1) + fibonacci(n - 2);
        }
    }
    
    return result;
}

int main() {
    int n;
    int valid_input = (scanf("%d", &n) == 1);
    
    if (valid_input && n >= 0) {
        int result = fibonacci(n);
        printf("%d", result);
    } else {
        printf("n/a");
    }
    
    return 0;
}
