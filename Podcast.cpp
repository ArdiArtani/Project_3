//
//  Podcast.cpp
//  Project_3
//
//  Created by Ardi Artani on 10/25/20.
//

#include "Podcast.hpp"


/* Constructor */
Podcast::Podcast(std::string title, double length, std::string genre, std::string nameOfPodcast, std::string host, std::string guest):PlaylistItem(title, length, genre)
{
    name_of_podcast_ = nameOfPodcast;
    host_ = host;
    guest_ = guest;
}

// Return name of podcast
std::string Podcast::getNameOfPodcast() const
{
    return name_of_podcast_;
}

// Return host_
std::string Podcast::getHost() const
{
    return host_;
}

// Return guest_
std::string Podcast::getGuest() const
{
    return guest_;
}


// Assign value to private name_of_podcast_
void Podcast::setNameOfPodcast(std::string nameOfPodcast)
{
    name_of_podcast_ = nameOfPodcast;
}

// Assign value to private host_
void Podcast::setHost(std::string host)
{
    host_ = host;
}

// Assign value to private guest_
void Podcast::setGuest(std::string guest)
{
    guest_ = guest;
}

/*
    Goal: Displays the member variables to the console.
    Format is based on the given example in audioBookExample.txt.
*/
void Podcast::display() const
{
    //    Example Output:
    //    Episode 121: A Spell for Chameleon
    //    Podcast: Literary Disco
    //    Host: Rider Strong
    //    Guest: Will Friedle
    //    Genre: Literature
    //    Length: 53.35
    std::cout << getTitle() << std::endl;
    std::cout <<  "Podcast: " << getNameOfPodcast() << std::endl;
    std::cout <<  "Host: " << getHost() << std::endl;
    std::cout <<  "Guest: " << getGuest() << std::endl;
    std::cout <<  "Genre: " << getGenre() << std::endl;
    std::cout <<  "Length: " << getLength() << std::endl << std::endl;
}
