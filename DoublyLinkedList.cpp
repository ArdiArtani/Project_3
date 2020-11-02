//
//  DoublyLinkedList.cpp
//  Project_3
//
//  Created by Ardi Artani on 10/25/20.
//

#include "DoublyLinkedList.hpp"

/*
    ***************************
    Default, Parameterized Constructor, and Destructor
    ***************************
*/


/*
    Default Constructor
*/
template<class ItemType>
DoublyLinkedList<ItemType>::DoublyLinkedList()
{
    head = nullptr;
    size = 0;
} //end DoublyLinkedList();


/*
    Parameterized Constructor
*/
template<class ItemType>
DoublyLinkedList<ItemType>::DoublyLinkedList(const DoublyLinkedList<ItemType> &a_list)
{
    // Let DoublyLinkedList be 1 indexed unlike arrays, which are 0 indexed
    // create for loop to loop over list
    DoubleNode<ItemType> *temp_list_ptr_ = a_list.head;
    for (int i = 1; i <= a_list.size; i++) {
        // copy each node
        // getItem data
        ItemType item = temp_list_ptr_->getItem();
        // insert
        this->insert(i, item);
        temp_list_ptr_ = temp_list_ptr_->getNext();
    }
} //end DoublyLinkedList();


/*
    Destructor
*/
template<class ItemType>
DoublyLinkedList<ItemType>::~DoublyLinkedList()
{
   clear(); // delete all nodes by calling clear()
} // end ~DoublyLinkedList()


/*
    inserts item at position in caller list
*/
template<class ItemType>
bool DoublyLinkedList<ItemType>::insert(const ItemType &item, const int &position)
{
    
    
    
    
    return true;
    
    
    
    
    
} //end insert



/*
    removes the node at position
*/
template<class ItemType>
bool DoublyLinkedList<ItemType>::remove(const int &position)
{
    
    
    
    
    return true;
    
    
    
    
}



/*
    returns the number of the nodes in the calling list
*/
template<class ItemType>
int DoublyLinkedList<ItemType>::getSize() const
{
    // returns protected member size
    return size;
}


/*
    returns a pointer to the node located at pos
*/
template<class ItemType>
DoubleNode<ItemType>* DoublyLinkedList<ItemType>::getAtPos(const int &pos) const
{
   // validate the position of pos
   if (pos < 1 || pos > size) {
       return nullptr;
   }
   else {
       // create a DoubleNode temp iterator
       DoubleNode<ItemType>* temp_item_ptr_ = head;
       // for loop i to pos
       for (int i = 1; i < pos; i++) {
           temp_item_ptr_ = temp_item_ptr_->getNext();
       }
       return temp_item_ptr_;
   }
}


/*
 returns whether the calling list is empty
*/
template<class ItemType>
bool DoublyLinkedList<ItemType>::isEmpty() const
{
    // check if protected member size is equal to 0
    return size == 0;
} // end isEmpty()
 

/*
    clears the list
*/
template<class ItemType>
void DoublyLinkedList<ItemType>::clear()
{
    // set protected size memeber to 0
    size = 0;
    DoubleNode<ItemType> *temp_node_ = head;
    // while untill head is not nullptr
    while (head != nullptr) {
        head = head->getNext();
        delete temp_node_;
        temp_node_ = head;
    }
    delete temp_node_;
} // end clear()


/*
    returns the position of the given item in the list, -1 otherwise
*/
template<class ItemType>
int DoublyLinkedList<ItemType>::getIndexOf(const ItemType &item) const
{
    
    
    
    
    return -1;
    
    
    
    
    
}


/*
    prints the contents of the calling list in order
*/
template<class ItemType>
void DoublyLinkedList<ItemType>::display() const {
    // open bracket
    std::cout << "[";
    // for loop each node and print its item
    DoubleNode<ItemType>* temp_list_ptr_ = head;
    for (int i = 0; i < size; i++) {
        std::cout << temp_list_ptr_->getItem();
        // print comma after each node aside from the last one
        if (i < size - 1) {
           std::cout << ", ";
        }
        // move to next node using getNext()
        temp_list_ptr_ = temp_list_ptr_->getNext();
    }
    // close bracket
    std::cout << "]" << std::endl;
}


/*
    prints the contents of the calling list in reverse order
*/
template<class ItemType>
void DoublyLinkedList<ItemType>::displayBackwards() const {
    // for lopp to move to end of the list
    DoubleNode<ItemType>* temp_list_ptr_ = head;
    for (int i = 1; i < size; i++) {
        temp_list_ptr_ = temp_list_ptr_->getNext();
    }
    
    // open bracket
    std::cout << "[";
    // for loop each node in reverse order and print its item
    for (int i = 0; i < size; i++) {
        std::cout << temp_list_ptr_->getItem();
        // print comma after each node aside from the last one
        if (i < size - 1) {
            std::cout << ", ";
        }
        // move to previous node using getPrev()
        temp_list_ptr_ = temp_list_ptr_->getPrevious();
    }
    // close bracket
    std::cout << "]" << std::endl;
}


/*
    returns the interleaved list of the calling and parameter lists
*/
template<class ItemType>
DoublyLinkedList<ItemType> DoublyLinkedList<ItemType>::interleave(const DoublyLinkedList<ItemType> &a_list)
{
    
    
    
    
    return 0;
    
    
    
    
}

