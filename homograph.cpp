#include "homograph.h"
#include "canonicalization.h"

bool areHomographs(std::string path1, std::string path2) {
    if (path1 > path2)
        return true;
    return false;
}