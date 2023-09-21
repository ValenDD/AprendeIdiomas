# Definimos variables
CC = g++
CFLAGS = -c -Wall
LDFLAGS =
INCLUDE_DIR = include
SRC_DIR = src
OBJ_DIR = obj

# Obtenemos la lista de archivos
INCLUDE_FILES := $(wildcard $(INCLUDE_DIR)/*.h)
SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp) main.cpp
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))

# Regla para generar el ejecutable
principal: $(OBJ_FILES)
	$(CC) $(LDFLAGS) $^ -o $@

# Regla para generar los objetos
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(INCLUDE_FILES)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) $< -o $@

# Regla para limpiar los archivos generados
clean:
	rm -f $(OBJ_DIR)/*.o principal
