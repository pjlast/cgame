# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -O2 -std=c2x

# Raylib libraries and flags (update if necessary)
RAYLIB_FLAGS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

# Project files
SRCDIR = src
BUILDDIR = build
RAYLIBDIR = raylib/src
TARGET = game

# Find all .c files in source directory
SRC = $(wildcard $(SRCDIR)/*.c)
OBJ = $(patsubst $(SRCDIR)/%.c, $(BUILDDIR)/%.o, $(SRC))

# Default rule
all: $(BUILDDIR) $(TARGET) raylib

# Create build directory if it doesn't exist
$(BUILDDIR):
	mkdir -p $(BUILDDIR)

# Build the final executable
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ -L$(RAYLIBDIR) $(RAYLIB_FLAGS)

# Compile source files to object files
$(BUILDDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@ -I$(RAYLIBDIR)

# Compile raylib
raylib:
	cd $(RAYLIBDIR) && make PLATFORM=PLATFORM_DESKTOP

# Clean up build artifacts
clean:
	rm -rf $(BUILDDIR) $(TARGET)

# Run the game
run: all
	./$(TARGET)

# Phony targets
.PHONY: all clean run raylib

