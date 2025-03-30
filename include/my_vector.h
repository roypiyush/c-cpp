#ifndef MYVECTOR_H
#define MYVECTOR_H

// alternatively use below
#pragma once

double sqrt(double num);

class MyVector
{
private:
    double *element;
    int sz;

public:
    MyVector(const int size);
    ~MyVector()
    {
        printf("Deleting...\n");
        delete[] element;
    }

    MyVector(const MyVector &vec);
    MyVector &operator=(const MyVector &vec);

    MyVector(MyVector &&vec);

    double &operator[](const int pos);
    friend std::ostream &operator<<(std::ostream &os, const MyVector &vec);
    int size();
};

#endif