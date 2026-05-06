//
// Created by petar on 4/3/2026.
//
#include "../include/Set_1_Basics/1_hex_to_base64.h"
#include "../include/Set_1_Basics/2_fixed_xor.h"
#include "../include/Set_1_Basics/3_single_xor_cipher.h"
#include "../include/Set_1_Basics/4_find_string_from_file.h"
#include "../include/Set_1_Basics/5_repeating_key_xor.h"
#include "../include/Set_1_Basics/6_break_repeating_key_xor.h"
#include "../include/Set_1_Basics/7_AES_ECB_mode.h"
#include "../include/Set_1_Basics/8_detect_AES_ECB.h"
#include "../include/Set_2_Block_Cipher/1_PKCS7_pad.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;


int main() {

    vector<unsigned char> bytes;
    bytes.push_back('A');
    bytes.push_back('A');
    PKCS7_pad(11, bytes);
    for (int i =0; i<bytes.size(); i++) {
        std::cout<<(int)bytes[i];
    }
    return 0;
}

