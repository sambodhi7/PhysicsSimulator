# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -std=c++17 -Iinclude -Ilibraries/sfml/include

# Build directory for executable
BUILD_DIR = build

SRCS = $(wildcard src/*.cpp			)
OBJS = $(SRCS:.cpp=.o)

# Target executable path inside build folder
TARGET = $(BUILD_DIR)/simulator.exe

# Create build directory if it doesn't exist (as a proper target)
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Default target: build the executable
all: $(TARGET)

# Link objects into executable in build folder, depends on build directory
$(TARGET): $(BUILD_DIR) $(OBJS)
	$(CXX) $(OBJS) -o $@ -Llibraries/sfml/lib -lsfml-graphics -lsfml-window -lsfml-system

# Compile source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build files and executable
clean:
	rm -f $(OBJS) $(TARGET)

# Run the program (builds if needed)
run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run
