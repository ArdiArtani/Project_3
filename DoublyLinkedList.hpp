//
//  DoublyLinkedList.hpp
//  Project_3
//
//  Created by Ardi Artani on 10/25/20.
//

#ifndef DoublyLinkedList_hpp
#define DoublyLinkedList_hpp

#include "DoubleNode.hpp"
#include <iostream>

template<class ItemType>
class DoublyLinkedList
{
public:
    // Default, Parameterized Constructor, and Destructor
    DoublyLinkedList();
    DoublyLinkedList(const DoublyLinkedList<ItemType> &a_list);
    ~DoublyLinkedList();

    //inserts item at position in caller list
    bool insert(const ItemType &item, const int &position);
       
    //removes the node at position
    bool remove(const int &position);
       
    // returns the number of the nodes in the calling list
    int getSize() const;
       
    // returns a copy of the headPtr
    DoubleNode<ItemType> *getHeadPtr() const;
       
    // returns a pointer to the node located at pos
    DoubleNode<ItemType> *getAtPos(const int &pos) const;
       
    // returns whether the calling list is empty
    bool isEmpty() const;
       
    // clears the list
    void clear();
    
    // returns the position of the given item in the list, -1 otherwise
    int getIndexOf(const ItemType &item) const;
       
    // prints the contents of the calling list in order
    void display() const;
       
    // prints the contents of the calling list in reverse order
    void displayBackwards() const;
       
    // returns the interleaved list of the calling and parameter lists
    DoublyLinkedList<ItemType> interleave(const DoublyLinkedList<ItemType> &a_list);
    
protected:
    // a head pointer to a DoubleNode of any arbitrary type ItemType
    DoubleNode<ItemType>* head;
    // a member that keeps track of the size of the list
    int size;
};

#include "DoublyLinkedList.cpp"
#endif /* DoublyLinkedList_hpp */



