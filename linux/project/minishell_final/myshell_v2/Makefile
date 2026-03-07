# ================================================
# Makefile
# What are we doing here?
# → All .c files compile pannurom
# → minishell binary create pannurom
# → make       → build
# → make clean → remove .o files and binary
# ================================================

CC    = gcc
FLAGS = -Wall -g

# Final binary name
TARGET = minishell

# All object files
OBJS = main.o signal_handler.o internal.o external.o

# ---- Build Target ----
all: $(TARGET)

$(TARGET): main.o signal_handler.o internal.o external.o
	$(CC) $(FLAGS) -o minishell main.o signal_handler.o internal.o external.o

# ---- Compile Each File ----
main.o: main.c head.h
	$(CC) $(FLAGS) -c main.c

signal_handler.o: signal_handler.c head.h
	$(CC) $(FLAGS) -c signal_handler.c

internal.o: internal.c head.h
	$(CC) $(FLAGS) -c internal.c

external.o: external.c head.h
	$(CC) $(FLAGS) -c external.c

# ---- Clean ----
clean:
	rm -f main.o signal_handler.o internal.o external.o minishell

.PHONY: all clean
