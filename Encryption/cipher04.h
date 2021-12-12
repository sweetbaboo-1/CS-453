/********************************************************************
* Header:
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#ifndef CIPHER04_H
#define CIPHER04_H


using namespace std;
/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher04 : public Cipher
{
public:
    virtual string getPseudoAuth() { return "Christopher Van Kammen"; }
    virtual string getCipherName() { return "Substitution cipher"; }
    virtual string getEncryptAuth() { return "Christopher Van Kammen"; }
    virtual string getDecryptAuth() { return "Christopher Van Kammen"; }

    /***********************************************************
     * GET CIPHER CITATION
     * Returns the citation from which we learned about the cipher
     ***********************************************************/
    virtual string getCipherCitation()
    {
        return string("Simon Singh. (n.d.). Crypto. Practical Cryptography.\n"
            "http://practicalcryptography.com/ciphers/classical-era/simple-substitution/");
    }

    /**********************************************************
     * GET PSEUDOCODE
     * Returns the pseudocode as a string to be used by the caller.
     **********************************************************/
    virtual string getPseudocode()
    {
        string str;

        // TODO: please format your pseudocode
        // The encrypt pseudocode
        str = "";

        // The decrypt pseudocode
        str += "insert the decryption pseudocode\n";

        return str;
    }

    /**********************************************************
     * ENCRYPT
     * TODO: ADD description
     **********************************************************/
    virtual string encrypt(const string& plainText,
        const string& password)
    {
        int count = 0;
        string cipherText;
        for (int i = plainText.length() - 1; i >= 0; i--)
        {
            cipherText += substitution.find(plainText[count])->second;
            count++;
        }
        return cipherText;
    }

    /**********************************************************
     * DECRYPT
     * TODO: ADD description
     **********************************************************/
    virtual string decrypt(const string& cipherText,
        const string& password)
    {
        string plainText;
        int count = 0;
        for (int i = cipherText.length() - 1; i >= 0; i--)
        {
            plainText += substitutionReverse.find(cipherText[count])->second;
            count++;
        }
        return plainText;
    }

