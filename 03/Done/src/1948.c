#include <stdio.h>

// Функция для взятия остатка через вычитание (проверка делимости)
// Возвращает 1 если a делится на b, иначе 0
int is_divisible(int a, int b) {
    if (b == 0) return 0;
    
    int abs_a = (a < 0) ? -a : a;
    int abs_b = (b < 0) ? -b : b;
    
    // Вычитаем b из a пока можем
    while (abs_a >= abs_b) {
        abs_a = abs_a - abs_b;
    }
    
    // Если остаток 0, то делится нацело
    return (abs_a == 0) ? 1 : 0;
}

// Функция для деления через вычитание
int divide_by_subtraction(int a, int b) {
    if (b == 0) return 0;
    
    int abs_a = (a < 0) ? -a : a;
    int abs_b = (b < 0) ? -b : b;
    int result = 0;
    
    while (abs_a >= abs_b) {
        abs_a = abs_a - abs_b;
        result = result + 1;
    }
    
    return result;
}

// Функция для поиска наибольшего простого делителя
int largest_prime_divisor(int n) {
    if (n == 0) return 0;
    
    int abs_n = (n < 0) ? -n : n;
    
    if (abs_n == 1) return 1;
    
    int largest = 1;
    
    // Сначала делим на 2 пока можем
    while (is_divisible(abs_n, 2)) {
        largest = 2;
        abs_n = divide_by_subtraction(abs_n, 2);
    }
    
    // Теперь проверяем нечётные делители от 3 и выше
    for (int i = 3; i <= abs_n; i = i + 2) {
        // Пока i делит abs_n нацело, делим
        while (is_divisible(abs_n, i)) {
            largest = i;
            abs_n = divide_by_subtraction(abs_n, i);
        }
    }
    
    return largest;
}

int main() {
    int a;
    int valid_input = (scanf("%d", &a) == 1);
    
    if (valid_input && a != 0) {
        int result = largest_prime_divisor(a);
        printf("%d", result);
    } else {
        printf("n/a");
    }
    
    return 0;
}
