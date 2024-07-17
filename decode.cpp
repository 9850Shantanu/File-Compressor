#include <bits/stdc++.h>
#include "huffman.hpp"
using namespace std;
int main(int argc, char const *argv[])
{
    if (argc != 3)
    {
        cout << "Enter File names : compressedFile.huf output.txt while executing";
        return 1;
    }
    Huffman f(argv[1], argv[2]);
    f.decompress();
    cout << "File Decompressed SuccessFully. Check if it is same as original input file." << endl;
    return 0;
}
