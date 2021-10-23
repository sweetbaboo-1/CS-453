#pragma once

#include <iostream>
#include <algorithm>

/**************************************
 * finds a string case insensitive
 * not sure if we need this it's
 * currently unused
 *************************************/
size_t findCaseInsensitive(std::string data, std::string toSearch, size_t pos = 0)
{
    // Convert complete given String to lower case
    std::transform(data.begin(), data.end(), data.begin(), ::tolower);
    // Convert complete given Sub String to lower case
    std::transform(toSearch.begin(), toSearch.end(), toSearch.begin(), ::tolower);
    // Find sub string in given string
    return data.find(toSearch, pos);
}

/**************************************
 * weak mitigation
 * takes an input (querry)
 * returns a weekly sanitized input
 *************************************/
std::string weakMitigation(std::string input)
{
    std::string sanitizedInput = input;

    /******************************
     * UNION attack
     * example test case:
     * SELECT authenticate FROM passwordList WHERE name='Matthew' and passwd='password' UNION SELECT authenticate FROM passwordList';
     *****************************/
    std::string search = " UNION ";
    std::size_t index = findCaseInsensitive(sanitizedInput, search);
    if (index != std::string::npos) // union statement at found
        sanitizedInput = sanitizedInput.substr(0, index - 1);

    /******************************
     * tautology attack
     * example test case:
     * "SELECT authenticate FROM passwordList WHERE name='Matthew' and passwd='password' OR 'x' = 'x';"
     *****************************/
    search = " OR "; // spaces to protect words like passwORd
    index = findCaseInsensitive(sanitizedInput, search);
    if (index != std::string::npos)
        sanitizedInput = sanitizedInput.substr(0, index - 1);

    /******************************
     * comment attack
     * example test case:
     * "SELECT authenticate FROM passwordList WHERE name='Root'; -- and passwd='nothign';
     *****************************/
    search = "--";
    index = findCaseInsensitive(sanitizedInput, search);
    // check if there is a ';' before the comment
    if (index != std::string::npos && sanitizedInput.find(";") < index) // there is a semicolon before a comment in a query that shouldn't have comments
    {
        std::string s = ";";
        std::size_t i = sanitizedInput.find(s);                               // the first ';' should be removed and the comment deleted
        std::string str = sanitizedInput.substr(0, i - 1);                    // the first half of the statement minus the ;
        str += sanitizedInput.substr(index + 3, sanitizedInput.length() - 1); // the comment is the other half of the statement
        sanitizedInput = str;
    }

    /******************************
     * additonal statement attack
     * example test case:
     * SELECT authenticate FROM passwordList WHERE name='Root' and passwd='nothing'; INSERT INTO passwordList (name, passwd) VALUES 'Bob', '1234';
     *****************************/
    search = ";";
    index = findCaseInsensitive(sanitizedInput, search);
    // the last char should be the one and only semicolon
    if (index != std::string::npos) // we have an illegal ;
        sanitizedInput = sanitizedInput.substr(0, index - 1);

    return sanitizedInput;
}

/**************************************
 * strong mitigation
 * takes an input name or password
 * returns a totally sanitized input
 * Not 100% sure this is the right approach
 *************************************/
std::string strongMitigation(const std::string input)
{
    //Block Comment Defence
    std::string sanitizedInput = input;
    
    //Block Comment Defense
    if(sanitizedInput.find("/*") != std::string::npos)
        sanitizedInput = sanitizedInput.erase(sanitizedInput.find("/*"), sanitizedInput.find("/*")+1);
    if(sanitizedInput.find("*/") != std::string::npos)
        sanitizedInput = sanitizedInput.erase(sanitizedInput.find("*/"), sanitizedInput.find("*/")+1);
    if(sanitizedInput.find("--") != std::string::npos)
        sanitizedInput = sanitizedInput.erase(sanitizedInput.find("--"), sanitizedInput.find("--")+1);
        
    //UNION Defence
    int filteredUnion = findCaseInsensitive(sanitizedInput, " UNION ");
    if(filteredUnion != std::string::npos) sanitizedInput = sanitizedInput.erase(filteredUnion, sanitizedInput.length()-1);

    //Additional Statement Defence
    int semi = sanitizedInput.find(";");
    if(semi != std::string::npos) sanitizedInput = sanitizedInput.erase(semi, sanitizedInput.length());
    
    //Tautology Defence
    int filteredTautology = findCaseInsensitive(sanitizedInput, " OR ");
    if(filteredTautology != std::string::npos) sanitizedInput = sanitizedInput.erase(filteredTautology, sanitizedInput.length()-1);

    return sanitizedInput;
}
