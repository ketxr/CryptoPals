#include "../include/2_fixed_xor.h"

#include <stdexcept>


std::vector<unsigned char> xorBuffers(std::vector<unsigned char> first, std::vector<unsigned char> second) {

    std::vector<unsigned char> result;

    if (first.size() != second.size()) { throw std::invalid_argument("first and second size mismatch"); }

    for (int i = 0; i < first.size(); i++) {
        result.push_back(first[i] ^ second[i]);
    }

    return result;
}

