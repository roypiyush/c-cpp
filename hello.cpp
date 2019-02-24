#include <iostream>
#include <climits>
#include <string>

using namespace std;


void goto_demo();
long factorial (const long &a);

int main(int argc, char** argv) {
    cout << "Hello World !!!" << endl;
    char mychar = 'a';
    cout << mychar << endl;
    const char16_t message[] = u"你好，世界\n";
    cout << " Chinese Hello World " << message << endl;
    cout << sizeof(message)/sizeof(char16_t) << "\n";

    string mystring = "Simple \a String";
    cout << mystring << endl;
    goto_demo();
    cout << factorial(5) << endl;

}

void goto_demo() {
    int n=10;
    mylabel:
        cout << n << ", ";
        n--;
        if (n>0) goto mylabel;
    cout << "liftoff!\n";
}

long factorial (const long &a) {
  if (a > 1)
   return (a * factorial (a-1));
  else
   return 1;
}