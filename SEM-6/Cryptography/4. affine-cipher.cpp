#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int modInv(int a, int m) {
    for (int x = 1; x < m; ++x) if ((a * x) % m == 1) return x;
    return -1;
}

string affine(string text, int a, int b, char mode) {
    string res = "";
    int a_inv = (mode == 'd') ? modInv(a, 26) : 0;
    if (mode == 'd' && a_inv == -1) return "Invalid 'a' (no inverse).";
    for (char c : text) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            int x = c - base;
            int v = (mode == 'e') ? (a * x + b) % 26 : (a_inv * (x - b + 26)) % 26;
            res += char(v + base);
        } else res += c;
    }
    return res;
}

int main() {
    string text; int a, b; char mode;
    cout << "Message: "; getline(cin, text);
    cout << "Key a (coprime with 26): "; cin >> a;
    cout << "Key b: "; cin >> b;
    cout << "Mode (e/d): "; cin >> mode;
    cout << "\nResult: " << affine(text, a, b, tolower(mode)) << endl;
}

// PS S:\WorkSpace\Academics\SEM-6\Cryptographics> ./a
// Message: Do you like this world
// Key a (coprime with 26): 9
// Key b: 6
// Mode (e/d): e

// Result: Hc oce basq vram wcdbh

// PS S:\WorkSpace\Academics\SEM-6\Cryptographics> ./a
// Message: Hc oce basq vram wcdbh
// Key a (coprime with 26): 9
// Key b: 6
// Mode (e/d): d

// Result: Do you like this world