# Compiler (support cross compilation)
CC = $(CROSS_COMPILE)gcc

# Flags for compiler
CFLAGS = -Wall -Werror

# Target binary
TARGET = writer

# Object files
OBJS = writer.o

# Default target: build the writer app
all: $(TARGET)

# Rule to link the final executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Rule to compile .c to .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up build artifacts
clean:
	rm -f $(TARGET) $(OBJS)
