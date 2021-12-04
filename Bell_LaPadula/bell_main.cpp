#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

// 3 menu options, run test cases, enter two file paths, quit

void bellLaPadula()
{
    std::string userInput = "";
    std::string path1 = "";
    std::string path2 = "";
    bool keepRunning = true;

    // begin menu
    std::cout << "\nWelcome to the Bell-LaPadula Lab!";

    // while the user hasn't quit
    while (keepRunning)
    {
        std::cout << "\n1. Option 1\n2. Option 2\n3. Exit\n";
        std::cin >> userInput;
        std::cout << "\n";

        if (userInput == "1") // test cases
        {
            cout << "user input 1" << endl;
        }
        else if (userInput == "2") // custom paths
        {
            cout << "user input 2" << endl;
        }
        else if (userInput == "3") // exit
        {
            std::cout << "Thank you, goodbye\n";
            keepRunning = false;
        }
        else
            std::cout << "Please enter a valid option\n";
    }
}
