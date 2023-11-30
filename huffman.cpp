#include <bits/stdc++.h>

// binary tree each character its huffman value
map<char, string> codes;

// store the frequency of character of the input data
map<char, int> freq;

// A Huffman binary search tree node
struct BsTree
{
    char data;             // fill the data
    int freq;             // presence of each caractther
    BsTree *left, *right; // Node to left and right

    BsTree(char data, int freq){
        left = right = NULL; // Made a NULL initial node
        this->data = data; // storage data
        this->freq = freq; //uptading the frequence
    }
};

// important function to use in bstree
struct compare{
    bool operator()(BsTree* left, BsTree* right){
        return (left->freq > right->freq);
    }
};

// function to filll the bstree acording the letter
void fillcode(struct BsTree* root, string str){
    if (root == NULL){
        return;
    }
    if (root->data != '$'){
        codes[root->data]=str;
    }
    fillcode(root->left, str + "0");
    fillcode(root->right, str + "1");
}

