//
// Created by petar on 4/5/2026.
//
#include "../../include/Set_1_Basics/5_repeating_key_xor.h"
#include "../../include/Set_1_Basics/1_hex_to_base64.h"
#include "../../include/Set_1_Basics/2_fixed_xor.h"
#include <string>
#include <vector>

std::string repeatingKeyXor(const std::string &text, const std::string &key) {
    std::vector<unsigned char> bytes = textStringToBytes(text);
    int keySize=key.length();
    std::vector<unsigned char> iceBytes;
    for (int i=0; i<bytes.size(); i++) {
        iceBytes.push_back(key[i%keySize]);
    }
    std::vector<unsigned char> result = xorBuffers(bytes, iceBytes);

    std::string resultString = bytesToHexString(result);
    return resultString;
}
