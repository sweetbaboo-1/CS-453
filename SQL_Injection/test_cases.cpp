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
void validTestCases(TestCase testCases[])
{
    // Matthew Peart
    TestCase mp;
    mp.username = "Matthew";
    mp.password = "P@ss_word1";
    testCases[0] = mp;

    // Christian Longhurst
    TestCase cl;
    cl.username = "Christian";
    cl.password = "p@55w0rd";
    testCases[1] = cl;

    // Chris Van Kammen
    TestCase cvk;
    cvk.username = "";
    cvk.password = "";
    testCases[2] = cvk;

    // Dylan Havens
    TestCase dh;
    dh.username = "Dylan";
    dh.password = "H3ll0_W0r1d";
    testCases[3] = dh;

    // Sam Haymond
    TestCase sh;
    sh.username = "dreyvonn";
    sh.password = "CableBoy45";
    testCases[4] = sh;

    // Tyler Craig
    TestCase tc;
    tc.username = "Tyler";
    tc.password = "blahblah";
    testCases[5] = tc;
}

/**************************************
 * These test cases MUST demonstrate a 
 * tautology attack
 *************************************/
void tautologyAttackTestCases(TestCase testCases[])
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
    cvk.username = "homeStarLegend%$#";
    cvk.password = "takingout OR date";
    testCases[2] = cvk;

    // Dylan Havens
    TestCase dh;
    dh.username = "Dylan";
    dh.password = "andThisAsWell\' OR username = TargetedUser";
    testCases[3] = dh;

    // Sam Haymond
    TestCase sh;
    sh.username = "dreyvonn";
    sh.password = "Tautology\' OR 1 = 1";
    testCases[4] = sh;

    // Tyler Craig
    TestCase tc;
    tc.username = "";
    tc.password = "";
    testCases[5] = tc;
}

/**************************************
 * These test cases MUST demonstrate a
 * union querry attack
 *************************************/
void unionQueryAttackTestCases(TestCase testCases[])
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
    cvk.username = "wizardgandolf";
    cvk.password = "you are being hacked UNION SELECT";
    testCases[2] = cvk;

    // Dylan Havens
    TestCase dh;
    dh.username = "Dylan Havens";
    dh.password = "dylanPassword\' UNION SELECT * FROM passwordList";
    testCases[3] = dh;

    // Sam Haymond
    TestCase sh;
    sh.username = "dreyvonn";
    sh.password = "password\' UNION    SELECT authenicate FROM passwordList";
    testCases[4] = sh;

    // Tyler Craig
    TestCase tc;
    tc.username = "";
    tc.password = "";
    testCases[5] = tc;
}

/**************************************
 * These test cases MUST demonstrate a 
 * additonal statement attack
 *************************************/
void additionalStatementAttackTestCases(TestCase testCases[])
{
    // Matthew Peart
    TestCase mp;
    mp.username = "Matthew";
    mp.password = "password\'; iNsErT INTO passwordList (name, passwd) VALUES \'matt\', \'correcthorsebatterystaple\'";
    testCases[0] = mp;

    // Christian Longhurst
    TestCase cl;
    cl.username = "";
    cl.password = "";
    testCases[1] = cl;

    // Chris Van Kammen
    TestCase cvk;
    cvk.username = "poleroidMan";
    cvk.password = "; SELECT * FROM passwordList LEFT JOIN myOwnTable on passwordList.passwords=myOwnTable.passwords;";
    testCases[2] = cvk;

    // Dylan Havens
    TestCase dh;
    dh.username = "Dylan";
    dh.password = "dylanPassword\'; UPDATE passwordList SET name = Dylan, passwd = dylanPassword";
    testCases[3] = dh;

    // Sam Haymond
    TestCase sh;
    sh.username = "dreyvonn";
    sh.password = "password\' DROP TABLE passwordList";
    testCases[4] = sh;

    // Tyler Craig
    TestCase tc;
    tc.username = "";
    tc.password = "";
    testCases[5] = tc;
}

/**************************************
 * These test cases MUST demonstrate a 
 * comment attack
 *************************************/
void commentAttackTestCases(TestCase testCases[])
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
    cvk.username = "poleroidMan; --";
    cvk.password = "password";
    testCases[2] = cvk;

    // Dylan Havens
    TestCase dh;
    dh.username = "Dylan";
    dh.password = "myPass; /*";
    testCases[3] = dh;

    // Sam Haymond
    TestCase sh;
    sh.username = "Root\'     --     ";
    sh.password = "nothing";
    testCases[4] = sh;

    // Tyler Craig
    TestCase tc;
    tc.username = "";
    tc.password = "";
    testCases[5] = tc;
}
