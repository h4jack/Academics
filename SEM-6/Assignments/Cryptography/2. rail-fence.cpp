#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string railEncrypt(const string &text, int rails) {
    vector<string> fence(rails);
    int row = 0, dir = 1;
    for (char ch : text) {
        fence[row] += ch;
        if (row == 0) dir = 1;
        else if (row == rails - 1) dir = -1;
        row += dir;
    }
    string res = "";
    for (auto &r : fence) res += r;
    return res;
}

string railDecrypt(const string &cipher, int rails) {
    vector<int> len(rails, 0);
    int row = 0, dir = 1;
    for (int i = 0; i < cipher.size(); ++i) {
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
    for (int i = 0; i < cipher.size(); ++i) {
        res += rail[row][pos[row]++];
        if (row == 0) dir = 1;
        else if (row == rails - 1) dir = -1;
        row += dir;
    }
    return res;
}

int main() {
    string msg, mode;
    int rails;
    cout << "Message: ";
    getline(cin, msg);
    msg.erase(remove(msg.begin(), msg.end(), ' '), msg.end());
    cout << "Rails: "; cin >> rails;
    cout << "Mode (encrypt/decrypt): "; cin >> mode;

    cout << "\nResult: " << (mode == "encrypt" ? railEncrypt(msg, rails) :
                               mode == "decrypt" ? railDecrypt(msg, rails) : "Invalid mode!") << endl;
    return 0;
}

// PS S:\WorkSpace\Academics\SEM-6\Cryptographics> ./a
// Message: I am Batman
// Rails: 4
// Mode (encrypt/decrypt): encrypt

// Result: ImatamanB

// PS S:\WorkSpace\Academics\SEM-6\Cryptographics> ./a
// Message: ImatamanB
// Rails: 4
// Mode (encrypt/decrypt): decrypt

// Result: IamBatman