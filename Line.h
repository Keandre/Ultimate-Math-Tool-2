#ifndef LINE_H
#define LINE_H
#include "Fraction.h"
#include <cmath>
#include <sstream>


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
   constexpr line operator=(const point<T> &in);
   constexpr T length();
   constexpr point<T> firstPoint() {return p1;}
   constexpr point<T> secondPoint() {return p2;}
   constexpr point<T> midpoint() {;}
   constexpr fraction<T> slope() {return fraction<T>(p2.getY()-p1.getY(),p2.getX()-p1.getX());}
   constexpr std::string equation() {
      //y = mx + b
      std::string b;
      int intSlope=0;
      fraction<T> fracSlope=fraction<T>(1,1);
      if (((p2.getY()-p1.getY())/(p2.getX()-p1.getX())==(int)(p2.getY()-p1.getY())/(p2.getX()-p1.getX()))) {
	   intSlope = (p2.getY()-p1.getY())/(p2.getX()-p1.getX());
      }
      else {
	 fracSlope = fraction<T>(p2.getY()-p1.getY(),p2.getX()-p1.getX());
      }
      if (intSlope!=0) {
	if ((p2.getY()-intSlope*p2.getX())==(int)(p2.getY()-intSlope*p2.getX())) {
	  b = std::to_string((int)p2.getY()-intSlope*p2.getX());
	}
      }
      else {
	b = std::to_string((-fracSlope+p2.getY()*p2.getX()));
      }
      if (intSlope!=0) {
	return std::to_string("y = "+std::to_string(intSlope)+"x + "+b);
      }
      else {
	return std::to_string("y = "+(std::string)fracSlope+"x + "+b);
      }
   }
     
};

#endif 
