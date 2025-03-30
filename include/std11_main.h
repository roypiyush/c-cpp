#pragma once

#include <string>
#include <iostream>

void hello_word(std::string value) { std::cout << "Hello " << value << std::endl; }

void hello() { std::cout << "Hello from thread" << std::endl; }

void smart_ptr_main();

void thread_main();

void mutex_main();

void time_main();

void random_gen_main();

void array_main();

void tuple_main();

void funational_main();

void regex_main();

void hashmap_main();
