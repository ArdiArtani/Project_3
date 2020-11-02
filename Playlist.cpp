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
    //    PlaylistItem* current_playlist_ = head_ptr_;
//    while (current_playlist_ != NULL)
//    {
//        totalTime += current_playlist_->getLength();
//        current_playlist_ = current_playlist_->getNext();
//    }
    
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
    
}


/*
    Goal: Moves the current object at the end of the list to the head of the list.
*/
void Playlist::rewind()
{
    
}


/*
    Goal: Calls the display function of each item in the Playlist
*/

void Playlist::display()
{
    while (head_ptr_ != nullptr) {
        head_ptr_->getItem()->display();
        head_ptr_ = head_ptr_->getNext();
    }
}
