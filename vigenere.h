#ifndef VIGENERE_H
#define VIGENERE_H

#include <string>
using namespace std;

// Function prototypes
string encryptVigenere(string plaintext, string key);
string decryptVigenere(string ciphertext, string key);
string readFile(string filename);
void writeFile(string filename, string content, bool binary);
string formatKey(string text, string key);

#endif

