#include <stdio.h>

int find_max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int a, b;
    int valid_input = (scanf("%d %d", &a, &b) == 2);
    
    if (valid_input) {
        printf("%d", find_max(a, b));
    } else {
        printf("n/a");
    }
    
    return 0;
}
