#include "BTree.h"
#include <bits/stdc++.h>
using namespace std;


// Método para printar a árvore de huffman
void printCodes(BsTree* root, string str)
{
    if (!root)
        return;
    if (root->data != '$')
        cout <<"[" <<root->data << "]: " << str << "\n";
    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}

// Método para preencher inicialmente a árvore de huffman
void fillcode(BsTree* root, string str, map<char, string> &codes){
    if (root == NULL){
        return;
    }
    if (root->data != '$'){
        codes[root->data]=str;
    }
    fillcode(root->left, str + "0", codes);
    fillcode(root->right, str + "1", codes);
}