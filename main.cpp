#include "Homograph/homograph_main.cpp"
#include "SQL_Injection/sql_main.cpp"

int main()
{
    bool keepRunning = true;
    std::string userInput = "";
    
    while (keepRunning)
    {
        std::cout << "\n1. Homograph Lab\n2. SQL Injection lab\n3. Exit\n";
        std::cin >> userInput;
        std::cout << "\n";

        if (userInput == "1") // Homograph Lab
        {
            homograph();
        }
        else if (userInput == "2") // SQL Injection Lab
        {
            sql();
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
