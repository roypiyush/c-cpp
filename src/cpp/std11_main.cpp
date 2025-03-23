#include <memory>
#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>
#include <random>
#include <array>
#include <tuple>
#include <functional>
#include <regex>
#include <unordered_map>

std::mutex mtx;

#include "std11_main.h"


int main() {
    smart_ptr_main();
    random_gen_main();
    array_main();
    tuple_main();
    funational_main();
    regex_main();
    hashmap_main();
    mutex_main();
    time_main();
    thread_main();
}

void hashmap_main()
{
    std::unordered_map<std::string, int> scores = {{"a", 90}, {"b", 85}};
    std::cout << "A's score: " << scores["a"] << "\n";
    std::cout << "B's score: " << scores["b"] << "\n";
}

void regex_main()
{
    std::string text = "hello 123";
    std::regex pattern("\\d+");

    if (std::regex_search(text, pattern))
    {
        std::cout << "Number found!\n";
    }
}

void funational_main()
{
    std::function<void(std::string)> f = hello_word;
    f("World");
}

void tuple_main()
{
    std::tuple<int, std::string, double> t(1, "hello", 3.14);
    auto [num, text, pi] = t; // Structured binding (C++17)
    std::cout << text << " " << pi << "\n";
}

void array_main()
{
    // better performance and safety
    std::array<int, 3> arr = {1, 2, 3};
    for (int n : arr) {
        std::cout << n << " ";
    }
}

void random_gen_main()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(1, 100);

    std::cout << "Random number: " << dist(gen) << "\n";
}

void time_main()
{
    std::cout << "Going to sleep \n";
    auto start = std::chrono::high_resolution_clock::now();
    std::this_thread::sleep_for(std::chrono::seconds(2));
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Elapsed time: " << elapsed.count() << "s\n";
}

void mutex_main()
{
    std::lock_guard<std::mutex> lock(mtx);
    std::cout << "Thread-safe print\n";
}

void thread_main()
{
    std::thread t(hello);
    t.join();
}

void smart_ptr_main()
{
    std::unique_ptr<int> ptr = std::make_unique<int>(10);
    std::cout << *ptr << std::endl;
}