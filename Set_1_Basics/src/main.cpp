//
// Created by petar on 4/3/2026.
//
#include "../include/1_hex_to_base64.h"
#include "../include/2_fixed_xor.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;


int main() {
    string hex1 = "1c0111001f010100061a024b53535009181c";
    string hex2 = "686974207468652062756c6c277320657965";


    vector<unsigned char> bytes1 = hexToBytes(hex1);
    vector<unsigned char> bytes2 = hexToBytes(hex2);
    vector<unsigned char> result = xorBuffers(bytes1, bytes2);

    cout << bytesToHexString(result);
    return 0;
}