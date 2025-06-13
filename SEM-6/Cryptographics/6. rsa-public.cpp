#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

bool is_prime(int n) {
    if (n < 2) return false;
    if (n < 4) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}

int generate_prime(int min_val = 100, int max_val = 300) {
    while (true) {
        int p = min_val + rand() % (max_val - min_val);
        if (is_prime(p)) return p;
    }
}

int mod_inverse(int e, int phi) {
    int a = e, b = phi, x0 = 1, x1 = 0;
    while (b) {
        int q = a / b, temp = b;
        b = a % b, a = temp;
        temp = x1;
        x1 = x0 - q * x1, x0 = temp;
    }
    return (x0 + phi) % phi;
}

int mod_exp(int base, int exp, int mod) {
    int result = 1;
    while (exp) {
        if (exp % 2) result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

void generate_keys(pair<int, int>& pub, pair<int, int>& priv) {
    int p = generate_prime(), q;
    do { q = generate_prime(); } while (q == p);
    int n = p * q, phi = (p - 1) * (q - 1), e = 2 + rand() % (phi - 2);
    while (gcd(e, phi) != 1) e = 2 + rand() % (phi - 2);
    pub = {e, n}, priv = {mod_inverse(e, phi), n};
}

vector<int> encrypt(const string& text, pair<int, int> pub) {
    vector<int> cipher;
    for (char ch : text) cipher.push_back(mod_exp(ch, pub.first, pub.second));
    return cipher;
}

string decrypt(const vector<int>& cipher, pair<int, int> priv) {
    string text;
    for (int val : cipher) text += char(mod_exp(val, priv.first, priv.second));
    return text;
}

int main() {
    srand(time(0));
    pair<int, int> pub, priv;
    generate_keys(pub, priv);
    
    cout << "RSA Key Generation\n";
    cout << "Public Key (e, n): (" << pub.first << ", " << pub.second << ")\n";
    cout << "Private Key (d, n): (" << priv.first << ", " << priv.second << ")\n";

    cout << "\nEnter a message to encrypt: ";
    string message;
    getline(cin, message);


    vector<int> encrypted = encrypt(message, pub);
    cout << "\nEncrypted: ";
    for (int val : encrypted) cout << val << " ";

    cout << "\nDecrypted: " << decrypt(encrypted, priv) << "\n";
    return 0;
}


// RSA Key Generation
// Public Key (e, n): (14737, 31831)
// Private Key (d, n): (28033, 31831)

// Enter a message to encrypt: I'm Death

// Encrypted: 3012 8678 5161 10526 27235 13370 10383 28586 22255
// Decrypted: I'm Death