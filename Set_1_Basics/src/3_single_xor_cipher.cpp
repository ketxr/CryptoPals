//
// Created by petar on 4/3/2026.
//
#include "../include/1_hex_to_base64.h"
#include "../include/2_fixed_xor.h"
#include "../include/3_single_xor_cipher.h"

#include <iostream>
#include <unordered_map>


unsigned char findKey(std::string encodedHex) {

    std::unordered_map<char, double> freq = {
        {'e', 12.7}, {'t', 9.1}, {'a', 8.2}, {'o', 7.5}, {'i', 7.0}, {'n', 6.7},
        {' ', 13.0},
        {'s', 6.3}, {'h', 6.1}, {'r', 6.0}, {'d', 4.3}, {'l', 4.0}, {'u', 2.8}
    };

    std::vector<unsigned char> encodedBytes = hexToBytes(encodedHex);

    double score;
    double result=-1e9;
    unsigned char key='0';
    for (int j = 0; j< 256; j++) {
        score=0;
        for (int i =0 ; i < encodedBytes.size(); i++) {
            unsigned char letter = encodedBytes[i] ^ j;
            unsigned char lower = tolower(letter);
            if (freq.count(lower)) {
                score += freq[lower];
            }
            else if (!std::isprint(lower)) {
                score-=10;
            }
        }
        if (score>result) {
            result=score;
            key=j;
        }
    }

    for (int i = 0; i< encodedBytes.size(); i++) {
        std::cout << (unsigned char) (encodedBytes[i] ^ key);

    }
    std::cout<<std::endl;
    return key;
}
