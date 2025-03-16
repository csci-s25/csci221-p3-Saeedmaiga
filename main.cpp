#include "vigenere.h"
#include <iostream>
#include <unistd.h> 

using namespace std;

int main(int argc, char** argv) {
    char opt;
    string inputFile;
    string outputFile;
    int eflag = 0, dflag = 0, iflag = 0, oflag = 0;

    // Parsing command-line arguments
    while ((opt = getopt(argc, argv, "i:o:ed")) != -1) {
        switch (opt) {
            case 'i':
                iflag = 1;
                inputFile = optarg;
                break;
            case 'o':
                oflag = 1;
                outputFile = optarg;
                break;
            case 'e':
                eflag = 1;
                break;
            case 'd':
                dflag = 1;
                break;
            default:
                cout << "Unknown option" << endl;
                return 1;
        }
    }

    // Validate input parameters
    if (argc != 6 || iflag == 0 || oflag == 0 || (eflag == dflag)) {
        cout << "Error: Invalid arguments!" << endl;
        cout << "Usage: " << argv[0] << " -i inputFile -o outputFile -e|-d" << endl;
        return 1;
    }

    // Read input file
    string text = readFile(inputFile);
    string key;

    cout << "Please enter the keyword: ";
    cin >> key;

    // Ensure the key contains only letters
    for (char c : key) {
        if (!isalpha(c)) {
            cerr << "Error: Keyword must contain only letters." << endl;
            return 1;
        }
    }

    string result;
    if (eflag) {
        result = encryptVigenere(text, key);
        writeFile(outputFile, result, true);  // Write as binary file
        cout << "Encrypted ciphertext binary file created: " << outputFile << endl;
    } else if (dflag) {
        result = decryptVigenere(text, key);
        writeFile(outputFile, result, false); // Write as text file
        cout << "Decrypted plaintext file created: " << outputFile << endl;
    }

    return 0;
}

