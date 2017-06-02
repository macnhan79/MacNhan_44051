/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Snake.h
 * Author: admin
 *
 * Created on May 29, 2017, 1:28 PM
 */

#ifndef SNAKE_H
#define SNAKE_H
#include "Object.h"
#include "ListNode.h"

class Snake {
private:
    ListNode *head; /*!< List head pointer */ // 
    ListNode *tail; /*!< List tail pointer */ // 
    int itemCount; /*!< counter for number of items in lit */ // 
    int speed = 0; /*!< speed of snake */
    int maxSpeed = 30; /*!< max speed of snake */

public:

    enum moveState {
        UP, DOWN, LEFT, RIGHT
    }; /*!< Enum Direction of snake */
    moveState state; /*!< Direction of snake */
    /*!
     * \brief Constructor of Snake class
     * \param none
     * \return none
     */
    Snake();
    /*!
     * \brief Create value for snake
     * \param none
     * \return none
     */
    void init();
    /*!
     * \brief Move snake to other position
     * \param none
     * \return none
     */
    void move();
    /*!
     * \brief The size of snake
     * \param none
     * \return the size of snake
     */
    int size();
    /*!
     * \brief Insert node to back of list
     * \param none
     * \return none
     */
    void insertBack(); // 
    /*!
     * \brief Delete node at back of list
     * \param none
     * \return none
     */
    void deleteBack();
    void displayList() const;
    /*!
     * \brief Get list head pointer
     * \param none
     * \return List head pointer
     */
    ListNode* getHead() const;
    /*!
     * \brief Set value of max speed
     * \param maxSpeed - value of max speed
     * \return none
     */
    void setMaxSpeed(int maxSpeed);
    /*!
     * \brief Get max speed
     * \param none
     * \return maxSpeed
     */
    int getMaxSpeed() const;
};

#endif /* SNAKE_H */

