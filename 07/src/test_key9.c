#include <stdio.h>
#define LEN 100

int input(int *buff, int *len);
void output(int *buff, int len);
void sum(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length);
void sub(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length);
int compare(int *buff1, int len1, int *buff2, int len2);

int main() {
    int buff1[LEN], buff2[LEN];
    int len1, len2;
    
    if (input(buff1, &len1) == 0 || input(buff2, &len2) == 0) {
        printf("n/a\n");
        return 0;
    }
    
    int result_sum[LEN + 1];
    int result_sub[LEN];
    int len_sum, len_sub;
    
    sum(buff1, len1, buff2, len2, result_sum, &len_sum);
    output(result_sum, len_sum);
    printf("\n");
    fprintf(stderr, "After sum\n");
    
    sub(buff1, len1, buff2, len2, result_sub, &len_sub);
    fprintf(stderr, "After sub, len_sub=%d\n", len_sub);
    if (len_sub == -1) {
        printf("n/a");
    } else {
        output(result_sub, len_sub);
    }
    
    return 0;
}
