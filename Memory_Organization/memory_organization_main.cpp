#include <stdio.h>
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

void one(long number);
void two(long number);
void pass() { cout << "You pass :)\n"; }
void fail() { cout << "You've failed :(\n"; }
const char *passMessage = ":)";
const char *failMessage = ":(";

//Parameter is that of a dynamically allocated variable that is a pointer
auto getHeapAddress(auto* d){
    return d;
}

//Paramter is that of a variable programmatically set
template <class T>
T getStackAddress(T var)
{
   return var;
}

template <class T>
auto getFunctionAddress(T fun)
{
   return (void *)fun;
}

/**
 * MAIN : The top of the callstack.
 **/
int memory_main()
{
   char text[8] = "MAIN**";
   long number = 123456;
   void (*pointerFunction)() = fail;
   long *number1 = new long();
   const char *message = failMessage;
   long *ptr = &number;
   cout << "getCode " << getFunctionAddress(pointerFunction) << endl;
   cout << "Stack " << getStackAddress(ptr) << endl;
   cout << "Heap " << getHeapAddress(number1) << endl;
   // display the initial values of the local variables
   cout << "main() : " << (void *)memory_main << endl;
   cout << "\ttext:             " << text << endl;
   cout << "\tnumber:           " << number << endl;
   cout << "\tmessage:          " << message << endl;
   cout << "\tfunction pointer: ";
   pointerFunction();

   // call the other functions
   one(number + 111111); // 234567

   // display the new values of the local variables
   cout << "main() - after\n";
   cout << "\ttext:             " << text << endl;
   cout << "\tnumber:           " << number << endl;
   cout << "\tmessage:          " << message << endl;
   cout << "\tfunction pointer: ";
   pointerFunction();

   return 0;
}

/************************************************
 * CONVERT TO STRING
 * Convert the data from p into a human-readable string
 * by removing all the unprintable characters and replacing
 * them with a dot
 ***********************************************/
string displayCharArray(const char *p)
{
   string output;
   for (int i = 0; i < 8; i++)
      output += string(" ") + (p[i] >= ' ' && p[i] <= 'z' ? p[i] : '.');
   return output;
}

/**********************************************
 * ONE : The next item on the call stack
 **********************************************/
void one(long number) // 234567
{
   char text[8] = "**ONE**";

   cout << "one() : " << (void *)one << endl;
   cout << "\tmessage: " << (void *)failMessage << endl;
   cout << "\tfail():  " << (void *)fail << endl;

   two(number + 111111); // 345678
}

/**********************************************
 * TWO : The bottom of the call stack
 **********************************************/
void two(long number) // 345678
{
   // start your display of the stack from this point
   long bow = number + 111111; // 456789
   char text[8] = "**TWO**";
   long *pLong = NULL;
   char *pChar = NULL;

   // header for our table. Use these setw() offsets in your table
   cout << '[' << setw(2) << 'i' << ']'
        << setw(15) << "address"
        << setw(20) << "hexadecimal"
        << setw(20) << "decimal"
        << setw(18) << "characters"
        << endl;
   cout << "----+"
        << "---------------+"
        << "-------------------+"
        << "-------------------+"
        << "-----------------+\n";

   // Display the Stack
   // starts at 150
   for (long i = 160; i >= -5; i--) // You may need to change 24 to another number
   {
      //bow += i;
      pLong = (&bow) + i; //char* c = "Hello world!" is equivalent to saying char c[] = "Hello world!".
      pChar = (char *)(pLong);
      cout << '[' << setw(2) << i << ']'
           << setw(15) << pLong
           << setw(20) << std::hex << *pLong
           << setw(20) << std::dec << (*pLong)
           << setw(18) << displayCharArray(pChar)
           << endl;
   }

   ////////////////////////////////////////////////
   // Insert code here to change the variables in main()

   // change text in main() to "*main**"
   pLong = (&bow) + 137;
   pChar = (char *)(pLong);
   pChar[0] = '*';
   pChar[1] = 'M';
   pChar[2] = 'A';
   pChar[3] = 'I';
   pChar[4] = 'N';
   pChar[5] = '*';
   pChar[6] = '*';
   // change number in main() to 654321
   pLong = (&bow) + 144;
   *pLong = (long)654321;
   
   //change pointerFunction in main() to point to pass
   pLong = (&bow) + 149;
   *pLong = (long)pass; // changing the address where the pointer points

   // change message in main() to point to passMessage
   pLong = (&bow + 153);
   *pLong = (long)passMessage;
   ////////////////////////////////////////////////
}
