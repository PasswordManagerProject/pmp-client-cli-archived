#include <iostream>
#include <string>
#include "data.h"
#include "utils.h"
#include "crypto.h"

int main(int argc, char* argv[])
{
    std::string pass;
    std::string encpass;

    if((std::string(argv[1])) == "config")
    {
        CreateConfigFile();
        return 0;
    }

    if(!ConfigFilesExists())
    {
        std::cout << "No config file found. Please run with the config argument." << std::endl;
        return 0;
    }

    if(argc < 2)
    {
        std::cout << "Please provide command line arguments." << std::endl;
        return 0;
    }

    if((std::string(argv[1])) == "new")
    {
        pass = ParseNew(argc, argv);

        std::cout << "Your new password: " << pass << std::endl;
        ToClipboard(pass);
    }
    else if((std::string(argv[1])) == "testlogin")
    {
        ValidateMaster();
    }

    return 0;
}
