#pragma once
#include <cmath>
#define EPS 1e-10

template <typename T>

class imNumbers 
{
public:
    T real;
    T im;

    imNumbers(T real = 0, T im = 0) : real(real), im(im) {}
    friend std::ostream& operator<<(std::ostream& os, const imNumbers& complex);
    friend imNumbers operator!(const imNumbers& c)
    {
        return imNumbers(c.real, -c.im);
    };

    bool operator=(const imNumbers& num)const;
    double operator()() const;
    bool operator==(const imNumbers& operand2) const;
    imNumbers operator+(const imNumbers& rhs)const;
    imNumbers operator-(const imNumbers& rhs)const;
    imNumbers operator*(const imNumbers& rhs) const;
    imNumbers operator/(const imNumbers& other)const;
    imNumbers operator+=(const imNumbers& other);
    imNumbers operator-=(const imNumbers& other);
    imNumbers operator*=(const imNumbers& other);
    imNumbers operator/=(const imNumbers& rhs);
};

template <typename T>

bool imNumbers<T>::operator=(const imNumbers<T>& num)const 
{
    return fabs(real - num.real) < EPS && fabs(im - num.im) < EPS;
}
