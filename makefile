CC = gcc
CFLAGS = -Wall -Wextra -g -I./include
LDFLAGS = -lm

SRC = ./src/*
TARGET = ./bin

main: $(SRC)
	$(shell mkdir -p bin)
	$(CC) $(SRC) $(CFLAGS) -o $(TARGET)

scalar: $(SRC)
	$(shell mkdir -p bin)
	$(CC) ./tests/scalar-test.c $(SRC) $(CFLAGS) -o $(TARGET)/scalar $(LDFLAGS)

vector: $(SRC)
	$(shell mkdir -p bin)
	$(CC) ./tests/vector-test.c $(SRC) $(CFLAGS) -o $(TARGET)/vector $(LDFLAGS)


matrix: $(SRC)
	$(shell mkdir -p bin)
	$(CC) ./tests/matrix-test.c $(SRC) $(CFLAGS) -o $(TARGET)/matrix $(LDFLAGS)


.PHONY: clean

clean:
	rm -rf ./bin