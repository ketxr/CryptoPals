//
// Created by petar on 4/3/2026.
//
#include "../include/4_find_string_from_file.h"

#include <iostream>
#include <fstream>

#include "../include/1_hex_to_base64.h"
#include "../include/2_fixed_xor.h"
#include "../include/3_single_xor_cipher.h"
using namespace std;

void findSentenceInFile(std::string fileName) {
    std::ifstream file("../Set_1_Basics/files/"+fileName);
    if (!file.is_open()) {
        std::cout << "File not found" << std::endl;
        return;
    }
    std::string s;

    double max = -1e9;
    unsigned char finalKey;
    string finalString;
    while (file>>s) {
        auto [key, result] = findKey(s);

        if (result>max) {
            finalKey = key;
            max = result;
            finalString = s;
        }

    }
    //create bytes out of the target string
    auto bytes = hexStringToBytes(finalString);

    //create one byte repeating key
    vector<unsigned char> byteKey;
    for (auto byte : bytes) {
        byteKey.push_back(finalKey);
    }

    //decode by xoring them
    auto res = xorBuffers(bytes, byteKey);

    //print bytes in ascii
    cout<<bytesToChar(res);


    file.close();

}
