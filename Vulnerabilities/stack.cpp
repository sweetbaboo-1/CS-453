#pragma once

#include <iostream>
/*************************************
 * stack VULNERABILTY
 * 1. There must be a buffer (such as an array) on the stack.
 * 2. The buffer must be reachable from an external input.
 * 3. The mechanism to fill the buffer from the external input must not correctly check for the buffer size.
 * 4. A buffer overrun (extend beyond the intended limits of the array) must extend to the return address on the stack
 ****************************************/
void stackVulnerability(char externalInput[256], int numChars)
{
    char name[128];
    for (int i = 0; i < numChars; i++)
    {
        name[i] = externalInput[i];
    }
}

/**************************************
 * stack WORKING
 * Call stackVulnerability() in a way that does
 * not yield unexpected behavior
 *************************************/
void stackWorking()
{
    int index = 2;
    std::cout << "Calling arrayVulnerability with the valid index of " << index << std::endl;
    char charArray[] = {'m','a','t','t','h','e','w'};
	stackVulnerability(charArray, 7);
}

/**************************************
 * stack EXPLOIT
 * 1. The attacker must provide more data into the outwardly facing buffer than the buffer is designed to hold.
 * 2. The attacker must know where the return address pointer resides on the stack. This should be just beyond the end of the buffer.
 * 3. The attacker must insert machine language instructions in the buffer. This may occur before, after, or even around the return address pointer. The machine language could be already compiled code in the program
 * 4. The attacker must overwrite the return address. The old value, directing the flow of the program after the function is returned, must be changed from the calling function to the provided machine language in step 3.
 *************************************/
void stackExploit()
{
	int index = 4;
    std::cout << "Calling arrayVulnerability with the invalid index of " << index << std::endl;
	stackVulnerability(index);
}

void ifThisRunsTheCodeWasExploited() 
{
    std::cout << "The stack was smashed";
}