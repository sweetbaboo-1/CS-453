#pragma once

#include <iomanip>
#include "test_cases.cpp"
/******************************************************
 * returns an SQL string representing a query
 *****************************************************/
inline std::string query(std::string username, std::string password)
{
    //NOT A VALID SQL STATEMENT
    return "SELECT authenticate FROM passwordList WHERE name=\'" + username + "\' and passwd=\'" + password + "\';";
}

/******************************************************
 * cycles through all given test cases and populates
 * queries with generated queries
 *****************************************************/
inline void generateQuerys(TestCase testCases[6], std::string queries[6]) 
{
    for (int i = 0; i < 6; i++)
    {
        queries[i] = query(testCases[i].username, testCases[i].password);
    }
}
