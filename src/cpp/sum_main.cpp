#include "iostream" 

#include "sum.h"

using namespace std; 

enum boolean { NO, YES };
enum escapes { BELL = '\a', BACKSPACE = '\b', TAB = '\t', NEWLINE = '\n', VTAB = '\v', RETURN = '\r' };

  
// Driver Code 
int main() 
{ 
  
    // Given two numbers 
    int a = 13, b = 22; 
  
    // Function declared in header 
    // file to find the sum 
    cout << "Sum is: "
         << sumOfTwoNumbers(a, b) 
         << endl; 
    cout << NO << endl;
    cout << YES << endl;
} 
