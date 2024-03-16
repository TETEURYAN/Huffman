#include "huffman.h"
#include <bits/stdc++.h>
using namespace std;

void CodingHeap(int size, priority_queue<BsTree*, vector<BsTree*>, compare> &minHeap, map<char, int> &freq, map<char, string> &codes)
{
    struct BsTree *left, *right, *top;
    for (map<char, int>::iterator v=freq.begin(); v!=freq.end(); v++)
        minHeap.push(new BsTree(v->first, v->second));

    while (minHeap.size() != 1)
    {
        left = minHeap.top();
        minHeap.pop();
        right = minHeap.top();
        minHeap.pop();
        top = new BsTree('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        minHeap.push(top);
    }
    fillcode(minHeap.top(), "", codes);
    printCodes(minHeap.top(), "");
}


void CountFreq(string str, int n, map<char, int> &freq)
{
    for (int i=0; i<str.size(); i++)
        freq[str[i]]++;
}

string DecodingFile(BsTree* root, string s)
{
    string ans = "";
    BsTree* curr = root;
    for (int i=0;i<s.size();i++)
    {
        if (s[i] == '0') curr = curr->left;
        else curr = curr->right;

        // Encontrou a folha
        if (curr->left==NULL and curr->right==NULL)
        {
            ans += curr->data;
            curr = root;
        }
    }
    return ans+'\0';
}

void CodingHistograma( string str, int hist[ STR_HISTOGRAM_MAX_TAM ] )
{
    memset( hist, 0, sizeof(int) * STR_HISTOGRAM_MAX_TAM );

    for (int i=0; i<str.size(); i++)
        hist[ str[i] ]++;
}

void ShowHistograma( int hist[STR_HISTOGRAM_MAX_TAM], int aux )
{
    for(int i = 0; i < STR_HISTOGRAM_MAX_TAM; i++ )
    {
        if( (isprint(i)) && (hist[i] >= aux) )
        {
           cout <<"[" << (char)i << "] : " << hist[i];
           cout << "\n";
        }
    }
}