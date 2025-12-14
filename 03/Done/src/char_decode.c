#include <stdio.h>

int hex_to_int(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    if (c >= 'A' && c <= 'F') return c - 'A' + 10;
    if (c >= 'a' && c <= 'f') return c - 'a' + 10;
    return -1;
}

int main(int argc, char *argv[]) {
    if (argc != 2 || (argv[1][0] != '0' && argv[1][0] != '1') || argv[1][1] != '\0') {
        printf("n/a");
        return 0;
    }
    
    int mode = argv[1][0] - '0';
    int ch, first = 1, count = 0;
    
    if (mode == 0) {
        while ((ch = getchar()) != '\n' && ch != EOF) {
            if (ch != ' ') {
                if (!first) printf(" ");
                printf("%02X", (unsigned char)ch);
                first = 0;
                count++;
            }
        }
    } else {
        char h1, h2;
        while ((ch = getchar()) != '\n' && ch != EOF) {
            if (ch == ' ') continue;
            
            h1 = ch;
            ch = getchar();
            if (ch == '\n' || ch == EOF || ch == ' ') {
                printf("n/a");
                return 0;
            }
            h2 = ch;
            
            int v1 = hex_to_int(h1);
            int v2 = hex_to_int(h2);
            if (v1 < 0 || v2 < 0) {
                printf("n/a");
                return 0;
            }
            
            printf("%c", (char)(v1 * 16 + v2));
            count++;
        }
    }
    
    if (count == 0) printf("n/a");
    
    return 0;
}
