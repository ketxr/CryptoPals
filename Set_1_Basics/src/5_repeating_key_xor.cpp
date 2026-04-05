//
// Created by petar on 4/5/2026.
//
#include "../include/5_repeating_key_xor.h"
#include "../include/1_hex_to_base64.h"
#include "../include/2_fixed_xor.h"
#include <string>
#include <vector>

std::string repeatingKeyXorICE(const std::string &text) {
    std::vector<unsigned char> bytes = textStringToBytes(text);
    std::vector<unsigned char> iceBytes;
    for (int i=0; i<bytes.size(); i++) {
        if (i%3==0) iceBytes.push_back('I');
        if (i%3==1) iceBytes.push_back('C');
        if (i%3==2) iceBytes.push_back('E');
    }
    std::vector<unsigned char> result = xorBuffers(bytes, iceBytes);

    std::string resultString = bytesToHexString(result);
    return resultString;
}
