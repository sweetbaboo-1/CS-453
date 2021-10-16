#pragma once
#include <iomanip>
#include <string>
#include <filesystem>

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
std::string toCannon(std::string path)
{
    std::string cannonizedString = toLowerCase(path);


    /*****************************************************
     * 
     * Process: 
     * remove all capital letters
     * exchange symbols for letters? not sure if 0 = o or if we need to be smarter than that
     * current directory tricks? 
     *    if current directory is documents then
     *    C:/Users/Matthew/documents/passwords.txt = /passwords.txt = /documents/passwords.txt
     * turn all this information into a base "canon" string
     *  full path from drive in lowercase letters
     * 
     ****************************************************/

    return cannonizedString;
}