#include <iostream>
#include <string>
#include "client.h"

int main(int argc, char* argv[])
{
    if(argc < 2)
    {
        std::cout << "Please provide command line arguments." << std::endl;
        return 0;
    }

    std::cout << argv[1] << std::endl;

    if((std::string(argv[1])) == "new")
    {
        ParseNew(argc, argv);
    }
    return 0;
}
