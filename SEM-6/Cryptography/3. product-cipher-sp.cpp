#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string caesar(const string &text, int shift) {
    string res = "";
    for (char ch : text)
        res += isalpha(ch) ? (char)((ch - (isupper(ch) ? 'A' : 'a') + shift + 26) % 26 + (isupper(ch) ? 'A' : 'a')) : ch;
    return res;
}

string railEncrypt(const string &text, int rails) {
    vector<string> rail(rails);
    int row = 0, dir = 1;
    for (char ch : text) {
        rail[row] += ch;
        if (row == 0) dir = 1;
        else if (row == rails - 1) dir = -1;
        row += dir;
    }
    string res = "";
    for (auto &r : rail) res += r;
    return res;
}

string railDecrypt(const string &cipher, int rails) {
    vector<int> len(rails, 0);
    int row = 0, dir = 1, n = cipher.size();

    for (int i = 0; i < n; ++i) {
        len[row]++;
        if (row == 0) dir = 1;
        else if (row == rails - 1) dir = -1;
        row += dir;
    }

    vector<string> rail(rails);
    int idx = 0;
    for (int r = 0; r < rails; ++r) {
        rail[r] = cipher.substr(idx, len[r]);
        idx += len[r];
    }

    string res = "";
    row = 0, dir = 1;
    vector<int> pos(rails, 0);
    for (int i = 0; i < n; ++i) {
        res += rail[row][pos[row]++];
        if (row == 0) dir = 1;
        else if (row == rails - 1) dir = -1;
        row += dir;
    }
    return res;
}

int main() {
    string mode, msg, res;
    int shift, rails;
    cout << "Mode (encrypt/decrypt): "; cin >> mode; cin.ignore();
    cout << "Message: "; getline(cin, msg);
    cout << "Shift: "; cin >> shift;
    cout << "Rails: "; cin >> rails;
    msg.erase(remove(msg.begin(), msg.end(), ' '), msg.end());

    if (mode == "encrypt")
        res = railEncrypt(caesar(msg, shift), rails);
    else if (mode == "decrypt")
        res = caesar(railDecrypt(msg, rails), -shift);
    else
        res = "Invalid mode!";
    
    cout << "\nResult: " << res << endl;
}


// PS S:\WorkSpace\Academics\SEM-6\Cryptographics> ./a
// Mode (encrypt/decrypt): encrypt
// Message: Hello World
// Shift: 23
// Rails: 7

// Result: EbiialiTol

// PS S:\WorkSpace\Academics\SEM-6\Cryptographics> ./a
// Mode (encrypt/decrypt): decrypt
// Message: EbiialiTol
// Shift: 23
// Rails: 7

// Result: HelloWorld