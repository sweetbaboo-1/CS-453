#pragma once

#include "test_cases.cpp"
#include <iostream>
#include <algorithm>

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
 * TODO: 
 *************************************/
std::string weakMitigation(std::string input)
{
    std::string sanitizedInput = input;

    int i = sanitizedInput.find('\'');

    sanitizedInput = sanitizedInput.substr(0, i);

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
    // filter input to remove union statements
    // remove single quotes or the 'OR' keyword - tautology
    // remove comments
    // remove semicolons

    // no comments or sql statements
    // comments
    std::string sanitizedInput = input;

    int i = sanitizedInput.find('\'');

    sanitizedInput = sanitizedInput.substr(0, i);

    return sanitizedInput;
}