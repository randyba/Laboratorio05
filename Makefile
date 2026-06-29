# Compilador
CC = gcc

# Opciones de compilación
CFLAGS = -Wall -Wextra -g

# Archivos fuente
SRC = src/main.c src/Funciones.c

# Nombre del ejecutable
OUT = main

# Regla principal
all: $(OUT)

# Compila el programa
$(OUT): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)

# Elimina archivos generados
clean:
	rm -f $(OUT)
