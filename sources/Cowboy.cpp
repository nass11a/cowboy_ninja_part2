 #include "Cowboy.hpp"
  using namespace ariel;
  const int hunderd=100;
 bool Cowboy::shoot(Character * other){
           if(!other->isAlive()||!this->isAlive()){
            std::__throw_runtime_error("Error: Character is already dead");
        }

          if(this==other){
            throw std::runtime_error("Error: Character cannot shoot itself");
          }
            if(bullet_numbers>0){
                bullet_numbers--;
                other->hit(10);
                return true;
            }
            else{
                return false;
            }
    }

    Character::Character(string name,const Point &loc):_name(std::move(name)),_loc(loc),_hitpoints(hunderd),alive(true),included_(false),isleader(true){
    }  

   string Cowboy::print(){
    string t="";
    cout << "Cowboy " << getName() << " is at (" << getLocation().getX() << ", " << getLocation().getY() << ")" << endl;
    cout << "Cowboy" << gethitpoints() << " hitpoints" << endl;
    return t;
    }

      bool Cowboy::reload(){
        if(!this->isAlive()){
            std::__throw_runtime_error("Error: Character is already dead");
        }
            bullet_numbers=6;
            return true;
        
        return false;
    }
    bool Cowboy::hasboolets(){
      if(bullet_numbers>0)
        return true;
        else
      return false;
    }

    double Cowboy::bulletsnum(){
        return bullet_numbers;
    }