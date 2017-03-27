/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: rcc
 *
 * Created on March 22, 2017, 7:43 PM
 */

#include <cstdlib>
#include <iostream>
using namespace std;
#include "MovieData.h"
/*
 * 
 */
void displayMovie(MovieData *);

int main(int argc, char** argv) {

    MovieData *m1 = new MovieData();
    m1->director = "Kevin";
    m1->title = "Love 90 days";
    m1->yearRelease = 2010;
    m1->runningTime = 90;
    m1->productionCost = 13523.34f;
    m1->firstYearRevenues = 32356.12f;

    MovieData *m2 = new MovieData();
    m2->director = "John";
    m2->title = "Batman";
    m2->runningTime = 120;
    m2->yearRelease = 2011;
    m2->productionCost = 43657.43f;
    m2->firstYearRevenues = 13569.2f;

    displayMovie(m1);
    displayMovie(m2);
    return 0;
}

void displayMovie(MovieData *m) {
    cout << "Movie name: " << m->title << endl;
    cout << "Director of movie: " << m->director << endl;
    cout << "Time: " << m->runningTime << endl;
    cout << "Year release: " << m->yearRelease << endl;
    cout << "First year's revenues: " << (((m->firstYearRevenues - m->productionCost) > 0) ? "profit" : "loss") << endl;
    cout << "---------------------------------" << endl;
}


