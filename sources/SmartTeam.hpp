#include "Team.hpp"
namespace ariel{
class SmartTeam : public Team {
    public:
    SmartTeam(Character * leader):Team(leader){}
    bool attack(Team *other);
};

}