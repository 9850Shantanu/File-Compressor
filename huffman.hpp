#ifndef HUFFMAN_HPP
#define HUFFMAN_HPP
#include <bits/stdc++.h>
using namespace std;

// Node of Huffman Tree
class Node
{
public:
    char data;
    unsigned int frequency;
    string code; // Huffman Code;
    Node *left, *right;
    Node()
    {
        left = right = NULL;
    }
};

class Huffman
{
    vector<Node *> arr; // List of Nodes

    fstream inFile, outFile; // Declaring input and output streams

    string inFileName, outFileName; // Declaring input and output file name

    Node *root; // Root of huffman Tree, It value is totalfreq

    class Compare
    {
    public:
        bool operator()(Node *le, Node *ri)
        {
            return le->frequency > ri->frequency;
        }
    };

    priority_queue<Node *, vector<Node *>, Compare> heap; // Heap DS to store generate huffman tree, using optimal merge pattern

    void createFreqArray();
    // Initialize a vector of treeNodes with ASCII value and its frequency.

    void generateCode(Node *, string);
    // Generate huffman codes of each character by traversing the huffman tree

    void buildTree(char, string &);
    // Construction tree again while decoding the File

    void createMinHeap();
    // Create a minHeap of Nodes by frequency, which will be used for optimal merge pattern and generating tree.

    void createTree();
    // Constructing the Huffman Tree using minHeap, while encoding file

    void createCodes();
    // Traverse the huffman tree and assign codes to each character

    int binaryToDecimal(string);
    // Convert binary string to its equivalent decimal

    string decimalToBinary(int);
    // Convert decimal number to its equivalent binary string.

    void saveEncodedFile();
    // Saving Huffman Encoded File.

    void getTreeFromEncodedFile();
    // Read encoded file and generate the huffman tree again for decoding

    void saveDecodedFile();
    // Saving Decoded file to get original file.

public:
    Huffman(string inFileName, string outFileName)
    {
        this->inFileName = inFileName;
        this->outFileName = outFileName;
        createFreqArray();
    }

    void compress();   // compressing input file
    void decompress(); // decompressing input file
};
#endif