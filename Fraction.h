#ifndef FRACTION_H
#define FRACTION_H
#include <iostream>
#include <assert.h>

template <typename T>
class fraction {
    private:
    T numerator;
    T denominator;
    public:
    constexpr int gcd(const T x, const T y);
    constexpr fraction operator=(const fraction &in);
    constexpr fraction operator=(const int &in);
    
    /*
    Operators
    */
    
    //==
    constexpr fraction operator==(const fraction &out);
    template <typename t>
     constexpr fraction operator==(const t &val);
    //!=
    
    constexpr fraction operator!=(const fraction &out) {
        return (numerator!=out.numerator) || (denominator!=out.denominator);
    }
    template <typename t>
     constexpr fraction operator!=(const t &out);
    
    //*
    constexpr fraction operator*(const fraction &other);
    template <typename t>
     constexpr fraction operator*(const t &other);

    //*=
    constexpr fraction operator*=(const fraction &other);
    template <typename t>
     constexpr fraction operator*=(const t &other);
    
    //+
    constexpr fraction operator+(const fraction &other);
    constexpr fraction operator+=(const fraction &other);
    constexpr fraction operator-(const fraction &other);
    constexpr fraction operator-=(const fraction &other);
    constexpr fraction operator/(const fraction &other);
    constexpr fraction operator/=(const fraction &other);
    constexpr fraction operator-();
    friend std::ostream& operator<<(std::ostream &os, const fraction &f);
    constexpr fraction(const T num, const T den): numerator(num),denominator(den);
    constexpr fraction(const T num);
      
    constexpr T getNumerator();
    constexpr T getDenominator();
    constexpr T setNumerator(T num);
    constexpr T setDenominator(T num);

    //Conversion
    operator int() const;
    operator double() const;
    operator float() const;
    operator std::string() const;
    constexpr fraction negativeReciprocal();
    

};

#endif 
