

#include <my_vector.h>

#include <iostream>
#include <memory>

using namespace std;

MyVector::MyVector(const int size) : element{new double[size]}, sz{size} {}

int MyVector::size() { return sz; }

double &MyVector::operator[](const int pos) {
    static double dummy = 0.0;
    if (pos < 0 || pos >= sz) {
        return dummy;
    }

    return element[pos];
}

std::ostream &operator<<(std::ostream &os, const MyVector &vec) {
    printf("Vector(%d)", vec.sz);
    os << " [";
    for (int i = 0; i < vec.sz; i++) {
        os << i << "->" << vec.element[i];
        if (i < vec.sz - 1) {
            os << ", ";
        }
    }

    os << "]";
    return os;
}

MyVector::MyVector(const MyVector &vec)
    : element(new double[vec.sz]), sz(vec.sz) {
    for (int i = 0; i < vec.sz; i++) {
        element[i] = vec.element[i];
    }
}

MyVector &MyVector::operator=(const MyVector &vec) {
    if (this == &vec) {
        return *this;  // Handle self-assignment
    }

    delete[] element;

    sz = vec.sz;
    element = new double[sz];
    for (int i = 0; i < vec.sz; i++) {
        element[i] = vec.element[i];
    }
    return *this;
}

MyVector::MyVector(MyVector &&vec) : element(vec.element), sz(vec.sz) {
    delete[] vec.element;
    vec.sz = 0;
}

int main() {
    MyVector vec(2);
    vec[0] = 1;
    vec[1] = 2;

    cout << vec << endl;
    cout << vec[100] << endl;

    MyVector *vec2 = new MyVector(2);
    (*vec2)[0] = 3;
    (*vec2)[1] = 5;
    cout << *vec2 << endl;

    delete vec2;

    unique_ptr<MyVector> vec3 = make_unique<MyVector>(2);
    vec3->operator[](0) = 2;
    vec3->operator[](1) = 4;

    cout << *vec3 << endl;

    // move
    *vec3 = move(vec);

    return 0;
}