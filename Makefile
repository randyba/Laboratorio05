CC = gcc
CFLAGS = -Wall -Wextra -g

SRC = src/main.c src/Funciones.c src/Stack.c
OUT = main

all: $(OUT)

$(OUT): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)

clean:
	rm -f $(OUT)

