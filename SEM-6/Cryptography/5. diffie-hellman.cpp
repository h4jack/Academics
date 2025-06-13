#include <iostream>
using namespace std;

long long mod_exp(long long base, long long exp, long long mod) {
    long long res = 1;
    base %= mod;
    while (exp) {
        if (exp & 1) res = res * base % mod;
        base = base * base % mod;
        exp >>= 1;
    }
    return res;
}

int main() {
    long long p, g, a, b;
    cout << "Prime p: "; cin >> p;
    cout << "Primitive root g: "; cin >> g;
    cout << "Alice's private key: "; cin >> a;
    cout << "Bob's private key: "; cin >> b;

    long long A = mod_exp(g, a, p);
    long long B = mod_exp(g, b, p);
    long long s1 = mod_exp(B, a, p);
    long long s2 = mod_exp(A, b, p);

    cout << "\nAlice's Public Key: " << A
         << "\nBob's Public Key: " << B
         << "\nAlice's Shared Secret: " << s1
         << "\nBob's Shared Secret: " << s2
         << "\n" << (s1 == s2 ? "Key Match!" : "Mismatch!") << endl;

    return 0;
}

// PS S:\WorkSpace\Academics\SEM-6\Cryptographics> ./a
// Prime p: 103 
// Primitive root g: 3
// Alice's private key: 6
// Bob's private key: 2

// Alice's Public Key: 8
// Bob's Public Key: 9
// Alice's Shared Secret: 64
// Bob's Shared Secret: 64
// Key Match!