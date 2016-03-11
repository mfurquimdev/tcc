#-------------------------------------------------------------------------------
# Copyright (c) 2016 Mateus Furquim
# Baseado no Makefile de:
# Edson Alves da Costa Júnior [https://github.com/edsomjr]
# Leonn Ferreira <leonn.paiva@gmail.com>
#-------------------------------------------------------------------------------

#-------------------------------------------------------------------------------
# Estrutura do projeto
# .
# ├── bin
# ├── doc
# ├── inc
# ├── main.c
# ├── Makefile
# ├── obj
# └── src
#-------------------------------------------------------------------------------

#-------------------------------------------------------------------------------
# Nome do projeto
#-------------------------------------------------------------------------------
NAME=big_points

#-------------------------------------------------------------------------------
# Diretórios
#-------------------------------------------------------------------------------
INC_DIR=./inc
OBJ_DIR=./obj
SRC_DIR=./src
BIN_DIR=./bin
MAP_DIR=./map

TARGET=$(BIN_DIR)/$(NAME)

CC=gcc

#-------------------------------------------------------------------------------
# C and Object Files
#-------------------------------------------------------------------------------
SRC_MAIN= main.c
SRC = ${wildcard $(SRC_DIR)/*.c}
OBJ = ${addprefix $(OBJ_DIR)/, ${notdir ${SRC:.c=.o}}}
MAP = ${addprefix $(MAP_DIR)/, ${notdir ${OBJ:.o=.funcmap}}}

#-------------------------------------------------------------------------------
# Flags
#-------------------------------------------------------------------------------
CFLAGS= -Wall -pedantic -ansi -g
INCLUDES= -I$(INC_DIR)
LIBS=

.PHONY: clean

all:
	@mkdir -vp $(OBJ_DIR) $(MAP_DIR) $(BIN_DIR)
	$(MAKE) $(TARGET)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@echo Building $@
	@$(CC) -c $(CFLAGS) $(INCLUDES) $< -o $@

$(MAP_DIR)/%.funcmap: $(OBJ_DIR)/%.o
	@echo MappingF $@
	@objdump -d $< > $@

$(TARGET): $(MAP)
	@echo Building $@
	@$(CC) $(OBJ) $(SRC_MAIN) -o $@ $(LIBS)

clean:
	@echo Cleaning...
	@find . -name *.o -exec rm {} \;
	@rm -rvf *~ $(OBJ_DIR)/*.o $(MAP_DIR)/*.funcmap $(BIN_DIR)/*