private:
    map<char, char> substitution = {
               { 'a', 'q' },
               { 'b', 'w' },
               { 'c', 'e' },
               { 'd', 'r' },
               { 'e', 't' },
               { 'f', 'y' },
               { 'g', 'u' },
               { 'h', 'i' },
               { 'i', 'o' },
               { 'j', 'p' },
               { 'k', '[' },
               { 'l', ']' },
               { 'm', 'a' },
               { 'n', 's' },
               { 'o', 'd' },
               { 'p', 'f' },
               { 'q', 'g' },
               { 'r', 'h' },
               { 's', 'j' },
               { 't', 'k' },
               { 'u', 'l' },
               { 'v', ';' },
               { 'w', '1' },
               { 'x', 'z' },
               { 'y', 'x' },
               { 'z', 'c' },
               { 'A', 'v' },
               { 'B', 'b' },
               { 'C', 'n' },
               { 'D', 'm' },
               { 'E', 'm' },
               { 'F', ',' },
               { 'G', '.' },
               { 'H', '/' },
               { 'I', 'Q' },
               { 'J', 'W' },
               { 'K', 'E' },
               { 'L', 'R' },
               { 'M', 'T' },
               { 'N', 'T' },
               { 'O', 'Y' },
               { 'P', 'U' },
               { 'Q', 'I' },
               { 'R', 'O' },
               { 'S', 'P' },
               { 'T', '{' },
               { 'U', '}' },
               { 'V', '|' },
               { 'W', 'A' },
               { 'X', 'S' },
               { 'Y', 'D' },
               { 'Z', 'F' },
               { '0', 'G' },
               { '1', 'H' },
               { '2', 'J' },
               { '3', 'K' },
               { '4', 'L' },
               { '5', 'Z' },
               { '6', 'X' },
               { '7', 'C' },
               { '8', 'V' },
               { '9', 'B' },
               { '!', 'N' },
               { '@', 'M' },
               { '#', '<' },
               { '$', '>' },
               { '%', '?' },
               { '^', '2' },
               { '&', '3' },
               { '*', '4' },
               { '(', '5' },
               { ')', '6' },
               { '-', '7' },
               { '_', '8' },
               { '=', '9' },
               { '+', '0' },
               { '[', '-' },
               { '{', '_' },
               { ']', '+' },
               { '}', '=' },
               { '|', '!' },
               { ';', '@' },
               { ':', '#' },
               { '\'','$' },
               { '<', '^' },
               { ',', '&' },
               { '>', '*' },
               { '/', ')' },
               { '?', '`' },
               { ' ', '~' },
               { '\n', '('},
               { '\t', '%'}
    };

    map<char, char> substitutionReverse = {
               { 'q', 'a' },
               { 'w', 'b' },
               { 'e', 'c' },
               { 'r', 'd' },
               { 't', 'e' },
               { 'y', 'f' },
               { 'u', 'g' },
               { 'i', 'h' },
               { 'o', 'i' },
               { 'p', 'j' },
               { '[', 'k' },
               { ']', 'l' },
               { 'a', 'm' },
               { 's', 'n' },
               { 'd', 'o' },
               { 'f', 'p' },
               { 'g', 'q' },
               { 'h', 'r' },
               { 'j', 's' },
               { 'k', 't' },
               { 'l', 'u' },
               { ';', 'v' },
               { '1', 'w' },
               { 'z', 'x' },
               { 'x', 'y' },
               { 'c', 'z' },
               { 'v', 'A' },
               { 'b', 'B' },
               { 'n', 'C' },
               { 'm', 'D' },
               { 'm', 'E' },
               { ',', 'F' },
               { '.', 'G' },
               { '/', 'H' },
               { 'Q', 'I' },
               { 'W', 'J' },
               { 'E', 'K' },
               { 'R', 'L' },
               { 'T', 'M' },
               { 'T', 'N' },
               { 'Y', 'O' },
               { 'U', 'P' },
               { 'I', 'Q' },
               { 'O', 'R' },
               { 'P', 'S' },
               { '{', 'T' },
               { '}', 'U' },
               { '|', 'V' },
               { 'A', 'W' },
               { 'S', 'X' },
               { 'D', 'Y' },
               { 'F', 'Z' },
               { 'G', '0' },
               { 'H', '1' },
               { 'J', '2' },
               { 'K', '3' },
               { 'L', '4' },
               { 'Z', '5' },
               { 'X', '6' },
               { 'C', '7' },
               { 'V', '8' },
               { 'B', '9' },
               { 'N', '!' },
               { 'M', '@' },
               { '<', '#' },
               { '>', '$' },
               { '?', '%' },
               { '2', '^' },
               { '3', '&' },
               { '4', '*' },
               { '5', '(' },
               { '6', ')' },
               { '7', '-' },
               { '8', '_' },
               { '9', '=' },
               { '0', '+' },
               { '-', '[' },
               { '_', '{' },
               { '+', ']' },
               { '=', '}' },
               { '!', '|' },
               { '@', ';' },
               { '#', ':' },
               { '$', '\''},
               { '^', '<' },
               { '&', ',' },
               { '*', '>' },
               { ')', '/' },
               { '`', '?' },
               { '~', ' ' },
               {'(', '\n' },
               {'%', '\t' }
    };
};
///********************************************************************
// * CLASS
// *******************************************************************/
//class Cipher04 : public Cipher
//{
//public:
//   virtual string getPseudoAuth()  { return "pseudocode author"; }
//   virtual string getCipherName()  { return "cipher name"; }
//   virtual string getEncryptAuth() { return "encrypt author"; }
//   virtual string getDecryptAuth() { return "decrypt author"; }
//
//   /***********************************************************
//    * GET CIPHER CITATION
//    * Returns the citation from which we learned about the cipher
//    ***********************************************************/
//   virtual string getCipherCitation()
//   {
//      return string("citation");
//   }
//   
//   /**********************************************************
//    * GET PSEUDOCODE
//    * Returns the pseudocode as a string to be used by the caller.
//    **********************************************************/
//   virtual string getPseudocode()
//   {
//      string str;
//
//      // TODO: please format your pseudocode
//      // The encrypt pseudocode
//      str =  "insert the encryption pseudocode\n";
//
//      // The decrypt pseudocode
//      str += "insert the decryption pseudocode\n";
//
//      return str;
//   }
//
//   /**********************************************************
//    * ENCRYPT
//    * TODO: ADD description
//    **********************************************************/
//   virtual string encrypt(const string & plainText,
//                               const string & password)
//   {
//      string cipherText = plainText;
//      // TODO - Add your code here
//      return cipherText;
//   }
//
//   /**********************************************************
//    * DECRYPT
//    * TODO: ADD description
//    **********************************************************/
//   virtual string decrypt(const string & cipherText,
//                               const string & password)
//   {
//      string plainText = cipherText;
//      // TODO - Add your code here
//      return plainText;
//   }
//};

#endif // CIPHER04_H