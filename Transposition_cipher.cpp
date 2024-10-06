#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string encrypt(string plaintext, int width)
{
    string ciphertext = "";

    int trailing_space = width - plaintext.size() % width;
    // cout << trailing_space << endl;

    for(int i = 0; i < trailing_space; i++)
    {
        plaintext += ' ';
        // cout << plaintext << endl;
    }

    for(int i = 0; i< width; i++)
    {
        for (int j = i; j < plaintext.length(); j += width)
        {
            ciphertext += plaintext[j];
        }
    }
    return ciphertext;
}

string decrypt(string ciphertext, int width)
{
    string decrypted_text = "";

    int rows = ceil((double)ciphertext.size() / width);
    // cout << ciphertext.size() << endl;
    for(int i = 0 ; i < rows; i++)
    {
        for (int j = i; j < ciphertext.size(); j += rows)
        {
            decrypted_text += ciphertext[j];
            // cout << decrypted_text << endl;
        }
        // cout<< decrypted_text << endl;
    }
    int count = 0;
    for (int i = decrypted_text.size() - 1; i >= 0; i--)
    {
        if(decrypted_text[i] == ' ') count++;
        else break;
    }

    decrypted_text = decrypted_text.substr(0, decrypted_text.size() - count);
    return decrypted_text;
}

int main()
{
    string plaintext= "RAJSHAHI BANGLADESH";
    // cout << plaintext.size() << endl;
    int width = 3 ;

    string ciphertext = encrypt(plaintext, width);
    cout << ciphertext << endl;

    string decrypted_text = decrypt(ciphertext, width);
    cout << decrypted_text << endl;
}
