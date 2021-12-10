/********************************************************************
* Header:
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#ifndef CIPHER01_H
#define CIPHER01_H
#define M 95 // the size of alphabet
#define A 3  // this is co prime to m 95 = 5 * 19, 3 = 3

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
      s += "https://www.geeksforgeeks.org/implementation-affine-cipher/\n";
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

      str += "encrypt(plainText, password)\n";
      str += "    for x is all values in plainText\n";
      str += "       cipher += (ax + b) % m\n";
      str += "a must be coprime to m where m = size of alphabet\n";
      str += "b must be integer value\n\n";

      // The decrypt pseudocode
      str += "decrypt(plainText, password)\n";
      str += "    for x is all values in plainText\n";
      str += "       decipher += a^-1 (x - b) mod m\n";
      str += "return decipher\n\n";

      // The getBfromPassword pseudocode
      str += "getBfromPassword(password)\n";
      str += "    for x is all values in password\n";
      str += "       b *= int(x)\n";
      str += "return b";
      return str;
   }

   /**********************************************************
    * ENCRYPT
    * This code uses the AFFINE cipher algorithm to encript
    * plaintext using a set of keys (a, b)
    * f(x) = (ax + b) % m
    **********************************************************/
   virtual std::string encrypt(const std::string &plainText, const std::string &password)
   {

      // shift everything down the ascii table by the value of the first char in our alphabet ' '
      string str = "";
      for (int i = 0; i < plainText.length(); i++)
         str += plainText[i] - ' '; // make our chars 0 based

      // encript everything using the formula f(x) = ax + b % m
      string cipher = "";
      for (int i = 0; i < str.length(); i++)
      {
         int x = (((A * (str[i])) + getBfromPassword(password)) % M);
         while (x > M)
            x -= M;
         cipher += (char)x;
      }

      // shift everything up the ascii table by the value ' ' undoing what we did earlier
      for (int i = 0; i < cipher.length(); i++)
         cipher[i] = cipher[i] + ' ';

      return cipher;
   }

   /**********************************************************
    * DECRYPT
    * This code reverses the encription process using the same
    * key pair (a, b)
    * A mutplicative inverse of 'a' must be found to solve
    * for x in the equation f(x) = (ax + b) % M
    * x = a^-1(x - b) % M
    **********************************************************/
   virtual std::string decrypt(const std::string &cipher, const std::string &password)
   {
      // mutiplicative inverse logic copied from https://www.geeksforgeeks.org/implementation-affine-cipher/
      // source
      int a_inv = 0;
      int flag = 0;

      for (int i = 0; i < M; i++)
      {
         flag = (A * i) % M;

         //Check if (a*i)%M == 1,
         //then i will be the multiplicative inverse of a
         if (flag == 1)
            a_inv = i;
      }
      // end source

      // shift everything down the ascii table to make it easier
      string str;
      for (int i = 0; i < cipher.length(); i++)
         str += cipher[i] - ' ';

      // perform the decription
      std::string msg = "";
      for (int i = 0; i < str.length(); i++)
      {
         int x = a_inv * (int(str[i]) - getBfromPassword(password));

         /*
         * if x is outside of the vaules of the given alphabet mod it
         * by the value of the alphabet. This is equivalent to adding
         * or subtracting the value of the alphabet to a number until
         * it is within the range of the alphabet
         */
         if (x > M)
            x = x % M;

         if (x < 0)
            x = x % M;

         msg += (char)x + ' '; //return the cipher text to the correct number
      }
      return msg;
   }

private:
   /**********************************************************
    * getBfromPassword
    * Given a string generate a valid key (b)
    * b can be any integer value
    * larger numbers are more secure
    **********************************************************/
   int getBfromPassword(std::string password)
   {
      int b = 0;
      for (int i = 0; i < password.length(); i++)
         b *= password[i];
      return b;
   }
};

#endif // CIPHER01_H