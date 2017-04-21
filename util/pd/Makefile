#-------------------------------------------------------------------------------
# Copyright (c) 2016 Mateus Furquim
# Baseado no Makefile de:
# Edson Alves da Costa Júnior [https://github.com/edsomjr]
# Leonn Ferreira <leonn.paiva@gmail.com>
#-------------------------------------------------------------------------------

#-------------------------------------------------------------------------------
# Estrutura do projeto
# .
# ├── inc
# ├── Makefile
# ├── obj
# └── src
#-------------------------------------------------------------------------------

#-------------------------------------------------------------------------------
# Nome do projeto
#-------------------------------------------------------------------------------
NAME=st.out

#-------------------------------------------------------------------------------
# Diretórios
#-------------------------------------------------------------------------------
SRC_DIR=./src
OBJ_DIR=./obj
INC_DIR=./inc
BIN_DIR=.

#-------------------------------------------------------------------------------
# C, Header, Object and Mapping Files
#-------------------------------------------------------------------------------
SRC = ${wildcard $(SRC_DIR)/*.cpp}
OBJ = ${addprefix $(OBJ_DIR)/, ${notdir ${SRC:.cpp=.o}}}
INC = -I$(INC_DIR)

#-------------------------------------------------------------------------------
# Compilador, flags e bibliotecas
#-------------------------------------------------------------------------------
CC=g++
CFLAGS= -Wall -Wextra -pedantic -ansi -g -std=c++11 -Ofast --param max-inline-recursive-depth=16 
LFLAGS= -lm

TARGET=$(BIN_DIR)/$(NAME)

.PHONY: clean all dirs

all: dirs
	@echo
	@echo Compiling...
	$(MAKE) $(TARGET)

dirs:
	@mkdir -vp $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@echo
	@echo Building $@
	$(CC) -c $^ -o $@ $(CFLAGS) $(INC)

$(TARGET): $(OBJ)
	@echo
	@echo Linking $@
	$(CC) -o $@ $(OBJ) $(LIB) $(LFLAGS)

clean:
	@echo Cleaning...
	rm -rvf *~ $(OBJ_DIR) $(TARGET) 

.PRECIOUS: %.o
