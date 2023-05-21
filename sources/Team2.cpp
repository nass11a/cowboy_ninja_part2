#include "Team2.hpp"
using namespace ariel;

bool Team2::attack(Team *other){
     if(other==nullptr){
            throw  std::invalid_argument("Team is null");
            }

       if (other->stillAlive() <=0) {
        throw std::runtime_error("Error: Attacking a dead team");
    }
    

        if(this->stillAlive()==0 || other->stillAlive()==0){
            throw std::runtime_error("Team is dead");
        }

        if(_leader->isAlive()){

           Character* minDistance_character= findClosestCharactera(other);

           for (std::vector<Character*>::size_type i = 0; i < _team_.size(); i++){

            if ( TrainedNinja* TrainedNinja_temp = dynamic_cast<TrainedNinja*>(_team_.at(i))) {

                if(TrainedNinja_temp ->isAlive() && TrainedNinja_temp->distance(minDistance_character) < 1 &&minDistance_character->isAlive()){

                   TrainedNinja_temp->slash(minDistance_character);

                       if(minDistance_character->gethitpoints() <= 0){
                           minDistance_character->alive=false;
                       }
                 
                   
                 }

                else {
                     if(TrainedNinja_temp ->isAlive() && minDistance_character->isAlive() ){

                    TrainedNinja_temp->move(minDistance_character);
                     }
                }

               if (!minDistance_character->isAlive() && minDistance_character->isleader && other->stillAlive() > 0) {
                    Character* temp = findClosestCharacter(other);
                    temp->isleader = true;
                    other->setLeader(temp);

                if (temp == minDistance_character) {
                     break; 
                }

    minDistance_character = temp;
}

            }
              if ( Cowboy* cowboy_temp = dynamic_cast<Cowboy*>(_team_.at(i))) {
                    
                bool shooted=false;

                if(cowboy_temp ->isAlive() && cowboy_temp->hasboolets() && minDistance_character->isAlive()){

                    cowboy_temp->shoot(minDistance_character);
                   
                    if(minDistance_character->gethitpoints() <= 0){
                           minDistance_character->alive=false;
                    }
                    shooted=true;

                 }

          if (!minDistance_character->isAlive() && minDistance_character->isleader && other->stillAlive() > 0) {
             Character* temp = findClosestCharacter(other);
             temp->isleader = true;
             other->setLeader(temp);

         if (temp == minDistance_character) {
              break; 
              }

              minDistance_character = temp;
}   

         if(cowboy_temp ->isAlive() && !cowboy_temp->hasboolets()&& minDistance_character->isAlive() && !shooted){
                    
                    cowboy_temp->reload();
                    
                    }

                }
           


                if ( OldNinja* OldNinja_temp = dynamic_cast<OldNinja*>(_team_[i])) {

                if(OldNinja_temp ->isAlive() && OldNinja_temp->distance(minDistance_character) < 1 && minDistance_character->isAlive()){
                   OldNinja_temp->slash(minDistance_character);
                    if(minDistance_character->gethitpoints() <= 0){
                           minDistance_character->alive=false;
                    }
                 }

                else {
                    if(OldNinja_temp ->isAlive()&& minDistance_character->isAlive()){
                    OldNinja_temp->move(minDistance_character);
                    }
                }

               if (!minDistance_character->isAlive() && minDistance_character->isleader && other->stillAlive() > 0) {
                    Character* temp = findClosestCharacter(other);
                    temp->isleader = true;
                    other->setLeader(temp);

                if (temp == minDistance_character) {
                    break; 
                    }

                minDistance_character = temp;
            }

            
        }       
                 if ( YoungNinja* YoungNinja_temp = dynamic_cast<YoungNinja*>(_team_[i])) {

                if(YoungNinja_temp ->isAlive() && YoungNinja_temp->distance(minDistance_character) < 1 && minDistance_character->isAlive()){
                   YoungNinja_temp->slash(minDistance_character);
                    if(minDistance_character->gethitpoints() <= 0){
                           minDistance_character->alive=false;
                    }
                 }

                else {
                    if(YoungNinja_temp ->isAlive()&& minDistance_character->isAlive()){
                    YoungNinja_temp->move(minDistance_character);
                    }
                }



         if (!minDistance_character->isAlive() && minDistance_character->isleader && other->stillAlive() > 0) {
                Character* temp = findClosestCharacter(other);
                temp->isleader = true;
                other->setLeader(temp);

        if (temp == minDistance_character) {
         break; 
         }

        minDistance_character = temp;
    }

             }
           }
          
        return true;
    }
    
        if(!_leader->isAlive() && stillAlive() > 0){

            Character* temp= findClosestCharacter(this);
                  temp->isleader=true;
                  this->setLeader(temp);

          attack(other);
            return true;
        }

            return false;
}