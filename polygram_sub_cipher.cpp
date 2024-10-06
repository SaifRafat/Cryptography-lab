#include<bits/stdc++.h>
using namespace std;

map<string, string> en_dict, dec_dict;

void create_dict()
{
    string w1,w2;
    ifstream dict_file("dictionary.txt");
    while (dict_file >> w1 >> w2)
    {
        en_dict[w1] = w2;
        dec_dict[w2] = w1;
    }
    dict_file.close();
    
}

string encryption(string plaintext)
{

    
    string ans = "";
    string tmp = "";
    // cout<<plaintext.size()<<endl;
    for (int i = 0; i < plaintext.size(); i++)
    {
        if(isalpha(plaintext[i]))
        {
            tmp += plaintext[i];
            // cout << tmp << endl;
    
            if(en_dict.find(tmp) != en_dict.end())
            {
                ans += en_dict[tmp];
                tmp = "";
            }
        }
        else
        {
            ans += plaintext[i];
        }
       
    }

    return ans;
}

string decryption(string ciphertext)
{
    string ans = "";
    string tmp = "";
    for (int i = 0; i < ciphertext.size(); i++)
    {
        if(isalpha(ciphertext[i]))
        {
            tmp += ciphertext[i];
            if(dec_dict.find(tmp) != dec_dict.end())
            {
                ans += dec_dict[tmp];
                tmp = "";
            }
        }
        else
        {
            ans += ciphertext[i];
        }
    }

    return ans;
}

int main(){
    string plaintext;
    string ciphertext;

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    
    

    getline(cin, plaintext);
    cin.clear();
    create_dict();
    ciphertext = encryption(plaintext);
    cout << "CipherText : " << ciphertext << endl;
    cout << "Decrypted : " << decryption(ciphertext) << endl;
}



