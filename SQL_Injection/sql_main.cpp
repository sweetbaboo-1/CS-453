#include "test_cases.cpp"
#include "query_generator.cpp"
#include "mitigation_strategies.cpp"

#include <iostream>

void displayQueries(std::string queries[6])
{
    for (int i = 0; i < 6; i++)
    {
        std::cout << "\t\t" << queries[i] << std::endl;
    }
}

void sanitizeTestCases(TestCase cases[6], bool weak)
{
    std::string queries[6];
    for (int i = 0; i < 6; i++)
    {
        if (weak)
        {
            cases[i].username = weakMitigation(cases[i].username);
            cases[i].password = weakMitigation(cases[i].password);
        }
        else
        {
            cases[i].username = strongMitigation(cases[i].username);
            cases[i].password = strongMitigation(cases[i].password);
        }
    }
    generateQuerys(cases, queries);
    displayQueries(queries);
}

void sql()
{
    bool keepRunning = true;
    std::string userInput = "";
    TestCase testCases[6];
    std::string queries[6];
    TestCase sanitizedInputs[6];
    while (keepRunning)
    {
        std::cout << "\n1. Valid Test Cases\n2. Tautology Attacks\n3. Union Query Attacks\n4. Additional Statement Attacks\n5. Comment Attacks\n6. Exit\n";
        std::cin >> userInput;
        std::cout << "\n";

        //generate queries off of test cases, display them, sanitize them then display the result

        if (userInput == "1") // valid test cases
        {
            std::cout << "Valid Test Cases:\n\n\tNo Mitigation\n";
            validTestCases(testCases); // testcases now has all valid test cases
            generateQuerys(testCases, queries);
            displayQueries(queries);

            std::cout << "\n\tWeak Mitigation\n";
            validTestCases(testCases);
            sanitizeTestCases(testCases, true);

            std::cout << "\n\tStrong Mitigation\n";
            validTestCases(testCases);
            sanitizeTestCases(testCases, false);
        }
        else if (userInput == "2") // tautology
        {
            std::cout << "Tautology Attack:\n\n\tNo Mitigation\n";
            tautologyAttackTestCases(testCases); // testcases now has all valid test cases
            generateQuerys(testCases, queries);
            displayQueries(queries);

            std::cout << "\n\tWeak Mitigation\n";
            tautologyAttackTestCases(testCases);
            sanitizeTestCases(testCases, true);

            std::cout << "\n\tStrong Mitigation\n";
            tautologyAttackTestCases(testCases);
            sanitizeTestCases(testCases, false);
        }
        else if (userInput == "3") // union query
        {
            std::cout << "Union Attack:\n\n\tNo Mitigation\n";
            unionQueryAttackTestCases(testCases); // testcases now has all valid test cases
            generateQuerys(testCases, queries);
            displayQueries(queries);

            std::cout << "\n\tWeak Mitigation\n";
            unionQueryAttackTestCases(testCases);
            sanitizeTestCases(testCases, true);

            std::cout << "\n\tStrong Mitigation\n";
            unionQueryAttackTestCases(testCases);
            sanitizeTestCases(testCases, false);
        }
        else if (userInput == "4") // additonal statment
        {
            std::cout << "Additonal Statement:\n\n\tNo Mitigation\n";
            additionalStatementAttackTestCases(testCases); // testcases now has all valid test cases
            generateQuerys(testCases, queries);
            displayQueries(queries);

            std::cout << "\n\tWeak Mitigation\n";
            additionalStatementAttackTestCases(testCases);
            sanitizeTestCases(testCases, true);

            std::cout << "\n\tStrong Mitigation\n";
            additionalStatementAttackTestCases(testCases);
            sanitizeTestCases(testCases, false);
        }
        else if (userInput == "5") // comment
        {
            std::cout << "Comment Attack:\n\n\tNo Mitigation\n";
            commentAttackTestCases(testCases); // testcases now has all valid test cases
            generateQuerys(testCases, queries);
            displayQueries(queries);

            std::cout << "\n\tWeak Mitigation\n";
            commentAttackTestCases(testCases);
            sanitizeTestCases(testCases, true);

            std::cout << "\n\tStrong Mitigation\n";
            commentAttackTestCases(testCases);
            sanitizeTestCases(testCases, false);
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