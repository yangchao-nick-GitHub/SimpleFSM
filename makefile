# Makefile for compiling fsm_student.cpp and main.cpp into a binary named main

# Compiler and flags
CC = g++
CFLAGS = -std=c++11 -I./include

# Source files and object files
SOURCES = example/fsm_student.cpp example/main.cpp
OBJECTS = $(SOURCES:.cpp=.o)

# Target executable
TARGET = main

# Rules
all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)

.PHONY: all clean