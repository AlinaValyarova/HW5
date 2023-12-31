#include "imNumbers.h"
#include <iostream>

using namespace std;

template <typename T>

double imNumbers<T>::operator()()const
{
    return sqrt(real * real + im * im);
}

template <typename T>

imNumbers<T> imNumbers<T>::operator+(const imNumbers<T>& rhs)const
{
    imNumbers<T> result = *this;
    result.real += rhs.real;
    result.im += rhs.im;
    return result;
}

template <typename T>

imNumbers<T> imNumbers<T>::operator-(const imNumbers<T>& rhs)const
{
    imNumbers<T> result = *this;
    result.real -= rhs.real;
    result.im -= rhs.im;
    return result;
}

template <typename T>

imNumbers<T> imNumbers<T>::operator*(const imNumbers<T>& rhs) const
{
    imNumbers<T> result = *this;
    result.real = real * rhs.real - im * rhs.im;
    result.im = (real * rhs.im) + (rhs.real * im);
    return result;
}

template <typename T>

imNumbers<T> imNumbers<T>::operator/(const imNumbers<T>& other)const
{
    imNumbers<T> result = *this;
    double denominator = other.real * other.real + other.im * other.im;
    result.real = (real * other.real + im * other.im) / denominator;
    result.im = (im * other.real - real * other.im) / denominator;
    return result;
}

template <typename T>

imNumbers<T> imNumbers<T>::operator+=(const imNumbers<T>& other)
{
    real += other.real;
    im += other.im;
    return *this;
}

template <typename T>

imNumbers<T> imNumbers<T>::operator-=(const imNumbers<T>& other)
{
    real -= other.real;
    im -= other.im;
    return *this;
}

template <typename T>

imNumbers<T> imNumbers<T>::operator*=(const imNumbers<T>& other) {
    T newReal = (real * other.real) - (im * other.im);
    T newImaginary = (real * other.im) + (im * other.real);
    real = newReal;
    im = newImaginary;
    return *this;
}

template <typename T>

imNumbers<T> imNumbers<T>::operator/=(const imNumbers<T>& rhs)
{
    T denominator = (rhs.real * rhs.real) + (rhs.im * rhs.im);

    T newReal = ((real * rhs.real) + (im * rhs.im)) / denominator;
    T newImaginary = ((im * rhs.real) - (real * rhs.im)) / denominator;

    real = newReal;
    im = newImaginary;

    return *this;
}

template <typename T>

bool imNumbers<T>::operator==(const imNumbers<T>& operand2) const
{
    return (real == operand2.real && im == operand2.im);
}

template <typename T>

std::ostream& operator<<(std::ostream& os, const imNumbers<T>& complex)
{
    os << complex.real;

    if (complex.im > 0)
        os << "+i" << complex.im;
    else if (complex.im < 0)
        os << "-i" << -complex.im;

    return os;
}