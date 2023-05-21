#include "OldNinja.hpp"
using namespace ariel;
bool OldNinja::slash(Character *other){
        if(!other->isAlive() || !this->isAlive()){
            std::__throw_runtime_error("Error: Character is already dead");
        }
        if(this==other){
            throw std::runtime_error("Error: Character cannot slash itself");
          }

            if(this->getLocation().distance(other->getLocation())<1){
                other->hit(slash_hitpoints1);
                return true;
            }
            else{
                return false;
            }

            other->hit(tweenty1);
            return true;
        
      
    }

bool OldNinja::move(Character* other) {
   Point new_location =Point::moveTowards(this->getLocation(),other->getLocation(),this->speed);
    this->_loc = new_location;//update the location
    return true;
}



    string OldNinja::print(){
        string tal="";
        cout << "OldNinja " << getName() << " is at (" << getLocation().getX() << ", " << getLocation().getY() << ")" << endl;
        cout << "OldNinja" << gethitpoints() << " hitpoints" << endl;
        return tal;
    }

    double OldNinja::getspeed() const{
        return speed;
    }