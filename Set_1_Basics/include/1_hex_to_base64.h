//
// Created by petar on 4/3/2026.
//

#ifndef CRYPTOPALS_1_HEX_TO_BASE64_H
#define CRYPTOPALS_1_HEX_TO_BASE64_H
#include <vector>
#include <string>



std::vector<unsigned char> hexToBytes(const std::string& hexString);

std::string bytesToBase64(const std::vector<unsigned char>& bytes);

#endif //CRYPTOPALS_1_HEX_TO_BASE64_H
