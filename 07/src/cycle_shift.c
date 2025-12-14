#include <stdio.h>
#define NMAX 10

int input(int *a, int *n, int *c);
void output(int *a, int n);
void cycle_shift(int *a, int n, int c);

int main() {
    int n, c, data[NMAX];
    if (input(data, &n, &c) == 0) {
        printf("n/a");
        return 0;
    }
    cycle_shift(data, n, c);
    output(data, n);
    return 0;
}

int input(int *a, int *n, int *c) {
    char ch;
    if (scanf("%d%c", n, &ch) != 2 || *n <= 0 || *n > NMAX || (ch != '\n' && ch != ' ' && ch != '\t')) {
        return 0;
    }
    for (int *p = a; p - a < *n; p++) {
        if (scanf("%d%c", p, &ch) != 2 || (ch != '\n' && ch != ' ' && ch != '\t')) {
            return 0;
        }
    }
    if (scanf("%d%c", c, &ch) != 2 || (ch != '\n' && ch != ' ' && ch != '\t')) {
        return 0;
    }
    return 1;
}

void output(int *a, int n) {
    for (int *p = a; p - a < n; p++) {
        if (p != a) {
            printf(" ");
        }
        printf("%d", *p);
    }
}

void cycle_shift(int *a, int n, int c) {
    if (n > 1) {
        c = c % n;
        if (c < 0) {
            c += n;
        }
        
        for (int shift = 0; shift < c; shift++) {
            int temp = *a;
            for (int *p = a; p - a < n - 1; p++) {
                *p = *(p + 1);
            }
            *(a + n - 1) = temp;
        }
    }
}
