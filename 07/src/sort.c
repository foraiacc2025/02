#include <stdio.h>
#define NMAX 10

int input(int *a, int n);
void output(int *a, int n);
void sort(int *a, int n);

int main() {
    int data[NMAX];
    if (input(data, NMAX) == 0) {
        printf("n/a");
        return 0;
    }
    sort(data, NMAX);
    output(data, NMAX);
    return 0;
}

int input(int *a, int n) {
    for (int *p = a; p - a < n; p++) {
        if (scanf("%d", p) != 1) {
            return 0;
        }
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

void sort(int *a, int n) {
    for (int *i = a; i - a < n - 1; i++) {
        for (int *j = a; j - a < n - 1 - (i - a); j++) {
            if (*j > *(j + 1)) {
                int temp = *j;
                *j = *(j + 1);
                *(j + 1) = temp;
            }
        }
    }
}
