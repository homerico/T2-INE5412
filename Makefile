# Define as variáveis
CXX = g++
SRC_DIR = src
INC_DIR = inc
OBJ_DIR = obj
BIN_DIR = bin
CXXFLAGS = -Wall -Wextra -I$(INC_DIR) -g -std=c++11 -ggdb3
EXECUTABLE = $(BIN_DIR)/main

# Lista de fontes e objetos
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SOURCES))

# Alvo padrão (compila o projeto)
all: $(BIN_DIR) $(OBJ_DIR) $(EXECUTABLE)

# Cria os diretórios obj/ e bin/
$(BIN_DIR):
	mkdir -p $(BIN_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Compila o executável
$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Compila os objetos
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpa objetos e executável
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

# Executa o projeto
run: all
	$(EXECUTABLE)

.PHONY: all clean run