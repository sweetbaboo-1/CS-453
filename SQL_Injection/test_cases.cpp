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
inline void validTestCases(TestCase testCases[6])
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
inline void tautologyAttackTestCases(TestCase testCases[6])
{
    // Matthew Peart
    TestCase mp;
    mp.username = "Matthew";
    mp.password = "password\' OR \'x\' = \'x";
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
inline void unionQueryAttackTestCases(TestCase testCases[6])
{
    // Matthew Peart
    TestCase mp;
    mp.username = "Matthew";
    mp.password = "password\' UNION SELECT authenticate FROM passwordList";
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
inline void additionalStatementAttackTestCases(TestCase testCases[6])
{
    // Matthew Peart
    TestCase mp;
    mp.username = "Matthew";
    mp.password = "password\'; INSERT INTO passwordList (name, passwd) VALUES \'matt\', \'correcthorsebatterystaple";
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
inline void commentAttackTestCases(TestCase testCases[6])
{
    // Matthew Peart
    TestCase mp;
    mp.username = "Root\'; -- ";
    mp.password = "password";
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
