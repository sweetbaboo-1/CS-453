#include "test_cases.cpp"
#include "query_generator.cpp"
#include "mitigation_strategies.cpp"

#include <iostream>

void sql()
{
    bool keepRunning = true;
    std::string userInput = "";
    TestCase testCases[6];
    std::string queries[6];
    while (keepRunning)
    {
        std::cout << "\n1. Valid test cases\n2. Tautology attacks\n3. Union query attacks\n4. Additional statement attacks\n5. Comment attacks\n6. Exit\n";
        std::cin >> userInput;
        std::cout << "\n";

        if (userInput == "1") // valid test cases
        {
            validTestCases(testCases);
        }
        else if (userInput == "2") // tautology
        {
            tautologyAttackTestCases(testCases);
        }
        else if (userInput == "3") // union query
        {
            unionQueryAttackTestCases(testCases);
        }
        else if (userInput == "4") // additonal statment
        {
            additionalStatementAttackTestCases(testCases);
        }
        else if (userInput == "5") // comment
        {
            commentAttackTestCases(testCases);
        }
        else if (userInput == "6") // exit
        {
            std::cout << "Thank you, goodbye\n";
            keepRunning = false;
        }
        else
            std::cout << "Please enter a valid option\n";
        
        generateQuerys(testCases, queries);
        for(int i = 0; i < 6; i++)
        {
            std::cout << queries[i] << std::endl;
        }
    }
}
