#include <iomanip>
#include <iostream>
#include "canonicalization.h" //TODO cpp?
#include "homograph.h"
#include "test_cases.h"

// 3 menu options, run test cases, enter two file paths, quit

int main()
{
    std::string userInput = "";
    std::string path1 = "";
    std::string path2 = "";
    bool keepRunning = true;

    // begin menu
    std::cout << "Welcome to the Homograph Lab!";

    // while the user hasn't quit
    while (keepRunning)
    {
        std::cout << "\n1. Run test cases\n2. Enter custom paths\n3. Exit\n";
        std::cin >> userInput;
        std::cout << "\n";

        if (userInput == "1")
            testCases();
        else if (userInput == "2")
        {
            std::cout << "Please enter the first path: ";
            std::cin >> path1;
            std::cout << "Please enter the second path: ";
            std::cin >> path2;
            // TODO this line prevents building, undefined reference error.
            std::cout << "\n";
            areHomographs(path1, path2) ? std::cout << "Paths, " << path1 << " and " << path2 << " are the same.\n" : std::cout << "Paths, " << path1 << " and " << path2 << " are not the same.\n";
        }
        else if (userInput == "3")
        {
            std::cout << "Thank you, goodbye";
            keepRunning = false;
        }
        else
            std::cout << "Please enter a valid option\n";
    }

    return 0;
}
