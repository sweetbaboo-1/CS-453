#pragma once

#include "test_cases.cpp"
#include <assert.h>
/**************************************
 * weak mitigation
 * takes an input (querry)
 * returns a weekly sanitized input
 *************************************/
std::string weakMitigation(const std::string input) // may need more than one input
{
    std::string output;
    const char *p = input.c_str();
    // filter input to remove union statements
    // remove single quotes or the 'OR' keyword
    // remove comments
    // remove semicolons

    // SELECT authenticate FROM passwordList WHERE name='Matthew' and passwd='password' UNION SELECT authenticate FROM passwordList';

    std::string search = "UNION";
    if (strstr(input.c_str(), search.c_str())) // we have a union attack
    {
        
    }

    return input;
}

/**************************************
 * strong mitigation
 * takes an input (querry)
 * returns a totally sanitized input
 *************************************/
std::string strongMitigation(std::string input) // may need more than one input
{
    // remove sql from workflow (works for all cases)
    return input;
}
