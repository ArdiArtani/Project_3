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
    
    // create temp node ptr from head ptr
    DoubleNode <PlaylistItem*>* temp_ptr_ = head_ptr_;
    
    DoubleNode <PlaylistItem*>* prev_ptr_ = nullptr;
    DoubleNode <PlaylistItem*>* last_ptr_ = head_ptr_;
 
    while( last_ptr_->getNext() != nullptr) {
        prev_ptr_ = temp_ptr_;
        last_ptr_ = last_ptr_->getNext();
    }
    prev_ptr_->setNext(nullptr);
    last_ptr_->setNext(temp_ptr_);
    temp_ptr_ = last_ptr_;
}


/*
    Goal: Moves the current object at the end of the list to the head of the list.
*/
void Playlist::rewind()
{
    // create temp node ptr from head ptr
    DoubleNode <PlaylistItem*>* temp_ptr_ = head_ptr_;
    
    DoubleNode <PlaylistItem*>* prev_ptr_ = nullptr;
    DoubleNode <PlaylistItem*>* last_ptr_ = head_ptr_;
 
    while( last_ptr_->getNext() != nullptr) {
        prev_ptr_ = temp_ptr_;
        last_ptr_ = last_ptr_->getNext();
    }
    prev_ptr_->setNext(nullptr);
    last_ptr_->setNext(temp_ptr_);
    temp_ptr_ = last_ptr_;
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
