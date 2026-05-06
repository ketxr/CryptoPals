//
// Created by Test on 06-May-26.
//
#include "../include/8_detect_AES_ECB.h"
#include "../include/1_hex_to_base64.h"
#include <fstream>
#include <iostream>
#include <openssl/aes.h>
#include <set>

std::string detectECB(std::string fileName) {
    std::ifstream file("../Set_1_Basics/files/"+fileName);
    if (!file.is_open()) {
        std::cout << "File not found" << std::endl;
        return "";
    }
    std::string line;
    while (getline(file, line)) {
        std::set<std::string> blocks;
        for (int i=0; i<line.length(); i+=32) {
            std::string sub = line.substr(i, 32);
            if (blocks.find(sub) != blocks.end()){
                return "Duplicate found on line: " + std::to_string(i) + ", and the line is: " + line;
            }
            blocks.insert(line.substr(i,32));
        }

    }
    std::cout<<line<<std::endl;
    return "";
}