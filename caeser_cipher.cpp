#include <bits/stdc++.h>
using namespace std;

string encryption(string plaintext, int shifter){
    
    string ans = "";
    for(char ch:plaintext){
        if(isalpha(ch)){
            char start = islower(ch) ? 'a': 'A';
            char result = start + ((ch - start + shifter )%26);
            ans += result;
        }
        else if(ch == ' '){
            ans += ' ';
        }
        else{
            ans += ch;
        }
    }
    return ans;
}

string decryption(string ciphertext, int shifter){
    return encryption(ciphertext, 26-shifter);
}


int main(){

    int shifter = 3;

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    string plaintext;
    getline(cin ,plaintext);
    // cout<<plaintext<<endl;
    // cout << "Plaintext: " << plaintext << endl;
    string ciphertext = encryption(plaintext, shifter);
    cout << "Ciphertext: " << ciphertext << endl;

    string decrypted = decryption(ciphertext, shifter);
    cout << "Decrypted: " << decrypted << endl;
    // return 0;
}