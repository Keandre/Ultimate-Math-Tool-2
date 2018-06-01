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
    constexpr int gcd(const T x, const T y) {
        if (y == 0) return x;
        if (y) {
            return gcd(y,x%y);
        }
        else {
            return x;
        }
    }
    constexpr fraction operator=(const fraction &in) {
        numerator = in.numerator;
        denominator = in.denominator;
    }
    constexpr fraction operator=(const int &in) {
        numerator = in;
        denominator = 1;
    }
    
    /*
    Operators
    */
    
    //==
    constexpr fraction operator==(const fraction &out) {
        return (numerator==out.numerator) && (denominator==out.denominator);
    } 
    template <typename t>
    constexpr fraction operator==(const t &val) {
        return (numerator/denominator)==val;
    }
    //!=
    
    constexpr fraction operator!=(const fraction &out) {
        return (numerator!=out.numerator) || (denominator!=out.denominator);
    }
    template <typename t>
    constexpr fraction operator!=(const t &out) {
        return (numerator/denominator) != out;
    }
    
    //*
    constexpr fraction operator*(const fraction &other) {
        return fraction<T>(numerator*other.numerator,denominator*other.denominator);
    }
    template <typename t>
    constexpr fraction operator*(const t &other) {
        return fraction<T>(numerator*other,denominator);
    }

    //*=
    constexpr fraction operator*=(const fraction &other) {
        numerator *= other.numerator;
        denominator *= other.denominator;
    }
    template <typename t>
    constexpr fraction operator*=(const t &other) {
        numerator = numerator*other;
    }
    
    //+
    constexpr fraction operator+(const fraction &other) {
        T commonMultiple = denominator*other.denominator;
        numerator *= commonMultiple/denominator;
        other.numerator *= commonMultiple/other.denominator;
        return fraction<T>(numerator+other.numerator,commonMultiple);
    }
    constexpr fraction operator+=(const fraction &other) {
        numerator = fraction<T>(numerator,denominator)+fraction<T>(other.numerator,other.denominator).getNumerator();
        denominator = fraction<T>(numerator,denominator)+fraction<T>(other.numerator,other.denominator).getDenominator();
    }
    constexpr fraction operator-(const fraction &other) {
        T commonMultiple = denominator*other.denominator;
        numerator *= commonMultiple/denominator;
        other.numerator *= commonMultiple/other.denominator;
        return fraction<T>(numerator-other.numerator,commonMultiple);
    }
    constexpr fraction operator-=(const fraction &other) {
        numerator = fraction<T>(numerator,denominator)-fraction<T>(other.numerator,other.denominator).getNumerator();
        denominator = fraction<T>(numerator,denominator)-fraction<T>(other.numerator,other.denominator).getDenominator();
    }
    constexpr fraction operator/(const fraction &other) {
        return fraction<T>(numerator,denominator)*fraction<T>(other.denominator,other.numerator);
    }
    constexpr fraction operator/=(const fraction &other) {
         numerator = fraction<T>(numerator,denominator)/fraction<T>(other.numerator,other.denominator).getNumerator();
        denominator = fraction<T>(numerator,denominator)/fraction<T>(other.numerator,other.denominator).getDenominator();
    }
    friend std::ostream& operator<<(std::ostream &os, const fraction &f) {
        os << f.numerator << "/" << f.denominator;
        return os;
    }
    constexpr fraction(const T num, const T den): numerator(num),denominator(den) {
        assert(den!=0);
        T divisor=gcd(num,den);
        if(divisor) {
            numerator/=divisor;
            denominator/=divisor;
        }
    }
    constexpr T getNumerator() {return numerator;}
    constexpr T getDenominator() {return denominator;}
    constexpr T setNumerator(T num) {numerator = num;}
    constexpr T setDenominator(T num) {denominator = num;}

    //Conversion
    operator int() const {return (int)numerator/(int)denominator;}
    operator double() const {return (double)numerator/denominator;}
    operator float() const {return (float)numerator/(float)denominator;}
    constexpr fraction negativeReciprocal() {return fraction<T>(-denominator,numerator);}
    

};

#endif 
