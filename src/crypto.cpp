//
// Created by dima on 10/17/21.
//

#include "crypto.h"

//TODO: Explore/Research key length limitations
//TODO: Exception Handling

std::string Encrypt(std::string input, std::string key)
{
    AES aes(128);
    unsigned int outLength;
    unsigned char* out = aes.EncryptECB((unsigned char*)(input.c_str()),
                                        input.length(),
                                        (unsigned char*) key.c_str(),
                                        outLength);

    return std::string(reinterpret_cast< char const* >(out));
}

std::string Decrypt(std::string input, std::string key)
{
    AES aes(128);
    unsigned char* out = aes.DecryptECB((unsigned char*)(input.c_str()),
                                        strlen((char*)(input.c_str())),
                                        (unsigned char *) key.c_str());

    return std::string(reinterpret_cast< char const* >(out));
}
