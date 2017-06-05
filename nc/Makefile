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
LFLAGS= -lncurses

TARGET=$(BIN_DIR)/$(NAME)

.PHONY: all dirs clean

all: dirs
	@echo
	@echo Compiling...
	$(MAKE) $(TARGET)

dirs:
	@mkdir -vp $(OBJ_DIR) $(MAP_DIR) $(BIN_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@echo
	@echo Building. $@
	$(CC) -c $^ -o $@ $(CFLAGS) $(INC)

$(TARGET): $(OBJ)
	@echo
	@echo Linking.. $@
	$(CC) -o $@ $(OBJ) $(LIB) $(LFLAGS)

clean:
	@echo Cleaning...
	@rm -rvf *~ $(OBJ_DIR) $(MAP_DIR) $(BIN_DIR)

.PRECIOUS: %.o
