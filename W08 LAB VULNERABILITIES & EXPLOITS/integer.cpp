/*************************************
 * integerOverflow VULNERABILTY
 * 1. There must be an integerOverflow and an integerOverflow index variable
 * 2. The integerOverflow index variable must be reachable through external input.
 * 3. There must not be bounds checking on the integerOverflow index variable.
 ****************************************/
void intVulnerability(/* feel free to add parameters */)
{
}

/**************************************
 * integerOverflow WORKING
 * Call integerOverflowVulnerability() in a way that does
 * not yield unexpected behavior
 *************************************/
void intWorking()
{
	intVulnerability(/* parameters with non-malicious data */);
}

/**************************************
 * integerOverflow EXPLOIT
 * 1. The attacker provides an integerOverflow index value outside the expected range
 * 2. The attacker must be able to provide input or redirect
 *    existing input into the integerOverflow at the index he provided
 * 3. The injected value must alter program state in a way
 *    that is desirable to the attacker
 *************************************/
void intExploit()
{
	intVulnerability(/* parameters with malicious data */);
}