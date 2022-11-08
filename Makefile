# Thanks to Job Vranish (https://spin.atomicobject.com/2016/08/26/makefile-c-projects/)
TARGET_EXEC := Sudoku

BUILD_DIR := ./build/
SRC_DIR := ./src/
EXE_DIR := ./exe/

LDFLAGS := 
INCFLAGS := /usr/include/x86_64-linux-gnu/
LIBS := -L/usr/lib/x86_64-linux-gnu/
WARN_FLAGS :=  -Wall -Werror -Wextra -pedantic -Wshadow -Wsign-conversion -Wunreachable-code -Wconversion
CPPFLAGS := -Og -ggdb -g -pg -march=native -std=c++11 -fbounds-check -fstack-protector -fcf-protection -fsanitize=leak,undefined
#RELEASE_FLAGS := -O2 -g0 -march=native -std=c++11 -fdelete-dead-exceptions
#DEBUG_FLAGS := -Og -ggdb -g -pg -march=native -std=c++11 -fbounds-check -fstack-protector -fcf-protection -fsanitize=leak,undefined
# -fsanitize=address

EXE := $(EXE_DIR)/$(TARGET_EXEC)

# Find all the C and C++ files we want to compile
# Note the single quotes around the * expressions. Make will incorrectly expand these otherwise.
SRCS := $(shell find $(SRC_DIR) -name '*.cpp')
HEADERS := $(shell find $(SRC_DIR) -name '*.h' -or -name '*.hpp')

# String substitution for every C/C++ file.
# As an example, hello.cpp turns into ./build/hello.cpp.o
OBJS := $(SRCS:%.cpp=$(BUILD_DIR)/%.o)

# Dependency files
DEPS := $(OBJS:.o=.d)

# Every folder in ./src will need to be passed to GCC so that it can find header files
INC_DIRS := $(INCFLAGS)
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

# The -MMD and -MP flags together generate Makefiles for us!
# These files will have .d instead of .o as the output.
CPPFLAGS += $(INC_FLAGS) $(WARN_FLAGS) -MMD -MP

all: $(EXE)

# The final build step.
$(EXE): $(OBJS)
	mkdir -p $(dir $@)
	$(CXX) $(OBJS) -o $@ $(LDFLAGS) $(CPPFLAGS)

# Build step for C++ source
$(BUILD_DIR)/%.o: %.cpp $(HEADERS)
	mkdir -p $(dir $@)
	$(CXX) $(CPPFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR) $(EXE_DIR)

-include $(DEPS)

