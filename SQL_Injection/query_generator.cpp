#pragma once

#include <iomanip>

/******************************************************
 * TODO: figure out how this should work and code it
 * THIS IS NOT DONE
 *****************************************************/
void generateQuerys(TestCase (&testCases)[6], std::string (&queries)[6]) 
{
    for (int i = 0; i < 6; i++)
    {
        // returning something to verify that it works as intended
        queries[i] = testCases[i].username + " " + testCases[i].password;
    }
}