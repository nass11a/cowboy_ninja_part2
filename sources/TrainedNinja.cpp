 #include "TrainedNinja.hpp"
using namespace ariel;
 bool TrainedNinja::slash(Character *other){
      if(!other->isAlive() || !this->isAlive()){
            std::__throw_runtime_error("Error: Character is already dead");
        }
        if(this==other){
            throw std::runtime_error("Error: Character cannot slash itself");
          }
            if(this->getLocation().distance(other->getLocation())<1){
                other->hit(slash_hitpoints);
                return true;
            }
            else{
                return false;
            }
            other->hit(tweenty);
            return true;

    }
bool TrainedNinja::move(Character* other) {
  Point new_location =Point::moveTowards(this->getLocation(),other->getLocation(),this->speed);
    this->_loc = new_location;//update the location
    return true;
}




    string TrainedNinja::print(){
        string tal="";
        cout << "trainedNinja " << getName() << " is at (" << getLocation().getX() << ", " << getLocation().getY() << ")" << endl;
        cout << "trainedNinja" << gethitpoints() << " hitpoints" << endl;
        return tal;
    }

    double TrainedNinja::getspeed() const{
        return speed;
    }