#include <stdio.h>
#include <stdlib.h>
#include "s21_string.h"

int is_space(char c) {
    return c == ' ' || c == '\t' || c == '\n' || c == '\r';
}

int parse_words(char *text, char words[][101]) {
    int len = s21_strlen(text);
    int word_count = 0;
    int word_start = 0;
    int in_word = 0;
    
    if (len > 0 && text[len - 1] == '\n') {
        text[len - 1] = '\0';
        len--;
    }
    
    for (int i = 0; i <= len; i++) {
        if (i < len && !is_space(text[i])) {
            if (!in_word) {
                word_start = i;
                in_word = 1;
            }
        } else if (in_word) {
            int word_len = i - word_start;
            for (int j = 0; j < word_len; j++) {
                words[word_count][j] = text[word_start + j];
            }
            words[word_count][word_len] = '\0';
            word_count++;
            in_word = 0;
        }
    }
    return word_count;
}

void print_line(char words[][101], int *line_words, int line_word_count, int width, int is_last_line) {
    if (line_word_count == 0) return;
    
    // Calculate total word length
    int total_word_len = 0;
    for (int j = 0; j < line_word_count; j++) {
        total_word_len += s21_strlen(words[line_words[j]]);
    }
    
    // If last line or only one word, don't justify
    if (is_last_line || line_word_count == 1) {
        for (int j = 0; j < line_word_count; j++) {
            printf("%s", words[line_words[j]]);
            if (j < line_word_count - 1) {
                printf(" ");
            }
        }
    } else {
        // Justify text
        int spaces_needed = width - total_word_len;
        int gaps = line_word_count - 1;
        int spaces_per_gap = spaces_needed / gaps;
        int extra_spaces = spaces_needed % gaps;
        
        for (int j = 0; j < line_word_count; j++) {
            printf("%s", words[line_words[j]]);
            if (j < line_word_count - 1) {
                for (int k = 0; k < spaces_per_gap; k++) {
                    printf(" ");
                }
                if (j < extra_spaces) {
                    printf(" ");
                }
            }
        }
    }
}

void split_long_word(const char *word, int word_len, int width, int *is_first_line) {
    int chars_printed = 0;
    
    while (chars_printed < word_len) {
        if (!(*is_first_line) || chars_printed > 0) printf("\n");
        *is_first_line = 0;
        
        int chars_to_print = width - 1;
        if (chars_printed + width - 1 >= word_len) {
            chars_to_print = word_len - chars_printed;
        }
        
        for (int j = 0; j < chars_to_print && chars_printed < word_len; j++) {
            printf("%c", word[chars_printed++]);
        }
        if (chars_printed < word_len) {
            printf("-");
        }
    }
}

void process_long_word(char words[][101], int i, int width, int *line_word_count, 
                       int *current_line_len, int *line_words, int *is_first_line) {
    const char *word = words[i];
    int word_len = s21_strlen(word);
    int chars_printed = 0;
    
    if (*line_word_count > 0) {
        if (!(*is_first_line)) printf("\n");
        *is_first_line = 0;
        print_line(words, line_words, *line_word_count, width, 0);
        printf(" ");
        *current_line_len += 1;
        
        int space_left = width - *current_line_len;
        if (space_left > 1) {
            for (int j = 0; j < space_left - 1 && chars_printed < word_len; j++) {
                printf("%c", word[chars_printed++]);
            }
            printf("-");
        }
        *line_word_count = 0;
        *current_line_len = 0;
    }
    
    split_long_word(word + chars_printed, word_len - chars_printed, width, is_first_line);
}

void format_by_width(int width, char *text) {
    char words[100][101];
    int word_count = parse_words(text, words);
    int current_line_len = 0;
    int line_word_count = 0;
    int line_words[100];
    int is_first_line = 1;
    
    for (int i = 0; i < word_count; i++) {
        int word_len = s21_strlen(words[i]);
        int space_needed = word_len;
        if (line_word_count > 0) {
            space_needed += 1;
        }
        
        if (current_line_len + space_needed <= width) {
            line_words[line_word_count++] = i;
            current_line_len += space_needed;
        } else if (word_len <= width) {
            if (line_word_count > 0) {
                if (!is_first_line) printf("\n");
                is_first_line = 0;
                print_line(words, line_words, line_word_count, width, 0);
                line_word_count = 0;
                current_line_len = 0;
            }
            line_words[0] = i;
            line_word_count = 1;
            current_line_len = word_len;
        } else {
            process_long_word(words, i, width, &line_word_count, 
                            &current_line_len, line_words, &is_first_line);
        }
    }
    
    if (line_word_count > 0) {
        if (!is_first_line) printf("\n");
        print_line(words, line_words, line_word_count, width, 1);
    }
}

int main(int argc, char *argv[]) {
    int result = 0;
    int width;
    char c;
    char text[101];
    
    if (argc != 2 || s21_strcmp(argv[1], "-w") != 0) {
        printf("n/a\n");
        result = 1;
    } else if (scanf("%d", &width) != 1 || width <= 0) {
        printf("n/a\n");
        result = 1;
    } else {
        scanf("%c", &c);
        if (fgets(text, 101, stdin) == NULL) {
            printf("n/a\n");
            result = 1;
        } else {
            format_by_width(width, text);
        }
    }
    
    return result;
}
