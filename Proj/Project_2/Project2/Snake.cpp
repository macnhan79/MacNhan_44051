/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Snake.h"

Snake::Snake() {
    init();
}

void Snake::init() {
    if (head != nullptr) {
        delete head;
        delete tail;
    }
    ListNode *new_head = new ListNode('+');
    head = new_head;
    head->setX(7);
    head->setY(15);

    ListNode *new_tail = new ListNode();
    tail = new_tail;
    tail->setPreviousNode(head);
    head->setNextNode(tail);
    tail->setX(6);
    tail->setY(15);
    state = RIGHT;
}

void Snake::move() {
    if (speed == maxSpeed) {
        ListNode *current = head;
        int x = current->getX();
        int y = current->getY();
        switch (state) {
            case DOWN:

                current->setY(y + 1);
                current = current->getNextNode();
                while (current != nullptr) {
                    //get current node x,y
                    int tempX = current->getX();
                    int tempY = current->getY();
                    //set current node [x,y] = prev node
                    current->setX(x);
                    current->setY(y);
                    x = tempX;
                    y = tempY;
                    current = current->getNextNode();
                }
                break;
            case UP:

                current->setY(y - 1);
                current = current->getNextNode();
                while (current != nullptr) {
                    //get current node x,y
                    int tempX = current->getX();
                    int tempY = current->getY();
                    //set current node [x,y] = prev node
                    current->setX(x);
                    current->setY(y);
                    x = tempX;
                    y = tempY;
                    current = current->getNextNode();
                }
                break;
            case LEFT:

                current->setX(x - 1);
                current = current->getNextNode();
                while (current != nullptr) {
                    //get current node x,y
                    int tempX = current->getX();
                    int tempY = current->getY();
                    //set current node [x,y] = prev node
                    current->setX(x);
                    current->setY(y);
                    x = tempX;
                    y = tempY;
                    current = current->getNextNode();
                }
                break;
            case RIGHT:

                current->setX(x + 1);
                current = current->getNextNode();
                while (current != nullptr) {
                    //get current node x,y
                    int tempX = current->getX();
                    int tempY = current->getY();
                    //set current node [x,y] = prev node
                    current->setX(x);
                    current->setY(y);
                    x = tempX;
                    y = tempY;
                    current = current->getNextNode();
                }
                break;
        }
        speed = 0;
    } else {
        speed += 5;
    }
}

int Snake::size() {
    return itemCount;
}

void Snake::insertBack() // insert node to back of snake
{
    ListNode *new_node;
    //cout << "New node created with value of " << new_node->getValue() << endl;
    if (tail == nullptr) {
        new_node = new ListNode('+');
        tail = new_node;
        head = tail;
    } else {
        new_node = new ListNode();
        tail->setNextNode(new_node);
        new_node->setPreviousNode(tail);
        tail = new_node;
    }
    itemCount++;
}

void Snake::deleteBack() // delete node at back of snake
{
    if (head == tail) {
        if (itemCount == 1) {
            delete head;
            itemCount--;
        }
    } else {
        ListNode *temp = tail;
        tail = tail->getPreviousNode();
        temp->setPreviousNode(nullptr);
        tail->setNextNode(nullptr);
        delete temp;
        itemCount--;
    }
}

void Snake::displayList() const {
    //    ListNode *current = head;
    //
    //    if (current == nullptr) {
    //        cout << "Double Linked List is empty, nothing to output.";
    //    } else
    //        while (current != nullptr) {
    //            cout << current->getSymbol() << " ";
    //            current = current->getNextNode();
    //        }
    //
    //    cout << endl;
}

ListNode* Snake::getHead() const {
    return head;
}

void Snake::setMaxSpeed(int maxSpeed) {
    this->maxSpeed = maxSpeed;
}

int Snake::getMaxSpeed() const {
    return maxSpeed;
}