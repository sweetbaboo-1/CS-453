#pragma once
#include <iostream>
#include "homograph.cpp"

// Non Homographs
inline void nonHomographTests()
{
    std::string forbiddenPath = ".\\jacob\\secret\\password.txt";
    std::string testPathOne = "\\jacob\\secret\\password.txt";
    std::string testPathTwo = ".jacob\\secret\\password.txt";
    std::string testPathThree = "..\\password.txt";
    std::string testPathFour = "..\\secret\\password.txt";
    std::string testPathFive = "..\\..\\jacob\\secret\\password.txt";
    std::string testPathSix = "..\\..\\..\\secret\\password.txt";
    std::string testPathSeven = "..\\jacob\\secret\\password.txt";
    std::string userInput = "";
    bool keepRunning = true;

    std::cout << "\nNon Homograph Test Cases for C:\\Users\\jacob\\secret\\password.txt with the current directory being C:\\Users\\jacob\\:\n";
    std::cout << "1. " << testPathOne << std::endl;
    std::cout << "2. " << testPathTwo << std::endl;
    std::cout << "3. " << testPathThree << std::endl;
    std::cout << "4. " << testPathFour << std::endl;
    std::cout << "5. " << testPathFive << std::endl;
    std::cout << "6. " << testPathSix << std::endl;
    std::cout << "7. " << testPathSeven << std::endl;
    std::cout << "8. Exit\n"
              << std::endl;
    std::cout << "Please select a test case to run: ";

    while (keepRunning) // user hasn't quit
    {
        std::cin >> userInput;

        if (userInput == "1")
        {
            std::cout << "These paths are" << (areHomographs(forbiddenPath, testPathOne) ? " " : " not ") << "homographs\n";
        }
        else if (userInput == "2")
        {
            std::cout << "These paths are" << (areHomographs(forbiddenPath, testPathTwo) ? " " : " not ") << "homographs\n";
        }
        else if (userInput == "3")
        {
            std::cout << "These paths are" << (areHomographs(forbiddenPath, testPathThree) ? " " : " not ") << "homographs\n";
        }
        else if (userInput == "4")
        {
            std::cout << "These paths are" << (areHomographs(forbiddenPath, testPathFour) ? " " : " not ") << "homographs\n";
        }
        else if (userInput == "5")
        {
            std::cout << "These paths are" << (areHomographs(forbiddenPath, testPathFive) ? " " : " not ") << "homographs\n";
        }
        else if (userInput == "6")
        {
            std::cout << "These paths are" << (areHomographs(forbiddenPath, testPathSix) ? " " : " not ") << "homographs\n";
        }
        else if (userInput == "7")
        {
            std::cout << "These paths are" << (areHomographs(forbiddenPath, testPathSeven) ? " " : " not ") << "homographs\n";
        }
        else if (userInput == "8")
        {
            keepRunning = false;
        }
    }
}

// Homographs
inline void homographTests()
{
    std::string forbiddenPath = ".\\jacob\\secret\\password.txt";
    std::string testPathOne = ".\\jacob/secret/password.txt";
    std::string testPathTwo = ".\\Jacob\\secret\\password.txt";
    std::string testPathThree = ".\\JACOB\\secret\\password.txt";
    std::string testPathFour = ".\\jacob\\secret\\password.txt";
    std::string testPathFive = ".\\jacob/secret\\password.txt";
    std::string testPathSix = ".\\jacob\\secret\\password";
    std::string testPathSeven = ".\\JACOB/SECRET/PASSWORD.TXT";
    std::string userInput = "";
    bool keepRunning = true;

    std::cout << "\nHomograph Test Cases for C:\\Users\\jacob\\secret\\password.txt with the current directory being C:\\Users\\jacob\\:\n";
    std::cout << "1. " << testPathOne << std::endl;
    std::cout << "2. " << testPathTwo << std::endl;
    std::cout << "3. " << testPathThree << std::endl;
    std::cout << "4. " << testPathFour << std::endl;
    std::cout << "5. " << testPathFive << std::endl;
    std::cout << "6. " << testPathSix << std::endl;
    std::cout << "7. " << testPathSeven << std::endl;
    std::cout << "8. Exit\n"
              << std::endl;
    std::cout << "Please select a test case to run: ";

    while (keepRunning) // user hasn't quit
    {
        std::cin >> userInput;

        if (userInput == "1")
        {
            std::cout << "These paths are" << (areHomographs(forbiddenPath, testPathOne) ? " " : " not ") << "homographs\n";
        }
        else if (userInput == "2")
        {
            std::cout << "These paths are" << (areHomographs(forbiddenPath, testPathTwo) ? " " : " not ") << "homographs\n";
        }
        else if (userInput == "3")
        {
            std::cout << "These paths are" << (areHomographs(forbiddenPath, testPathThree) ? " " : " not ") << "homographs\n";
        }
        else if (userInput == "4")
        {
            std::cout << "These paths are" << (areHomographs(forbiddenPath, testPathFour) ? " " : " not ") << "homographs\n";
        }
        else if (userInput == "5")
        {
            std::cout << "These paths are" << (areHomographs(forbiddenPath, testPathFive) ? " " : " not ") << "homographs\n";
        }
        else if (userInput == "6")
        {
            std::cout << "These paths are" << (areHomographs(forbiddenPath, testPathSix) ? " " : " not ") << "homographs\n";
        }
        else if (userInput == "7")
        {
            std::cout << "These paths are" << (areHomographs(forbiddenPath, testPathSeven) ? " " : " not ") << "homographs\n";
        }
        else if (userInput == "8")
        {
            keepRunning = false;
        }
    }
}

// runs through all defined test cases to ensure the program is functioning correctly
inline void testCases()
{
    bool keepRunning = true;
    std::string userInput = "";

    while (keepRunning) // user hasn't quit
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