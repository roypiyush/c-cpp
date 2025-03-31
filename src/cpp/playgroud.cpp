#include <algorithm>
#include <cwchar>
#include <iostream>
#include <string>

using namespace std;

struct MyMessage {
    const std::string message;

    MyMessage(const std::string &str) : message(str) {}
};

void print(struct MyMessage *ptr) {
    if (ptr == NULL) {
        return;
    }

    printf("%c", ptr->message);

    printf(".\n");
}

auto add(int a, int b, int c = 3) -> int;

int add(const int a, const int b, const int c) { return a + b + c; }

auto int_from(istream &in) -> int {
    int x;
    in >> x;
    return x;
}

enum TrafficLight { RED, YELLOW, GREEN };

struct MyStruct {
    double c;  // 8 bytes
    int b;     // 4 bytes (aligned)
};

auto main() -> int {
    cout << sizeof(MyStruct) << endl;
    cout << "000" << endl;

    int *a = new int[2];
    a[0] = 1;
    a[1] = 2;
    cout << add(a[0], a[1]) << endl;
    cout << a[0] << " " << endl;

    char name[6] = {'H', 'e', 'l', 'l', 'o', '\0'};
    cout << name << endl;
    cout << "The alignment requirement of int is: " << alignof(int) << '\n';

    wchar_t wideChar = L'Ω';  // Omega character
    std::wcout << L"Wide character: " << wideChar << std::endl;

    std::wstring wideString = L"こんにちは, world!";  // Japanese and English
    std::wcout << L"Wide string (wstring): " << wideString << std::endl;

    struct MyMessage demo = {"hello"};
    print(&demo);

    // dynamic memory so delete
    delete a;

    cout << TrafficLight::GREEN << endl;
    return 0;
}
