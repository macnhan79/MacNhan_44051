/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Fruit.h
 * Author: admin
 *
 * Created on May 29, 2017, 9:19 PM
 */

#ifndef FRUIT_H
#define FRUIT_H
#include "Object.h"
#include <cstdlib>

class Fruit : public Object {
public:
     /*!
     * \brief Constructor of Fruit class
     * \param none
     * \return none
     */
    Fruit();
    /*!
     * \brief reLocation function is a function generation coordinates x,y
     * \param none
     * \return none
     */
    void reLocation();
};

#endif /* FRUIT_H */

