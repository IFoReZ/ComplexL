#pragma once
#include <iostream>
#include <cmath>

template <typename T>
class Complex
{
protected:
  T real;
  T imag;

public:
  Complex();


  Complex(T r, T i);


  Complex(const Complex& c);


  ~Complex();


  T getReal() const;
  T getImag() const;

  void setReal(T r);
  void setImag(T i);


  Complex operator+ (const Complex<T>& c);

  Complex operator- (const Complex<T>& c);

  Complex operator* (const Complex<T>& c);

  Complex operator/ (const Complex<T>& c);

  Complex& operator+= (const Complex<T>& c);

  Complex& operator-= (const Complex<T>& c);

  Complex& operator*= (const Complex<T>& c);

  Complex& operator/= (const Complex<T>& c);

  Complex& operator= (const Complex<T>& c);

  bool operator== (const Complex<T>& c);

  bool operator!= (const Complex<T>& c);


  template <class T1>
  friend std::ostream& operator<<(std::ostream& out, Complex<T1>& c);


  template <class T1>
  friend std::istream& operator>>(std::istream& i, Complex<T1>& c);
};

template <class T>
inline Complex<T>::Complex()
{
  real = 1;
  imag = 1;
}

template <class T>
inline Complex<T>::Complex(T r, T i)
{
  real = r;
  imag = i;
}

template <class T>
inline Complex<T>::Complex(const Complex& c)
{
  real = c.getReal();
  imag = c.getImag();
}

template <class T>
inline Complex<T>::~Complex()
{}

template <class T>
inline T Complex<T>::getReal() const
{
  return real;
}

template <class T>
inline T Complex<T>::getImag() const
{
  return imag;
}

template <class T>
inline void Complex<T>::setReal(T r)
{
  real = r;
}

template <class T>
inline void Complex<T>::setImag(T i)
{
  imag = i;
}

template <class T>
inline Complex<T> Complex<T>::operator+ (const Complex<T>& c)
{
  return Complex(real + c.real, imag + c.imag);
}

template <class T>
inline Complex<T> Complex<T>::operator- (const Complex<T>& c)
{
  return Complex(real - c.real, imag - c.imag);
}

template <class T>
inline Complex<T> Complex<T>::operator* (const Complex<T>& c)
{
  return Complex(real * c.real - imag * c.imag, real * c.imag + imag * c.real);
}

template <class T>
inline Complex<T> Complex<T>::operator/ (const Complex<T>& c)
{
  T denom1 = (c.real * c.real) + (c.imag * c.imag);
  T denom2 = (c.real * c.real) - (c.imag * c.imag);
  if (denom1 != (T)0 && denom2 != (T)0)
  {
    return Complex((((real * c.real) + (imag * c.imag)) / denom1),
      (((imag * c.real) - (real * c.imag)) / denom2));
  }
  else
  {
    std::cout << "The Denominator Can`t Be A Zero" << std::endl;
    return Complex(0, 0);
  }
}

template <class T>
inline Complex<T>& Complex<T>::operator+= (const Complex<T>& c)
{
  real += c.real;
  imag += c.imag;
  return *this;
}

template <class T>
inline Complex<T>& Complex<T>::operator-= (const Complex<T>& c)
{
  real -= c.real;
  imag -= c.imag;
  return *this;
}

template <class T>
inline Complex<T>& Complex<T>::operator*= (const Complex<T>& c)
{
  real = real * c.real - imag * c.imag;
  imag = real * c.imag + imag * c.real;
  return *this;
}

template <class T>
inline Complex<T>& Complex<T>::operator/= (const Complex<T>& c)
{
  T denom1 = (c.real * c.real) + (c.imag * c.imag);
  T denom2 = (c.real * c.real) - (c.imag * c.imag);
  if (denom1 != (T)0 && denom2 != (T)0)
  {
    real = ((real * c.real) + (imag * c.imag)) / denom1;
    imag = ((imag * c.real) - (real * c.imag)) / denom2;
  }
  else
  {
    std::cout << "The Denominator Can`t Be A Zero" << std::endl;
  }
  return *this;
}

template <class T>
inline Complex<T>& Complex<T>::operator= (const Complex<T>& c)
{
  real = c.real;
  imag = c.imag;
  return *this;
}

template <class T>
inline bool Complex<T>::operator== (const Complex<T>& c)
{
  return ((real == c.real) && (imag == c.imag));
}

template <class T>
inline bool Complex<T>::operator!= (const Complex<T>& c)
{
  return !(*this == c);
}

template <class T1>
inline std::ostream& operator<< (std::ostream& o, Complex<T1>& c)
{
  o << c.real;
  if (c.imag >= 0)
    o << "+";
  o << c.imag << "i";
  return o;
}

template <class T1>
inline std::istream& operator>> (std::istream& i, Complex<T1>& c)
{
  char sign;
  i >> c.real >> sign >> c.imag;
  if (sign == '-')
  {
    c.imag = -c.imag;
  }
  return i;
}
