//
// Created by petar on 4/3/2026.
//
#include "../include/1_hex_to_base64.h"
#include "../include/2_fixed_xor.h"
#include "../include/3_single_xor_cipher.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;


int main() {
    string hex = "1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736";

    cout<<findKey(hex);


    return 0;
}