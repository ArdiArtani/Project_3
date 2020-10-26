//
//  AudioBook.hpp
//  Project_3
//
//  Created by Ardi Artani on 10/25/20.
//

#ifndef AudioBook_hpp
#define AudioBook_hpp

#include "PlaylistItem.hpp"

class AudioBook : public PlaylistItem
{
public:
    AudioBook(std::string title, double length, std::string genre, std::string author, std::string speaker);

    std::string getAuthor() const;
    std::string getSpeaker() const;

    void setAuthor(std::string author);
    void setSpeaker(std::string speaker);

    /*
        Goal: Displays the member variables to the console.
        Format is based on the given example in audioBookExample.txt.
    */
    void display() const;
private:
    std::string author_;
    std::string speaker_;
};


#endif /* AudioBook_hpp */
