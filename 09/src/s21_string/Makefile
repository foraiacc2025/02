CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11
BUILD_DIR = /workspaces/02/build

SRCS = s21_string.c s21_string_test.c
OBJS = $(SRCS:.c=.o)

all: full_coverage_tests

strlen_tests: s21_string.o s21_string_test.o
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) s21_string.o s21_string_test.o -o $(BUILD_DIR)/Quest_6

strcmp_tests: s21_string.o s21_string_test.o
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) s21_string.o s21_string_test.o -o $(BUILD_DIR)/Quest_7

strcpy: s21_string.o s21_string_test.o
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) s21_string.o s21_string_test.o -o $(BUILD_DIR)/Quest_8

strcat: s21_string.o s21_string_test.o
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) s21_string.o s21_string_test.o -o $(BUILD_DIR)/Quest_9

strchr: s21_string.o s21_string_test.o
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) s21_string.o s21_string_test.o -o $(BUILD_DIR)/Quest_10

strstr: s21_string.o s21_string_test.o
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) s21_string.o s21_string_test.o -o $(BUILD_DIR)/Quest_11

full_coverage_tests: s21_string.o s21_string_test.o
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) s21_string.o s21_string_test.o -o $(BUILD_DIR)/Quest_12

text_processor: text_processor.o s21_string.o
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) text_processor.o s21_string.o -o $(BUILD_DIR)/Quest_13

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) text_processor.o
	rm -f $(BUILD_DIR)/Quest_6 $(BUILD_DIR)/Quest_7 $(BUILD_DIR)/Quest_8
	rm -f $(BUILD_DIR)/Quest_9 $(BUILD_DIR)/Quest_10 $(BUILD_DIR)/Quest_11
	rm -f $(BUILD_DIR)/Quest_12 $(BUILD_DIR)/Quest_13

rebuild: clean all

.PHONY: all clean rebuild strlen_tests strcmp_tests strcpy strcat strchr strstr full_coverage_tests text_processor
