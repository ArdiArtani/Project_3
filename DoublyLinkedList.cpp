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
    head_ptr_ = nullptr;
    size_ = 0;
} //end DoublyLinkedList();


/*
    Parameterized Constructor
*/
template<class ItemType>
DoublyLinkedList<ItemType>::DoublyLinkedList(const DoublyLinkedList<ItemType> &a_list)
{
    // set default parameters
    head_ptr_ = nullptr;
    size_ = 0;
    
    // points to the headpointer of the a_list
    DoubleNode<ItemType>* temp_list_ptr_ = a_list.head_ptr_;

    // inserts items from a_list to the new one
    for (int i = 1; i <= a_list.getSize(); i++)
    {
        this->insert(temp_list_ptr_->getItem(), i);
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
    if (position < 1 || position > size_ + 1) {
        return false;
    }
    else {
        //Create a new node containing the new entry
        DoubleNode<ItemType>* new_node_ = new DoubleNode<ItemType>(item);
        
        // if index is equal to 1 add node head position
        if (position == 1) {
            // check if head list has any nodes
            if (head_ptr_ == nullptr) {
                head_ptr_ = new_node_;
            }
            else {
                // assign head to new_node_ setNext
                new_node_->setNext(head_ptr_);
                head_ptr_->setPrevious(new_node_);
                // reset head
                head_ptr_ = new_node_;
            }
        }
        else {
            // create for loop to loop till given position in the list
            DoubleNode<ItemType>* temp_node_ptr_ = head_ptr_;
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
        size_++;
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
    if (position < 1 || position > size_) {
       return false;
    }
    
    // create a temp node pointer
    DoubleNode<ItemType>* temp_ptr_;
    
    // check if head node is equal to 1
    if (position == 1) {
        temp_ptr_ = head_ptr_;
        head_ptr_ = head_ptr_->getNext(); // call getNext()
        if (head_ptr_ != nullptr) {
            // otherwise call setPrevious()
            head_ptr_->setPrevious(nullptr);
        }
        delete temp_ptr_;
    }
    else {
        // create for loop to loop till given position in the list
        DoubleNode<ItemType>* temp_node_ptr_ = head_ptr_;
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
    size_--;
    return true;
    
} // end remove


/*
    returns the number of the nodes in the calling list
*/
template<class ItemType>
int DoublyLinkedList<ItemType>::getSize() const
{
    // returns protected member size
    return size_;
}


/*
    returns a copy of the headPtr
*/
template<class ItemType>
DoubleNode<ItemType>* DoublyLinkedList<ItemType>::getHeadPtr() const
{
    // returns protected member head_ptr_
    return head_ptr_;
}


/*
    returns a pointer to the node located at pos
*/
template<class ItemType>
DoubleNode<ItemType>* DoublyLinkedList<ItemType>::getAtPos(const int &pos) const
{
    // check if position exists
    if (pos > size_ || pos < 1 ) {
        return nullptr;
    }
    else {
        // finds the node the position and returns it
        DoubleNode<ItemType>* temp_node_ptr_ = head_ptr_;
        for (int i = 1; i < pos; i++)
        {
            temp_node_ptr_ = temp_node_ptr_->getNext();
        }
        return temp_node_ptr_;
    }
}


/*
 returns whether the calling list is empty
*/
template<class ItemType>
bool DoublyLinkedList<ItemType>::isEmpty() const
{
    // check if protected member size is equal to 0
    return size_ == 0;
} // end isEmpty()
 

/*
    clears the list
*/
template<class ItemType>
void DoublyLinkedList<ItemType>::clear()
{
    // set protected size memeber to 0
    size_ = 0;
    DoubleNode<ItemType> *del_node_ = head_ptr_;
    // while untill head is not nullptr
    while (head_ptr_ != nullptr) {
        head_ptr_ = head_ptr_->getNext();
        delete del_node_;
        del_node_ = head_ptr_;
    }
    delete del_node_;
} // end clear()


/*
    returns the position of the given item in the list, -1 otherwise
*/
template<class ItemType>
int DoublyLinkedList<ItemType>::getIndexOf(const ItemType &item) const
{
    bool found = false;
    int result = -1;
    int searchIndex = 0;
    
    DoubleNode<ItemType>* temp_head_ptr_ = head_ptr_;
    while (!found && (searchIndex < this->getSize()))
    {
       if (temp_head_ptr_[searchIndex] == item)
       {
          found = true;
          result = searchIndex;
       }
       else
       {
          searchIndex++;
       }
    }
    return result;
} // end getIndexOf


/*
    prints the contents of the calling list in order
*/
template<class ItemType>
void DoublyLinkedList<ItemType>::display() const {
    // for loop each node and print its item
    DoubleNode<ItemType>* temp_list_ptr_ = head_ptr_;
    for (int i = 0; i < size_; i++) {
        std::cout << temp_list_ptr_->getItem();
        // print comma after each node aside from the last one
        if (i < size_ - 1) {
           std::cout << " ";
        }
        // move to next node using getNext()
        temp_list_ptr_ = temp_list_ptr_->getNext();
    }
    std::cout << std::endl;
} // end display


/*
    prints the contents of the calling list in reverse order
*/
template<class ItemType>
void DoublyLinkedList<ItemType>::displayBackwards() const {
    // for lopp to move to end of the list
    DoubleNode<ItemType>* temp_list_ptr_ = head_ptr_;
    for (int i = 1; i < size_; i++) {
        temp_list_ptr_ = temp_list_ptr_->getNext();
    }
    
    // for loop each node in reverse order and print its item
    for (int i = 0; i < size_; i++) {
        std::cout << temp_list_ptr_->getItem();
        // print comma after each node aside from the last one
        if (i < size_ - 1) {
            std::cout << " ";
        }
        // move to previous node using getPrevious()
        temp_list_ptr_ = temp_list_ptr_->getPrevious();
    }
    std::cout << std::endl;
} // end displayBackwards


/*
    returns the interleaved list of the calling and parameter lists
*/
template<class ItemType>
DoublyLinkedList<ItemType> DoublyLinkedList<ItemType>::interleave(const DoublyLinkedList<ItemType> &a_list)
{
    // create a new list to return
    DoublyLinkedList<ItemType>* interleavelist_ = new DoublyLinkedList();
    
    // set index to 1
    int index = 1;
    
    // points to the head_ptr_ of the first list
    DoubleNode<ItemType>* first_list_ = this->head_ptr_;
    // points to the head_ptr_ of the second list
    DoubleNode<ItemType>* second_list_ = a_list.head_ptr_;
    
    while (first_list_ != nullptr && second_list_ != nullptr) {
        // if first list is not done adding add node
        interleavelist_->insert(first_list_->getItem(), index);
        first_list_ = first_list_->getNext();

        // if second list is not done adding add node
        interleavelist_->insert(second_list_->getItem(), index);
        second_list_ = second_list_->getNext();
        
        index++;
    }

    // if there are still items in list 1
    if (first_list_ != nullptr && second_list_ == nullptr){
        // while first_list_ does not equal nullptr
        while(first_list_ != nullptr){
            // inseert item into interleavelist_
            interleavelist_->insert(first_list_->getItem(), index);
            // getNext()
            first_list_ = first_list_->getNext();
            index++;
        }
    }
    
    // if there are still items in list 2
    if (first_list_ == nullptr && second_list_ != nullptr) {
        // while second_list_ does not equal nullptr
        while(second_list_ != nullptr){
            // inseert item into interleavelist_
            interleavelist_->insert(second_list_->getItem(), index);
            // getNext()
            second_list_ = second_list_->getNext();
            index++;
        }
    }

    return *interleavelist_;
} // end interleave







