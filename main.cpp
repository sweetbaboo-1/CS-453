#include <iomanip>
#include <iostream>
#include "canonicalization.h"
#include "homograph.h"
#include "test_cases.cpp"


// 3 menu options, run test cases, enter two file paths, quit

int main()
{
    int userInput = 0;
    bool keepRunning = true;
    std::string path1, path2 = "";

    std::cout << "Welcome to the Homograph Lab!";
    

    while (keepRunning)
    {
        std::cout << "\n1. Run test cases\n2. Enter custom paths\n3. Exit\n";
        std::cin >> userInput;
        std::cout << "\n";
        switch (userInput)
        {
        case 1:
            testCases();
            break;
        case 2:
            std::cout << "Please enter the first path: ";
            std::cin >> path1;
            std::cout << "Please enter the second path: ";
            std::cin >> path2;
            // TODO this line prevents building, undefined reference error.
            //areHomographs(path1, path2) ? std::cout << "Paths, " << path1 << " and " << path2 << " are the same." : std::cout << "Paths, " << path1 << " and " << path2 << " are not the same.";
            break;
        case 3:
            keepRunning = false;
            break;
        default:
            std::cout << "Please enter a valid option\n";
            break;
        }
    }

    return 0;
}
