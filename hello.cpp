#include <iostream>
#include <climits>
#include <string>
#include <fstream>

using namespace std;


void goto_demo();
long factorial (const long &a);
void readFile();

void overload(int a) {
    cout << a << endl;
}

void overload(int a, int b) {
    cout << a + b << endl;
}

void overload(int a, int &b) {
    cout << a + b << endl;
}


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
    cout << "Factorial " << factorial(5) << endl;
    overload(1);
    overload(1, 2);
    overload(1, 2);
    readFile();
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

void readFile() {
    string line;
    ifstream myfile ("/var/log/kern.log");
    if (myfile.is_open()) {
        while ( getline (myfile,line) ) {
            cout << line << '\n';
        }
        myfile.close();
    } else {
        cout<< "Coudn't open file" << endl;
    }
}