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
    std::string sanitizedInput = input;
    // filter input to remove union statements
    // remove single quotes or the 'OR' keyword - tautology
    // remove comments
    // remove semicolons

    /******************************
     * UNION attack
     * xample test case:
     * SELECT authenticate FROM passwordList WHERE name='Matthew' and passwd='password' UNION SELECT authenticate FROM passwordList';
     *****************************/
    std::string search = "UNION";
    std::size_t index = input.find(search);
    if (index != std::string::npos) // union statement at found
        sanitizedInput = input.substr(0, index - 1) + ";"; // not sure if this -1 is always correct but i haven't been able to break it

    /******************************
     * tautology attack
     * example test case:
     * "SELECT authenticate FROM passwordList WHERE name='Matthew' and passwd='password' OR 'x' = 'x';"
     *****************************/
    search = "OR";
    index = input.find(search);
    if (index != std::string::npos)
        sanitizedInput = input.substr(0, index - 1) + ";"; // not sure if this -1 is always correct but i haven't been able to break it

    /******************************
     * comment attack
     * example test case:
     * "SELECT authenticate FROM passwordList WHERE name='Root'; -- and passwd='nothign';
     *****************************/
    search = "--";
    index = input.find(search);
    // check if there is a ';' before the comment
    if (index != std::string::npos && input.find(";") < index) // there is a semicolon before a comment in a query that shouldn't have comments
    {
        // TODO: THIS NEEDS TO REMOVE THE EXTRA ' THAT IS IN THE QUERY
        std::string s = ";";
        std::size_t i = input.find(s);        // the first ';' should be removed and the comment deleted
        std::string str = input.substr(0, i); // the first half of the statement
        str += input.substr(index + 4) + ";";       // the comment is the other half of the statement
        sanitizedInput = str;
    }

    /******************************
     * additonal statement attack
     * example test case:
     * SELECT authenticate FROM passwordList WHERE name='Root' and passwd='nothing'; INSERT INTO passwordList (name, passwd) VALUES 'Bob', '1234';
     *****************************/
    search = ";";
    index = input.find(search);
    // the last char should be the one and only semicolon
    if (index != std::string::npos && index < input.find_last_of(search)) // we have an additional ;
        sanitizedInput = input.substr(0, index) + ";";

    return sanitizedInput;
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

void runWeakMitigation(std::string inputs[6], std::string sanitizedInputs[6])
{
    for (int i = 0; i < 6; i++)
    {
        sanitizedInputs[i] = weakMitigation(inputs[i]);
    }
}

void runStrongMitigation(std::string inputs[6], std::string sanitizedInputs[6])
{
    for (int i = 0; i < 6; i++)
    {
        sanitizedInputs[i] = strongMitigation(inputs[i]);
    }
}