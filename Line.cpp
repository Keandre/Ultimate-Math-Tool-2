#include "Line.h"
template <typename T>

constexpr point point::operator=(const point &in) {
  x = in.x;
  y = in.y;
}

friend std::ostream& point::operator<<(std::ostream &os,const point &p) {
  os << p.x << ";" << p.y;
  return os;
}

T point::getX() {return x;}
T point::getY() {return y;}

//Point class

constexpr line line::operator=(const point<T> &in) {
  p1 = in.p1;
  p2 = in.p2;
}

constexpr T line::length() {
  return std::pow(p2.x-p1.x,2)+std::pow(p2.y-p1.y,2);
}

constexpr point<T> point::firstPoint() {
  return p1;
}

constexpr point<T> point::secondPoint() {
  return p2;
}

constexpr point<T> point::midpoint() {
  return point<T>((p1.x+p2.x)/2,(p1.y+p2.y)/2);
}


