#ifndef BTREE_H
#define BTREE_H

#include <bits/stdc++.h>
using namespace std;

// // Hash para armazenar o valor na árvore de Huffman
// map<char, string> codes;

// // Hash para armazenar a frequência 
// map<char, int> freq;

// Struct da árvore binária
struct BsTree
{
    char data;             // data
    int freq;             // Atributo da frequencia
    BsTree *left, *right; // Nós da esquerda e direita

    BsTree(char data, int freq){ // Construtor da árvoren de Huffman
        left = right = NULL; // Inicializando como NULL o primeiro nó
        this->data = data; // Armazenando dado
        this->freq = freq; // Atualizando a frequência
    }
};

// Método para comparar os nós da árvore de huffman
struct compare{
    bool operator()(BsTree* left, BsTree* right){
        return (left->freq > right->freq);
    }
};

// Método para printar a árvore de huffman
void printCodes(BsTree* root, string str);

// Método para percorrer a árvore binária
void fillcode(BsTree* root, string str,map<char, string> &codes);

#endif // HUFFMAN_H