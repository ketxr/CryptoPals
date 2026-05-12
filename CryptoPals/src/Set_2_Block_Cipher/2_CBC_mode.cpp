//
// Created by petar on 5/12/2026.
//

#include "../../include/Set_2_Block_Cipher/2_CBC_mode.h"
#include "../../include/Set_2_Block_Cipher/1_PKCS7_pad.h"
#include "../../include/Set_1_Basics/1_hex_to_base64.h"
#include "../../include/Set_1_Basics/2_fixed_xor.h"

#include <openssl/aes.h>
#include <sstream>
#include <fstream>
#include <iostream>


std::string CBC_encryptAES(std::string plaintext, unsigned char* key) {
    std::ofstream outFile("../CryptoPals/files/crypted_custom_2.txt");
    AES_KEY aesKey;
    auto bytes = textStringToBytes(plaintext);

    AES_set_encrypt_key(key, 128, &aesKey);
    PKCS7_pad(16,bytes);

    std::vector<unsigned char> final;
    std::vector<unsigned char> temp16(16,0);
    for (int i = 0; i < bytes.size(); i+=16) {

        unsigned char block[16];
        std::vector<unsigned char> block16(bytes.data()+i, bytes.data()+ i  + 16);
        block16 = xorBuffers(block16,temp16);
        AES_encrypt(block16.data(), block, &aesKey);
        temp16.clear();
        for (int j = 0; j < 16; j++) {
            final.push_back(block[j]);
            temp16.push_back(block[j]);
        }

    }
    outFile<<bytesToBase64(final);

    outFile.close();

    return "Success, created/updated a file: crypted_custom_2.txt";
}


std::string CBC_decryptAES(std::string fileName, unsigned char* key) {
    std::ifstream file("../CryptoPals/files/"+fileName);
    if (!file.is_open()) {
        std::cout << "File not found" << std::endl;
        return "fail";
    }
    AES_KEY aesKey;
    AES_set_decrypt_key(key, 128, &aesKey);
    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string str = buffer.str();
    str.erase(std::remove(str.begin(), str.end(), '\n'), str.end());

    auto bytes = base64ToBytes(str);
    std::vector<unsigned char> decrypted;
    std::vector<unsigned char> prev(16,0);
    for (size_t i = 0; i < bytes.size(); i += 16) {

        unsigned char block[16];
        AES_decrypt(bytes.data() + i, block, &aesKey);

        std::vector<unsigned char> vectorBlock(block, block + 16);
        vectorBlock = xorBuffers(vectorBlock, prev);
        decrypted.insert(decrypted.end(), vectorBlock.begin(), vectorBlock.end()); //ovde umesto bloka insertujemo blok xorovan sa proslim bytes[i, i+16]

        prev.assign(bytes.begin()+i, bytes.begin()+i+16);  //prev treba da uzme vrednost od bytes od [i,i+16]
    }
    //decrypted.push_back('\0');

    unsigned char padding = decrypted.back();

    if (padding > 0 && padding <= 16) {
        decrypted.resize(decrypted.size() - padding);
    }
    return std::string (decrypted.begin(), decrypted.end());
}

