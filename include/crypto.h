//
// Created by dima on 10/17/21.
//

#ifndef PMP_CLIENT_CLI_CRYPTO_H
#define PMP_CLIENT_CLI_CRYPTO_H
#define MAX_KEY_SIZE 32

#include <iostream> //remove later
#include "../lib/AES.h"

std::string Encrypt(std::string input, std::string key);
std::string Decrypt(std::string input, std::string key);
void CleanKey(std::string key, unsigned char *cleanKey);

#endif //PMP_CLIENT_CLI_CRYPTO_H
