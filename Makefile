OBJ = main.cpp
HUFFMAN = ./src/huffman.cpp
BINARYTREE = ./src/BTree.cpp



HUFFMANPATH = ./src/huffman.h
BINARYTREEPATH = ./src/BTree.h


FLAG = 

all:  clean create build run fill

clean:
	rm -rf bin

create:
	mkdir bin

build:
	g++ -o bin/huffman.bin $(OBJ) $(HUFFMAN) $(BINARYTREE) $(HUFFMANPATH) $(BINARYTREEPATH) $(FLAG)

run: 
	./bin/huffman.bin -f data/decode.huff

fill:
	rm bin/huffman