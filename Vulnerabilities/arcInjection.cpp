/*************************************
 * arc VULNERABILTY
 * 1. There must be an arc and an arc index variable
 * 2. The arc index variable must be reachable through external input.
 * 3. There must not be bounds checking on the arc index variable.
 ****************************************/
void arcVulnerability(/* feel free to add parameters */)
{
}

/**************************************
 * arc WORKING
 * Call arcVulnerability() in a way that does
 * not yield unexpected behavior
 *************************************/
void arcWorking()
{
	arcVulnerability(/* parameters with non-malicious data */);
}

/**************************************
 * arc EXPLOIT
 * 1. The attacker provides an arc index value outside the expected range
 * 2. The attacker must be able to provide input or redirect
 *    existing input into the arc at the index he provided
 * 3. The injected value must alter program state in a way
 *    that is desirable to the attacker
 *************************************/
void arcExploit()
{
	arcVulnerability(/* parameters with malicious data */);
}