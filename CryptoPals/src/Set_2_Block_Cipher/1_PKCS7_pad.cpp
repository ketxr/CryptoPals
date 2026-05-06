//
// Created by Test on 06-May-26.
//
#include "../../include/Set_2_Block_Cipher/1_PKCS7_pad.h"
#include <iostream>
void PKCS7_pad(int padTo, std::vector<unsigned char>& bytes) {
    int padding =  padTo-bytes.size()%padTo;
    if (padding==0) {
        padding=padTo;
    }
    for (int i=0;i<padding;i++) {
        bytes.push_back((unsigned char)padding);
    }

}