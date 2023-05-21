#include "SmartTeam.hpp"
using namespace ariel;
#include <limits>

bool SmartTeam::attack(Team* other) {
    if (other == nullptr) {
        throw std::invalid_argument("Team is null");
    }

    if (other->stillAlive() <= 0) {
        throw std::runtime_error("Error: Attacking a dead team");
    }

    if (this->stillAlive() == 0 || other->stillAlive() == 0) {
        throw std::runtime_error("Team is dead");
    }

    if (!_leader->isAlive() && stillAlive() > 0) {
        Character* temp = findClosestCharacter(this);
        temp->isleader = true;
        this->setLeader(temp);
        return attack(other);
    }

    Character* minHP_character = nullptr;
    int minHP = std::numeric_limits<int>::max();

    for (Character* enemy : other->_team_) {
        if (enemy->isAlive() && enemy->gethitpoints() < minHP) {
            minHP_character = enemy;
            minHP = enemy->gethitpoints();
        }
    }

    for (Character* attacker : _team_) {
        if (!attacker->isAlive()) {
            continue;
        }

        if (TrainedNinja* trainedNinja = dynamic_cast<TrainedNinja*>(attacker)) {
            if (trainedNinja->isAlive() && trainedNinja->distance(minHP_character) < 1 && minHP_character->isAlive()) {
                trainedNinja->slash(minHP_character);

                if (minHP_character->gethitpoints() <= 0) {
                    minHP_character->alive = false;
                }
            } else if (trainedNinja->isAlive() && minHP_character->isAlive()) {
                trainedNinja->move(minHP_character);
            }

            if (!minHP_character->isAlive() && minHP_character->isleader && other->stillAlive() > 0) {
                Character* newLeader = findClosestCharacter(other);
                newLeader->isleader = true;
                other->setLeader(newLeader);

                if (newLeader == minHP_character) {
                    break;
                }

                minHP_character = newLeader;
            }
        } else if (Cowboy* cowboy = dynamic_cast<Cowboy*>(attacker)) {
            bool shooted = false;

            if (cowboy->isAlive() && cowboy->hasboolets() && minHP_character->isAlive()) {
                cowboy->shoot(minHP_character);

                if (minHP_character->gethitpoints() <= 0) {
                    minHP_character->alive = false;
                }
                shooted = true;
            }

            if (!minHP_character->isAlive() && minHP_character->isleader && other->stillAlive() > 0) {
                Character* newLeader = findClosestCharacter(other);
                newLeader->isleader = true;
                other->setLeader(newLeader);

                if (newLeader == minHP_character) {
                    break;
                }

                minHP_character = newLeader;
            }

            if (cowboy->isAlive() && !cowboy->hasboolets() && minHP_character->isAlive() && !shooted) {
                cowboy->reload();
            }
        } else if (OldNinja* oldNinja = dynamic_cast<OldNinja*>(attacker)) {
            if (oldNinja->isAlive() && oldNinja->distance(minHP_character) < 1 && minHP_character->isAlive()) {
                oldNinja->slash(minHP_character);

                if (minHP_character->gethitpoints() <= 0) {
                    minHP_character->alive = false;
                }
            } else if (oldNinja->isAlive() && minHP_character->isAlive()) {
                oldNinja->move(minHP_character);
            }

            if (!minHP_character->isAlive() && minHP_character->isleader && other->stillAlive() > 0) {
                Character* newLeader = findClosestCharacter(other);
                newLeader->isleader = true;
                other->setLeader(newLeader);

                if (newLeader == minHP_character) {
                    break;
                }

                minHP_character = newLeader;
            }
        } else if (YoungNinja* youngNinja = dynamic_cast<YoungNinja*>(attacker)) {
            if (youngNinja->isAlive() && youngNinja->distance(minHP_character) < 1 && minHP_character->isAlive()) {
                youngNinja->slash(minHP_character);

                if (minHP_character->gethitpoints() <= 0) {
                    minHP_character->alive = false;
                }
            } else if (youngNinja->isAlive() && minHP_character->isAlive()) {
                youngNinja->move(minHP_character);
            }

            if (!minHP_character->isAlive() && minHP_character->isleader && other->stillAlive() > 0) {
                Character* newLeader = findClosestCharacter(other);
                newLeader->isleader = true;
                other->setLeader(newLeader);

                if (newLeader == minHP_character) {
                    break;
                }

                minHP_character = newLeader;
            }
        }
    }

    return true;
}
