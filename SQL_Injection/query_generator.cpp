#pragma once
#include <iomanip>

/******************************************************
 * returns an SQL string representing a query
 *****************************************************/
std::string query(std::string username, std::string password)
{
    //NOT A VALID SQL STATEMENT
    return "SELECT authenticate FROM passwordList WHERE name=\'" + username + "\' and passwd=\'" + password + "\';";
}

/******************************************************
 * cycles through all given test cases and populates
 * queries
 *****************************************************/
void generateQuerys(TestCase testCases[6], std::string queries[6]) 
{
    for (int i = 0; i < 6; i++)
    {
        queries[i] = query(testCases[i].username, testCases[i].password);
    }
}
