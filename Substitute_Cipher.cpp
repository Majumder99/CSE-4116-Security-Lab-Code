#include<bits/stdc++.h>
using namespace std;

string encryptSubstitution( string& message, string& key)
{
    string encryptedMessage = message;
    for (char& ch : encryptedMessage)
    {
        if (isalpha(ch))
        {
            // Convert the character to uppercase
            ch = toupper(ch);
            // Apply the substitution
            ch = key[ch - 'A'];
        }
    }
    return encryptedMessage;
}

string decryptSubstitution( string& encryptedMessage, string& key)
{
    string decryptedMessage = encryptedMessage;
    for (char& ch : decryptedMessage)
    {
        if (isalpha(ch))
        {
            // Convert the character to uppercase
            ch = toupper(ch);
            // Reverse the substitution to obtain the original letter
            ch = 'A' + key.find(ch);
        }
    }
    return decryptedMessage;
}

int main()
{
    string message = "HELLO, WORLD!";
    string key = "ZYXWVUTSRQPONMLKJIHGFEDCBA";

    string encrypted = encryptSubstitution(message, key);
    cout << "Encrypted message: " << encrypted << endl;

    string decrypted = decryptSubstitution(encrypted, key);
    cout << "Decrypted message: " << decrypted << endl;

    return 0;
}
