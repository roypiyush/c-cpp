#include <iostream>

using namespace std;


int main(int argc, char** argv) {
    cout << "Hello World !!!" << endl;
    char mychar = 'a';
    cout << mychar << endl;
    const char16_t message[] = u"你好，世界\n";
    cout << " Chinese Hello World " << message << endl;
    cout << sizeof(message)/sizeof(char16_t) << "\n";
}