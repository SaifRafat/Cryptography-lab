#include<bits/stdc++.h>
using namespace std;

string encrypt(string plaintext, string key)
{
    string ciphertext = "";

    int cipher[key.length()];

    for (int i = 0; i < key.length() ; i++)
    {
        cipher[i] = plaintext[i] - 'A' + (key[i] - 'A');
    }

    for (int  i = 0; i < key.length() ; i++)
    {
        if(cipher[i] > 25)
        {
            cipher[i] = cipher[i] - 26;
        }

    }

    for (int i = 0; i < key.length() ; i++)
    {
        int x = cipher[i] + 'A';
        ciphertext += x;
    }
    return ciphertext;
}


string decrypt(string ciphertext, string key)
{
    string decrypted_text = "";

    int plain[key.length()];

    for (int i = 0; i < key.length() ; i++)
    {
        plain[i] = ciphertext[i] - 'A' - (key[i] - 'A');
    }

    for (int i = 0; i < key.length() ; i++)
    {
        if (plain[i] < 0)
        {
            plain[i] = plain[i] + 26;
        }
    }

    for (int i = 0; i < key.length() ; i++)
    {
        int x = plain[i] + 'A';
        decrypted_text += x;
    }
    return decrypted_text;
}

int main()
{
    string plaintext = "ONETIMEPAD";
    string key = "TBFRGFARFM";

    for (int i = 0; i < plaintext.length() ; i++)
    {
        plaintext[i] = toupper(plaintext[i]);
    }

    for (int i = 0; i < key.length(); i++)
    {
        key[i] = toupper(key[i]);
    }
    
    string ciphertext = encrypt(plaintext, key);
    cout << ciphertext << endl;
    cout << decrypt(ciphertext, key) << endl;
    
}