#pragma once
#include <iomanip>
#include <string>

// returns a string with all alphabetical charecters in their lowercase form
std::string toLowerCase(std::string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        str[i] = tolower(str[i]);
    }
    return str;
}

// returns a canonized version of a given string
std::string toCannon(std::string path) {
    std::string cannonizedString = toLowerCase(path);  

    return cannonizedString;
}