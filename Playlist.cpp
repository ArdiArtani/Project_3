//
//  Playlist.cpp
//  Project_3
//
//  Created by Ardi Artani on 10/25/20.
//

#include "Playlist.hpp"

/*
    Default Constructor
    Goal: Calls its parent constructor
*/
Playlist::Playlist() : DoublyLinkedList()
{
}


/*
    Goal: Returns the sum of the lengths of the each item in the Playlist
*/
double Playlist::getTotalTime() const
{
    double totalTime = 0.0;
    
    // create temp node ptr from head ptr
    DoubleNode <PlaylistItem*>* temp_ptr_ = head_ptr_;
    
    // loop until temp_ptr is not nullptr
    while (temp_ptr_ != nullptr) {
        // grab item length
        totalTime += temp_ptr_->getItem()->getLength();
        // go to next node
        temp_ptr_ = temp_ptr_->getNext();
    }
    
    return totalTime;
}


/*
    Parameter: Another Playlist (rhs)
    Goal: Implement Union.
    rhs to be combined with the contents of this (the calling) list.
    Duplicates are allowed.
*/
void Playlist::operator+=(Playlist rhs)
{
    DoubleNode <PlaylistItem*>* temp_ptr_ = head_ptr_;
    int index = 1;
    
    while (temp_ptr_ != nullptr) {
        rhs.insert(temp_ptr_->getItem(), size_ + index);
        temp_ptr_ = temp_ptr_->getNext();
        index++;
    }
}


/*
    Parameter: Another Playlist (rhs)
    Goal: Implement Difference.
    Removes all items from this (the calling) list that are also in rhs.
*/
void Playlist::operator-=(Playlist rhs)
{
    
}


/*
    Goal: Moves the current object at the head of the list to the end of the list.
*/
void Playlist::skip()
{
    /* Initialize first and last pointers */
    DoubleNode <PlaylistItem*>* first_ptr_ = head_ptr_;
    DoubleNode <PlaylistItem*>* last_ptr_ = head_ptr_;

    // after this loop last contains address of last node in Linked List
    while (last_ptr_->getNext() != nullptr) {
        last_ptr_ = last_ptr_->getNext();
    }
  
    // change the head pointer to point to second node now
    head_ptr_ = first_ptr_->getNext();
  
    // set the next of first as nullptr
    first_ptr_->setNext(nullptr);
  
    // set the next of last as first
    last_ptr_->setNext(first_ptr_);
}


/*
    Goal: Moves the current object at the end of the list to the head of the list.
*/
void Playlist::rewind()
{
    /* Initialize first and last pointers */
    DoubleNode <PlaylistItem*>* first_ptr_ = head_ptr_;
    DoubleNode <PlaylistItem*>* last_ptr_ = head_ptr_;
    
//    first_ptr_
//    A
//    B
//    C 
//
//    REWIND()
//
//    last_ptr_
//    C
//    A
//    B
    
//    last_ptr_ == C
    
    // after this loop last contains address of last node in Linked List
    while (first_ptr_->getNext() != nullptr) {
        first_ptr_ = first_ptr_->getNext();
    }
    
    // change the second node to point to head pointer
    //    first_ptr_ = head_ptr_->getNext();
    
    last_ptr_->setNext(first_ptr_);
    
    // set the next of last as first
    last_ptr_->setPrevious(nullptr);
}


/*
    Goal: Calls the display function of each item in the Playlist
*/

void Playlist::display()
{
    // create temp node ptr from head ptr
    DoubleNode <PlaylistItem*>* temp_ptr_ = head_ptr_;
    
    while (temp_ptr_ != nullptr) {
        temp_ptr_->getItem()->display();
        temp_ptr_ = temp_ptr_->getNext();
    }
}

