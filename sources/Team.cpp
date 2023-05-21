 #include "Team.hpp"
 #include <limits>
    using namespace ariel;
    using namespace std;
   // Copy constructor
    Team::Team(const Team& other) {
        // Copy constructor implementation
    }

    // Copy assignment operator
    Team& Team::operator=(const Team& other) {
        if (this != &other) {
            // Copy assignment operator implementation
        }
        return *this;
    }

    // Move constructor
    Team::Team(Team&& other) noexcept {
        // Move constructor implementation
    }

    // Move assignment operator
    Team& Team::operator=(Team&& other) noexcept {
        if (this != &other) {
            // Move assignment operator implementation
        }
        return *this;
    }

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

 void Team::add(Character *charac){
     if (_team_.size() == 10) {
        throw std::runtime_error("Team is already full");
    }
    if(charac->getincluded() == true){
        throw std::runtime_error("Character is already in a team");
    }


        if(charac->distance(_leader)<min){
            min=charac->distance(_leader);
            _leader2=charac;
        }
        

    _team_.push_back(charac);
    charac->setincluded(true);

    }



void Team::print(){
    cout << "Team Leader: " << _leader->getName() << endl;
    for (std::vector<Character*>::size_type i = 0; i < _team_.size(); i++)
    {
    _team_.at(i)->print();
    }
       
   
        
    }

Team::~Team(){
    for (std::vector<Character*>::size_type i = 0; i < _team_.size(); i++)
    {
       delete _team_.at(i);
    }   
}

    int Team::stillAlive(){
        int count=0;
          for (std::vector<Character*>::size_type i = 0; i < _team_.size(); i++){
                if(_team_.at(i)->isAlive()){
                    count++;
                }
          }

       return count;
    }



    bool Team::attack(Team *other){
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

        }

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
    
    Character* Team::findClosestCharacter(Team* other) { 
    Character* minDistance_character = nullptr;
    double min = TMP_MAX;

    for (std::vector<Character*>::size_type i = 0; i < other->_team_.size(); i++) {
    if (other->_team_[i]->isAlive()) {
        double temp = other->_leader->distance(other->_team_[i]);
        if (temp < min) {
            min = temp;
            minDistance_character = other->_team_[i];
        }
    }
}

return minDistance_character;

    }


Character* Team::findClosestCharactera(Team* other) {
    Character* minDistance_character = nullptr;
    double min = TMP_MAX;

    for (std::vector<Character*>::size_type i = 0; i < other->_team_.size(); i++) {
        if (other->_team_[i]->isAlive()) {
            double temp = _leader->distance(other->_team_[i]);
            if (temp < min) {
                min = temp;
                minDistance_character = other->_team_[i];
            }
        }
    }
    return minDistance_character;
}
