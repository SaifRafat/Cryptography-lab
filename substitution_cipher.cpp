
#include<iostream>
#include<map>
using namespace std; 

string all_chars = "abcdefghijklmnopqrstuvwxyz"
                       "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; // define all letters
    

string encryption(string plaintext, int key)
{
    
    map<char, char> dict1;
    int len = all_chars.length();

    for(int i = 0; i <len; i++)
    {
        dict1[all_chars[i]] = all_chars[(i+key) % len]; // add key value with all elemets of all_chars
    }

    string ciphertext = "";
    for(char ch : plaintext)
    {
        if(dict1.find(ch) != dict1.end()) //match corresponding letter from plaintext with the dictionary
        {
            ciphertext += dict1[ch];
        }
        else
        {
            ciphertext += ch;
        }
    }
    return ciphertext;
}

string decryption(string ciphertext, int key)
{
    
    map<char, char> dict2;
    int len = all_chars.length();

    for(int i = 0; i <len; i++)
    {
        dict2[all_chars[i]] = all_chars[(i-key+len) % len];
    }

    string decryptedtext = "";
    for(char ch : ciphertext)
    {
        if(dict2.find(ch) != dict2.end())
        {
            decryptedtext += dict2[ch];
        }
        else
        {
            decryptedtext += ch;
        }
    }
    return decryptedtext;
}

int main()
{
    string plaintext = "I am studying Data Encryption";
    string ciphertext = encryption(plaintext, 3);
    cout << ciphertext << endl;
    string decryptedtext = decryption(ciphertext,3);
    cout << decryptedtext << endl;
}