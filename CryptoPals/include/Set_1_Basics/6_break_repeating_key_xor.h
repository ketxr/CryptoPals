//
// Created by petar on 4/6/2026.
//

#ifndef CRYPTOPALS_6_BREAK_REPEATING_KEY_XOR_H
#define CRYPTOPALS_6_BREAK_REPEATING_KEY_XOR_H
#include <string>
#include <vector>


int hammingDistance(std::string str1, std::string str2);
int hammingDistanceBytes(std::vector<unsigned char> bytes1, std::vector<unsigned char> bytes2);

int findKeySize(std::string &fileName);

#endif //CRYPTOPALS_6_BREAK_REPEATING_KEY_XOR_H
