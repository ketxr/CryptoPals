#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<unsigned char> hexToBytes(const string& hexString){
    vector<unsigned char> bytes;

    for(int i=0; i<hexString.length(); i+=2){
        unsigned char byte = (unsigned char) stoi(hexString.substr(i,2),nullptr, 16);
        bytes.push_back(byte);
    }
    return bytes;
}

string bytesToBase64(const vector<unsigned char>& bytes){
    const string base64_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    string result;
    for(int i =0; i < bytes.size(); i+=3){
        unsigned char b0 = bytes[i];
        unsigned char b1 = (i + 1 < bytes.size()) ? bytes[i+1] : 0;
        unsigned char b2 = (i + 2 < bytes.size()) ? bytes[i+2] : 0;

        int triple = (b0 << 16) | (b1 << 8) | b2;

        int c0 = (triple >> 18) & 0x3F;
        int c1 = (triple >> 12) & 0x3F;
        int c2 = (triple >> 6) & 0x3F;
        int c3 = triple & 0x3F;

        result.push_back(base64_chars[c0]);
        result.push_back(base64_chars[c1]);

        if (i + 1 < bytes.size())
            result.push_back(base64_chars[c2]);
        else
            result.push_back('=');

        if (i + 2 < bytes.size())
            result.push_back(base64_chars[c3]);
        else
            result.push_back('=');
   }
   return result;
}
int main(){

    string hex = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d";
    vector<unsigned char> bytes = hexToBytes(hex);
    cout<<bytesToBase64(bytes);
    return 0;
}
