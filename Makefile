CC = gcc
CFLAGS = -Wall -Wextra -g

SRC = src/main.c src/ArreglosDinamicos.c src/Stack.c src/ListaEnlazada.c src/ListaDolementeEnlazada.c
OUT = main

all: $(OUT)

$(OUT): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)

clean:
	rm -f $(OUT)
