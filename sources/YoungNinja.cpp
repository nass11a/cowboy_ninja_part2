 #include "YoungNinja.hpp"
using namespace ariel;
 bool YoungNinja::slash(Character *other){
          if(!other->isAlive() || !this->isAlive()){
            std::__throw_runtime_error("Error: Character is already dead");
        }
         if(this==other){
            throw std::runtime_error("Error: Character cannot slash itself");
          }
            if(this->getLocation().distance(other->getLocation())<1){
                other->hit(slash_hitpoints_1);
                return true;
            }
            else{
                return false;
            }
    }

bool YoungNinja::move(Character* other) {
  Point new_location =Point::moveTowards(this->getLocation(),other->getLocation(),this->speed);
    this->_loc = new_location;//update the location
    return true;
}

    string YoungNinja::print(){
        string tal="";
        cout << "YoungNinja " << getName() << " is at (" << getLocation().getX() << ", " << getLocation().getY() << ")" << endl;
        cout << "YoungNinja" << gethitpoints() << " hitpoints" << endl;
        return tal;
    }

    double YoungNinja::getspeed() const{
        return speed;
    }