// A class template for holding a double linked list.
// The node type is also a class template.
#ifndef DLINKEDLIST_H
#define DLINKEDLIST_H
#include <iostream>
using namespace std;

/**********************************************
 *  The DListNode class creates a type used to *
 *  store a node of the double linked list.    *
 **********************************************/

template <class T>
class DListNode {
private:
    T value; // Node value
    DListNode<T> *next; // Pointer to the next node
    DListNode<T> *prev; // Pointer to the previous node

public:
    // Constructor

    DListNode(T nodeValue) {
        value = nodeValue;
        next = nullptr;
        prev = nullptr;
    }

    DListNode<T> *getNextNode() {
        return next;
    }

    DListNode<T> *getPreviousNode() {
        return prev;
    }

    T getValue() {
        return value;
    }

    void setNextNode(DListNode<T> *newNode) {
        next = newNode;
    }

    void setPreviousNode(DListNode<T> *newNode) {
        prev = newNode;
    }

    void setValue(T newValue) {
        value = newValue;
    }
};

/*******************
 * LinkedList class *
 *******************/

template <class T>
class DLinkedList {
private:
    DListNode<T> *head; // List head pointer
    DListNode<T> *tail; // List tail pointer
    int itemCount; // counter for number of items in dlinkedlist

public:
    // Constructor

    DLinkedList() {
        head = nullptr;
        tail = nullptr;
        itemCount = 0;
    }

    // Destructor
    ~DLinkedList();

    // Linked list operations
    int size(); // return the size (or itemCount) of our dlinkedlist

    void insertFront(T); // insert node to front of dlinkedlist
    void insertAt(T, int); // insert node at the specified index
    void insertBack(T); // insert node to back of dlinkedlist
    void deleteFront(); // delete node at front of dlinkedlist 
    void deleteAt(int); // delete node at the specified index
    void deleteBack(); // delete node at back of dlinkedlist
    void displayList() const;

};

/**************
 * displayList *
 **************/

template <class T>
void DLinkedList<T>::displayList() const {
    DListNode<T> *current = head;

    if (current == nullptr) {
        cout << "Double Linked List is empty, nothing to output.";
    } else
        while (current != nullptr) {
            cout << current->getValue() << " ";
            current = current->getNextNode();
        }

    cout << endl;
}

template <class T>
int DLinkedList<T>::size() {
    return itemCount;
}

template <class T>
void DLinkedList<T>::insertFront(T newValue) {
    DListNode<T> *new_node = new DListNode<T>(newValue);
    //cout << "New node created with value of " << new_node->getValue() << endl;
    if (head == nullptr) {
        head = new_node;
        tail = head;
    } else {
        head->setPreviousNode(new_node);
        new_node->setNextNode(head);
        //tail = head;
        head = new_node;
    }
    itemCount++;
}

template <class T>
void DLinkedList<T>::insertAt(T newValue, int position) // insert node at the specified index
{
    // create new node
    // current = head
    // for i = 0; i<position; i++
    //		current = current->next
    // newnode->next = current
    // newnode->previous = current->previous
    // current->previous->next = newnode
    // current->previous = newnode
    // increment item count by 1
}

template <class T>
void DLinkedList<T>::insertBack(T newValue) // insert node to back of dlinkedlist
{
    DListNode<T> *new_node = new DListNode<T>(newValue);
    //cout << "New node created with value of " << new_node->getValue() << endl;
    if (tail == nullptr) {
        tail = new_node;
        head = tail;
    } else {
        tail->setNextNode(new_node);
        new_node->setPreviousNode(tail);
        tail = new_node;
    }
    itemCount++;
}

template <class T>
void DLinkedList<T>::deleteFront() // delete node at front of dlinkedlist 
{
    if (head == tail) {
        if (itemCount == 1) {
            delete head;
            itemCount--;
        }
    } else {
        DListNode<T> *temp = head;
        head = head->getNextNode();
        temp->setNextNode(nullptr);
        head->setPreviousNode(nullptr);
        delete temp;
        itemCount--;
    }
}

template <class T>
void DLinkedList<T>::deleteAt(int position) // delete node at the specified index
{
    // current = head
    // for i = 0; i<position; i++
    //		current = current->next
    // current->next = current->previous
    // current->previous->next = current->next
    // current->next->previous = current->previous
    // decrement item count by 1
}

template <class T>
void DLinkedList<T>::deleteBack() // delete node at back of dlinkedlist
{
    if (head == tail) {
        if (itemCount == 1) {
            delete head;
            itemCount--;
        }
    } else {
        DListNode<T> *temp = tail;
        tail = tail->getPreviousNode();
        temp->setPreviousNode(nullptr);
        tail->setNextNode(nullptr);
        delete temp;
        itemCount--;
    }
}

template <class T>
DLinkedList<T>::~DLinkedList() {
    DListNode<T> *nodePtr; // To traverse the list
    DListNode<T> *nextNode; // To point to the next node

    // Position nodePtr at the head of the list.
    nodePtr = head;

    // While nodePtr is not at the end of the list...
    while (nodePtr != nullptr) {
        // Save a pointer to the next node.
        nextNode = nodePtr->getNextNode();

        // Delete the current node.
        delete nodePtr;

        // Position nodePtr at the next node.
        nodePtr = nextNode;
    }
}
#endif