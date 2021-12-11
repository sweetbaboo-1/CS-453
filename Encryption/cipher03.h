/********************************************************************
* Header:
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#ifndef CIPHER03_H
#define CIPHER03_H

/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher03 : public Cipher
{
public:
   virtual std::string getPseudoAuth()  { return "Christian Longhurst"; }
   virtual std::string getCipherName()  { return "Rail Fence Cipher"; }
   virtual std::string getEncryptAuth() { return "Christian Longhurst"; }
   virtual std::string getDecryptAuth() { return "Christian Longhurst"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      return std::string("“RAIL FENCE CIPHER - encryption and decryption,” GeeksforGeeks, 24-Aug-2021. [Online]. Available: https://www.geeksforgeeks.org/rail-fence-cipher-encryption-decryption/. [Accessed: 11-Dec-2021]. ");
   }
   
   /**********************************************************
    * GET PSEUDOCODE
    * Returns the pseudocode as a string to be used by the caller.
    **********************************************************/
   virtual std::string getPseudocode()
   {
      std::string str;

      str ="encrypt\n";
      str += "\tCREATE matrix with row size of password length and column is size of text length\n";
      str += "\tLOOP through matrix of size of text size and password size filling the matrix of empty spaces\n";
      str += "\t\tLOOP through the text size\n";
      str += "\t\t\tIF the matrix is at the ends\n";
      str += "\t\t\t\tdir_down <- opposite of what dir_down is\n";
      str += "\t\tmatrix at position of current row and column <- current text character\n";
      str += "\t\tIF dir_down is true row <- increase by one ELSE row <- decrease by one\n";
      str += "\tLOOP through the password length\n";
      str += "\t\tLOOP through the text length\n";
      str += "\t\t\tIF current matrix character IS NOT \\n\n";
      str += "\t\t\t\tresult.push_back(current character)\n";
      str += "\tRETURN result";

      str += "decrypt\n";
      str += "\tCREATE matrix with row size of password length and column is size of text length\n";
      str += "\tLOOP through matrix of size of text size and password size filling the matrix of empty spaces\n";
      str += "\t\tLOOP through the text size\n";
      str += "\t\t\tIF the row = 0\n";
      str += "\t\t\t\tdir_down <- true\n";
      str += "\t\t\tIF row = password length\n";
      str += "\t\t\t\tdir_down <- false";
      str += "\t\tmatrix at position of current row and column <- marker character\n";
      str += "\t\tIF dir_down is true row <- increase by one ELSE row <- decrease by one\n";
      str += "\tLOOP through the password length\n";
      str += "\t\tLOOP through the text length\n";
      str += "\t\t\tIF current matrix character = marker character AND index < text length\n";
      str += "\t\t\t\tmatrix <- cipher character at index\n";
      str += "\tLoop through the text length\n";
      str += "\t\tIF row = 0\n";
      str += "\t\t\tdir_down <- true\n";
      str += "\t\tIF row = password length-1\n";
      str += "\t\t\tdir_down <- false\n";
      str += "\t\tIF matrix current character IS NOT \\t\n";
      str += "\t\t\tresult.push_back(matrix current character)\n";
      str += "\t\tIF dir_down is true row <- increase by one ELSE row <- decrease by one\n";
      str += "\tRESULT result";

      return str;
   }

   /**********************************************************
    * ENCRYPT
    * TODO: ADD description
    **********************************************************/
   virtual std::string encrypt(const std::string & plainText,
                               const std::string & password)
   {
      char matrix[(password.length())][(plainText.length())];
      for (int i = 0; i < password.length(); i++)
           for (int j = 0; j < plainText.length(); j++)
               matrix[i][j] = '\n';
      bool dir_down = false;
      int row = 0, col = 0;
      for(int i = 0; i < plainText.length(); i++){
           if(row == 0 || row == password.length()-1)
               dir_down = !dir_down;
         matrix[row][col++] = plainText[i];
         if(dir_down) 
               row++;
         else
               row--;
    }
    string result;
    for(int i = 0; i < password.length(); i++)
        for(int j = 0; j < plainText.length(); j++)
            if(matrix[i][j] != '\n')
                result.push_back(matrix[i][j]);
    return result;
   }

   /**********************************************************
    * DECRYPT
    * TODO: ADD description
    **********************************************************/
   virtual std::string decrypt(const std::string & cipherText,
                               const std::string & password)
   {
      int key = password.length();
    char matrix[password.length()][cipherText.length()];
    for (int i=0; i < key; i++)
        for (int j=0; j < cipherText.length(); j++)
            matrix[i][j] = '\n';
 
    // to find the direction
    bool dir_down;
 
    int row = 0, col = 0;
 
    for (int i=0; i < cipherText.length(); i++)
    {
        if (row == 0)
            dir_down = true;
        if (row == key-1)
            dir_down = false;
        matrix[row][col++] = '\t';
        dir_down?row++ : row--;
    }
 
    int index = 0;
    for (int i=0; i<key; i++)
        for (int j=0; j<cipherText.length(); j++)
            if (matrix[i][j] == '\t' && index<cipherText.length())
                matrix[i][j] = cipherText[index++];
    string result;
    row = 0, col = 0;
    for (int i=0; i< cipherText.length(); i++)
    {
        if (row == 0)
            dir_down = true;
        if (row == key-1)
            dir_down = false;
        if (matrix[row][col] != '\t')
            result.push_back(matrix[row][col++]);
        dir_down?row++: row--;
    }
    return result;
   }
};

#endif // CIPHER03_H
