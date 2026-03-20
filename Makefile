CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -Werror -std=c11 -Iinclude
SRC = src/main.c src/io.c src/doi.c src/fetch.c src/bibtex.c src/abnt.c src/style.c src/formatter.c
OUT = pointertoref

all:
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)

clean:
	rm -f $(OUT)
