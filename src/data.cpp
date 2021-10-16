//
// Created by dima on 10/7/21.
//

#include "data.h"

std::string ParseNew(int argc, char* argv[])
{
    std::string temp;
    std::string delimiter = "=";
    std::string pass;
    //just basics for now...
    int length = -1;
    int lengthFound = false;
    bool alpha = true;
    bool numerics = true;
    bool special = true;

    for(int i = 2; i < argc; i++)
    {
        temp = argv[i];
        if(temp.find("-l") != std::string::npos)
        {
            length = std::stoi(temp.substr(3, temp.find(delimiter)), nullptr, 10);
            lengthFound = true;
        }
        else if(temp.find("-ns") != std::string::npos)
        {
            special = false;
        }
        else if(temp.find("-na") != std::string::npos)
        {
            alpha = false;
        }
        else if(temp.find("-nn") != std::string::npos)
        {
            numerics = false;
        }
    }

    if(length < 5) length = 5;
    if(length > 30) length = 30;
    if(!lengthFound) length = 15;

    pass = GeneratePass(length, alpha, numerics, special);

    return pass;
}

std::string GeneratePass(int length, bool alpha, bool numerics, bool special)
{
    int max = 126;
    int min = 35;
    char current;
    std::string pass = "";

    srand(time(NULL));

    for(int i = 0; i < length; i++)
    {
        current = char(min) + (rand() % (max - min));

        if(!special)
        {
            if((current >= 33 && current <= 47) ||
               (current >= 58 && current <= 64) ||
               (current >= 91 && current <= 96) ||
               (current >= 123 && current <= 126))
            {
                i--;
                continue;
            }
        }
        if(!numerics)
        {
            if((current >= 49 && current <= 57))
            {
                i--;
                continue;
            }
        }
        if(!alpha)
        {
            if((current >= 65 && current <= 90) ||
               (current >= 97 && current <= 122))
            {
                i--;
                continue;
            }
        }

        pass += current;
    }

    return pass;
}