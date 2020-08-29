#include <iostream>
#include <string>
#include <iomanip>
#include "main.h"
using namespace std;

int main() {
    auto roster = new Player[3];

    loadPlayers(roster);
    displayTable(roster);

    return 0;
}

void loadPlayers(Player roster[]){
    for(int i = 0; i < 3; i++) {
        int currentPlayer = i+1;
        cout << "Entering information for Player "<< currentPlayer << endl << endl;
        cout << "Enter the name for Player " << currentPlayer << ": ";
        getline(cin, roster[i].name);

        bool validPlayerNumber = false;
        while(!validPlayerNumber){
            cout << "Enter the number for Player " << currentPlayer << ": ";
            cin >> roster[i].number;

            if(roster[i].number >= 0){
               validPlayerNumber = true;
            }
        }

        bool validPointScored = false;
        while(!validPointScored){
            cout << "Enter the total points scored for Player " << currentPlayer << ": ";
            cin >> roster[i].totalPoints;

            if(roster[i].totalPoints >= 0){
                validPointScored = true;
            }
        }

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
};

void displayRoster(Player roster[]){
    for(int i = 0; i < 3; i++) {
        displayPlayer(roster[i]);
    }
    cout << endl;
};

void displayPlayer(Player thisPlayer){
    cout << right << setw(20) << thisPlayer.name <<  setw(20) << thisPlayer.number << setw(20) << thisPlayer.totalPoints << endl;
};

void displayTeamStats(Player roster[]){
    int teamTotal = 0;
    for(int i = 0; i < 3; i++) {
        teamTotal += roster[i].totalPoints;
    }

    cout << "Team Points: " << teamTotal << endl;
}

void displayTopPerformer(Player roster[]){
    int topPerformerIndex = 0;
    for(int i = 1; i < 3; i++) {
        topPerformerIndex = roster[topPerformerIndex].totalPoints > roster[i].totalPoints ? topPerformerIndex : i;
    }

    cout << "Top Performer: " << roster[topPerformerIndex].name << " wearing jersey #" << roster[topPerformerIndex].number << endl;
};


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