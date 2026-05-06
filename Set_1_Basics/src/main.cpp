//
// Created by petar on 4/3/2026.
//
#include "../include/1_hex_to_base64.h"
#include "../include/2_fixed_xor.h"
#include "../include/3_single_xor_cipher.h"
#include "../include/4_find_string_from_file.h"
#include "../include/5_repeating_key_xor.h"
#include "../include/6_break_repeating_key_xor.h"
#include "../include/7_AES_ECB_mode.h"
#include "../include/8_detect_AES_ECB.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;


int main() {

    string fileName="hex_crypted_aes.txt";

    cout<<detectECB(fileName)<<endl;
//dsadsa
    //proba
    return 0;
}

