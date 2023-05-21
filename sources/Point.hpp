#ifndef POINT_HPP
#define POINT_HPP
#include "iostream"
#include "string"
#include <math.h>

using namespace std;
 namespace ariel{



 class Point{
    double _dxi;
    double _dyi;

    public:
    Point(double dxi, double dyi);
    Point():_dxi(0),_dyi(0){
    }

    Point(Point const &other);

//  Point() : _x(0), _y(0) {}


    // Destructor
    ~Point();

    // Copy assignment operator
    Point& operator=(const Point& other);

    // Move constructor
    Point(Point&& other) noexcept;

    // Move assignment operator
    Point& operator=(Point&& other) noexcept;

double distance(const Point &other) const ;

static Point moveTowards(const Point &source ,const Point &dest , double distance);

   string print() const ;
    double getX() const;

    double getY() const;


 };

 }

#endif
