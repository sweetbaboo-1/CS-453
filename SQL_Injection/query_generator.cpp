#pragma once

#include <iomanip>
#include "test_cases.cpp"

/******************************************************
 * cycles through all given test cases and populates
 * queries with generated queries
 *****************************************************/
void generateQueries(TestCase testCases[], std::string queries[], int count) 
{
    for (int i = 0; i < count; i++)
        queries[i] = "SELECT authenticate FROM passwordList WHERE name=\'" + testCases[i].username + "\' and passwd=\'" + testCases[i].password + "\';";
}
