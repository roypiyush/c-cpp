#include <iostream>

int main(int argc, char **argv) {
    // lambda without params
    auto lam1 = []() -> void { std::cout << "Hello from Lambda" << std::endl; };
    lam1();

    // lambda with params
    auto lam2 = [](int a, int b) -> bool { return a > b; };

    int a = 1, b = 3;
    std::cout << lam2(a, b) << std::endl;

    // lambda without params but captures params by value from scope
    auto lam3 = [a, b]() { return a > b; };
    std::cout << lam3() << std::endl;

    auto lam4 = [&a, &b]() {
        a = a + 2;
        b = b - 2;
    };

    lam4();
    std::cout << a << " " << b << " " << lam3() << std::endl;

    // lambda without params but captures params by reference from scope
    auto lam5 = [&a, &b]() { return a > b; };
    std::cout << a << " " << b << " " << lam5() << std::endl;

    return 0;
}