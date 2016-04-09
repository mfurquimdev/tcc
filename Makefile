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
SRC = ${wildcard $(SRC_DIR)/*.cpp}
#SRC = pawn.cpp disc.cpp main.cpp
OBJ = ${addprefix $(OBJ_DIR)/, ${notdir ${SRC:.cpp=.o}}}
MAP = ${addprefix $(MAP_DIR)/, ${notdir ${OBJ:.o=.funcmap}}}
INC = -I$(INC_DIR)

#-------------------------------------------------------------------------------
# Compilador, flags e bibliotecas
#-------------------------------------------------------------------------------
CC=g++
CFLAGS= -Wall -Wextra -pedantic -ansi -g -std=c++11
LIB=

TARGET=$(BIN_DIR)/$(NAME)

.PHONY: clean

all: dirs
	@clear
	@clear
	@$(MAKE) clean

	@echo
	@echo Compiling...
	$(MAKE) $(TARGET)

	@echo
	@echo Executing...
	@./prog 2> debug.err
#	@cat input.in | ./prog 2> debug.err
#
#	@echo
#	@echo Debugging...
#	@cat debug.err
#
#	@echo
#	@echo Printing game...
#	@cat output.out

dirs:
	@mkdir -vp $(OBJ_DIR) $(MAP_DIR) $(BIN_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@echo
	@echo Building. $@
	$(CC) -c $^ -o $@ $(CFLAGS) $(INC)

$(TARGET): $(OBJ)
	@echo
	@echo Linking.. $@
	$(CC) -o $@ $(OBJ) $(LIB)


map: $(MAP_DIR)/%.funcmap
	@echo
	@echo Mapping.. $@

$(MAP_DIR)/%.funcmap: $(OBJ_DIR)/%.o
	objdump -d $^ > $@

clean:
	@echo Cleaning...
	@rm -rvf *~ $(OBJ_DIR)/*.o $(MAP_DIR)/*.funcmap $(BIN_DIR)/*

.PRECIOUS: %.o
