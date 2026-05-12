cmake_minimum_required(VERSION 4.2)

project(CryptoPals)
set(CMAKE_CXX_STANDARD 17)
find_package(OpenSSL REQUIRED)
add_executable(CryptoPals CryptoPals/src/main.cpp
        CryptoPals/src/Set_1_Basics/1_hex_to_base64.cpp
        CryptoPals/src/Set_1_Basics/2_fixed_xor.cpp
        CryptoPals/src/Set_1_Basics/3_single_xor_cipher.cpp
        CryptoPals/src/Set_1_Basics/4_find_string_from_file.cpp
        CryptoPals/src/Set_1_Basics/5_repeating_key_xor.cpp
        CryptoPals/src/Set_1_Basics/6_break_repeating_key_xor.cpp
        CryptoPals/include/Set_1_Basics/7_AES_ECB_mode.h
        CryptoPals/src/Set_1_Basics/7_AES_ECB_mode.cpp
        CryptoPals/include/Set_1_Basics/8_detect_AES_ECB.h
        CryptoPals/src/Set_1_Basics/8_detect_AES_ECB.cpp
        CryptoPals/include/Set_2_Block_Cipher/1_PKCS7_pad.h
        CryptoPals/src/Set_2_Block_Cipher/1_PKCS7_pad.cpp
        CryptoPals/include/Set_2_Block_Cipher/2_CBC_mode.h
        CryptoPals/src/Set_2_Block_Cipher/2_CBC_mode.cpp
)

target_link_libraries(CryptoPals OpenSSL::SSL OpenSSL::Crypto)