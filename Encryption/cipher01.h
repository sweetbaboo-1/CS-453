/********************************************************************
* Header:
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#ifndef CIPHER01_H
#define CIPHER01_H

/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher01 : public Cipher
{
public:
   std::string password = "";

   virtual std::string getPseudoAuth() { return "Matthew Peart"; }
   virtual std::string getCipherName() { return "Affine Cipher"; }
   virtual std::string getEncryptAuth() { return "Matthew Peart"; }
   virtual std::string getDecryptAuth() { return "Matthew Peart"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      std::string s;
      s += "Geeks for Geeks (2021), ";
      s += "\"Implementation of Affine Cipher\" \n retrieved: 2021\n";
      s += "https://www.geeksforgeeks.org/implementation-affine-cipher/";
      return s;
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

      str += "E ( x ) = ( a x + b ) mod m \n";
      str += "modulus m: size of the alphabet\n";
      str += "a and b: key of the cipher\n.";
      str += "a must be chosen such that a and m are coprime.";

      // The decrypt pseudocode
      str += "D ( x ) = a^-1 ( x - b ) mod m\n";
      str += "a^-1 : modular multiplicative inverse of a modulo m. i.e., it satisfies the equation\n";
      str += "1 = a a^-1 mod m .";

      return str;
   }

   /**********************************************************
    * ENCRYPT
    * TODO: ADD description
    **********************************************************/
   virtual std::string encrypt(const std::string &plainText, const std::string &password)
   {
      int b = getBfromPassword(password);

      ///Cipher Text initially empty
      string cipher = "";
      for (int i = 0; i < plainText.length(); i++)
      {
         // Avoid space to be encrypted
         if (plainText[i] != ' ')
            /* applying encryption formula ( a x + b ) mod m
            {here x is msg[i] and m is 26} and added 'A' to
            bring it in range of ascii alphabet[ 65-90 | A-Z ] */
            cipher = cipher +
                     (char)((((a * (plainText[i] - 'A')) + b) % 26) + 'A');
         else
            //else simply append space character
            cipher += plainText[i];
      }
      return cipher;
   }

   /**********************************************************
    * DECRYPT
    * TODO: ADD description
    **********************************************************/
   virtual std::string decrypt(const std::string &cipherText, const std::string &password)
   {
      string msg = "";
      int a_inv = 0;
      int flag = 0;
      int b = getBfromPassword(password);

      //Find a^-1 (the multiplicative inverse of a
      //in the group of integers modulo m.)
      for (int i = 0; i < 26; i++)
      {
         flag = (a * i) % 26;

         //Check if (a*i)%26 == 1,
         //then i will be the multiplicative inverse of a
         if (flag == 1)
         {
            a_inv = i;
         }
      }
      for (int i = 0; i < cipherText.length(); i++)
      {
         if (cipherText[i] != ' ')
            /*Applying decryption formula a^-1 ( x - b ) mod m
            {here x is cipher[i] and m is 26} and added 'A'
            to bring it in range of ASCII alphabet[ 65-90 | A-Z ] */
            msg = msg +
                  (char)(((a_inv * ((cipherText[i] + 'A' - b)) % 26)) + 'A');
         else
            //else simply append space character
            msg += cipherText[i];
      }

      return msg;
   }

private:
   int m = 95; // the number of chars in our alphabet
   int a = 77; // this is co prime to m 95 = 5 * 19, 77 = 11 * 7

   //b = ascii number from first char
   int getBfromPassword(std::string password)
   {
      return int(password[0]);
   }
};

#endif // CIPHER01_H