LIB = myplugin
LIB_NAME = lib$(LIB).so

BIN_DIR = bin
BUILD_DIR = build
DEPS_DIR = $(BUILD_DIR)/deps
OBJ_DIR = $(BUILD_DIR)/obj
SRC_DIR = src
INC_DIR = inc

SV_DIR = server
SV_NAME = omp-server

SRC = $(shell find $(SRC_DIR) -name '*.c') $(shell find $(INC_DIR) -name '*.c')
OBJ = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

CC = clang
CFLAGS = -g -m32 -fPIC -MD -MF $(DEPS_DIR)/$(LIB).d -Wvarargs -Wall -Werror -Werror=vla
INC_FLAGS = -I$(SRC_DIR) -I$(INC_DIR) -I/usr/include
LINK_FLAGS = -shared
DEFINES = -DLINUX

all: build

build: $(BIN_DIR)/$(LIB_NAME)

# Build App
$(BIN_DIR)/$(LIB_NAME): $(OBJ)
	@mkdir -p $(BIN_DIR)
	clang $(CFLAGS) $(DEFINES) $(INC_FLAGS) $(LINK_FLAGS) $(OBJ) -o $@

# Build objects
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(DEPS_DIR)
	$(CC) $(CFLAGS) $(DEFINES) $(INC_FLAGS) -c $< -o $@

run: install
	@cd $(SV_DIR) && ./$(SV_NAME)

install: build
	cp $(BIN_DIR)/$(LIB_NAME) $(SV_DIR)/plugins

clean:
	rm -rf $(BIN_DIR) $(BUILD_DIR) $(SV_DIR)/plugins/$(LIB_NAME)

.PHONY: all build install run clean

-include $(DEPS_DIR)/*.d