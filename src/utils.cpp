//
// Created by dima on 10/16/21.
//

#include "utils.h"

void ToClipboard(std::string pass)
{
    //going to cheat and use cli piping for now.
    //TODO: Actual API clipboard integration
    int result;
    std::string cmd;
    std::string cleanPass;

    cleanPass = CleanString(pass);
#ifdef _WIN32
    cmd = "echo " + cleanPass + "| xclip -selection c";
    result = system(const_cast<char*>(cmd.c_str()));
#endif
#ifdef TARGET_OS_MAC
    cmd = cleanPass + "| pbcopy";
    result = system(const_cast<char*>(cmd.c_str()));
#endif
#ifdef __linux__
    cmd = "echo -n " + cleanPass + "| xclip -selection c";
    result = system(const_cast<char*>(cmd.c_str()));
#endif
}

std::string CleanString(std::string pass)
{
    std::string cleanString = "";
    for(int i = 0; i < pass.length(); i++)
    {
        if((pass[i] >= 33 && pass[i] <= 36) ||
           (pass[i] >= 38 && pass[i] <= 42) ||
           (pass[i] >= 59 && pass[i] <= 63) ||
           (pass[i] >= 91 && pass[i] <= 96) ||
           (pass[i] >= 123 && pass[i] <= 126))
        {
            cleanString = cleanString + "'" + pass[i] + "'";
        }
        else
        {
            cleanString += pass[i];
        }
    }

    return cleanString;
}

bool ConfigFilesExists()
{
    std::ifstream f(CONFIG_FILE);
    return f.good();
}

bool CreateConfigFile()
{
    std::string master = "";
    std::string master_enc = "";
    std::ofstream file;

    if(ConfigFilesExists())
    {
        std::cout << "A config file already exists. Please delete manually if you want to lose your master password."
        << std::endl;
        return false;
    }

    std::cout << "Please enter a master password: ";
    //TODO: HIDE PASSWORD ENTRY
    getline(std::cin, master);

    master_enc = Encrypt(master, std::string(MASTER_KEY));

    file.open(CONFIG_FILE);
    file << master_enc;
    file.close();

    return true;
}

bool ValidateMaster()
{
    std::string master = "";
    std::string master_enc = "";
    std::ifstream file;

    std::cout << "Please enter your master password: ";
    //TODO: HIDE PASSWORD ENTRY
    getline(std::cin, master);

    master_enc = Encrypt(master, std::string(MASTER_KEY));

    file.open(CONFIG_FILE);

    if(!file.good())
    {
        std::cout << "No config file found. How did you end up here?" << endl;
        return false;
    }

    std::string filepass { istreambuf_iterator<char>(file), istreambuf_iterator<char>() };

    if(filepass == master_enc)
    {
        return true;
    }
    else
    {
        std::cout << "Incorrect password." << std::endl;
        return false;
    }
}