#include <iomanip>
#include <iostream>
#include <string>
#include "homograph.cpp"
#include "test_cases.cpp"

// 3 menu options, run test cases, enter two file paths, quit

int main()
{
    std::string userInput = "";
    std::string path1 = "";
    std::string path2 = "";
    bool keepRunning = true;

    // begin menu
    std::cout << "\nWelcome to the Homograph Lab!";

    // while the user hasn't quit
    while (keepRunning)
    {
        std::cout << "\n1. Run test cases\n2. Enter custom paths\n3. Exit\n";
        std::cin >> userInput;
        std::cout << "\n";

        if (userInput == "1") // test cases
        {
            testCases();
        }
        else if (userInput == "2") // custom paths
        {
            std::cout << "Please enter the first path: ";
            std::cin >> path1;
            std::cout << "Please enter the second path: ";
            std::cin >> path2;
            std::cout << "\nPaths, " << path1 << " and " << path2 << " are" << (areHomographs(path1, path2) ? " " : " not ") << "the same\n";
        }
        else if (userInput == "3") // exit
        {
            std::cout << "Thank you, goodbye\n";
            keepRunning = false;
        }
        else
            std::cout << "Please enter a valid option\n";
    }

    return 0;
}
