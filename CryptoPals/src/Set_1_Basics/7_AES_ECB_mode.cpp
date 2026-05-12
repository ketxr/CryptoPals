//
// Created by Test on 04-May-26.
//

#include "../../include/Set_1_Basics/7_AES_ECB_mode.h"
#include "../../include/Set_1_Basics/1_hex_to_base64.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <algorithm>
#include <openssl/aes.h>
#include "../../include/Set_2_Block_Cipher/1_PKCS7_pad.h"
#include <iterator>

std::string ECB_decryptAES(std::string fileName) {
    std::ifstream file("../CryptoPals/files/"+fileName);
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

    unsigned char padding = decrypted.back();

    if (padding > 0 && padding <= 16) {
        decrypted.resize(decrypted.size() - padding);
    }
    return std::string (decrypted.begin(), decrypted.end());
}


std::string ECB_encryptAES(std::string tekst) {

    std::ofstream outFile("../CryptoPals/files/crypted_custom.txt");
    AES_KEY aesKey;
    unsigned char user_key[17] = "YELLOW SUBMARINE";
    auto bytes = textStringToBytes(tekst);
    AES_set_encrypt_key(user_key, 128, &aesKey);
    PKCS7_pad(16,bytes);
    std::vector<unsigned char> v;
    for (int i = 0; i < bytes.size(); i+=16) {
        unsigned char block[16];
        AES_encrypt(bytes.data() + i, block, &aesKey);
        for (int j = 0; j < 16; j++) {
            v.push_back(block[j]);
        }
    }
    outFile<<bytesToBase64(v);

    outFile.close();

    return "Success, created/updated a file: crypted_custom.txt";
}