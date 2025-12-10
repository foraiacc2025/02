#include <stdio.h>

void encode_char(char c) { printf("%02X", (unsigned char)c); }

int hex_to_int(char hex) {
    int result = -1;
    if (hex >= '0' && hex <= '9') {
        result = hex - '0';
    } else if (hex >= 'A' && hex <= 'F') {
        result = hex - 'A' + 10;
    } else if (hex >= 'a' && hex <= 'f') {
        result = hex - 'a' + 10;
    }
    return result;
}

int decode_hex(char hex1, char hex2, char *result) {
    int val1 = hex_to_int(hex1);
    int val2 = hex_to_int(hex2);
    int success = 0;
    
    if (val1 >= 0 && val2 >= 0) {
        *result = (char)(val1 * 16 + val2);
        success = 1;
    }
    
    return success;
}

int validate_encode_input(char *input, int pos) {
    int valid = 1;
    int char_count = 0;
    int i = 0;
    
    while (i < pos && valid) {
        if (input[i] != ' ') {
            if (i + 1 < pos && input[i + 1] != ' ') {
                valid = 0;
            }
            char_count++;
        }
        i++;
    }
    
    if (char_count == 0) {
        valid = 0;
    }
    
    return valid;
}

void encode_mode() {
    char input[1000];
    int pos = 0;
    int ch = getchar();
    
    while (ch != '\n' && ch != EOF && pos < 999) {
        input[pos++] = (char)ch;
        ch = getchar();
    }
    
    if (validate_encode_input(input, pos)) {
        int first = 1;
        for (int i = 0; i < pos; i++) {
            if (input[i] != ' ') {
                if (!first) printf(" ");
                encode_char(input[i]);
                first = 0;
            }
        }
    } else {
        printf("n/a");
    }
}

int decode_mode() {
    char buffer[3];
    int buf_pos = 0;
    int count = 0;
    int first = 1;
    int error = 0;
    int ch = getchar();
    
    while ((ch != '\n' && ch != EOF) && !error) {
        if (ch == ' ') {
            if (buf_pos == 2) {
                char result;
                if (!first) printf(" ");
                if (decode_hex(buffer[0], buffer[1], &result)) {
                    printf("%c", result);
                    first = 0;
                    count++;
                } else {
                    error = 1;
                }
                buf_pos = 0;
            } else if (buf_pos != 0) {
                error = 1;
            }
        } else {
            if (buf_pos < 2) {
                buffer[buf_pos++] = (char)ch;
            } else {
                error = 1;
            }
        }
        ch = getchar();
    }
    
    if (!error && buf_pos == 2) {
        char result;
        if (!first) printf(" ");
        if (decode_hex(buffer[0], buffer[1], &result)) {
            printf("%c", result);
            count++;
        } else {
            error = 1;
        }
    } else if (!error && buf_pos != 0) {
        error = 1;
    }
    
    if (error || count == 0) {
        printf("n/a");
    }
    
    return 0;
}

int main(int argc, char *argv[]) {
    int valid_args = (argc == 2 && (argv[1][0] == '0' || argv[1][0] == '1') && argv[1][1] == '\0');
    
    if (valid_args) {
        int mode = argv[1][0] - '0';
        if (mode == 0) {
            encode_mode();
        } else {
            decode_mode();
        }
    } else {
        printf("n/a");
    }
    
    return 0;
}
