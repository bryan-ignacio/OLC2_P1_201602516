SRC     := src
BUILD   := build

CC      := gcc
BISON   := bison
FLEX    := flex
CFLAGS  := -I$(SRC) -Wall -Wextra
GTK_CFLAGS := $(shell pkg-config --cflags gtk+-3.0)
GTK_LIBS := $(shell pkg-config --libs gtk+-3.0)
RM      := rm -rf $(BUILD)
MKDIR   := mkdir -p $(BUILD)

.DEFAULT_GOAL := all

# Buscar todos los .c en src (excepto parser.y y lexer.l)
SRC_FILES_CONSOLE := $(shell find $(SRC) -name '*.c' -not -path '$(SRC)/gui/*' -not -name 'main_gui.c')
SRC_FILES_GUI := $(shell find $(SRC) -name '*.c' -not -name 'main.c')

# Archivos generados por Bison y Flex
BISON_C := $(BUILD)/parser.tab.c
BISON_H := $(BUILD)/parser.tab.h
LEX_C   := $(BUILD)/lex.yy.c

# Objetos finales
OBJ_SRC_CONSOLE := $(patsubst $(SRC)/%.c,$(BUILD)/%.o,$(SRC_FILES_CONSOLE))
OBJ_SRC_GUI := $(patsubst $(SRC)/%.c,$(BUILD)/%.o,$(SRC_FILES_GUI))
OBJ_GEN := $(BUILD)/parser.tab.o $(BUILD)/lex.yy.o
OBJ_ALL_CONSOLE := $(OBJ_SRC_CONSOLE) $(OBJ_GEN)
OBJ_ALL_GUI := $(OBJ_SRC_GUI) $(OBJ_GEN)

all: console

console: $(BUILD)/calc

gui: $(BUILD)/calc-gui

$(BUILD):
	$(MKDIR)

# Generar parser
$(BISON_C) $(BISON_H) $(BUILD)/parser.output: $(SRC)/entriesTools/parser.y | $(BUILD)
	$(BISON) -d -v --locations -o $(BISON_C) $<

# Generar lexer
$(LEX_C): $(SRC)/entriesTools/lexer.l $(BISON_H) | $(BUILD)
	$(FLEX) -o $@ $<

# Compilar .c de src a .o
$(BUILD)/%.o: $(SRC)/%.c | $(BUILD)
	@mkdir -p $(dir $@)
	@if echo "$<" | grep -q "gui/" || echo "$<" | grep -q "main_gui.c"; then \
		$(CC) $(CFLAGS) $(GTK_CFLAGS) -c $< -o $@; \
	else \
		$(CC) $(CFLAGS) -c $< -o $@; \
	fi

# Compilar .c generados por Bison/Flex a .o
$(BUILD)/parser.tab.o: $(BISON_C) $(BISON_H)
	$(CC) $(CFLAGS) -c $(BISON_C) -o $@

$(BUILD)/lex.yy.o: $(LEX_C)
	$(CC) $(CFLAGS) -c $(LEX_C) -o $@

# Enlazar versión consola
$(BUILD)/calc: $(OBJ_ALL_CONSOLE)
	$(CC) $(CFLAGS) -o $@ $^ -lm

# Enlazar versión GUI
$(BUILD)/calc-gui: $(OBJ_ALL_GUI)
	$(CC) $(CFLAGS) -o $@ $^ $(GTK_LIBS) -lm

clean:
	$(RM)

.PHONY: all clean console gui

console: $(BUILD)/calc

gui: $(BUILD)/calc-gui
