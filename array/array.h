#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include <iostream>

template<int N, typename T>
class Array {
 private:
 	T a[N];
 
 public:
    Array();

    Array(const char* in);

    Array(T in[]);

    void operator=(const char* in);

 	T& operator[](int in);

    std::ostream& print(std::ostream& sout);

};
#endif