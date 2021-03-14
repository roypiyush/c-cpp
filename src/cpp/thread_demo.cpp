#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

#define SLEEP_TIME_IN_MILLIS 1000

/*
use -pthread in option
*/

void foo() {
    cout << "Doing stuffs in foo()" << endl;
    this_thread::sleep_for(std::chrono::milliseconds(SLEEP_TIME_IN_MILLIS));
    cout << "foo() completed" << endl;
}

void bar(int x) {
    cout << "Doing stuffs in bar()" << endl;
    this_thread::sleep_for(std::chrono::milliseconds(SLEEP_TIME_IN_MILLIS));
    cout << "bar() completed" << endl;
}

int main() {
    thread first (foo);      // spawn new thread that calls foo()
    thread second (bar, 0);  // spawn new thread that calls bar(0)
    cout << "main, foo and bar now execute concurrently...\n";
    
    // synchronize threads:
    first.join();                // pauses until first finishes
    second.join();               // pauses until second finishes
    
    cout << "foo and bar completed.\n";
}