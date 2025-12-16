#include <stdio.h>
#include <stdlib.h>
#include "s21_string.h"

void s21_strlen_test() {
    printf("=== s21_strlen_test ===\n");
    
    // Test 1: Normal string
    const char *test1 = "Hello";
    size_t result1 = s21_strlen(test1);
    printf("Test 1 - Input: \"%s\" | Output: %zu | Expected: 5 | %s\n", 
           test1, result1, result1 == 5 ? "SUCCESS" : "FAIL");
    
    // Test 2: Empty string
    const char *test2 = "";
    size_t result2 = s21_strlen(test2);
    printf("Test 2 - Input: \"\" | Output: %zu | Expected: 0 | %s\n", 
           result2, result2 == 0 ? "SUCCESS" : "FAIL");
    
    // Test 3: String with spaces
    const char *test3 = "Hello World";
    size_t result3 = s21_strlen(test3);
    printf("Test 3 - Input: \"%s\" | Output: %zu | Expected: 11 | %s\n", 
           test3, result3, result3 == 11 ? "SUCCESS" : "FAIL");
    
    // Test 4: Long string
    const char *test4 = "This is a longer test string";
    size_t result4 = s21_strlen(test4);
    printf("Test 4 - Input: \"%s\" | Output: %zu | Expected: 28 | %s\n", 
           test4, result4, result4 == 28 ? "SUCCESS" : "FAIL");
    
    printf("\n");
}

void s21_strcmp_test() {
    printf("=== s21_strcmp_test ===\n");
    
    // Test 1: Equal strings
    const char *test1a = "abc";
    const char *test1b = "abc";
    int result1 = s21_strcmp(test1a, test1b);
    printf("Test 1 - Input: \"%s\" vs \"%s\" | Output: %d | Expected: 0 | %s\n", 
           test1a, test1b, result1, result1 == 0 ? "SUCCESS" : "FAIL");
    
    // Test 2: First string is less
    const char *test2a = "abc";
    const char *test2b = "xyz";
    int result2 = s21_strcmp(test2a, test2b);
    printf("Test 2 - Input: \"%s\" vs \"%s\" | Output: %d | Expected: < 0 | %s\n", 
           test2a, test2b, result2, result2 < 0 ? "SUCCESS" : "FAIL");
    
    // Test 3: First string is greater
    const char *test3a = "xyz";
    const char *test3b = "abc";
    int result3 = s21_strcmp(test3a, test3b);
    printf("Test 3 - Input: \"%s\" vs \"%s\" | Output: %d | Expected: > 0 | %s\n", 
           test3a, test3b, result3, result3 > 0 ? "SUCCESS" : "FAIL");
    
    // Test 4: Empty strings
    const char *test4a = "";
    const char *test4b = "";
    int result4 = s21_strcmp(test4a, test4b);
    printf("Test 4 - Input: \"\" vs \"\" | Output: %d | Expected: 0 | %s\n", 
           result4, result4 == 0 ? "SUCCESS" : "FAIL");
    
    printf("\n");
}

void s21_strcpy_test() {
    printf("=== s21_strcpy_test ===\n");
    
    // Test 1: Normal string
    char dest1[50];
    const char *src1 = "Hello";
    s21_strcpy(dest1, src1);
    int match1 = 1;
    for (int i = 0; src1[i] != '\0' || dest1[i] != '\0'; i++) {
        if (src1[i] != dest1[i]) {
            match1 = 0;
            break;
        }
    }
    printf("Test 1 - Input: \"%s\" | Output: \"%s\" | %s\n", 
           src1, dest1, match1 ? "SUCCESS" : "FAIL");
    
    // Test 2: Empty string
    char dest2[50];
    const char *src2 = "";
    s21_strcpy(dest2, src2);
    printf("Test 2 - Input: \"\" | Output: \"%s\" | %s\n", 
           dest2, dest2[0] == '\0' ? "SUCCESS" : "FAIL");
    
    // Test 3: String with spaces
    char dest3[50];
    const char *src3 = "Hello World";
    s21_strcpy(dest3, src3);
    int match3 = 1;
    for (int i = 0; src3[i] != '\0' || dest3[i] != '\0'; i++) {
        if (src3[i] != dest3[i]) {
            match3 = 0;
            break;
        }
    }
    printf("Test 3 - Input: \"%s\" | Output: \"%s\" | %s\n", 
           src3, dest3, match3 ? "SUCCESS" : "FAIL");
    
    printf("\n");
}

