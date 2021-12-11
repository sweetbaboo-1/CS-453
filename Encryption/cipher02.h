/********************************************************************
* Header:
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#ifndef CIPHER02_H
#define CIPHER02_H

#include <iostream>
#include <map>

/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher02 : public Cipher
{
public:
   virtual std::string getPseudoAuth() { return "Sam Haymond"; }
   virtual std::string getCipherName() { return "Keyword Cipher"; }
   virtual std::string getEncryptAuth() { return "Sam Haymond"; }
   virtual std::string getDecryptAuth() { return "Sam Haymond"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      return std::string("Geeks for Geeks (2021), \"Keyword Cipher\"\nretrieved: 2021\nhttps://www.geeksforgeeks.org/keyword-cipher/\n");
   }

   /**********************************************************
    * GET PSEUDOCODE
    * Returns the pseudocode as a string to be used by the caller.
    **********************************************************/
   virtual std::string getPseudocode()
   {
      std::string str;

      // TODO: please format your pseudocode
      // The encrypt pseudocode
      str += "\nencrypt(plainText, password)\n";
      str += "    FOR every element in password\n";
      str += "        IF letter is uppercase between A and Z\n";
      str += "            IF letter has not been added to encoded string\n";
      str += "                ADD letter to encoded string\n";
      str += "        ELSE IF letter is lowercase between a and z\n";
      str += "            IF letter has not been added to encoded string\n";
      str += "                ADD letter to encoded string\n";
      str += "    \nFOR 26 times\n";
      str += "        fill in remainder of letters to encoded string\n";
      str += "    \nFOR element in plainText\n";
      str += "        IF lowercase letter between a and z\n";
      str += "            position = plaintext element - 97\n";
      str += "            cipherText += encoded letter at position\n";
      str += "        ELSE IF uppercase letter between A and Z\n";
      str += "            position = plaintext element - 65\n";
      str += "            cipherText += encoded letter at position\n";
      str += "        ELSE cipherText += plaintext element\n";
      str += "    RETURN cipherText\n";

      // The decrypt pseudocode
      str += "\ndecrypt(cipherText, password)\n";
      str += "FOR every element in password\n";
      str += "    IF letter is uppercase between A and Z\n";
      str += "        IF letter has not been added to encoded string\n";
      str += "            ADD letter to encoded string\n";
      str += "    ELSE IF letter is lowercase between a and z\n";
      str += "        IF letter has not been added to encoded string\n";
      str += "            ADD letter to encoded string\n";
      str += "\nFOR 26 times\n";
      str += "    fill in remainder of letters to encoded string\n";
      str += "    \nFOR element in cipherText\n";
      str += "        IF lowercase letter between a and z\n";
      str += "            position = element location in encoded alphabet - 32\n";
      str += "            plainText += letter at position in normal alphabet\n";
      str += "        ELSE IF uppercase letter between A and Z\n";
      str += "            position = element location in encoded alphabet\n";
      str += "            plainText += letter at position in normal alphabet\n";
      str += "        ELSE plainText += ciphertext element\n";
      str += "    RETURN plainText\n";

      return str;
   }

   /**********************************************************
    * ENCRYPT
    * TODO: ADD description
    **********************************************************/
   virtual std::string encrypt(const std::string &plainText,
                               const std::string &password)
   {
      std::string cipherText = "";
      std::string encoded = "";
      bool arr[26] = {0};

      // Create encoded alphabet string
      for (int i = 0; i < password.size(); i++)
      {
         // Check for a letter
         if (password[i] >= 'A' && password[i] <= 'Z')
         {
            // Check to make sure the letter hasn't already been added
            if (arr[password[i] - 65] == 0)
            {
               encoded += password[i];
               arr[password[i] - 65] = 1;
            }
         }
         // Check for lower case input and change the encoded to uppercase
         else if (password[i] >= 'a' && password[i] <= 'z')
         {
            if (arr[password[i] - 97] == 0)
            {
               encoded += password[i] - 32;
               arr[password[i] - 97] = 1;
            }
         }
      }

      // Populate the remainder of the ecnoded alphabet with remaining letters of the alphabet
      for (int i = 0; i < 26; i++)
      {
         if (arr[i] == 0)
         {
            arr[i] = 1;
            encoded += char(i + 65);
         }
      }

      // Encrypt plainText
      for (int i = 0; i < plainText.size(); i++)
      {
         // Check for lowercase valid input
         if (plainText[i] >= 'a' && plainText[i] <= 'z')
         {
            int pos = plainText[i] - 97;
            cipherText += encoded[pos];
         }
         else if (plainText[i] >= 'A' && plainText[i] <= 'Z')
         {
            int pos = plainText[i] - 65;
            cipherText += encoded[pos];
         }
         else
         {
            cipherText += plainText[i];
         }
      }

      return cipherText;
   }

   /**********************************************************
    * DECRYPT
    * TODO: ADD description
    **********************************************************/
   virtual std::string decrypt(const std::string &cipherText,
                               const std::string &password)
   {
      std::string plainText = "";

      std::string encoded = "";
      bool arr[26] = {0};

      // Create encoded alphabet string
      for (int i = 0; i < password.size(); i++)
      {
         // Check for a letter
         if (password[i] >= 'A' && password[i] <= 'Z')
         {
            // Check to make sure the letter hasn't already been added
            if (arr[password[i] - 65] == 0)
            {
               encoded += password[i];
               arr[password[i] - 65] = 1;
            }
         }
         // Check for lower case input and change the encoded to uppercase
         else if (password[i] >= 'a' && password[i] <= 'z')
         {
            if (arr[password[i] - 97] == 0)
            {
               encoded += password[i] - 32;
               arr[password[i] - 97] = 1;
            }
         }
      }

      // Populate the remainder of the ecnoded alphabet with remaining letters of the alphabet
      for (int i = 0; i < 26; i++)
      {
         if (arr[i] == 0)
         {
            arr[i] = 1;
            encoded += char(i + 65);
         }
      }

      std::map<char, int> enc;
      for (int i = 0; i < encoded.size(); i++)
      {
         enc[encoded[i]] = i;
      }

      std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

      // Decrypt cipherText
      for (int i = 0; i < cipherText.size(); i++)
      {
         if (cipherText[i] >= 'a' && cipherText[i] <= 'z')
         {
            int pos = enc[cipherText[i] - 32];
            plainText += alphabet[pos];
         }
         else if (cipherText[i] >= 'A' && cipherText[i] <= 'Z')
         {
            int pos = enc[cipherText[i]];
            plainText += alphabet[pos];
         }
         else
         {
            plainText += cipherText[i];
         }
      }

      return plainText;
   }
};

#endif // CIPHER02_H