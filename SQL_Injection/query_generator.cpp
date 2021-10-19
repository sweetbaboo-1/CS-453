#pragma once

#include <iomanip>

std::string* generateQuerys(TestCase testCases[6], std::string queries[6]) 
{
    for (int i = 0; i < 6; i++)
    {
        queries[i] = testCases[i].username + " " + testCases[i].password;
    }
    
    return queries;
}