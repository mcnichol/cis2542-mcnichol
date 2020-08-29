#include <iostream>
#include <string>
#include <iomanip>
#include "main.h"

using namespace std;

int main() {
    Player *roster = new Player[ROSTER_SIZE];

    loadPlayers(roster);
    displayTable(roster);

    return 0;
}

void loadPlayers(Player roster[]){
    for(int i = 0; i < ROSTER_SIZE; i++) {
        int currentPlayer = i+1;
        cout << "Entering information for Player "<< currentPlayer << endl << endl;
        cout << "Enter the name for Player " << currentPlayer << ": ";
        getline(cin, roster[i].name);

        roster[i].number = getValidPlayerNumber(currentPlayer);
        roster[i].totalPoints = getValidPointScored(currentPlayer);

        cin.ignore(INT_MAX, '\n');
        cout << endl;
    }
}

void displayTable(Player roster[]){
    displayHeader();
    displayRoster(roster);
    displayTeamStats(roster);
    displayTopPerformer(roster);
}

void displayHeader(){
    cout << right << setw(20) << "Player Name" <<  setw(20) << "Player Number" << setw(20) << "Total Points" << endl;
    cout << "=================================================================" << endl;
}

void displayRoster(Player roster[]){
    for(int i = 0; i < ROSTER_SIZE; i++) {
        displayPlayer(&roster[i]);
    }
    cout << endl;
}

void displayPlayer(Player *thisPlayer){
    cout << right << setw(20) << thisPlayer->name <<  setw(20) << thisPlayer->number << setw(20) << thisPlayer->totalPoints << endl;
}

void displayTeamStats(Player roster[]){
    int teamTotal = 0;
    for(int i = 0; i < ROSTER_SIZE; i++) {
        teamTotal += roster[i].totalPoints;
    }

    cout << "Team Points: " << teamTotal << endl;
}

void displayTopPerformer(Player roster[]){
    int topPerformerIndex = 0;
    for(int i = 1; i < ROSTER_SIZE; i++) {
        topPerformerIndex = roster[topPerformerIndex].totalPoints > roster[i].totalPoints ? topPerformerIndex : i;
    }

    cout << "Top Performer: " << roster[topPerformerIndex].name << " wearing jersey #" << roster[topPerformerIndex].number << endl;
}

int getValidPointScored(int currentPlayer) {
    int pointScored = -1;
    while(pointScored < 0){
        cout << "Enter the total points scored for Player " << currentPlayer << ": ";
        cin >> pointScored;
    }

    return pointScored;
}

int getValidPlayerNumber(int currentPlayer) {
    int playerNumber = -1;
    while(playerNumber < 0){
        cout << "Enter the number for Player " << currentPlayer << ": ";
        cin >> playerNumber;
    }

    return playerNumber;
}

/*
Entering information for Player 1

Enter the name for Player 1: Player One
Enter the number for Player 1: -1
Enter the number for Player 1: -100
Enter the number for Player 1: 1
Enter the total points scored for Player 1: 10

Entering information for Player 2

Enter the name for Player 2: Player Two
Enter the number for Player 2: -2
Enter the number for Player 2: 2
Enter the total points scored for Player 2: 200

Entering information for Player 3

Enter the name for Player 3: Player Three
Enter the number for Player 3: 3
Enter the total points scored for Player 3: -30
Enter the total points scored for Player 3: 30

         Player Name       Player Number        Total Points
=================================================================
          Player One                   1                  10
          Player Two                   2                 200
        Player Three                   3                  30

Team Points: 240
Top Performer: Player Two wearing jersey #2
 */