#include <iostream>
using namespace std;

string caesar_cipher(string text, int shift, char mode = 'c') {
    string result = "";
    if(mode == 'd') shift = -shift;
    for(auto c : text)
        if(isalpha(c)){
            int base = 65;
            if(islower(c)){
                base = 97;
            }
            result += char((int(c) - base + shift) % 26 + base);
        }else result += c;
    return result;
}

int main(){
    string text;
    int shift;
    char mode;
    cout << "Enter your message: ";
    cin >> text;
    cout << "Enter shift value (e.g., 3): ";
    cin >> shift;
    cout << "Enter Encryption or Decryption mode as ('e' or 'd'): ";
    cin >> mode;
    cout << caesar_cipher(text, shift, tolower(mode));
    return 0;
}