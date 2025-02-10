# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++98 -Wall -Wextra -pedantic

# Define the name of the executable
TARGET = megaphone

# The source files and object files
SRC = $(wildcard *.cpp)       # Find all .cpp files in the current directory
OBJ = $(SRC:.cpp=.o)          # Convert .cpp files to .o files

# Colors for output
RED     = \033[0;31m
GREEN   = \033[0;32m
YELLOW  = \033[0;33m
BLUE    = \033[0;34m
MAGENTA = \033[0;35m
CYAN    = \033[0;36m
RESET   = \033[0m

# Default target
all: $(TARGET)

# Link the object files into the final executable
$(TARGET): $(OBJ)
	@echo "$(GREEN)Linking $(TARGET)...$(RESET)"
	@$(CXX) $(OBJ) -o $(TARGET)
	@echo "$(CYAN)Build complete!$(RESET)"

# Compile each .cpp file into a .o file
%.o: %.cpp
	@echo "$(YELLOW)Compiling $<...$(RESET)"
	@$(CXX) $(CXXFLAGS) -c $< -o $@
	@echo "$(MAGENTA)Compiled $<$(RESET)"

# Clean up generated files (object files and the executable)
clean:
	@echo "$(RED)Cleaning up...$(RESET)"
	@rm -f $(OBJ) $(TARGET)
	@echo "$(GREEN)Cleanup complete!$(RESET)"

fclean: clean
	@echo "$(MAGENTA)Cleaning up executable...$(RESET)"
	@rm -f $(TARGET)
	@echo "$(GREEN)Executable obliterated!$(RESET)"



# Rebuild everything from scratch
re: fclean all

# For debugging
debug: CXXFLAGS += -g
debug: clean all

# To run the compiled program
run: $(TARGET)
	@echo "$(BLUE)Running the program...$(RESET)"
	./$(TARGET)

.PHONY: all clean rebuild debug run

