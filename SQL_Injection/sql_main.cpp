#include "test_cases.cpp"
#include "query_generator.cpp"
#include "mitigation_strategies.cpp"

#include <iostream>

void displaySanitizedInputs(std::string inputs[6])
{
    for (int i = 0; i < 6; i++)
    {
        std::cout << inputs[i] << std::endl;
    }
}

void sql()
{
    bool keepRunning = true;
    std::string userInput = "";
    TestCase testCases[6];
    std::string queries[6];
    std::string sanitizedInputs[6];
    while (keepRunning)
    {
        std::cout << "\n1. Valid test cases\n2. Tautology attacks\n3. Union query attacks\n4. Additional statement attacks\n5. Comment attacks\n6. Exit\n";
        std::cin >> userInput;
        std::cout << "\n";

        if (userInput == "1") // valid test cases
        {
            std::cout << "Valid Test Cases:\n";
            validTestCases(testCases);
            generateQuerys(testCases, queries);
            std::cout << "\nWeak Mitigation\n";
            runWeakMitigation(queries, sanitizedInputs);
            displaySanitizedInputs(sanitizedInputs);
        }
        else if (userInput == "2") // tautology
        {
            std::cout << "Tautology Test Cases:\n";
            tautologyAttackTestCases(testCases);
            generateQuerys(testCases, queries);
            std::cout << "\nWeak Mitigation\n";
            runWeakMitigation(queries, sanitizedInputs);
            displaySanitizedInputs(sanitizedInputs);
        }
        else if (userInput == "3") // union query
        {
            std::cout << "Union Query Test Cases:\n";
            unionQueryAttackTestCases(testCases);
            generateQuerys(testCases, queries);
            std::cout << "\nWeak Mitigation\n";
            runWeakMitigation(queries, sanitizedInputs);
            displaySanitizedInputs(sanitizedInputs);
        }
        else if (userInput == "4") // additonal statment
        {
            std::cout << "Additional Statement Test Cases:\n";
            additionalStatementAttackTestCases(testCases);
            generateQuerys(testCases, queries);
            std::cout << "\nWeak Mitigation\n";
            runWeakMitigation(queries, sanitizedInputs);
            displaySanitizedInputs(sanitizedInputs);
        }
        else if (userInput == "5") // comment
        {
            std::cout << "Comment Attack Test Cases:\n";
            commentAttackTestCases(testCases);
            generateQuerys(testCases, queries);
            std::cout << "\nWeak Mitigation\n";
            runWeakMitigation(queries, sanitizedInputs);
            displaySanitizedInputs(sanitizedInputs);
        }
        else if (userInput == "6") // exit
        {
            std::cout << "Thank you, goodbye\n";
            keepRunning = false;
        }
        else
            std::cout << "Please enter a valid option\n";
    }
}
