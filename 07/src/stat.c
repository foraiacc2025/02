#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
int max(int *a, int n);
int min(int *a, int n);
double mean(int *a, int n);
double variance(int *a, int n);

void output_result(int max_v,
                   int min_v,
                   double mean_v,
                   double variance_v);

int main() {
    int n, data[NMAX];
    if (input(data, &n) == 0) {
        printf("n/a");
        return 0;
    }
    output(data, n);
    printf("\n");
    output_result(max(data, n),
                  min(data, n),
                  mean(data, n),
                  variance(data, n));

    return 0;
}

int input(int *a, int *n) {
    if (scanf("%d", n) != 1 || *n <= 0 || *n > NMAX) {
        return 0;
    }
    for (int *p = a; p - a < *n; p++) {
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

int max(int *a, int n) {
    int max_val = *a;
    for (int *p = a + 1; p - a < n; p++) {
        if (*p > max_val) {
            max_val = *p;
        }
    }
    return max_val;
}

int min(int *a, int n) {
    int min_val = *a;
    for (int *p = a + 1; p - a < n; p++) {
        if (*p < min_val) {
            min_val = *p;
        }
    }
    return min_val;
}

double mean(int *a, int n) {
    double sum = 0.0;
    for (int *p = a; p - a < n; p++) {
        sum += *p;
    }
    return sum / n;
}

double variance(int *a, int n) {
    double mean_val = mean(a, n);
    double sum = 0.0;
    for (int *p = a; p - a < n; p++) {
        double diff = *p - mean_val;
        sum += diff * diff;
    }
    return sum / n;
}

void output_result(int max_v,
                   int min_v,
                   double mean_v,
                   double variance_v) {
    printf("%d %d %f %f", max_v, min_v, mean_v, variance_v);
}


