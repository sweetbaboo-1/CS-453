
/***********************************************************************
 * COMPONENT:
 *    CONTROL
 * Author:
 *    Br. Helfrich, <Matthew Peart>
 * Summary:
 *    This class stores the notion of Bell-LaPadula
 ************************************************************************/


#include <iomanip>
#include <string>
#include <iostream>

using namespace std;



enum Control
{
    PUBLIC,
    CONFIDENTIAL,
    PRIVILEGED,
    SECRET
};


/* TODO: make it easier to add users*/
inline Control authenticate(string username, string password)
{
    Control control;
    // returns public confidential privileged secret depending on the status of the user
    if      (username == "AdmiralAbe"     && password == "password")
        return control = SECRET;
    else if (username == "CaptainCharlie" && password == "password")
        return control = PRIVILEGED;
    else if (username == "SeamanSam"      && password == "password")
        return control = CONFIDENTIAL;
    else if (username == "SeamanSue"      && password == "password")
        return control = CONFIDENTIAL;
    else if (username == "SeamanSly"      && password == "password")
        return control = CONFIDENTIAL;
    else
        return control = PUBLIC;
}

inline bool securityConditionRead(Control assetControl, Control subjectControl)
{
    return subjectControl >= assetControl;
}

inline bool securityConditionWrite(Control assetControl, Control subjectControl)
{
    return subjectControl <= assetControl;
}

#endif //PATHDEBUNKER_CPP_INTERACT_H
