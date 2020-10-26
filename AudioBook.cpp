//
//  AudioBook.cpp
//  Project_3
//
//  Created by Ardi Artani on 10/25/20.
//

#include "AudioBook.hpp"

/* Constructor */
AudioBook::AudioBook(std::string title, double length, std::string genre, std::string author, std::string speaker):PlaylistItem(title, length, genre)
{
    author_ = author;
    speaker_ = speaker;
}

// Goal: Return the value of author_
std::string AudioBook::getAuthor() const
{
    return author_;
}

// Goal: Return the value of author_
std::string AudioBook::getSpeaker() const
{
    return speaker_;
}

// Assign value to private author_
void AudioBook::setAuthor(std::string author)
{
    author_ = author;
}

// Assign value to private speaker_
void AudioBook::setSpeaker(std::string speaker)
{
    speaker_ = speaker;
}

/*
    Goal: Displays the member variables to the console.
    Format is based on the given example in audioBookExample.txt.
*/
void AudioBook::display() const
{
    //    Example Output:
    //    Playing It My Way
    //    Author: Sachin Tendulkar
    //    Narrator: Sartaj Garewal
    //    Genre: Biography
    //    Length: 849
    std::cout << getTitle() << std::endl;
    std::cout <<  "Author: " << getAuthor() << std::endl;
    std::cout <<  "Narrator: " << getSpeaker() << std::endl;
    std::cout <<  "Genre: " << getGenre() << std::endl;
    std::cout <<  "Length: " << getLength() << std::endl;
}
