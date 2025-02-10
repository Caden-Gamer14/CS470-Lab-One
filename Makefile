CC = gcc
CFLAGS = -Wall -Wextra -std=c11
TARGET = projectone

all: $(TARGET)

$(TARGET): process_program.c
	$(CC) $(CFLAGS) -o $(TARGET) process_program.c

clean:
	rm -f $(TARGET)