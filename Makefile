# Makefile version 1.0.0
# Brion Lang
# github: ewoner@gmail.com
#
# STR project Makefile version
# - TARGET_EXEC specialized

# Declare Variables
TARGET_EXEC := main.exe
BUILD_DIR := Build
SRC_DIRS := Sources
DATA_DIR := Data
RELEASE_DIR := Release
EXE := $(BUILD_DIR)/$(TARGET_EXEC)

# Find all C++ files to compile
SRCS := $(shell find $(SRC_DIRS) -name '*.cpp')

# Create List of Object files needed
OBJS := $(SRCS:%.cpp=$(BUILD_DIR)/%.o)

# Create List of Dependent fiels needed
DEPS := $(OBJS:.o=.d)

# Create List of Include Directories
INC_DIRS := $(shell find $(SRC_DIRS) -type d)

# Create Command Line -I entries for all include directories
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

# Create Command Line Areguments for g++
# -MMD and -MP generate dependent fiels (.d)
# -std is the version fof C++ to compile at
# -g add debugging information
CPPFLAGS_RELEASE := $(INC_FLAGS) -std=c++20
CPPFLAGS := $(CPPFLAGS_RELEASE) -MMD -MP -g

# Main build command ... Creates the executable and directories
.PHONY: main
main:  $(BUILD_DIR)/$(SRC_DIRS)/main.o $(OBJS)
	@echo -e "\nCreating...." $(BUILD_DIR)/$(TARGET_EXEC) "\n"
	$(CXX) $(OBJS) -o $(BUILD_DIR)/$(TARGET_EXEC) $(LDFLAGS) $(CPPFLAGS)
	@echo -e "\ncoping data files over....\n"
	mkdir -p $(BUILD_DIR)/$(DATA_DIR)
	cp $(DATA_DIR)/* $(BUILD_DIR)/$(DATA_DIR)
	@echo -e "\nDone!!\n"

# Builds the individual object files in the BUILD_DIR
$(BUILD_DIR)/%.o: %.cpp
	@echo -e "\nCompiling ..." $@ "\n"
	mkdir -p $(dir $@)
	$(CXX) $(CPPFLAGS) -c $< -o $@

# Delete all build files and the BUILD_DIR
# also cleans up the SRC_DIR of misplaced files
.PHONY: clean
clean:
	@echo -e "\nCLean and removing Build files....\n"
	$(RM) $(BUILD_DIR) -rf
	@echo -E "Now cleaning source directories...\n"
	$(RM) $(SRC_DIR)/*.{o,s,gch,d,exe} -rf
	@echo -e "\nDone!!\n"

#Deletes and rebuilds all files
.PHONY: build
build: clean main

# Creates the main executable and runs it
.PHONY: run
run: main
	$(EXE)

# Runs the GDB after updating the build
.PHONY: debug
debug: main
	gdb $(EXE)

# Builds and copys EXE to RELEASE_DIR
.PHONY: release
release: build
	mkdir -p $(RELEASE_DIR)/OLD
	mv -f --backup=numbered $(RELEASE_DIR)/$(TARGET_EXEC) $(RELEASE_DIR)/OLD 2> /dev/null
	$(CXX) $(OBJS) -o $(RELEASE_DIR)/$(TARGET_EXEC) $(LDFLAGS) $(CPPFLAGS_RELEASE)

-include $(DEPS)

