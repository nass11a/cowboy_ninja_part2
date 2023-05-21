#ifndef YoungNinja_HPP
#define YoungNinja_HPP


#include "Character.hpp"
#include "iostream"
#include "string"
#include "Point.hpp"

using namespace std;


const int tweenty_1 = 20;
const int speed_num_1 = 14;
const int hitpoints_num_1 = 100;
const int slash_hitpoints_1 = 40;

namespace ariel{
class YoungNinja:public Character{
    double speed;
    bool alive;

    public:

   YoungNinja(string name,const Point &loc):Character(std::move(name),loc),speed(speed_num_1),alive(true){
        this->sethitpoints(hitpoints_num_1);
    }
    bool slash(Character *other);

    bool move(Character *other);
    
    string print();

    double getspeed() const;
};
}
#endif