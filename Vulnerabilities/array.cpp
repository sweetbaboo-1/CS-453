#pragma once

#include <iostream>
/*************************************
 * array VULNERABILTY
 * 1. There must be an array and an array index variable
 * 2. The array index variable must be reachable through external input.
 * 3. There must not be bounds checking on the array index variable.
 ****************************************/
void arrayVulnerability(int index)
{
    bool array[4] = {false, false, false, false};
    bool authenticated = false; // the asset

    array[index] = true;
    std::cout << "authenticated = " << authenticated << std::endl;
}

/**************************************
 * array WORKING
 * Call arrayVulnerability() in a way that does
 * not yield unexpected behavior
 *************************************/
void arrayWorking()
{
    int index = 2;
    std::cout << "Calling arrayVulnerability with the valid index of " << index << std::endl;
	arrayVulnerability(index);
}

/**************************************
 * array EXPLOIT
 * 1. The attacker provides an array index value outside the expected range
 * 2. The attacker must be able to provide input or redirect existing input into the array at the index he provided
 * 3. The injected value must alter program state in a way that is desirable to the attacker    
 *************************************/
void arrayExploit()
{
	int index = 4;
    std::cout << "Calling arrayVulnerability with the invalid index of " << index << std::endl;
	arrayVulnerability(index);
}