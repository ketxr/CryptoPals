//
// Created by petar on 4/3/2026.
//

#ifndef CRYPTOPALS_3_SINGLE_XOR_CIPHER_H
#define CRYPTOPALS_3_SINGLE_XOR_CIPHER_H
#include <string>
#include <utility>

std::pair<unsigned char, double> findKey(std::string encodedHex);
std::pair<unsigned char, double> findKeyBytes(std::vector<unsigned char> encodedBytes);

#endif //CRYPTOPALS_3_SINGLE_XOR_CIPHER_H
