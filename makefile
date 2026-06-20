CC = gcc
CFLAGS = -Wall -Wextra -g -I./include

SRC = src/main.c src/linear.c
TARGET = bin/main

main: $(SRC)
	$(shell mkdir -p bin)
	$(CC) $(SRC) $(CFLAGS) -o $(TARGET)

.PHONY: clean
clean:
	rm -rf ./bin