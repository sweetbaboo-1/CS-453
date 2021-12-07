#include "Homograph/homograph_main.cpp"
#include "SQL_Injection/sql_main.cpp"
// #include "Memory_Organization/memory_organization_main.cpp"
#include "Vulnerabilities_Exploits/vulnerabilitiesExploitsMain.cpp"

int main()
{
    bool keepRunning = true;
    std::string userInput = "";

    while (keepRunning)
    {
        std::cout << "\n1. Homograph Lab\n2. SQL Injection Lab\n3. Memory Lab\n4. Vulnerabilites and Exploits Lab\n5. Bell-LaPadula\nQ. Exit\n";
        std::cin >> userInput;

        if (userInput == "1") // Homograph Lab
            homograph();
        else if (userInput == "2") // SQL Injection Lab
            sql();
        else if (userInput == "3")
            // memory_main();
            cout << "commented out because not working" << endl;
        else if (userInput == "4")
            vulnerabilitiesExploitsMain();
        else if (userInput == "5")
            encriptionMain();
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
