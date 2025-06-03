# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -std=c++17

# Output binary
TARGET = BankingConsoleApp

# Source files
SRCS = main.cpp banking_console.cpp bank_account.cpp helpers/console_helper.cpp helpers/dollar_cent_conversion_helper.cpp

# Object files (replacing .cpp with .o)
OBJS = $(SRCS:.cpp=.o)

# Default rule
all: $(TARGET)

# Link the object files into the final binary
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)

# Compile each .cpp into a .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build artifacts
clean:
	rm -f $(OBJS) $(TARGET)