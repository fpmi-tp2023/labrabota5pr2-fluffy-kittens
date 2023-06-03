# Compiler settings
CC := g++
CFLAGS := -std=c++17 -Wall -Wextra -pedantic

# Directories
SRC_DIR := src
INCLUDE_DIR := includes
BUILD_DIR := build
BIN_DIR := bin
TEST_DIR := test

# Source files
SRC := $(wildcard $(SRC_DIR)/*.cc)
TEST_SRC := $(wildcard $(TEST_DIR)/*.cc)

# Object files
OBJ := $(patsubst $(SRC_DIR)/%.cc,$(BUILD_DIR)/%.o,$(SRC))
TEST_OBJ := $(patsubst $(TEST_DIR)/%.cc,$(BUILD_DIR)/%.o,$(TEST_SRC))

# Libraries
LIBS := -lncurses
TEST_LIBS := -lgtest -lgtest_main

# Main target
MAIN_TARGET := $(BIN_DIR)/main
$(MAIN_TARGET): $(OBJ) $(BUILD_DIR)/main.o | $(BIN_DIR)
	$(CC) $(CFLAGS) $^ -g -o $@ $(LIBS)

# Test target
TEST_TARGET := $(BIN_DIR)/test
$(TEST_TARGET): $(filter-out $(BUILD_DIR)/main.o,$(OBJ)) $(TEST_OBJ) | $(BIN_DIR)
	$(CC) $(CFLAGS) $^ -g -o $@ $(LIBS) $(TEST_LIBS)

# Object files compilation
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cc | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c -g $< -o $@ -I$(INCLUDE_DIR)

$(BUILD_DIR)/%.o: $(TEST_DIR)/%.cc | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c -g $< -o $@ -I$(INCLUDE_DIR) -I$(TEST_DIR)

# Directories creation
$(BUILD_DIR) $(BIN_DIR):
	mkdir -p $@

# Phony targets
.PHONY: clean test run debug build check distcheck
build: $(MAIN_TARGET)
test: $(TEST_TARGET)
	$(TEST_TARGET)
run: build
	$(MAIN_TARGET)
debug: build
	gdb $(MAIN_TARGET)
clean:
	rm -rf $(BUILD_DIR)/* $(BIN_DIR)/*
check:
	shell: /usr/bin/bash -e {0}
distcheck:
	shell: /usr/bin/bash -e {0}
