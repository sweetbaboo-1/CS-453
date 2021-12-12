/********************************************************************
* Header:
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#include <math.h>
#ifndef CIPHER07_H
#define CIPHER07_H

using namespace std;
/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher07 : public Cipher
{
public:
   virtual std::string getPseudoAuth()  { return "Tyler Craig"; }
   virtual std::string getCipherName()  { return "Hill Cipher"; }
   virtual std::string getEncryptAuth() { return "Tyler Craig"; }
   virtual std::string getDecryptAuth() { return "Tyler Craig"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      string citiation = "";
      citiation += "Geeks for Geeks (2021), ";
      citiation += "\"Hill Cipher\" \n retrieved: 2021\n";
      citiation += "https://www.geeksforgeeks.org/hill-cipher/?ref=lbp\n";
      return citiation;
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
      str =  "encryption pseudocode:\n";
      str += "For each row\n\t";
      str += "For each column\n\t";
      str += "\tcipher matrix = Matrix multiply the key matrix by the plain text vector\n";
      str += "\tcipher matrix = cipher matrix mod 26\n\n";


      // The decrypt pseudocode
      str += "decryption pseudocode\n";
      str += "cacluate inverse of key matrix\n";
      str += "For each row\n\t";
      str += "For each column\n\t";
      str += "\tplain text vector = Matrix multiply the inverse key matrix by the cipher text vector\n";
      str += "\tplain text vector = plain text vector mod 26\n\n";

      return str;
   }

   /**********************************************************
    * ENCRYPT
    * TODO: ADD description
    **********************************************************/
   virtual std::string encrypt(const std::string & plainText,
                               const std::string & password)
   {
      
      float key[3][3], mes[3][1];

      // fill mes
      for(int i = 0; i < 3; i++)
      {
         mes[i][0] = plainText[i] - 97;
      }

      // fill key
      int m = 0;
      for(int i = 0; i < 3; i++)
      {
         for(int j = 0; j < 3; j++)
         {
            key[i][j] = password[m] % 65;
            c[i][j] = key[i][j];
            m++;
         }
         
      } 

      string cipherText = "";
      int i, j, k;
      for(i = 0; i < 3; i++)
      {
         for(j = 0; j < 1; j++)
         {
            for(k = 0; k < 3; k++)
            {
               encrypted[i][j] = encrypted[i][j] + key[i][k] * mes[k][j];
            }
         }   
      }

      // fill cipher text
      for(i = 0; i < 3; i++)
      {
         cipherText += (char)(fmod(encrypted[i][0], 26) + 97);
      }

      return cipherText;
   }

   /**********************************************************
    * DECRYPT
    * TODO: ADD description
    **********************************************************/
   virtual std::string decrypt(const std::string & cipherText,
                               const std::string & password)
   {

      int i, j, k;
      float p, q;
      for(i = 0; i < 3; i++)
      {
         for(j = 0; j < 3; j++) 
         {
            if(i == j)
               b[i][j] = 1;
            else
               b[i][j] = 0;
         }
      }

      for(k = 0; k < 3; k++) 
      {
         for(i = 0; i < 3; i++) 
         {
            p = c[i][k];
            q = c[k][k];
            for(j = 0; j < 3; j++) 
            {
               if(i != k) 
               {
                  c[i][j] = c[i][j]*q - p*c[k][j];
                  b[i][j] = b[i][j]*q - p*b[k][j];
               }
            }
         }
      }
      for(i = 0; i < 3; i++)
         for(j = 0; j < 3; j++)
            b[i][j] = b[i][j] / c[i][i];

      for(i = 0; i < 3; i++)
         for(j = 0; j < 1; j++)
            for(k = 0; k < 3; k++)
               decrypted[i][j] = decrypted[i][j] + b[i][k] * encrypted[k][j];
      
      string plainText = "";

      for(i = 0; i < 3; i++)
         plainText += (char)(fmod(decrypted[i][0], 26) + 97);

      return plainText;

   }
private:
   float encrypted[3][1], decrypted[3][1], c[3][3],  b[3][3];

};


#endif // CIPHER07_H