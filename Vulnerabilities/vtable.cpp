/*************************************
 * vtable VULNERABILTY
 * 1. There must be an vtable and an vtable index variable
 * 2. The vtable index variable must be reachable through external input.
 * 3. There must not be bounds checking on the vtable index variable.
 ****************************************/
void vtableVulnerability(/* feel free to add parameters */)
{
}

/**************************************
 * vtable WORKING
 * Call vtableVulnerability() in a way that does
 * not yield unexpected behavior
 *************************************/
void vtableWorking()
{
	vtableVulnerability(/* parameters with non-malicious data */);
}

/**************************************
 * vtable EXPLOIT
 * 1. The attacker provides an vtable index value outside the expected range
 * 2. The attacker must be able to provide input or redirect
 *    existing input into the vtable at the index he provided
 * 3. The injected value must alter program state in a way
 *    that is desirable to the attacker
 *************************************/
void vtableExploit()
{
	vtableVulnerability(/* parameters with malicious data */);
}