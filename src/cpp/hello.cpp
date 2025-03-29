#include <iostream>
#include <climits>
#include <string>
#include <fstream>
#include <unistd.h>

using namespace std;

void goto_demo();
long factorial(const long &a);
void readFile();

void overload(int a)
{
    cout << a << endl;
}

void overload(int a, int b)
{
    cout << a + b << endl;
}

void overload(int a, int &b)
{
    cout << a + b << endl;
}

void goto_demo()
{
    int n = 3;
mylabel:
    cout << n << ", " << std::flush;
    n--;
    sleep(1);
    if (n > 0)
        goto mylabel;
    cout << "liftoff!\n";
    sleep(1);
}

long factorial(const long &a)
{
    if (a > 1)
        return (a * factorial(a - 1));
    else
        return 1;
}

void readFile()
{
    string line;
    ifstream myfile("/var/log/kern.log");
    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            cout << line << '\n';
        }
        myfile.close();
    }
    else
    {
        cout << "Coudn't open file" << endl;
    }
}

int main(int argc, char **argv)
{

    goto_demo();
    cout << "Factorial " << factorial(5) << endl;
    overload(1);
    overload(1, 2);
    overload(1, 2);
    readFile();
}

