#ifndef HUFFMAN_H
#define HUFFMAN_H

#include "BTree.h"
#include <bits/stdc++.h>
using namespace std;

#define MAX_TREE_HT 256
#define STR_HISTOGRAM_MAX_TAM   (256)

//Método para preencher a heap
void CodingHeap(int size, priority_queue<BsTree*, vector<BsTree*>, compare> &minHeap, map<char, int> &freq, map<char, string> &codes);

// Método para contar a freqência de bits da string
void CountFreq(string str, int n, map<char, int> &freq);

//Método para decodificar a árvore de Huffman
string DecodingFile(BsTree* root, string s);

// Método para montar a hash de letras da string
void CodingHistograma( string str, int hist[ STR_HISTOGRAM_MAX_TAM ] );

// Método para mostrar o histrograma 
void ShowHistograma( int hist[STR_HISTOGRAM_MAX_TAM], int aux );

#endif // HUFFMAN_H