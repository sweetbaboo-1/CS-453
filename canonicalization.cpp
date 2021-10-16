#pragma once
#include <iomanip>
#include <iostream>
#include <string>
#include <filesystem>
#include <stdio.h>

// returns a string with all alphabetical charecters in their lowercase form
inline std::string toLowerCase(std::string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        str[i] = tolower(str[i]);
    }
    return str;
}

// returns a canonized version of a given string
inline std::string toCannon(std::string path) {
    
    std::string canonizedPath = toLowerCase(path); 
    if(canonizedPath[0] == '.' && canonizedPath[1] == '/')
    {
        canonizedPath.erase(0);
        canonizedPath = "";
        std::cout << canonizedPath;
    } 
    
    for(std::string::size_type i = 0; i < canonizedPath.size(); ++i)
    {

        // remove all symbols
        if(canonizedPath[i] == '%' || canonizedPath[i] == '$' 
        || canonizedPath[i] == '#' || canonizedPath[i] == '&' 
        || canonizedPath[i] == '*' || canonizedPath[i] == ' ' 
        || canonizedPath[i] == '[' || canonizedPath[i] == ']'
        || canonizedPath[i] == '|' || canonizedPath[i] == '\\'
        || canonizedPath[i] == '+' || canonizedPath[i] == '='
        || canonizedPath[i] == '-' || canonizedPath[i] == '_'
        || canonizedPath[i] == '{' || canonizedPath[i] == '}'
        || canonizedPath[i] == ',' || canonizedPath[i] == '<'
        || canonizedPath[i] == '>' || canonizedPath[i] == '\''
        || canonizedPath[i] == '"' || canonizedPath[i] == '`'
        || canonizedPath[i] == '~' || canonizedPath[i] == '(' 
        || canonizedPath[i] == ')' || canonizedPath[i] == '^'
        || canonizedPath[i] == ':' || canonizedPath[i] == ';'
        || canonizedPath[i] == '/')
        {
            canonizedPath.erase(i);
        }

        // replace certain symbols with their canonized version
        if(canonizedPath[i] == '0') canonizedPath[i] = 'o';
        else if (canonizedPath[i] == '3') canonizedPath[i] = 'e';
        else if (canonizedPath[i] == '5') canonizedPath[i] = 's';
        else if (canonizedPath[i] == '!') canonizedPath[i] = 'i';
        else if (canonizedPath[i] == '@') canonizedPath[i] = 'a';
        else if (canonizedPath[i] == '1') canonizedPath[i] = 'l';
        else if (canonizedPath[i] == '8') canonizedPath[i] = 'b';
        else if (canonizedPath[i] == '9') canonizedPath[i] = 'p';
        else if (canonizedPath[i] == '4') canonizedPath[i] = 'a';
        else if (canonizedPath[i] == '6') canonizedPath[i] = 'b';
        else if (canonizedPath[i] == '2') canonizedPath[i] = 'z';
        else if (canonizedPath[i] == '7') canonizedPath[i] = 't';
    }
    
    return canonizedPath;
}