TARGET_EXEC := my_curl
cc := clang
BUILD_DIR := ./build
SRC_DIRS := ./src
CFLAGS = -fsanitize=address -Wall -Wextra -Werror
LDFLAGS = $(CFLAGS)

export C_INCLUDE_PATH=include/

# Find all the C files we want to compile
# Note the single quotes around the * expressions. Make will incorrectly expand these otherwise.

SRCS := $(shell find $(SRC_DIRS) -name '*.c')
# rm $(BUIS)
# BUIS := $(shell find $(BUILD_DIR) -name '*.o')
# String substitution for every C file.
# As an example, hello.c turns into ./build/hello.c.o
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)

# String substitution (suffix version without %).
# As an example, ./build/hello.c.o turns into ./build/hello.c.d
DEPS := $(OBJS:.o=.d)

# Every folder in ./src will need to be passed to GCC so that it can find header files
INC_DIRS := $(shell find $(SRC_DIRS) -type d)
# Add a prefix to INC_DIRS. So moduleA would become -ImoduleA. GCC understands this -I flag
INC_FLAGS := $(addprefix -IC,$(INC_DIRS))

# The -MMD and -MP flags together generate Makefiles for us!
# These files will have .d instead of .o as the output.
XTRAFLAGS := $(INC_FLAGS) -g -MMD -MP

# The final build step.

$(BUILD_DIR)/$(TARGET_EXEC): $(OBJS)
	$(CC) $(OBJS) -o $@ 
	cp $(BUILD_DIR)/$(TARGET_EXEC) ./
# Build step for C source
$(BUILD_DIR)/%.c.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(XTRAFLAGS) -c $< -o $@
#$(LDFLAGS)
.PHONY: clean fclean debug debugc
clean:
	rm $(shell find $(BUILD_DIR) -name '*.o')
	rm $(BUILD_DIR)/$(TARGET_EXEC)
	rm $(TARGET_EXEC)

fclean:
	rm -r $(BUILD_DIR)
	rm $(TARGET_EXEC)

debug: $(OBJS)
	$(CC) -g $(OBJS) -o $@ $(LDFLAGS)

debugc:	
	rm -r $(BUILD_DIR)
	rm debug

# Include the .d makefiles. The - at the front suppresses the errors of missing
# Makefiles. Initially, all the .d files will be missing, and we don't want those
# errors to show up.
-include $(DEPS)

# Thanks to Job Vranish (https://spin.atomicobject.com/2016/08/26/makefile-c-projects/)