//
// Created by mcnichol on 8/29/20.
//

#ifndef LAB_01_MAIN_H
#define LAB_01_MAIN_H

struct Player {
    Player(){
        name = "";
        number = -1;
        totalPoints = -1;
    }

    std::string name;
    int number;
    int totalPoints;
};

const int ROSTER_SIZE = 3;

void loadPlayers(Player[]);
void displayTable(Player[]);

void displayHeader();
void displayRoster(Player[]);
void displayPlayer(Player*);
void displayTeamStats(Player[]);
void displayTopPerformer(Player[]);

int getValidPlayerNumber(int);
int getValidPointScored(int);

#endif //LAB_01_MAIN_H
