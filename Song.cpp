//
//  Song.cpp
//  Project_3
//
//  Created by Ardi Artani on 10/25/20.
//

#include "Song.hpp"

/* Constructor */
Song::Song(std::string title, double length, std::string genre, std::string artist):PlaylistItem(title, length, genre)
{
    artist_ = artist;
}

/************************ Getter Functions ************************/
/*
    Goal: Return the value of artist_
*/
std::string Song::getArtist() const
{
    return artist_;
}


/************************ Setter Functions ************************/

/*
    Goal: Update the value of artist_ with the given parameter
*/
void Song::setArtist(std::string artist)
{
    artist_ = artist;
}

/************************ Other Functions ************************/

/*
    Goal: Displays the member variables to the console.
    Format is based on the given example in songExample.txt.
*/
void Song::display() const
{
    //    Expected Output:
    //    Miracle
    //    Artist: Beachwood
    //    Genre: Electro Pop
    //    Length: 2.48
    std::cout << getTitle() << std::endl;
    std::cout <<  "Artist: " << getArtist() << std::endl;
    std::cout <<  "Genre: " << getGenre() << std::endl;
    std::cout <<  "Length: " << getLength() << std::endl;
}
