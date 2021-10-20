//
// Created by dima on 10/16/21.
//

#ifndef PMP_CLIENT_CLI_UTILS_H
#define PMP_CLIENT_CLI_UTILS_H

#define CONFIG_FILE "config.ini"
#define MASTER_KEY "thisisatest" //REPLACE LATER

#include <string>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <iterator>
#include "crypto.h"

#ifdef _WIN32

#endif
#ifdef TARGET_OS_MAC

#endif
#ifdef __linux__

#endif

void ToClipboard(std::string pass);
std::string CleanString(std::string pass);
bool ConfigFilesExists();
bool CreateConfigFile();
bool ValidateMaster();

#endif //PMP_CLIENT_CLI_UTILS_H
