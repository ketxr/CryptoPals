//
// Created by Test on 04-May-26.
//

#include "../include/7_AES_ECB_mode.h"
#include "../include/1_hex_to_base64.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <openssl/aes.h>
#include <iterator>

std::string decryptAES(std::string fileName, std::string key) {
    std::ifstream file("../Set_1_Basics/files/"+fileName);
    if (!file.is_open()) {
        std::cout << "File not found" << std::endl;
        return "fail";
    }
    AES_KEY aesKey;
    unsigned char user_key[17] = "YELLOW SUBMARINE";
    AES_set_decrypt_key(user_key, 128, &aesKey);
    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string str = buffer.str();
    str.erase(std::remove(str.begin(), str.end(), '\n'), str.end());

    auto bytes = base64ToBytes(str);
    std::vector<unsigned char> decrypted;


    for (size_t i = 0; i < bytes.size(); i += 16) {

        unsigned char block[16];
        AES_decrypt(bytes.data() + i, block, &aesKey);
        decrypted.insert(decrypted.end(), block, block + 16);
    }
    //decrypted.push_back('\0');


    return std::string (decrypted.begin(), decrypted.end());
}