void s21_strcat_test() {
    printf("=== s21_strcat_test ===\n");
    
    // Test 1: Concatenate two strings
    char dest1[50] = "Hello";
    const char *src1 = " World";
    s21_strcat(dest1, src1);
    const char *expected1 = "Hello World";
    int match1 = 1;
    for (int i = 0; expected1[i] != '\0' || dest1[i] != '\0'; i++) {
        if (expected1[i] != dest1[i]) {
            match1 = 0;
            break;
        }
    }
    printf("Test 1 - Input: \"Hello\" + \" World\" | Output: \"%s\" | %s\n", 
           dest1, match1 ? "SUCCESS" : "FAIL");
    
    // Test 2: Concatenate empty string
    char dest2[50] = "Hello";
    const char *src2 = "";
    s21_strcat(dest2, src2);
    printf("Test 2 - Input: \"Hello\" + \"\" | Output: \"%s\" | %s\n", 
           dest2, s21_strlen(dest2) == 5 ? "SUCCESS" : "FAIL");
    
    // Test 3: Concatenate to empty string
    char dest3[50] = "";
    const char *src3 = "World";
    s21_strcat(dest3, src3);
    int match3 = 1;
    for (int i = 0; src3[i] != '\0' || dest3[i] != '\0'; i++) {
        if (src3[i] != dest3[i]) {
            match3 = 0;
            break;
        }
    }
    printf("Test 3 - Input: \"\" + \"World\" | Output: \"%s\" | %s\n", 
           dest3, match3 ? "SUCCESS" : "FAIL");
    
    printf("\n");
}

void s21_strchr_test() {
    printf("=== s21_strchr_test ===\n");
    
    // Test 1: Character found
    const char *test1 = "Hello World";
    char *result1 = s21_strchr(test1, 'W');
    printf("Test 1 - Input: \"%s\", 'W' | Output: %s | %s\n", 
           test1, result1 ? result1 : "NULL", 
           result1 && result1[0] == 'W' ? "SUCCESS" : "FAIL");
    
    // Test 2: Character not found
    const char *test2 = "Hello World";
    char *result2 = s21_strchr(test2, 'x');
    printf("Test 2 - Input: \"%s\", 'x' | Output: %s | %s\n", 
           test2, result2 ? result2 : "NULL", 
           result2 == NULL ? "SUCCESS" : "FAIL");
    
    // Test 3: Search for null terminator
    const char *test3 = "Hello";
    char *result3 = s21_strchr(test3, '\0');
    printf("Test 3 - Input: \"%s\", '\\0' | Output: %s | %s\n", 
           test3, result3 ? "found" : "NULL", 
           result3 != NULL ? "SUCCESS" : "FAIL");
    
    // Test 4: First character
    const char *test4 = "Hello";
    char *result4 = s21_strchr(test4, 'H');
    printf("Test 4 - Input: \"%s\", 'H' | Output: %s | %s\n", 
           test4, result4 ? result4 : "NULL", 
           result4 && result4[0] == 'H' ? "SUCCESS" : "FAIL");
    
    printf("\n");
}

void s21_strstr_test() {
    printf("=== s21_strstr_test ===\n");
    
    // Test 1: Substring found
    const char *haystack1 = "Hello World";
    const char *needle1 = "World";
    char *result1 = s21_strstr(haystack1, needle1);
    printf("Test 1 - Input: \"%s\", \"%s\" | Output: %s | %s\n", 
           haystack1, needle1, result1 ? result1 : "NULL", 
           result1 && result1[0] == 'W' ? "SUCCESS" : "FAIL");
    
    // Test 2: Substring not found
    const char *haystack2 = "Hello World";
    const char *needle2 = "xyz";
    char *result2 = s21_strstr(haystack2, needle2);
    printf("Test 2 - Input: \"%s\", \"%s\" | Output: %s | %s\n", 
           haystack2, needle2, result2 ? result2 : "NULL", 
           result2 == NULL ? "SUCCESS" : "FAIL");
    
    // Test 3: Empty needle
    const char *haystack3 = "Hello World";
    const char *needle3 = "";
    char *result3 = s21_strstr(haystack3, needle3);
    printf("Test 3 - Input: \"%s\", \"\" | Output: %s | %s\n", 
           haystack3, result3 ? result3 : "NULL", 
           result3 == haystack3 ? "SUCCESS" : "FAIL");
    
    // Test 4: Needle at beginning
    const char *haystack4 = "Hello World";
    const char *needle4 = "Hello";
    char *result4 = s21_strstr(haystack4, needle4);
    printf("Test 4 - Input: \"%s\", \"%s\" | Output: %s | %s\n", 
           haystack4, needle4, result4 ? result4 : "NULL", 
           result4 == haystack4 ? "SUCCESS" : "FAIL");
    
    printf("\n");
}

int main() {
    s21_strlen_test();
    s21_strcmp_test();
    s21_strcpy_test();
    s21_strcat_test();
    s21_strchr_test();
    s21_strstr_test();
    return 0;
}
