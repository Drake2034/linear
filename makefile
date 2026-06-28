CC = gcc
CFLAGS = -Wall -Wextra -g -I./include

SRC = src
TARGET = ./bin/main

main: $(SRC)
	$(shell mkdir -p bin)
	$(CC) $(SRC) $(CFLAGS) -o $(TARGET)

test: $(SRC)
	$(shell mkdir -p bin)
	$(CC) ./tests/* ./src/* $(CFLAGS) -o $(TARGET)

.PHONY: clean
clean:
	rm -rf ./bin