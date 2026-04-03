#include <string>
#include <iostream>
#include <vector>
#include "../include/1_hex_to_base64.h"

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

std::string bytesToChar(const std::vector<unsigned char>& bytes) {
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
    result = bytesToChar(bytes);
    return result;

}
