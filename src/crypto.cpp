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
    unsigned char cleanKey[MAX_KEY_SIZE];

    CleanKey(key, cleanKey);
    unsigned char* out = aes.EncryptECB((unsigned char*)(input.c_str()),
                                        input.length(),
                                        cleanKey,
                                        outLength);

    return std::string(reinterpret_cast< char const* >(out));
}

std::string Decrypt(std::string input, std::string key)
{
    AES aes(128);
    unsigned char cleanKey[MAX_KEY_SIZE];

    CleanKey(key, cleanKey);
    unsigned char* out = aes.DecryptECB((unsigned char*)(input.c_str()),
                                        strlen((char*)(input.c_str())),
                                        cleanKey);

    return std::string(reinterpret_cast< char const* >(out));
}

void CleanKey(std::string key, unsigned char *cleanKey)
{
    for(int i = 0; i < key.length(); i++)
    {
        cleanKey[i] = key[i];
    }

    for(int i = key.length(); i < MAX_KEY_SIZE; i++)
    {
        cleanKey[i] = '\0';
    }
}