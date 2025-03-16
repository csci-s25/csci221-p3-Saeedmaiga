#include "vigenere.h"
#include <fstream>
#include <iostream>
#include <cctype>

using namespace std;

// Function to format the key to match the plaintext length
string formatKey(string text, string key) {
    string formattedKey;
    int keyIndex = 0;      
    int keyLength = key.length();

    for (char c : text) {  
        if (isalpha(c)) {  
            formattedKey += toupper(key[keyIndex % keyLength]); // Convert to uppercase
            keyIndex++;     
        } else {
            formattedKey += c; // Preserve spaces & punctuation
        }
    }
    return formattedKey;   
}

// Function to encrypt plaintext using Vigenere Cipher
string encryptVigenere(string plaintext, string key) {
    string ciphertext;
    string formattedKey = formatKey(plaintext, key);

    for (size_t i = 0; i < plaintext.length(); i++) {
        char pt = plaintext[i];

        if (isalpha(pt)) {
            int shift = toupper(formattedKey[i]) - 'A';
            char base = isupper(pt) ? 'A' : 'a';
            char encryptedChar = ((pt - base + shift) % 26) + base;
            ciphertext += encryptedChar;
        } else {
            ciphertext += pt;
        }
    }
    return ciphertext;
}

// Function to decrypt ciphertext using Vigenere Cipher
string decryptVigenere(string ciphertext, string key) {
    string plaintext;
    string formattedKey = formatKey(ciphertext, key);

    for (size_t i = 0; i < ciphertext.length(); i++) {
        char ct = ciphertext[i];

        if (isalpha(ct)) {
            int shift = toupper(formattedKey[i]) - 'A';
            char base = isupper(ct) ? 'A' : 'a';
            char decryptedChar = ((ct - base - shift + 26) % 26) + base;
            plaintext += decryptedChar;
        } else {
            plaintext += ct;
        }
    }
    return plaintext;
}

// Function to read a file
string readFile(string filename) {
    ifstream file(filename, ios::binary); // Open in binary mode for ciphertext
    if (!file) {
        cerr << "Error: Unable to open file " << filename << endl;
        return "";
    }

    string content((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    file.close();
    return content;
}

// Function to write to a file
void writeFile(string filename, string content, bool binary) {
    ofstream file;
    
    if (binary) {
        file.open(filename, ios::binary);
        file.write(content.c_str(), content.size()); // Writing raw binary
    } else {
        file.open(filename);
        file << content;
    }

    if (!file) {
        cerr << "Error: Could not open file for writing." << endl;
    }

    file.close();
}