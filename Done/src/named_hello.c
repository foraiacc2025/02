#include <stdio.h>

int main() {
    int name;
    if (scanf("%d", &name) == 1) {
        printf("Hello, %d!", name);
    }
    return 0;
}
