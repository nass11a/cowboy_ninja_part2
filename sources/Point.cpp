#include "Point.hpp"
using namespace ariel;

 Point::Point(double dxi, double dyi):_dxi(dxi),_dyi(dyi){

 }
    
    Point::Point(Point const &other):_dxi(other._dxi),_dyi(other._dyi){}


    // Destructor
    Point::~Point() {}

    // Copy assignment operator
    Point& Point::operator=(const Point& other) {
        if (this != &other) {
            _dxi = other._dxi;
            _dyi = other._dyi;
        }
        return *this;
    }

    // Move constructor
    Point::Point(Point&& other) noexcept : _dxi(std::move(other._dxi)), _dyi(std::move(other._dyi)) {}

    // Move assignment operator
    Point& Point::operator=(Point&& other) noexcept {
        if (this != &other) {
            _dxi = std::move(other._dxi);
            _dyi = std::move(other._dyi);
        }
        return *this;
    }

double Point::distance(const Point &other) const {
    double dx_temp = _dxi - other._dxi;
    double dy_temp = _dyi - other._dyi;
        return std::sqrt(dx_temp * dx_temp + dy_temp * dy_temp);
    
}

 Point Point::moveTowards(const Point &source ,const Point &dest , double distance){

    if(distance < 0){

        throw std::invalid_argument("the distance cannot be negative!");

    }

    double dxa = dest.getX() - source.getX();

        double dya = dest.getY() - source.getY();

        double currentDistance = std::sqrt(dxa * dxa + dya * dya);
        
        if (currentDistance <= distance) {

            return dest;

        } 
            double ratio = distance / currentDistance;

            double newX = source.getX() + dxa * ratio;

            double newY = source.getY() + dya * ratio;

            return Point(newX, newY);

        
    }

   string Point::print() const {
        return to_string(_dxi) + "," + to_string(_dyi);
    }

    double Point::getX() const{
        return _dxi;
    }
    double Point::getY() const{
        return _dyi;
    }