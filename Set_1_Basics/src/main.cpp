//
// Created by petar on 4/3/2026.
//
#include "../include/1_hex_to_base64.h"
#include "../include/2_fixed_xor.h"
#include "../include/3_single_xor_cipher.h"
#include "../include/4_find_string_from_file.h"
#include "../include/5_repeating_key_xor.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;


int main() {
    string hex = "1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736";
    string fileName="crypted.txt";
    string text = "Burning 'em, if you ain't quick and nimble\nI go crazy when I hear a cymbal";
    cout<<repeatingKeyXor(text,"ICE");

    //proba
    return 0;
}

