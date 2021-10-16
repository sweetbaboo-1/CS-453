#pragma once
#include <iomanip>
#include <iostream>
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
std::string toCannon(std::string path) {
    std::string lowerPath = toLowerCase(path);  
    
    for(std::string::size_type i = 0; i < lowerPath.size(); ++i)
    {
        if(lowerPath[i] == '.')
        {
            auto old = filesystem::current_path();
            std::cout << old;

        }
        if(lowerPath[i] == '%' || lowerPath[i] == '$' 
        || lowerPath[i] == '#' || lowerPath[i] == '&' 
        || lowerPath[i] == '*' || lowerPath[i] == ' ' 
        || lowerPath[i] == '[' || lowerPath[i] == ']'
        || lowerPath[i] == '|' || lowerPath[i] == '\\'
        || lowerPath[i] == '+' || lowerPath[i] == '='
        || lowerPath[i] == '-' || lowerPath[i] == '_'
        || lowerPath[i] == '{' || lowerPath[i] == '}'
        || lowerPath[i] == ',' || lowerPath[i] == '<'
        || lowerPath[i] == '>' || lowerPath[i] == '\''
        || lowerPath[i] == '"' || lowerPath[i] == '`'
        || lowerPath[i] == '~' || lowerPath[i] == '(' || lowerPath[i] == ')')
        {
            lowerPath.erase(i);
        }

        if(lowerPath[i] == '0') lowerPath[i] = 'o';
        else if (lowerPath[i] == '3') lowerPath[i] = 'e';
        else if (lowerPath[i] == '5') lowerPath[i] = 's';
        else if (lowerPath[i] == '!') lowerPath[i] = 'i';
        else if (lowerPath[i] == '@') lowerPath[i] = 'a';
        else if (lowerPath[i] == '^') lowerPath[i] = 'v';
        else if (lowerPath[i] == '1') lowerPath[i] = 'l';
    }

    return lowerPath;
}