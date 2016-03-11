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
# ├── map
# ├── obj
# └── src
#-------------------------------------------------------------------------------

#-------------------------------------------------------------------------------
# Nome do projeto
#-------------------------------------------------------------------------------
NAME=big_points

#-------------------------------------------------------------------------------
# Versão do projeto
#-------------------------------------------------------------------------------
#MAJOR_VERSION=0
#MINOR_VERSION=0
#MICRO_VERSION=1
#VERSION=$(MAJOR_VERSION).$(MINOR_VERSION).$(MICRO_VERSION)

#-------------------------------------------------------------------------------
# Diretórios
#-------------------------------------------------------------------------------
SRC_DIR=./src
OBJ_DIR=./obj
MAP_DIR=./map
INC_DIR=./inc
BIN_DIR=./bin

#-------------------------------------------------------------------------------
# C, Header, Object and Mapping Files
#-------------------------------------------------------------------------------
SRC_MAIN= main.c
SRC = ${wildcard $(SRC_DIR)/*.c}
OBJ = ${addprefix $(OBJ_DIR)/, ${notdir ${SRC:.c=.o}}}
MAP = ${addprefix $(MAP_DIR)/, ${notdir ${OBJ:.o=.funcmap}}}
INC = -I$(INC_DIR)

#-------------------------------------------------------------------------------
# Compilador, flags e bibliotecas
#-------------------------------------------------------------------------------
CC=gcc
CFLAGS= -Wall -pedantic -ansi -g
LIB=

TARGET=$(BIN_DIR)/$(NAME)

.PHONY: clean

all: dirs
	@echo
	$(MAKE) $(TARGET)

dirs:
	@mkdir -vp $(OBJ_DIR) $(MAP_DIR) $(BIN_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@echo
	@echo Building. $@
	$(CC) -c $^ -o $@ $(CFLAGS) $(INC)

$(MAP_DIR)/%.funcmap: $(OBJ_DIR)/%.o
	@echo Mapping.. $@
	objdump -d $^ > $@

$(TARGET): $(MAP)
	@echo
	@echo Linking.. $@
	$(CC) -o $@ $(SRC_MAIN) $(OBJ) $(LIB)

clean:
	@echo Cleaning...
	@rm -rvf *~ $(OBJ_DIR)/*.o $(MAP_DIR)/*.funcmap $(BIN_DIR)/*
