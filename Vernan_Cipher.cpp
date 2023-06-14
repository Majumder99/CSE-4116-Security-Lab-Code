#include <bits/stdc++.h>
using namespace std;

string vernamEncrypt(string& plaintext, string& key) {
    string ciphertext;
    for (int i = 0; i < plaintext.size(); ++i) {
        char encryptedChar = plaintext[i] ^ key[i % key.size()];
        ciphertext.push_back(encryptedChar);
    }
    return ciphertext;
}

string vernamDecrypt(string& ciphertext, string& key) {
    string plaintext;
    for (int i = 0; i < ciphertext.size(); ++i) {
        char decryptedChar = ciphertext[i] ^ key[i % key.size()];
        plaintext.push_back(decryptedChar);
    }
    return plaintext;
}

int main() {
    string plaintext = "Hello, World!";
    string key = "SecretKey";

    string ciphertext = vernamEncrypt(plaintext, key);
    string decryptedText = vernamDecrypt(ciphertext, key);

    cout << "Plaintext: " << plaintext << endl;
    cout << "Ciphertext: " << ciphertext << endl;
    cout << "Decrypted Text: " << decryptedText << endl;

    return 0;
}
