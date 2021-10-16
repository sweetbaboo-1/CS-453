#pragma once
#include <iomanip>
#include <iostream>
#include <string>
#include <filesystem>
#include <stdio.h>
#include <dirent.h>

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
std::string toCannon(std::string path) {
    std::string lowerPath = toLowerCase(path); 
    if(lowerPath[0] == '.' && lowerPath[1] == '/')
    {
        std::string dir = _getcwd(0, 0);
        dir = toLowerCase(dir);
        lowerPath.erase(0);
        dir.append(lowerPath);
        lowerPath = "";
        lowerPath = dir;
        std::cout << lowerPath;
    } 
    
    for(std::string::size_type i = 0; i < lowerPath.size(); ++i)
    {
        // /a/b/c/d.out
        // ./a/b/c/d.out
        // C:\Computer Security\HomographLab-main\HomographLab-main/a/b/c/d.out
        
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
        || lowerPath[i] == '~' || lowerPath[i] == '(' 
        || lowerPath[i] == ')' || lowerPath[i] == '^'
        || lowerPath[i] == ':' || lowerPath[i] == ';'
        || lowerPath[i] == '/')
        {
            lowerPath.erase(i);
        }

        if(lowerPath[i] == '0') lowerPath[i] = 'o';
        else if (lowerPath[i] == '3') lowerPath[i] = 'e';
        else if (lowerPath[i] == '5') lowerPath[i] = 's';
        else if (lowerPath[i] == '!') lowerPath[i] = 'i';
        else if (lowerPath[i] == '@') lowerPath[i] = 'a';
        else if (lowerPath[i] == '1') lowerPath[i] = 'l';
        else if (lowerPath[i] == '8') lowerPath[i] = 'b';
        else if (lowerPath[i] == '9') lowerPath[i] = 'p';
        else if (lowerPath[i] == '4') lowerPath[i] = 'a';
        else if (lowerPath[i] == '6') lowerPath[i] = 'b';
        else if (lowerPath[i] == '2') lowerPath[i] = 'z';
        else if (lowerPath[i] == '7') lowerPath[i] = 't';
    }
    
    return lowerPath;
}