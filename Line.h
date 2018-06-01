#ifndef LINE_H
#define LINE_H
#include "Fraction.h"
#include <cmath>
#include <sstream>
#include "boost/variant.hpp"


template <typename T>
class point {
    private:
    T x;
    T y;
    public:
    constexpr point operator=(const point &in) {
        x = in.x;
        y = in.y;
    }
    constexpr point (T in, T in2):x(in),y(in2){}
    friend std::ostream& operator<<(std::ostream &os, const point &p){
        os << p.x << ";" << p.y;
        return os;
    }
    T getX() {return x;}
    T getY() {return y;}
};
template <typename T>
class line {
   private:
   point<T> p1;
   point<T> p2;
   public:
   constexpr line(point<T> p1, point<T> p2) : p1(p1),p2(p2) {}
   constexpr line operator=(const point<T> &in) {
       p1 = in.p1;
       p2 = in.p2;
   }
   constexpr T length() {return std::pow(p2.x-p1.x,2)+std::pow(p2.y-p1.y,2);}
   constexpr point<T> firstPoint() {return p1;}
   constexpr point<T> secondPoint() {return p2;}
   constexpr point<T> midpoint() {return point<T>((p1.x+p2.x)/2,(p1.y+p2.y)/2);}
   constexpr fraction<T> slope() {return fraction<T>(p2.getY()-p1.getY(),p2.getX()-p1.getX());}

    constexpr std::string equation() {
        
    
    }
};

#endif 