/*
    Search module for the desired value from data array.

    Returned value must be:
        - "even"
        - ">= mean"
        - "<= mean + 3 * sqrt(variance)"
        - "!= 0"

        OR

        0
*/

#include <stdio.h>
#define NMAX 30

int input(int *a, int *n);
double mean(int *a, int n);
double variance(int *a, int n);
double my_sqrt(double x);
int search(int *a, int n);

int main() {
    int n, data[NMAX];
    if (input(data, &n) == 0) {
        printf("n/a");
        return 0;
    }
    printf("%d", search(data, n));
    return 0;
}

int input(int *a, int *n) {
    char c;
    if (scanf("%d%c", n, &c) != 2 || *n <= 0 || *n > NMAX || (c != '\n' && c != ' ' && c != '\t')) {
        return 0;
    }
    for (int *p = a; p - a < *n; p++) {
        if (scanf("%d%c", p, &c) != 2 || (c != '\n' && c != ' ' && c != '\t')) {
            return 0;
        }
    }
    return 1;
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

double my_sqrt(double x) {
    double result = 0.0;
    
    if (x > 0) {
        double guess = x / 2.0;
        double epsilon = 0.00001;
        double diff = epsilon + 1;
        
        while (diff >= epsilon || diff <= -epsilon) {
            double new_guess = (guess + x / guess) / 2.0;
            diff = new_guess - guess;
            guess = new_guess;
        }
        result = guess;
    }
    
    return result;
}

int search(int *a, int n) {
    double mean_val = mean(a, n);
    double var = variance(a, n);
    double std_dev = my_sqrt(var);
    double upper_bound = mean_val + 3 * std_dev;
    
    for (int *p = a; p - a < n; p++) {
        if (*p != 0 && 
            *p % 2 == 0 && 
            *p >= mean_val && 
            *p <= upper_bound) {
            return *p;
        }
    }
    
    return 0;
}



