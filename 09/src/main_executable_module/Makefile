CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11
BUILD_DIR = /workspaces/02/build
TARGET = $(BUILD_DIR)/Quest_3

DATA_LIBS_DIR = ../data_libs
DATA_MODULE_DIR = ../data_module
DECISION_MODULE_DIR = ../yet_another_decision_module

SRCS = main_executable_module.c \
       $(DATA_LIBS_DIR)/data_io.c \
       $(DATA_LIBS_DIR)/data_stat.c \
       $(DATA_MODULE_DIR)/data_process.c \
       $(DECISION_MODULE_DIR)/decision.c

OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $(OBJS) -lm -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

rebuild: clean all

# Static library target
data_stat.a: $(DATA_LIBS_DIR)/data_stat.o
	ar rcs $(BUILD_DIR)/data_stat.a $(DATA_LIBS_DIR)/data_stat.o

build_with_static: main_executable_module.o $(DATA_LIBS_DIR)/data_io.o $(DATA_MODULE_DIR)/data_process.o $(DECISION_MODULE_DIR)/decision.o data_stat.a
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) main_executable_module.o $(DATA_LIBS_DIR)/data_io.o $(DATA_MODULE_DIR)/data_process.o $(DECISION_MODULE_DIR)/decision.o $(BUILD_DIR)/data_stat.a -lm -o $(BUILD_DIR)/Quest_4

# Dynamic library target
$(DATA_MODULE_DIR)/data_process_dyn.o: $(DATA_MODULE_DIR)/data_process.c
	$(CC) $(CFLAGS) -fPIC -c $(DATA_MODULE_DIR)/data_process.c -o $(DATA_MODULE_DIR)/data_process_dyn.o

data_process.so: $(DATA_MODULE_DIR)/data_process_dyn.o $(DATA_LIBS_DIR)/data_stat.o
	@mkdir -p $(BUILD_DIR)
	$(CC) -shared $(DATA_MODULE_DIR)/data_process_dyn.o $(DATA_LIBS_DIR)/data_stat.o -lm -o $(BUILD_DIR)/data_process.so

build_with_dynamic: main_executable_module.o $(DATA_LIBS_DIR)/data_io.o $(DECISION_MODULE_DIR)/decision.o data_process.so
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -DUSE_DYNAMIC main_executable_module.c $(DATA_LIBS_DIR)/data_io.c $(DATA_LIBS_DIR)/data_stat.c $(DECISION_MODULE_DIR)/decision.c -ldl -lm -o $(BUILD_DIR)/Quest_5

.PHONY: all clean rebuild build_with_static build_with_dynamic
