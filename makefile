SRC_DIR = src
LANG_DIR = src/lua
COMPILER_ARGS = -pedantic -Wall -std=gnu++17 -I/$(SRC_DIR)
OUTPUT_DIR = bin

build: main.o queue.o lexer.o location.o token.o
	g++ -o $(OUTPUT_DIR)/main $(OUTPUT_DIR)/main.o $(OUTPUT_DIR)/queue.o $(OUTPUT_DIR)/location.o $(OUTPUT_DIR)/token.o $(OUTPUT_DIR)/lexer.o

lexer.o: $(SRC_DIR)/lexer.cpp
	g++ -o $(OUTPUT_DIR)/lexer.o -c $(SRC_DIR)/lexer.cpp $(COMPILER_ARGS)

main.o: $(SRC_DIR)/main.cpp
	g++ -o $(OUTPUT_DIR)/main.o -c $(SRC_DIR)/main.cpp $(COMPILER_ARGS)

queue.o: $(SRC_DIR)/queue.cpp
	g++ -o $(OUTPUT_DIR)/queue.o -c $(SRC_DIR)/queue.cpp $(COMPILER_ARGS)

location.o: $(SRC_DIR)/location.cpp
	g++ -o $(OUTPUT_DIR)/location.o -c $(SRC_DIR)/location.cpp $(COMPILER_ARGS)
	
token.o: $(SRC_DIR)/token.cpp
	g++ -o $(OUTPUT_DIR)/token.o -c $(SRC_DIR)/token.cpp $(COMPILER_ARGS)

clean:
	rm --force $(OUTPUT_DIR)/*