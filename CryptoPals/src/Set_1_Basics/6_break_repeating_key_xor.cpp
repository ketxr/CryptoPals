//
// Created by petar on 4/6/2026.
//
#include "../../include/Set_1_Basics/6_break_repeating_key_xor.h"

#include <iostream>

#include "../../include/Set_1_Basics/1_hex_to_base64.h"
#include "../../include/Set_1_Basics/2_fixed_xor.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <iterator>
#include "../../include/Set_1_Basics/3_single_xor_cipher.h"

int hammingDistance(std::string str1, std::string str2) {
    std::vector<unsigned char> bytes1 = textStringToBytes(str1);
    std::vector<unsigned char> bytes2 = textStringToBytes(str2);

    std::vector<unsigned char> bytes3 = xorBuffers(bytes1, bytes2);
    int cnt=0;
    int mask=1;
    for (int i=0; i<bytes3.size(); i++) {
        for (int j=0; j<8; j++) {
            if (bytes3[i] >> j & mask) { cnt++;}
        }
    }
    return cnt;
}

int hammingDistanceBytes(std::vector<unsigned char> bytes1, std::vector<unsigned char> bytes2) {
    std::vector<unsigned char> bytes3 = xorBuffers(bytes1, bytes2);
    int cnt=0;
    int mask=1;
    for (int i=0; i<bytes3.size(); i++) {
        for (int j=0; j<8; j++) {
            if (bytes3[i] >> j & mask) { cnt++;}
        }
    }
    return cnt;
}


int findKeySize(std::string &fileName) {
    int keySize=0;
    std::ifstream file("../CryptoPals/files/"+fileName);
    if (!file.is_open()) {
        std::cout << "File not found" << std::endl;
        return -1;
    }

    std::string s1;
    std::string s2;
    std::string s3;
    std::string s4;


    file>>s1; //first 60 characters of base64 i.e. first 45 bytes
    file>>s2; // second 45 bytes
    file>>s3;
    file>>s4;
    std::vector<unsigned char> bytes1 = base64ToBytes(s1);
    std::vector<unsigned char> bytes2 = base64ToBytes(s2);
    std::vector<unsigned char> bytes3 = base64ToBytes(s3);
    std::vector<unsigned char> bytes4 = base64ToBytes(s4);
    bytes1.insert(bytes1.end(), bytes2.begin(), bytes2.end());
    bytes1.insert(bytes1.end(), bytes3.begin(), bytes3.end());
    bytes1.insert(bytes1.end(), bytes4.begin(), bytes4.end());
    double minHamming = INT_MAX;
    double hamming1;
    double hamming2;
    double hamming3;
    double avg;
    for (int i =4 ; i<=40; i++) {
        std::vector<unsigned char> sub1(bytes1.begin(), bytes1.begin()+i);
        std::vector<unsigned char> sub2(bytes1.begin()+i, bytes1.begin()+2*i);
        std::vector<unsigned char> sub3(bytes1.begin()+i*2, bytes1.begin()+3*i);
        std::vector<unsigned char> sub4(bytes1.begin()+i*3, bytes1.begin()+4*i);
        hamming1=(double)hammingDistanceBytes(sub1, sub2);
        hamming2=(double)hammingDistanceBytes(sub2, sub3);
        hamming3=(double)hammingDistanceBytes(sub3, sub4);
        avg = (hamming1+hamming2+hamming3)/3;
        avg=avg/i;


       //std::cout <<"i:"<< i<<"-"<<avg << std::endl;
        if (avg<minHamming) {
            minHamming=avg;
            keySize=i;
        }
    }
    //cout<<minHamming;

    file.clear();               // Clear EOF and error flags
    file.seekg(0, std::ios::beg); // Reset pointer to the beginning
    std::stringstream buffer;
    buffer << file.rdbuf(); // Read the file buffer into the stream
    std::string str = buffer.str(); // Convert stream to string
    str.erase(std::remove(str.begin(), str.end(), '\n'), str.end());
    //std::cout << str << std::endl;
    std::vector<unsigned char> bytes = base64ToBytes(str);
    std::vector<unsigned char> prvi;
    std::string final;
    for (int j=0;j<keySize;j++) {
        prvi.clear();
        for (int i=j; i<bytes.size(); i+=keySize) {
            prvi.push_back(bytes[i]);
        }
        final.push_back(findKeyBytes(prvi).first);
    }
    std::cout << final << std::endl;
    std::vector<unsigned char> finalBytes=textStringToBytes(final);
    std::vector<unsigned char> decryptedBytes;
    for (int i=0;i<bytes.size();i++) {
        decryptedBytes.push_back(bytes[i]^finalBytes[i%keySize]);
    }
    std::cout<<stringifyByteArray(decryptedBytes);
    file.close();
    return keySize;
}
