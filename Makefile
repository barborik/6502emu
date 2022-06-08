CC = gcc

CFLAGS = -g -std=c99 -Wall -Wextra -Wpedantic -Wno-unused-function
LFLAGS = 

INCL = 
LIBS = 

SRC = $(wildcard src/*.c)
OBJ = $(patsubst src/%.c, obj/%.o, $(SRC))

ifeq ($(OS),Windows_NT)
TARGET = bin/6502emu.exe
LFLAGS += -lmingw32
else
TARGET = bin/6502emu
endif

$(TARGET): $(OBJ)
	$(CC) $^ -o $@ $(LIBS) $(LFLAGS)

obj/%.o: src/%.c
	$(CC) -c $< -o $@ $(INCL) $(CFLAGS)
