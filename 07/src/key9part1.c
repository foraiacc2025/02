/*------------------------------------
	Здравствуй, человек!
	Чтобы получить ключ, 
	поработай с комментариями.
-------------------------------------*/

#include <stdio.h>
#define NMAX 10

void input(int *buffer, int *length);
void output(int *buffer, int length);
int sum_numbers(int *buffer, int length);
int find_numbers(int* buffer, int length, int number, int* numbers);

/*------------------------------------
	Функция получает массив данных 
	через stdin.
	Выдает в stdout особую сумму
	и сформированный массив 
	специальных элементов
	(выбранных с помощью найденной суммы):
	это и будет частью ключа.
-------------------------------------*/
int main() {
    int n, buffer[NMAX];
    input(buffer, &n);
    
    int sum = sum_numbers(buffer, n);
    
    if (sum == 0) {
        printf("n/a");
        return 0;
    }
    
    int numbers[NMAX];
    int count = find_numbers(buffer, n, sum, numbers);
    
    if (count == 0) {
        printf("n/a");
        return 0;
    }
    
    printf("%d\n", sum);
    output(numbers, count);
    
    return 0;
}

void input(int *buffer, int *length) {
    scanf("%d", length);
    for (int *p = buffer; p - buffer < *length; p++) {
        scanf("%d", p);
    }
}

void output(int *buffer, int length) {
    for (int *p = buffer; p - buffer < length; p++) {
        if (p != buffer) {
            printf(" ");
        }
        printf("%d", *p);
    }
}

/*------------------------------------
	Функция должна находить
	сумму четных элементов 
	с 0-й позиции.
-------------------------------------*/
int sum_numbers(int *buffer, int length) {
    int sum = 0;
    
    for (int *p = buffer; p - buffer < length; p++) {
        if (*p % 2 == 0 && *p != 0) {
            sum = sum + *p;
        }
    }
    
    return sum;
}

/*------------------------------------
	Функция должна находить
	все элементы, на которые нацело
	делится переданное число, и
	записывать их в выходной массив.
-------------------------------------*/
int find_numbers(int* buffer, int length, int number, int* numbers) {
    int count = 0;
    
    for (int *p = buffer; p - buffer < length; p++) {
        if (*p != 0 && number % *p == 0) {
            numbers[count] = *p;
            count++;
        }
    }
    
    return count;
}
