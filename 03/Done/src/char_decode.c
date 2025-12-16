#include <stdio.h>

int hex_to_int(char c) {
    int result = -1;
    if (c >= '0' && c <= '9') {
        result = c - '0';
    } else if (c >= 'A' && c <= 'F') {
        result = c - 'A' + 10;
    } else if (c >= 'a' && c <= 'f') {
        result = c - 'a' + 10;
    }
    return result;
}

void encode_mode(int *count) {
    int ch, first = 1;
    while ((ch = getchar()) != '\n' && ch != EOF) {
        if (ch != ' ') {
            if (!first) printf(" ");
            printf("%02X", (unsigned char)ch);
            first = 0;
            (*count)++;
        }
    }
}

int decode_mode(int *count) {
    int ch, error = 0;
    while ((ch = getchar()) != '\n' && ch != EOF && !error) {
        if (ch != ' ') {
            int h1 = ch;
            ch = getchar();
            if (ch == '\n' || ch == EOF || ch == ' ') {
                error = 1;
            } else {
                int v1 = hex_to_int(h1);
                int v2 = hex_to_int(ch);
                if (v1 < 0 || v2 < 0) {
                    error = 1;
                } else {
                    printf("%c", (char)(v1 * 16 + v2));
                    (*count)++;
                }
            }
        }
    }
    return error;
}

int main(int argc, char *argv[]) {
    int count = 0;
    
    if (argc != 2 || (argv[1][0] != '0' && argv[1][0] != '1') || argv[1][1] != '\0') {
        printf("n/a");
        return 0;
    }
    
    int mode = argv[1][0] - '0';
    int error = 0;
    
    if (mode == 0) {
        encode_mode(&count);
    } else {
        error = decode_mode(&count);
    }
    
    if (error || count == 0) {
        printf("n/a");
    }
    
    return 0;
}
