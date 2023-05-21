#include "Point.hpp"
#include "Team2.hpp"
#include "Character.hpp"
#include "Cowboy.hpp"
#include "OldNinja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include <iostream>
#include <cmath>
using namespace std;
using namespace ariel;

int main() {
    // Create instances of characters
    Point a(1, 1), b(2, 2), c(3, 3), d(4, 4), e(2, 2);
    Point t(64, 57);

    YoungNinja *malia = new YoungNinja("Yogia", a);
    YoungNinja *yashia = new YoungNinja("kalia", b);
    Cowboy *toma = new Cowboy("Firasa", c);
    OldNinja *sushia = new OldNinja("Naela", d);
    YoungNinja *lauia = new YoungNinja("lakika", b);

    // Create Team2 instances
    Team2 Team2_A(malia);
    Team2_A.add(new YoungNinja("Yogiass", t));
    Team2_A.add(yashia);
    Team2_A.add(toma);
    Team2_A.add(sushia);
    Team2_A.add(lauia);

    TrainedNinja *flakea = new TrainedNinja("flakea", a);
    YoungNinja *drakea = new YoungNinja("drakea", b);
    Cowboy *snakea = new Cowboy("snakea", c);
    OldNinja *rakea = new OldNinja("rakea", d);
    YoungNinja *jacka = new YoungNinja("jacka", b);

    Team2 Team2_B(flakea);
    Team2_B.add(drakea);
    Team2_B.add(snakea);
    Team2_B.add(rakea);
    Team2_B.add(jacka);

    // Perform attacks between teams until one team wins
    while (Team2_A.stillAlive() > 0 && Team2_B.stillAlive() > 0) {
        Team2_A.attack(&Team2_B);
        Team2_B.attack(&Team2_A);
        Team2_A.print();
        Team2_B.print();
    }

    // Determine the winner based on remaining members
    if (Team2_A.stillAlive() > 0) {
        cout << "Team2_A is the winner!" << endl;
    } else {
        cout << "Team2_B is the winner!" << endl;
    }

    return 0;
}
