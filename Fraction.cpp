#include "Fraction.h"

template <typename T>
constexpr int fraction::gcd(const T x, const T y) {
  if (y) {
    return gcd(y,x%y);
  }
  else {
    return x;
  }
 }

//=
template <typename T>
constexpr operator fraction::operator=(const T in) {
  numerator = in;
  denominator = 1;
}

constexpr operator fraction::operator=(const fraction &in) {
  numerator = in.numerator;
  denominator = in.denominator;
}

//==
constexpr operator fraction::operator==(const fraction &out) {
  return (numerator==out.numerator) && (denominator==out.denominator);
}

template <typename T>
constexpr operator fraction::operator==(const T &val) {
  return (numerator/denominator)==val;
}

//!=
constexpr fraction fraction::operator!=(const fraction &out) {
  return (numerator!=out.numerator) || (denominator!=out.denominator);
}

template <typename T>
constexpr fraction fraction::operator!=(const T &out) {
  return (numerator/denominator) != out;
}

//*
constexpr fraction fraction::operator*(const fraction &other) {
  return fraction<T>(numerator*other.numerator,denominator*other.denominator);
}

template <typename T>
constexpr fraction fraction::operator*(const T &other) {
  return fraction<T>(numerator*other,denominator);
}

//*=

constexpr fraction fraction::operator*=(const fraction &other) {
  numerator *= other.numerator;
  denominator *= other.denominator;
}

template <typename T>
constexpr fraction fraction::operator*=(const T &other) {
  numerator *= other;
}

//+
constexpr fraction fraction::operator+(const fraction &other) {
  T commonMultiple = denominator*other.denominator;
  numerator *= commonMultiple/denominator;
  other.numerator *= commonMultiple/other.denominator;
  return fraction<T>(numerator+other.numerator,commonMultiple);
}

//+=
constexpr fraction fraction::operator+=(const fraction &other) {
   numerator = fraction<T>(numerator,denominator)+fraction<T>(other.numerator,other.denominator).getNumerator();
   denominator = fraction<T>(numerator,denominator)+fraction<T>(other.numerator,other.denominator).getDenominator();
}

//-
constexpr fraction fraction::operator-(const fraction &other) {
  T commonMultiple = denominator*other.denominator;
  numerator *= commonMultiple/denominator;
  other.numerator *= commonMultiple/other.denominator;
  return fraction<T>(numerator-other.numerator,commonMultiple);
}
constexpr fraction fraction::operator-() {
  return fraction<T>(-numerator,denominator);
}

//-=
constexpr fraction fraction::operator-=(const fraction &other) {
     numerator = fraction<T>(numerator,denominator)-fraction<T>(other.numerator,other.denominator).getNumerator();
     denominator = fraction<T>(numerator,denominator)-fraction<T>(other.numerator,other.denominator).getDenominator();
}

//Division
 constexpr fraction operator/(const fraction &other) {
        return fraction<T>(numerator,denominator)*fraction<T>(other.denominator,other.numerator);
 }

//Division=
constexpr fraction operator/=(const fraction &other) {
         numerator = fraction<T>(numerator,denominator)/fraction<T>(other.numerator,other.denominator).getNumerator();
        denominator = fraction<T>(numerator,denominator)/fraction<T>(other.numerator,other.denominator).getDenominator();
    }

friend std::ostream& operator<<(std::ostream &os,const fraction &f) {
  os << f.numerator << "/" << f.denominator;
  return os;
}

constexpr fraction::fraction(const T num, const T den): numerator(num),denominator(den) {
  assert(den!=0);
  T divisor=gcd(num,den);
  if (divisor) {
    numerator/=divisor;
    denominator/=divisor;
  }
}
constexpr fraction::fraction(const T num) {
  numerator = fraction<T>(num*num,num).getNumerator();
  denominator = fraction<T>(num*num,num).getDenominator();
}
constexpr T fraction::getNumerator() {return numerator;}
constexpr T fraction::getDenominator() {return denominator;}
constexpr T fraction::setNumerator(T num) {numerator = num;}
constexpr T fraction::setDenominator(T num) {denominator = num;}

    //Conversion
operator fraction::int() const {return (int)numerator/(int)denominator;}
operator fraction::double() const {return (double)numerator/denominator;}
operator fraction::float() const {return (float)numerator/(float)denominator;}
operator fraction::std::string() const { return std::to_string(numerator)+"/"+std::to_string(denominator); }
constexpr fraction fraction::negativeReciprocal() {return fraction<T>(-denominator,numerator);}
    








 

