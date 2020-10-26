//
//  DoubleNode.hpp
//  Project_3
//
//  Created by Ardi Artani on 10/25/20.
//

#ifndef DoubleNode_hpp
#define DoubleNode_hpp

template<class ItemType>
class DoubleNode
{
public:
    
    // Default and Parameterized constructor:
    DoubleNode();
    DoubleNode(const ItemType &anItem);
    DoubleNode(const ItemType &anItem, DoubleNode <ItemType> *nextNodePtr, DoubleNode <ItemType> *previousNodePtr);
    
    // Setter Functions
    void setItem(const ItemType &anItem);
    void setPrevious(DoubleNode<ItemType> *previousNodePtr);
    void setNext(DoubleNode<ItemType> *nextNodePtr);

    // Getter Functions
    ItemType getItem() const;
    DoubleNode<ItemType> *getNext() const;
    DoubleNode<ItemType> *getPrevious() const;
private:
    ItemType item_;
    DoubleNode<ItemType> *next_;
    DoubleNode<ItemType> *prev_;
};

#include "DoubleNode.cpp"
#endif /* DoubleNode_hpp */
