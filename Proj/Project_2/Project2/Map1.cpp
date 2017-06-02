/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "Map1.h"
#include "BaseMap.h"
#include "Walls.h"

Map1::Map1() {
    BaseMap();
    //
    for (int i = 0; i < 5; i++) {
        Walls wall;
        wall.setX(10);
        wall.setY(i+5);
        map[wall.getY()][wall.getX()] = wall;
        
        Walls wall1;
        wall1.setX(11);
        wall1.setY(i+5);
        map[wall1.getY()][wall1.getX()] = wall1;
        
        Walls wall2;
        wall2.setX(12);
        wall2.setY(i+5);
        map[wall2.getY()][wall2.getX()] = wall2;
        
        Walls wall3;
        wall3.setX(13);
        wall3.setY(i+5);
        map[wall3.getY()][wall3.getX()] = wall3;
        
        Walls wall4;
        wall4.setX(14);
        wall4.setY(i+5);
        map[wall4.getY()][wall4.getX()] = wall4;
        
        //--------------------------------------------------------
        Walls wall5;
        wall5.setX(45);
        wall5.setY(i+5);
        map[wall5.getY()][wall5.getX()] = wall5;
        
        Walls wall6;
        wall6.setX(46);
        wall6.setY(i+5);
        map[wall6.getY()][wall6.getX()] = wall6;
        
        Walls wall7;
        wall7.setX(47);
        wall7.setY(i+5);
        map[wall7.getY()][wall7.getX()] = wall7;
        
        Walls wall8;
        wall8.setX(48);
        wall8.setY(i+5);
        map[wall8.getY()][wall8.getX()] = wall8;
        
        Walls wall9;
        wall9.setX(49);
        wall9.setY(i+5);
        map[wall9.getY()][wall9.getX()] = wall9;
        
        //--------------------------------------------------------
        Walls wall10;
        wall10.setX(10);
        wall10.setY(i+20);
        map[wall10.getY()][wall10.getX()] = wall10;
        
        Walls wall11;
        wall11.setX(11);
        wall11.setY(i+20);
        map[wall11.getY()][wall11.getX()] = wall11;
        
        Walls wall12;
        wall12.setX(12);
        wall12.setY(i+20);
        map[wall12.getY()][wall12.getX()] = wall12;
        
        Walls wall13;
        wall13.setX(13);
        wall13.setY(i+20);
        map[wall13.getY()][wall13.getX()] = wall13;
        
        Walls wall14;
        wall14.setX(14);
        wall14.setY(i+20);
        map[wall14.getY()][wall14.getX()] = wall14;
        
        //--------------------------------------------------------
        Walls wall15;
        wall15.setX(45);
        wall15.setY(i+20);
        map[wall15.getY()][wall15.getX()] = wall15;
        
        Walls wall16;
        wall16.setX(46);
        wall16.setY(i+20);
        map[wall16.getY()][wall16.getX()] = wall16;
        
        Walls wall17;
        wall17.setX(47);
        wall17.setY(i+20);
        map[wall17.getY()][wall17.getX()] = wall17;
        
        Walls wall18;
        wall18.setX(48);
        wall18.setY(i+20);
        map[wall18.getY()][wall18.getX()] = wall18;
        
        Walls wall19;
        wall19.setX(49);
        wall19.setY(i+20);
        map[wall19.getY()][wall19.getX()] = wall19;
    }

    
}
