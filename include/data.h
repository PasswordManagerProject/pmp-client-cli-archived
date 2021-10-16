//
// Created by dima on 10/7/21.
//

#ifndef PMP_CLIENT_CLI_DATA_H
#define PMP_CLIENT_CLI_DATA_H

#include <string>
#include <iostream>
#include <time.h>

std::string ParseNew(int argc, char* argv[]);
std::string GeneratePass(int length, bool alpha, bool numerics, bool special);

#endif //PMP_CLIENT_CLI_DATA_H
