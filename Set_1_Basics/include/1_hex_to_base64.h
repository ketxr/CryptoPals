//
// Created by petar on 4/3/2026.
//

#ifndef CRYPTOPALS_1_HEX_TO_BASE64_H
#define CRYPTOPALS_1_HEX_TO_BASE64_H
#include <vector>
#include <string>



std::vector<unsigned char> hexStringToBytes(const std::string& hexString);

std::string bytesToBase64(const std::vector<unsigned char>& bytes);

std::string bytesToHexString(const std::vector<unsigned char>& bytes);

std::string bytesToChar(const std::vector<unsigned char>& bytes);

std::string hexStringToChar(const std::string& hexString);

#endif //CRYPTOPALS_1_HEX_TO_BASE64_H
