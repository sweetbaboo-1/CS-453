#include <iomanip>
#include <iostream>
#include <string>
#include "lab12.cpp"

using namespace std;


void bellLaPadula()
{
    string userInput = "";
    string path1 = "";
    string path2 = "";
    bool keepRunning = true;

    // begin menu
    cout << "\nWelcome to the Bell-LaPadula Lab!";

    // while the user hasn't quit
    while (keepRunning)
    {
        cout << "\n1. Run Bell-LaPadula Lab\n2. Option 2\n3. Exit\n";
        cin >> userInput;
        cout << "\n";

        if (userInput == "1") // test cases
        {
            main();
        }
        else if (userInput == "2") // custom paths
        {
            cout << "user input 2" << endl;
        }
        else if (userInput == "3") // exit
        {
            cout << "Thank you, goodbye\n";
            keepRunning = false;
        }
        else
            cout << "Please enter a valid option\n";
    }
}
