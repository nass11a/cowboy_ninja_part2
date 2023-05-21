#include "Character.hpp"
    using namespace ariel;

    Character::~Character(){}

  bool Character::isAlive() {
    return _hitpoints > 0;
}
      Character::Character(const Character& other):_name(other._name),_loc(other._loc),_hitpoints(other._hitpoints),alive(other.alive),included_(other.included_),isleader(other.isleader) {
    }
    Character::Character():_name(""),_loc(Point()),_hitpoints(0),alive(true),included_(false),isleader(false){
    }
    bool Character::getincluded(){
        return included_;
    }
    void Character::setincluded(bool included){
        included_=included;
    }
    Point  Character::getLocation()const{
        return _loc;
    }
    string  Character::getName(){
        return _name;
    }
    string  Character::print(){
        string t="";
       return t;
    }
    void  Character::hit(double hitpoints){
        if(hitpoints<0){
            throw std::invalid_argument("Error: negative value!");
        }
        _hitpoints -= hitpoints;
    }

   Character::Character(Character&& other) noexcept
    : _name(std::move(other._name)),
      _loc(std::move(other._loc)),
      _hitpoints(std::move(other._hitpoints)),
      alive(std::move(other.alive)),
      included_(std::move(other.included_)),
      isleader(std::move(other.isleader)){}

Character& Character::operator=(const Character& other) {
    if (this != &other) {
        _name = other._name;
        _loc = other._loc;
        _hitpoints = other._hitpoints;
        alive = other.alive;
        included_ = other.included_;
        isleader = other.isleader;
    }
    return *this;
}

Character& Character::operator=(Character&& other) noexcept {
    if (this != &other) {
        _name = std::move(other._name);
        _loc = std::move(other._loc);
        _hitpoints = other._hitpoints;
        alive = other.alive;
        included_ = other.included_;
        isleader = other.isleader;
        other._name = "";
        other._loc = Point();
        other._hitpoints = 0;
        other.alive = true;
        other.included_ = false;
        other.isleader = false;
    }
    return *this;
}




    double Character::distance(const Character* other) const {
    return _loc.distance(other->getLocation());
}

    void  Character::setlocation(Point loc){
        _loc=loc;
    }
    double  Character::gethitpoints(){
        return _hitpoints;
    }
    void  Character::sethitpoints(double hitpoints){
        _hitpoints=hitpoints;
    }