//
// Created by dima on 10/7/21.
//

#include "client.h"

void ParseNew(int argc, char* argv[])
{
    std::string temp;
    std::string delimiter = "=";
    //just basics for now...
    int length = 0;
    bool alpha = true;
    bool numerics = true;
    bool special = true;

    for(int i = 1; i < argc; i++)
    {
        temp = argv[i];
        if(temp.find("-l") != std::string::npos)
        {

        }
    }
}