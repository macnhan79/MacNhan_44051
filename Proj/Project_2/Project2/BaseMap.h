/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BaseMap.h
 * Author: admin
 *
 * Created on May 29, 2017, 1:15 PM
 */

#ifndef BASEMAP_H
#define BASEMAP_H
#include <iostream>
#include "Walls.h"
#include "Snake.h"

class BaseMap {
public:
    /*!
     * \brief Constructor of BaseMap class
     * \param none
     * \return none
     */
    BaseMap();
    Object map[30][60]; /*!< Node of map */
};

#endif /* BASEMAP_H */

