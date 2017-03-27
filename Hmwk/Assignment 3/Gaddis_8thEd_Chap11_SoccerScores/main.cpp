/* 
 * File:   main.cpp
 * Author: admin
 *
 * Created on March 23, 2017, 1:22 AM
 */

#include <cstdlib>
#include <iostream>
using namespace std;
#include "Player.h"

/*
 * 
 */
void displayPlayers(Player *);
int SIZE = 12;

int main(int argc, char** argv) {


    Player *player = new Player[SIZE];
    for (int i = 0; i < SIZE; i++) {
        cout << "Player " << i + 1 << endl;
        cout << "Enter name: ";
        cin >> player[i].name;
        do {
            cout << "Enter number of player: ";
            cin >> player[i].number;
        } while (player[i].number < 0);
        do {
            cout << "Enter point scored by player: ";
            cin >> player[i].point;
        } while (player[i].point < 0);
    }
    displayPlayers(player);
    int totalPoints = 0;
    int highestPoint = 0;
    for (int i = 0; i < SIZE; i++) {
        if (player[i].point > highestPoint)highestPoint = player[i].point;
        totalPoints += player[i].point;
    }
    cout << "The total points earned by them team: " << totalPoints << endl;
    cout << "The players have the highest points" << endl;
    cout << "Name\tNumber\tPoints" << endl;
    for (int i = 0; i < SIZE; i++) {
        if (highestPoint == player[i].point) {
            cout << player[i].name << "\t" << player[i].number << "\t" << player[i].point << endl;
        }
    }
    return 0;
}

void displayPlayers(Player *p) {
    cout << "List of players" << endl;
    cout << "Name\tNumber\tPoints" << endl;
    for (int i = 0; i < SIZE; i++) {
        cout << p[i].name << "\t" << p[i].number << "\t" << p[i].point << endl;
    }
}

