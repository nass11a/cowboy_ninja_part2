#ifndef TEAM_HPP
#define TEAM_HPP
#include "iostream"
#include "string"
#include "Point.hpp"
#include "Character.hpp"
#include "Cowboy.hpp"
#include "OldNinja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include <vector>
using namespace std;


const double temp=100000;
namespace ariel{
class Team{

    public:

    std::vector <Character * > _team_;

    double min=temp;

    Character *_leader;  
    Character *_leader2;
    
    Team(Character * leader):_leader(leader),_leader2(nullptr){

        if (leader->getincluded()) {
    throw std::runtime_error("Error: Leader already exists in the team");
    }

        _team_.push_back(leader);
        leader->setincluded(true);

        }


    // Copy constructor
    Team(const Team& other);
    // Copy assignment operator
    Team& operator=(const Team& other);

    // Move constructor
    Team(Team&& other) noexcept ;
    // Move assignment operator
    Team& operator=(Team&& other) noexcept ;

    void add(Character *charac);
    Character* findClosestCharacter(Team* other);
    Character* findClosestCharactera(const Character * character, const Team * team) ;
  
    void print();

    virtual ~Team();
    
    Team(){
        _leader=nullptr;
        _leader2=nullptr;
    }

    int stillAlive();
      void setLeader(Character* newLeader) {
        this->_leader = newLeader;
    }

    Character getleader(){
        return *_leader;
    }

    bool attack(Team *other);




        Character* findClosestCharactera(Team* other);

 //   bool attack(Team2 *other);




};
}
#endif