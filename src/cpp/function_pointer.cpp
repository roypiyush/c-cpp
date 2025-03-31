#include <iostream>

using namespace std;

char *hello() { return "hello"; }

int main() {
    char *(*funcptr)();

    funcptr = &hello;

    cout << funcptr() << endl;

    return 0;
}