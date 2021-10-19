#pragma once

#include <iomanip>

// All test cases should be in this file

struct TestCase
{
    std::string username;
    std::string password;
};

/*************************************
 * These test cases should be VALID
 * passwords MUST contain:
 * letters
 * numbers
 * underscores
 *************************************/
void validTestCases(TestCase testCases[6])
{
    // Matthew Peart
    TestCase mp;
    mp.username = "Matthew";
    mp.password = "P@ss_word1";
    testCases[0] = mp;

    // Christian Longhurst
    TestCase cl;
    cl.username = "";
    cl.password = "";
    testCases[1] = cl;

    // Chris Van Kammen
    TestCase cvk;
    cl.username = "";
    cl.password = "";
    testCases[2] = cvk;

    // Dylan Havens
    TestCase dh;
    cl.username = "";
    cl.password = "";
    testCases[3] = dh;

    // Sam Haymond
    TestCase sh;
    cl.username = "";
    cl.password = "";
    testCases[4] = sh;

    // Tyler Craig
    TestCase tc;
    cl.username = "";
    cl.password = "";
    testCases[5] = tc;
}

/**************************************
 * These test cases MUST demonstrate a 
 * tautology attack
 *************************************/
void tautologyAttackTestCases(TestCase testCases[6])
{
    // Matthew Peart
    TestCase mp;
    mp.username = "";
    mp.password = "";
    testCases[0] = mp;

    // Christian Longhurst
    TestCase cl;
    cl.username = "";
    cl.password = "";
    testCases[1] = cl;

    // Chris Van Kammen
    TestCase cvk;
    cl.username = "";
    cl.password = "";
    testCases[2] = cvk;

    // Dylan Havens
    TestCase dh;
    cl.username = "";
    cl.password = "";
    testCases[3] = dh;

    // Sam Haymond
    TestCase sh;
    cl.username = "";
    cl.password = "";
    testCases[4] = sh;

    // Tyler Craig
    TestCase tc;
    cl.username = "";
    cl.password = "";
    testCases[5] = tc;
}

/**************************************
 * These test cases MUST demonstrate a
 * union querry attack
 *************************************/
void unionQueryAttackTestCases(TestCase testCases[6])
{
    // Matthew Peart
    TestCase mp;
    mp.username = "";
    mp.password = "";
    testCases[0] = mp;

    // Christian Longhurst
    TestCase cl;
    cl.username = "";
    cl.password = "";
    testCases[1] = cl;

    // Chris Van Kammen
    TestCase cvk;
    cl.username = "";
    cl.password = "";
    testCases[2] = cvk;

    // Dylan Havens
    TestCase dh;
    cl.username = "";
    cl.password = "";
    testCases[3] = dh;

    // Sam Haymond
    TestCase sh;
    cl.username = "";
    cl.password = "";
    testCases[4] = sh;

    // Tyler Craig
    TestCase tc;
    cl.username = "";
    cl.password = "";
    testCases[5] = tc;
}

/**************************************
 * These test cases MUST demonstrate a 
 * additonal statement attack
 *************************************/
void additionalStatementAttackTestCases(TestCase testCases[6])
{
    // Matthew Peart
    TestCase mp;
    mp.username = "";
    mp.password = "";
    testCases[0] = mp;

    // Christian Longhurst
    TestCase cl;
    cl.username = "";
    cl.password = "";
    testCases[1] = cl;

    // Chris Van Kammen
    TestCase cvk;
    cl.username = "";
    cl.password = "";
    testCases[2] = cvk;

    // Dylan Havens
    TestCase dh;
    cl.username = "";
    cl.password = "";
    testCases[3] = dh;

    // Sam Haymond
    TestCase sh;
    cl.username = "";
    cl.password = "";
    testCases[4] = sh;

    // Tyler Craig
    TestCase tc;
    cl.username = "";
    cl.password = "";
    testCases[5] = tc;
}

/**************************************
 * These test cases MUST demonstrate a 
 * comment attack
 *************************************/
void commentAttackTestCases(TestCase testCases[6])
{
    // Matthew Peart
    TestCase mp;
    mp.username = "";
    mp.password = "";
    testCases[0] = mp;

    // Christian Longhurst
    TestCase cl;
    cl.username = "";
    cl.password = "";
    testCases[1] = cl;

    // Chris Van Kammen
    TestCase cvk;
    cl.username = "";
    cl.password = "";
    testCases[2] = cvk;

    // Dylan Havens
    TestCase dh;
    cl.username = "";
    cl.password = "";
    testCases[3] = dh;

    // Sam Haymond
    TestCase sh;
    cl.username = "";
    cl.password = "";
    testCases[4] = sh;

    // Tyler Craig
    TestCase tc;
    cl.username = "";
    cl.password = "";
    testCases[5] = tc;
}
