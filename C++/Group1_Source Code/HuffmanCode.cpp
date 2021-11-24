/*
    HuffmanCode.cpp
    2021-11-23 Denta Bramasta
*/

#include <bits/stdc++.h>
using namespace std;

int codes = 0;
int compressed = 0;
struct MinHeapNode 
{
    char data;
    unsigned int freq;
    MinHeapNode *left, *right;

    MinHeapNode(char data, unsigned int freq)
    {
        this->left = this->right = NULL;
        this->data = data;
        this->freq = freq;
    }
};

struct compare 
{
    bool operator() (MinHeapNode* left, MinHeapNode* right)
    {
        return(left->freq > right->freq);
    }
};

void encode (MinHeapNode* root, string s)
{
    if (!root)
        return;
    if (root->data != '$')
    {
        int currentNodeSize = s.size();
        codes += currentNodeSize;
        compressed += root->freq * currentNodeSize;
        cout << root->data << ": " << s << endl;
    }
    encode(root->left, s + "0");
    encode(root->right, s + "1");
}

void HuffmanCodes (char *data, int *freq, int size)
{
    MinHeapNode *left, *right, *top;
    priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> myMinHeap;
    for (int i = 0; i < size; i++)
        myMinHeap.push(new MinHeapNode(data[i], freq[i]));
    while (myMinHeap.size() != 1)
    {
        left = myMinHeap.top();
        myMinHeap.pop();
        right = myMinHeap.top();
        myMinHeap.pop();

        top = new MinHeapNode('$', left->freq + right->freq);

        top->left = left;
        top->right = right;

        myMinHeap.push(top);
    }
    encode(myMinHeap.top(), "");
}


int main() {
    int size;
    cin >> size;
    
    char arr[size];
    int freq[size];

    char Karakter;
    int Frekuensi;
    int TotalFreq = 0;
    for (int i = 0; i < size; i++)
    {
        cin >> Karakter >> Frekuensi;
        arr[i] = Karakter;

        freq[i] = Frekuensi;
        TotalFreq += Frekuensi;
    }
    cout << "\n" << "****** RESULT ******" << endl;
    HuffmanCodes(arr, freq, size);
    int uncompressed = TotalFreq * 8;
    int TotalCompressed = codes + compressed + (size * 8);
    // cout << uncompressed << endl;
    // cout << codes << endl;
    // cout << TotalCompressed << endl;
    // cout << compressed << endl;
    cout << ((double)TotalCompressed/(double)uncompressed)*100 << "%\n";
    cout << "****** RESULT ******\n" << endl;
    return 0;
}