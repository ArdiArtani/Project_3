//
//  DoublyLinkedList.cpp
//  Project_3
//
//  Created by Ardi Artani on 10/25/20.
//

#include "DoublyLinkedList.hpp"

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
    // first valid position return false
    if (position < 1 || position > (size + 1)) {
        return false;
    }
    else {
        //Create a new node containing the new entry
        DoubleNode<ItemType>* new_node_ = new DoubleNode<ItemType>(item);
        
        // if index is equal to 1 add node head position
        if (position == 1) {
            // check if head list has any nodes
            if (head == nullptr) {
                head = new_node_;
            }
            else {
                // assign head to new_node_ setNext
                new_node_->setNext(head);
                head->setPrevious(new_node_);
                // reset head
                head = new_node_;
            }
        }
        else {
            // create for loop to loop till given position in the list
            DoubleNode<ItemType>* temp_node_ptr_ = head;
            for (int i = 2; i < position; i++) {
                temp_node_ptr_ = temp_node_ptr_->getNext();
            }
            
            // assign node and if new node is not the last node assign node to left side
            if (temp_node_ptr_->getNext() != nullptr) {
                temp_node_ptr_->getNext()->setPrevious(new_node_);
                new_node_->setNext(temp_node_ptr_->getNext());
            }
            
            temp_node_ptr_->setNext(new_node_);
            new_node_->setPrevious(temp_node_ptr_);
        }

        // imcreament size and return true
        size++;
        return true;
    }
} //end insert


/*
    removes the node at position
*/
template<class ItemType>
bool DoublyLinkedList<ItemType>::remove(const int &position)
{
    // first valid position return false
    if (position < 1 || position > size) {
       return false;
    }
    else {
       // create a temp node pointer
       DoubleNode<ItemType>* temp_ptr_;
        
       // check if head node is equal to 1
       if (position == 1) {
           temp_ptr_ = head;
           head = head->getNext(); // call getNext()
           if (head != nullptr) {
               // otherwise call setPrevious()
               head->setPrevious(nullptr);
           }
           delete temp_ptr_;
       }
       else {
           // create for loop to loop till given position in the list
           DoubleNode<ItemType>* temp_node_ptr_ = head;
           for (int i = 2; i < position; i++) {
               // assign next node to temp_ptr_
               temp_ptr_ = temp_node_ptr_->getNext();
               
               // remove node links from right side only if node at right exist
               if (temp_node_ptr_->getNext()->getNext() != nullptr) {
                   temp_node_ptr_->getNext()->getNext()->setPrevious(temp_node_ptr_);
                   temp_node_ptr_->setNext(temp_node_ptr_->getNext()->getNext());
               }
               else {
                   temp_node_ptr_->setNext(nullptr);
               }
               delete temp_ptr_;
           }
       }
       // decrement size
       size--;
       return true;
    }
} // end remove


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
    returns a copy of the headPtr
*/
template<class ItemType>
DoubleNode<ItemType>* DoublyLinkedList<ItemType>::getHeadPtr() const
{
    // returns protected member head
    return head;
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
    
    
    
    
    
} // end getIndexOf


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
} // end display


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
        // move to previous node using getPrevious()
        temp_list_ptr_ = temp_list_ptr_->getPrevious();
    }
    // close bracket
    std::cout << "]" << std::endl;
} // end displayBackwards


/*
    returns the interleaved list of the calling and parameter lists
*/
template<class ItemType>
DoublyLinkedList<ItemType> DoublyLinkedList<ItemType>::interleave(const DoublyLinkedList<ItemType> &a_list)
{
    // create a new list to return
    DoublyLinkedList<ItemType>* interleave_output_ = new DoublyLinkedList();
    
    // set index to 1
    int index = 1;
    
    // assign both lists new nodes
    DoubleNode<ItemType>* temp_list1_ = this->head;
    DoubleNode<ItemType>* temp_list2_ = a_list.head;
    
    // loop till lists have node left to add
    while (!(temp_list1_ == nullptr && temp_list2_ == nullptr)) {
        
        // if first list is not null add node
        if (temp_list1_ != nullptr) {
            interleave_output_->insert(index, temp_list1_->getItem());
            temp_list1_ = temp_list1_->getNext();
            index++;
        }
        
        // if second list is not null add node
        if (temp_list2_ != nullptr) {
            interleave_output_->insert(index, temp_list2_->getItem());
            temp_list2_ = temp_list2_->getNext();
            index++;
        }
    }
    
    return *interleave_output_;
} // end interleave
