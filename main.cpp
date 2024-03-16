// Programa em C++ para a codificação de Huffman
#include <bits/stdc++.h>
#include "src/huffman.h"
#include "src/BTree.h"

using namespace std;

// Hash para armazenar o valor na árvore de Huffman
map<char, string> codes;

// Hash para armazenar a frequência 
map<char, int> freq;

// Heap com os bits da arvore de Huffman
priority_queue<BsTree*, vector<BsTree*>, compare> minHeap;


int main(int argc, char *argv[]){

    string in = "";

    for (int i = 1; i < argc; i++){
        if (strcmp(argv[i], "-h") == 0){
            cout << "Help:" << endl;
            cout << "-h: mostra o help" << endl;
            cout << "-f <arquivo>: indica o 'arquivo' que contém a string de entrada" << endl;  
            return 0;
        }
        else if (strcmp(argv[i], "-f") == 0 and i < argc - 1){
            in = argv[++i];
        }
    }

    if (in == ""){
        cerr << "Nenhum arquivo especificado. Use -f como parametro." << endl;
        return 1;
    }


    ifstream fin(in);

    if (not fin){
        cerr << "Nao foi possivel abrir o arquivo: " << in << endl;
        return 1;
    }


    string str;

    stringstream buffer;
    buffer << fin.rdbuf();
    str = buffer.str();

    fin.close();
    cout <<"====================== ALGORITMO DE COMPACTAÇÃO DE HUFFMAN =====================" <<"\n\n";
    cout <<"====================== FRASE ESCRITA =====================" <<"\n\n";
    cout << str;

    cout << "\n\n" <<"====================== FREQUENCIA DOS CARACTERES =====================" <<"\n\n";
    int h[ STR_HISTOGRAM_MAX_TAM ];
    CodingHistograma( str, h );
    ShowHistograma( h, 1 );


    cout << "\n\n" << "====================== CODIGO DE CADA CARACTERE =====================" <<"\n\n";
    string encodedString, decodedString;
    CountFreq(str, str.length(), freq);
    CodingHeap(str.length(),minHeap, freq, codes);


    cout << "\n\n" << "====================== CODIGO NOVO DE CADA CARACTERE =====================" <<"\n\n";
    for (auto v=codes.begin(); v!=codes.end(); v++)
        cout << "[" << v->first << "]" <<" : " << v->second << endl;

    for (auto i: str)
        encodedString+=codes[i];

   cout << "\n\n" << "====================== DADOS CRIPTOGRAFADOS NO HUFFMAN =====================" <<"\n\n" << encodedString << endl;

    decodedString = DecodingFile(minHeap.top(), encodedString);

    ofstream fout("data/encode.huff");
    if (not fout){
        cerr << "Nao foi possivel abrir o arquivo: data/encode.huff" <<  endl;
        return 1;
    }
        
    cout << "\nArmazenando a codificacao em: data/encode.huff" << endl;
    
    for (auto i: encodedString)
        fout << i;

    fout.close();

    cout << "\n" << "====================== DADOS DESCRIPTOGRAFADOS NO HUFFMAN =====================" <<"\n\n" << decodedString << "\n\n";

    return 0;
}