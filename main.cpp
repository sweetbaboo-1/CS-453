#include "Homograph/homograph_main.cpp"
#include "SQL_Injection/sql_main.cpp"
#include "Memory_Organization/memory_organization_main.cpp"
#include "Vulnerabilities/vulnerabilitiesExploitsMain.cpp"
int main()
{
    bool keepRunning = true;
    std::string userInput = "";

    while (keepRunning)
    {
        std::cout << "\n1. Homograph Lab\n2. SQL Injection Lab\n3. Memory Lab\n4. Vulnerabilities Lab\nQ. Exit\n";
        std::cin >> userInput;

        if (userInput == "1") // Homograph Lab
            homograph();
        else if (userInput == "2") // SQL Injection Lab
            sql();
        else if (userInput == "3")
        { 
            //memory_main();
            int x = 2;
        }
        else if (userInput == "4")
            vulnerabilities_main();
        else if (userInput == "q" || userInput == "Q") // exit
        {
            std::cout << "Thank you, goodbye\n";
            keepRunning = false;
        }
        else
            std::cout << "Please enter a valid option\n";
    }
    return 0;
}
