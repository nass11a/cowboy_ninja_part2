#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include "iostream"
#include "string"
#include "Point.hpp"

using namespace std;
namespace ariel{



class Character{
  
    public:
    string _name;
    Point _loc;
    double _hitpoints;
    bool alive;
    bool included_;
    bool isleader;
    Character(string name,const Point &loc);
    virtual ~Character();
     // Copy constructor
    Character(const Character& other);
    Character();
    // Copy assignment operator
    Character& operator=(const Character& other);
       Character(Character&& other) noexcept;

    Character& operator=(Character&& other) noexcept ;

    bool isAlive();
   // bool move(Character *other);
    Point getLocation()const;
    string getName();
    string print();
    void hit(double hitpoints);
    double distance(const Character *other) const;
    void setlocation(Point loc);
    double gethitpoints();
    void sethitpoints(double hitpoints);
    bool getincluded();
    void setincluded(bool included);

    
};

}

#endif