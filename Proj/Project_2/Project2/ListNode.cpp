/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "ListNode.h"

// Constructor

ListNode::ListNode() {
    this->setSymbol('0');
    this->setPoints(1);
    next = nullptr;
    prev = nullptr;
}

ListNode::ListNode(bool isHead) {
    this->setSymbol('+');
    this->setPoints(1);
    next = nullptr;
    prev = nullptr;
}

ListNode* ListNode::getNextNode() {
    return next;
}

ListNode* ListNode::getPreviousNode() {
    return prev;
}

void ListNode::setNextNode(ListNode *newNode) {
    next = newNode;
}

void ListNode::setPreviousNode(ListNode *newNode) {
    prev = newNode;
}

