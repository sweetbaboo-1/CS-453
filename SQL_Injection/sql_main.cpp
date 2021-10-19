#include "test_cases.cpp"
#include "query_generator.cpp"
#include "mitigation_strategies.cpp"

void sql()
{
    bool keepRunning = true;
    TestCase testCases[6];
    std::string queries[6];
    while (keepRunning)
    {
        std::cout << "\n1. Valid test cases\n2. Tautology attacks\n3. Union query attacks\n4. Additional statement attacks\n5. Comment attacks\n";
        std::cin >> userInput;
        std::cout << "\n";

        if (userInput == "1") // valid test cases
        {
            generateQuerys(validTestCases(testCases, queries));
        }
        else if (userInput == "2") // tautology
        {
            generateQuerys(tautologyAttackTestCases(testCases, queries));
        }
        else if (userInput == "3") // union query
        {
            generateQuerys(unionQueryAttackTestCases(testCases, queries));
        }
        else if (userInput == "4") // additonal statment
        {
            generateQuerys(additionalStatementAttackTestCases(testCases, queries));
        }
        else if (userInput == "5") // comment
        {
            generateQuerys(commentAttackTestCases(testCases, queries));
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
