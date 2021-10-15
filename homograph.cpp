#pragma once
#include <iomanip>
#include "canonicalization.cpp"

// leverages the toCannon function to check if 2 file paths are the same
bool areHomographs(std::string path1, std::string path2) {
    std::string path1Canon = toCannon(path1);
    std::string path2Canon = toCannon(path2);
    
    if (path1Canon == path2Canon)
        return true;
        
    return false;
}