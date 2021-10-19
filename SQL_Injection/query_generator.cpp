#pragma once

#include <iomanip>

void generateQuerys(TestCase (&testCases)[6], std::string (&queries)[6]) 
{
    for (int i = 0; i < 6; i++)
    {
        queries[i] = testCases[i].username + " " + testCases[i].password;
    }
}