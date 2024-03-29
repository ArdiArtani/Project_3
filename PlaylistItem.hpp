//
//  PlaylistItem.hpp
//  Project_3
//
//  Created by Ardi Artani on 10/25/20.
//

#ifndef PlaylistItem_hpp
#define PlaylistItem_hpp

#include <iostream>
#include <string>

class PlaylistItem
{
public:
    /*
        Parameterized Construtor
        Parameters: title, length, genre
        Goal: Update member variables with given parameters
    */
    PlaylistItem(std::string title, double length, std::string genre);

    
    /************************ Getter Functions ************************/
    // Goal: Return the value of title_
    std::string getTitle() const;
    
    // Goal: Return the value of length
    double getLength() const;

    // Goal: Return the value of genre_
    std::string getGenre() const;

    
    /************************ Setter Functions ************************/
    // Goal: Update the value of title_ with the given parameter
    void setTitle(std::string title);

    // Goal: Update the value of length_ with the given parameter
    void setLength(double length);

    // Goal: Update the value of genre_ with the given parameter
    void setGenre(std::string genre);

    
    /************************ Other Functions ************************/
    // A virtual function to be implemented by the children classes
    virtual void display() const = 0;
    
   
private:
    std::string title_;
    double length_;
    std::string genre_;
};

#endif /* PlaylistItem_hpp */
