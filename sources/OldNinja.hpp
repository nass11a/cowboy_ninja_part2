#ifndef OLDNINJA_HPP
#define OLDNINJA_HPP

#include "Cowboy.hpp"
#include "iostream"
#include "string"
#include "Point.hpp"

using namespace std;

const int tweenty1 =20;
const int speed_num1= 8;
const int hitpoints_num1 =150;
const int slash_hitpoints1 = 40;
namespace ariel{
class OldNinja:public Character{
    double speed;
    bool alive;

    public:
    OldNinja(string name,const Point &loc):Character(std::move(name),loc),speed(speed_num1),alive(true){
        this->sethitpoints(hitpoints_num1);
    }
    bool slash(Character *other);
    bool move(Character *other);

    string print();

    double getspeed() const;

};
}
#endif