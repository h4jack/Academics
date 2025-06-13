#include <iostream>
using namespace std;

string caesar(string t, int s, char m = 'e') {
    s%=26;
    if (m == 'd') s = -s;

    for (char &c : t)
        if (isalpha(c)) {
            char base = islower(c) ? 'a' : 'A';
            c = (c - base + s + 26) % 26 + base;
        }
    return t;
}

int main() {
    string text;
    int shift;
    char mode;
    cout << "Message: "; getline(cin, text);
    cout << "Shift: "; cin >> shift;
    cout << "Mode (e/d): "; cin >> mode;
    cout << "\nResult: " << caesar(text, shift, tolower(mode)) << endl;
}

// PS S:\WorkSpace\Academics\SEM-6\Cryptographics> ./a
// Message: Hii Friends
// Shift: 54 
// Mode (e/d): e

// Result: Jkk Htkgpfu

// PS S:\WorkSpace\Academics\SEM-6\Cryptographics> ./a
// Message: Jkk Htkgpfu
// Shift: 54 
// Mode (e/d): d

// Result: Hii Friends