PROJECT_NAME := image-processing
CXX := g++
CXXFLAGS := -W -Wall -ansi -pedantic
RM := -rm

OBJ_DIR := ./build
INC_DIR := ./include
SRC_DIR := ./src
BIN_DIR := ./bin

SRC := $(wildcard src/*.cpp)
INC := $(wildcard include/*.hpp)
OBJ := $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

all: project 

project: $(OBJ) $(INC) | $(BIN_DIR)
	$(CXX) $(OBJ) $(CXXFLAGS) -o $(BIN_DIR)/$(PROJECT_NAME)
	@ln $(BIN_DIR)/$(PROJECT_NAME) $(PROJECT_NAME)

$(OBJ): 
		$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp $(INC) | $(OBJ_DIR)
		$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR):
		@mkdir -p $(OBJ_DIR)

$(BIN_DIR):
		@mkdir -p $(BIN_DIR)

clean: 
	@$(RM) -f image-processing 
	@$(RM) -r $(OBJ_DIR)
	@$(RM) -r $(BIN_DIR)
