#include <stdio.h>

#define LEN 100

void sum(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length);
void sub(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length);
int input(int *buff, int *len);
void output(int *buff, int len);
int compare(int *buff1, int len1, int *buff2, int len2);

/*
    Беззнаковая целочисленная длинная арифметика
    с использованием массивов.
    Ввод: 
     * 2 длинных числа в виде массивов до 100 элементов.
     * В один элемент массива нельзя вводить число > 9.
    Вывод: 
     * Результат сложения и разности чисел-массивов.
    Пример:
     * 1 9 4 4 6 7 4 4 0 7 3 7 0 9 5 5 1 6 1
       2 9

       1 9 4 4 6 7 4 4 0 7 3 7 0 9 5 5 1 9 0
       1 9 4 4 6 7 4 4 0 7 3 7 0 9 5 5 1 3 2
*/
int main() {
    int buff1[LEN], buff2[LEN];
    int len1, len2;
    
    if (input(buff1, &len1) == 0 || input(buff2, &len2) == 0) {
        printf("n/a");
        return 0;
    }
    
    int result_sum[LEN + 1];
    int result_sub[LEN];
    int len_sum, len_sub;
    
    sum(buff1, len1, buff2, len2, result_sum, &len_sum);
    output(result_sum, len_sum);
    printf("\n");
    
    sub(buff1, len1, buff2, len2, result_sub, &len_sub);
    if (len_sub == -1) {
        printf("n/a");
    } else {
        output(result_sub, len_sub);
    }
    
    return 0;
}

int input(int *buff, int *len) {
    char c = ' ';
    *len = 0;
    int error = 0;
    
    while (c != '\n' && *len < LEN && error == 0) {
        if (scanf("%d%c", &buff[*len], &c) != 2) {
            error = 1;
        } else if (buff[*len] < 0 || buff[*len] > 9) {
            error = 1;
        } else {
            (*len)++;
        }
    }
    
    return (error == 0 && *len > 0) ? 1 : 0;
}

void output(int *buff, int len) {
    for (int i = 0; i < len; i++) {
        if (i > 0) {
            printf(" ");
        }
        printf("%d", buff[i]);
    }
}

int compare(int *buff1, int len1, int *buff2, int len2) {
    int result = 0;
    
    if (len1 > len2) {
        result = 1;
    } else if (len1 < len2) {
        result = -1;
    } else {
        int i = 0;
        while (i < len1 && result == 0) {
            if (buff1[i] > buff2[i]) {
                result = 1;
            } else if (buff1[i] < buff2[i]) {
                result = -1;
            }
            i++;
        }
    }
    
    return result;
}

void sum(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length) {
    int carry = 0;
    int max_len = (len1 > len2) ? len1 : len2;
    *result_length = 0;
    
    for (int i = 0; i < max_len || carry; i++) {
        int digit1 = (len1 - 1 - i >= 0) ? buff1[len1 - 1 - i] : 0;
        int digit2 = (len2 - 1 - i >= 0) ? buff2[len2 - 1 - i] : 0;
        
        int sum_digit = digit1 + digit2 + carry;
        carry = sum_digit / 10;
        result[i] = sum_digit % 10;
        (*result_length)++;
    }
    
    // Переворачиваем результат
    for (int i = 0; i < *result_length / 2; i++) {
        int temp = result[i];
        result[i] = result[*result_length - 1 - i];
        result[*result_length - 1 - i] = temp;
    }
}

void sub(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length) {
    if (compare(buff1, len1, buff2, len2) < 0) {
        *result_length = -1;
        return;
    }
    
    int borrow = 0;
    *result_length = 0;
    
    for (int i = 0; i < len1; i++) {
        int digit1 = buff1[len1 - 1 - i];
        int digit2 = (len2 - 1 - i >= 0) ? buff2[len2 - 1 - i] : 0;
        
        int diff = digit1 - digit2 - borrow;
        
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        
        result[i] = diff;
        (*result_length)++;
    }
    
    // Убираем ведущие нули
    while (*result_length > 1 && result[*result_length - 1] == 0) {
        (*result_length)--;
    }
    
    // Переворачиваем результат
    for (int i = 0; i < *result_length / 2; i++) {
        int temp = result[i];
        result[i] = result[*result_length - 1 - i];
        result[*result_length - 1 - i] = temp;
    }
}
