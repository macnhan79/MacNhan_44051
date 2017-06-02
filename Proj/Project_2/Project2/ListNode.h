/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListNode.h
 * Author: admin
 *
 * Created on May 29, 2017, 2:04 PM
 */

#ifndef LISTNODE_H
#define LISTNODE_H
#include "Object.h"

class ListNode : public Object {
private:
    ListNode *next; /*!< Pointer to the next node */ // 
    ListNode *prev; /*!< Pointer to the previous node */// 

public:
    /*!
     * \brief Constructor of ListNode class
     * \param none
     * \return none
     */
    ListNode();
    /*!
     * \brief Constructor of ListNode class
     * \param isHead - A flag notice this node is the head
     * \return none
     */
    ListNode(bool);
    /*!
     * \brief Get the next node
     * \param none
     * \return none
     */
    ListNode *getNextNode();
    /*!
     * \brief Get the previous node
     * \param none
     * \return none
     */
    ListNode *getPreviousNode();
    /*!
     * \brief set the value of next node
     * \param newNode - The value of next node
     * \return none
     */
    void setNextNode(ListNode *);
    /*!
     * \brief set the value of previous node
     * \param newNode - The value of previous node
     * \return none
     */
    void setPreviousNode(ListNode *);

};

#endif /* LISTNODE_H */

