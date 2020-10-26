//
//  DoubleNode.cpp
//  Project_3
//
//  Created by Ardi Artani on 10/25/20.
//

#include "DoubleNode.hpp"

/*
    *********************
    Default and Parameterized constructor:
    *********************
*/
template<class ItemType>
DoubleNode<ItemType>::DoubleNode():next_(nullptr), prev_(nullptr) {}

template<class ItemType>
DoubleNode<ItemType>::DoubleNode(const ItemType &anItem):item_(anItem), next_(nullptr), prev_(nullptr) {}

template<class ItemType>
DoubleNode<ItemType>::DoubleNode(const ItemType &anItem, DoubleNode<ItemType> *nextNodePtr, DoubleNode<ItemType> *previousNodePtr):item_(anItem), next_(nextNodePtr), prev_(previousNodePtr) {}


/*
    *********************
    SETTER FUNCTIONS
    *********************
*/

// setItem
template<class ItemType>
void DoubleNode<ItemType>::setItem(const ItemType &anItem)
{
    item_ = anItem;
}

// setPrevious
template<class ItemType>
void DoubleNode<ItemType>::setPrevious(DoubleNode<ItemType> *previousNodePtr)
{
    prev_ = previousNodePtr;
}

// setNext
template<class ItemType>
void DoubleNode<ItemType>::setNext(DoubleNode<ItemType> *nextNodePtr)
{
    next_ = nextNodePtr;
}


/*
    *********************
    GETTER FUNCTIONS
    *********************
*/

// getItem
template<class ItemType>
ItemType DoubleNode<ItemType>::getItem() const
{
    return item_;
}

// getNext
template<class ItemType>
DoubleNode<ItemType>* DoubleNode<ItemType>::getNext() const
{
    return next_;
}

// getPrevious
template<class ItemType>
DoubleNode<ItemType>* DoubleNode<ItemType>::getPrevious() const
{
    return prev_;
}

