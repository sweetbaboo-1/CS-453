#pragma once
#include <iostream>
#include "homograph.cpp"

// Non Homographs
void nonHomographTests()
{
    std::string forbiddenPath = ".\\jacob\\secret\\password.txt";
    std::string testPathOne = "\\jacob\\secret\\password.txt";
    std::string testPathTwo = ".jacob\\secret\\password.txt";
    std::string testPathThree = "..\\password.txt";
    std::string testPathFour = "..\\secret\\password.txt";
    std::string userInput = "";
    bool keepRunning = true;

    std::cout << "\nNon Homograph Test Cases for C:\\Users\\jacob\\secret\\password.txt with the current directory being C:\\Users\\jacob\\:\n";
    std::cout << "1. " << testPathOne << std::endl;
    std::cout << "2. " << testPathTwo << std::endl;
    std::cout << "3. " << testPathThree << std::endl;
    std::cout << "4. " << testPathFour << std::endl;
    std::cout << "5. Exit\n"
              << std::endl;
    std::cout << "Please select a test case to run: ";

    while (keepRunning)
    {
        std::cin >> userInput;

        if (userInput == "1")
        {
            std::cout << "These paths are" << (areHomographs(forbiddenPath, testPathOne) ? " " : " not ") << "the same\n";
        }
        else if (userInput == "2")
        {
            std::cout << "These paths are" << (areHomographs(forbiddenPath, testPathTwo) ? " " : " not ") << "the same\n";
        }
        else if (userInput == "3")
        {
            std::cout << "These paths are" << (areHomographs(forbiddenPath, testPathThree) ? " " : " not ") << "the same\n";
        }
        else if (userInput == "4")
        {
            std::cout << "These paths are" << (areHomographs(forbiddenPath, testPathFour) ? " " : " not ") << "the same\n";
        }
        else if (userInput == "5")
        {
            keepRunning = false;
        }
    }
}

// Homographs
void homographTests()
{
}

// runs through all defined test cases to ensure the program is functioning correctly
void testCases()
{
    bool keepRunning = true;
    std::string userInput = "";

    while (keepRunning)
    {
        std::cout << "\nPlease select an option below:\n";
        std::cout << "1. Non Homograph Test case\n";
        std::cout << "2. Homograph Test case\n";
        std::cout << "3. Exit\n";
        std::cin >> userInput;

        if (userInput == "1")
        {
            nonHomographTests();
        }
        else if (userInput == "2")
        {
            homographTests();
        }
        else if (userInput == "3")
        {
            keepRunning = false;
        }
    }
}