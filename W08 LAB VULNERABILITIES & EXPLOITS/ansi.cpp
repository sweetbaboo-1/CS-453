/*************************************
 * ansi VULNERABILTY
 * 1. There must be an ansi and an ansi index variable
 * 2. The ansi index variable must be reachable through external input.
 * 3. There must not be bounds checking on the ansi index variable.
 ****************************************/
void ansiVulnerability(/* feel free to add parameters */)
{
}

/**************************************
 * ansi WORKING
 * Call ansiVulnerability() in a way that does
 * not yield unexpected behavior
 *************************************/
void ansiWorking()
{
	ansiVulnerability(/* parameters with non-malicious data */);
}

/**************************************
 * ansi EXPLOIT
 * 1. The attacker provides an ansi index value outside the expected range
 * 2. The attacker must be able to provide input or redirect
 *    existing input into the ansi at the index he provided
 * 3. The injected value must alter program state in a way
 *    that is desirable to the attacker
 *************************************/
void ansiExploit()
{
	ansiVulnerability(/* parameters with malicious data */);
}