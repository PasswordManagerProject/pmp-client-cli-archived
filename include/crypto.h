//
// Created by dima on 10/17/21.
//

#ifndef PMP_CLIENT_CLI_CRYPTO_H
#define PMP_CLIENT_CLI_CRYPTO_H

#include <iostream> //remove later
#include "../lib/AES.h"

std::string Encrypt(std::string input, std::string key);
std::string Decrypt(std::string input, std::string key);

#endif //PMP_CLIENT_CLI_CRYPTO_H
