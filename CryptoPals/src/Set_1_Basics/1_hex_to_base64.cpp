#include <string>
#include <iostream>
#include <vector>
#include "../../include/Set_1_Basics/1_hex_to_base64.h"

using namespace std;

vector<unsigned char> hexStringToBytes(const string& hexString){
    vector<unsigned char> bytes;

    for(int i=0; i<hexString.length(); i+=2){
        unsigned char byte = (unsigned char) stoi(hexString.substr(i,2),nullptr, 16);
        bytes.push_back(byte);
    }
    return bytes;
}

string bytesToHexString(const vector<unsigned char>& bytes) {
    string result;
    const string hexChars = "0123456789abcdef";
    for (int i = 0; i < bytes.size(); i++) {
        result.push_back(hexChars[bytes[i]>>4]);
        result.push_back(hexChars[bytes[i]&0x0F]);
    }
    return result;
}

std::string stringifyByteArray(const std::vector<unsigned char>& bytes) {
    std::string result;
    for (unsigned char byte : bytes) {
        result.push_back(byte);
    }
    return result;
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

std::string hexStringToChar(const std::string& hexString) {
    string result;
    auto bytes= hexStringToBytes(hexString);
    result = stringifyByteArray(bytes);
    return result;

}

vector<unsigned char> textStringToBytes(const string& textString) {
    vector<unsigned char> bytes;

    for(int i=0; i<textString.length(); i++){
        unsigned char byte = (unsigned char) textString[i];
        bytes.push_back(byte);
    }
    return bytes;
}

vector<unsigned char> base64ToBytes(const string& base64String) {
    std::vector<unsigned char> out;
    std::vector<int> T(256, -1);
    const char* chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    for (int i = 0; i < 64; i++) T[chars[i]] = i;

    int val = 0, valb = -8;
    for (unsigned char c : base64String) {
        if (T[c] == -1) break; // End at first non-base64 char (like padding '=')
        val = (val << 6) + T[c];
        valb += 6;
        if (valb >= 0) {
            out.push_back(char((val >> valb) & 0xFF));
            valb -= 8;
        }
    }
    return out;
}
