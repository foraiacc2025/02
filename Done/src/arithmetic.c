#include <stdio.h>

int main() {
    int a, b;
    int valid_input = (scanf("%d %d", &a, &b) == 2);
    
    if (valid_input) {
        printf("%d %d %d ", a + b, a - b, a * b);
        
        if (b == 0) {
            printf("n/a");
        } else {
            printf("%d", a / b);
        }
    } else {
        printf("n/a");
    }
    
    return 0;
}