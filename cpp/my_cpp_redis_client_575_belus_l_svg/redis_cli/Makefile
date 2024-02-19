TARGET_EXEC := my_project
CC := clang++
NASM := nasm
BUILD_DIR := ./build
SRC_DIRS := ./src
CFLAGS = -fsanitize=address -fno-omit-frame-pointer -Wall -Wextra -Werror
LDFLAGS = $(CFLAGS)

export C_INCLUDE_PATH=include/
export CPLUS_INCLUDE_PATH=include/

# Find all the C and ASM files we want to compile
SRCS := $(shell find $(SRC_DIRS) -name '*.c')
SRCS_ASM := $(shell find $(SRC_DIRS) -name '*.asm')
SRCS_CPP := $(shell find $(SRC_DIRS) -name '*.cpp')

# Object files for C and ASM sources
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)
OBJS_ASM := $(SRCS_ASM:%=$(BUILD_DIR)/%.o)
OBJS_CPP := $(SRCS_CPP:%=$(BUILD_DIR)/%.o)

# String substitution (suffix version without %).
# As an example, ./build/hello.c.o turns into ./build/hello.c.d
DEPS := $(OBJS:.o=.d)

# Every folder in ./src will need to be passed to GCC so that it can find header files
INC_DIRS := $(shell find $(SRC_DIRS) -type d)
# Add a prefix to INC_DIRS. So moduleA would become -ImoduleA. Compiler understands this -IC flag
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

# The -MMD and -MP flags together generate Makefiles for us!
# These files will have .d instead of .o as the output.
XTRAFLAGS := $(INC_FLAGS) -g -MMD -MP -std=c++17

# The final build step.

$(BUILD_DIR)/$(TARGET_EXEC): $(OBJS) $(OBJS_ASM) $(OBJS_CPP)
	$(CC) $(OBJS) $(OBJS_ASM) $(OBJS_CPP) -o $@ 
	cp $(BUILD_DIR)/$(TARGET_EXEC) ./

# Build step for C source
$(BUILD_DIR)/%.c.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(XTRAFLAGS) -Wno-deprecated -c $< -o $@

# Build step for C++ source
$(BUILD_DIR)/%.cpp.o: %.cpp
	mkdir -p $(dir $@)
	$(CC) $(XTRAFLAGS) -c $< -o $@

# Build step for ASM source
$(BUILD_DIR)/%.asm.o: %.asm
	mkdir -p $(dir $@)
	$(NASM) -f elf64 -o $@ $<

.PHONY: clean fclean debug debugc
clean:
	rm $(shell find $(BUILD_DIR) -name '*.o')
	rm $(BUILD_DIR)/$(TARGET_EXEC)
	rm $(TARGET_EXEC)

fclean:
	rm -r $(BUILD_DIR)
	rm $(TARGET_EXEC)

debug: $(OBJS) $(OBJS_ASM) $(OBJS_CPP)
	$(CC) -g $(OBJS) $(OBJS_ASM) $(OBJS_CPP) -o $@ $(LDFLAGS)

debugc:
	rm -r $(BUILD_DIR)
	rm debug

# Include the .d makefiles. The - at the front suppresses the errors of missing
# Makefiles. Initially, all the .d files will be missing, and we don't want those
# errors to show up.
-include $(DEPS)
