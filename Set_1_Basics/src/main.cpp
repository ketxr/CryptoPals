//
// Created by petar on 4/3/2026.
//
#include "../include/1_hex_to_base64.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;


int main() {
    string hex = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d";
    vector<unsigned char> bytes = hexToBytes(hex);
    cout<<bytesToBase64(bytes);
    return 0;
}