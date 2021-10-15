#include <iomanip>
#include <string>
#include "canonicalization.cpp"

bool areHomographs(std::string path1, std::string path2) {
    std::string path1Canon = toCannon(path1);
    std::string path2Canon = toCannon(path2);
    
    if (path1Canon == path2Canon)
        return true;
    return false;
}