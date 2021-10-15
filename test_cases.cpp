#pragma once
#include <iostream>
#include "homograph.cpp"
using namespace std;
string PATH = "/home/user/cse453/secret/password.txt";

// Non Homographs
string nonHomograph1 = "home/user/cse453/secret/password.txt";
string nonHomograph2 = "./secret/password.txt";
string nonHomograph3 = "../password.txt";
// Homographs
string homograph1 = "/home/user/cse453/secret/password.txt";
string homograph2 = "/Home/user/cse453/secret/password.txt";
string homograph3 = "./../secret/password.txt";
// runs through all defined test cases to ensure the program is functioning correctly
void testCases() {
    cout << "Running test cases...\n";
    cout << "------ Non-homographs ------" << endl;
    cout << PATH << " and " << nonHomograph1 << " : " << areHomographs(PATH, nonHomograph1) << endl;
}