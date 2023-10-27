#pragma once
#include <cmath>
#include <iostream>
#define EPS 1e-10

template <typename T>

class imNumbers 
{
public:
    T real;
    T im;

    imNumbers(T real = 0, T im = 0) : real(real), im(im) {}
    friend std::ostream& operator<<(std::ostream& os, const imNumbers<T>& complex);
    friend imNumbers<T> operator!(const imNumbers<T>& c)
    {
        return imNumbers<T>(c.real, -c.im);
    };

    bool operator=(const imNumbers<T>& num)const;
    double operator()() const;
    bool operator==(const imNumbers<T>& operand2) const;
    imNumbers<T> operator+(const imNumbers<T>& rhs)const;
    imNumbers<T> operator-(const imNumbers<T>& rhs)const;
    imNumbers<T> operator*(const imNumbers<T>& rhs) const;
    imNumbers<T> operator/(const imNumbers<T>& other)const;
    imNumbers<T> operator+=(const imNumbers<T>& other);
    imNumbers<T> operator-=(const imNumbers<T>& other);
    imNumbers<T> operator*=(const imNumbers<T>& other);
    imNumbers<T> operator/=(const imNumbers<T>& rhs);
};

template <typename T>

bool imNumbers<T>::operator=(const imNumbers<T>& num)const 
{
    return fabs(real - num.real) < EPS && fabs(im - num.im) < EPS;
}
