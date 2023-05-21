#ifndef TRAINEDNINJA_HPP
#define TRAINEDNINJA_HPP

#include "Character.hpp"
#include "iostream"
#include "string"
#include "Point.hpp"

using namespace std;

const int tweenty = 20;
const int speed_num = 12;
const int hitpoints_num = 120;
const int slash_hitpoints = 40;

namespace ariel{

class TrainedNinja:public Character{
    double speed;
    bool alive;

    public:
    TrainedNinja(string name,const Point &loc):Character(std::move(name),loc),speed(speed_num),alive(true){
        this->sethitpoints(hitpoints_num);
    }
    bool slash(Character *other);
    
    bool move(Character *other);

    string print();

    double getspeed() const;
};
}
#endif