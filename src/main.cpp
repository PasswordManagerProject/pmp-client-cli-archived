#include <iostream>
#include <string>
#include "data.h"
#include "utils.h"
#include "crypto.h"

int main(int argc, char* argv[])
{
    std::string pass;
    std::string encpass;

    if(argc < 2)
    {
        std::cout << "Please provide command line arguments." << std::endl;
        return 0;
    }

    if((std::string(argv[1])) == "new")
    {
        pass = ParseNew(argc, argv);
    }

    std::cout << "Your new password: " << pass << std::endl;
    ToClipboard(pass);

    encpass = Encrypt(pass, "");
    std::cout << encpass << std::endl;
    std::cout << Decrypt(encpass, "") << std::endl;

    return 0;
}
