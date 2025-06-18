#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

string pbox_encrypt(const string &message, const vector<int> &pbox) {
    int size = pbox.size();
    string padded = message + string((size - message.length() % size) % size, ' ');
    string encrypted = padded;

    for (size_t i = 0; i < padded.length(); i += size)
        for (int j = 0; j < size; ++j)
            encrypted[i + j] = padded[i + pbox[j]];

    return encrypted;
}

string pbox_decrypt(const string &ciphertext, const vector<int> &pbox) {
    int size = pbox.size();
    vector<int> inverse(size);
    for (int i = 0; i < size; ++i) inverse[pbox[i]] = i;

    string decrypted = ciphertext;
    for (size_t i = 0; i < ciphertext.length(); i += size)
        for (int j = 0; j < size; ++j)
            decrypted[i + j] = ciphertext[i + inverse[j]];

    return decrypted;
}

int main() {
    string message;
    vector<int> pbox;

    cout << "Enter the message: ";
    getline(cin, message);

    cout << "Enter P-box (0-based, space-separated): ";
    string pbox_input;
    getline(cin, pbox_input);
    istringstream iss(pbox_input);
    int index;

    while (iss >> index) pbox.push_back(index);

    if (pbox.empty()) {
        cout << "Error: P-box cannot be empty!\n";
        return 1;
    }

    string encrypted = pbox_encrypt(message, pbox);
    string decrypted = pbox_decrypt(encrypted, pbox);

    cout << "\nEncrypted: '" << encrypted << "'\n";
    cout << "Decrypted: '" << decrypted << "'\n";

    return 0;
}

// PS S:\WorkSpace\Academics\SEM-6\Cryptographics> g++ '.\7. pbox.cpp'
// PS S:\WorkSpace\Academics\SEM-6\Cryptographics> ./a
// Enter the message: Internal Pointer Variable
// Enter P-box (0-based, space-separated): 4 2 3 0 1

// Encrypted: 'rteInPl naentoirVar eblia'
// Decrypted: 'Internal Pointer Variable'