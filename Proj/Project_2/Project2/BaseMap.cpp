/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "BaseMap.h"
#include <typeinfo>
BaseMap::BaseMap() {
    //init map
    for (int i = 0; i < 30; i++) {
        for (int j = 0; j < 60; j++) {
            if (i == 0 || i == 29) {
                Walls wall;
                wall.setX(j);
                wall.setY(i);
                map[i][j] = wall;
            } else {
                Walls wall;
                wall.setX(j);
                wall.setY(i);
                map[i][0] = wall;
                map[i][59] = wall;
            }
            map[i][j].setX(j);
            map[i][j].setY(i);
        }
    }
}






