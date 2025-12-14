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
    char c;
    
    if (scanf("%d%c", &n, &c) != 2 || c != '\n' || n < 0) {
        printf("n/a");
               
    } else {
        printf("%d", fibonacci(n));
    }
        return 0;
}
